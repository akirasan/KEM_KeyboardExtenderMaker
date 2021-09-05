void testleds_pcb()
{
    allColorKEY(0, 0, 255);
    delay(500);
    allColorKEY(0, 255, 0);
    delay(500);
    allColorKEY(255, 0, 0);
    delay(500);
    allColorKEY(255, 255, 255);
    delay(500);

    allColorKEY(0, 0, 0);

    allColorBASE(0, 0, 255);
    delay(500);
    allColorBASE(0, 255, 0);
    delay(500);
    allColorBASE(255, 0, 0);
    delay(500);
    allColorBASE(255, 255, 255);
    delay(500);
    allColorBASE(0, 0, 0);
    delay(500);

    allColorKEY(0, 0, 255);
    allColorBASE(0, 0, 255);
    delay(500);

    allColorKEY(0, 255, 0);
    allColorBASE(0, 255, 0);
    delay(500);

    allColorKEY(255, 0, 0);
    allColorBASE(255, 0, 0);
    delay(500);

    allColorKEY(255, 255, 255);
    allColorBASE(255, 255, 255);

    delay(1000);
    allColorKEY(0, 0, 0);
    allColorBASE(0, 0, 0);
}

void testkeys_pcb()
{
    pinMode(PIN_KEY1, INPUT_PULLUP);
    pinMode(PIN_KEY2, INPUT_PULLUP);
    pinMode(PIN_KEY3, INPUT_PULLUP);
    pinMode(PIN_KEY4, INPUT_PULLUP);
    pinMode(PIN_KEY5, INPUT_PULLUP);
    pinMode(PIN_KEY6, INPUT_PULLUP);
    pinMode(PIN_KEY7, INPUT_PULLUP);
    pinMode(PIN_KEY8, INPUT_PULLUP);

 Serial.print("KEY1: ");
    Serial.println(digitalRead(PIN_KEY1));
    Serial.print("KEY2: ");
    Serial.println(digitalRead(PIN_KEY2));
    Serial.print("KEY3: ");
    Serial.println(digitalRead(PIN_KEY3));
    Serial.print("KEY4: ");
    Serial.println(digitalRead(PIN_KEY4));
    Serial.print("KEY5: ");
    Serial.println(digitalRead(PIN_KEY5));
    Serial.print("KEY6: ");
    Serial.println(digitalRead(PIN_KEY6));
    Serial.print("KEY7: ");
    Serial.println(analogRead(PIN_KEY7));
    Serial.print("KEY8: ");
    Serial.println(analogRead(PIN_KEY8));


    delay(1000);
}