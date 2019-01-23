#include "main.h"
#include "Robot/Global.hpp"
#include "Robot/functions.hpp"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

int middle = 0;
string auton = 0;

  static lv_res_t blueFront(lv_obj_t * btn)
  {
    static bool pressed = true;
    delay(100);
    if (pressed)
    {
      middle = 1;
      pressed = false;
      count = 1;
      auton = "BLUE FRONT";
    }
    return LV_RES_OK;
  }

  static lv_res_t redFront(lv_obj_t * btn)
  {
    static bool pressed = true;
    delay(100);
    if (pressed)
    {
      middle = 1;
      pressed = false;
      count = 0;
      auton = "RED FRONT";
    }
    return LV_RES_OK;
  }

  static lv_res_t blueBack(lv_obj_t * btn)
  {
    static bool pressed = true;
    delay(100);
    if (pressed)
    {
      middle = 1;
      pressed = false;
      count = 3;
      auton = "BLUE BACK";
    }
    return LV_RES_OK;
  }

  static lv_res_t redBack(lv_obj_t * btn)
  {
    static bool pressed = true;
    delay(100);
    if (pressed)
    {
      middle = 1;
      pressed = false;
      count = 2;
      auton = "RED BACK";
    }
    return LV_RES_OK;
  }

  void lv_tutorial_objects(void)
{

  //    static lv_style_t button_style;
  //       lv_style_copy(&button_style, &lv_style_plain);
  // button_style.body.radius = LV_RADIUS_CIRCLE;
  // button_style.body.main_color = vdb;
   //button_style.body.grad_color = TRANSP;
   //button_style.body.shadow.color = LV_COLOR_TRANSP;
   //button_style.body.shadow.width = 0;
   //button_style.body.border.width = 2;
   //button_style.body.border.color = LV_COLOR_BLACK;
   //button_style.text.color = LV_COLOR_WHITE;
   //button_style.text.letter_space = 1;


    /********************
     * CREATE A SCREEN  *
     ********************/
    lv_obj_t * scr = lv_page_create(NULL, NULL);
    lv_scr_load(scr);

    // Creates a screen object that has nothing displayed on it //
    lv_obj_t * none = lv_page_create(NULL,NULL);
    /****************
     *     TITLE    *
     ****************/
    while(middle == 0)
    {
    lv_obj_t * label = lv_label_create(scr, NULL);
    lv_label_set_text(label, "Autonomous Selection");
    lv_obj_set_x(label, 145);
    lv_obj_set_y(label,15);

    /***********************
     * CREATE FOUR BUTTONS
     ***********************/

    // Create a button for the blue front auton //
    lv_obj_t * blueF = lv_btn_create(lv_scr_act(), NULL);
    lv_btn_set_action(blueF, LV_BTN_ACTION_CLICK, blueFront);
    lv_obj_align(blueF, blueF,LV_ALIGN_CENTER, 100, 35);

    label = lv_label_create(blueF, NULL);
    lv_label_set_text(label, "BLUE FRONT");

    // Creates a button for the red front auton //
    lv_obj_t * redF = lv_btn_create(lv_scr_act(), NULL);
    lv_btn_set_action(blueF, LV_BTN_ACTION_CLICK, redFront);
    lv_obj_align(redF, blueF, LV_ALIGN_CENTER, 150, 0);

    label = lv_label_create(redF, NULL);
    lv_label_set_text(label, "RED FRONT");

    // Create a button for the red back auton //
    lv_obj_t *redB = lv_btn_create(lv_scr_act(),NULL);
    lv_btn_set_action(blueF, LV_BTN_ACTION_CLICK, redBack);
    lv_obj_align(redB,blueF,LV_ALIGN_OUT_BOTTOM_MID,0,10);

    label = lv_label_create(redB,NULL);
    lv_label_set_text(label,"RED BACK");

    // Create a button for the blue back auton //
    lv_obj_t *blueB = lv_btn_create(lv_scr_act(),NULL);
    lv_btn_set_action(blueF, LV_BTN_ACTION_CLICK, blueBack);
    lv_obj_align(blueB,redF,LV_ALIGN_OUT_BOTTOM_MID,0,10);

    label = lv_label_create(blueB,NULL);
    lv_label_set_text(label,"BLUE BACK");
    delay(20);
  }
    lv_scr_load(none);
  
}

void initialize()
{
  lv_tutorial_objects();



//	lcd::initialize();
//  lcd::set_text(3,"               DO NOT MOVE"); //the spaces are used to put the text in the middle of the screen
//  delay(2000);
//  lcd::clear_line(3);


}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled()
{
//selectAuton();
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
void competition_initialize()
{
}
