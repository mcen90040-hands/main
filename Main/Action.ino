int action(int option) {
  int val = 0;
  switch (option) {
    case 1: {
        //do something when var equals 1
        int finish = 0;
        move(MOTOR_A, HALF_SPEED, CLOCKWISE);
        while (finish = 0) {
          val = analogRead(potPin);    // read the value from the sensor
          Serial.println(val);
          if (val > 500) {
            stop();
            finish = 1;
          }
        }
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
