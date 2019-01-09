#include "main.h"

extern float frontLeftDrive;
extern float frontRightDrive;
extern float backLeftDrive;
extern float backRightDrive;
extern float Gyro;

class Timer {
private:
int lastTime = millis();

public:
int myTime;
int currentTime;
  int getTime()
  {
    myTime = millis();
    currentTime = myTime - lastTime;
    return currentTime;
  }

  void resetTimer()
  {
   lastTime = millis();
  }

};

int driveRightPos();
int driveLeftPos();
int inToTick(float inch);
int inToTickSide(float inch);
int sign(int in);
void setMotors(int mySpeedL,int mySpeedR);
void updateData();
void resetData();
