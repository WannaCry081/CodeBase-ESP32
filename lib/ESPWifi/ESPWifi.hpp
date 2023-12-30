#include <Arduino.h>
#include <WiFi.h>
#include <Update.h>
#include <LittleFS.h>
#include <SD.h>
#ifndef ESPWIFI_HPP
#define ESPWIFI_HPP

class ESPWifi
{
private:
    String _ssid;
    String _password;
    int _counter;

public:
    ESPWifi(String &ssid, String &password);
    bool IsConnect();
    bool IsSuccess();
};

#endif