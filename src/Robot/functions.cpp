#include "main.h"
#include "Motors.h"
#include "functions.hpp"
#include "Global.hpp"
//upload --slot 4
//open terminal with Ctrl+Shift+P; then type in terminal

// setup for variables used within functions.cpp //
float frontLeftDrive = 0;
float frontRightDrive = 0;
float backLeftDrive = 0;
float backRightDrive = 0;
float Gyro = 0;

//************Motor Enconder Functions*************//

// sets the speed of the left and right motors of the drive //
void setMotors(int mySpeedL,int mySpeedR)
	{
LFDrive.move(mySpeedL);
LBDrive.move(mySpeedL);
RFDrive.move(mySpeedR);
RBDrive.move(mySpeedR);
	}

	// Updates the values of the motor encoders //
	inline void updateDataP()
	{
	 frontLeftDrive = LFDrive.get_position();
	 frontRightDrive = RFDrive.get_position();
	 backLeftDrive = LBDrive.get_position();
	 backRightDrive = RBDrive.get_position();
	 Gyro = myGyro.get_value();
	}

// resets the data of the enconders and sensors //
void resetData()
{
	RFDrive.set_zero_position(0);
  LFDrive.set_zero_position(0);
  RBDrive.set_zero_position(0);
  LBDrive.set_zero_position(0);
  myGyro.reset();

}

// Returns the absolute value of the sum of the right motors //
int rightDrivePos()
{
	updateDataP();
  return (fabs(frontRightDrive) + fabs(backRightDrive));
}

// Returns the absolute value of the sum of the left motors //
int leftDrivePos()
{
	updateDataP();
  return (fabs(frontLeftDrive) + fabs(backLeftDrive));
}


// clears the brain lcd screen //
void lcd_clear()
{
	lcd::clear_line(1);
	lcd::clear_line(2);
	lcd::clear_line(3);
	lcd::clear_line(4);
}


//************ Auto DrawBack *************/



// Sets bool drawBack to true (allows the auton DRAWBACK task to execute) //
void shoot ()
{
  drawBack = true;
}

// Sets bool SDSD to true (allows the auton DOUBLE_SHOOT task to execute) //
void doubleShoot()
{
	SDSD = true;
}

// Function setup for the opcontrol shoot & drawback task //
void DRAWBACK_TASK(void*){
  while(true){

    if (drawBack){

      while(true){

        Puncher.move(127);
        Puncher.tare_position();

        if (Puncher.get_current_draw() < 300 && Puncher.get_actual_velocity() > 180)
        break;

        delay(2);
      }

      while (true){

        Puncher.move(127);

        if (fabs(Puncher.get_position()) > 790)
        break;

        delay(2);
      }

      Puncher.move(0);
    }

    delay(20);
  }
	drawBack = false;
}

// Functions setup for the opcontrol double shoot task //
void DOUBLE_SHOOT (void*)
{
while(true){

if(SDSD){
	if(angleDown.get_value())
	{
		shoot();
		delay(100);
		Angler.move(127);
		Intake.move(120);
		if(angleUp.get_value())
		{
    Angler.move(0);
		Intake.move(0);
		delay(50);
   	shoot();
		break;
		}
	}
	if(angleUp.get_value()){
       shoot();
			 Angler.move(-127);
			 Intake.move(120);
			 if(angleUp.get_value()){
       Angler.move(0);
			 Intake.move(0);
			 delay(50);
			 shoot();
			 break;
			 }
     }
		 SDSD = false;
   }
	 delay(20);
 }
}


//****************** PID Functions *******************//

// Converts the input inchs to Ticks //
int inchToTicks (float inch)
{
  int ticks;
  const int conversionFactor = 70;
  ticks = inch * conversionFactor;

  return ticks;
}

// Converts the input inchs to Ticks for strafing //
int inchToTickStrafe (float inch)
{
  int ticks;

  const int conversionFactor = 127;
  ticks = inch * conversionFactor;

  return ticks;
}

// Setup for the PID timer lock //
Timer PID;

