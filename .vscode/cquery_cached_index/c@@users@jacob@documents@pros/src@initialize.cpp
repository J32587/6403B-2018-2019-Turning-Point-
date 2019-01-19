#include "main.h"
#include "Robot/Motors.h"
#include "Robot/Global.hpp"
#include "Robot/functions.hpp"

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
  delay(100);
  middle = 0;
           }

}


//***************** Auton Selection Functions *****************//
void selectAuton()
{
middle = 0;
lcd_clear(); //removes any pre-existing text
while(middle == 0)
  {
lcd::register_btn1_cb(buttonMid);
  switch(count)
   {
case 0 :

lcd::set_text(3,"               Red Front");

lcd::register_btn2_cb(buttonAdd);

lcd::register_btn0_cb(buttonSub);

break;
case 1 :

lcd::set_text(3,"               Blue Front");

lcd::register_btn2_cb(buttonAdd);

lcd::register_btn0_cb(buttonSub);

break;
case 2:

lcd::set_text(3,"               Red Back");

lcd::register_btn2_cb(buttonAdd);

lcd::register_btn0_cb(buttonSub);

break;
case 3 :

lcd::set_text(3,"               Blue Back");

lcd::register_btn2_cb(buttonAdd);

lcd::register_btn0_cb(buttonSub);

break;
case 4 :
lcd::set_text(3,"                    Skillz");

lcd::register_btn2_cb(buttonAdd);

lcd::register_btn0_cb(buttonSub);

break;
default :
count = 0;
    }
		delay(20);
  }
  lcd_clear();
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize()
{
	lcd::initialize();
  lcd::set_text(3,"               DO NOT MOVE"); //the spaces are used to put the text in the middle of the screen
  delay(2000);
  lcd::clear_line(3);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled()
{
selectAuton();
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {


}
