#include <DHT.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#define DHTPin 8
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

DHT dht(DHTPin, DHT22);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

float temp, hum;
bool isTemperatureDisplayed = true;
unsigned long lastDisplayChange = 0;
const unsigned long displayChangeInterval = 5000;

void setup() {
  Serial.begin(9600);
  dht.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - lastDisplayChange >= displayChangeInterval) {
    isTemperatureDisplayed = !isTemperatureDisplayed;
    lastDisplayChange = currentMillis;
  }

  display.clearDisplay();
  display.setCursor(0, 5);

  temp = dht.readTemperature();
  hum = dht.readHumidity();

  if (!isnan(temp) && !isnan(hum)) {
    if (isTemperatureDisplayed) {
      display.println("T: " + String(temp) + " C");
    } else {
      display.println("H: " + String(hum) + " %");
    }
  } else {
    display.println("Failed to read sensor");
  }
  display.display();
}
