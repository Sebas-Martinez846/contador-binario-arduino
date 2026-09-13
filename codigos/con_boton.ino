const int leds[] = {2, 4, 7, 8};
const int TOTAL_LEDS = 4;
const int PIN_BOTON = 12;

int numero = 0;
int estadoBotonAnterior = HIGH;

void setup() {
  for (int i = 0; i < TOTAL_LEDS; i++) {
    pinMode(leds[i], OUTPUT);
    // Asegurar que los LEDs arranquen apagados (Estado inicial: 0)
    digitalWrite(leds[i], LOW); 
  }
  pinMode(PIN_BOTON, INPUT_PULLUP);
}

void loop() {
  int estadoBotonActual = digitalRead(PIN_BOTON);

  // Detecta el momento exacto en que se presiona el botón
  if (estadoBotonAnterior == HIGH && estadoBotonActual == LOW) {
    
    // 1. Incrementar el número primero
    numero++;
    
    // 2. Reiniciar si pasa de 15
    if (numero > 15) {
      numero = 0;
    }

    // 3. Escribir el nuevo número en los LEDs usando operaciones bit a bit
    for (int bit = 0; bit < TOTAL_LEDS; bit++) {
      int estadoBit = (numero & (1 << bit)) ? HIGH : LOW;
      digitalWrite(leds[bit], estadoBit);
    }

    // 4. Pausa para evitar el rebote mecánico del botón (debounce)
    delay(50);
  }
  
  // Actualizar el estado del botón para el siguiente ciclo
  estadoBotonAnterior = estadoBotonActual;
}