void graph()
{
  TCA9548A(1);
  switch (graph_menu_number)
  {
    case 1:
      lcd.setCursor(0, 0);
      lcd.print("A.get_led1_val     ");
      lcd.setCursor(0, 1);
      lcd.print("NEXT             ");
      Serial.println(AFE_IRled.get_led1_val());
      break;

    case 2:
      lcd.setCursor(0, 0);
      lcd.print("A.get_led2_val     ");
      lcd.setCursor(0, 1);
      lcd.print("NEXT             ");
      Serial.println(AFE_IRled.get_led2_val());
      break;

    case 3:
      lcd.setCursor(0, 0);
      lcd.print("A.get_led3_val    ");
      lcd.setCursor(0, 1);
      lcd.print("NEXT             ");
      Serial.println(AFE_IRled.get_led3_val());
      break;

    case 4:
      lcd.setCursor(0, 0);
      lcd.print("A.get_Aled1_val    ");
      lcd.setCursor(0, 1);
      lcd.print("NEXT             ");
      Serial.println(AFE_IRled.get_Aled1_val());
      break;

    case 5:
      lcd.setCursor(0, 0);
      lcd.print("A.get_led1_ALED1_val   ");
      lcd.setCursor(0, 1);
      lcd.print("NEXT             ");
      Serial.println(AFE_IRled.get_led1_ALED1_val());
      break;

    case 6:
      lcd.setCursor(0, 0);
      lcd.print("A.get_led2_ALED2_val    ");
      lcd.setCursor(0, 1);
      lcd.print("NEXT             ");
      Serial.println(AFE_IRled.get_led2_ALED2_val());
      break;
  }
}
