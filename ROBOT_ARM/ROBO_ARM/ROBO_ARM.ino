#include <Servo.h>


const int LeftJoystickX = A0;// We Define constants for joystick pins
const int LeftJoystickY = A1;
const int RightJoystickX = A2;
const int RightJoystickY = A3;


const int BaseServoPin = 2;// We Define servo pins
const int ElbowServoPin = 3;
const int WristServoPin = 4;
const int JawsServoPin = 5;


const int JoystickCenter = 512;// We Define joystick center and freezone
const int JoystickFreezone = 50;


Servo baseServo; // We Define servo objects
Servo elbowServo;
Servo wristServo;
Servo jawsServo;

int delayTime = 10;

void setup() {

  baseServo.attach(BaseServoPin);
  elbowServo.attach(ElbowServoPin);
  wristServo.attach(WristServoPin);
  jawsServo.attach(JawsServoPin);
}

void loop() {
  
  int leftJoystickX = analogRead(LeftJoystickX);// now will Read joystick values
  int leftJoystickY = analogRead(LeftJoystickY);
  int rightJoystickX = analogRead(RightJoystickX);
  int rightJoystickY = analogRead(RightJoystickY);

  int baseAngle = map(leftJoystickX, 0, 1023, 0, 180);
  int elbowAngle = map(leftJoystickY, 0, 1023, 0, 180);
  int wristAngle = map(rightJoystickX, 0, 1023, 0, 180);
  int jawsAngle = map(rightJoystickY, 0, 1023, 0, 180);

  // We apply freezone to joystick values
  if (abs(leftJoystickX - JoystickCenter) <= JoystickFreezone) {  //function abs() calculates the absolute value of its argument.
    baseAngle = 90; // Center position
  }
  if (abs(leftJoystickY - JoystickCenter) <= JoystickFreezone) {
    elbowAngle = 90; 
  }
  if (abs(rightJoystickX - JoystickCenter) <= JoystickFreezone) {
    wristAngle = 90; 
  }
  if (abs(rightJoystickY - JoystickCenter) <= JoystickFreezone) {
    jawsAngle = 90; 
  }

 
  baseServo.write(baseAngle); // We move servos to mapped angles
  elbowServo.write(elbowAngle);
  wristServo.write(wristAngle);
  jawsServo.write(jawsAngle);

  delay(delayTime);
}
















































/*
#include <Servo.h>
#define STEPS 100
const int Lefft = A0 ;
const int Right = A1 ;
const int Lefft1 = A4 ;
const int Right1 = A5 ;
const int UP = A2 ;
const int DOWN = A3 ;
const int Open = A6 ;
const int Close = A3 ;
const int Servo1pin = 2 ;
const int Servo2pin = 3 ;
const int Servo3pin = 4 ;
const int Servo4pin = 5 ;

int freezone = 10;

// the previous reading from the analog input
int Servolangle = 90;
int delayTime = 1;

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;


void setup() {

  int L_first = analogRead(Lefft);
  int R_first = analogRead(Right);
  int L1_first = analogRead(Lefft1);
  int R1_first = analogRead(Right1);
  int U_first = analogRead(UP);
  int D_first = analogRead(DOWN);
  int O_first = analogRead(Open);
  int C_first = analogRead(Close);

  servo1.attach(Servo1pin);
  servo1.attach(Servo2pin);
  servo1.attach(Servo3pin);
  servo1.attach(Servo4pin);
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
/*
}*/