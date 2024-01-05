#ifndef ESPFIREBASE_HPP
#define ESPFIREBASE_HPP

#include <Arduino.h>
#include <Firebase_ESP_Client.h>

/**
 * @class ESPFirebase
 * @brief A class for interfacing with the Firebase Realtime Database on ESP32 using the Firebase Arduino library.
 */
class ESPFirebase
{
private:
    FirebaseData _fbdo;     ///< Firebase data object for managing communication with Firebase.
    FirebaseAuth _auth;      ///< Firebase authentication object for managing user authentication.
    FirebaseConfig _config;  ///< Firebase configuration object for storing API key and database URL.
    FirebaseJson _json;      ///< Firebase JSON object for handling JSON data.

public:
    /**
     * @brief Constructor for initializing ESPFirebase with API key and database URL.
     * @param apiKey The Firebase project API key.
     * @param databaseUrl The URL of the Firebase Realtime Database.
     */
    ESPFirebase(const String &apiKey, const String &databaseUrl);

    /**
     * @brief Checks if a user is signed up.
     * @return true if a user is signed up, false otherwise.
     */
    bool IsSignUp(void);

    /**
     * @brief Checks if a user is signed up with a specific email and password.
     * @param email The user's email.
     * @param password The user's password.
     * @return true if the user is signed up, false otherwise.
     */
    bool IsSignUp(String email, String password);

    /**
     * @brief Initializes the Firebase configuration and authentication.
     */
    void InitializeFirebase(void);

    /**
     * @brief Pushes string data to the specified path in the Firebase Realtime Database.
     * @param path The path in the database.
     * @param data The string data to be pushed.
     * @return true if the data is successfully pushed, false otherwise.
     */
    bool pushStringData(String &path, String &data);

    /**
     * @brief Reads string data from the specified path in the Firebase Realtime Database.
     * @param path The path in the database.
     * @param result The variable to store the read string data.
     * @return true if the data is successfully read, false otherwise.
     */
    bool readStringData(String &path, String &result);

    /**
     * @brief Updates string data at the specified path in the Firebase Realtime Database.
     * @param path The path in the database.
     * @param data The string data to be updated.
     * @return true if the data is successfully updated, false otherwise.
     */
    bool updateStringData(String &path, String &data);

    /**
     * @brief Deletes data at the specified path in the Firebase Realtime Database.
     * @param path The path in the database.
     * @return true if the data is successfully deleted, false otherwise.
     */
    bool deleteData(String &path);
};

#endif // ESPFIREBASE_HPP
