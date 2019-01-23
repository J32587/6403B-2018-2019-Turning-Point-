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
  Task DoubleShoot(DOUBLE_SHOOT);
  // Move the Intake when the auton period of the match starts //
  Intake.move(70);
  // Move the robot forwards to get the ball under the cap //
  moveRobotPID("north",39,_settleTime,_autonSpeed);
  // Delay the robot then stop the intake so the robot can get the ball //
  delay(265);
  Intake.move(0);
  // Move the Robot backwards so it is inline with the flags //
  moveRobotPID("south",38.5,_settleTime,_autonSpeed);
  // Turn the robot right so it is facing the flags //
  moveRobotPID("right turn",97,_settleTime,_autonSpeed);
  // Move the robot Forwards a very small amount so it is able to shoot the top flag //
  moveRobotPID("north",6.5,_settleTime,80);
  // Execute the DoubleShoot task which will make the robot shoot the top and middle flags //
  doubleShoot();
  delay(600);
  // Strafe to the right to line the robot up with the bottom flag //
  moveRobotPID("east",4.5,_settleTime,_autonSpeed);
  // Move forward and hit the bottom flag, also wait so the robot can pick up the rebound//
  moveRobotPID("north",43.5,_settleTime,_autonSpeed);
  delay(200);
  // Move Backwards so the robot is aligned with the cap //
  moveRobotPID("south",33.5,_settleTime,_autonSpeed);
  // Turn the robot right so it is facing the cap with the lift //
  moveRobotPID("right turn",97,_settleTime,_autonSpeed);//
  // Move the robot forwards to flip the cap //
  moveRobotPID("south",14.5,_settleTime,_autonSpeed);
  // Flip the cap //
  Lift.move(-127);
  delay(230);
  Lift.move(0);
  // Turn the robot so it is aligned with the top middle flag //
  moveRobotPID("left turn",151,_settleTime,_autonSpeed);//
  // Execute the shoot task which uses the rebound //
  shoot();
  delay(545);
  // Move the robot fowards so the driver can move into the flag after auton //
  moveRobotPID("north",38,1,127);
  // Stop any motors from moving //
  Intake.move(0);
  Puncher.move(0);
  // Display the amount of time the auton took to execute //
  BLUEFRONT.getTime();
}
