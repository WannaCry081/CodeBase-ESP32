#include "ESPWifi.hpp"

ESPWifi::ESPWifi(const String &ssid, const String &password)
{
    WiFi.begin(ssid, password);
}

bool ESPWifi::IsConnected(void)
{
    return WiFi.status() == WL_CONNECTED;
}
 
bool ESPWifi::IsSuccess(void)
{
    return _counter++ < 20;
}

void ESPWifi::DisplayStatus()
{
    const String SSID = WiFi.SSID(void);
    
    Serial.println("---------------------");
    switch (WiFi.status()){
        case WL_CONNECTED:
            Serial.printf("ESP32 is Connected to %s.\n", SSID);
            break;

        case WL_CONNECT_FAILED:
            Serial.printf("ESP32 Failed to Connect to %s.\n", SSID);
            break;

        case WL_CONNECTION_LOST:
            Serial.printf("ESP32 Lost Connection to %s.\n", SSID);
            break;

        case WL_DISCONNECTED:
            Serial.printf("ESP32 Disconnected to %s.\n", SSID);
            break;
    }

    Serial.printf("IPV4 of %s: %s\n", SSID, WiFi.localIP());
    Serial.printf("IPV6 of %s: %s\n", SSID, WiFi.localIPv6());
    Serial.println("---------------------");
}