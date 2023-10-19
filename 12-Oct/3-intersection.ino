// ADONIS
const int redPins[] = {2, 6};
const int yellowPins[] = {3, 7};
const int greenPins[] = {4, 8};
const int numLights = 2;

void setLights(int stage, int currentLight) {
  for (int i = 0; i < numLights; i++) {
    if (i == currentLight) {
      switch (stage) {
        case 1:
          digitalWrite(redPins[i], HIGH);
          digitalWrite(yellowPins[i], LOW);
          digitalWrite(greenPins[i], LOW);
          break;

        case 2:
          digitalWrite(redPins[i], HIGH);
          digitalWrite(yellowPins[i], HIGH);
          digitalWrite(greenPins[i], LOW);
          break;

        case 3:
          digitalWrite(redPins[i], LOW);
          digitalWrite(yellowPins[i], LOW);
          digitalWrite(greenPins[i], HIGH);
          break;

        case 4:
          digitalWrite(redPins[i], HIGH);
          digitalWrite(yellowPins[i], HIGH);
          digitalWrite(greenPins[i], LOW);
          break;

        default:
          digitalWrite(redPins[i], HIGH);
          digitalWrite(yellowPins[i], LOW);
          digitalWrite(greenPins[i], LOW);
          break;
      }
    } else {
      digitalWrite(redPins[i], HIGH);
      digitalWrite(yellowPins[i], LOW);
      digitalWrite(greenPins[i], LOW);
    }
  }
}

void setup() {
  for (int i = 0; i < numLights; i++) {
    pinMode(redPins[i], OUTPUT);
    pinMode(yellowPins[i], OUTPUT);
    pinMode(greenPins[i], OUTPUT);
  }
}

void loop() {
  // Phase 1: Red
  setLights(1, 0);
  delay(2000);

  // Phase 2: Red and Yellow
  setLights(2, 0);
  delay(2000);

  // Phase 3: Green
  setLights(3, 0);
  delay(2000);

  // Phase 4: Yellow
  setLights(4, 0);
  delay(2000);

  setLights(1, 1);
  delay(2000);
  setLights(2, 1);
  delay(2000);
  setLights(3, 1);
  delay(2000);
  setLights(4, 1);
  delay(2000);
}
