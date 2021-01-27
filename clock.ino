
void time_now_clk()
{
  timeNow = millis() /1000 ;
  seconds = timeNow - timeLast;

  if (seconds >= 60)
  {
    timeLast = timeNow;
    minutes = minutes + 1;
  }

  if (minutes == 60)
  {
    minutes = 0;
    hours = hours + 1;
  }

  if (hours == 24)
  {
    hours = 0;
    days = days + 1;
  }

  if (seconds < 10)
  {
     null_var_sec = "0";
  }

 else if (seconds >= 10)
  {
     null_var_sec = "";
  }

    if (minutes < 10)
  {
     null_var_min = "0";
  }

 else if (minutes >= 10)
  {
     null_var_min = "";
  }


  time_now = String(hours) + ":" + String(null_var_min) + String(minutes) + ":" + String(null_var_sec) + String(seconds);

}
