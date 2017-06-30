int action(int option) {
  int val = 0;
  switch (option) {
    case 1: {
        if ( en_state == LOW) {
          digitalWrite(ENABLE, HIGH);
        }
        setPointA = 2500;
        setPointB = 2500;
        setPointC = 700;
        setPointD = 2500;
        setPointE = 2500;
        // read the value from the potentiometer sensor
        potValUpdate();

        //determine if there is a new turn
        currentPositionA = edgeDetect(MOTOR_A);
        currentPositionB = edgeDetect(MOTOR_B);
        currentPositionC = edgeDetect(MOTOR_C);
        currentPositionD = edgeDetect(MOTOR_D);
        currentPositionE = edgeDetect(MOTOR_E);
        //PID control
        gainSchedule(currentPositionA, setPointA);
        gainSchedule(currentPositionB, setPointB);
        gainSchedule(currentPositionC, setPointC);
        gainSchedule(currentPositionD, setPointD);
        gainSchedule(currentPositionE, setPointE);

        //Motor Action
        //      controller(MOTOR_B, currentPositionB, setPointB);
        controller(MOTOR_A, currentPositionA, setPointA);
        controller(MOTOR_B, currentPositionB, setPointB);
        controller(MOTOR_C, currentPositionC, setPointC);
        controller(MOTOR_D, currentPositionD, setPointD);
        controller(MOTOR_E, currentPositionE, setPointE);

        //Update last pot value
        lastPotA = potValA;
        lastPotB = potValB;
        lastPotC = potValC;
        lastPotD = potValD;
        lastPotE = potValE;
        break;
      }
    case 2: {
        if ( en_state == LOW) {
          digitalWrite(ENABLE, HIGH);
        }
        setPointA = 650;
        setPointB = 620;
        setPointC = 700;
        setPointD = 150;
        setPointE = 450;
        // read the value from the potentiometer sensor
        potValUpdate();

        //determine if there is a new turn
        currentPositionA = edgeDetect(MOTOR_A);
        currentPositionB = edgeDetect(MOTOR_B);
        currentPositionC = edgeDetect(MOTOR_C);
        currentPositionD = edgeDetect(MOTOR_D);
        currentPositionE = edgeDetect(MOTOR_E);
        //PID control
        gainSchedule(currentPositionA, setPointA);
        gainSchedule(currentPositionB, setPointB);
        gainSchedule(currentPositionC, setPointC);
        gainSchedule(currentPositionD, setPointD);
        gainSchedule(currentPositionE, setPointE);

        //Motor Action
        //      controller(MOTOR_B, currentPositionB, setPointB);
        controller(MOTOR_A, currentPositionA, setPointA);
        controller(MOTOR_B, currentPositionB, setPointB);
        controller(MOTOR_C, currentPositionC, setPointC);
        controller(MOTOR_D, currentPositionD, setPointD);
        controller(MOTOR_E, currentPositionE, setPointE);

        //Update last pot value
        lastPotA = potValA;
        lastPotB = potValB;
        lastPotC = potValC;
        lastPotD = potValD;
        lastPotE = potValE;
        break;
      }
    default:
      // if nothing else matches, do the default
      // default is optional
      en_state = LOW;
      digitalWrite(ENABLE, en_state);
      break;
  }
  // return 1 if no error occurred
  return 1;
}
