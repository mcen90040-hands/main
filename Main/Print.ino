void prtF() {
  Serial.print("Pot: ");
    Serial.print(potValA);
  Serial.print("    ");
  Serial.print(potValB);
  Serial.print("    ");
  Serial.print(potValC);
  Serial.print("    ");
  Serial.print(potValD);
  Serial.println("    ");
  Serial.println();
  Serial.print("currentPosition: ");
  Serial.print(currentPositionA);
  Serial.print("    ");
  Serial.print(currentPositionB);
  Serial.print("    ");
  Serial.print(currentPositionC);
  Serial.print("    ");
  Serial.print(currentPositionD);
  Serial.println("    ");
  Serial.println();
  
  Serial.print("output:  ");
  Serial.print(outputA);
  Serial.print("    ");
  Serial.print(outputB);
  Serial.print("    ");
  Serial.print(outputC);
  Serial.print("    ");
  Serial.print(outputD);
  Serial.println();
  
  Serial.print("Rev: ");
  Serial.println(revA);
  Serial.print("Current: ");
  Serial.println((double)cfC / 1023 * 5 / 0.525);
  Serial.println();
  Serial.println();
}
