void percentage_to_end ()
{
  percentage_variable = percentage_variable  -  0.5;      
  
  percentage = map( percentage_variable,percentage_variable_map, 1, 0, 100);

  if(percentage != percentageSaved)
  {
  lcd.setCursor(13, 1);
  lcd.print(String(avg_hr) + " ");
  lcd.setCursor(13, 0);
  lcd.print(String(int(percentage)) + "%");
  percentageSaved = percentage;
  }
}
