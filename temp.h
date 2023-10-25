#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define BUS 23
#define DHTTYPE DHT11

DHT_Unified dht(BUS, DHTTYPE);
sensor_t sensor;
sensors_event_t event;
uint32_t sensorDelay = 0;

void setupTemperature(){
  dht.begin();
  dht.temperature().getSensor(&sensor);
}

float getTemperature(){
  dht.temperature().getEvent(&event);
  return isnan(event.temperature) ? -1 : event.temperature;
}
