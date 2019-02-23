#include "main.h"
#include "Robot/Global.hpp"
#include "Robot/functions.hpp"
#include "Robot/Motors.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

short middle = 0;
short page = 0;
bool hit = true;

/*********************
 * CREATE TWO SCREENS*
 ********************/

lv_obj_t * scr = lv_page_create(NULL, NULL);

lv_obj_t * scr2 = lv_page_create(NULL, NULL);


/*****************************************************
 * FUNCTION DECLRATION FOR AUTON SELECTION BUTTONS   *
 *****************************************************/

// Function that is called when the BLUEFRONT button is pressed //

  static lv_res_t blueFront(lv_obj_t * btn)
  {
    delay(100);
      count = 1;
    return LV_RES_OK;
  }

// Function that is called when the REDFRONT button is pressed //

  static lv_res_t redFront(lv_obj_t * btn)
  {

    delay(100);
      count = 0;
    return LV_RES_OK;
  }

// Function that is called when the BLUEBACK button is pressed //

  static lv_res_t blueBack(lv_obj_t * btn)
  {
    delay(100);
      count = 3;
    return LV_RES_OK;
  }

// Function that is called when the REDBACK button is pressed //

  static lv_res_t redBack(lv_obj_t * btn)
  {
    delay(100);
    count = 2;
    return LV_RES_OK;
  }


// Function that is called when the SKILLZ button is pressed //

  static lv_res_t skillz(lv_obj_t * btn)
  {
    delay(100);
      count = 4;
    return LV_RES_OK;
  }

 // Function that is called when the page2 button is pressed //

  static lv_res_t page2(lv_obj_t * btn)
  {

    delay(100);

  lv_scr_load(scr2);

    return LV_RES_OK;
  }

//Function that is called when the NONE button is pressed //

  static lv_res_t nothing(lv_obj_t * btn)
  {
    delay(100);
      count = 5;
    return LV_RES_OK;
  }

// Function that is called when the page1 button is pressed //
    static lv_res_t page1(lv_obj_t * btn)
    {
      delay(100);
        lv_scr_load(scr);
      return LV_RES_OK;
    }


static lv_style_t pagebtn;


