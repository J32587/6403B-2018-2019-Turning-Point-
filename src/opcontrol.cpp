#include "main.h"
#include "Robot/Motors.h"
#include "Robot/functions.hpp"


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

	int X1 = 0;
	int X4 = 0;
	int Y3 = 0;
 const	int _deadzone = 16;
Task ReloadPuncherTask (reloadPuncher);
	while (true)
	{
			// Check deadzones for base control
			if (abs(Controller1.get_analog(ANALOG_RIGHT_X)) > _deadzone)
			{
			X1 = Controller1.get_analog(ANALOG_RIGHT_X);
		  }
			else X1 = 0;
			if (abs(Controller1.get_analog(ANALOG_LEFT_X)) > _deadzone)
			{
			X4 = Controller1.get_analog(ANALOG_LEFT_X);
		  }
			else X4 = 0;
			if (abs(Controller1.get_analog(ANALOG_LEFT_Y)) > _deadzone)
			{
			Y3 = Controller1.get_analog(ANALOG_LEFT_Y);
		  }
			else Y3 = 0;
				LFDrive.move(-(Y3 + X4 + X1));
				RFDrive.move(-(Y3 - X4 - X1));
				LBDrive.move(-(Y3 - X4 + X1));
				RBDrive.move(-(Y3 + X4 - X1));

			if (Controller1.get_digital(E_CONTROLLER_DIGITAL_R1)){
				Intake.move(95);
			}
			else if (Controller1.get_digital(E_CONTROLLER_DIGITAL_L1)){
				Intake.move(-95);
			}
			else {
				Intake.move(0);
	}
	if(Controller1.get_digital(E_CONTROLLER_DIGITAL_R2))
	Lift.move(-120);
	else if(Controller1.get_digital(E_CONTROLLER_DIGITAL_L2))
	Lift.move(120);
	else Lift.move(0);

	}
}
