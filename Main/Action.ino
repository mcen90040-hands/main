int reset() {

}

int action(int option) {
  int val = 0;
  switch (option) {
    case 1: {
        //determine if there is a new turn
        currentPositionA = edgeDetect(1);
        currentPositionB = edgeDetect(2);
        currentPositionC = edgeDetect(3);
        currentPositionD = edgeDetect(4);

        //PID control
        gainSchedule(currentPositionA, setPointA);

        //Printing parameters for debugging
        prtF();

        //Motor Action
        move(1, 255, COUNTER_CLOCKWISE);

        //Update last pot value
        lastPotA = potValA;
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
