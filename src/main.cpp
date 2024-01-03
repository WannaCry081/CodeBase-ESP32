#include <Arduino.h>
#include <ESPWifi.hpp>

const String WIFI_SSID = "Pagstudyna";
const String WIFI_PASSWORD = "Data2Santi";

void setup()
{
  Serial.begin(115200);

  ESPWifi wifi(WIFI_SSID, WIFI_PASSWORD);

  Serial.printf("Connecting to %s...", WIFI_SSID);
  while (!wifi.IsConnect()) {
    Serial.print(".");
    delay(1000);

    if (!wifi.IsSuccess()){
      Serial.printf("\nError! Failed to Connect to%s.\n",  WIFI_SSID);
    }
  }

  if (wifi.IsConnect()){
    Serial.printf("\nSuccessfully Connected to %s\n", WIFI_SSID);
    wifi.DisplayStatus();
  }

}

void loop()
{

}