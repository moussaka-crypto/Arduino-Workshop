int counter = 0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(counter++);
  delay(1000);
}
