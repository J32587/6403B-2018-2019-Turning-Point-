#include "main.h"
#include "Motors.h"

// Defines the motors, sensors, and controller //
Controller Controller1 (CONTROLLER_MASTER);
Motor LFDrive (3, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS);//
Motor RFDrive (4, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_COUNTS);
Motor LBDrive (13, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS);
Motor RBDrive (12, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_COUNTS);
Motor Lift (17, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor Intake (5, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS);
Motor Puncher (8, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_DEGREES);
Motor Angler (2, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
ADIGyro myGyro (8);
ADIButton angleDown(7);
ADIButton angleUp(6);
