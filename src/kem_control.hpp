// KEM Keyboard Extender Maker
// by akirasan
// septiembre 2021
// -------------------------------------------------

#include <Arduino.h>

#define MODE_PRESS 1
#define MODE_HOLDED 2

class KeyboardExtMaker
{

public:
    KeyboardExtMaker(class Adafruit_NeoPixel);
    void setKey(byte, byte, byte, byte, byte sensibilidad = 5, const char *texto = "KEY");
    void setKeyFunc(byte, voidFuncPtr, const char *text_cmd1 = "KEY");
    void setKeyFuncComand1(byte, voidFuncPtr, const char *text_cmd1 = "KEY");
    void setKeyFuncComand2(byte, voidFuncPtr, const char *text_cmd2 = "KEY");

    void setColorDefault(byte, byte, byte);
    void setColorPress(byte, byte, byte, byte);
    void setColorComand1(byte, byte, byte, byte);
    void setColorComand2(byte, byte, byte, byte);
    void setColorBase(byte, byte, byte);
    void showColorKeys();
    boolean KeyPressed();

    void loop();

private:
    typedef void (*voidFuncPtr)(void);
    typedef struct
    {
        byte PinKey;
        byte Led;
        byte Mode;
        byte Sensibilidad;
        boolean Status = false;
        voidFuncPtr callfunc_cmd1;
        voidFuncPtr callfunc_cmd2;

        const char *text_cmd1;
        const char *text_cmd2;

        byte R_st1;
        byte G_st1;
        byte B_st1;

        byte R_st2;
        byte G_st2;
        byte B_st2;

        boolean Keypressed;

    } KEMkeys;

    typedef struct
    {
        byte R;
        byte G;
        byte B;
    } KEMbase;

    KEMkeys KeysKEM[8];
    KEMbase LedsBase[4];

    byte colorKeyDef_R;
    byte colorKeyDef_G;
    byte colorKeyDef_B;
};

//====================================================

KeyboardExtMaker::KeyboardExtMaker(class Adafruit_NeoPixel = led_key)
{

    // Definimos lo básico de todo el teclado
    setKey(KEM_KEY1, PIN_KEY1, LED_KEY1, MODE_PRESS, 5, "KEY 1");
    setKey(KEM_KEY2, PIN_KEY2, LED_KEY2, MODE_PRESS, 5, "KEY 2");
    setKey(KEM_KEY3, PIN_KEY3, LED_KEY3, MODE_PRESS, 5, "KEY 3");
    setKey(KEM_KEY4, PIN_KEY4, LED_KEY4, MODE_PRESS, 5, "KEY 4");
    setKey(KEM_KEY5, PIN_KEY5, LED_KEY5, MODE_PRESS, 5, "KEY 5");
    setKey(KEM_KEY6, PIN_KEY6, LED_KEY6, MODE_PRESS, 5, "KEY 6");
    setKey(KEM_KEY7, PIN_KEY7, LED_KEY7, MODE_PRESS, 5, "KEY 7");
    setKey(KEM_KEY8, PIN_KEY8, LED_KEY8, MODE_PRESS, 5, "KEY 8");

    //Color base todo el teclado
    colorKeyDef_R = 0;
    colorKeyDef_G = 0;
    colorKeyDef_B = 0;
}

void KeyboardExtMaker::setColorDefault(byte red, byte green, byte blue)
{
    colorKeyDef_R = red;
    colorKeyDef_G = green;
    colorKeyDef_B = blue;
    allColorKEY(colorKeyDef_R, colorKeyDef_G, colorKeyDef_B);
}

void KeyboardExtMaker::showColorKeys()
{
    for (byte i = 0; i < 8; i++)
    {
        if (KeysKEM[i].Mode == MODE_HOLDED)
        {
            if (KeysKEM[i].Status)
            {
                led_key.setPixelColor(KeysKEM[i].Led, KeysKEM[i].R_st1, KeysKEM[i].G_st1, KeysKEM[i].B_st1);
            }
            else
            {
                led_key.setPixelColor(KeysKEM[i].Led, KeysKEM[i].R_st2, KeysKEM[i].G_st2, KeysKEM[i].B_st2);
            }
        }
        else
        {
            if (KeysKEM[i].Mode == MODE_PRESS)
            {
                led_key.setPixelColor(KeysKEM[i].Led, colorKeyDef_R, colorKeyDef_G, colorKeyDef_B);
            }
        }
    }
    led_key.show();
}

