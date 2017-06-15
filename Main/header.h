#include <PID_v1.h>
#include <elapsedMillis.h>

// define constants for ports
// Motor 1 
#define POTA A3 // select the input pin for the potentiometer 1
#define PWMA 7 //Speed control 1
#define FBA A0 //Current feedback for the motor 1 
#define AIN1 11 //Direction 1 for motor 1
#define AIN2 12 //Direction 2 for motor 1

// Motor 2
#define POTB A2 // select the input pin for the potentiometer 1
#define PWMB 4 //Speed control 1
#define FBB A1 //Current feedback for the motor 1 
#define BIN1 9 //Direction 1 for motor 1
#define BIN2 8 //Direction 2 for motor 1

// Motor 3
#define POTC A7 // select the input pin for the potentiometer 1
#define PWMC 5 //Speed control 1
#define FBC A13 //Current feedback for the motor 1 
#define CIN1 29 //Direction 1 for motor 1
#define CIN2 39 //Direction 2 for motor 1

// Motor 4
#define POTD A8 // select the input pin for the potentiometer 1
#define PWMD 2 //Speed control 1
#define FBD A14 //Current feedback for the motor 1 
#define DIN1 25 //Direction 1 for motor 1
#define DIN2 26 //Direction 2 for motor 1

// Motor 5
#define POTE A10 // select the input pin for the potentiometer 1
#define PWME 3 //Speed control 1
#define FBE A12 //Current feedback for the motor 1 
#define EIN1 37 //Direction 1 for motor 1
#define EIN2 36 //Direction 2 for motor 1

// Motor 6
#define POTF A11 // select the input pin for the potentiometer 1
#define PWMF 6 //Speed control 1
#define FBF A9 //Current feedback for the motor 1 
#define FIN1 19 //Direction 1 for motor 1
#define FIN2 18 //Direction 2 for motor 1


//motors
#define MOTOR_A 1
#define MOTOR_B 2
#define MOTOR_C 3
#define MOTOR_D 4
#define MOTOR_E 5
#define MOTOR_F 6

// misc
#define batDetect A15 // for low voltage detection
#define batThreshold 620 //Minimum volt
#define lowLED 53
#define SAMPLE 25 //sample time
#define ENABLE 38
#define PWMMAX 170
#define PWMMIN 0

//commands
#define OFF 0
#define FULL_SPEED 255
#define HALF_SPEED 128
#define CLOCKWISE 0
#define COUNTER_CLOCKWISE 1
#define EPS 20
#define ONE_REV 1024
#define EDGE_DETECTION 400
#define TIME_TOLERANCE 100
#define ACTION_TIME 2000

//global variables
int incomingInt[4];   // for incoming serial data
int actionFinish = 1; //Check whether the action is finished
elapsedMillis elapsedTimeA,elapsedTimeB,elapsedTimeC,elapsedTimeD,elapsedTimeE;
elapsedMillis actionTime;

//Define Variables we'll be connecting to
double setPointA, currentPositionA, outputA, revA = 0;
int lastPotA, potValA;

double setPointB, currentPositionB, outputB, revB = 0;
int lastPotB, potValB;

double setPointC, currentPositionC, outputC, revC = 0;
int lastPotC, potValC;

double setPointD, currentPositionD, outputD, revD = 0;
int lastPotD, potValD;

double setPointE, currentPositionE, outputE, revE = 0;
int lastPotE, potValE;

//double setPointF, currentPositionF, outputF, revF = 0;
//int lastPotF, potValF;
int option,en_state;

//Define Vs for current fb
int cfA,cfB,cfC,cfD,cfE,cfF;
//Specify the links and initial tuning parameters
double Kp = 0.5, Ki = 0, Kd = 0;
PID myPIDA(&currentPositionA, &outputA, &setPointA, Kp, Ki, Kd, DIRECT);
PID myPIDB(&currentPositionB, &outputB, &setPointB, Kp, Ki, Kd, DIRECT);
PID myPIDC(&currentPositionC, &outputC, &setPointC, Kp, Ki, Kd, DIRECT);
PID myPIDD(&currentPositionD, &outputD, &setPointD, Kp, Ki, Kd, DIRECT);
PID myPIDE(&currentPositionE, &outputE, &setPointE, Kp, Ki, Kd, DIRECT);
//PID myPIDF(&currentPositionF, &outputF, &setPointF, Kp, Ki, Kd, DIRECT);
