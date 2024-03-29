/*---------------------LCD--------------------*/
#include "SparkSoftLCD.h"
#define LCD_TX 2

SparkSoftLCD lcd = SparkSoftLCD(LCD_TX);
/*--------------------------------------------------*/
/*---------------------HUMIDITIE--------------------*/
#include <dht.h>
dht DHT;
#define DHT22_PIN 5

int a ;
float hum;
float temp;
/*--------------------------------------------------*/
/*---------------------MOTOR--------------------*/
// Motor A
int enA = 9;
int in1 = 8;
int in2 = 7;
 
// Motor B
int enB = 3;
int in3 = 5;
int in4 = 4;

int MotorSpeed1 = 0;
int MotorSpeed2 = 0;
/*--------------------------------------------------*/

/*---------------------Joystick --------------------*/
int joyVert = A0; // Vertical  
int joyHorz = A1; // Horizontal

int joyposVert = 512;/*Joystick Values - Start at 512 (middle position)becaus in the ardouino its start from 0-1023 so 512 is good one so from 0-512==Backward and -512-1023 Forward*/
int joyposHorz = 512;  
/*--------------------------------------------------*/

void setup() 
{ 
  /*---------------------MOTOR--------------------*/
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  // Motor A
  digitalWrite(enA, LOW); //disable the motor first 
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  // Motor B
  digitalWrite(enB, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
/*--------------------------------------------------*/

  pinMode(LCD_TX, OUTPUT);
  lcd.begin(9600);
  lcd.clear();
  lcd.cursor(0);
  show_setup();
  delay(500);
 
}

void loop() {
/*---------------------MOTOR--------------------*/
	joyposVert = analogRead(joyVert);  //read the joystick
	joyposHorz = analogRead(joyHorz);
 
	if (joyposVert < 460) // we chose 460 because the joustick is not perfect 
	{
		digitalWrite(in1, LOW);  // Set Motor A backward
		digitalWrite(in2, HIGH);
		digitalWrite(in3, LOW);  	// Set Motor B backward
		digitalWrite(in4, HIGH);
 /* so if we go Backward and as we pull the joystick down the number on the analog input are gooing 
 to get lower and we want the motor to go faster so */
		joyposVert = joyposVert - 460;
    joyposHorz = joyposHorz * -1;

		MotorSpeed1 = map(joyposVert, 0, 460, 0, 255);
		MotorSpeed2 = map(joyposVert, 0, 460, 0, 255);
 
	}
	else if (joyposVert > 564)
	{
		digitalWrite(in1, HIGH);// Set Motor A forward
		digitalWrite(in2, LOW);
		digitalWrite(in3, HIGH); // Set Motor B forward
		digitalWrite(in4, LOW);
 
		MotorSpeed1 = map(joyposVert, 564, 1023, 0, 255); 	//Determine Motor Speeds
		MotorSpeed2 = map(joyposVert, 564, 1023, 0, 255); 
 
	}
	else
	{
		MotorSpeed1 = 0;// This is Stopped
		MotorSpeed2 = 0; 
	}
/* now will set the steering */
	if (joyposHorz < 460)
	{// Move Left
		joyposHorz = joyposHorz - 460; 
		joyposHorz = joyposHorz * -1;  
 
		joyposHorz = map(joyposHorz, 0, 460, 0, 255); 
			  
		MotorSpeed1 = MotorSpeed1 - joyposHorz; //spin the left motor slower
		MotorSpeed2 = MotorSpeed2 + joyposHorz; //spin the right motor faster
 
		if (MotorSpeed1 < 0)MotorSpeed1 = 0; 	
		if (MotorSpeed2 > 255)MotorSpeed2 = 255;
	}
	else if (joyposHorz > 564)
	{// Move Right

		joyposHorz = map(joyposHorz, 564, 1023, 0, 255);  
			  
		MotorSpeed1 = MotorSpeed1 + joyposHorz; //spin the right motor faster
		MotorSpeed2 = MotorSpeed2 - joyposHorz;//spin the left motor slower
 
		if (MotorSpeed1 > 255)MotorSpeed1 = 255;// Don't exceed range of 0-255 for motor speeds
		if (MotorSpeed2 < 0)MotorSpeed2 = 0;		  
 
	}
 
	if (MotorSpeed1 < 8)MotorSpeed1 = 0;// Adjust to prevent "buzzing" at very low speed
	if (MotorSpeed2 < 8)MotorSpeed2 = 0;
 
	analogWrite(enA, MotorSpeed1);   	// Set the motor speeds
	analogWrite(enB, MotorSpeed2);
/*--------------------------------------------------*/
/*---------------------HUMIDITIE--------------------*/
    a = DHT.read22(DHT22_PIN);
  hum = DHT.humidity;
  temp = DHT.temperature;
  /*if ()
  {
    lcd.clear();
    lcd.cursorTo(0, 1);
    lcd.print("Humiditie:");
    lcd.print(hum);
    lcd.print(17 , 1);
    lcd.println("%");

    lcd.cursorTo(0, 0);
    lcd.print("Temperature:");
    lcd.print(temp);
    lcd.print(19 , 1);
    lcd.println("C");

    Serial.print("Humiditie :");
    Serial.print(hum);
    Serial.println("%");
    Serial.print("Temperature :");
    Serial.print(temp);
    Serial.println("C");
    delay(500);
  }*/
  /*--------------------------------------------------*/

}



void show_setup() {
  
/* lcd.print("I am setting up!");
 lcd.cursorTo(0,1);
 delay(200);
 for (byte i = 0; i <= 15; i++ ) {
     delay(150);
     lcd.scroll(true); // scroll display to the right
 }*/
 delay(500);
 lcd.print("Hello This is my ROBOTIC CAR");
 
 for (byte i = 0; i <=28 ; i++ ) {
     delay(150);
       // scroll back to the left, revealing our new text
     lcd.scroll(false);
 }
 
}






































































































    /*lcd.clear();
    lcd.cursor(2);
    lcd.print("Arming");
    delay(1500);
    lcd.clear();
      // hidden cursor
    lcd.cursor(0);
    lcd.print("16");
    lcd.cursorTo(2,1);
    lcd.print("---------------*");
    delay(1000);
    for( byte i = 15; i >= 1; i-- ) {
        
        lcd.scroll(false);
        
        // as we scroll left, we need to move our cursor to
        // the right to continue to show our countdown
        //
        // in this way, we achieve the sense that a fuse is getting
        // shorter...
        lcd.cursorTo(1,1 + (16 - i) );
        lcd.print(i, DEC);
        delay(1000);
     }
    
      // make last bit disappear
    lcd.scroll(false);
    delay(500);
    lcd.clear();
    lcd.cursorTo(2, 10);
    lcd.print("(boom)");
    
    delay(2000);*/