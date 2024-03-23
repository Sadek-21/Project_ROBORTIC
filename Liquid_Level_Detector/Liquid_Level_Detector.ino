const int SensorPin = A0;
const int RLEDPin  = 2;
const int YLEDPin  = 3;
const int Y2LEDPin = 4;
const int BLEDPin  = 5;
const int B2LEDPin = 6;
const int GLEDPin  = 7;

void setup() 
{
  pinMode(SensorPin, INPUT);
  pinMode(RLEDPin, OUTPUT);
  pinMode(YLEDPin, OUTPUT); 
  pinMode(Y2LEDPin, OUTPUT);
  pinMode(B2LEDPin, OUTPUT); 
  pinMode(GLEDPin, OUTPUT); 
}
void loop() 
{
  int Val = analogRead(SensorPin);    // Read the analog value form sensor
  int Level = map(Val,0,1023,0,100);

  if(Level >= 90)
  {
    digitalWrite(RLEDPin, HIGH);
    digitalWrite(YLEDPin, HIGH);
    digitalWrite(Y2LEDPin,HIGH);
    digitalWrite(BLEDPin, HIGH);
    digitalWrite(B2LEDPin,HIGH);
    digitalWrite(GLEDPin, HIGH);
  }
  else if(Level >= 80 && Level < 90)
  {
    digitalWrite(RLEDPin, HIGH);
    digitalWrite(YLEDPin, HIGH);
    digitalWrite(Y2LEDPin,HIGH);
    digitalWrite(BLEDPin, HIGH);
    digitalWrite(B2LEDPin,HIGH);
    digitalWrite(GLEDPin, LOW);
  }
  else if(Level >= 60 && Level < 80)
  {
    digitalWrite(RLEDPin, HIGH);
    digitalWrite(YLEDPin, HIGH);
    digitalWrite(Y2LEDPin,HIGH);
    digitalWrite(BLEDPin, HIGH);
    digitalWrite(B2LEDPin,LOW);
    digitalWrite(GLEDPin, LOW);
  }
  else if(Level >= 40 && Level < 60)
  {
    digitalWrite(RLEDPin, HIGH);
    digitalWrite(YLEDPin, HIGH);
    digitalWrite(Y2LEDPin,HIGH);
    digitalWrite(BLEDPin, LOW);
    digitalWrite(B2LEDPin,LOW);
    digitalWrite(GLEDPin, LOW);
  }
  else if(Level >= 20 && Level < 40)
  {
    digitalWrite(RLEDPin, HIGH);
    digitalWrite(YLEDPin, HIGH);
    digitalWrite(Y2LEDPin,LOW);
    digitalWrite(BLEDPin, LOW);
    digitalWrite(B2LEDPin,LOW);
    digitalWrite(GLEDPin, LOW);
  }
  else if(Level < 20)
  {
    digitalWrite(RLEDPin, HIGH);
    digitalWrite(YLEDPin, LOW);
    digitalWrite(Y2LEDPin,LOW);
    digitalWrite(BLEDPin, LOW);
    digitalWrite(B2LEDPin,LOW);
    digitalWrite(GLEDPin, LOW);
  }
  else
  {
    digitalWrite(RLEDPin, LOW);
    digitalWrite(YLEDPin, LOW);
    digitalWrite(Y2LEDPin,LOW);
    digitalWrite(BLEDPin, LOW);
    digitalWrite(B2LEDPin,LOW);
    digitalWrite(GLEDPin, LOW);
  }
  
}


