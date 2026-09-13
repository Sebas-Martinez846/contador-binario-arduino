const int leds[] = {2, 4, 7, 8};
const int TOTAL_LEDS = 4;
int waitDelay = 1000;

void setup() {
  for (int i = 0; i < TOTAL_LEDS; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  // numero += 2 hace que el conteo salte: 0, 2, 4, 6, 8, 10, 12, 14
  for (int numero = 0; numero <= 15; numero += 2) {
    for (int bit = 0; bit < TOTAL_LEDS; bit++) {
      digitalWrite(leds[bit], bitRead(numero, bit));
    }
    delay(waitDelay);
  }
}