// jeffrey
#define RED 2
#define YELLOW 3
#define GREEN 4

const int traffic_light[] = {RED, YELLOW, GREEN};

void setup() {
  for (int i = 2; i < 5; i++)
  {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  digitalWrite(2, HIGH);
  delay(5000);

  for (int i = 0; i < 5; i++){
    digitalWrite(3, HIGH);
    delay(1000);
    digitalWrite(3, LOW);
    delay(500);
  }
  digitalWrite(2,LOW);
  
  digitalWrite(4, HIGH);
  delay(2500);
  digitalWrite(4, LOW);

  for (int i = 0; i < 5; i++){
    digitalWrite(3, HIGH);
    delay(1000);
    digitalWrite(3, LOW);
    delay(500);
  }
}
