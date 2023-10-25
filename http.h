#include <WebServer.h>

#define HTTP_OK_CODE 200
#define HTTP_404_CODE 404
#define MIME_TYPE "text/plain"
#define ERROR_MSG "Done"
#define ENABLE_OVERRIDE_MSG "First enable Manual Override"

WebServer server(80);

String statusData="";

bool manualOverride = false;
bool ipvValveState = 0;
bool opvValveState = 0;
int tds = 0;

void toggleIPVState(){
  if(manualOverride){
    ipvValveState = ipvValveState ? false : true;
    controlInputValve(ipvValveState);
    server.send(HTTP_OK_CODE, MIME_TYPE, String(ipvValveState));
  }else{
    server.send(HTTP_OK_CODE, MIME_TYPE, ENABLE_OVERRIDE_MSG);    
  }
}

void toggleOPVState(){
  if(manualOverride){
    opvValveState = opvValveState ? false : true;
    controlOutputValve(opvValveState);
    server.send(HTTP_OK_CODE, MIME_TYPE, String(opvValveState));
  }else{
    server.send(HTTP_OK_CODE, MIME_TYPE, ENABLE_OVERRIDE_MSG);
  }
}

void toggleOverrideState(){
  manualOverride = manualOverride ? false : true;
  server.send(HTTP_OK_CODE, MIME_TYPE, String(manualOverride));
}

void systemReset(){
  server.send(HTTP_OK_CODE, MIME_TYPE, "SYSTEM RESET");
  delay(3000);
  ESP.restart();
}

void getSystemStatus(){
  
  statusData = String(getPh())+":"+String(getTDS(getTemperature()))+":";
  statusData += String(getTemperature())+":"+String(manualOverride)+":";
  statusData += String(ipvValveState)+":"+String(opvValveState)+":";
  statusData += String(getDistance());
  
  server.send(HTTP_OK_CODE, MIME_TYPE, statusData);
}


void notFound(){
  server.send(HTTP_404_CODE, MIME_TYPE, "");
}

void setupServer(){
  server.on("/ipv", toggleIPVState);
  server.on("/opv", toggleOPVState);
  server.on("/override", toggleOverrideState);
  server.on("/status",getSystemStatus);
  server.on("/reset", systemReset);
  server.onNotFound(notFound);
  server.begin();
}

void handleRequests(){
  server.handleClient();
}
