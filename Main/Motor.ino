// 2 PWM input might be used to reduce by 1 pinout

void move(int motor, int speed, int direction) {
  //Move specific motor at speed and direction

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
  else if (motor == MOTOR_B) {
    digitalWrite(BIN1, inPin1);
    digitalWrite(BIN2, inPin2);
    analogWrite(PWMB, speed);
  }
  else if (motor == MOTOR_C) {
    digitalWrite(CIN1, inPin1);
    digitalWrite(CIN2, inPin2);
    analogWrite(PWMC, speed);
  }
  else if (motor == MOTOR_D) {
    digitalWrite(DIN1, inPin1);
    digitalWrite(DIN2, inPin2);
    analogWrite(PWMD, speed);
  }
  //multiple if to select motors
}

void stop(int motor) {
  // PWM=0
  if (motor == MOTOR_A) {
    digitalWrite(PWMA, 0);
  }
  else if (motor == MOTOR_B) {
    digitalWrite(PWMB, 0);
  }
  else if (motor == MOTOR_C) {
    digitalWrite(PWMC, 0);
  }
  else if (motor == MOTOR_D) {
    digitalWrite(PWMD, 0);
  }
}
