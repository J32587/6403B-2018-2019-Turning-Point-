#include "main.h"
#include "../Motors.h"
#include "../functions.hpp"
#include "BlueBack.hpp"

Timer BLUEBACK;
void BlueBack(void)
{
BLUEBACK.resetTimer();
const short _autonSpeed = 100;
const short _settleTime = 250;
Task reload(DRAWBACK_TASK);
Intake.move(60);
moveRobotPID("north",46,_settleTime,_autonSpeed);
delay(390);
Intake.move(0);
moveRobotPID("right turn",97, _settleTime, _autonSpeed);
moveRobotPID("south",13,_settleTime,_autonSpeed);
Lift.move(-127);
delay(270);
Lift.move(0);
moveRobotPID("west",3,_settleTime,_autonSpeed);
moveRobotPID("north",11,_settleTime,_autonSpeed);
shoot();
delay(550);
moveRobotPID("east",10.5,_settleTime,_autonSpeed);
moveRobotPID("north",46,_settleTime,_autonSpeed);
BLUEBACK.getTime();

}
