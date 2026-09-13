# contador-binario-arduino
Implementación y simulación de un contador binario de 4 bits (0 a 15) con Arduino Uno y LEDs. Incluye esquemas en Tinkercad, código en C++ optimizado con arrays/bitRead y evidencias de montaje físico.

# Parcial Práctico – Contador Binario de 4 Bits con Arduino Uno

Implementación física y simulación de un contador binario de 4 bits (conteo de 0 a 15) utilizando una placa Arduino Uno, diodos LED y resistencias limitadoras, aplicando optimización de código mediante arrays y manipulación de bits.

---

## Integrantes
* **Sebastián Martinez **
* **Yeimer Ortiz **
* **Camilo Martinez **
* **Alexandro Leones **
* **Steven Santamaría **

---

## Objetivos del Laboratorio
* Implementar salidas digitales discontinuas en Arduino mediante arrays.
* Representar números enteros en formato binario mediante LEDs (0 = apagado, 1 = encendido).
* Optimizar la estructura del firmware sustituyendo código repetitivo por bucles `for` y `bitRead()`.
* Dimensionar resistencias de protección aplicando la Ley de Ohm.

---

## Materiales y Componentes

<table>
  <thead>
    <tr>
      <th align="center">Cantidad</th>
      <th align="left">Componente</th>
      <th align="left">Descripción</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td align="center">1</td>
      <td><strong>Arduino Uno R3</strong></td>
      <td>Placa de desarrollo principal</td>
    </tr>
    <tr>
      <td align="center">1</td>
      <td><strong>Protoboard</strong></td>
      <td>Tablero de pruebas para montaje sin soldadura</td>
    </tr>
    <tr>
      <td align="center">4</td>
      <td><strong>Diodos LED</strong></td>
      <td>Indicadores visuales de cada bit</td>
    </tr>
    <tr>
      <td align="center">4</td>
      <td><strong>Resistencias 220 Ω</strong></td>
      <td>Resistencias limitadoras de corriente</td>
    </tr>
    <tr>
      <td align="center">-</td>
      <td><strong>Jumpers macho-macho</strong></td>
      <td>Cables de conexión</td>
    </tr>
    <tr>
      <td align="center">1</td>
      <td><strong>Cable USB</strong></td>
      <td>Alimentación y carga de firmware</td>
    </tr>
  </tbody>
</table>

---

## Justificación Técnica: ¿Por qué resistencias de 220 Ω?

Se calculan aplicando la **Ley de Ohm** ($V = I \times R$):

* **Voltaje de salida digital:** $V_{pin} = 5\text{ V}$
* **Caída de tensión típica del LED:** $V_{led} \approx 2\text{ V}$
* **Voltaje en la resistencia:** $V_R = 5\text{ V} - 2\text{ V} = 3\text{ V}$

$$I = \frac{V_R}{R} = \frac{3\text{ V}}{220\ \Omega} \approx 13.6\text{ mA}$$

Una corriente de **~13.6 mA** garantiza un brillo óptimo y nítido sin sobrepasar el límite de seguridad de los pines del microcontrolador (40 mA máximos) ni comprometer la vida útil del LED.

---

## Asignación de Pines y Pesos Binarios

<table>
  <thead>
    <tr>
      <th align="left">Componente</th>
      <th align="center">Pin Arduino</th>
      <th align="center">Bit Binario</th>
      <th align="center">Ponderación</th>
      <th align="left">Función</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td><strong>LED 1</strong></td>
      <td align="center">Pin 2</td>
      <td align="center">Bit 0 (LSB)</td>
      <td align="center">2⁰ = 1</td>
      <td>Bit menos significativo</td>
    </tr>
    <tr>
      <td><strong>LED 2</strong></td>
      <td align="center">Pin 4</td>
      <td align="center">Bit 1</td>
      <td align="center">2¹ = 2</td>
      <td>Bit intermedio</td>
    </tr>
    <tr>
      <td><strong>LED 3</strong></td>
      <td align="center">Pin 7</td>
      <td align="center">Bit 2</td>
      <td align="center">2² = 4</td>
      <td>Bit intermedio</td>
    </tr>
    <tr>
      <td><strong>LED 4</strong></td>
      <td align="center">Pin 8</td>
      <td align="center">Bit 3 (MSB)</td>
      <td align="center">2³ = 8</td>
      <td>Bit más significativo</td>
    </tr>
    <tr>
      <td><strong>Cátodos</strong></td>
      <td align="center">GND</td>
      <td align="center">-</td>
      <td align="center">-</td>
      <td>Retorno común a tierra</td>
    </tr>
  </tbody>
</table>

---

## Tabla de Verdad (Conteo 0 al 15)

