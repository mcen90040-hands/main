#include "header.h"

// the setup routine runs once when you press reset:
void setup() {
  // Initial serial com
  Serial.begin(115200);

  // Setting pin mode
  pinMode(STBY, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  //initialize the variables we're linked to
  potVal = analogRead(potPin);
  setPoint = 20000;
  rev = 0;
  currentPosition = potVal;
  lastPot = currentPosition;

  myPID.SetSampleTime(3); // in ms
  myPID.SetMode(AUTOMATIC); //turn the PID on
}

// the loop routine runs over and over again forever:
void loop() {
  potVal = analogRead(potPin);    // read the value from the potentiometer sensor

  //determine if there is a new turn
  edgeDetect();

  //determine the linearized current position
  currentPosition = potVal + rev * ONE_REV;

  //PID control
  gainSchedule(currentPosition, setPoint);

  //Printing parameters for debugging
  prtF(); 

  //Motor Action
//  controller(MOTOR_A, currentPosition, setPoint);
  move(1, 255, COUNTER_CLOCKWISE);
  //Update last pot value
  lastPot = potVal;
}
