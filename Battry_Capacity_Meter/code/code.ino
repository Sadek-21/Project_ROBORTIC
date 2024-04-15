#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4);

const int saPin = A0; // Solar amperage
const int svPin = A1; // Solar voltage
const int evPin = A2; // Battery voltage

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
}

void loop() {
  float amp = getAmperage(saPin);
  float svv = getVoltage(svPin);
  float evv = getVoltage(evPin);

  Serial.print("Read Voltage: "); Serial.println(evv);

  if (evv < 2.0) {
    lcd.setCursor(0, 0);
    lcd.print("No Battery     ");
    lcd.setCursor(0, 1);
    lcd.print("                ");
  } else {
    int epp = calculatePercentage(evv, 12.5, 10.5); // Assuming 12.5V is 100% and 10.5V is 0%

    Serial.print("Percentage: "); Serial.println(epp);

    lcd.setCursor(0, 1);
    lcd.print("A:" + String(amp, 2) + "A " + "V:" + String(evv, 2)+"V");

    lcd.setCursor(0, 0);
    lcd.print("BATTERY:" + String(epp) + "%      ");
  }
  //lcd.print("A:" + String(amp, 2) + "A " + "V:" + String(svv, 2) + "V");

  delay(100);
}

float getAmperage(int pin) {
  int value = analogRead(pin);
  return map(value, 0, 1023, 0, 3); // Update mapping based on actual sensor range
}

float getVoltage(int pin) {
    int value = analogRead(pin);
    float voltage = (value * 5.0) / 1023.0; // 5.0 represents the reference voltage
    float scaledVoltage = voltage * (12.5 / 5.0); // Adjust the ratio based on actual measurements
    return scaledVoltage;
}


int calculatePercentage(float voltage, float maxVolt, float minVolt) {
    float scaled = (voltage - minVolt) / (maxVolt - minVolt);
    int percentage = scaled * 100;
    return constrain(percentage, 0, 100); // Ensures the percentage is within 0 to 100
}
