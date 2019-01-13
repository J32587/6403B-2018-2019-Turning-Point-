#include "main.h"
#include "../Motors.h"
#include "../functions.hpp"
#include "BlueFront.hpp"
const short unsigned int _autonSpeed = 100;
Timer BLUEFRONT;
void BlueFront(void)
{
  BLUEFRONT.resetTimer();
  Task reload(DRAWBACK_AUTON_TASK);
  Intake.move(90);
  moveRobotPID("north",40,200,_autonSpeed);
  delay(290);
  Intake.move(0);
  moveRobotPID("south",39,250,_autonSpeed);
  delay(250);
  moveRobotPID("right turn",97,230,_autonSpeed);
  delay(250);
  moveRobotPID("north",10.4,250,80);
  shoot(false);
  delay(550);
  Intake.move(100);
  moveRobotPID("north",22,250,_autonSpeed);
  shoot(false);
  delay(550);
  moveRobotPID("east",3.2,250,_autonSpeed);
  delay(250);
  moveRobotPID("north",17,250,_autonSpeed);
  delay(250);
  moveRobotPID("south",22,250,_autonSpeed);
  delay(250);
  moveRobotPID("right turn",97,230,_autonSpeed);
  delay(250);
  moveRobotPID("south",13,250,_autonSpeed);
  delay(150);
  Lift.move(-127);
  delay(270);
  Lift.move(0);
  moveRobotPID("left turn",150,250,_autonSpeed);
  delay(150);
  shoot(false);
  lcd::set_text(4,to_string(BLUEFRONT.getTime()));
  Puncher.move(0);

  //delay(250);

}
