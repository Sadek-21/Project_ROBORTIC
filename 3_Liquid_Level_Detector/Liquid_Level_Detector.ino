void setup() 
{
  pinMode(A0, INPUT);
  pinMode(2 , OUTPUT);
  pinMode(3 , OUTPUT); 
  pinMode(4 , OUTPUT);
  pinMode(6 , OUTPUT); 
  pinMode(7 , OUTPUT); 
}
void loop() 
{
  int Val = analogRead(A0);    // Read the analog value form sensor
  int Level = map(Val,0,1023,0,100);

  if(Level >= 90)
  {
    digitalWrite(2 , HIGH);
    digitalWrite(3 , HIGH);
    digitalWrite(4 ,HIGH);
    digitalWrite(5 , HIGH);
    digitalWrite(6 ,HIGH);
    digitalWrite(7 , HIGH);
  }
  else if(Level >= 80 && Level < 90)
  {
    digitalWrite(2 , HIGH);
    digitalWrite(3 , HIGH);
    digitalWrite(4 ,HIGH);
    digitalWrite(5 , HIGH);
    digitalWrite(6 ,HIGH);
    digitalWrite(7 , LOW);
  }
  else if(Level >= 60 && Level < 80)
  {
    digitalWrite(2 , HIGH);
    digitalWrite(3 , HIGH);
    digitalWrite(4 , HIGH);
    digitalWrite(5 , HIGH);
    digitalWrite(6 , LOW);
    digitalWrite(7 , LOW);
  }
  else if(Level >= 40 && Level < 60)
  {
    digitalWrite(2 , HIGH);
    digitalWrite(3 , HIGH);
    digitalWrite(4 , HIGH);
    digitalWrite(5 , LOW);
    digitalWrite(6 , LOW);
    digitalWrite(7 , LOW);
  }
  else if(Level >= 20 && Level < 40)
  {
    digitalWrite(2 , HIGH);
    digitalWrite(3 , HIGH);
    digitalWrite(4 , LOW);
    digitalWrite(5 , LOW);
    digitalWrite(6 , LOW);
    digitalWrite(7 , LOW);
  }
  else if(Level < 20)
  {
    digitalWrite(2 , HIGH);
    digitalWrite(3 , LOW);
    digitalWrite(4 , LOW);
    digitalWrite(5 , LOW);
    digitalWrite(6 , LOW);
    digitalWrite(7 , LOW);
  }
  else
  {
    digitalWrite(2 , LOW);
    digitalWrite(3 , LOW);
    digitalWrite(4 , LOW);
    digitalWrite(5 , LOW);
    digitalWrite(6 , LOW);
    digitalWrite(7 , LOW);
  }
  
}


