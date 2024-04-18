#include <Servo.h>
Servo myservo;
int pos = 90; // Initial position

void setup() {
  myservo.attach(10);
  Serial.begin(9600);
  myservo.write(pos);
}

void loop() {
  if (Serial.available() > 0) {
    char x = Serial.read();
    if (x == 'a') {  // Check if 'a' is received, indicating the start of a position command
      if (Serial.available() > 0) {
        int v = Serial.parseInt(); // Read the integer position
        v = constrain(v, 0, 180); // Constrain the value to ensure servo safety
        myservo.write(v);
      }
    }
  }
  delay(10); // Small delay to stabilize the servo
}
