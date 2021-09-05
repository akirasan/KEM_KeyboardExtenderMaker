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

void setup_Keys()
{

  KEM.setKeyFunc(KEM_KEY1, ADD_CUBE_BLENDER, "add cube");
  KEM.setColorPress(KEM_KEY1, 255, 255, 255);

  KEM.setKey(KEM_KEY2, PIN_KEY2, LED_KEY2, MODE_HOLDED);
  KEM.setColorComand1(KEM_KEY2, 255, 0, 0);
  KEM.setKeyFuncComand1(KEM_KEY2, Send_KEY2_func1, "key 2 f1");

  KEM.setColorComand2(KEM_KEY2, 0, 255, 0);
  KEM.setKeyFuncComand2(KEM_KEY2, Send_KEY2_func2, "key 2 f2");

  KEM.setKeyFunc(KEM_KEY3, HelloWorld, "Hello World");
  KEM.setColorPress(KEM_KEY3, 255, 255, 255);

  KEM.setKeyFunc(KEM_KEY4, ALT_TAB, "ALT + TAB");
  KEM.setColorPress(KEM_KEY4, 255, 5, 5);

  KEM.setColorPress(KEM_KEY5, 255, 255, 255);
  KEM.setColorPress(KEM_KEY6, 255, 255, 255);
  KEM.setColorPress(KEM_KEY7, 255, 255, 255);
  KEM.setColorPress(KEM_KEY8, 255, 255, 255);

  KEM.setColorDefault(0, 0, 50);
  KEM.setColorBase(50, 0, 255);
  
  allColorBASE(50, 0, 150);
}

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
