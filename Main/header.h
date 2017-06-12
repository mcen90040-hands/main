#include <PID_v1.h>
#include <elapsedMillis.h>

// define constants for ports
// Motor 1 
#define POTA A8 // select the input pin for the potentiometer 1
#define PWMA 2 //Speed control 1
#define FBA A0 //Current feedback for the motor 1 
#define AIN1 22 //Direction 1 for motor 1
#define AIN2 23 //Direction 2 for motor 1

// Motor 2
#define POTB A9 // select the input pin for the potentiometer 1
#define PWMB 3 //Speed control 1
#define FBB A1 //Current feedback for the motor 1 
#define BIN1 24 //Direction 1 for motor 1
#define BIN2 25 //Direction 2 for motor 1

// Motor 3
#define POTC A10 // select the input pin for the potentiometer 1
#define PWMC 4 //Speed control 1
#define FBC A2 //Current feedback for the motor 1 
#define CIN1 26 //Direction 1 for motor 1
#define CIN2 27 //Direction 2 for motor 1

// Motor 4 
#define POTD A11 // select the input pin for the potentiometer 1
#define PWMD 5 //Speed control 1
#define FBD A3 //Current feedback for the motor 1 
#define DIN1 28 //Direction 1 for motor 1
#define DIN2 29 //Direction 2 for motor 1


//motors
#define MOTOR_A 1
#define MOTOR_B 2
#define MOTOR_C 3
#define MOTOR_D 4

// misc
#define batDetect A15 // for low voltage detection
#define batThreshold 700 //Minimum volt
#define lowLED 

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
int incomingInt[4];   // for incoming serial data
int actionFinish = 0; //Check whether the action is finished
elapsedMillis elapsedTimeA,elapsedTimeB,elapsedTimeC,elapsedTimeD;

//Define Variables we'll be connecting to
double setPointA, currentPositionA, outputA, revA = 0;
int lastPotA, potValA;

double setPointB, currentPositionB, outputB, revB = 0;
int lastPotB, potValB;

double setPointC, currentPositionC, outputC, revC = 0;
int lastPotC, potValC;

double setPointD, currentPositionD, outputD, revD = 0;
int lastPotD, potValD;


//Define Vs for current fb
int cfA,cfB,cfC,cfD;
//Specify the links and initial tuning parameters
double Kp = 1, Ki = 0.1, Kd = 0;
PID myPIDA(&currentPositionA, &outputA, &setPointA, Kp, Ki, Kd, DIRECT);
PID myPIDB(&currentPositionB, &outputB, &setPointB, Kp, Ki, Kd, DIRECT);
PID myPIDC(&currentPositionC, &outputC, &setPointC, Kp, Ki, Kd, DIRECT);
PID myPIDD(&currentPositionD, &outputD, &setPointD, Kp, Ki, Kd, DIRECT);
