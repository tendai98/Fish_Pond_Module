#include <WiFi.h>
#include <HTTPClient.h>
#include "sonar.h"

#define AP_SSID "Pond-0001"
#define AP_PASS "12345678"
#define HOST "192.168.4.1"

HTTPClient http;

void blink_led(int count){
  pinMode(4, OUTPUT);
  for(int i = 0; i < count; i++){
    digitalWrite(4, HIGH);
    delay(100);
    digitalWrite(4, LOW);
    delay(100);
  }
}


void initNet(){
  WiFi.begin(AP_SSID, AP_PASS);
  while(WiFi.status() != WL_CONNECTED){
    blink_led(3);
    delay(1000);
  }
  digitalWrite(4, LOW);
}

void setup(){
  setupSonar();
  initNet();
}

void sendRangeData(){
  String url = "http://192.168.4.1/range?value=" + String(getDistance());
  http.begin(url);
  
  int httpResponseCode = http.GET();
  http.end();
}

void loop(){
  sendRangeData();
  delay(250);
}
