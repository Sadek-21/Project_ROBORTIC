#include <Servo.h>
#define STEPS 100
const int Lefft = A0 ;
const int Right = A1 ;
const int UP = A2 ;
const int DOWN = A3 ;
const int Servo1pin = 2 ;
const int Servo2pin = 3 ;
const int Servo3pin = 4 ;
const int Servo4pin = 5 ;

int freezone = 10;

// the previous reading from the analog input
int Servolangle = 90;
int delayTime = 1;

Servo servo1;

void setup() {

  int L_first = analogRead(Lefft);
  int R_first = analogRead(Right);
  int U_first = analogRead(UP);
  int D_first = analogRead(DOWN);

  servo1.attach(Servo1pin);
  //Serial.begin(9600);
}

void loop() {
  int L_first = analogRead(Lefft);
  int R_first = analogRead(Right);
  int U_first = analogRead(UP);
  int D_first = analogRead(DOWN);

  int L = analogRead(Lefft);
  int R = analogRead(Right);
  int U = analogRead(UP);
  int D = analogRead(DOWN);
  
  if ( L >= L_first + freezone)
  {
    R = 0;
    L = map( L , L_first , 1023 , 0 , 180 );
    servo1.write(L);
    Serial.println(L);
    delay(delayTime);
  }
  else if ( R <= R_first - freezone)
  {
    L = 0;
    R = map( L , L_first , 1023 , 0 , 180 );
    servo1.write(R); 
    Serial.println(R);
    delay(delayTime);
  }
  else
  {
    R = 0;
    L = 0;
  }
  if ( U >= U_first + freezone)
  {
    D = 0;
    U = map( U , L_first , 1023 , 0 , 180 );
    servo1.write(U);
    Serial.println(U);
    delay(delayTime);
  }
  else if ( D <= D_first - freezone)
  {
    U = 0;
    D = map( D , L_first , 1023 , 0 , 180 );
    servo1.write(D);
    Serial.println(D);
    delay(delayTime);
  }
  else
  { 
    U = 0;
    D = 0;
  }

  /*analogWrite(Servo1pin, L);
  analogWrite(Servo2pin, R); 
  analogWrite(Servo3pin, U);
  analogWrite(Servo4pin, D);*/

}