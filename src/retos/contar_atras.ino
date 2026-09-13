const int leds[] = {2, 4, 7, 8};
const int TOTAL_LEDS = 4;
int waitDelay = 1000;

void setup() {
  for (int i = 0; i < TOTAL_LEDS; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  // El bucle ahora inicia en 15 y retrocede hasta 0
  for (int numero = 15; numero >= 0; numero--) {
    for (int bit = 0; bit < TOTAL_LEDS; bit++) {
      digitalWrite(leds[bit], bitRead(numero, bit));
    }
    delay(waitDelay);
  }
}