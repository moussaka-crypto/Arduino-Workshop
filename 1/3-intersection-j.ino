// jeffrey
#define redLED 2
#define yellowLED 3
#define greenLED 4

#define redLED2 6
#define yellowLED2 7
#define greenLED2 8

int delay1 = 1000;
int delay2 = 2000;
int delay3 = 100;

void setup(){

  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);

  pinMode(redLED2, OUTPUT);
  pinMode(yellowLED2, OUTPUT);
  pinMode(greenLED2, OUTPUT);
}

void loop(){
  digitalWrite(redLED, HIGH);
  digitalWrite(redLED2, HIGH);
  delay(delay2);

  digitalWrite(yellowLED, HIGH);
  delay(delay1);

  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  delay(delay3);

  digitalWrite(greenLED, HIGH);
  delay(delay2);

  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, HIGH);
  delay(delay1);

  digitalWrite(yellowLED, LOW);
  digitalWrite(redLED, HIGH);
  delay(delay2);

  digitalWrite(redLED2, HIGH);
  delay(delay2);

  digitalWrite(yellowLED2, HIGH);
  delay(delay1);

  digitalWrite(redLED2, LOW);
  digitalWrite(yellowLED2, LOW);
  delay(delay3);

  digitalWrite(greenLED2, HIGH);
  delay(delay2);

  digitalWrite(greenLED2, LOW);
  digitalWrite(yellowLED2, HIGH);
  delay(delay1);

  digitalWrite(yellowLED2, LOW);
}
