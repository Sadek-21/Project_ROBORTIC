void setup() 
{
  pinMode(13,OUTPUT); 
}
void loop() 
{
  float Sensor = analogRead(A0);  
  int Temp = (Sensor*500)/1023; // Storing value in Degree Celsius
  
  if(Temp < 50) //If Temperature is Less Than 15'C
  {
    digitalWrite(13,HIGH);  //Turn ON the Heater
  }
  else
  {
    digitalWrite(13,LOW);  //Turn OFF the Heater
  }
}
