#include "main.h"
#include "../Motors.h"
#include "../functions.hpp"
#include "RedBack.hpp"
Timer REDBACK;
void RedBack(void)
{
const short unsigned int _autonSpeed = 100;
Task reload(DRAWBACK_AUTON_TASK);
REDBACK.resetTimer();
Intake.move(60);
moveRobotPID("north",46,250,_autonSpeed);
delay(390);
Intake.move(0);
moveRobotPID("left turn",97, 250, _autonSpeed);
moveRobotPID("south",13,250,_autonSpeed);
Lift.move(-127);
delay(270);
Lift.move(0);
moveRobotPID("east",2,260,_autonSpeed);
moveRobotPID("north",6.5,260,_autonSpeed);
shoot(false);
delay(550);
moveRobotPID("west",12.5,250,_autonSpeed);
moveRobotPID("north",46,250,_autonSpeed);
lcd::set_text(4,std::to_string(REDBACK.getTime()));

}
