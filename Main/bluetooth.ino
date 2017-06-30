void blue(){
     //Serial.println("HI");
   myo.updatePose();
   switch ( myo.getCurrentPose() ) {
    case rest:
//      digitalWrite(FIST_PIN,LOW); 
//      digitalWrite(WAVEIN_PIN,LOW);
//      digitalWrite(WAVEOUT_PIN,LOW);
//      digitalWrite(FINGERSSPREAD_PIN,LOW);
//      digitalWrite(DOUBLETAP_PIN,LOW);
      option = 6;
      break;
    case fist:
//      digitalWrite(FIST_PIN,HIGH);
      option = 1;
      break;
    case fingersSpread:
//      digitalWrite(FINGERSSPREAD_PIN,HIGH);
      option = 2;
      break;
      
    case waveIn:
//      digitalWrite(WAVEIN_PIN,HIGH);
      option = 3;
      break;
    case waveOut:
//      digitalWrite(WAVEOUT_PIN,HIGH);
      option = 4;
      break;
    case doubleTap:
//      digitalWrite(DOUBLETAP_PIN,HIGH);
      option = 5;
      break;
   } 
}

