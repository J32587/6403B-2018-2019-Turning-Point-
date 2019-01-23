#include "main.h"
#include "../Motors.h"
#include "../functions.hpp"
#include "RedBack.hpp"
Timer REDBACK;
void RedBack(void)
{
const short _autonSpeed = 100;
const short _settleTime = _settleTime;
Task reload(DRAWBACK_TASK);
REDBACK.resetTimer();
Intake.move(60);
moveRobotPID("north",46,_settleTime,_autonSpeed);
delay(390);
Intake.move(0);
moveRobotPID("left turn",97, _settleTime, _autonSpeed);
moveRobotPID("south",13,_settleTime,_autonSpeed);
Lift.move(-127);
delay(270);
Lift.move(0);
moveRobotPID("east",2,_settleTime,_autonSpeed);
moveRobotPID("north",11,_settleTime,_autonSpeed);
shoot();
delay(550);
moveRobotPID("west",10.5,_settleTime,_autonSpeed);
moveRobotPID("north",46,_settleTime,_autonSpeed);
REDBACK.getTime();

}
