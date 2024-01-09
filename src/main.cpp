#include <Arduino.h>
#include <ESPWifi.hpp>
#include <ESPFirebase.hpp>
// #include <ESPBlue.hpp>

// const String SERVICE_UUID = "UNIQUE-GUID";
// const String CHARACTERISTIC_UUID = "UNIQUE-GUID";

const String WIFI_SSID = "WIFI-SSID";
const String WIFI_PASSWORD = "WIFI-PASSWORD";

const String API_KEY = "FIREBASE-API-KEY";
const String DATABASE_URL = "FIREBASE-RDMS-DATABASE-URL";

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