#include "header.h"

// the setup routine runs once when you press reset:
void setup() {
  // Initial serial com
  Serial.begin(115200);

  // Setting pin mode
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(PWMC, OUTPUT);
  pinMode(PWMD, OUTPUT);

  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(CIN1, OUTPUT);
  pinMode(CIN2, OUTPUT);
  pinMode(DIN1, OUTPUT);
  pinMode(DIN2, OUTPUT);

  //initialize the variables we're linked to
  potValA = analogRead(POTA);
  setPoint = 0;
  revA = 0;
  currentPositionA = potValA;
  lastPotA = currentPositionA;

  myPID.SetSampleTime(3); // in ms
  myPID.SetMode(AUTOMATIC); //turn the PID on
}

// the loop routine runs over and over again forever:
void loop() {
  // read the value from the potentiometer sensor
  potUpdate();

// Action 1
action(1);

}
