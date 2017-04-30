int controller(int motor, int currentPosition, int setPoint) {
  int output;
  if (motor == MOTOR_A) {
    output = outputA;
    if (currentPosition < setPoint - EPS) {
      myPIDA.SetControllerDirection(DIRECT);
      move(motor, output, CLOCKWISE);
    }
    else if (currentPosition > setPoint + EPS) {
      myPIDA.SetControllerDirection(REVERSE);
      move(motor, output, COUNTER_CLOCKWISE);
    }
    else {
      stop(motor);
    }
  }
  else if (motor == MOTOR_B) {
    output = outputB;
    if (currentPosition < setPoint - EPS) {
      myPIDB.SetControllerDirection(DIRECT);
      move(motor, output, CLOCKWISE);
    }
    else if (currentPosition > setPoint + EPS) {
      myPIDB.SetControllerDirection(REVERSE);
      move(motor, output, COUNTER_CLOCKWISE);
    }
    else {
      stop(motor);
    }
  }
  else if (motor == MOTOR_C) {
    output = outputC;
    if (currentPosition < setPoint - EPS) {
      myPIDC.SetControllerDirection(DIRECT);
      move(motor, output, CLOCKWISE);
    }
    else if (currentPosition > setPoint + EPS) {
      myPIDC.SetControllerDirection(REVERSE);
      move(motor, output, COUNTER_CLOCKWISE);
    }
    else {
      stop(motor);
    }
  }
  else if (motor == MOTOR_D) {
    output = outputD;
    if (currentPosition < setPoint - EPS) {
      myPIDD.SetControllerDirection(DIRECT);
      move(motor, output, CLOCKWISE);
    }
    else if (currentPosition > setPoint + EPS) {
      myPIDD.SetControllerDirection(REVERSE);
      move(motor, output, COUNTER_CLOCKWISE);
    }
    else {
      stop(motor);
    }
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
  myPIDA.Compute();
  myPIDB.Compute();
  myPIDC.Compute();
  myPIDD.Compute();
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


