int action(int option) {

  switch (option) {
    case 1: {   // index flexion
        if ( en_state == LOW) {
          digitalWrite(ENABLE, HIGH);
        }
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% //
        //       setPointB = 500+dist;

        // read the value from the potentiometer sensor
        potValUpdate();

        //determine if there is a new turn
        currentPositionB = edgeDetect(MOTOR_B);

        //PID control
        gainSchedule(currentPositionB, setPointB);

        //Motor Action
        //      controller(MOTOR_B, currentPositionB, setPointB);
        controller(MOTOR_B, currentPositionB, setPointB);

        //Update last pot value
        lastPotB = potValB;
        break;
      }
    case 2: {   // index extension
        if ( en_state == LOW) {
          digitalWrite(ENABLE, HIGH);
        }
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% //
        //        setPointB = 500;

        // read the value from the potentiometer sensor
        potValUpdate();

        //determine if there is a new turn
        currentPositionB = edgeDetect(MOTOR_B);

        //PID control
        gainSchedule(currentPositionB, setPointB);

        //Motor Action
        //      controller(MOTOR_B, currentPositionB, setPointB);
        controller(MOTOR_B, currentPositionB, setPointB);

        //Update last pot value
        lastPotB = potValB;
        break;
      }
    case 3: {   // middle flexion
        if ( en_state == LOW) {
          digitalWrite(ENABLE, HIGH);
        }
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% //
        //       setPointA = 221+dist;

        // read the value from the potentiometer sensor
        potValUpdate();

        //determine if there is a new turn
        currentPositionA = edgeDetect(MOTOR_A);

        //PID control
        gainSchedule(currentPositionA, setPointA);

        //Motor Action
        //      controller(MOTOR_B, currentPositionB, setPointB);
        controller(MOTOR_A, currentPositionA, setPointA);

        //Update last pot value
        lastPotA = potValA;
        break;
      }
    case 4: {   // middle extension
        if ( en_state == LOW) {
          digitalWrite(ENABLE, HIGH);
        }
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% //
        setPointA = 50;

        // read the value from the potentiometer sensor
        potValUpdate();

        //determine if there is a new turn
        currentPositionA = edgeDetect(MOTOR_A);

        //PID control
        gainSchedule(currentPositionA, setPointA);

        //Motor Action
        //      controller(MOTOR_B, currentPositionB, setPointB);
        controller(MOTOR_A, currentPositionA, setPointA);

        //Update last pot value
        lastPotA = potValA;
        break;
      }
    case 5: {   // ring flexion
        if ( en_state == LOW) {
          digitalWrite(ENABLE, HIGH);
        }
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% //
        setPointD = 122 + dist;

        // read the value from the potentiometer sensor
        potValUpdate();

        //determine if there is a new turn
        currentPositionD = edgeDetect(MOTOR_D);

        //PID control
        gainSchedule(currentPositionD, setPointD);

        //Motor Action
        //      controller(MOTOR_B, currentPositionB, setPointB);
        controller(MOTOR_D, currentPositionD, setPointD);

        //Update last pot value
        lastPotD = potValD;
        break;
      }
    case 6: {   // ring extension
        if ( en_state == LOW) {
          digitalWrite(ENABLE, HIGH);
        }
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% //
        setPointD = 122;

        // read the value from the potentiometer sensor
        potValUpdate();

        //determine if there is a new turn
        currentPositionD = edgeDetect(MOTOR_D);

        //PID control
        gainSchedule(currentPositionD, setPointD);

        //Motor Action
        //      controller(MOTOR_B, currentPositionB, setPointB);
        controller(MOTOR_D, currentPositionD, setPointD);

        //Update last pot value
        lastPotD = potValD;
        break;
      }
    case 7: {   // little flexion
        if ( en_state == LOW) {
          digitalWrite(ENABLE, HIGH);
        }
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% //
        setPointC = 230 + dist;

        // read the value from the potentiometer sensor
        potValUpdate();

        //determine if there is a new turn
        currentPositionC = edgeDetect(MOTOR_C);

        //PID control
        gainSchedule(currentPositionC, setPointC);

        //Motor Action
        //      controller(MOTOR_B, currentPositionB, setPointB);
        controller(MOTOR_C, currentPositionC, setPointC);

        //Update last pot value
        lastPotC = potValC;
        break;
      }
    case 8: {   // ring extension
        if ( en_state == LOW) {
          digitalWrite(ENABLE, HIGH);
        }
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% //
        setPointD = 230;

        // read the value from the potentiometer sensor
        potValUpdate();

        //determine if there is a new turn
        currentPositionC = edgeDetect(MOTOR_C);

        //PID control
        gainSchedule(currentPositionC, setPointC);

        //Motor Action
        //      controller(MOTOR_B, currentPositionB, setPointB);
        controller(MOTOR_C, currentPositionC, setPointC);

        //Update last pot value
        lastPotC = potValC;
        break;
      }
          case 9: {   // ring extension
        if ( en_state == LOW) {
          digitalWrite(ENABLE, HIGH);
        }
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% //
        setPointD = 230;

        // read the value from the potentiometer sensor
        potValUpdate();

        //determine if there is a new turn
        currentPositionC = edgeDetect(MOTOR_C);

        //PID control
        gainSchedule(currentPositionC, setPointC);

        //Motor Action
        //      controller(MOTOR_B, currentPositionB, setPointB);
        controller(MOTOR_C, currentPositionC, setPointC);

        //Update last pot value
        lastPotC = potValC;
        break;
      }
          case 10: {   // ring extension
        if ( en_state == LOW) {
          digitalWrite(ENABLE, HIGH);
        }
// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% //
        setPointD = 230;

        // read the value from the potentiometer sensor
        potValUpdate();

        //determine if there is a new turn
        currentPositionC = edgeDetect(MOTOR_C);

        //PID control
        gainSchedule(currentPositionC, setPointC);

        //Motor Action
        //      controller(MOTOR_B, currentPositionB, setPointB);
        controller(MOTOR_C, currentPositionC, setPointC);

        //Update last pot value
        lastPotC = potValC;
        break;
      }
    //      case 1: {
    //        if ( en_state == LOW) {
    //          digitalWrite(ENABLE, HIGH);
    //        }
    //        setPointA = 2500;
    //        setPointB = 2500;
    //        setPointC = 700;
    //        setPointD = 2500;
    //        setPointE = 2500;
    //        // read the value from the potentiometer sensor
    //        potValUpdate();
    //
    //        //determine if there is a new turn
    //        currentPositionA = edgeDetect(MOTOR_A);
    //        currentPositionB = edgeDetect(MOTOR_B);
    //        currentPositionC = edgeDetect(MOTOR_C);
    //        currentPositionD = edgeDetect(MOTOR_D);
    //        currentPositionE = edgeDetect(MOTOR_E);
    //        //PID control
    //        gainSchedule(currentPositionA, setPointA);
    //        gainSchedule(currentPositionB, setPointB);
    //        gainSchedule(currentPositionC, setPointC);
    //        gainSchedule(currentPositionD, setPointD);
    //        gainSchedule(currentPositionE, setPointE);
    //
    //        //Motor Action
    //        //      controller(MOTOR_B, currentPositionB, setPointB);
    //        controller(MOTOR_A, currentPositionA, setPointA);
    //        controller(MOTOR_B, currentPositionB, setPointB);
    //        controller(MOTOR_C, currentPositionC, setPointC);
    //        controller(MOTOR_D, currentPositionD, setPointD);
    //        controller(MOTOR_E, currentPositionE, setPointE);
    //
    //        //Update last pot value
    //        lastPotA = potValA;
    //        lastPotB = potValB;
    //        lastPotC = potValC;
    //        lastPotD = potValD;
    //        lastPotE = potValE;
    //        break;
    //      }
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
