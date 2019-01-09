#include "main.h"

#ifndef MOTORS_H
#define MOTORS_H

#define leftFrontDrive_Port (15)
#define rightFrontDrive_Port (1)
#define leftBackDrive_Port (16)
#define rightBackDrive_Port (17)
#define puncher_Port (18)
#define lift_Port (7)
#define intake_Port (2)
#define angler_Port (6)
#define gyro_Port ('A')
#define controller CONTROLLER_MASTER

extern Motor LFDrive;
extern Motor RFDrive;
extern Motor LBDrive;
extern Motor RBDrive;
extern Motor Puncher;
extern Motor Angler;
extern Motor Lift;
extern Motor Intake;
extern Controller Controller1;
extern ADIGyro myGyro;





#endif
