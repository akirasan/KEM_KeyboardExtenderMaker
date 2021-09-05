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


