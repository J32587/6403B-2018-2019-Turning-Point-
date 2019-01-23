#include "main.h"
#include "../Motors.h"
#include "../functions.hpp"
#include "RedFront.hpp"

// Creates a REDFRONT object that is a member of the timer class
Timer REDFRONT;

void RedFront(void)
{
  // Display the rpm of the left front and Right front motors //
//  lcd::set_text(5,"LF");lcd::set_text(5,std::to_string(   LFDrive.get_actual_velocity()));
//  lcd::set_text(6,"RF");lcd::set_text(5,std::to_string(   LFDrive.get_actual_velocity()));
  // Constants for the maxPower and settleTime of the robot //
  const short _autonSpeed = 114;
  const short _settleTime = 240;
  // Reset the Timer for the auton //
  REDFRONT.resetTimer();
  // Start the tasks for shooting the puncher //
  Task reload(DRAWBACK_TASK);
  Task DoubleShoot(DOUBLE_SHOOT);

  // Move the Intake when the auton period of the match starts //
  Intake.move(60);
  // Move the robot forwards to get the ball under the cap //
  moveRobotPID("north",39,_settleTime,_autonSpeed);
  // Delay the robot then stop the intake so the robot can get the ball //
  delay(345);
  Intake.move(0);
  // Move the Robot backwards so it is inline with the flags //
  moveRobotPID("south",38.5,_settleTime,_autonSpeed);
  // Turn the robot left so it is facing the flags //
  moveRobotPID("left turn",97,_settleTime,_autonSpeed);
  //Move the robot Forwards a very small amount so it is able to shoot the top flag //
  moveRobotPID("north",2,_settleTime,80);
  //Execute the DoubleShoot task which will make the robot shoot the top and middle flags //
  doubleShoot();
  delay(600);
  // Strafe to the left to line the robot up with the bottom flag //
  moveRobotPID("west",3.25,_settleTime,_autonSpeed);
  // Move forward and hit the bottom flag, also wait so the robot can pick up the rebound//
  moveRobotPID("north",43.5,_settleTime,_autonSpeed);
  delay(200);
  // Move Backwards so the robot is aligned with the cap //
  moveRobotPID("south",20,_settleTime,_autonSpeed);
  // Turn the robot left so it is facing the cap with the lift //
  moveRobotPID("left turn",97,_settleTime,_autonSpeed);
  // Move the robot forwards to flip the cap //
  moveRobotPID("south",13,_settleTime,_autonSpeed);
  // Flip the cap //
  Lift.move(-127);
  delay(230);
  Lift.move(0);
  // Turn the robot so it is aligned with the top middle flag //
  moveRobotPID("right turn",155,_settleTime,_autonSpeed);
  // Execute the shoot task which uses the rebound //
  shoot();
  delay(540);
  // Move the robot fowards so the driver can move into the flag after auton //
  moveRobotPID("north",38,1,127);
  // Stop any motors from moving //
  Intake.move(0);
  Puncher.move(0);
  setMotors(0,0);
  // Displays the amount of time the auton took to execute //
  REDFRONT.getTime();
}
