#include <PID_v1.h>
#include <elapsedMillis.h>




#define potPin A0 // select the input pin for the potentiometer A
#define PWMA 2 //Speed control
#define AIN1 24 //Direction
#define AIN2 26//Direction
#define STBY 22 //standby
#define OFF 0
#define FULL_SPEED 255
#define HALF_SPEED 128
#define CLOCKWISE 0
#define COUNTER_CLOCKWISE 1
#define MOTOR_A 1
#define EPS 3
#define ONE_REV 1024
#define EDGE_DETECTION 100
#define TIME_TOLERANCE 100
int finish = 0;
elapsedMillis elapsedTime;

//Define Variables we'll be connecting to
double setPoint, currentPosition, Output,rev;
int multiplier,lastPot, potVal;

//Specify the links and initial tuning parameters
double Kp = 1, Ki = 0.1, Kd = 0;
PID myPID(&currentPosition, &Output, &setPoint, Kp, Ki, Kd, DIRECT);
