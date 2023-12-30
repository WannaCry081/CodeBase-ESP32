#ifndef ESPBLUE_HPP
#define ESPBLUE_HPP

#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEService.h>
#include <BLEUtils.h>

class ESPBlue
{
private:
    BLECharacteristic *_pCharacteristic;
    String _serviceUUID;
    String _characteristicUUID;

    class MyCallbacks : public BLECharacteristicCallbacks
    {
        void onWrite(BLECharacteristic *pCharacteristic);
    };

public:
    ESPBlue(const String &serviceUUID, const String &characteristicUUID);
    void setup();
    void loop();
};

#endif
