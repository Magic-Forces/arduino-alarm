#include "voids.h"

void loop()
{
  checkState(ch1);
  checkState(ch2);

  while (alarmState == 1)
  {
    if (digitalRead(ups) == 1 || analogRead(pir0) > 500 || analogRead(pir1) > 500)
    {
      alert++;
      printAlert();
      
      digitalWrite(alarm, HIGH);

      unsigned long timer = millis();
      while (millis() <= (timer + 180000)) //3 minutes
      {
        checkState(ch1);
        if (alarmState == 0)
        {
          break;
        }
      }
      digitalWrite(alarm, LOW);
    }
    checkState(ch1);
  }
}