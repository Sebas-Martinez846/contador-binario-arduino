# contador-binario-arduino
Implementación y simulación de un contador binario de 4 bits (0 a 15) con Arduino Uno y LEDs. Incluye esquemas en Tinkercad, código en C++ optimizado con arrays/bitRead y evidencias de montaje físico.

## 1. Descripción del proyecto
El proyecto consiste en el diseño, programación y montaje de un contador binario de 4 bits. Utiliza una placa Arduino Uno para controlar cuatro LEDs que representan visualmente los números decimales del 0 al 15 mediante sus equivalentes en sistema binario, gestionando los estados (encendido/apagado) a través de operaciones bit a bit.

## Integrantes
* Sebastián Martinez 
* Yeimer Ortiz 
* Camilo Martinez 
* Alexandro Leones 
* Steven Santamaría
* Martín Castro  

## 2. Materiales utilizados
* 1 Placa Arduino UNO R3
* 1 Protoboard
* 4 Diodos LED (Indicadores de bits 0 al 3)
* 1 Diodo LED extra (Indicador de límite para el Reto 5)
* 4 Resistencias de 220 Ω
* 1 Pulsador táctil (Para el Reto 3)
* Cables tipo Jumper (Macho-Macho)

## 3. Explicación del circuito
* **LEDs y Resistencias:** Los ánodos (patas largas) de los 4 LEDs están conectados a los pines digitales 2, 4, 7 y 8 a través de resistencias de 220 Ω. Estas resistencias limitan la corriente (~13.6 mA) protegiendo el LED y el pin del microcontrolador.
* **GND (Tierra):** Los cátodos (patas cortas) de todos los LEDs se puentean a una línea común en la protoboard que retorna al pin GND del Arduino.
* **Pulsador (Reto 3):** Conectado entre el pin digital 12 y GND. Utiliza la resistencia pull-up interna del Arduino, leyendo un nivel bajo (`LOW`) cuando se presiona.
* **LED Indicador (Reto 5):** Conectado al pin 13 con su respectiva resistencia de 220 Ω a GND, actuando como señalizador visual del valor máximo (15).

## 4. Funcionamiento del contador binario
Cuatro LEDs permiten generar $2^4 = 16$ combinaciones posibles. Cada LED representa una potencia de 2 dependiendo de su posición:
* LED 1 (Bit 0): $2^0 = 1$
* LED 2 (Bit 1): $2^1 = 2$
* LED 3 (Bit 2): $2^2 = 4$
* LED 4 (Bit 3): $2^3 = 8$
El estado encendido (`1`) suma el valor de su posición. Si el número decimal es 5, su representación binaria es `0101` (LEDs 3 y 1 encendidos: $4 + 1 = 5$). 

## 5. Explicación del código
* `setup()`: Función que se ejecuta una sola vez al arrancar. Se usa para configurar el hardware inicial.
* `loop()`: Ciclo infinito que se ejecuta repetidamente. Contiene la lógica principal de conteo.
* `pinMode()`: Configura un pin específico para que funcione como entrada (`INPUT` / `INPUT_PULLUP`) o salida (`OUTPUT`).
* `digitalWrite()`: Envía voltaje (`HIGH` = 5V) o lo retira (`LOW` = 0V) en un pin configurado como salida.
* `digitalRead()`: Lee el estado eléctrico de un pin configurado como entrada, devolviendo `HIGH` o `LOW`.
* `delay()`: Detiene la ejecución del programa durante una cantidad específica de milisegundos.
* **Arreglos:** Colecciones de variables del mismo tipo. Usamos `leds[] = {2, 4, 7, 8}` para agrupar los pines discontinuos y recorrerlos fácilmente.
* **Ciclos for:** Estructura iterativa que repite un bloque de código un número determinado de veces.
* **Operadores bitwise (`&` y `<<`):** 
  * `<<` (Left Shift): Desplaza el número binario `1` a la izquierda según la posición del ciclo (`bit`). Crea una "máscara" (ej. `1 << 2` resulta en `0100`).
  * `&` (AND): Compara el número actual con la máscara. `(numero & (1 << bit))` devuelve un valor mayor a cero solo si el bit en esa posición exacta es un `1`. Esto determina si el LED correspondiente debe encenderse.

## 6. Desarrollo de los cinco retos
* **Reto 1 (Velocidad):** Se solicitó un retraso de 500 ms usando variables. *Modificación:* Se creó `int waitDelay = 500;` y se reemplazó el número fijo en `delay(waitDelay)`. *Resultado:* El contador avanza al doble de velocidad.
* **Reto 2 (Descendente):** Se solicitó contar de 15 a 0. *Modificación:* Ajuste en el for principal a `for (int numero = 15; numero >= 0; numero--)`. *Resultado:* Los LEDs decrementan su valor binario hasta 0 y reinician en 15.
* **Reto 3 (Botón):** Se solicitó avance manual. *Modificación:* Se eliminó el `delay` principal y se introdujo un `if` que compara `estadoBotonAnterior` y `digitalRead(PIN_BOTON)`. *Resultado:* El conteo solo avanza una posición al soltar/presionar el pulsador físico.
* **Reto 4 (Pares):** Se solicitó mostrar solo números pares (0, 2, 4...). *Modificación:* El for principal se alteró a `for (int numero = 0; numero <= 15; numero += 2)`. *Resultado:* El bit 0 (LED 1) siempre permanece apagado, mostrando solo números divisibles entre 2.
* **Reto 5 (LED indicador):** Se solicitó un LED que se encienda en 15. *Modificación:* Se agregó un quinto LED en el pin 13 y la condición `if (numero == 15)` dentro del loop. *Resultado:* Al llegar a `1111`, el quinto LED se enciende automáticamente.

## 7. Enlace de funcionamiento
* **Video demostrativo:** [https://youtube.com/shorts/umP8_quK6YE]
* **Simulación interactiva:** [https://www.tinkercad.com/things/bRoe2dM0TiH-primer-diseno?sharecode=HKOERj-NE_7qSPv1ypEqylI2slHjOgNc9rVHGWSa15Y]
