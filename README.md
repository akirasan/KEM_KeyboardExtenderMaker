# KEM Keyboard Extender Maker
KEM Keyboard Extender Maker

Las principales características de KE-M son:

- 8 teclas configurables en dos posibles modos:
-- MODE_PRESS: al pulsar se ejecuta una función que envía códigos
-- MODE_HOLDED: es un doble modo, al pulsar se ejecuta una función, al volver a pulsar se envía otra.
- Pantalla OLED para mostrar mensajes
- LEDs RGBs en la base y en cada una de las teclas
- Librerías de control **U8g2lib.h**, **AdafruitNeoPixel.h** y **Keyboard.h**

![](https://github.com/akirasan/KEM_KeyboardExtenderMaker/blob/main/images/KE-M%20keyboard%20extender%20maker.jpg)

# Componentes hardware
El microprocesador que he utilizado es una pequeña placa de desarrollo Seeeduino XIAO SAMD21 Cortex M0+ que va perfecta para ser integrada en una PCB.

El resto de componentes básicos:

- 4x leds RGB WS2812B
- 8x leds RGB WS2812 2020
- 8x teclas transparentes
- 8x interruptores MX para PCB
- 1x pantalla OLED 128x32 (0,91") I2C (opcional)

![](https://github.com/akirasan/KEM_KeyboardExtenderMaker/blob/main/images/KEM004.jpg)
![](https://github.com/akirasan/KEM_KeyboardExtenderMaker/blob/main/images/KEM005.jpg)

# ¿Qué podemos hacer con la clase KeyboardExtMaker?

**setKey** permite definir la configuración del teclado. Por defecto al instanciar la clase se configura todo según PCB, pero está disponible por si se quiere alterar alguna cosa.

**setKeyFunc**, **setKeyFuncComand1**, **setKeyFuncComand2** estos métodos permiten configurar a qué función llamar cuando se pulsa una tecla y que mensaje hay que mostrar en la pantalla OLED.

**setColor***** son métodos para configurar los leds RGBs de la base, de estado de reposo de las teclas y cuando son pulsados.

**loop** es el método que inicia todo el control del keyboard de forma recurrente

# Configuración de las keys
En el fichero **keys_config.h** hay que modificar la función que hay **setup_Keys()**, para indicar comportamiento de cada una de la teclas.


# Opensource
El proyecto es opensource y a parte de este repositorio, lo puedes encontrar también en mi blog:
https://akirasan.net/kem-keyboard-extender-maker/

...y en PCBWay he compartido el proyecto:
https://www.pcbway.com/project/shareproject/KE_M_Keyboard_Extender_Maker.html
