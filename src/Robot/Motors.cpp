#include "main.h"
#include "Motors.h"

//Define motors, controller, and sensors
Controller Controller1 (E_CONTROLLER_MASTER);
Motor LFDrive (leftFrontDrive_Port, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_COUNTS);
Motor RFDrive (rightFrontDrive_Port, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS);
Motor LBDrive (leftBackDrive_Port, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS);
Motor RBDrive (rightBackDrive_Port, E_MOTOR_GEARSET_18, true, E_MOTOR_ENCODER_COUNTS);
Motor Lift (lift_Port, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
Motor Intake (intake_Port, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_COUNTS);
Motor Puncher (puncher_Port, E_MOTOR_GEARSET_18, false, E_MOTOR_ENCODER_DEGREES);
ADIGyro myGyro (gyro_Port);
