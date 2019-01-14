#include "main.h"
#include "../Motors.h"
#include "../functions.hpp"
#include "RedFront.hpp"
Timer REDFRONT;
void RedFront(void)
{
  const short unsigned int _autonSpeed = 105;
  REDFRONT.resetTimer();
  Task reload(DRAWBACK_AUTON_TASK);
  Intake.move(90);
  moveRobotPID("north",40,200,_autonSpeed);
  delay(195);
  Intake.move(0);
  moveRobotPID("south",39,250,_autonSpeed);
  moveRobotPID("left turn",97,230,_autonSpeed);//
  moveRobotPID("north",10,250,80);
  shoot(false);
  delay(550);
  Intake.move(100);
  moveRobotPID("north",22,250,_autonSpeed);
  shoot(false);
  delay(550);
  moveRobotPID("west",3.2,250,_autonSpeed);
  moveRobotPID("north",20,250,_autonSpeed);
  moveRobotPID("south",23,250,_autonSpeed);
  moveRobotPID("left turn",97,230,_autonSpeed);//
  moveRobotPID("south",13,250,_autonSpeed);
  Lift.move(-127);
  delay(270);
  Lift.move(0);
  moveRobotPID("right turn",159,250,_autonSpeed);//
  shoot(false);
  delay(550);
  moveRobotPID("left turn",4,200,_autonSpeed);
  setMotors(127,127);
  delay(1190);
  setMotors(0,0);
  Intake.move(0);
  lcd::set_text(4,to_string(REDFRONT.getTime()));
  Puncher.move(0);


}
