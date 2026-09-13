const int leds[] = {2, 4, 7, 8};
const int TOTAL_LEDS = 4;
int waitDelay = 500;

void setup() {
  for (int i = 0; i < TOTAL_LEDS; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for (int numero = 15; numero >= 0; numero--) {
    for (int bit = 0; bit < TOTAL_LEDS; bit++) {
      int estadoBit = (numero & (1 << bit)) ? HIGH : LOW;
      digitalWrite(leds[bit], estadoBit);
    }
    delay(waitDelay);
  }
}