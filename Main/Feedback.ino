int feedback(){
  cfA = analogRead(FBA);
  cfB = analogRead(FBB);
  cfC = analogRead(FBC);
  cfD = analogRead(FBD);
}

int potValUpdate(){
  potValA = analogRead(POTA);
  potValB = analogRead(POTB);
  potValC = analogRead(POTC);
  potValD = analogRead(POTD);
}

int lastPotUpdate(){
  lastPotA = potValA;
  lastPotB = potValB;
  lastPotC = potValC;
  lastPotD = potValD;
}

int voltDetect(){
  if (analogRead(batDetect<700)){
    
  }
}
// TODO overcurrent detection
