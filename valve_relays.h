#define INPUT_VALVE_RELAY 19
#define OUTPUT_VALVE_RELAY 18

void setupValveControls(){
   pinMode(INPUT_VALVE_RELAY, OUTPUT);
   pinMode(OUTPUT_VALVE_RELAY, OUTPUT);
   digitalWrite(INPUT_VALVE_RELAY, HIGH);
   digitalWrite(OUTPUT_VALVE_RELAY, HIGH);
}

void controlInputValve(int state){
  digitalWrite(INPUT_VALVE_RELAY, !state);
}

void controlOutputValve(int state){
  digitalWrite(OUTPUT_VALVE_RELAY, !state);
}
