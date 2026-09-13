const int leds[] = {2, 4, 7, 8};
const int TOTAL_LEDS = 4;
const int PIN_LED_FINAL = 13; // El quinto LED
int waitDelay = 1000;

void setup() {
  for (int i = 0; i < TOTAL_LEDS; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(PIN_LED_FINAL, OUTPUT); // Declaramos el quinto LED como salida
}

void loop() {
  for (int numero = 0; numero <= 15; numero++) {
    
    // Si llegamos a 15, enciende el 5to LED. Si no, mantenlo apagado.
    if (numero == 15) {
      digitalWrite(PIN_LED_FINAL, HIGH);
    } else {
      digitalWrite(PIN_LED_FINAL, LOW);
    }

    // Código habitual del contador
    for (int bit = 0; bit < TOTAL_LEDS; bit++) {
      digitalWrite(leds[bit], bitRead(numero, bit));
    }
    delay(waitDelay);
  }
}