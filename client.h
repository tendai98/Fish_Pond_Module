
#include <WiFi.h>
#include <FirebaseESP32.h>
#include "addons/TokenHelper.h"
#include "addons/RTDBHelper.h"

#define WIFI_SSID "Tinkertech"
#define WIFI_PASSWORD "1234567890"
#define API_KEY "AIzaSyAo7WcUIbCl5ZzvizcgW-80wEDVfMRxiEA"
#define DATABASE_URL "https://pond-controller-default-rtdb.firebaseio.com/" 
#define USER_EMAIL "controller@system.net"
#define USER_PASSWORD "1234567890"

FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;
String dataValues;

unsigned long sendDataPrevMillis = 0;

void setupClient()
{


  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(300);
  }
  config.api_key = API_KEY;
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;
  config.database_url = DATABASE_URL;
  config.token_status_callback = tokenStatusCallback;
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
  Firebase.setDoubleDigits(5);
  Serial.begin(115200);
  Firebase.setInt(fbdo, "/ipv", 0);
  Firebase.setInt(fbdo, "/opv", 0);
  Firebase.setInt(fbdo, "/override", 0);
}


void getData(){
  dataValues = String(getPh())+":";
  dataValues += String(getTemperature())+":"+String(manualOverride)+":";
  dataValues += String(ipvValveState)+":"+String(ipvValveState)+":";
  dataValues += String(getDistance());
}

void sendValues()
{
  if (Firebase.ready() && (millis() - sendDataPrevMillis > 2000 || sendDataPrevMillis == 0))
  {
    sendDataPrevMillis = millis();
    getData();
    Firebase.setString(fbdo, "/systemData", dataValues);
    Firebase.setString(fbdo, "/systemDataLog/"+String(millis()), dataValues);
  }
}
