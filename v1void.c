#define SOIL_PIN 34  // Analog pin for soil moisture sensor

void setup() {
  Serial.begin(115200);
  Serial.println("Soil Moisture Sensor Test - ESP32");
}

void loop() {
  int sensorValue = analogRead(SOIL_PIN);  // Read analog value (0–4095)
  
  // Convert to percentage (optional calibration)
  // Dry soil ~ 0 (or low value), Wet soil ~ 4095 (depends on sensor)
  float moisturePercent = (4095 - sensorValue) * 100.0 / 4095.0;

  Serial.print("Raw Value: ");
  Serial.print(sensorValue);
  Serial.print("\tMoisture: ");
  Serial.print(moisturePercent, 1);
  Serial.println(" %");

  delay(1000);  // Wait 1 second
}
