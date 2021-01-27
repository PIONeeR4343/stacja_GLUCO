void HR(long sensorValue)
{
  if (LV_gLED_sample < 300 && millis_time_now - millis_time_mem_4 >= 10UL)       //wstępna filtracja i zebranie danych
  {
    LV_gLED_sample += 1;
    millis_time_mem_4 = millis();
    data_high = (alpha_high * adcFilter.filter(sensorValue)) + ((1 - alpha_high) * data_high);

    meas_array[LV_gLED_sample] = data_high;
    time_array[LV_gLED_sample] = millis();
  }


  if (LV_gLED_sample == 300)
  {
    for (LV_checked_sample_inArray ; LV_checked_sample_inArray < 289; LV_checked_sample_inArray++)
    {
      if (meas_array[LV_checked_sample_inArray - 10] < meas_array[LV_checked_sample_inArray] && meas_array[LV_checked_sample_inArray - 9] < meas_array[LV_checked_sample_inArray] &&
          meas_array[LV_checked_sample_inArray - 8] < meas_array[LV_checked_sample_inArray] && meas_array[LV_checked_sample_inArray - 7] < meas_array[LV_checked_sample_inArray] &&
          meas_array[LV_checked_sample_inArray - 6] < meas_array[LV_checked_sample_inArray] && meas_array[LV_checked_sample_inArray + 10] < meas_array[LV_checked_sample_inArray] &&
          meas_array[LV_checked_sample_inArray + 9] < meas_array[LV_checked_sample_inArray] && meas_array[LV_checked_sample_inArray + 8] < meas_array[LV_checked_sample_inArray] &&
          meas_array[LV_checked_sample_inArray + 7] < meas_array[LV_checked_sample_inArray] && meas_array[LV_checked_sample_inArray + 6] < meas_array[LV_checked_sample_inArray])
      {
        LV_array_literation_forMAXpoints += 1;

        Array_Positions_MAX_points[LV_array_literation_forMAXpoints] = LV_checked_sample_inArray;
        LV_checked_sample_inArray += 11;
      }
    }

    if (LV_checked_sample_inArray >= 289 && LV_COMP_TtoMAXpoint < LV_array_literation_forMAXpoints && LV_array_literation_forMAXpoints >= 3)
    {
      LV_COMP_TtoMAXpoint += 1;

      int last_hr = hr;

      hr = (60000 / (time_array[Array_Positions_MAX_points[LV_COMP_TtoMAXpoint]] - time_array[Array_Positions_MAX_points[LV_COMP_TtoMAXpoint - 1]]));

      if ((hr >= last_hr * 1.15 || hr <= last_hr * 0.85) && last_hr != 0)
      {
        reset_hr_function();
      }

      hr_sum = hr_sum + hr;

      if (LV_COMP_TtoMAXpoint == LV_array_literation_forMAXpoints )
      {
        avg_hr = hr_sum / (LV_COMP_TtoMAXpoint - 1);

        if (avg_hr < 40 || avg_hr > 280)
        {
          reset_hr_function();
        }
        else
        {
          if (HR_meas == 1 && interface == 0)
          {
            lcd.setCursor(0, 0);
            lcd.print("   HEART RATE   ");
            lcd.setCursor(0, 1);
            lcd.print(String(avg_hr) + "bpm            ");
          }

          reset_hr_function();
        }
      }
    }

    else if (LV_array_literation_forMAXpoints <= 2)
    {
      reset_hr_function();
    }
  }
}

void reset_hr_function()
{
  hr = 0;
  hr_sum = 0;
  LV_gLED_sample = 0;
  LV_array_literation_forMAXpoints = 0;
  LV_COMP_TtoMAXpoint = 1;
  LV_checked_sample_inArray = 11;
}
