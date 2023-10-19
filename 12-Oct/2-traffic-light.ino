// ADONIS
#define RED 2
#define YELLOW 3
#define GREEN 4

const int traffic_light[] = {RED, YELLOW, GREEN};
void setup() {
  for (int i = 0; i < 3; i++)
  {
    pinMode(traffic_light[i], OUTPUT);
  }
}

void loop() {
  digitalWrite(traffic_light[0],HIGH);
  delay(5000);

  for (int i = 0; i < 5; i++)
  {
    digitalWrite(traffic_light[1], HIGH);
    delay(1000);
    digitalWrite(traffic_light[1], LOW);
    delay(500);
  }
  digitalWrite(traffic_light[0],LOW);
  
  digitalWrite(traffic_light[2], HIGH);
  delay(2500);
  digitalWrite(traffic_light[2], LOW);

  for (int i = 0; i < 5; i++)
  {
    digitalWrite(traffic_light[1], HIGH);
    delay(1000);
    digitalWrite(traffic_light[1], LOW);
    delay(500);
  }
}
