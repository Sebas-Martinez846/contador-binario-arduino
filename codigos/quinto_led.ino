const int leds[] = {2, 4, 7, 8};
const int TOTAL_LEDS = 4;
const int PIN_LED_FINAL = 13;
int waitDelay = 1000;

void setup() {
  for (int i = 0; i < TOTAL_LEDS; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(PIN_LED_FINAL, OUTPUT);
}

void loop() {
  for (int numero = 0; numero <= 15; numero++) {
    if (numero == 15) {
      digitalWrite(PIN_LED_FINAL, HIGH);
    } else {
      digitalWrite(PIN_LED_FINAL, LOW);
    }
    
    for (int bit = 0; bit < TOTAL_LEDS; bit++) {
      int estadoBit = (numero & (1 << bit)) ? HIGH : LOW;
      digitalWrite(leds[bit], estadoBit);
    }
    delay(waitDelay);
  }
}