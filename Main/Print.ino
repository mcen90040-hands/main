void prtF(){
  Serial.print("Pot: ");
  Serial.println(potValB);
  Serial.print("currentPosition: ");
  Serial.println(currentPositionA);
  Serial.print("outputC: ");
  Serial.println(outputA);
  Serial.print("Rev: ");
  Serial.println(revA);
  Serial.print("Current: ");
  Serial.println((double)cfC/1023*5/0.525);
  Serial.println();
  Serial.println();
}
