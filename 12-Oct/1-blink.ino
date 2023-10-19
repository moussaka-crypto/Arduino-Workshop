#define LED 8
// the setup function runs once when you press reset or power the board
void setup() {
  pinMode(LED, OUTPUT);
  const int delay = 500;
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(delay);             // wait for a second
  digitalWrite(LED, LOW);   // turn the LED off by making the voltage LOW
  delay(delay);             // wait for a second
}
