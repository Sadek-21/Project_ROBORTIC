#include <PS2X_lib.h>  // Include the PS2 Controller library

#define MOTOR1_IN1 A3  // Motor 1 input pins for direction control
#define MOTOR1_IN2 A2
#define MOTOR1_IN3 A1  // Motor 2 input pins for direction control
#define MOTOR1_IN4 A0
#define MOTOR2_IN1 4    // 
#define MOTOR2_IN2 5
#define MOTOR2_IN3 6    //
#define MOTOR2_IN4 7
#define RELAY_PIN A4    // Pin for controlling relay to rotate the conveyor

#define PS2_DAT 12  // PS2 controller data pin
#define PS2_CMD 11  // PS2 controller command pin
#define PS2_SEL 10  // PS2 controller select pin
#define PS2_CLK 13  // PS2 controller clock pin

#define MOTOR_SPEED 200 // Adjust motor speed as needed

#define PSB_SQUARE 0
#define PSB_CIRCLE 1
#define PSB_TRIANGLE 2
#define PSB_X 3

PS2X ps2x; // Create PS2 Controller object

void setup() {
  Serial.begin(57600);
  
  // Initialize motor control pins
  pinMode(MOTOR1_IN1, OUTPUT);
  pinMode(MOTOR1_IN2, OUTPUT);
  pinMode(MOTOR2_IN1, OUTPUT);
  pinMode(MOTOR2_IN2, OUTPUT);
  pinMode(MOTOR2_IN3, OUTPUT);
  pinMode(MOTOR2_IN4, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);

  // Ensure all motor control pins are initially LOW
  digitalWrite(MOTOR1_IN1, LOW);
  digitalWrite(MOTOR1_IN2, LOW);
  digitalWrite(MOTOR2_IN1, LOW);
  digitalWrite(MOTOR2_IN2, LOW);
  digitalWrite(MOTOR2_IN3, LOW);
  digitalWrite(MOTOR2_IN4, LOW);
  digitalWrite(RELAY_PIN, LOW);

  // Enable debugging mode for PS2 controller
  int error = ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, false, false); // Disabling pressures and rumble
  
  if (error == 0) {
    Serial.println("PS2 controller setup successful");
  } else {
    Serial.println("PS2 controller setup failed");
  }
}

void loop() {
  ps2x.read_gamepad(); // Read controller
  
  // Control forward/backward and left/right motors based on D-pad button presses
  if (ps2x.Button(PSB_PAD_UP)) {
    digitalWrite(MOTOR1_IN1, HIGH);
    digitalWrite(MOTOR1_IN2, LOW);
    digitalWrite(MOTOR1_IN3, HIGH);
    digitalWrite(MOTOR1_IN4, LOW);
  } else if (ps2x.Button(PSB_PAD_DOWN)) {
    digitalWrite(MOTOR1_IN1, LOW);
    digitalWrite(MOTOR1_IN2, HIGH);
    digitalWrite(MOTOR1_IN3, LOW);
    digitalWrite(MOTOR1_IN4, HIGH);
  } else if (ps2x.Button(PSB_PAD_LEFT)) {
    digitalWrite(MOTOR1_IN1, LOW);
    digitalWrite(MOTOR1_IN2, HIGH);
    digitalWrite(MOTOR1_IN3, HIGH);
    digitalWrite(MOTOR1_IN4, LOW);
  } else if (ps2x.Button(PSB_PAD_RIGHT)) {
    digitalWrite(MOTOR1_IN1, HIGH);
    digitalWrite(MOTOR1_IN2, LOW);
    digitalWrite(MOTOR1_IN3, LOW);
    digitalWrite(MOTOR1_IN4, HIGH);
  } else {
    // Stop motors if no D-pad buttons are pressed
    digitalWrite(MOTOR1_IN1, LOW);
    digitalWrite(MOTOR1_IN2, LOW);
    digitalWrite(MOTOR1_IN3, LOW);
    digitalWrite(MOTOR1_IN4, LOW);
  }

 ps2x.read_gamepad(); // Read controller
  
  // Read analog values from the right analog stick (manetta)
  int rightAnalogX = ps2x.Analog(PSS_RX);
  int rightAnalogY = ps2x.Analog(PSS_RY);

  // Read analog values from the left analog stick (manetta)
  int leftAnalogX = ps2x.Analog(PSS_LX);
  int leftAnalogY = ps2x.Analog(PSS_LY);

  // Control the motor for laban based on the right analog stick
  if (rightAnalogY < 100) {
    // Move laban up
    digitalWrite(MOTOR2_IN1, HIGH);
    digitalWrite(MOTOR2_IN2, LOW);
  } else if (rightAnalogY > 150) {
    // Move laban down
    digitalWrite(MOTOR2_IN1, LOW);
    digitalWrite(MOTOR2_IN2, HIGH);
  } else {
    // Stop laban if the right analog stick is in the middle position
    digitalWrite(MOTOR2_IN1, LOW);
    digitalWrite(MOTOR2_IN2, LOW);
  }

  // Control the motor for convoyer based on the left analog stick
  if (leftAnalogY < 100) {
    // Move convoyer up
    digitalWrite(MOTOR2_IN3, HIGH);
    digitalWrite(MOTOR2_IN4, LOW);
  } else if (leftAnalogY > 150) {
    // Move convoyer down
    digitalWrite(MOTOR2_IN3, LOW);
    digitalWrite(MOTOR2_IN4, HIGH);
  } else {
    // Stop convoyer if the left analog stick is in the middle position
    digitalWrite(MOTOR2_IN3, LOW);
    digitalWrite(MOTOR2_IN4, LOW);
  }



  if(ps2x.Button(PSB_START))         //will be TRUE as long as button is pressed
    digitalWrite(RELAY_PIN, HIGH);
    
  if(ps2x.Button(PSB_SELECT))
      digitalWrite(RELAY_PIN, LOW);




  delay(50); // Delay for stability
}
