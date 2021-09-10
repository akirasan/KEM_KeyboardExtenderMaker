//===== Comandos preconfigurados listos para usar
// Librería de comandos compartidos

// S.O.
//===== ALT + TAB
void ALT_TAB()
{
    Keyboard.press(KEY_LEFT_ALT);
    delay(10);
    Keyboard.press(KEY_TAB);
    delay(10);
    Keyboard.releaseAll();
}

// BLENDER
//===== Crea un CUBO en BLENDER en el cursor
void ADD_CUBE_BLENDER()
{
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.write('a');
    delay(10);
    Keyboard.release(KEY_LEFT_SHIFT);
    delay(10);

    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.write('m');
    delay(10);
    Keyboard.release(KEY_LEFT_ALT);
    delay(10);

    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.write('c');
    delay(10);
    Keyboard.release(KEY_LEFT_ALT);
}

// Combinaciones imposibles I
// Crtl+Alt+Shift____1 al 8
// =======
void CRTL_ALT_SHIFT_1()
{
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.write('1');
    delay(10);
    Keyboard.releaseAll();
}
void CRTL_ALT_SHIFT_2()
{
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.write('2');
    delay(10);
    Keyboard.releaseAll();
}
void CRTL_ALT_SHIFT_3()
{
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.write('3');
    delay(10);
    Keyboard.releaseAll();
}
void CRTL_ALT_SHIFT_4()
{
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.write('4');
    delay(10);
    Keyboard.releaseAll();
}
void CRTL_ALT_SHIFT_5()
{
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.write('5');
    delay(10);
    Keyboard.releaseAll();
}
void CRTL_ALT_SHIFT_6()
{
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.write('6');
    delay(10);
    Keyboard.releaseAll();
}
void CRTL_ALT_SHIFT_7()
{
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.write('7');
    delay(10);
    Keyboard.releaseAll();
}
void CRTL_ALT_SHIFT_8()
{
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY_LEFT_SHIFT);
    Keyboard.write('8');
    delay(10);
    Keyboard.releaseAll();
}
// =======