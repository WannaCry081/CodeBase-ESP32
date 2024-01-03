#ifndef ESPFIREBASE_HPP
#define ESPFIREBASE_HPP

#include <Arduino.h>
#include <Firebase_ESP_Client.h>

class ESPFirebase
{
private:
    FirebaseData _fbdo;
    FirebaseAuth _auth;
    FirebaseConfig _config;
    FirebaseJson _json;

public:
    ESPFirebase(const String &apiKey, const String &databaseUrl);
    bool IsSignUp(void);
    bool IsSignUp(String email, String password);
    void InitializeFirebase(void);

    bool pushStringData(String &path, String &data);
    bool readStringData(String &path, String &result);
    bool updateStringData(String &path, String &data);
    bool deleteData(String &path);
};

#endif