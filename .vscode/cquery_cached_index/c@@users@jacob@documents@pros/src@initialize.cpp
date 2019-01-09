#include "main.h"
#include "Robot/Motors.h"
#include "Robot/Global.h"

int middle = 0;

void buttonAdd()
{
  static bool pressed = false;
  pressed = !pressed;
  if (pressed) count++;

}

void buttonSub()
{
  static bool pressed = false;
  pressed = !pressed;
  if (pressed) count--;
}

void buttonMid()
{
  static bool pressed = false;
  pressed = !pressed;
  if (pressed){
  middle = 1;
  delay(300);
  middle =0;
           }

}


//***************** Auton Selection Functions *****************//
void selectAuton()
{
middle = 0;
while(middle == 0)
  {
lcd::register_btn1_cb(buttonMid);
  switch(count)
   {
case 0 :

lcd::print(1,"Red Front");

lcd::register_btn2_cb(buttonAdd);

lcd::register_btn0_cb(buttonSub);

break;
case 1 :

lcd::print(1,"Blue Front");

lcd::register_btn2_cb(buttonAdd);

lcd::register_btn0_cb(buttonSub);

break;
case 2:

lcd::print(1,"Red Back");

lcd::register_btn2_cb(buttonAdd);

lcd::register_btn0_cb(buttonSub);

break;
case 3 :

lcd::print(1,"Blue Back");

lcd::register_btn2_cb(buttonAdd);

lcd::register_btn0_cb(buttonSub);

break;
case 4 :
lcd::print(1,"None");

lcd::register_btn2_cb(buttonAdd);

lcd::register_btn0_cb(buttonSub);

break;
default :
count = 0;
    }
  }
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	lcd::initialize();
  selectAuton();


}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}
