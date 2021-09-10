// Ejemplo de fichero de configuración basica
//

void setup_Keys()
{

  KEM.setKeyFunc(KEM_KEY1, CRTL_ALT_SHIFT_1, "key 1");
  KEM.setColorPress(KEM_KEY1, 255, 255, 255);

  KEM.setKeyFunc(KEM_KEY2, CRTL_ALT_SHIFT_2, "key 2");
  KEM.setColorPress(KEM_KEY2, 255, 255, 255);

  KEM.setKeyFunc(KEM_KEY3, CRTL_ALT_SHIFT_3, "key 3");
  KEM.setColorPress(KEM_KEY3, 255, 255, 255);

  KEM.setKeyFunc(KEM_KEY4, CRTL_ALT_SHIFT_4, "key 4");
  KEM.setColorPress(KEM_KEY4, 255, 255, 255);

  KEM.setKeyFunc(KEM_KEY5, CRTL_ALT_SHIFT_5, "key 5");
  KEM.setColorPress(KEM_KEY5, 255, 255, 255);

  KEM.setKeyFunc(KEM_KEY6, CRTL_ALT_SHIFT_6, "key 6");
  KEM.setColorPress(KEM_KEY6, 255, 255, 255);

  KEM.setKeyFunc(KEM_KEY7, CRTL_ALT_SHIFT_7, "key 7");
  KEM.setColorPress(KEM_KEY7, 255, 255, 255);

  KEM.setKeyFunc(KEM_KEY8, CRTL_ALT_SHIFT_8, "key 8");
  KEM.setColorPress(KEM_KEY8, 255, 255, 255);

  KEM.setColorDefault(0, 0, 50);
  KEM.setColorBase(50, 0, 255);
  
  allColorBASE(50, 0, 150);
}