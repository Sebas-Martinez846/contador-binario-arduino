// Definición de pines asignados en un arreglo (array)
// Índice 0 = Bit 0 (LSB) -> Pin 2
// Índice 1 = Bit 1       -> Pin 4
// Índice 2 = Bit 2       -> Pin 7
// Índice 3 = Bit 3 (MSB) -> Pin 8
const int leds[] = {2, 4, 7, 8};
const int TOTAL_LEDS = 4;
const int TIEMPO_ESPERA = 1000; // 1 segundo

void setup() {
  // Configuración de todos los pines de salida mediante un bucle
  for (int i = 0; i < TOTAL_LEDS; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  // Conteo decimal de 0 a 15
  for (int numero = 0; numero <= 15; numero++) {
    // Escribir el estado binario en cada LED
    for (int bit = 0; bit < TOTAL_LEDS; bit++) {
      int estadoBit = bitRead(numero, bit);
      digitalWrite(leds[bit], estadoBit);
    }
    delay(TIEMPO_ESPERA);
  }
}