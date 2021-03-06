#include "main.h"
#include "../Motors.h"
#include "../functions.hpp"
#include "BlueFront.hpp"

// Creates a BLUEFRONT object that is a member of the timer class
Timer BLUEFRONT;

void BlueFront(void)
{
  // Constants for the maxPower of the robot and settleTime //
  const short _autonSpeed = 114;
  const short _settleTime = 240;
  // Reset the timer for the auton //
  BLUEFRONT.resetTimer();
  // Start the reload and DoubleShoot tasks for the Puncher //
  Task reload(DRAWBACK_TASK);
  // Move the Intake when the auton period of the match starts //
  Intake.move(127);
  // Move the robot forwards to get the ball under the cap //
  moveRobotPID("north",42.5,_settleTime,120);
  delay(300);
  Intake.move(0);
  // Delay the robot then stop the intake so the robot can get the ball //
  // Move the Robot backwards so it is inline with the flags //
  moveRobotPID("south",46.5,_settleTime,_autonSpeed);
  // Turn the robot right so it is facing the flags //
  moveRobotPID("right turn",92,_settleTime,_autonSpeed);
  // Move the robot Forwards a very small amount so it is able to shoot the top flag //
  moveRobotPID("north",6.5,_settleTime,80);
  // Execute the DoubleShoot task which will make the robot shoot the top and middle flags //
  DOUBLE_SHOOT();
  delay(300);
  moveRobotPID("right turn",8,_settleTime,_autonSpeed);
  // Move forward and hit the bottom flag, also wait so the robot can pick up the rebound//
  moveRobotPID("north",43.5,_settleTime,_autonSpeed);
  delay(200);

  reload.suspend();
  Intake.move(0);
  Puncher.move(0);
  // Display the amount of time the auton took to execute //
  BLUEFRONT.getTime();
}
