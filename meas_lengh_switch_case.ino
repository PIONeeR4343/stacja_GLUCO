 void meas_lengh_switch_case () {  //sterowanie dlugoscią pomiaru


      switch (meas_lengh)
      {
        case 1 :
          meas_lengh_set = 10000UL;
          meas_leng_real = "10 sec           ";
          percentage_variable = 10;
          percentage_variable_map = percentage_variable;
          break;

        case 2 :
          meas_lengh_set = 30000UL;
          meas_leng_real = "30 sec          ";
          percentage_variable = 30;
          percentage_variable_map = percentage_variable;
          break;

        case 3 :
          meas_lengh_set = 60000UL;
          meas_leng_real = "1 min         ";
          percentage_variable = 60;
          percentage_variable_map = percentage_variable;
          break;

        case 4 :
          meas_lengh_set = 300000UL;
          meas_leng_real = "5 min          ";
          percentage_variable = 300;
          percentage_variable_map = percentage_variable;
          break;

        case 5 :
          meas_lengh_set = 600000UL;
          meas_leng_real = "10 min          ";
          percentage_variable = 600;
          percentage_variable_map = percentage_variable;
          break;

        case 6 :
          meas_lengh_set = 1800000UL;
          meas_leng_real = "30 min         ";
          percentage_variable = 1800;
          percentage_variable_map = percentage_variable;
          break;

        case 7 :
          meas_lengh_set = 3600000UL;
          meas_leng_real = "1 hour          ";
          percentage_variable = 3600;
          percentage_variable_map = percentage_variable;
          break;

        case 8 :
          meas_lengh_set = 7200000UL;
          meas_leng_real = "2 hour          ";
          percentage_variable = 7200;
          percentage_variable_map = percentage_variable;
          break;

        case 9 :
          meas_lengh_set = 14400000UL;
          meas_leng_real = "4 hour         ";
          percentage_variable = 14400;
          percentage_variable_map = percentage_variable;
          break;
      }
    }
