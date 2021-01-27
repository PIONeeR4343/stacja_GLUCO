void wifi_NTP_init()
{
  WiFi.begin(ssid, password);

  wifi_connect();
  timeClient.begin();

  for (int i = 0; i < 100; i++)
  {
    timeClient.update();
  }

  get_hours_UDP = timeClient.getHours();
  get_minutes_UDP = timeClient.getMinutes();

  minutes = get_minutes_UDP;
  hours = get_hours_UDP;

}


void wifi_connect()
{
  connecting();

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("CONNECTED");
  lcd.setCursor(0, 1);
  lcd.print(WiFi.localIP());
  delay(2000);
}

void connecting()
{
  while ( WiFi.status() != WL_CONNECTED )
  {

    delay (500);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("WiFi connecting:");
    lcd.setCursor(0, 1);
    lcd.print(String(ssid));
  }

}
