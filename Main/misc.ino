void time_check(){
  if (actionTime > ACTION_TIME) {
    actionTime = ACTION_TIME + 1000;
    option = 0;
    digitalWrite(ENABLE, LOW);
  } else {
    option = 1;
    if ( en_state == LOW) {
      digitalWrite(ENABLE, HIGH);
    }
  }
}

