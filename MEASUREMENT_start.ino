void MEASUREMENT_start()
{
  if (start_meas == true)
  {

    if (start_open_file == true)
    {
      TCA9548A(0);
      AFE_GROUPled.initSECOND();
      TCA9548A(1);
      AFE_IRled.initFIRST();
      
      percentage_variable = percentage_variable_map;
      number_of_meas = number_of_meas + 1;    //zmiana nazyw pliku przy kolejnym pomiarze data_X_...


      file_name = data_name + String(number_of_meas) + "_" + String(number_of_data) + ".txt";  //nazwa pliku txt


      // obsługa ekranu
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("SAVING   ");
      lcd.setCursor(0, 1);
      lcd.print(file_name);



      myFile = SD.open(file_name, FILE_WRITE);    //otwarcie zapisu do pliku


      millis_time_now = millis();

      millis_time_mem_2 = millis_time_now;


      start_open_file = false;        //wyłączenie measuremnt_start po utworzeniu nowej serii pomiarowej
    }
    MEASUREMENT();
  }
}
