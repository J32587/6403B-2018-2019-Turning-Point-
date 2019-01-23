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
void lcd_clear();
int rightDrivePos();
int leftDrivePos();
int inToTick(float inch);
int inToTickSide(float inch);
int sign(int in);
void setMotors(int mySpeedL,int mySpeedR);
inline void updateDataP();
void resetData();
void DRAWBACK_TASK(void*);
void DOUBLE_SHOOT(void*);
void doubleShoot(void);
void shoot(void);
void moveRobotPID (const string direction, float target, float waitTime, int maxPower);

extern float frontLeftDrive;
extern float frontRightDrive;
extern float backLeftDrive;
extern float backRightDrive;
extern float Gyro;
