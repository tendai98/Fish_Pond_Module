const int pingPin = 33; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 32; // Echo Pin of Ultrasonic Sensor
int currentSonarRange = 0;
int lap = 0;

void setupSonar() {
   pinMode(pingPin, OUTPUT);
   pinMode(echoPin, INPUT);
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}

int getDistance() {
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   long duration = pulseIn(echoPin, HIGH);
   
   if((millis() - lap) > 2000){
      lap = millis();
      currentSonarRange = microsecondsToCentimeters(duration);
      return currentSonarRange;
   }else{
      return currentSonarRange;
   }
}
