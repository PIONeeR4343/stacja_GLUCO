void MEASUREMENT()
{
  HR(SensorValue_2);

  while (millis_time_now - millis_time_mem_1 >= 19)
  {

    millis_time_now = millis();
    millis_time_mem_1 = millis_time_now;

    i = i + 1;          // zmienna opisująca ilość próbek w jednym txt

    TCA9548A(1);
    SensorValue = labs(AFE_IRled.get_led1_val());         // odpytanie AFE
    TCA9548A(0);
    SensorValue_2 = AFE_GROUPled.get_led1_val();

    GSR = analogRead(ANALOG_PIN);

    data = String(i) + ";" + time_now + ";" + String(SensorValue) + ";" + String(avg_hr) + ";" + String(GSR) + ";" + String(znacznik);     // definiowanie pojedynczego wiersza pliku txt
    znacznik = "--";


    if (myFile)
    {
      myFile.println(data);        //zapis do pliku

      data = "";                  //"zerowanie" zmiennej data
    }
    else                          //błąd zapisu do pliku
    {
      delay(1000);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("error");
      lcd.setCursor(0, 1);
      lcd.print("error");
    }

    while (millis_time_now - millis_time_mem_2 >= 500UL)       //zakończenie zapisu co 500ms
    {
      millis_time_now = millis();
      millis_time_mem_2 = millis_time_now;

      file_size = myFile.size() / 1000;          //zmienna opisująca rozmiar poprzedniego pliku txt

      myFile.close();                   //zamkniecie i weryfikacja pliku txt

      percentage_to_end ();


      if (a == txt_measu_length_set)        //określenie czasu trwania zapisu do pojedynczego pliku txt
      {
        sd_verification();      //sprawdzenie poprzedniego pliku txt, czy istnieje na karcie SD


        number_of_data = number_of_data + 1;        //zmienna opisująca numer pliku txt w danym pomiarze


        file_name = data_name + String(number_of_meas) + "_" + String(number_of_data) + ".txt";     //zmiana nazwy pliku podczas trwania danego pomiaru


        // obsługa ekranu
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print(data_name + String(number_of_meas) + "_" + String(number_of_data));
        lcd.setCursor(0, 1);
        lcd.print(String(file_size) + "KB " + String(i / (txt_measu_length_set / 2)) + "sp");   //wyświetlenie rozmiaru poprzedniego pliku txt oraz średniej ilości próbek na sekundę

        i = 0;    //reset (zmienna opisująca ilość próbek w jednym txt)
        a = 0;    //reset (zmienna zliczająca moment otwarcia kolejnego pliku txt przy danym pomiarze)

        lcd.setCursor(13, 1);
        lcd.print(String(avg_hr) + " ");
        lcd.setCursor(13, 0);
        lcd.print(String(int(percentage)) + "%");
        percentageSaved = percentage;
      }

      myFile = SD.open(file_name, FILE_WRITE);    //otwarcie kolejnego pliku txt podczas trwania danego pomiaru

      a = a + 1;    //zmienna zliczająca moment otwarcia kolejnego pliku txt przy danym pomiarze

    }

  }

  MEASUREMENT_time_out();      //zakończenie pomiaru po określonym upływie czasu

}
