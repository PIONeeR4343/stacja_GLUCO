void sd_verification()
{
  while (!SD.exists(file_name))  //funkcja sprawdzająca czy dany plik istnieje na karcie SD
  {
    delay(100);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("error");
    lcd.setCursor(0, 1);
    lcd.print("error");
  }
}
