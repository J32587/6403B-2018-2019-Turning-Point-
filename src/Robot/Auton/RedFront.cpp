#include "main.h"
#include "../Motors.h"
#include "../functions.hpp"
#include "RedFront.hpp"
Timer REDFRONT;
void RedFront(void)
{
  const short unsigned int _autonSpeed = 114;
  REDFRONT.resetTimer();
  Task reload(DRAWBACK_AUTON_TASK);
  Intake.move(60);
  moveRobotPID("north",39,200,_autonSpeed);
  delay(345);
  Intake.move(0);
  moveRobotPID("south",38.5,230,_autonSpeed);
  moveRobotPID("left turn",97,230,_autonSpeed);//
  moveRobotPID("north",2,240,80);
  shoot(false);
  delay(540);
  Intake.move(100);
  moveRobotPID("north",27.5,230,_autonSpeed);
  shoot(false);
  delay(540);
  moveRobotPID("west",3.25,250,_autonSpeed);
  moveRobotPID("north",23.5,230,_autonSpeed);
  delay(170);
  moveRobotPID("south",20,230,_autonSpeed);
  moveRobotPID("left turn",97,240,_autonSpeed);//
  moveRobotPID("south",13,230,_autonSpeed);
  Lift.move(-127);
  delay(230);
  Lift.move(0);
  moveRobotPID("right turn",155,250,_autonSpeed);//
  shoot(false);
  delay(545);
  moveRobotPID("north",38,1,127);
  Intake.move(0);
  lcd::set_text(4,to_string(REDFRONT.getTime()));
  Puncher.move(0);


}
