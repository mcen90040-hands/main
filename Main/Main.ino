
#include <header.h>


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
  CurrentPosition = analogRead(potPin);
  Setpoint = -3500;
  rev=0;
  LastPot = analogRead(potPin);

  
  myPID.SetSampleTime(3); // in ms
  myPID.SetMode(AUTOMATIC); //turn the PID on
  
}

// the loop routine runs over and over again forever:
void loop() {

  PotVal = analogRead(potPin);    // read the value from the sensor
  if (PotVal-LastPot<-600){
    rev++;
  }

  if (PotVal-LastPot>600){

    rev--;
  }
  CurrentPosition = PotVal+rev*ONE_REV;
  if(abs(CurrentPosition-Setpoint)>50 ){
    double Kp = 1, Ki = 0.1, Kd = 0;
  }else{
    double Kp = 50, Ki = 1, Kd = 0;
  }
  myPID.Compute();
  Serial.print("CurrentPosition: ");
  Serial.println(CurrentPosition);
  Serial.print("Output: ");
  Serial.println(Output);

  Serial.print("Rev: ");
  Serial.println(rev);

//  Serial.println(myPID.GetITerm());

  if (CurrentPosition<Setpoint-EPS){
    myPID.SetControllerDirection(DIRECT);
    move(MOTOR_A, Output, CLOCKWISE);
  }
  else if(CurrentPosition>Setpoint+EPS){

    myPID.SetControllerDirection(REVERSE);
    move(MOTOR_A, Output, COUNTER_CLOCKWISE);
  }
  else{
    stop();
  }
  LastPot=PotVal;
}
