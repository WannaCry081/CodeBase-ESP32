#ifndef ESPWIFI_HPP
#define ESPWIFI_HPP

#include <Arduino.h>
#include <SD.h>
#include <WiFi.h>
#include <Update.h>
#include <LittleFS.h>

class ESPWifi
{
private:
    short int _counter;     // Connection attempt counter

public:
    /**
     * @brief Constructor for ESPWifi class.
     * 
     * @param ssid The WiFi SSID to connect to.
     * @param password The password for the WiFi network.
     */
    ESPWifi(const String &ssid, const String &password);

    /**
     * @brief Checks if the ESP is connected to the WiFi network.
     * 
     * @return True if connected, false otherwise.
     */
    bool IsConnected(void);

    /**
     * @brief Checks if the last WiFi connection attempt was successful.
     * 
     * @return True if successful, false otherwise.
     */
    bool IsSuccess(void);

    /**
     * @brief Displays the current WiFi connection status.
     */
    void DisplayStatus(void);
};

#endif
