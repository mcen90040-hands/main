#include "header.h"


// the setup routine runs once when you press reset:
void setup() {
  Initialization();
}

// the loop routine runs over and over again forever:
void loop() {
  //blue();
  serialRead();
  voltDetect();
  prtF();
  feedback();
  time_check();
  action(1);
  
  delay(20);
}
