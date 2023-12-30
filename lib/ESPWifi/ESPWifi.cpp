#include "ESPWifi.hpp"

ESPWifi::ESPWifi(const String &ssid, const String &password) : _ssid(ssid), _password(password)
{   
    WiFi.begin(_ssid, _password);
}

bool ESPWifi::IsConnect()
{
    return WiFi.status() != WL_CONNECTED;
}

bool ESPWifi::IsSuccess()
{
    return _counter++ < 20;
}