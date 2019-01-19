#include "main.h"
#include "../Motors.h"
#include "../functions.hpp"
#include "Skillz.hpp"

Timer SKILLZ;
void Skillz(void)
{
  const short unsigned int _autonSpeed = 97;
  SKILLZ.resetTimer();
  Task reload(DRAWBACK_AUTON_TASK);
  moveRobotPID("north",50,250,120);
  Intake.move(120);
  delay(300);
  Intake.move(0);
  Intake.move(-50);
  delay(100);
  Intake.move(0);
  moveRobotPID("south",50,250,_autonSpeed);
  moveRobotPID("left turn",97,250,_autonSpeed);
  moveRobotPID("north",53.5,250,_autonSpeed);
  shoot(false);
  delay(540);
  Intake.move(100);
  moveRobotPID("north",29,250,_autonSpeed);
  shoot(false);
  delay(540);
  reload.suspend();
  delay(100);
  Intake.move(0);
  reload.resume();
  moveRobotPID("west",3.75,250,_autonSpeed);
  moveRobotPID("north",19,250,_autonSpeed);
  Intake.move(100);
  delay(400);
  Intake.move(0);
  moveRobotPID("south",52,250,_autonSpeed);
  moveRobotPID("east",6,250,_autonSpeed);
  moveRobotPID("right turn", 97,250,_autonSpeed);
  moveRobotPID("north",46,250,_autonSpeed);
  Intake.move(90);
  delay(285);
  Intake.move(0);
  delay(100);
  moveRobotPID("west",4,250,_autonSpeed);
  moveRobotPID("left turn",96,250,_autonSpeed);
  shoot(false);
  delay(545);
  Intake.move(100);
  moveRobotPID("north",25,230,_autonSpeed);
  shoot(false);
  delay(545);
  reload.suspend();
  delay(100);
  reload.resume();
  moveRobotPID("west",3.25,250,_autonSpeed);
  moveRobotPID("north",24,250,_autonSpeed);
  moveRobotPID("south",26,250,_autonSpeed);
  moveRobotPID("right turn",97,250,_autonSpeed);
  moveRobotPID("south",13,250,_autonSpeed);
  Lift.move(-127);
  delay(160);
  Lift.move(-127);
  delay(160);
  Lift.move(0);
  moveRobotPID("right turn",97,250,_autonSpeed);
  moveRobotPID("north",24,250,_autonSpeed);
  moveRobotPID("right turn",97,250,_autonSpeed);
  moveRobotPID("north",38,250,_autonSpeed);
  moveRobotPID("left turn",97,250,_autonSpeed);
  moveRobotPID("north",25,250,_autonSpeed);
  moveRobotPID("left turn",97,250,_autonSpeed);
  moveRobotPID("north",40,250,_autonSpeed);
  moveRobotPID("north",30,250,_autonSpeed);

  lcd::set_text(4,std::to_string(SKILLZ.getTime()));


}
