#include <WiFi.h>
#include <DHT.h>
#define DHT22_PIN  18 // ESP32 pin GPIO18 connected to DHT22 sensor

DHT dht18(DHT22_PIN, DHT22);
float humidity;
float temperature;


void setup() {
  Serial.begin(9600);
  Serial.print("Connecting to WiFi");
  WiFi.begin("Wokwi-GUEST", "", 6);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println(" Connected!");
}

void loop() {

  humidity = dht18.readHumidity();
  temperature = dht18.readTemperature();

    if ( isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT22 sensor!");
  } else {
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println("%");

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println("°C  ~  ");
  } 


  delay(2000); 

 
}
