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

  ticks = inch * _conversionFactor * 4;

  //Return the number of ticks
  return ticks;
}

//Calculates the number of ticks it take to move one inch lateraly
int inToTickSide (float inch)
{

  int ticks;
  const int _conversionFactor = 127;

  ticks = inch * _conversionFactor * 4;

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
