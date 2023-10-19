const int buttonPin = 7;
const int ledPin = 8;    

bool ledState = LOW;
unsigned long previousMillis = 0;
const long interval = 1000;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);  
}

void loop() {
  unsigned long currentMillis = millis();

  // Check if the button was pressed
  if (digitalRead(buttonPin) == LOW) {
    // Button is pressed
    if (currentMillis - previousMillis >= interval) {
      // Toggle the LED state
      if (ledState == LOW) {
        ledState = HIGH;
      } else {
        ledState = LOW;
      }
      digitalWrite(ledPin, ledState);
      previousMillis = currentMillis;
    }
  }
}
