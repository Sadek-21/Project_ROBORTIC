#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8, 7);

int Full  = A0;
int Half  = A1;
int Quatr = A2;
int Empty = A3;
int motor = 7;
int F , H , Q , E ;
void setup() 
{
  lcd.begin(20, 4);
  lcd.print("Tank Statu ....");
  pinMode(A0 , INPUT);
  pinMode(A1 , INPUT);
  pinMode(A2 , INPUT);
  pinMode(A3 , INPUT);
  pinMode( motor , OUTPUT);
}

void loop() 
{
  F = digitalRead(Full);
  H = digitalRead(Half);
  Q = digitalRead(Quatr);
  E = digitalRead(Empty);

  if ( F==1 && H==1 && Q==1 && E==1 )
  {
    lcd.setCursor(0,0);
    lcd.print(char(219));
    lcd.print(char(219));
    lcd.print(char(219));
    lcd.print(char(219));
    lcd.print(" ");
    lcd.setCursor(5,0);
    lcd.print("Full .....");
    lcd.setCursor(0,0);
    lcd.print("Motor is OFF    ");
    digitalWrite( motor , LOW);
  }
  else if ( F==0 && H==1 && Q==1 && E==1 )
  {
    lcd.setCursor(0,0);
    lcd.print(char(219));
    lcd.print(char(219));
    lcd.print(char(219));
    lcd.print("_");
    lcd.print(" ");
    lcd.setCursor(5,0);
    lcd.print("HALF .....");
    lcd.setCursor(0,0);
    lcd.print("Motor is OFF    ");
    digitalWrite( motor , LOW);
  }
  else if ( F==0 && H==0 && Q==1 && E==1 )
  {
    lcd.setCursor(0,0);
    lcd.print(char(219));
    lcd.print(char(219));
    lcd.print("_");
    lcd.print("_");
    lcd.print(" ");
    lcd.setCursor(5,0);
    lcd.print("QUATR .....");
    lcd.setCursor(0,0);
    lcd.print("Motor is ON    ");
    digitalWrite( motor , HIGH);
  }
  else if ( F==0 && H==0 && Q==0 && E==1 )
  {
    lcd.setCursor(0,0);
    lcd.print(char(219));
    lcd.print("_");
    lcd.print("_");
    lcd.print("_");
    lcd.print(" ");
    lcd.setCursor(5,0);
    lcd.print("EMPTY .....");
    lcd.setCursor(0,0);
    lcd.print("Motor is ON    ");
    digitalWrite( motor , HIGH);
  }
  else if ( F==0 && H==0 && Q==0 && E==0 )
  {
    lcd.setCursor(0,0);
    lcd.print("_");
    lcd.print("_");
    lcd.print("_");
    lcd.print("_");
    lcd.print(" ");
    lcd.setCursor(5,0);
    lcd.print("EMPTY 100% .....");
    lcd.setCursor(0,0);
    lcd.print("Motor is ON    ");
    digitalWrite( motor , HIGH);
  }
  else 
  {
    digitalWrite( motor , LOW);
    lcd.setCursor(0, 0);
    lcd.print(" Sensor Fail!...");
  }

}
