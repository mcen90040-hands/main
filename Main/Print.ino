void prtF(){
  Serial.print("Pot: ");
  Serial.println(potValC);
  Serial.print("currentPosition: ");
  Serial.println(currentPositionC);
  Serial.print("output: ");
  Serial.println(output);
  Serial.print("Rev: ");
  Serial.println(revC);
  Serial.print("Current: ");
  Serial.println((double)cfC/1023*5/0.525);
  Serial.println();
  Serial.println();
}
