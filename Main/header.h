#include <PID_v1.h>
#include <elapsedMillis.h>



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
#define EPS 3
#define ONE_REV 1024
#define EDGE_DETECTION 100
#define TimeTolerance 100
int finish = 0;
elapsedMillis ElapsedTime;

//Define Variables we'll be connecting to
double Setpoint, CurrentPosition, Output,rev;
int multiplier,LastPot, PotVal;

//Specify the links and initial tuning parameters
double Kp = 1, Ki = 0.1, Kd = 0;
PID myPID(&CurrentPosition, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
