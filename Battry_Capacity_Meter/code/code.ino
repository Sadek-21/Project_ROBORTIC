#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

const int saPin = A3;  // Update this to the pin connected to your current sensor
const int svPin = A1;
const int evPin = A2;

float R1 = 30000.0;
float R2 = 7500.0;


void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  float amp = getCurrent(saPin);   // Get the current from the sensor
  float evv = getVoltage(evPin);
  float expectedCapacity = calculateCurrentCapacity(evv);  // Calculate expected capacity

  Serial.print("Read Voltage: "); Serial.println(evv);
  Serial.print("Read Current: "); Serial.println(amp);
  Serial.print("Expected Capacity: "); Serial.println(expectedCapacity, 2);


  if (evv < 2.0) {
    lcd.setCursor(0, 0);
    lcd.print("No Battery     ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
  } else {
    int epp = calculatePercentage(evv, 12.01, 2);

    lcd.setCursor(0, 1);
    lcd.print("A:" + String(expectedCapacity, 2) + " " +"V:" + String(evv, 2) );
    lcd.setCursor(0, 0);
    lcd.print("BATTERY:" + String(epp) + "%      ");
  }
  delay(100);
}

float getVoltage(int pin) {
  int value = analogRead(pin);                  // Read the analog value from the pin
  float vOUT = (value * 5.0) / 1024.0;          // Calculate the output voltage from the ADC value
  float vIN = vOUT / (R2 / (R1 + R2));          // Calculate the input voltage using the voltage divider formula
  return vIN;                                   // Return the input voltage
}

float getCurrent(int pin) {
  int analogValue = analogRead(pin);
  float voltageDrop = (analogValue * 5.0) / 1024.0;
  float current = voltageDrop / 0.1; // Assuming shunt resistor value of 0.1 ohms for current measurement
  return current;
}
// Solving these two equations:
float m = (1.35 - 1.3) / (12.30 - 12);  // Change in capacity / Change in voltage
float b = 1.3 - m * 12;                // Rearranging the first equation for b

// Now, rewrite the calculateCurrentCapacity function:
float calculateCurrentCapacity(float voltage) {
  if (voltage < 10.0) {
    return 0;
  } else {
    return m * voltage + b;  // Using the new line parameters
  }
}



int calculatePercentage(float voltage, float maxVolt, float minVolt) {
  float scaled = (voltage - minVolt) / (maxVolt - minVolt);
  int percentage = scaled * 100;
  return constrain(percentage, 0, 100);
}
