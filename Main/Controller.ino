int controller(int motor, int currentPosition, int setPoint) {
  if (currentPosition < setPoint - EPS) {
    myPID.SetControllerDirection(DIRECT);
    move(motor, output, CLOCKWISE);
  }
  else if (currentPosition > setPoint + EPS) {
    myPID.SetControllerDirection(REVERSE);
    move(motor, output, COUNTER_CLOCKWISE);
  }
  else {
    stop(motor);
  } 
}

int gainSchedule(int currentPosition, int setPoint) {
  
  if (abs(currentPosition - setPoint) > 300 ) {
    double Kp = 100, Ki = 0, Kd = 0;
  }
  else if (abs(currentPosition - setPoint) > 100 ) {
    double Kp = 10, Ki = 0, Kd = 0;
  }
  else {
    double Kp = 1, Ki = 0, Kd = 0;
  }
  myPID.Compute();
}

int edgeDetect(int motor) {
  if (motor == MOTOR_A) {
    if (potValA - lastPotA < -EDGE_DETECTION && elapsedTimeA > TIME_TOLERANCE) {
      elapsedTimeA = 0;
      revA++;
    }
    if (potValA - lastPotA > EDGE_DETECTION && elapsedTimeA > TIME_TOLERANCE) {
      elapsedTimeA = 0;
      revA--;
    }
    //determine the linearized current position
    return potValA + revA * ONE_REV;
  }
  else if (motor == MOTOR_B) {
    if (potValB - lastPotB < -EDGE_DETECTION && elapsedTimeB > TIME_TOLERANCE) {
      elapsedTimeB = 0;
      revB++;
    }
    if (potValA - lastPotA > EDGE_DETECTION && elapsedTimeB > TIME_TOLERANCE) {
      elapsedTimeB = 0;
      revB--;
    }
    //determine the linearized current position
    return potValB + revB * ONE_REV;
  }
  else if (motor == MOTOR_C) {
    if (potValC - lastPotC < -EDGE_DETECTION && elapsedTimeC > TIME_TOLERANCE) {
      elapsedTimeC = 0;
      revC++;
    }
    if (potValC - lastPotC > EDGE_DETECTION && elapsedTimeC > TIME_TOLERANCE) {
      elapsedTimeC = 0;
      revC--;
    }
    //determine the linearized current position
    return potValC + revC * ONE_REV;
  }
  else if (motor == MOTOR_D) {
    if (potValD - lastPotD < -EDGE_DETECTION && elapsedTimeD > TIME_TOLERANCE) {
      elapsedTimeC = 0;
      revD++;
    }
    if (potValD - lastPotD > EDGE_DETECTION && elapsedTimeD > TIME_TOLERANCE) {
      elapsedTimeD = 0;
      revD--;
    }
    //determine the linearized current position
    return potValD + revD * ONE_REV;
  }

}


