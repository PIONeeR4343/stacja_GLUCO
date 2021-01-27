void menu()
{

  if (interface == 1)
  {
    
    switch (menu_gl) {

      case 1:
        lcd.setCursor(0, 0);
        lcd.print("START" "   " + time_now + "    ");       
        lcd.setCursor(0, 1);
        lcd.print("NEXT          OK");
        break;

        case 2:
        lcd.setCursor(0, 0);
        lcd.print("HEART RATE      ");       
        lcd.setCursor(0, 1);
        lcd.print("NEXT          OK");
        break;


      case 3:
        if (settings == 0)
        {
          lcd.setCursor(0, 0);
          lcd.print("SETTINGS         ");
          lcd.setCursor(0, 1);
          lcd.print("NEXT          OK");
        }

        if (settings == 1)
        {
          switch (menu_settings)
          {
            case 1:

              if (meas_lengh_menu == 0)
              {
                lcd.setCursor(0, 0);
                lcd.print("MEASUREMENT TIME");
                lcd.setCursor(0, 1);
                lcd.print("NEXT          OK");
              }

              if (meas_lengh_menu == 1)
              {
                lcd.setCursor(0, 0);
                lcd.print("Set measurement ");
                lcd.setCursor(0, 1);
                lcd.print("time: " + String(meas_leng_real) + "          ");
              }

              break;

            case 2:

              if (txt_measu_length_menu == 0)
              {
                lcd.setCursor(0, 0);
                lcd.print("TXT MEASU. LENGTH");
                lcd.setCursor(0, 1);
                lcd.print("NEXT          OK");
              }

              if (txt_measu_length_menu == 1)
              {
                lcd.setCursor(0, 0);
                lcd.print("Set txt measu. length");
                lcd.setCursor(0, 1);
                lcd.print("time: " + String(txt_measu_length_real) + "          ");
              }
              break;
          }
        }
        break;


      case 4:
        lcd.setCursor(0, 0);
        lcd.print("SD CARD TEST     ");
        lcd.setCursor(0, 1);
        lcd.print("NEXT          OK");
        break;



      case 5:
        if (graph_menu == 0)
        {
          lcd.setCursor(0, 0);
          lcd.print("GRAPH            ");
          lcd.setCursor(0, 1);
          lcd.print("NEXT          OK");
        }
        if (graph_menu == 1)
        {
          graph();
        }

        break;

      case 6:
        lcd.setCursor(0, 0);
        lcd.print("RESTART         ");
        lcd.setCursor(0, 1);
        lcd.print("NEXT          OK");
        break;

      case 7:
        if (update_ota == 0)
        {
          lcd.setCursor(0, 0);
          lcd.print("UPDATE         ");
          lcd.setCursor(0, 1);
          lcd.print("NEXT          OK");
        }
        if (update_ota == 1)
        {
          lcd.setCursor(0, 0);
          lcd.print(" WAITING FOR PC ");
          lcd.setCursor(0, 1);
          lcd.print(WiFi.localIP());
          lcd.print("    ");
          ArduinoOTA.handle();
        }
        break;


      default:
        break;
    }
  }
}
