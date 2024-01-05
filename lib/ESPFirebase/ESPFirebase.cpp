#include "ESPFirebase.hpp"
#include "addons/RTDBHelper.h"
#include "addons/TokenHelper.h"

ESPFirebase::ESPFirebase(const String &apiKey, const String &databaseUrl)
{
    _config.api_key = apiKey;
    _config.database_url = databaseUrl;
}

bool ESPFirebase::IsSignUp(void)
{
    return Firebase.signUp(&_config, &_auth, "", "");
}

bool ESPFirebase::IsSignUp(String email, String password)
{
    return Firebase.signUp(&_config, &_auth, email, password);
}

void ESPFirebase::InitializeFirebase(void)
{
    _config.token_status_callback = tokenStatusCallback;
    Firebase.begin(&_config, &_auth);
    Firebase.reconnectWiFi(true);
}

bool ESPFirebase::pushStringData(String &path, String &data)
{
    if (Firebase.RTDB.setString(&_fbdo, path, data))
    {
        return true;
    }
    else
    {
        Serial.println(_fbdo.errorReason());
        return false;
    }
}

bool ESPFirebase::readStringData(String &path, String &result)
{
    if (Firebase.RTDB.getString(&_fbdo, path))
    {
        result = _fbdo.to<String>();
        return true;
    }
    else
    {
        Serial.println(_fbdo.errorReason());
        return false;
    }
}

bool ESPFirebase::updateStringData(String &path, String &data)
{
    _json.set("stringValue", data);

    if (Firebase.RTDB.updateNode(&_fbdo, path, &_json))
    {
        return true;
    }
    else
    {
        Serial.println(_fbdo.errorReason());
        return false;
    }
}

bool ESPFirebase::deleteData(String &path)
{
    if (Firebase.RTDB.deleteNode(&_fbdo, path))
    {
        return true;
    }
    else
    {
        Serial.println(_fbdo.errorReason());
        return false;
    }
}