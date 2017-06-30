void time_check(){
  if (actionTime > ACTION_TIME) {
    actionTime = ACTION_TIME + 1000;
    digitalWrite(ENABLE, LOW);
  } else {
    if ( en_state == LOW) {
      digitalWrite(ENABLE, HIGH);
    }
  }
}

