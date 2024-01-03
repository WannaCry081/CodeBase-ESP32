#ifndef ESPFIREBASE_HPP
#define ESPFIREBASE_HPP

#include <Arduino.h>
#include <Firebase_ESP_Client.h>

class ESPFirebase {
    private:
        FirebaseData _fbdo;
        FirebaseAuth _auth;
        FirebaseConfig _config;

    public:
        ESPFirebase(const String &apiKey, const String &databaseUrl);
        bool IsSignUp(void);
        bool IsSignUp(String email, String password);
        void InitializeFirebase(void);
};


#endif