#include "main.h"
#include "../Motors.h"
#include "../functions.hpp"
#include "BlueFront.hpp"
Timer BLUEFRONT;
void BlueFront(void)
{
  const short unsigned int _autonSpeed = 114;
  BLUEFRONT.resetTimer();
  Task reload(DRAWBACK_AUTON_TASK);
  Intake.move(70);
  moveRobotPID("north",39,200,_autonSpeed);
  delay(275);
  Intake.move(0);
  moveRobotPID("south",38.5,230,_autonSpeed);
  moveRobotPID("right turn",97,230,_autonSpeed);
  moveRobotPID("north",6.5,240,80);
  shoot(false);
  delay(540);
  Intake.move(100);
  moveRobotPID("north",27.5,230,_autonSpeed);
  shoot(false);
  delay(540);
  moveRobotPID("east",4.5,250,_autonSpeed);
  moveRobotPID("north",23.5,230,_autonSpeed);
  delay(200);
  moveRobotPID("south",33.5,240,_autonSpeed);
  moveRobotPID("right turn",97,240,_autonSpeed);//
  moveRobotPID("south",14.5,230,_autonSpeed);
  Lift.move(-127);
  delay(230);
  Lift.move(0);
  moveRobotPID("left turn",151,250,_autonSpeed);//
  shoot(false);
  delay(545);
  moveRobotPID("north",38,1,127);
  Intake.move(0);
  lcd::set_text(4,to_string(BLUEFRONT.getTime()));
  Puncher.move(0);

}
