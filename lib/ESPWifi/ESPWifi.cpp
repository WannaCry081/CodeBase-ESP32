#include "ESPWifi.hpp"

ESPWifi::ESPWifi(const String &ssid, const String &password) : _ssid(ssid), _password(password)
{   
    WiFi.begin(ssid, password);
}

bool ESPWifi::IsConnect()   
{
    return WiFi.status() == WL_CONNECTED;
}

bool ESPWifi::IsSuccess()
{
    return _counter++ < 20;
}

void ESPWifi::DisplayStatus(){
    Serial.println(WiFi.localIP());
    Serial.println(WiFi.localIPv6());
}