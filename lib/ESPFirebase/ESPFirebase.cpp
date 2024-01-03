#include "ESPFirebase.hpp"
#include "addons/RTDBHelper.h"
#include "addons/TokenHelper.h"

ESPFirebase::ESPFirebase(const String &apiKey, const String &databaseUrl) {
    _config.api_key = apiKey;
    _config.database_url = databaseUrl;
}

bool ESPFirebase::IsSignUp(void) {
    return Firebase.signUp(&_config, &_auth, "", "");
}

bool ESPFirebase::IsSignUp(String email, String password) {
    return Firebase.signUp(&_config, &_auth, email, password);
}

void ESPFirebase::InitializeFirebase(void) {
    _config.token_status_callback = tokenStatusCallback;
    Firebase.begin(&_config, &_auth);
    Firebase.reconnectWiFi(true);
}
