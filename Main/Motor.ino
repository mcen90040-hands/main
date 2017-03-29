// 2 PWM input might be used to reduce by 1 pinout

void move(int motor, int speed, int direction) {
  //Move specific motor at speed and direction

  digitalWrite(STBY, HIGH); //disable standby


  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;

  if (direction == COUNTER_CLOCKWISE) {
    inPin1 = HIGH;
    inPin2 = LOW;
  }
  if (motor == MOTOR_A) {
    digitalWrite(AIN1, inPin1);
    digitalWrite(AIN2, inPin2);
    analogWrite(PWMA, speed);
  }
}

void stop() {
  //enable standby
  digitalWrite(STBY, LOW);
}
