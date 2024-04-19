#include <LiquidCrystal.h>

  LiquidCrystal lcd(13, 12, 11, 10,  9,  8);

//Define the Pin Numbers
const int CAPTEUR = 2;
const int REMPLISSAGE = 7;
const int VIDANGE = 6;
 
void setup ()  
{   
  lcd.begin(20, 4);
  pinMode (CAPTEUR, INPUT); 
  pinMode(REMPLISSAGE, OUTPUT);  
  pinMode(VIDANGE, OUTPUT);  

   
  lcd.setCursor(0,0);
  lcd.print(" DETECTEUR DE PLUIE ");
}  
void loop ()  
{
  int Sensor = digitalRead(CAPTEUR);  //get reading from Sensor
  
  if (Sensor == HIGH) //If Sensor Detected the Rain
  {
    digitalWrite(REMPLISSAGE, HIGH);
    digitalWrite(VIDANGE, LOW);
    
    lcd.setCursor(0, 1);
    lcd.print(" La Pluie Arrive...    ");
    //delay(100);
  }
  else
  {
    lcd.setCursor(0, 1);
    lcd.print("    PAS DE PLUIE !      ");
    digitalWrite(REMPLISSAGE, LOW);
    digitalWrite(VIDANGE, HIGH);
  }
}
