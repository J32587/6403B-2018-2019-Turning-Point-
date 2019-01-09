#include "main.h"
#include "Motors.h"
#include "functions.hpp"
//upload --slot 4
//open terminal with Ctrl+Shift+P; then type in terminal


//************Motor Enconder Functions*************//

void setMotors(int mySpeedL,int mySpeedR)
	{
LFDrive.move_voltage(mySpeedL);
LBDrive.move_voltage(mySpeedL);
RFDrive.move_voltage(mySpeedR);
RBDrive.move_voltage(mySpeedR);
	}

void updateData()
{
  frontLeftDrive = LFDrive.get_position();
  frontRightDrive = RFDrive.get_position();
  backLeftDrive = LBDrive.get_position();
  backRightDrive = RBDrive.get_position();
  Gyro = myGyro.get_value();
}

void resetData()
{
RFDrive.set_zero_position(0);
RFDrive.set_zero_position(0);
myGyro.reset();
}

//****************** PID Functions *******************//

int inToTick (float inch)
{
  //Define return variable
  int ticks;

  const int _conversionFactor = 72;

  ticks = inch * _conversionFactor;

  //Return the number of ticks
  return ticks;
}

//Calculates the number of ticks it take to move one inch lateraly
int inToTickSide (float inch)
{

  int ticks;
  const int _conversionFactor = 127;

  ticks = inch * _conversionFactor;

  //Return ticks
  return ticks;
}

//Function to return the sign of a number
int sign (int in){

  int out;

  out = in / (abs(in));

  //Return sign
  return out;
}

int driveRightPos()
{
  return fabs(frontLeftDrive + fabs(backLeftDrive));
}

int driveLeftPos()
{
  return fabs(frontRightDrive + fabs(backLeftDrive));
}

