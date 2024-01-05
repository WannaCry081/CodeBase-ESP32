/**
 * @file ESPBlue.hpp
 * @brief ESPBlue class definition for managing Bluetooth functionality on ESP32.
 */

#ifndef ESPBLUE_HPP
#define ESPBLUE_HPP

#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEService.h>
#include <BLEUtils.h>

/**
 * @class SampleCallback
 * @brief A sample callback class for handling Bluetooth characteristic events.
 */
class SampleCallback : public BLECharacteristicCallbacks
{
public:
    /**
     * @brief Callback triggered when a central device writes to the characteristic.
     * @param pCharacteristic The BLE characteristic being written.
     */
    void onWrite(BLECharacteristic *pCharacteristic);

    /**
     * @brief Callback triggered when a central device reads the value of the characteristic.
     * @param pCharacteristic The BLE characteristic being read.
     */
    void onRead(BLECharacteristic *pCharacteristic);

    /**
     * @brief Callback triggered when a notification is sent from the characteristic.
     * @param pCharacteristic The BLE characteristic sending the notification.
     */
    void onNotify(BLECharacteristic *pCharacteristic);

    /**
     * @brief Callback triggered when there is a status change in the characteristic.
     * @param pCharacteristic The BLE characteristic with the status change.
     * @param s The status type.
     * @param code The status code.
     */
    void onStatus(BLECharacteristic *pCharacteristic, Status s, uint32_t code);

    /**
     * @brief Callback triggered when an indication is sent from the characteristic.
     * @param pCharacteristic The BLE characteristic sending the indication.
     */
    void onIndicate(BLECharacteristic *pCharacteristic);
};

/**
 * @class ESPBlue
 * @brief ESPBlue class for managing Bluetooth functionality on ESP32.
 */
class ESPBlue
{
private:
    BLECharacteristic *_pCharacteristic;
    String _serviceUUID;
    String _characteristicUUID;

public:
    /**
     * @brief Constructor for initializing ESPBlue with service and characteristic UUIDs.
     * @param serviceUUID The UUID of the Bluetooth service.
     * @param characteristicUUID The UUID of the Bluetooth characteristic.
     */
    ESPBlue(const String &serviceUUID, const String &characteristicUUID);

    /**
     * @brief Sets up the Bluetooth functionality.
     */
    void Setup(void);

    /**
     * @brief Sets the callbacks for the BLE characteristic.
     * @param callbacks The BLE characteristic callbacks.
     */
    void SetCallbacks(BLECharacteristicCallbacks *callbacks);
};

#endif
