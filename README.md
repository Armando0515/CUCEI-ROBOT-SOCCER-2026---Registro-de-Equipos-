# CUCEI-ROBOT-SOCCER-2026 

Una implementación de firmware robusta escrita para ESP32 para controlar un robot de fútbol con tracción diferencial utilizando mandos Bluetooth modernos (Xbox One/Series, PS4 DualShock, PS5 DualSense, Switch Pro Controller, etc.).

* INSTALACIÓN Y CONFIGURACIÓN DEL SOFTWARE:

 - Paso 1. Agregar la URL del Gestor de Tarjetas:
Abre Arduino IDE.
Ve a Archivo → Preferencias (o presiona Ctrl + ,).
Busca el campo Gestor de URLs Adicionales de Tarjetas.
Pega la siguiente URL: https://raw.githubusercontent.com/ricardoquesada/esp32-arduino-lib-builder/master/bluepad32_files/package_esp32_bluepad32_index.json
Da click en aceptar.

 - Paso 2: Instalar el Paquete de Placas
Dirígete a Herramientas → Placa → Gestor de tarjetas...
En el buscador escribe: ESP32 + Bluepad32
Selecciona el paquete e haz clic en Instalar.

 - Paso 3: Seleccionar la Placa Correcta
Ve a Herramientas → Placa → ESP32 + Bluepad32 Arduino.
Selecciona ESP32 Dev Module.
⚠️ Importante: NO selecciones el ESP32 Dev Module estándar de Espressif. Debes seleccionar la opción dentro del menú de ESP32 + Bluepad32 Arduino, de lo contrario el firmware no compilará o el Bluetooth no inicializará.

    * Enparejamiento del Control:
Carga el Código: Graba el programa carro.ino en tu tarjeta ESP32.
Abre el Monitor Serie: Configura la velocidad en 115200 baudios.
Pon el Mando en Modo Emparejamiento:
Xbox (Modelo 1708+): Enciende el mando y mantén presionado el botón de vinculación superior hasta que el botón Xbox parpadee rápidamente.
PS4 / PS5: Mantén presionados los botones Share/Create + Botón PS simultáneamente hasta que la barra de luz parpadee en ráfagas dobles.
Conexión Automática: El ESP32 borra las llaves previas al iniciar (BP32.forgetBluetoothKeys()) y se conectará automáticamente al mando que esté buscando conexión.
El Monitor Serie mostrará CONTROL XBOX CONECTADO una vez establecida la vinculación o si quieres una conexión sencilla para cambiar de mando constamente deja dicha linea en el codigo.

CODIGO EN ROBOT: El código interpreta las palancas (joysticks) y las cuales podria traducir en movimiento físico en la cancha si así se quisiera. Las palancas analógicas de los mandos de Xbox o PS4 envían valores en el rango de -512 a 512 en cada eje, pero como los potenciómetros físicos nunca regresan a un cero perfecto al soltarlos, el código aplica un filtro de zona muerta, ya que si la lectura es menor a 100, lo toma como 0 o sin movimiento. 

Nosotros como prueba base recomendamos: 

- Joystick Izquierdo Eje Y (ly): Controla el avance y la reversa (se invierte el signo -ly porque mover la palanca hacia arriba entrega valores negativos).
- Joystick Izquierdo Eje X (lx): Controla la dirección y rotación (valores negativos a la izquierda, positivos a la derecha).

Pueden existir distintas formas de programarlo, por ejemplo un boton de aceleración y otro de reversa con valores constantes en ambos motores, esta parte queda a la imaginación y comodidades del equipo. 

 * COMPONENTES NECESARIOS PARA ARMADO FÍSICO:

Para cada equipo participante sera otorgado un chasis impreso en 3D obligatorio a usar como el siguiente: 

<p align="center">
  <img src="https://github.com/user-attachments/assets/f48173c1-1694-45f0-bc6e-49401f864f50" width="300" alt="Esquema 2">
</p>

En dicho chasis, se debera utilizar un par de motoreductores amarillos convencionales, los cuales estaran sujetos al chasis mediante tornilleria y junto con su respectiva llanta usal. En cuestiones de alimentación se debera contar con portapilas con capacidad de dos baterias de un tamaño y capacidad de 3.7V con su respectivo switch de encedido y apagado del robor, se recomienda dichas baterias por cuestiones de espacio en el chasis. Todo esto se puede interpretar mejor en la siguiente imagen. 

<p align="center">
  <img src="https://github.com/user-attachments/assets/69354280-8824-4825-9bfd-1800a8b3ec47" width="300" alt="Esquema 1">
</p>

A continuación se mostrara un circuito de conexión base, el uso de alimentación, microcontrolador y puente H es recomendado, estos apartados quedan a disposición de cada equipo, solo recuerden que debe tener conexión bluethoot y debe ser teleoperado. 

<p align="center">
  <img src="https://github.com/user-attachments/assets/85006c56-b13d-43e4-b259-beccdade3f96" width="300" alt="Esquema 3">
</p>
 
Listo, ya con todas las bases anteriores puedes comenzar con el armado y programación de tu robot - soccer listo para competir. 
¡MUCHO EXITO A TODOS!
  

