# Sistema de riego automatizado
El proyecto consiste en mantener una planta con cierto rango de humedad. Para ello debemos estar leyendo constantemente la humedad de la planta, y en tal caso de que tenga poca humedad, encender el sistema de riego.

## Materiales
| Cantidad | Artículo                  |                                        Imagen                                        |
|:--------:|:--------------------------|:------------------------------------------------------------------------------------:|
|   0.5    | Cable de red UTP (Metros) |            <img src='./assets/images/cable-de-red-utp.jpeg' width='150'>             |
|    1     | Arduino UNO               | <img src='./assets/images/arduino-uno-r3-atmega-dip-328p-chip-grde.jpg' width='150'> |
|    1     | Sensor de humedad LM393   |         <img src='./assets/images/sensor-de-humedad-lm393.jpg' width='150'>          |
|    1     | Bomba de agua para pecera |        <img src='./assets/images/bomba-de-agua-para-pecera.webp' width='150'>        |
|    1     | Led (Cualquier color)     |                   <img src='./assets/images/led.webp' width='150'>                   |
|    1     | Resistencia 240 Ω         |               <img src='./assets/images/resistencias.png' width='150'>               |
|    1     | Resistencia 1 kΩ          |               <img src='./assets/images/resistencias.png' width='150'>               |
|    1     | Resistencia 10 kΩ         |               <img src='./assets/images/resistencias.png' width='150'>               |
|    1     | Micro Pulsador            |             <img src='./assets/images/micro-pulsador.webp' width='150'>              |
|    1     | Transistor 2N2222A (BJT)  |          <img src='./assets/images/transistor-2n2222a-bjt.jpg' width='150'>          |
|    1     | Relé de 5 VDC             |              <img src='./assets/images/rele-de-5-vdc.jpg' width='150'>               |
|    1     | Diodo                     |                  <img src='./assets/images/diodo.jpg' width='150'>                   |

## Programación
- [Arduino UNO](./arduino-sistema-de-riego.ino)

## Recursos utilizados

### Uso y configuración del sensor de humedad LM393 (Video)
[![SERIE SENSORES Y MÓDULOS #4: SENSOR DE HUMEDAD DE SUELO HL-69 / YL-69](https://img.youtube.com/vi/ppvKm-5BG-0/0.jpg)](https://www.youtube.com/watch?v=ppvKm-5BG-0)

### Uso y configuración del relé de 5 VDC (Video)
[![Conectar 110V / 220V con Arduino](https://img.youtube.com/vi/Gif-vw9FtII/0.jpg)](https://www.youtube.com/watch?v=Gif-vw9FtII)

### Esquema del Arduino UNO
![Esquema del Arduino UNO](./assets/images/arduino-uno-esquema.png)