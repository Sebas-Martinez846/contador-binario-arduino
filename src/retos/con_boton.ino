const int leds[] = {2, 4, 7, 8};
const int TOTAL_LEDS = 4;
const int PIN_BOTON = 12;

int numero = 0;
int estadoBotonAnterior = HIGH;

void setup() {
  for (int i = 0; i < TOTAL_LEDS; i++) {
    pinMode(leds[i], OUTPUT);
  }
  pinMode(PIN_BOTON, INPUT_PULLUP);
}

void loop() {
  int estadoBotonActual = digitalRead(PIN_BOTON);

  if (estadoBotonAnterior == HIGH && estadoBotonActual == LOW) {
    for (int bit = 0; bit < TOTAL_LEDS; bit++) {
      int estadoBit = (numero & (1 << bit)) ? HIGH : LOW;
      digitalWrite(leds[bit], estadoBit);
    }
    numero++;
    if (numero > 15) numero = 0;
    delay(50); 
  }
  estadoBotonAnterior = estadoBotonActual;
}