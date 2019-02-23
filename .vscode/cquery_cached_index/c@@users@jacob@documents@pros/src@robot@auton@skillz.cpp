#include "main.h"
#include "../Motors.h"
#include "../functions.hpp"
#include "Skillz.hpp"

Timer SKILLZ;
void Skillz(void)
{
  const short _autonSpeed = 97;
  const short _settleTime = 250;
  SKILLZ.resetTimer();
  Task reload(DRAWBACK_TASK);
  Task hold(holdLift);

  moveLift(400);

SKILLZ.getTime();


}
