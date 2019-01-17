#include "main.h"
#include "../Motors.h"
#include "../functions.hpp"
#include "Skillz.hpp"

Timer SKILLZ;
void Skillz(void)
{
  const short unsigned int _autonSpeed = 114;
  SKILLZ.resetTimer();
  moveRobotPID("north",49,250,115);
  delay(390);
  Intake.move(0);
  moveRobotPID("left turn",97, 250, _autonSpeed);
  moveRobotPID("south",13,250,_autonSpeed);
  Lift.move(-127);
  delay(270);
  Lift.move(0);
  moveRobotPID("right turn",97,250,_autonSpeed);
  moveRobotPID("north",40,250,_autonSpeed);
  moveRobotPID("left turn",97,250,_autonSpeed);
  moveRobotPID("north",40,250,_autonSpeed);
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
  lcd::set_text(4,std::to_string(SKILLZ.getTime()));


}
