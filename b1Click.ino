void b1Click()
{
  if (settings == 0 && interface == 1 && graph_menu == 0 ) // poruszanie się po głównym menu
  {
    menu_gl = menu_gl + 1;

    if (menu_gl == 8)
    {
      menu_gl = 1;
    }
  }

  if ( settings == 1 && menu_gl == 3 && meas_lengh_menu == 0) // poruszanie się po menu_ settings
  {
    menu_settings =  menu_settings + 1;

    if (menu_settings == 3)
    {
      menu_settings = 1;

    }
  }

  if ( settings == 1 && menu_gl == 3 && meas_lengh_menu == 1) //powrót do menu_settings z meas_lengh_menu
  {
    menu_settings = 1;
    meas_lengh_menu = 0;
  }

  if ( settings == 1 && menu_gl == 3 && txt_measu_length_menu == 1) //powrót do menu_settings z txt_measu_length_menu
  {
    menu_settings = 1;
    txt_measu_length_menu = 0;
  }

  if (settings == 0 && interface == 1 && graph_menu == 1) // poruszanie się po menu wykresy
  {
    graph_menu_number = graph_menu_number + 1;

    if (graph_menu_number == 7)
    {
      graph_menu_number = 1;
    }
  }



}

void b1Hold()
{
  if (interface == 1)     //powrót na start
  {
    menu_gl = 1;
    menu_settings = 1;
    settings = 0;
    txt_measu_length_menu = 0;
    meas_lengh_menu = 0;
    graph_menu = 0;
    update_ota = 0;
    HR_meas = 0;

    TCA9548A(0);
    AFE_GROUPled.off();
    TCA9548A(1);
    AFE_IRled.off();
  }



  if (interface == 0 && start_meas == true)   // wyłączenie pomiaru przyciskiem
  {
    myFile.close();
    sd_verification();

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("END");
    lcd.setCursor(0, 1);
    lcd.print("END");
    delay(1000);
    
    TCA9548A(0);
    AFE_GROUPled.off();
    TCA9548A(1);
    AFE_IRled.off();


    start_meas = false;
    interface = 1;
    start_open_file = true;
    i = 0;
    a = 0;
    number_of_data = 0;
  }

  if (HR_meas == 1)     //powrót na start
  {
    interface = 1;
    menu_gl = 1;
    menu_settings = 1;
    settings = 0;
    txt_measu_length_menu = 0;
    meas_lengh_menu = 0;
    graph_menu = 0;
    update_ota = 0;
    HR_meas = 0;

    TCA9548A(0);
    AFE_GROUPled.off();
    TCA9548A(1);
    AFE_IRled.off();
  }

}
