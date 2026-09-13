const int leds[] = {2, 4, 7, 8};
const int TOTAL_LEDS = 4;
int waitDelay = 500; // Tiempo reducido a la mitad (medio segundo)

void setup() {
  for (int i = 0; i < TOTAL_LEDS; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for (int numero = 0; numero <= 15; numero++) {
    for (int bit = 0; bit < TOTAL_LEDS; bit++) {
      digitalWrite(leds[bit], bitRead(numero, bit));
    }
    delay(waitDelay);
  }
}