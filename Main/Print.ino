void prtF(){


  Serial.print("Pot: ");
  Serial.println(potVal);
  Serial.print("currentPosition: ");
  Serial.println(currentPosition);
  Serial.print("output: ");
  Serial.println(output);
  Serial.print("Rev: ");
  Serial.println(rev);
  Serial.print("Current: ");
  Serial.println((double)cf1/1023*5/0.525);
  Serial.println();
  Serial.println();
}
