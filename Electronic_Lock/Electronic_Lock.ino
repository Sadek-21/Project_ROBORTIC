#include <Keypad.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(10,11,12,13,1,0);  // Include LCD display library for I2C
#define Password_Length 8  // Length of password + 1 for null character

char Data[Password_Length];  // Character to hold password input
char CP[Password_Length] = "A123A45";  // Password //CP==>stand for correct password
byte count = 0; // Counter for character entries
char customKey;  // Character to hold key input

const byte ROWS = 4;
const byte COLS = 4;
 
char Keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
 
byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};
 
Keypad customKeypad = Keypad(makeKeymap(Keys), rowPins, colPins, ROWS, COLS);


void setup() {

  lcd.begin( 20 , 4 ); 

  pinMode(A0, OUTPUT);  // Set lockOutput as an OUTPUT pin
}
 
void loop() {

  lcd.setCursor(0, 0);
  lcd.print("Enter Password:");

  customKey = customKeypad.getKey();
 
  if (customKey) {
    Data[count] = customKey;
    lcd.setCursor(count, 1);
    lcd.print('*'); // Display '*' instead of the actual character
    //lcd.print(Data[count]);
    count++;
  }
  if (count == Password_Length - 1) {
    lcd.clear();

  if (!strcmp(Data, CP)) {
      
      lcd.print("Correct");// Password is correct
      
      digitalWrite(A0, HIGH);  // Turn on relay for 5 seconds
      delay(5000);
      digitalWrite(A0, LOW);
    }
    else {
      
      lcd.print("Incorrect"); // Password is incorrect
      delay(1000);
    }
 
    
    lcd.clear(); 
    clearData();
  }
}
 
void clearData() {

  while (count != 0) {
    Data[count--] = 0;
  }
  return;
}