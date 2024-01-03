#include <Arduino.h>
#include <ESPWifi.hpp>
#include <ESPFirebase.hpp>

const String WIFI_SSID = "Pagstudyna";
const String WIFI_PASSWORD = "Data2Santi";

const String API_KEY = "AIzaSyApj_PWjGm_aEsZmICo-SmOxyRGpUUy-qk";
const String DATABASE_URL = "https://thermospectra-default-rtdb.firebaseio.com/";

ESPFirebase firebase(API_KEY, DATABASE_URL);

void setup()
{
  Serial.begin(115200);

  ESPWifi wifi(WIFI_SSID, WIFI_PASSWORD);

  Serial.printf("Connecting to %s...", WIFI_SSID);
  while (!wifi.IsConnect())
  {
    Serial.print(".");
    delay(1000);

    if (!wifi.IsSuccess())
    {
      Serial.printf("\nError! Failed to Connect to%s.\n", WIFI_SSID);
    }
  }

  if (wifi.IsConnect())
  {
    Serial.printf("\nSuccessfully Connected to %s\n", WIFI_SSID);
    wifi.DisplayStatus();
  }

  if (firebase.IsSignUp())
  {
    Serial.println("Successfully Connected to Firebase.");
    firebase.InitializeFirebase();
  }
  else
  {
    Serial.println("Failed to Connect to Firebase");
  }
}

void loop()
{
  if (Firebase.ready())
  {
    Serial.println("Hello World");
    delay(1000);
  }
}