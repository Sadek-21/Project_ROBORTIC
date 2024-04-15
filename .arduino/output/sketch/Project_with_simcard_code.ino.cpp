#include <Arduino.h>
#line 1 "C:\\Users\\mohsa\\OneDrive\\Desktop\\Ardouino\\Project_ROBORTIC\\Project_with_simcard\\Project_with_simcard_code\\Project_with_simcard_code.ino"
#include <LiquidCrystal.h>
#include <SoftwareSerial.h>
#define button1 A0
#define button2 A1
#define button3 A2
#define RX  0
#define TX  1
LiquidCrystal lcd( 13 , 12 , 11 , 10 , 9 , 8);

SoftwareSerial sim800l(RX , TX); 



void setup()
{

  lcd.begin( 20 , 4 );
  pinMode(button1, INPUT_PULLUP); //The button is always on HIGH level, when pressed it goes LOW
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);
  pinMode( 1 , OUTPUT);
  pinMode( 3 , OUTPUT);
  sim800l.begin(9600);   //Module baude rate, this is on max, it depends on the version
  // Serial.begin(9600);   // modifiez la vitesse si nécéssaire entre 9600 et 115200
  delay(1000);
}
 
void loop()
{
  

  bool M = digitalRead(button1);   //We are constantly reading the button State
  bool A = digitalRead(button2);
  bool N = digitalRead(button3);
 
  if (M == LOW) {            //And if it's pressed
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sending SMS...");
    delay(200);                         //Small delay to avoid detecting the button press many times
    if (sendSMS("+212701965542", "Machine X has a problem.")) 
    {
      lcd.setCursor(0, 1);
      lcd.print("SMS sent!");
      Serial.println("SMS sent successfully.");
      digitalWrite( 2 , HIGH);
    } 
      else 
      {
      lcd.setCursor(0, 1);
      lcd.print("SMS failed!");
      Serial.println("Failed to send SMS.");
      digitalWrite( 3 , HIGH);
      }

    delay(2000); // Delay to show the result on the LCD
  }
  if (A == LOW) {            //And if it's pressed
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sending SMS...");
    delay(200);                         //Small delay to avoid detecting the button press many times
    if (sendSMS("+212701965542", "Machine X has a problem.")) 
    {
      lcd.setCursor(0, 1);
      lcd.print("SMS sent!");
      Serial.println("SMS sent successfully.");
      digitalWrite( 2 , HIGH);
    } 
      else 
      {
      lcd.setCursor(0, 1);
      lcd.print("SMS failed!");
      Serial.println("Failed to send SMS.");
      digitalWrite( 3 , HIGH);
      }

    delay(2000); // Delay to show the result on the LCD
  }
  if (N == LOW) {            //And if it's pressed
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sending SMS...");
    delay(200);                         //Small delay to avoid detecting the button press many times
    if (sendSMS("+212701965542", "Machine X has a problem.")) 
    {
      lcd.setCursor(0, 1);
      lcd.print("SMS sent!");
      Serial.println("SMS sent successfully.");
      digitalWrite( 2 , HIGH);
    } 
      else 
      {
      lcd.setCursor(0, 1);
      lcd.print("SMS failed!");
      Serial.println("Failed to send SMS.");
      digitalWrite( 3 , HIGH);
      }

    delay(2000); // Delay to show the result on the LCD
  }
}
 
bool sendSMS(const char* phoneNumber, const char* message) 
{
  sim800l.print("AT+CMGF=1\r");
  delay(100);
  sim800l.print("AT+CMGS=\"");
  sim800l.print(phoneNumber);
  sim800l.print("\"\r");
  delay(500);
  sim800l.print(message);
  delay(500);
  sim800l.write(0x1A); // Send Ctrl+Z to indicate end of message
  delay(500);

  return waitForResponse("OK");  // Check for "OK" response indicating successful sending of SMS
}

bool waitForResponse(const char* expectedResponse) {
  unsigned long startTime = millis();
  char response[100];
  int index = 0;
  while (millis() - startTime < 5000) { // Wait for response for up to 5 seconds
    if (sim800l.available()) {
      char c = sim800l.read();
      response[index++] = c;
      response[index] = '\0'; // Null terminate the response string
      if (strstr(response, expectedResponse) != NULL) {
        return true;
      }
    }
  }
  return false;
}
 

