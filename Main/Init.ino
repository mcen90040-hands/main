void Initialization(){
    // Initial serial com
  Serial.begin(115200);

  // Setting pin mode
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(PWMC, OUTPUT);
  pinMode(PWMD, OUTPUT);
  pinMode(PWME, OUTPUT);
//  pinMode(PWMF, OUTPUT);

  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(CIN1, OUTPUT);
  pinMode(CIN2, OUTPUT);
  pinMode(DIN1, OUTPUT);
  pinMode(DIN2, OUTPUT);
  pinMode(EIN1, OUTPUT);
  pinMode(EIN2, OUTPUT);
//  pinMode(FIN1, OUTPUT);
//  pinMode(FIN2, OUTPUT);

  pinMode(lowLED, OUTPUT);
  pinMode(ENABLE, OUTPUT);
  digitalWrite(ENABLE, HIGH);
  //initialize the variables linked to
  potValUpdate();

  revA = 0;
  revB = 0;
  revC = 0;
  revD = 0;
  revE = 0;

  currentPositionA = potValA;
  currentPositionB = potValB;
  currentPositionC = potValC;
  currentPositionD = potValD;
  currentPositionE = potValE;
//  currentPositionF = potValF;

  lastPotA = currentPositionA;
  lastPotB = currentPositionB;
  lastPotC = currentPositionC;
  lastPotD = currentPositionD;
  lastPotE = currentPositionE;
//  lastPotF = currentPositionF;

  myPIDA.SetSampleTime(SAMPLE); // in ms
  myPIDB.SetSampleTime(SAMPLE); // in ms
  myPIDC.SetSampleTime(SAMPLE); // in ms
  myPIDD.SetSampleTime(SAMPLE); // in ms
  myPIDE.SetSampleTime(SAMPLE); // in ms
//  myPIDF.SetSampleTime(SAMPLE); // in ms
  
  myPIDA.SetMode(AUTOMATIC); //turn the PID on
  myPIDB.SetMode(AUTOMATIC); //turn the PID on
  myPIDC.SetMode(AUTOMATIC); //turn the PID on
  myPIDD.SetMode(AUTOMATIC); //turn the PID on
  myPIDE.SetMode(AUTOMATIC); //turn the PID on
//  myPIDF.SetMode(AUTOMATIC); //turn the PID on

  myPIDA.SetOutputLimits(PWMMIN, PWMMAX);
  myPIDB.SetOutputLimits(PWMMIN, PWMMAX);
  myPIDC.SetOutputLimits(PWMMIN, PWMMAX);
  myPIDD.SetOutputLimits(PWMMIN, PWMMAX);
  myPIDE.SetOutputLimits(PWMMIN, PWMMAX);
//  myPIDF.SetOutputLimits(PWMMIN, PWMMAX);


  if (analogRead(batDetect>batThreshold)){
    digitalWrite(lowLED,HIGH);
  }
  setPointUpdate();
}

