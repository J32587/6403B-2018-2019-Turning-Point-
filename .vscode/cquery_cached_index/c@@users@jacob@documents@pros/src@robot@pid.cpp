#include "main.h"
#include "Motors.h"

void PIDMoveForward (float target, float waitTime, int maxPower)
{
  //Defining Variables
  const float Kp = 0.55;
  const float Ki = 0.005; //can be a very small value and to disable set to 0.1*10^-10
  const float Kd = 0.2;

  int error;

  float proportion;
  int integralRaw;
  float integral;
  int lastError;
  int derivative;

  const float integralPowerLimit = 50 / Ki;
  const float integralActiveZone = 1000;

  int finalPower;

  float Kp_C = 0.05;
  int error_drift;
  float proportion_drift;

  bool timerLock = true;

    resetData();
  Brain.resetTimer();
    updateData();

  while (Brain.timer(vex::timeUnits::msec) < waitTime){
    //Proportion control
    error = target -  (backLeftDrive +( backRightDrive + 41.0) );
    proportion = Kp * error;

    //Drift control
    error_drift = std::abs(backLeftDrive) - std::abs( (backRightDrive + 41.0) );
    proportion_drift = Kp_C * error_drift;

    //Integral control
    if (abs(error) < integralActiveZone && error != 0)
      integralRaw = integralRaw + error;
    else
      integralRaw = 0;

    if (integralRaw > integralPowerLimit)
      integralRaw = integralPowerLimit;
    if (integralRaw < -integralPowerLimit)
      integralRaw = -integralPowerLimit;

    integral = Ki * integralRaw;

    //Derivative control
    derivative = Kd * (error - lastError);
    lastError = error;
    if (error == 0)
      derivative = 0;

    //Set motor powers
    finalPower = proportion + integral + derivative;
    if (finalPower > percentToMotorValue(maxPower))
      finalPower = percentToMotorValue(maxPower);
    else if (finalPower < -percentToMotorValue(maxPower))
      finalPower = -percentToMotorValue(maxPower);

    setMotors(finalPower - proportion_drift, finalPower + proportion_drift);

    //Dont wanna over load the poor CPU now do we
    vex::task::sleep(40);

    //When where is 30 error left (0.3") start the wait timer to end the loop
    if (std::abs(error) < 100) // Must get the absolute value because the error can be negative, which will in essence put the driving on a timer
      timerLock = false;

    if (timerLock) Brain.resetTimer();
  }
  //Turn off the drive
  setMotors(0, 0);
}



void PIDMoveBackwards (float target, float waitTime, int maxPower){
  //Defining Variables
  const float Kp = 0.4;
  const float Ki = 0.005; //can be a very small value and to disable set to 0.1*10^-10
  const float Kd = 0.4;

  int error;

  float proportion;
  int integralRaw;
  float integral;
  int lastError;
  int derivative;

  const float integralPowerLimit = 50 / Ki;
  const float integralActiveZone = 1000;

  int finalPower;

  float Kp_C = 0.05;
  int error_drift;
  float proportion_drift;

  bool timerLock = true;

    resetMotors();
  Brain.resetTimer();
    updateData();

  while (Brain.timer(vex::timeUnits::msec) < waitTime){
    //Proportion control
    error = target -  ((backLeftDrive  + 18.0) + backRightDrive );
    proportion = Kp * error;

    //Drift control
    error_drift = std::abs((backLeftDrive + 18.0)) - std::abs( backRightDrive );
    proportion_drift = Kp_C * error_drift;

    //Integral control
    if (abs(error) < integralActiveZone && error != 0)
      integralRaw = integralRaw + error;
    else
      integralRaw = 0;

    if (integralRaw > integralPowerLimit)
      integralRaw = integralPowerLimit;
    if (integralRaw < -integralPowerLimit)
      integralRaw = -integralPowerLimit;

    integral = Ki * integralRaw;

    //Derivative control
    derivative = Kd * (error - lastError);
    lastError = error;
    if (error == 0)
      derivative = 0;

    //Set motor powers
    finalPower = proportion + integral + derivative;
    if (finalPower > percentToMotorValue(maxPower))
      finalPower = percentToMotorValue(maxPower);
    else if (finalPower < -percentToMotorValue(maxPower))
      finalPower = -percentToMotorValue(maxPower);

    setMotors(finalPower - proportion_drift, finalPower + proportion_drift);

    //Dont wanna over load the poor CPU now do we
    vex::task::sleep(40);

    //When where is 30 error left (0.3") start the wait timer to end the loop
    if (std::abs(error) < 100) // Must get the absolute value because the error can be negative, which will in essence put the driving on a timer
      timerLock = false;

    if (timerLock)
      Brain.resetTimer();
  }
  //Turn off the drive
  setMotors(0, 0);
}

void PIDTurnRobot(float target, float waitTime, int maxPower = 150){
  //Defining Variables

  const float Kp = 0.5;
  const float Ki = 0.005; //can be a very small value and to disable set to 0.1*10^-10
  const float Kd = 0.25;

  int error;

  float proportion;
  int integralRaw;
  float integral;
  int lastError;
  int derivative;

  const float integralPowerLimit = 50 / Ki;
  const float integralActiveZone = 1000;

  float Kp_C = 1;
  int error_drift;
  float proportion_drift;

  int finalPower;

  bool timerLock = true;

    resetMotors();
    Brain.resetTimer();
  updateData();
  while (Brain.timer(vex::timeUnits::msec) < waitTime)
    {
    //Proportion control
    error = target - (frontLeftDrive - frontRightDrive);
    proportion = Kp * error;

    //Drift control
    error_drift = std::abs(frontLeftDrive) - std::abs(frontRightDrive);
    proportion_drift = Kp_C * error_drift;

        //Integral control
    if (std::abs(error) < integralActiveZone && error != 0)
      integralRaw = integralRaw + error;
    else
      integralRaw = 0;

    if (integralRaw > integralPowerLimit)
      integralRaw = integralPowerLimit;
    if (integralRaw < -integralPowerLimit)
      integralRaw = -integralPowerLimit;

    integral = Ki * integralRaw;

    //Derivative control
    derivative = Kd * (error - lastError);
    lastError = error;
    if (error == 0)
      derivative = 0;

    //Set motor powers
    finalPower = proportion + integral + derivative;
    if (finalPower > percentToMotorValue(maxPower))
      finalPower = percentToMotorValue(maxPower);
    else if (finalPower < -percentToMotorValue(maxPower))
      finalPower = -percentToMotorValue(maxPower);

    setMotors(finalPower - proportion_drift, -finalPower + proportion_drift);


    vex::task::sleep(50);

    //When there is 30 error left (0.3") start the wait timer to end the loop
    if (std::abs(error) < 70)
      timerLock = false;

    if (timerLock)
      Brain.resetTimer();
  }
  //Turn off the drive
  setMotors(0, 0);
}
