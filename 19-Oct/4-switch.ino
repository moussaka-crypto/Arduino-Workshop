#include <DHT.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#define DHTPin 8
#define SCREEN_WIDTH 128
#define SCREEN_HEIGTH 32
#define button 2

volatile bool status = false;

DHT dht(DHTPin, DHT22);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGTH, &Wire, -1);

float temp, hum;
bool tempON = true;

void ISRoutine(){
  status = !status;
}

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(button, INPUT);
  attachInterrupt(digitalPinToInterrupt(button), ISRoutine, FALLING);

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);  
  }

  delay(2000);
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(WHITE);
}

void loop() {
  if (status){
    tempON = !tempON;
    status = false;
  }

  display.clearDisplay();
  display.setCursor(0, 5);
  delay(1000);

  temp = dht.readTemperature();
  hum = dht.readHumidity();

  if (!isnan(temp) && !isnan(hum)) {
    if (tempON){
      display.println("T: " + String(temp) + " C");
    }
    else{
      display.println("H: " + String(hum) + " %");
    }
    display.display();
  } else {
    display.println("Failed to read sensor");
  }
}
