#include <WiFi.h>

#define AP_SSID "Fish-Pond"
#define AP_PASS "12345678"
#define HOSTNAME "fishpond"

void setupAP(){
   WiFi.mode(WIFI_MODE_APSTA);
   WiFi.hostname(HOSTNAME);
   WiFi.softAP(AP_SSID, AP_PASS);
}
