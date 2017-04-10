// This tab is for debugging only.

void prtF(){
  Serial.print("Pot: ");
  Serial.println(potValA);
  Serial.print("currentPosition: ");
  Serial.println(currentPositionA);
  Serial.print("output: ");
  Serial.println(outputA);
  Serial.print("Rev: ");
  Serial.println(revA);
  Serial.print("Current: ");
  Serial.println((double)cfA/1023*5/0.525);
  Serial.println(feedback());
  Serial.println();
  Serial.println();
}
