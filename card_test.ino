void card_init()
{
  lcd.clear();
  
  while (!SD.begin(CS))   //inicjalizacja karty SD
  {
    lcd.setCursor(0, 0);
    lcd.print("INSERT CARD");   //komunikat gdy nie ma karty podczas uruchomienia urządzenia
    delay(100);
  }
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("");
  delay(2000);
}


void card_test()
{
  file_name = "TEST.txt";     //testowanie zapisu do karty pamieci - ustawienie nazwy pliku

  card_init();

  

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("TESTING...");
  lcd.setCursor(0, 1);
  lcd.print("Writing TEST.txt");


  myFile = SD.open("TEST.txt", FILE_WRITE);   //otwarcie pliku txt
  myFile.println("ABCD;0123456789");          //zapis danych do pliku txt
  myFile.close();                             //zamkniecie i weyfikacja pliku

  delay(3000);

  lcd.clear();

  sd_verification();                          //sprawdzenie czy plik istnieje na karcie sd

  lcd.clear();

  myFile = SD.open("TEST.txt");             //odczyt zapisanych danych na karcie SD + wyświetlenie ich na ekranie
  if (myFile) {
    while (myFile.available())
    {
      cr = myFile.read();
      if ((cr == '\r') || (cr == '\n'))
        break;
      lcd.print(cr);
    }
    myFile.close();             //zamkniecie i weyfikacja pliku
    lcd.setCursor(0, 1);
    lcd.print("Time:" + String(time_now));       //sprawdzenie zegaru rzeczywistego 
  }

  delay(3000);

  sd_verification();            //ponowne sprawdzenie czy plik istnieje na karcie sd

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Deleting a file:");
  lcd.setCursor(0, 1);
  lcd.print("TEST.txt");

  SD.remove("TEST.txt");        //usuniecie pliku TEST.txt z karty SD

  delay(3000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Ending testing");

  delay(3000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("OK");
  file_name = "";     //"zerowanie" nazwy pliku

  delay(1000);

  if (menu_gl == 3)       //powrót do menu
  {
    lcd.setCursor(0, 0);
    lcd.print("SD CARD TEST     ");
    lcd.setCursor(0, 1);
    lcd.print("NEXT          OK");
  }

  get_hours_UDP = timeClient.getHours();
  get_minutes_UDP = timeClient.getMinutes();

  minutes = get_minutes_UDP;
  hours = get_hours_UDP;

  timeLast = timeNow;

  

}
