void txt_measu_length_switch_case()   //sterowanie czasem zapisu do jednego pliku txt
    {
      switch (txt_measu_length)
      {
        case 1 :
          txt_measu_length_set = 20;
          txt_measu_length_real = "10 sec           ";
          break;

        case 2 :
          txt_measu_length_set = 60;
          txt_measu_length_real = "30 sec          ";
          break;

        case 3 :
          txt_measu_length_set = 120;
          txt_measu_length_real = "1 min         ";
          break;

        case 4 :
          txt_measu_length_set = 600;
          txt_measu_length_real = "5 min          ";
          break;

        case 5 :
          txt_measu_length_set = 1200;
          txt_measu_length_real = "10 min          ";
          break;

        case 6 :
          txt_measu_length_set = 3600;
          txt_measu_length_real = "30 min         ";
          break;
      }
    }
