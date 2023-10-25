#include "wifi.h"
#include "valve_relays.h"
#include "ph.h"
#include "tds.h"
#include "temp.h"
#include "sonar.h"
#include "http.h"
#include "client.h"

float currentPh;
float currentTemp;
int currentTDS;
int currentSonarLevel;


bool autoControlSub(){
    currentPh = getPh();
    currentTemp =  getTemperature();
    currentTDS = getTDS(currentTemp);
    
    bool check1 = currentTDS > 500;
    bool check2 = currentPh  > 7 && currentPh  >= 7.5;
    bool check3 = currentPh  <= 6 && currentPh  <= 6.5;    
    return (check1 || check2 || check3);
}

void waterLevelControlSub(){
  if(getDistance() > 4){
    controlInputValve(HIGH);
    if(getDistance() > 1000){
      controlInputValve(LOW); 
    }
  }else{    bool check2 = currentPh  >= 7.0 && currentPh  >= 7.5;
    controlInputValve(LOW);    
  }
}

void setup(){
  initPh();
  setupAP();
  //setupClient();
  setupSonar();
  setupServer();
  setupTemperature();
  setupValveControls();
}

void loop(){

  if(!manualOverride){
    waterLevelControlSub();
    if(autoControlSub()){
      controlOutputValve(HIGH);
    }else{
      controlOutputValve(LOW);      
    }
  }

 
  handleRequests();
  //sendValues();
  delay(100);
}
