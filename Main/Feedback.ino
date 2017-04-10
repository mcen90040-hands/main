int feedback(){
  cfA = analogRead(FBA);
  cfB = analogRead(FBB);
  cfC = analogRead(FBC);
  cfD = analogRead(FBD);
}

int potUpdate(){
  potValA = analogRead(POTA);
  potValB = analogRead(POTB);
  potValC = analogRead(POTC);
  potValD = analogRead(POTD);
}
// TODO overcurrent detection
