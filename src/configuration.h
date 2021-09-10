// KEM Keyboard Extender Maker
//
// Definición básica de PCB-KEM

#define PIN_LEDS_KEY 10
#define PIN_LEDS_BASE 9

#define NUMPIXELS_KEYS 8
#define NUMPIXELS_BASE 4

#define DELAY_PRESS 50

#define PIN_KEY1 0
#define PIN_KEY2 1
#define PIN_KEY3 2
#define PIN_KEY4 3
#define PIN_KEY5 6
#define PIN_KEY6 8
#define PIN_KEY7 7
#define PIN_KEY8 7

#define LED_KEY1 0
#define LED_KEY2 1
#define LED_KEY3 2
#define LED_KEY4 3
#define LED_KEY5 4
#define LED_KEY6 5
#define LED_KEY7 6
#define LED_KEY8 7

#define KEM_KEY1 0
#define KEM_KEY2 1
#define KEM_KEY3 2
#define KEM_KEY4 3
#define KEM_KEY5 4
#define KEM_KEY6 5
#define KEM_KEY7 6
#define KEM_KEY8 7

Adafruit_NeoPixel led_key(NUMPIXELS_KEYS, PIN_LEDS_KEY, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel led_base(NUMPIXELS_BASE, PIN_LEDS_BASE, NEO_GRB + NEO_KHZ800);
U8G2_SSD1306_128X32_UNIVISION_F_HW_I2C oled(U8G2_R0, /* clock=*/5, /* data=*/4, /* reset=*/U8X8_PIN_NONE); // High speed I2C

//================================== KEY CONFIGURATION
#include "keys_preconfig.h"
#include "keys_functions_user.h"
