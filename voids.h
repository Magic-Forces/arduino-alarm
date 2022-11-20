#include "config.h"

void signal(int time)
{
  digitalWrite(alarm, HIGH);
  delay(time);
  digitalWrite(alarm, LOW);
  delay(time);
}

void printAlert()
{
  lcd.setCursor(14, 0);
  lcd.write(0);
  lcd.print(alert);
}

void pumpOn()
{
  lcd.setCursor(7, 1);
  lcd.print("ON ");

  signal(400);

  digitalWrite(valve, HIGH);
  delay(2000);
  digitalWrite(pump, HIGH);
  pumpState = 1;
}

void pumpOff()
{
  lcd.setCursor(7, 1);
  lcd.print("OFF");

  signal(400);
  signal(400);

  digitalWrite(pump, LOW);
  delay(2000);
  digitalWrite(valve, LOW);
  pumpState = 0;
}

void alarmOn()
{
  if (pumpState == 1)
  {
    pumpOff();
  }
  
  lcd.noBacklight();
  lcd.setCursor(7, 0);
  lcd.print("ON ");
  alarmState = 1;
  
  printAlert();

  signal(200);
  signal(200);
}

void alarmOff()
{
  lcd.backlight();
  lcd.setCursor(7, 0);
  lcd.print("OFF");
  alarmState = 0;

  alert = 0;
  printAlert();

  signal(200);
}

void checkState(int pin)
{
  if (pin == ch1)
  {
    alarmPinCheck = digitalRead(ch1);

    if (alarmPinCheckOld == 0 && alarmPinCheck == 1)
    {
      if (alarmState == 0)
      {
        alarmOn();
      }
      else
      {
        alarmOff();
      }
    }
    alarmPinCheckOld = alarmPinCheck;
  }
  else if (pin == ch2)
  {
    pumpPinCheck = digitalRead(ch2);

    if (pumpPinCheckOld == 0 && pumpPinCheck == 1)
    {
      if (pumpState == 0 && alarmState == 0)
      {
        pumpOn();
      }
      else if (pumpState == 1)
      {
        pumpOff();
      }
    }
    pumpPinCheckOld = pumpPinCheck;
  }
}