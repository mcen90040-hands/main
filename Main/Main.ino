#include "header.h"

// the setup routine runs once when you press reset:
void setup(){
  // Initial serial com
  Serial.begin(115200);

  // Setting pin mode
  pinMode(STBY, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);

  //initialize the variables we're linked to
  potVal = analogRead(potPin);
  setPoint = 3500;
  rev=0;

  currentPosition = potVal;
  lastPot = currentPosition;

  
  myPID.SetSampleTime(3); // in ms
  myPID.SetMode(AUTOMATIC); //turn the PID on
}

// the loop routine runs over and over again forever:
void loop() {

  potVal = analogRead(potPin); // read the value from the potentiometer sensor

  //determine if there is a new turn
  if (potVal-lastPot<-EDGE_DETECTION&&elapsedTime>TIME_TOLERANCE){
    elapsedTime = 0;
    rev++;
  }

  if (potVal-lastPot>EDGE_DETECTION&&elapsedTime>TIME_TOLERANCE){
    elapsedTime = 0;
  }

  if (potVal-lastPot>EDGE_DETECTION){
    rev--;
  }
  
  currentPosition = potVal+rev*ONE_REV;
  
  //PID control
  if(abs(currentPosition-setPoint)>50 ){
    double Kp = 1, Ki = 0.1, Kd = 0;
  }else{
    double Kp = 50, Ki = 1, Kd = 0;
  }
  myPID.Compute();
  Serial.print("Pot: ");
  Serial.println(potVal);
  Serial.print("currentPosition: ");
  Serial.println(currentPosition);
  Serial.print("Output: ");
  Serial.println(Output);

  Serial.print("Rev: ");
  Serial.println(rev);
  Serial.println();
  Serial.println();

//  Serial.println(myPID.GetITerm());
  //Control the motor rotates to the position we want
  if (currentPosition<setPoint-EPS){
    myPID.SetControllerDirection(DIRECT);
    move(MOTOR_A, Output, CLOCKWISE);
  }
  else if(currentPosition>setPoint+EPS){

    myPID.SetControllerDirection(REVERSE);
    move(MOTOR_A, Output, COUNTER_CLOCKWISE);
    Serial.println("Reverse ");
  }
  else{
    stop();
  }
  lastPot=potVal;
}
