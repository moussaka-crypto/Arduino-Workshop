#include <DHT.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#define DHTPin 8
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define button 2

volatile bool status = false;
bool lastButtonState = HIGH;
bool isTemperatureDisplayed = true;

DHT dht(DHTPin, DHT22);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

float temp, hum;
String data;

void ISRoutine() {
  status = true;
}

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(button, INPUT);
  attachInterrupt(digitalPinToInterrupt(button), ISRoutine, FALLING);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
}

void loop() {
  int buttonState = digitalRead(button);

  if (buttonState == LOW && lastButtonState == HIGH) {
    isTemperatureDisplayed = !isTemperatureDisplayed;
    status = true;
  }
  
  lastButtonState = buttonState;

  if (status) {
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
    status = false;
  }
}
