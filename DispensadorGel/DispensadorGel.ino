#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

int trig = 7;
int echo = 8;
int relay = 13;
int tiempo;
int distancia;
int accionar=0;

void setup()
{
  pinMode(relay, OUTPUT);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void loop()
{
  digitalWrite(trig, HIGH);
  delay(1000);
  digitalWrite(trig, LOW);
  tiempo= pulseIn(echo, HIGH);
  distancia = tiempo / 58.2;
  
  if (distancia < 10) 
    {
    digitalWrite(relay, HIGH);
    accionar=accionar+1;
    lcd.setCursor(0,0);
    lcd.print("Num.Accionadas");
    lcd.setCursor(6,1);
    lcd.print(" Gracias");
    lcd.setCursor(3,1);
    lcd.print(accionar);
    }
  else
    {
    digitalWrite(relay, LOW);
    }
}
