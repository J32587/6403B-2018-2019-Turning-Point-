#include "main.h"
#include "../Motors.h"
#include "../functions.hpp"
#include "RedFront.hpp"


void RedFront(void)
{
const short unsigned int _autonSpeed = 100;
Task reload(DRAWBACK_AUTON_TASK);
moveRobotPID("left turn",97,250,_autonSpeed);
delay(250);
moveRobotPID("north",40,250,_autonSpeed);
delay(250);
Intake.move(100);
delay(400);
moveRobotPID("south",43,250,_autonSpeed);
delay(250);
moveRobotPID("right turn",97,250,_autonSpeed);
delay(250);
moveRobotPID("north",3,250,50);
shoot(true);
delay(250);
moveRobotPID("north",28,250,_autonSpeed);
shoot(false);
moveRobotPID("south",28,250,_autonSpeed);
delay(250);


}
