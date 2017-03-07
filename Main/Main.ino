#include <PID_v1.h>
double Setpoint, Input, Output;
PID myPID(&Input, &Output, &Setpoint, 20.5, 10.5, 9.99, DIRECT);
#define m1c1  20
#define m1c2  21
#define m2c1  18
#define m2c2  19
#define ENC1 2
#define ENB1 3
#define M1M1 13
#define M1M2 12
#define M2M1 11
#define M2M2 10
long m1Count = 0;
long rot1 = 0;
long rev1 = 0;
long m2Count = 0;
long rot2 = 0;
long rev2 = 0;
short spd = 60;
double deg1 = 0;
double deg2 = 0;
int rev = -1;
int deg = 0;
short m1pwm = 0;
short m2pwm = 0;
float t = 0;
float a0 = 0, a1 = 0, a2 = 135, a3 = -90;
float y = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  // Define encoder signals for the motor 1
  pinMode(m1c1, INPUT);
  pinMode(m1c2, INPUT);

  // Define encoder signals for the motor 2
  pinMode(m2c1, INPUT);
  pinMode(m2c2, INPUT);

  // M1 control signal
  pinMode(M1M1, OUTPUT);//dir
  pinMode(M1M2, OUTPUT);//dir
  pinMode(ENC1, OUTPUT);//pwm(speed)

  // M2 control signal
  pinMode(M2M1, OUTPUT);//dir
  pinMode(M2M2, OUTPUT);//dir
  pinMode(ENB1, OUTPUT);//pwm(speed)

  myPID.SetSampleTime(10);
  myPID.SetMode(AUTOMATIC);
  // test
  //  digitalWrite(M1M1, LOW);
  //  digitalWrite(M1M2, HIGH);
  //  analogWrite(ENC1, 100);
  //
  //  digitalWrite(M2M1, LOW);
  //  digitalWrite(M2M2, HIGH);
  //  analogWrite(ENB1, 100);
  motorFW(M1M1, M1M2);
  // M1 encoder int
  attachInterrupt(digitalPinToInterrupt(m1c1), motor1EncoderC1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(m1c2), motor1EncoderC2, CHANGE);

  // M2 encoder int
  attachInterrupt(digitalPinToInterrupt(m2c1), motor2EncoderC1, CHANGE);
  attachInterrupt(digitalPinToInterrupt(m2c2), motor2EncoderC2, CHANGE);
}

// the loop routine runs over and over again forever:
void loop() {

  // send data only when you receive data:
  Serial.println("Please make a choice: ");
  Serial.println("1. Action 1");
  Serial.println("1. Action 2");
  Serial.println("1. Action 3");
  Serial.println("1. Action 4");
  // and etc.
  
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();

    // say what you got:
    Serial.print("The choice is : ");
    Serial.println(incomingByte, DEC);
  }

  int action(int option){
    
  }



