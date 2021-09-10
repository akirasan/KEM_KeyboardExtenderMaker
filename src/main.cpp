#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>
#include <Keyboard.h>
#include <Adafruit_NeoPixel.h>

#include "configuration.h"

//#define TESTPCB

#include "oled_control.h"
#include "led_control.h"
#include "kem_control.hpp"

#ifdef TESTPCB
#include "PCB_test.h"
#endif

KeyboardExtMaker KEM;

#include "keys_config.h"

void setup()
{
  oled.begin();
  Keyboard.begin();
  led_key.begin();
  led_base.begin();

  led_key.clear();
  led_key.show();
  led_base.clear();
  led_base.show();

#ifndef TESTPCB
  starting();
  welcome();
  rotateKEY_led_color(150, 0, 55, 70, false);
  rotateKEY_led_color(150, 0, 55, 70, true);
#endif

  setup_Keys();
}

void loop(void)
{
#ifdef TESTPCB
  //testleds_pcb();
  testkeys_pcb();
#endif

#ifndef TESTPCB
  KEM.loop();
#endif
}
