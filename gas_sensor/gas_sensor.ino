#include<LiquidCrystal.h>

LiquidCrystal lcd(12 , 11 , 5 ,4 ,3 ,2);
int Gas = 9;
int redLed = 7;
int greenLed = 6;

void setup() {

pinMode(Gas , INPUT);
  
}

void loop() {

  if(digitalRead(Gas) == HIGH){
    lcd.setCursor(0,0);
    lcd.print("Gas Detected Yes ");
    digitalWrite(7 , HIGH);
    digitalWrite(6, LOW);
  }
else{
  lcd.setCursor(0,0);
  lcd.print("Gas No Detected ");
  digitalWrite(6, HIGH);
  digitalWrite(7 ,LOW);
}
delay(500);
lcd.clear();

}