void KeyboardExtMaker::loop()
{
    unsigned long tiempo1 = 0;
    unsigned long tiempo2 = 0;

    while (true)
    {
        tiempo2 = millis();

        for (byte i = 0; i < 8; i++)
        {
            int valor = analogRead(KeysKEM[i].PinKey);
            if ((valor < 10) && (i < KEM_KEY8)) //KEY8 y KEY7 comparten PIN
            {
                KeysKEM[i].Keypressed = true;
                delay(KeysKEM[i].Sensibilidad);
            }
            else
            {
                if ((valor > 300) && (valor < 1023) && (i == KEM_KEY8)) //KEY8 y KEY7 comparten PIN
                {
                    KeysKEM[i].Keypressed = true;
                    delay(KeysKEM[i].Sensibilidad);
                }
            }
            delay(10);
        }

        for (byte i = 0; i < 8; i++)
        {

            if ((KeysKEM[i].Keypressed) && (KeysKEM[i].Mode == MODE_PRESS))
            {
                KeysKEM[i].Keypressed = false;
                led_key.setPixelColor(KeysKEM[i].Led, KeysKEM[i].R_st1, KeysKEM[i].G_st1, KeysKEM[i].B_st1);
                led_key.show();
                drawKEY(KeysKEM[i].text_cmd1);
                if (KeysKEM[i].callfunc_cmd1 != NULL)
                {
                    KeysKEM[i].callfunc_cmd1();
                }

                delay(DELAY_PRESS);
                tiempo1 = millis();
            }
            else
            {
                if ((KeysKEM[i].Keypressed) && (KeysKEM[i].Mode == MODE_HOLDED))
                {
                    KeysKEM[i].Keypressed = false;
                    KeysKEM[i].Status = !KeysKEM[i].Status;
                    if (KeysKEM[i].Status)
                    {
                        drawKEY(KeysKEM[i].text_cmd1);
                        KeysKEM[i].callfunc_cmd1();
                    }
                    else
                    {
                        drawKEY(KeysKEM[i].text_cmd2);
                        KeysKEM[i].callfunc_cmd2();
                    }
                    delay(DELAY_PRESS);
                    tiempo1 = millis();
                }
            }
            showColorKeys();
        }
        if ((tiempo1 + 1000) < tiempo2)
        {
            drawWait();
        }
    }
}

void KeyboardExtMaker::setKey(byte number_key, byte pin_key, byte led_position, byte mode, byte sensibilidad, const char *texto)
{

    KeysKEM[number_key].Led = led_position;
    KeysKEM[number_key].PinKey = pin_key;

    KeysKEM[number_key].Status = 0;
    KeysKEM[number_key].Mode = mode;
    KeysKEM[number_key].Sensibilidad = sensibilidad;

    KeysKEM[number_key].text_cmd1 = texto;
    KeysKEM[number_key].text_cmd2 = texto;
    KeysKEM[number_key].callfunc_cmd1 = NULL;
    KeysKEM[number_key].callfunc_cmd2 = NULL;

    pinMode(KeysKEM[number_key].PinKey, INPUT_PULLUP);
}

// Define funcion al presionar MODO_PRESS
void KeyboardExtMaker::setKeyFunc(byte number_key, voidFuncPtr call_func, const char *texto)
{
    KeysKEM[number_key].callfunc_cmd1 = call_func;
    KeysKEM[number_key].text_cmd1 = texto;
}

// Define funcion al presionar estado 1 MODO_HOLDED
void KeyboardExtMaker::setKeyFuncComand1(byte number_key, voidFuncPtr call_func, const char *texto)
{
    KeysKEM[number_key].callfunc_cmd1 = call_func;
    KeysKEM[number_key].text_cmd1 = texto;
}

// Define funcion al presionar estado 1 MODO_HOLDED
void KeyboardExtMaker::setKeyFuncComand2(byte number_key, voidFuncPtr call_func, const char *texto)
{
    KeysKEM[number_key].callfunc_cmd2 = call_func;
    KeysKEM[number_key].text_cmd2 = texto;
}

boolean KeyboardExtMaker::KeyPressed()
{
    return false;
}

// Color al presionar MODO_PRESS
void KeyboardExtMaker::setColorPress(byte number_key, byte red, byte green, byte blue)
{
    KeysKEM[number_key].R_st1 = red;
    KeysKEM[number_key].G_st1 = green;
    KeysKEM[number_key].B_st1 = blue;
}

// Color en estado 1 MODO_HOLDED
void KeyboardExtMaker::setColorComand1(byte number_key, byte red, byte green, byte blue)
{
    KeysKEM[number_key].R_st1 = red;
    KeysKEM[number_key].G_st1 = green;
    KeysKEM[number_key].B_st1 = blue;
}

// Color en estado 2 MODO_HOLDED
void KeyboardExtMaker::setColorComand2(byte number_key, byte red, byte green, byte blue)
{
    KeysKEM[number_key].R_st2 = red;
    KeysKEM[number_key].G_st2 = green;
    KeysKEM[number_key].B_st2 = blue;
}

// Color de toda la base
void KeyboardExtMaker::setColorBase(byte red, byte green, byte blue)
{
    for (byte i = 0; i < 4; i++)
    {
        LedsBase[i].R = red;
        LedsBase[i].G = green;
        LedsBase[i].B = blue;
    }
}