inline void updateDataP()
{
 frontLeftDrive = LFDrive.get_position();
 frontRightDrive = RFDrive.get_position();
 backLeftDrive = LBDrive.get_position();
 backRightDrive = RBDrive.get_position();
 Gyro = myGyro.get_value();
}
Timer PID;
void moveRobotPID (const string direction, float target, float waitTime, int maxPower){
	PID.resetTimer();
	//Constants for Axial Movement
	const float Kp = 0.2;
	const float Kp_C = 1;
	const float Ki = 0.1;
	const float Kd = 0.5;

	//Constants for Turing
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

	//Intigral Limits
	const float integralPowerLimit = 10 / Ki;
	const float integralActiveZone = inToTick(3);

	//Final Power
	int finalPower;
	int minPower = 15;

	//Initialize Sensors and Timers
	bool timerLock = true;
	resetData();
	PID.resetTimer();
	//Set minimum wait time
	if (waitTime <= 250){
		waitTime = 250;
	}

	//Check for axial movement
	if (direction == "north" || direction == "south"){
		//Infinate loop
		while (true){
			//Proportion control
			error = inToTick(target) - (driveLeftPos() + driveRightPos());
			proportion = Kp * error;

			//Drift control
			error_drift = myGyro.get_value();
			proportion_drift = Kp_C * error_drift;

			//Integral control
			if (fabs(error) < integralActiveZone && error > 5)
			integralRaw = integralRaw + error;
			else
			integralRaw = 0;

			if (integralRaw > 20)
			integralRaw = 20;
			if (integralRaw < -20)
			integralRaw = -20;

			integral = Ki * integralRaw;

			//Derivative control
			derivative = Kd * (error - lastError);
			lastError = error;
			if (error == 0)
			derivative = 0;

			//Set final power
			finalPower = proportion + integral + derivative;

			if (abs(finalPower) > maxPower){
				finalPower = maxPower;
			}
			else {
				finalPower = sign(finalPower) * (abs(finalPower) /*+ 15*/);
			}

			//Move motors
			if (direction == "north")
			setMotors(finalPower - proportion_drift, finalPower + proportion_drift);
			else if (direction == "south")
			setMotors(-finalPower - proportion_drift, -finalPower + proportion_drift);

			//When where is 100 error left (1.0") start the wait timer to end the loop
			if (error < 100){
				timerLock = false;
			}
			if (timerLock){
				PID.resetTimer();
			}
			if (PID.getTime() >= waitTime){
				break;
			}

			//Dont wanna over load the poor CPU now do we
			delay(20);
		}
	}

	//Check for turning
	else if (direction == "left" || direction == "right"){
		//Infinate loop
		while (true){
			//Proportion control
			error = fabs(target * 10) - fabs(myGyro.get_value());
			proportion = Kp_turn * error;

			//Integral control
			if (fabs(error) < integralActiveZone && fabs(error) != 0)
			integralRaw = integralRaw + error;
			else
			integralRaw = 0;

			if (integralRaw > 20)
			integralRaw = 20;
			if (integralRaw < -20)
			integralRaw = -20;

			integral = Ki_turn * integralRaw;

			//Derivative control
			derivative = Kd_turn * (error - lastError);
			lastError = error;
			if (error == 0)
			derivative = 0;

			//Set final power
			finalPower = proportion + integral + derivative;

			if (abs(finalPower) > maxPower){
				finalPower = maxPower;
			}
			else {
				finalPower = sign(finalPower) * (abs(finalPower) /*+ 15*/);
			}

			//Move motors
			if (direction == "left")
			setMotors(-finalPower - proportion_drift, finalPower + proportion_drift);
			else if (direction == "right")
			setMotors(finalPower - proportion_drift, -finalPower + proportion_drift);

			//When where is 100 error left (1.0") start the wait timer to end the loop
			if (error < 100){
				timerLock = false;
			}

			if (timerLock){
				PID.resetTimer();
			}

			if (PID.getTime() >= waitTime){
				break;
			}

			//Dont wanna over load the poor CPU now do we
			delay(20);
		}
	}

	//Checks for lateral movement
	if (direction == "east" || direction == "west"){
		while(true){
			//Proportion control
			error = target - (driveLeftPos() + driveRightPos());
			proportion = Kp * error;

			//Drift control
			error_drift = myGyro.get_value();
			proportion_drift = Kp_C * error_drift;

			//Integral control
			if (fabs(error) < integralActiveZone && error > 5)
			integralRaw = integralRaw + error;
			else
			integralRaw = 0;

			if (integralRaw > 20)
			integralRaw = 20;
			if (integralRaw < -20)
			integralRaw = -20;

			integral = Ki * integralRaw;

			//Derivative control
			derivative = Kd * (error - lastError);
			lastError = error;
			if (error == 0)
			derivative = 0;

			//Set final power
			finalPower = proportion + integral + derivative;

			if (abs(finalPower) > maxPower){
				finalPower = maxPower;
			}
			else {
				finalPower = sign(finalPower) * (abs(finalPower) /*+ 15*/);
			}

			//Move motors
			setMotors(-finalPower - proportion_drift, -finalPower + proportion_drift);
			if (direction == "west"){
				LFDrive.move(-finalPower - proportion_drift);
				RFDrive.move(finalPower + proportion_drift);
				LBDrive.move(finalPower - proportion_drift);
				RBDrive.move(-finalPower + proportion_drift);
			}
			else if (direction == "east"){
				LFDrive.move(finalPower - proportion_drift);
				RFDrive.move(-finalPower + proportion_drift);
				LBDrive.move(-finalPower - proportion_drift);
				RBDrive.move(finalPower + proportion_drift);
			}

			//When where is 100 error left (1.0") start the wait timer to end the loop
			if (error < 100){
				timerLock = false;
			}
			if (timerLock){
				PID.resetTimer();
			}
			if (PID.getTime() >= waitTime){
				break;
			}

			//Dont wanna over load the poor CPU now do we
			delay(20);
		}
	}
	//Turn off the drive
	setMotors(0, 0);
}
