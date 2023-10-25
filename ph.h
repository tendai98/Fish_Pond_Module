const int adcPin = 35;
float ph = 0;
int lapPh = 0;

void initPh(){
  pinMode(adcPin, INPUT);
}

float getPh() {
  if((millis() - lapPh) > 3000){
      lapPh = millis();
      float Po = analogRead(adcPin) * 3.3 / 4096;
      ph = 7 - (2.5 - Po) - 0.8;
      return ph;
   }else{
      return ph;
   }
}
