//===== Definicion funciones custom para keys MODO_PRESS
void HelloWorld()
{
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.write(' ');
    delay(50);
    Keyboard.write('h');
    delay(50);
    Keyboard.write('e');
    delay(50);
    Keyboard.write('l');
    delay(50);
    Keyboard.write('l');
    delay(50);
    Keyboard.write('o');
    delay(50);
    Keyboard.write(' ');
    delay(500);
    Keyboard.write('w');
    delay(50);
    Keyboard.write('o');
    delay(50);
    Keyboard.write('r');
    delay(50);
    Keyboard.write('l');
    delay(50);
    Keyboard.write('d');
    delay(50);
    Keyboard.releaseAll();
}



//===== Definicion funciones custom para keys MODO_HOLDED
void Send_KEY2_func1()
{
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.write('1');
    delay(10);
    Keyboard.releaseAll();
}

void Send_KEY2_func2()
{
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.write('2');
    delay(10);
    Keyboard.releaseAll();
}
