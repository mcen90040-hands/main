void serialRead(){
  int p1, p2, p3, p4;
 
  int readSuccess = 0;
  // send data only when you receive data:
  if (actionFinish == 1) {
    int i = 0;
    while (Serial.available() > 0) {
      // read the incoming int:
      incomingInt[i] = Serial.parseInt();
      if (incomingInt[i] > 10000||incomingInt[i] < -10000) {// over the limit TODO
        Serial.println("TOOOOOOOO big bro. ");
        readSuccess = 0;
        break;
      }
      
      // say what you got: just for debugging
      Serial.print(i, DEC);
      Serial.print("I received: ");
      Serial.println(incomingInt[i], DEC);
      // Only read the first four int
      if (i == 3) {
        readSuccess = 1;
        break;
      }
      i++;
    }
  }
  if (readSuccess == 1) {

    p1 = incomingInt[0];
    p2 = incomingInt[1];
    p3 = incomingInt[2];
    p4 = incomingInt[3];
    // Just for debugging
    Serial.println("Positions are updated! ");
    Serial.print("P1=  ");
    Serial.println(p1, DEC);
    Serial.print("P2=  ");
    Serial.println(p2, DEC);
    Serial.print("P3=  ");
    Serial.println(p3, DEC);
    Serial.print("P4=  ");
    Serial.println(p4, DEC);
    //actionFinish = 0;

  }
}

