void rotateKEY_led_color(byte R, byte G, byte B, unsigned time_wait, boolean inversa = false)
{
    if (!inversa)
    {
        for (int i = 0; i < NUMPIXELS_KEYS; i++)
        {
            led_key.setPixelColor(i, led_key.Color(R, G, B));
            led_key.show();
            delay(time_wait);
            led_key.setPixelColor(i, led_key.Color(0, 0, 0));
            led_key.show();
        }
    }
    else
    {
        for (int i = NUMPIXELS_KEYS; i > 0; i--)
        {
            led_key.setPixelColor(i, led_key.Color(R, G, B));
            led_key.show();
            delay(time_wait);
            led_key.setPixelColor(i, led_key.Color(0, 0, 0));
            led_key.show();
        }
    }
}

void rotateBASE_led_color(byte R, byte G, byte B, unsigned time_wait)
{
    for (int i = 0; i < NUMPIXELS_BASE; i++)
    {
        led_base.setPixelColor(i, led_base.Color(R, G, B));
        led_base.show();
        delay(time_wait);
        led_base.setPixelColor(i, led_base.Color(0, 0, 0));
        led_base.show();
    }
}

void allColorKEY(byte R, byte G, byte B)
{
    led_key.fill(led_key.Color(R, G, B));
    led_key.show();
}

void allColorBASE(byte R, byte G, byte B)
{
    led_base.fill(led_base.Color(R, G, B));
    led_base.show();
}
