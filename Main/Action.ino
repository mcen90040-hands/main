int action(int option) {
  int val = 0;
  switch (option) {
    case 1: {
        // read the value from the potentiometer sensor
        potValUpdate();

        //determine if there is a new turn
        currentPositionB = edgeDetect(MOTOR_A);
        currentPositionC = edgeDetect(MOTOR_B);

        //PID control
        gainSchedule(currentPositionB, setPointB);
        gainSchedule(currentPositionA, setPointA);
        //Printing parameters for debugging
        prtF();

        //Motor Action
  //      controller(MOTOR_B, currentPositionB, setPointB);
       controller(MOTOR_A, currentPositionA, setPointA);

        //Update last pot value
        lastPotA = potValA;
        lastPotB = potValB;
        lastPotC = potValC;
        lastPotD = potValD;
        break;
      }
    case 2:
      //do something when var equals 2
      break;
    case 3:
      //do something when var equals 3
      break;
    case 4:
      //do something when var equals 4
      break;
    default:
      // if nothing else matches, do the default
      // default is optional
      break;
  }
  // return 1 if no error occurred
  return 1;
}
