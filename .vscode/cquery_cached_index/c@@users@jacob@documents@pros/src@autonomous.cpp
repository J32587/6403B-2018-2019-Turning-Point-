#include "main.h"
#include "Robot/Auton/All_Autons.hpp"
#include "Robot/Global.hpp"


/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
 lv_obj_t * scr_none = lv_page_create(NULL, NULL);

void autonomous()
{
  // Swith statement that runs the choosen autonomous function //
  switch(count)
	{
case 0 :
RedFront();
lv_scr_load(scr_none);
break;

case 1 :
BlueFront();
lv_scr_load(scr_none);
break;

case 2 :
RedBack();
lv_scr_load(scr_none);
break;

case 3 :
BlueBack();
lv_scr_load(scr_none);
break;

case 4 :
Skillz();
lv_scr_load(scr_none);
break;

case 5:
break;

default:
count = 0;

 }
}
