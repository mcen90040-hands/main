int action(int option) {
  int val = 0;
  switch (option) {
    case 1: {
        // read the value from the potentiometer sensor
        potValUpdate();

        //determine if there is a new turn
        currentPositionC = edgeDetect(MOTOR_C);
        currentPositionD = edgeDetect(MOTOR_D);

        //PID control
        gainSchedule(currentPositionC, setPointC);
        gainSchedule(currentPositionD, setPointD);
        //Printing parameters for debugging
        prtF();

        //Motor Action
        controller(MOTOR_C, currentPositionC, setPointC);
        controller(MOTOR_D, currentPositionD, setPointD);
        
        //Update last pot value
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
