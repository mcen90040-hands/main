#include <PID_v1.h>
#include <elapsedMillis.h>

// define constants for ports

#define potPin A0 // select the input pin for the potentiometer 1
#define PWMA 2 //Speed control 1
#define FB1 A7 //Current feedback for the motor 1 
#define AIN1 24 //Direction 1 for motor 1
#define AIN2 26 //Direction 2 for motor 1
#define STBY 22 //status 1

//motors
#define MOTOR_A 1

//commands
#define OFF 0
#define FULL_SPEED 255
#define HALF_SPEED 128
#define CLOCKWISE 0
#define COUNTER_CLOCKWISE 1
#define EPS 500
#define ONE_REV 1024
#define EDGE_DETECTION 100
#define TIME_TOLERANCE 100

//global variables
int finish = 0; //a token
elapsedMillis elapsedTime;

//Define Variables we'll be connecting to
double setPoint, currentPosition, output,rev;
int multiplier,lastPot, potVal;

//Define Vs for current fb
int cf1;
//Specify the links and initial tuning parameters
double Kp = 1, Ki = 0.1, Kd = 0;
PID myPID(&currentPosition, &output, &setPoint, Kp, Ki, Kd, DIRECT);
