#include "main.h"
#include "Robot/Motors.h"
#include "Robot/functions.hpp"
#include "Robot/Global.hpp"

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol()
{
// deadzone variable deleration and inzializtion //
int X1 = 0;
int X4 = 0;
int Y3 = 0;
float liftTarget;
float liftError;
int finalPower;
const short _deadzone = 16;
const float _kp = .7;

// Tasks for the shooting and double shooting //
Task DrawBack (DRAWBACK_TASK);
	while (true)
	{
      //Creates a deadzone for the joystick driver control //
			if (abs(Controller1.get_analog(ANALOG_RIGHT_X)) > _deadzone)
			X1 = Controller1.get_analog(ANALOG_RIGHT_X);
			else X1 = 0;

			if (abs(Controller1.get_analog(ANALOG_LEFT_X)) > _deadzone)
			X4 = Controller1.get_analog(ANALOG_LEFT_X);
			else X4 = 0;

			if (abs(Controller1.get_analog(ANALOG_LEFT_Y)) > _deadzone)
			Y3 = Controller1.get_analog(ANALOG_LEFT_Y);
			else Y3 = 0;

        // Sets the motor power according to the user input //
				LFDrive.move(Y3 + X4);
				RFDrive.move(Y3 - X4);
				LBDrive.move(Y3 + X4);
				RBDrive.move(Y3 - X4);

      // User control for the intake //
			if (Controller1.get_digital(E_CONTROLLER_DIGITAL_R1))
		  Intake.move(127);
			else if (Controller1.get_digital(E_CONTROLLER_DIGITAL_L1))
			Intake.move(-127);
			else
			Intake.move(0);

// User control for the lift //
	if(Controller1.get_digital(E_CONTROLLER_DIGITAL_R2))
 {
	 Lift.move(-127);
	 liftTarget = Lift.get_position();
 }
	else if(Controller1.get_digital(E_CONTROLLER_DIGITAL_L2))
	{
	Lift.move(127);
	liftTarget = Lift.get_position();
}
	else
	{

	liftError = liftTarget - Lift.get_position();

	if(abs(liftError) < 5) liftError = 0;

  finalPower = liftError * _kp;
	Lift.move(finalPower);
	}


  // User control the allows the driver to execute the DoubleShoot task by pressing A //
	if(Controller1.get_digital(E_CONTROLLER_DIGITAL_B)) DOUBLE_SHOOT();
	else SDSD = false;

  // User control that allows the driver to execute the drawBack task //
	if(Controller1.get_digital(E_CONTROLLER_DIGITAL_Y)) drawBack = true;
	else drawBack = false;

	if(Controller1.get_digital(E_CONTROLLER_DIGITAL_A))
	Angler.move(-127);

	else if (Controller1.get_digital(E_CONTROLLER_DIGITAL_X))
	Angler.move(127);

	else if (angleUp.get_value() && !Controller1.get_digital(E_CONTROLLER_DIGITAL_X))
	Angler.move(10);

	else if (angleDown.get_value() && !Controller1.get_digital(E_CONTROLLER_DIGITAL_A))
	Angler.move(-10);

   // Delay so the Brain doesnt die //
   delay(20);
	}
}
