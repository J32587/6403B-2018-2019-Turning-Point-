#include "main.h"
#include "Motors.h"

// Defines the motors, sensors, and controller //
Controller Controller1 (CONTROLLER_MASTER);
Motor LFDrive (12, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_COUNTS);
Motor RFDrive (1, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS);
Motor LBDrive (14, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS);
Motor RBDrive (11, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_COUNTS);
Motor Lift (7, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor Intake (2, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS);
Motor Puncher (10, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor Angler (19, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
ADIGyro myGyro (1);
ADIButton angleDown(2);
ADIButton angleUp(3);
