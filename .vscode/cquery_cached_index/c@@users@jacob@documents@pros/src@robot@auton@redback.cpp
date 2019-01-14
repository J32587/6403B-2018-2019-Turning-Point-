#include "main.h"
#include "../Motors.h"
#include "../functions.hpp"
#include "RedBack.hpp"
Timer REDBACK;
void RedBack(void)
{
const short unsigned int _autonSpeed = 100;
REDBACK.resetTimer();
Intake.move(127);
moveRobotPID("north,",34,250,_autonSpeed);
delay(290);
Intake.move(0);
moveRobotPID("left turn",120, 250, _autonSpeed);
delay(250);
moveRobotPID("south",12,250,_autonSpeed);
delay(150);
Lift.move(-127);
delay(270);
Lift.move(-127);
lcd::set_text(4,std::to_string(REDBACK.getTime()));

}
