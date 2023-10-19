#include <DHT.h>
#include <SPI.h>
#define DHTPin 8

DHT dht(DHTPin, DHT22);
float temp, hum;

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);
  temp = dht.readTemperature();
  hum = dht.readHumidity();

  if (!isnan(temp) && !isnan(hum)) {
    Serial.println("Temperature: " + String(temp) + "° C | Humidity: " + String(hum) + " %");
  } else {
    Serial.println("Failed to read DHT sensor");
  }
}
