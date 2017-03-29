int controller(int motor, int currentPosition, int setPoint) {
  if (currentPosition < setPoint - EPS) {
    myPID.SetControllerDirection(DIRECT);
    move(motor, output, CLOCKWISE);
  }
  else if (currentPosition > setPoint + EPS) {
    myPID.SetControllerDirection(REVERSE);
    move(motor, output, COUNTER_CLOCKWISE);
    Serial.println("Reverse ");
  }
  else {
    stop();
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

int edgeDetect( ){
    
  if (potVal - lastPot < -EDGE_DETECTION && elapsedTime > TIME_TOLERANCE) {
    elapsedTime = 0;
    rev++;
  }         
  if (potVal - lastPot > EDGE_DETECTION && elapsedTime > TIME_TOLERANCE) {
    elapsedTime = 0;
    rev--;
  }
} 