// Function for the Robot PID movement //
void moveRobotPID (string direction, float target, float waitTime, int maxPower){

	//Constants for movement
  const float Kp = 0.2;
  const float Kp_C = .8;
  const float Ki = 0.1;
  const float Kd = 0.4;
  const float Kp_turn = 0.2;
  const float Ki_turn = 0.1;
  const float Kd_turn = 0.4;

  //PID Variables
  float error;
  float proportion;
  float integralRaw;
  float integral;
  float lastError;
  float derivative;

  //Drift Variables
  float error_drift;
  float proportion_drift;

  const float integralPowerLimit = 20 / Ki;
  const float integralActiveZone = inchToTicks(3);
  const short minPower = 15;

  short finalPower;

  bool timerLock = true;
  resetData();
  PID.resetTimer();

  if (waitTime <= 250) waitTime = 250;

  if (direction == "north" || direction == "south")
	{
    while (true)
		{
      error = inchToTicks(target) - ((leftDrivePos() + rightDrivePos())/4);
      proportion = Kp * error;

      error_drift = myGyro.get_value();
      proportion_drift = Kp_C * error_drift;

      if (fabs(error) < integralActiveZone && error != 0) integralRaw = integralRaw + error;
      else integralRaw = 0;

      if (integralRaw > integralPowerLimit) integralRaw = integralPowerLimit;
      if (integralRaw < -integralPowerLimit) integralRaw = -integralPowerLimit;

      integral = Ki * integralRaw;

      derivative = Kd * (error - lastError);
      lastError = error;
      if (error == 0) derivative = 0;

      finalPower = proportion + integral + derivative;

      if (finalPower > maxPower) finalPower = maxPower;

      else if (finalPower < -maxPower) finalPower = -maxPower;

      if (direction == "north")
      setMotors(finalPower - proportion_drift, finalPower + proportion_drift);
      else if (direction == "south")
      setMotors(-finalPower - proportion_drift, -finalPower + proportion_drift);

      if (error < 100) timerLock = false;

      if (timerLock) PID.resetTimer();

      if (PID.getTime() >= waitTime) break;

      delay(20);
    }
  }

  else if (direction == "left turn" || direction == "right turn"){

    while (true)
		{

      error = fabs(target * 10) - fabs(myGyro.get_value());
      proportion = Kp_turn * error;

      if (fabs(error) < integralActiveZone && fabs(error) != 0)
      integralRaw = integralRaw + error;
      else integralRaw = 0;

      if (integralRaw > integralPowerLimit) integralRaw = integralPowerLimit;
      if (integralRaw < -integralPowerLimit) integralRaw = -integralPowerLimit;

      integral = Ki_turn * integralRaw;

      derivative = Kd_turn * (error - lastError);
      lastError = error;
      if (error == 0) derivative = 0;

      finalPower = proportion + integral + derivative;

      if (finalPower > maxPower) finalPower = maxPower;

      else if(finalPower < -maxPower) finalPower = -maxPower;

      if (direction == "left turn")
      setMotors(-finalPower - proportion_drift, finalPower + proportion_drift);

      else if (direction == "right turn")
      setMotors(finalPower - proportion_drift, -finalPower + proportion_drift);


      if (error < 100) timerLock = false;

      if (timerLock) PID.resetTimer();

      if (PID.getTime() >= waitTime) break;

      delay(20);
    }
  }

  if (direction == "east" || direction == "west")
	{
    while(true)
		{
      error = inchToTickStrafe(target) - ((leftDrivePos() + rightDrivePos())/4);
      proportion = Kp * error;

      error_drift = myGyro.get_value();
      proportion_drift = Kp_C * error_drift;

      if (fabs(error) < integralActiveZone && error != 0) integralRaw = integralRaw + error;
      else integralRaw = 0;

      if (integralRaw > integralPowerLimit)  integralRaw = integralPowerLimit;
      if (integralRaw < -integralPowerLimit) integralRaw = -integralPowerLimit;

      integral = Ki * integralRaw;

      derivative = Kd * (error - lastError);
      lastError = error;
      if (error == 0) derivative = 0;

      finalPower = proportion + integral + derivative;

      if (abs(finalPower) > maxPower) finalPower = maxPower;

      else if(finalPower < -maxPower) finalPower = -maxPower;

      setMotors(-finalPower - proportion_drift, -finalPower + proportion_drift);
      if (direction == "west")
			{
        LFDrive.move(-finalPower - proportion_drift);
        RFDrive.move(finalPower + proportion_drift);
        LBDrive.move(finalPower - proportion_drift);
        RBDrive.move(-finalPower + proportion_drift);
      }
      else if (direction == "east")
			{
        LFDrive.move(finalPower - proportion_drift);
        RFDrive.move(-finalPower + proportion_drift);
        LBDrive.move(-finalPower - proportion_drift);
        RBDrive.move(finalPower + proportion_drift);
      }

      if (error < 100) timerLock = false;

      if (timerLock) PID.resetTimer();

      if (PID.getTime() >= waitTime) break;

      delay(20);
    }
  }
  setMotors(0, 0);
}
