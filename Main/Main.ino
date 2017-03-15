#include <PID_v1.h>


#define potPin 2 // select the input pin for the potentiometer A
#define PWMA 3 //Speed control 
#define AIN1 9 //Direction
#define AIN2 8 //Direction
#define STBY 10 //standby
#define OFF 0
#define FULL_SPEED 255
#define HALF_SPEED 128
#define CLOCKWISE 0
#define COUNTER_CLOCKWISE 1
#define MOTOR_A 1
#define eps 3
int finish = 0;

//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
double Kp = 1, Ki = 0.1, Kd = 0;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);



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
  Input = analogRead(potPin);
  Setpoint = 100;

  
  myPID.SetSampleTime(3); // in ms
  myPID.SetMode(AUTOMATIC); //turn the PID on
  
}

// the loop routine runs over and over again forever:
void loop() {
  Input = analogRead(potPin);    // read the value from the sensor
  if(abs(Input-Setpoint)>50 ){
    double Kp = 1, Ki = 0.1, Kd = 0;
  }else{
    double Kp = 50, Ki = 1, Kd = 0;
  }
  myPID.Compute();
  Serial.print("Input: ");
  Serial.println(Input);
  Serial.print("Output: ");
  Serial.println(Output);



  
//  Serial.println(myPID.GetITerm());
  if (Input<Setpoint-eps){
    myPID.SetControllerDirection(DIRECT);
    move(MOTOR_A, Output, CLOCKWISE);
  }
  else if(Input>Setpoint+eps){
    myPID.SetControllerDirection(REVERSE);
    move(MOTOR_A, Output, COUNTER_CLOCKWISE);
  }
  else{
    stop();
  }
  

}

int action(int option) {
  int val = 0;
  switch (option) {
    case 1: {
        //do something when var equals 1
        int finish = 0;
        move(MOTOR_A, HALF_SPEED, CLOCKWISE);
        while (finish = 0) {
          val = analogRead(potPin);    // read the value from the sensor
          Serial.println(val);
          if (val > 500) {
            stop();
            finish = 1;
          }
        }
        break;
      }
    case 2:
      //do something when var equals 2
      break;
    case 3:
      //do something when var equals 3
      break;
    case 4:
      //do something when var equals 4
      break;
    default:
      // if nothing else matches, do the default
      // default is optional
      break;
  }
  // return 1 if no error occurred
  return 1;
}

void move(int motor, int speed, int direction) {
  //Move specific motor at speed and direction

  digitalWrite(STBY, HIGH); //disable standby


  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;

  if (direction == COUNTER_CLOCKWISE) {
    inPin1 = HIGH;
    inPin2 = LOW;
  }
  if (motor == MOTOR_A) {
    digitalWrite(AIN1, inPin1);
    digitalWrite(AIN2, inPin2);
    analogWrite(PWMA, speed);
  }
}

void stop() {
  //enable standby
  digitalWrite(STBY, LOW);
}
