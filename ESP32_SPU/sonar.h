const int pingPin = 12; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 13; // Echo Pin of Ultrasonic Sensor

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

   return microsecondsToCentimeters(duration);
}
