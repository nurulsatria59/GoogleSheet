#include "TRIGGER_WIFI.h"               
#include "TRIGGER_GOOGLESHEETS.h"      
#include "DHT.h"
#define DHTTYPE DHT11
#define dht_pin D4

DHT dht(dht_pin, DHTTYPE);

char column_name_in_sheets[ ][20] = {"value1","value2"};
String Sheets_GAS_ID = "AKfycbyuQZOUDAcMtY78-VAaXdT_Ow7NliJ3qxO0g4G0SfwukvmA6vOi5kTRH3j2WUeNbuCENg";
int No_of_Parameters = 2;

void setup() 
{
  Serial.begin(9600);
  while (!Serial);
  dht.begin();

  WIFI_Connect("Nurul Satria","urisarang4");
  Google_Sheets_Init(column_name_in_sheets, Sheets_GAS_ID, No_of_Parameters );
}

void loop() 
{
  float s = dht.readTemperature();
  float h = dht.readHumidity();                          

  Data_to_Sheets(No_of_Parameters,  s,  h);

  Serial.println();
  delay(5000);
}
