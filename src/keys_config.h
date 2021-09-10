void setup_Keys()
{

  KEM.setKeyFunc(KEM_KEY1, ADD_CUBE_BLENDER, "add cube");
  KEM.setColorPress(KEM_KEY1, 255, 255, 255);

  KEM.setKey(KEM_KEY2, PIN_KEY2, LED_KEY2, MODE_HOLDED);
  KEM.setColorComand1(KEM_KEY2, 255, 0, 0);
  KEM.setColorComand2(KEM_KEY2, 0, 255, 0);
  KEM.setKeyFuncComand1(KEM_KEY2, Send_KEY2_func1, "func 1");
  KEM.setKeyFuncComand2(KEM_KEY2, Send_KEY2_func2, "func 2");

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