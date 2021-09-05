void starting()
{
  oled.clearBuffer();
  oled.setFont(u8g2_font_roentgen_nbp_tr);

  oled.setCursor(10, 20);
  oled.printf("Starting...");
  oled.sendBuffer();
  delay(500);
}

void drawWait()
{
  oled.clearBuffer();
  oled.setFont(u8g2_font_calibration_gothic_nbp_t_all);

  oled.drawStr(10, 25, "K E M");

  oled.setFont(u8g2_font_mozart_nbp_t_all);
  oled.drawStr(60, 7, "Keyboard");
  oled.drawStr(60, 17, "Extender");
  oled.drawStr(60, 27, "Maker");

  oled.sendBuffer();
}

void welcome()
{
  oled.clearBuffer();

  oled.setFont(u8g2_font_calibration_gothic_nbp_t_all);
  oled.drawStr(10, 25, "K");
  oled.setFont(u8g2_font_mozart_nbp_t_all);
  oled.drawStr(60, 7, "Keyboard");
  oled.sendBuffer();
  delay(800);

  oled.setFont(u8g2_font_calibration_gothic_nbp_t_all);
  oled.drawStr(23, 25, "E");
  oled.setFont(u8g2_font_mozart_nbp_t_all);
  oled.drawStr(60, 17, "Extender");
  oled.sendBuffer();
  delay(800);

  oled.setFont(u8g2_font_calibration_gothic_nbp_t_all);
  oled.drawStr(36, 25, "M");
  oled.setFont(u8g2_font_mozart_nbp_t_all);
  oled.drawStr(60, 27, "Maker");
  oled.sendBuffer();
  delay(800);
}

void drawKEY(const char *in_strKEY)
{
  oled.clearBuffer();
  oled.setFont(u8g2_font_roentgen_nbp_tr);
  oled.drawStr(10, 10, in_strKEY);
  oled.sendBuffer();
}

void drawVALUE(unsigned int in_VAL)
{
  oled.setFont(u8g2_font_chroma48medium8_8u);
  oled.setCursor(10, 25);
  oled.print(in_VAL);
  oled.sendBuffer();
}