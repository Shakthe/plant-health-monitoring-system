#include <WiFi.h>  
#include <PubSubClient.h>
#include <DHTesp.h>

const int DHT_PIN = 15;  
const int SOIL_PIN = 34;   // ✅ Added: Analog pin for soil moisture sensor

DHTesp dht;

const char* ssid = "SNUC"; ///  wifi ssid
const char* password = "snu12345";
const char* mqtt_server = "test.mosquitto.org"; // mosquitto server url

WiFiClient espClient;
PubSubClient client(espClient);
unsigned long lastMsg = 0;
float temp = 0;
float hum = 0;

void setup_wifi() {
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  randomSeed(micros());
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
}

void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);
    if (client.connect(clientId.c_str())) {
      Serial.println("Connected");
      client.publish("/smart_garden/Publish", "Welcome");
      client.subscribe("/smart_garden/Subscribe");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

void setup() {
  pinMode(2, OUTPUT);    
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  dht.setup(DHT_PIN, DHTesp::DHT11);
  pinMode(SOIL_PIN, INPUT);   // ✅ Added: Initialize soil moisture pin
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  unsigned long now = millis();
  if (now - lastMsg > 500) { // publish data
    lastMsg = now;
    TempAndHumidity  data = dht.getTempAndHumidity();

    String temp = String(data.temperature, 2);
    client.publish("/smart_garden/team4/temp", temp.c_str()); 

    String hum = String(data.humidity, 1);
    client.publish("/smart_garden/team4/hum", hum.c_str());   

    Serial.print("Temperature: ");
    Serial.println(temp);
    Serial.print("Humidity: ");
    Serial.println(hum);

    // ✅ Added: Soil moisture reading and publishing
    int soilRaw = analogRead(SOIL_PIN);  
    float soilPercent = (4095 - soilRaw) * 100.0 / 4095.0;  // Convert to percentage
    String soilStr = String(soilPercent, 1);

    client.publish("/smart_garden/team4/mois", soilStr.c_str());  

    Serial.print("Soil Moisture: ");
    Serial.print(soilStr);
    Serial.println(" %");
  }
}
