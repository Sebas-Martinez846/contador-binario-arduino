const int leds[] = {2, 4, 7, 8};
const int TOTAL_LEDS = 4;
const int PIN_BOTON = 12; // Pin donde se conecta el botón

int numero = 0;
int estadoBotonAnterior = HIGH; // Como usamos PULLUP, HIGH es "no presionado"

void setup() {
  for (int i = 0; i < TOTAL_LEDS; i++) {
    pinMode(leds[i], OUTPUT);
  }
  // Activa la resistencia interna para el botón
  pinMode(PIN_BOTON, INPUT_PULLUP);
}

void loop() {
  int estadoBotonActual = digitalRead(PIN_BOTON);

  // Detecta el momento exacto en que se presiona el botón (cambio de estado)
  if (estadoBotonAnterior == HIGH && estadoBotonActual == LOW) {
    
    // Muestra el número actual en los LEDs
    for (int bit = 0; bit < TOTAL_LEDS; bit++) {
      digitalWrite(leds[bit], bitRead(numero, bit));
    }
    
    // Aumenta el número para el siguiente toque
    numero++;
    if (numero > 15) {
      numero = 0; // Reinicia si pasa de 15
    }
    
    delay(50); // Pequeña pausa para evitar rebotes mecánicos del botón
  }
  
  estadoBotonAnterior = estadoBotonActual;
}