#include <Arduino.h>
#include <ESPWifi.hpp>

// Bluetooth Setup
// #include <ESPBlue.hpp>
// const String SERVICE_UUID = "4fafc201-1fb5-459e-8fcc-c5c9c331914b";
// const String CHARACTERISTIC_UUID = "beb5483e-36e1-4688-b7f5-ea07361b26a8";
// ESPBlue bluetooth(SERVICE_UUID, CHARACTERISTIC_UUID);

const String WIFI_SSID = "Testing";
const String WIFI_PASSWORD = "12345678";


void setup(){
  Serial.begin(115200);

  // Bluetooth Setup
  // bluetooth.setup();

  ESPWifi wifi(WIFI_SSID, WIFI_PASSWORD);

  Serial.print("Connecting to Wifi");
  while (!wifi.IsConnect()) {

    Serial.print(".");
    if (!wifi.IsSuccess()) {
      Serial.println("Error! Failed to Connect Wifi.");
      break;
    }
  }

  if (wifi.IsConnect()){
    Serial.println("Successfully connect to " + WIFI_SSID);
  }

  
}

void loop(){

}