<table>
  <thead>
    <tr>
      <th align="center">Decimal</th>
      <th align="center">LED 4 (Pin 8)<br><sub>[2³]</sub></th>
      <th align="center">LED 3 (Pin 7)<br><sub>[2²]</sub></th>
      <th align="center">LED 2 (Pin 4)<br><sub>[2¹]</sub></th>
      <th align="center">LED 1 (Pin 2)<br><sub>[2⁰]</sub></th>
      <th align="left">Estado Visual</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td align="center"><strong>0</strong></td>
      <td align="center">0</td>
      <td align="center">0</td>
      <td align="center">0</td>
      <td align="center">0</td>
      <td>Todos apagados</td>
    </tr>
    <tr>
      <td align="center"><strong>1</strong></td>
      <td align="center">0</td>
      <td align="center">0</td>
      <td align="center">0</td>
      <td align="center">1</td>
      <td>LED 1 encendido</td>
    </tr>
    <tr>
      <td align="center"><strong>2</strong></td>
      <td align="center">0</td>
      <td align="center">0</td>
      <td align="center">1</td>
      <td align="center">0</td>
      <td>LED 2 encendido</td>
    </tr>
    <tr>
      <td align="center"><strong>3</strong></td>
      <td align="center">0</td>
      <td align="center">0</td>
      <td align="center">1</td>
      <td align="center">1</td>
      <td>LEDs 1 y 2 encendidos</td>
    </tr>
    <tr>
      <td align="center"><strong>4</strong></td>
      <td align="center">0</td>
      <td align="center">1</td>
      <td align="center">0</td>
      <td align="center">0</td>
      <td>LED 3 encendido</td>
    </tr>
    <tr>
      <td align="center"><strong>5</strong></td>
      <td align="center">0</td>
      <td align="center">1</td>
      <td align="center">0</td>
      <td align="center">1</td>
      <td>LEDs 1 y 3 encendidos</td>
    </tr>
    <tr>
      <td align="center"><strong>6</strong></td>
      <td align="center">0</td>
      <td align="center">1</td>
      <td align="center">1</td>
      <td align="center">0</td>
      <td>LEDs 2 y 3 encendidos</td>
    </tr>
    <tr>
      <td align="center"><strong>7</strong></td>
      <td align="center">0</td>
      <td align="center">1</td>
      <td align="center">1</td>
      <td align="center">1</td>
      <td>LEDs 1, 2 y 3 encendidos</td>
    </tr>
    <tr>
      <td align="center"><strong>8</strong></td>
      <td align="center">1</td>
      <td align="center">0</td>
      <td align="center">0</td>
      <td align="center">0</td>
      <td>LED 4 encendido</td>
    </tr>
    <tr>
      <td align="center"><strong>9</strong></td>
      <td align="center">1</td>
      <td align="center">0</td>
      <td align="center">0</td>
      <td align="center">1</td>
      <td>LEDs 1 y 4 encendidos</td>
    </tr>
    <tr>
      <td align="center"><strong>10</strong></td>
      <td align="center">1</td>
      <td align="center">0</td>
      <td align="center">1</td>
      <td align="center">0</td>
      <td>LEDs 2 y 4 encendidos</td>
    </tr>
    <tr>
      <td align="center"><strong>11</strong></td>
      <td align="center">1</td>
      <td align="center">0</td>
      <td align="center">1</td>
      <td align="center">1</td>
      <td>LEDs 1, 2 y 4 encendidos</td>
    </tr>
    <tr>
      <td align="center"><strong>12</strong></td>
      <td align="center">1</td>
      <td align="center">1</td>
      <td align="center">0</td>
      <td align="center">0</td>
      <td>LEDs 3 y 4 encendidos</td>
    </tr>
    <tr>
      <td align="center"><strong>13</strong></td>
      <td align="center">1</td>
      <td align="center">1</td>
      <td align="center">0</td>
      <td align="center">1</td>
      <td>LEDs 1, 3 y 4 encendidos</td>
    </tr>
    <tr>
      <td align="center"><strong>14</strong></td>
      <td align="center">1</td>
      <td align="center">1</td>
      <td align="center">1</td>
      <td align="center">0</td>
      <td>LEDs 2, 3 y 4 encendidos</td>
    </tr>
    <tr>
      <td align="center"><strong>15</strong></td>
      <td align="center">1</td>
      <td align="center">1</td>
      <td align="center">1</td>
      <td align="center">1</td>
      <td>Todos encendidos</td>
    </tr>
  </tbody>
</table>

---

## Código Fuente Base

```cpp
// Asignación de pines discontinuos en un array
const int leds[] = {2, 4, 7, 8};
const int TOTAL_LEDS = 4;
const int TIEMPO_ESPERA = 1000; // 1 segundo por estado

void setup() {
  // Inicialización de pines como salidas mediante bucle
  for (int i = 0; i < TOTAL_LEDS; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  // Ciclo principal de conteo de 0 a 15
  for (int numero = 0; numero <= 15; numero++) {
    // Extracción y escritura de cada bit en su respectivo pin
    for (int bit = 0; bit < TOTAL_LEDS; bit++) {
      digitalWrite(leds[bit], bitRead(numero, bit));
    }
    delay(TIEMPO_ESPERA);
  }
}
