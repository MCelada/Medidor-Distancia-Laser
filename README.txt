# Medidor de Distancia Láser con Factor de Calibración

## Descripción del Proyecto

Este proyecto implementa un medidor de distancia láser utilizando la placa Nucleo F401RE de STMicroelectronics, el sensor de distancia VL53L0X y un display OLED con interfaz I2C. La característica distintiva de este proyecto es la inclusión de un factor de calibración para mejorar la precisión de las mediciones en diversas condiciones.

## Características Principales

- **Sensor de Distancia VL53L0X:** Utiliza un sensor láser de tiempo de vuelo para mediciones precisas de distancia.

- **Placa Nucleo F401RE:** Microcontrolador STM32 Nucleo basado en el ARM Cortex-M4.

- **Display OLED con I2C:** Proporciona una interfaz de usuario visual para mostrar las mediciones.

- **Factor de Calibración:** Permite ajustar y calibrar el dispositivo para mejorar la precisión de las mediciones.

## Requisitos del Sistema

- **Hardware:**
  - Placa Nucleo F401RE
  - Sensor de Distancia VL53L0X
  - Display OLED con interfaz I2C
  - Conexiones y cables necesarios

- **Software:**
  - STM32CubeIDE u otro entorno de desarrollo compatible
  - Bibliotecas necesarias para el sensor VL53L0X y el display OLED

## Instalación y Configuración

1. **Clona el Repositorio:**

git clone https://github.com/tu-usuario/medidor-distancia-laser.git


2. **Configura el Hardware:**
- Conecta el sensor VL53L0X y el display OLED a la placa Nucleo F401RE según las especificaciones del fabricante.

3. **Configuración del Proyecto:**
- Abre el proyecto en STM32CubeIDE (o tu entorno de desarrollo preferido) y configura el proyecto según las especificaciones de hardware.

4. **Carga el Código:**
- Compila y carga el código en la placa Nucleo F401RE.

5. **Calibración:**
- Sigue las instrucciones proporcionadas en el código para realizar la calibración inicial.

## Uso

1. Enciende el dispositivo.

2. Selecciona el objeto al que deseas medir la distancia.

3. Observa la distancia medida en el display OLED.

## Contribuciones

Las contribuciones son bienvenidas. Si encuentras errores o tienes mejoras, por favor, crea un problema o envía una solicitud de extracción.
