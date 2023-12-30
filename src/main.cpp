#include <Arduino.h>
#include <ESPWifi.hpp>

String ssid = "Testing";
String password = "12345678";

void setup(){
  Serial.begin(115200);

  ESPWifi wifi(ssid, password);

  Serial.print("Connecting to Wifi");
  while (!wifi.IsConnect()) {

    Serial.print(".");
    if (!wifi.IsSuccess()) {
      Serial.println("Error! Failed to Connect Wifi.");
      break;
    }
  }

  if (wifi.IsConnect()){
    Serial.println("Successfully connect to " + ssid);
  }
}

void loop(){

}