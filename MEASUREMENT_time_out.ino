void MEASUREMENT_time_out ()
{

  if (millis_time_now > millis_time_mem_3)    //jesli czas zdeklarowany przez użytkownika jest mniejszy od aktualnego, to konczony jest pomiar
  {
    myFile.close();       //zamkniecie i weryfikacja aktualnie otwartego pliku

    sd_verification();    // werifikacja czy poprzedni plik istnieje na karcie

    start_meas = false;    //wyłączenie zmiennej odpowiedzialnej za pomiar
    interface = 1;        //włączenie menu
    start_open_file = true;    //włączenie zmiennej odpowiedzialnej za tworzenie nowego pomiaru (measurement_start)

    //obsługa wyśiwtlacza
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("END");
    lcd.setCursor(0, 1);
    lcd.print("END");

    i = 0;    //reset (zmienna opisująca ilość próbek w jednym txt)
    a = 0;    //reset (zmienna zliczająca moment otwarcia kolejnego pliku txt przy danym pomiarze)



    number_of_data = 0;       //reset (zmienna opisująca numer pliku txt w danym pomiarze)

    TCA9548A(0);
    AFE_GROUPled.off();
    TCA9548A(1);
    AFE_IRled.off();

    delay(1000);
  }
}
