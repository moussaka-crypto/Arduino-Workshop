#include <DHT.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#define DHTPin 8
#define SCREEN_WIDTH 128
#define SCREEN_HEIGTH 32

DHT dht(DHTPin, DHT22);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGTH, &Wire, -1);
float temp, hum;

void setup() {
  Serial.begin(9600);
  dht.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);  
  }
  delay(2000);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
}

void loop() {
  display.clearDisplay();
  display.setCursor(0, 5);
  delay(2000);

  temp = dht.readTemperature();
  hum = dht.readHumidity();

  if (!isnan(temp) && !isnan(hum)) {
    display.println("Tempreature: " + String(temp) + " C\nHumidity: " + String(hum) + " %");
    display.display();
  } else {
    display.println("Failed to read DHT sensor");
  }
}
