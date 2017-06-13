#include "header.h"

// the setup routine runs once when you press reset:
void setup() {
  Initialization();
}

// the loop routine runs over and over again forever:
void loop() {
  serialRead();
  //voltDetect();
  action(1);
  delay(3);
}