// Function that draws the buttons and sets their actions //

  void lv_objects(void)
{
  // Loads the main screen //

  lv_scr_load(scr);
  // Sets the pagebtn style on the defult plain style and modify the style //
  lv_style_copy(&pagebtn, &lv_style_plain);
  pagebtn.body.border.color = LV_COLOR_GRAY;
  pagebtn.body.main_color = LV_COLOR_GRAY;
  pagebtn.body.radius = LV_RADIUS_CIRCLE;
  pagebtn.body.grad_color = LV_COLOR_GRAY;
  pagebtn.body.border.width = 2;
  pagebtn.body.empty = 1;
  pagebtn.body.opa = LV_OPA_0;

   // Gets rid of the scroll wheel //

   lv_page_set_sb_mode(scr2, LV_SB_MODE_OFF);
   lv_page_set_sb_mode(scr, LV_SB_MODE_OFF);

    /****************
     *     TITLES   *
     ****************/

    // Creates a label object that is used for the title and for the label on the first screen //

    lv_obj_t * label = lv_label_create(scr, NULL);
    lv_label_set_text(label, "Autonomous Selection");
    lv_obj_set_x(label, 145);

    // Creates a alabel object that is used for the title and for the label on the second screen //

    lv_obj_t * label2 = lv_label_create(scr2, NULL);
    lv_label_set_text(label2, "Autonomous Selection");
    lv_obj_set_x(label2, 145);


    /***********************
     * CREATE SIX BUTTONS  *
     ***********************/

    // Create a button for the blue front auton //

    lv_obj_t * blueF = lv_btn_create(lv_scr_act(), NULL);
    lv_btn_set_action(blueF, LV_BTN_ACTION_CLICK, blueFront);
    lv_obj_align(blueF, blueF,LV_ALIGN_CENTER, 100, 35);

    label = lv_label_create(blueF, NULL);
    lv_label_set_text(label, "BLUE FRONT");

    // Creates a button for the red front auton //

    lv_obj_t * redF = lv_btn_create(lv_scr_act(), NULL);
    lv_btn_set_action(redF, LV_BTN_ACTION_CLICK, redFront);
    lv_obj_align(redF, blueF, LV_ALIGN_CENTER, 150, 0);

    label = lv_label_create(redF, NULL);
    lv_label_set_text(label, "RED FRONT");

    // Create a button for the red back auton //

    lv_obj_t *redB = lv_btn_create(lv_scr_act(),NULL);
    lv_btn_set_action(redB, LV_BTN_ACTION_CLICK, redBack);
    lv_obj_align(redB,blueF,LV_ALIGN_OUT_BOTTOM_MID,0,10);

    label = lv_label_create(redB,NULL);
    lv_label_set_text(label,"RED BACK");

    // Create a button for the blue back auton //

    lv_obj_t *blueB = lv_btn_create(lv_scr_act(),NULL);
    lv_btn_set_action(blueB, LV_BTN_ACTION_CLICK, blueBack);
    lv_obj_align(blueB,redF,LV_ALIGN_OUT_BOTTOM_MID,0,10);

    label = lv_label_create(blueB,NULL);
    lv_label_set_text(label,"BLUE BACK");


 // Creates a button for the SKILLZ auton //

 lv_obj_t *illz = lv_btn_create(scr2,NULL);
 lv_btn_set_action(illz, LV_BTN_ACTION_CLICK, skillz);
 lv_obj_align(illz,blueF,LV_ALIGN_CENTER,0,10);

 label = lv_label_create(illz,NULL);
 lv_label_set_text(label,"SKILLZ");

 // Creates a button for no auton auton //

 lv_obj_t *none = lv_btn_create(scr2,NULL);
 lv_btn_set_action(none, LV_BTN_ACTION_CLICK, nothing);
 lv_obj_align(none,illz,LV_ALIGN_CENTER,150,0);

 label = lv_label_create(none,NULL);
 lv_label_set_text(label,"NONE");


 // Button to get back to the first page //

  lv_obj_t *secpage = lv_btn_create(scr2,NULL);
 lv_obj_set_size(secpage,60,60);
 lv_btn_set_action(secpage, LV_BTN_ACTION_CLICK, page1);
 lv_obj_align(secpage,none,LV_ALIGN_IN_LEFT_MID,-40,45);

 // Sets the style for all states the button can be in //

 lv_btn_set_style(secpage,LV_BTN_STYLE_PR, &pagebtn);
 lv_btn_set_style(secpage,LV_BTN_STYLE_INA, &pagebtn);
 lv_btn_set_style(secpage,LV_BTN_STYLE_TGL_PR, &pagebtn);
 lv_btn_set_style(secpage,LV_BTN_STYLE_TGL_REL, &pagebtn);
  lv_btn_set_style(secpage,LV_BTN_STYLE_REL, &pagebtn);

 // Button to get to the second page //

 lv_obj_t *firpage = lv_btn_create(scr,NULL);
 lv_obj_set_size(firpage,60,60);
 lv_btn_set_action(firpage, LV_BTN_ACTION_CLICK, page2);
 lv_obj_align(firpage,redF,LV_ALIGN_IN_LEFT_MID,-40,45);

 // Sets the style for all states the button can be in //
 lv_btn_set_style(firpage,LV_BTN_STYLE_PR, &pagebtn);
 lv_btn_set_style(firpage,LV_BTN_STYLE_INA, &pagebtn);
 lv_btn_set_style(firpage,LV_BTN_STYLE_TGL_PR, &pagebtn);
 lv_btn_set_style(firpage,LV_BTN_STYLE_TGL_REL, &pagebtn);
  lv_btn_set_style(firpage,LV_BTN_STYLE_REL, &pagebtn);

}

void initialize()
{


  lv_obj_t * scr3 = lv_page_create(NULL, NULL);
  lv_obj_t * label = lv_label_create(scr3, NULL);
  lv_label_set_text(label, "DO NOT MOVE");
  lv_obj_set_x(label, 145);

   lv_scr_load(scr3);
   delay(2400);
   lv_objects();
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled()
{
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
