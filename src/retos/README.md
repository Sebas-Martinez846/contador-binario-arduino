# Directorio `/src` - Retos y Modificaciones del Código

Este directorio contiene los códigos fuente en C++ (`.ino`) desarrollados para dar solución a los 5 retos planteados durante la práctica del contador binario de 4 bits. 

Cada archivo es un programa independiente que puede ser cargado directamente en la placa Arduino Uno o simulado en Tinkercad.

---

## Descripción de los Retos

### 1. Reto 1: Aumento de Velocidad (`reto1_velocidad.ino`)
* Objetivo: Hacer que el contador avance más rápido.
* Solución implementada:** Se modificó la variable de tiempo (`waitDelay`) reduciendo su valor de `1000` ms a `500` ms, logrando que los LEDs cambien de estado cada medio segundo.

### 2. Reto 2: Conteo Descendente (`reto2_descendente.ino`)
* Objetivo: Contar hacia atrás en lugar de la secuencia normal.
* Solución implementada:** Se invirtió la lógica del bucle principal. El ciclo `for` ahora se inicializa en 15, tiene como condición ser mayor o igual a 0, y utiliza un decremento (`numero--`).

### 3. Reto 3: Modo Manual con Botón (`reto3_boton.ino`)
* Objetivo: El conteo solo debe avanzar cuando el usuario presione un botón.
* Solución implementada:** Se integró un pulsador conectado al **Pin 12** utilizando la resistencia interna del microcontrolador (`INPUT_PULLUP`). El código detecta el cambio de estado (flanco de bajada) para incrementar la variable `numero` manualmente, evitando rebotes mecánicos (*debounce*).

### 4. Reto 4: Números Pares (`reto4_pares.ino`)
* Objetivo: Mostrar únicamente los números pares en la secuencia binaria.
* Solución implementada:** Se ajustó el incremento del ciclo `for` principal. En lugar de avanzar de uno en uno (`numero++`), avanza de dos en dos (`numero += 2`), mostrando la secuencia: 0, 2, 4, 6, 8, 10, 12 y 14.

### 5. Reto 5: Quinto LED como Indicador de Tope (`reto5_quinto_led.ino`)
* Objetivo: Usar un quinto LED para indicar visualmente que el contador alcanzó su límite (15).
* Solución implementada:** Se configuró el **Pin 13** como una nueva salida digital. Dentro de la lógica del bucle, se agregó una estructura condicional `if (numero == 15)` que enciende este LED extra exclusivamente cuando el ciclo llega a su valor máximo, y lo apaga en el resto de los números.

---

## Instrucciones de Uso
1. Abre el archivo `.ino` correspondiente al reto que deseas probar en el **Arduino IDE**.
2. Verifica que las conexiones de hardware coincidan con los pines indicados (especialmente en los retos 3 y 5 que requieren hardware extra).
3. Selecciona tu placa (Arduino Uno) y el puerto correspondiente.
4. Presiona **Subir** para cargar el firmware.
