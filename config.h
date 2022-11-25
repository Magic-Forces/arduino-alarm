#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16, 2);

#define ch1 2
#define ch2 3
#define ups 4
#define led 5
#define pump 6
#define valve 7
#define alarm 8

#define pir0 A0
#define pir1 A1

int alarmPinCheck;
int alarmPinCheckOld = 0;
int alarmState = 0; // turned on at startup

int pumpPinCheck;
int pumpPinCheckOld = 0;
int pumpState = 1; //turned off at startup

int alert = 0;

byte bell[] = {
  B00000,
  B00100,
  B01110,
  B01110,
  B01110,
  B11111,
  B00000,
  B00100
};

void setup()
{
  pinMode(ch1, INPUT);
  pinMode(ch2, INPUT);
  pinMode(ups, INPUT);
  pinMode(pump, OUTPUT);
  pinMode(valve, OUTPUT);
  pinMode(alarm, OUTPUT);

  pinMode(pir0, INPUT);
  pinMode(pir1, INPUT);

  lcd.init();
  lcd.createChar(0, bell);

  lcd.setCursor(0, 0);
  lcd.print("ALARM:");
  lcd.setCursor(0, 1);
  lcd.print("PUMP:");
}