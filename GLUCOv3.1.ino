#include <AFE_connect.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <AnalogButtons.h>
#include <SPI.h>
#include <SD.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "NTPClient.h"
#include "ESP8266WiFi.h"
#include "WiFiUdp.h"
#include <ArduinoOTA.h>
#include "user_interface.h"
#include <Ewma.h>

#define CS 15
#define ANALOG_PIN A0
#define AnalogMux D3 //D3

Ewma adcFilter(0.01);

const char *ssid = "5G_internet";
const char *password = "xiaomiint";
const char* host_ota = "Gluco";
const char* password_ota = "esp8266";

const long utcOffsetInSeconds = 3600;  //2x60x60

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);

Button b1 = Button(524, &b1Click, &b1Hold);
Button b2 = Button(0, &b2Click);

AFE AFE_IRled;
AFE AFE_GROUPled;

File myFile;

LiquidCrystal_I2C lcd(0x27, 16, 2);

AnalogButtons analogButtons(ANALOG_PIN, INPUT);

signed long SensorValue = 0;
signed long SensorValue_2 = 0;
long sensorFingerDetect = 0;
int GSR = 0;

unsigned long HR_time;
unsigned long millis_time_now = 0;
unsigned long millis_time_mem_2 = 0;
unsigned long millis_time_mem_4 = 0;
unsigned long millis_time_mem_1 = 0;
unsigned long millis_time_mem_3 = 0;

unsigned long meas_lengh_set = 60000UL;
String time_now;
int mseconds = 0;
int seconds = 0;
int minutes = 0;
int hours = 12;
int days = 0;
int get_hours_UDP;
int get_minutes_UDP;
unsigned long timeNow = 0;
unsigned long timeLast = 0;
String null_var_sec ;
String null_var_min ;

long number_of_data = 0;
long number_of_meas = 0;
long i = 0;
long a = 0;
char cr;
bool start_meas = false;
bool start_open_file = true;

String data = "";
String data_name = "D_";
String file_name = "TEST.txt";
signed long file_size = 0;

int interface = 1;
int menu_gl = 1;
int menu_settings = 1;
int set_butt = 0;
int settings = 0;
int meas_lengh_menu = 0;
int graph_menu = 0;
int graph_menu_number = 1;
int update_ota = 0;
int meas_lengh = 3;
int txt_measu_length_menu = 0;
int txt_measu_length = 4;
int txt_measu_length_set = 600;
int HR_meas = 0;
String meas_leng_real = "1 min";
String txt_measu_length_real = "5 min";
String znacznik = "--";

double percentage = 0;
double percentage_variable = 60;
double percentage_variable_map = 60;
int percentageSaved = 0;

float alpha_high = 0.4;                       //częstotliwość odcięcia
long data_high;                               //Filtr GP
long meas_array[300];                         //tablica zawierająca próbki z diody zielonej
long time_array[300];                         //tablica z zapisanym czasem [ms] do próbek
int Array_Positions_MAX_points[30];           //tablica przechowująca numery próbek zawierające wartość MAX
int hr;                                       //obliczone tętno
int avg_hr;                                   //średnia wartość z ilości próbek
int hr_sum;

int LV_gLED_sample = 0;                       //zmienna służąca do zapisu danych w tablicy
int LV_checked_sample_inArray = 11;           //zmienna służąca do literacji po tablicy w celu znalezienia punktów MAX
int LV_array_literation_forMAXpoints = 0;     //zmienna służąca do dodawania punktów określających wartość MAX do tablicy
int LV_COMP_TtoMAXpoint = 1;                  //zmienna służaca do znajdowania w tablicy czasu wartości odpowiadających punktom MAX



void setup()
{
  pinMode(AnalogMux, OUTPUT);

  wifi_set_phy_mode(PHY_MODE_11B); //tryb 802.11B
  WiFi.setOutputPower(20.5); // moc nadajnika

  Serial.begin(115200);


  analogButtons.add(b1);
  analogButtons.add(b2);

  Wire.begin();
  TCA9548A(0);
  AFE_GROUPled.off();
  TCA9548A(1);
  AFE_IRled.off();
  lcd.begin();
  lcd.home();


  lcd.clear();

  wifi_NTP_init();

  card_init();

  ArduinoOTA.setHostname(host_ota);
  ArduinoOTA.setPassword(password_ota);
  OTA_setup();
  ArduinoOTA.begin();
}

void loop()
{

  digitalWrite(AnalogMux, LOW); //Button Read
  analogButtons.check();
  digitalWrite(AnalogMux, HIGH); //GSR Read
  menu();

  time_now_clk();
  MEASUREMENT_start();

  if (HR_meas == 1 && interface == 0)
  {
    HR(AFE_GROUPled.get_led1_val());
  }

  millis_time_now = millis();

}
