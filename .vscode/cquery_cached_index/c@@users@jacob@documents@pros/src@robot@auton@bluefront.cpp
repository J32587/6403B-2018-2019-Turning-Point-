#include "main.h"
#include "../Motors.h"
#include "../functions.hpp"
#include "BlueFront.hpp"
Timer BLUEFRONT;
void BlueFront(void)
{
  const short unsigned int _autonSpeed = 105;
  BLUEFRONT.resetTimer();
  Task reload(DRAWBACK_AUTON_TASK);
  Intake.move(90);
  moveRobotPID("north",40,200,_autonSpeed);
  delay(195);
  Intake.move(0);
  moveRobotPID("south",39,250,_autonSpeed);
  moveRobotPID("right turn",97,230,_autonSpeed);//
  moveRobotPID("north",10,250,80);
  shoot(false);
  delay(550);
  Intake.move(100);
  moveRobotPID("north",22,250,_autonSpeed);
  shoot(false);
  delay(550);
  moveRobotPID("east",3.2,250,_autonSpeed);
  moveRobotPID("north",20,250,_autonSpeed);
  moveRobotPID("south",23,250,_autonSpeed);
  moveRobotPID("right turn",97,230,_autonSpeed);//
  moveRobotPID("south",13,250,_autonSpeed);
  Lift.move(-127);
  delay(270);
  Lift.move(0);
  moveRobotPID("left turn",159,250,_autonSpeed);//
  shoot(false);
  delay(550);
  moveRobotPID("right turn",4,200,_autonSpeed);//
  //moveRobotPID("")
  Intake.move(0);
  lcd::set_text(4,to_string(BLUEFRONT.getTime()));
  Puncher.move(0);

  //delay(250);

}
