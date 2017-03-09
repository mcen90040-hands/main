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
int finish = 0;

//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
double Kp = 0, Ki = 0.1, Kd = 0;
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
  Setpoint = 500;

  //turn the PID on
  myPID.SetMode(AUTOMATIC);
}

// the loop routine runs over and over again forever:
void loop() {
  int work = 1;


  // send data only when you receive data:
//  Serial.println("Please make a choice: ");
//  Serial.println("1. Action 1");
//  Serial.println("1. Action 2");
//  Serial.println("1. Action 3");
//  Serial.println("1. Action 4");
  // and etc.

  //  if (Serial.available() > 0) {
  //    // read the incoming byte:
  //    int option = Serial.read();
  //
  //    // say what you got:
  //    Serial.print("The choice is : ");
  //    Serial.println(option, DEC);
  //
  //  }


  
  Input = analogRead(potPin);    // read the value from the sensor
  myPID.Compute();
  Serial.print("Input: ");
  Serial.println(Input);
  Serial.print("Output: ");
  Serial.println(Output);
//  Serial.println(myPID.GetITerm());
  move(MOTOR_A, Output, CLOCKWISE);
  

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



