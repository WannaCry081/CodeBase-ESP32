#include <Arduino.h>
#include <ESPWifi.hpp>
#include <ESPFirebase.hpp>
// #include <ESPBlue.hpp>

// const String SERVICE_UUID = "4fafc201-1fb5-459e-8fcc-c5c9c331914b";
// const String CHARACTERISTIC_UUID = "beb5483e-36e1-4688-b7f5-ea07361b26a8";

const String WIFI_SSID = "Pagstudyna";
const String WIFI_PASSWORD = "Data2Santi";

const String API_KEY = "AIzaSyApj_PWjGm_aEsZmICo-SmOxyRGpUUy-qk";
const String DATABASE_URL = "https://thermospectra-default-rtdb.firebaseio.com/";

// ESPBlue bluetooth(SERVICE_UUID, CHARACTERISTIC_UUID);
ESPFirebase firebase(API_KEY, DATABASE_URL);

void setup()
{
  Serial.begin(115200);

  ESPWifi wifi(WIFI_SSID, WIFI_PASSWORD);
  // bluetooth.setup();
  
  Serial.printf("Connecting to %s...", WIFI_SSID);
  while (!wifi.IsConnected())
  {
    Serial.print(".");
    delay(1000);

    if (!wifi.IsSuccess())
    {
      Serial.printf("\nError! Failed to Connect to%s.\n", WIFI_SSID);
    }
  }

  if (wifi.IsConnected())
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
    // Code Here
  }
}