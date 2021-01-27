void b2Click()
{
  if (settings == 1 && menu_gl == 3 && menu_settings == 1)  //wejscie w meas_lengh_menu
  {
    meas_lengh_menu = 1;
  }

  if (settings == 0 && menu_gl == 5)  //wejscie w wykresy
  {
    graph_menu = 1;
    TCA9548A(1);
    AFE_IRled.initFIRST();
  }

  if (settings == 1 && menu_gl == 3 && menu_settings == 2)  //wejscie w Time_write_menu
  {
    txt_measu_length_menu = 1;
  }

  if (menu_gl == 3)  // wejście w menu_settings
  {
    settings = 1;
  }

  if (menu_gl == 7)  // wejście w aktualizację
  {
    update_ota = 1;
  }

  if (settings == 1 && menu_gl == 3 && menu_settings == 1 && meas_lengh_menu == 1) //zmiana wartości w meas_lengh_menu
  {
    meas_lengh = meas_lengh + 1;
    if (meas_lengh == 10)
    {
      meas_lengh = 1;
    }
    meas_lengh_switch_case ();
  }

  if (settings == 1 && menu_gl == 3 && menu_settings == 2 && txt_measu_length_menu == 1) //zmiana wartości w Time_write_menu
  {
    txt_measu_length = txt_measu_length + 1;
    if (txt_measu_length == 7)
    {
      txt_measu_length = 1;
    }
    txt_measu_length_switch_case();
  }

  if (menu_gl == 1 && interface == 1)  // wejście w pomiar
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("MEAS t: " + String(meas_leng_real));
    lcd.setCursor(0, 1);
    lcd.print("TXT t: " + String(txt_measu_length_real));

    delay(4000);

    interface = 0 ;
    start_meas = true;
    millis_time_now = millis();
    millis_time_mem_3 = meas_lengh_set + millis_time_now;

  }

  if (menu_gl == 2 && interface == 1)  // wejście w HR
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("   HEART RATE   ");
    lcd.setCursor(0, 1);
    lcd.print("    MEASUREMENT  ");

    delay(2000);

    interface = 0 ;
    HR_meas = 1;

    TCA9548A(0);
    AFE_GROUPled.initSECOND();
    TCA9548A(1);
    AFE_IRled.initFIRST();

   

  }

  if ( start_meas == true && start_open_file == false)
  {
    znacznik = "MARKER";
  }


  if (menu_gl == 6)  // restart
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("RESTARTING......");
    lcd.setCursor(0, 1);
    lcd.print(":(   :(   :(");
    delay(2000);
    ESP.restart();
  }


  if (menu_gl == 4)  //
  {
    card_test();
  }

}
