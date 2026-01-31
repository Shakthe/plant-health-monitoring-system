#include <DHTesp.h>
 
const int DHT_PIN = 15;
DHTesp dht;
float temp = 0;
float hum = 0;
unsigned long lastMsg = 0 ;
void setup() {
 pinMode(2, OUTPUT);    
 Serial.begin(115200);
 dht.setup(DHT_PIN, DHTesp::DHT11);
}

void loop() {
 
 unsigned long now = millis();
 if (now - lastMsg > 2000) {
   lastMsg = now;
   TempAndHumidity  data = dht.getTempAndHumidity();
   String temp = String(data.temperature, 2);
   String hum = String(data.humidity, 1);
   Serial.print("Temperature: ");
   Serial.println(temp);
   Serial.print("Humidity: ");
   Serial.println(hum);
 }
}
