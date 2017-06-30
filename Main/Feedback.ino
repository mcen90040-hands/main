int feedback() {
  cfA = analogRead(FBA);
  cfB = analogRead(FBB);
  cfC = analogRead(FBC);
  cfD = analogRead(FBD);
  cfE = analogRead(FBE);
//  cfF = analogRead(FBF);
}

int potValUpdate() {
  potValA = analogRead(POTA);
  potValB = analogRead(POTB);
  potValC = analogRead(POTC);
  potValD = analogRead(POTD);
  potValE = analogRead(POTE);
//  potValF = analogRead(POTF);

}

int lastPotUpdate() {
  lastPotA = potValA;
  lastPotB = potValB;
  lastPotC = potValC;
  lastPotD = potValD;
  lastPotE = potValE;
//  lastPotF = potValF;
}

void voltDetect() {
  if (analogRead(batDetect) < batThreshold) {
    digitalWrite(lowLED, HIGH);
  } else {
    digitalWrite(lowLED, LOW);
  }

}
// TODO overcurrent detection
