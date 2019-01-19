#include "main.h"
#include "../Motors.h"
#include "../functions.hpp"
#include "BlueBack.hpp"
Timer BLUEBACK;
void BlueBack(void)
{
BLUEBACK.resetTimer();
const short unsigned int _autonSpeed = 100;
Task reload(DRAWBACK_AUTON_TASK);
Intake.move(60);
moveRobotPID("north",46,250,_autonSpeed);
delay(390);
Intake.move(0);
moveRobotPID("right turn",97, 250, _autonSpeed);
moveRobotPID("south",13,250,_autonSpeed);
Lift.move(-127);
delay(270);
Lift.move(0);
moveRobotPID("west",3,260,_autonSpeed);
moveRobotPID("north",11,260,_autonSpeed);
shoot(false);
delay(550);
moveRobotPID("east",10.5,250,_autonSpeed);
moveRobotPID("north",46,250,_autonSpeed);
lcd::set_text(4,std::to_string(BLUEBACK.getTime()));

}
