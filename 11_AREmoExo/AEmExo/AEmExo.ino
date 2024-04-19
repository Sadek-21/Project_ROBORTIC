#include <HX711.h>
#include <Servo.h>

#define LOADCELL_DOUT_PIN  3
#define LOADCELL_SCK_PIN   2
#define SERVO_PIN          9

HX711 scale;
Servo myServo;

float calibration_factor = -7050; // Calibration factor for HX711
const float upper_threshold_weight = 3.7; // Weight threshold to move servo to 160 degrees
const float lower_threshold_weight = -0.5; // Lower threshold to move servo back to 30 degrees
int currentServoPosition = 30; // Start position of servo

void setup() {
  Serial.begin(9600);
  myServo.attach(SERVO_PIN);
  scale.begin(LOADCELL_DOUT_PIN, LOADCELL_SCK_PIN);
  scale.set_scale(calibration_factor);
  scale.tare();  // Zero out the scale at startup
  
  myServo.write(currentServoPosition);  // Initialize servo at the lower position
  Serial.println("Setup complete. Adjust the weight.");
}

void loop() {
  float weight = getStableWeight();  // Get a stabilized weight reading
  Serial.print("Stable Reading: ");
  Serial.print(weight, 1);
  Serial.println(" lbs");

  if (weight >= upper_threshold_weight && currentServoPosition != 110) {
    currentServoPosition = 110;  // Move servo to 160 degrees
    myServo.write(currentServoPosition);
    Serial.println("Assisting up...");
  } else if (weight <= lower_threshold_weight && currentServoPosition != 30) {
    currentServoPosition = 30;  // Move servo back to 30 degrees
    myServo.write(currentServoPosition);
    Serial.println("Assisting down...");
  }

  delay(1000);  // Delay to stabilize readings and reduce "chatter"
}


float getStableWeight() {
  const int numReadings = 10;
  float readings[numReadings];  // Array to store weight readings
  float total = 0;

  for (int i = 0; i < numReadings; i++) {
    readings[i] = scale.get_units();
    total += readings[i];
    delay(50);  // Short delay between readings
  }

  float average = total / numReadings;
  return average;  // Return the average weight
}
