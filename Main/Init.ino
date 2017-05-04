void Initialization(){
    // Initial serial com
  Serial.begin(115200);

  // Setting pin mode
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(PWMC, OUTPUT);
  pinMode(PWMD, OUTPUT);

  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
  pinMode(CIN1, OUTPUT);
  pinMode(CIN2, OUTPUT);
  pinMode(DIN1, OUTPUT);
  pinMode(DIN2, OUTPUT);

  //initialize the variables linked to
  potValUpdate();

  revA = 0;
  revB = 0;
  revC = 0;
  revD = 0;

  currentPositionA = potValA;
  currentPositionB = potValB;
  currentPositionC = potValC;
  currentPositionD = potValD;

  lastPotA = currentPositionA;
  lastPotB = currentPositionB;
  lastPotC = currentPositionC;
  lastPotD = currentPositionD;

  myPIDA.SetSampleTime(3); // in ms
  myPIDB.SetSampleTime(3); // in ms
  myPIDC.SetSampleTime(3); // in ms
  myPIDD.SetSampleTime(3); // in ms
  
  myPIDA.SetMode(AUTOMATIC); //turn the PID on
  myPIDB.SetMode(AUTOMATIC); //turn the PID on
  myPIDC.SetMode(AUTOMATIC); //turn the PID on
  myPIDD.SetMode(AUTOMATIC); //turn the PID on
}

