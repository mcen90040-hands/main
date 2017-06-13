#include <MyoController.h>

#define FIST_PIN 6
#define WAVEIN_PIN 7
#define WAVEOUT_PIN 8
#define FINGERSSPREAD_PIN 9
#define DOUBLETAP_PIN 10

MyoController myo = MyoController();

void setup() {
  Serial.begin(9600);
  pinMode(FIST_PIN, OUTPUT);
  pinMode(WAVEIN_PIN, OUTPUT);
  pinMode(WAVEOUT_PIN, OUTPUT);
  pinMode(FINGERSSPREAD_PIN, OUTPUT);
  pinMode(DOUBLETAP_PIN, OUTPUT);
  
  myo.initMyo();
}

void loop()
{
   //Serial.println("HI");
   myo.updatePose();
   switch ( myo.getCurrentPose() ) {
    case rest:
      digitalWrite(FIST_PIN,LOW); 
      digitalWrite(WAVEIN_PIN,LOW);
      digitalWrite(WAVEOUT_PIN,LOW);
      digitalWrite(FINGERSSPREAD_PIN,LOW);
      digitalWrite(DOUBLETAP_PIN,LOW);
//      Serial.println("6");
      break;
    case fist:
      digitalWrite(FIST_PIN,HIGH);
//      Serial.println("1");
      break;
    case fingersSpread:
      digitalWrite(FINGERSSPREAD_PIN,HIGH);
//      Serial.println("2");
      break;
      
    case waveIn:
      digitalWrite(WAVEIN_PIN,HIGH);
//      Serial.println("3");
      break;
    case waveOut:
      digitalWrite(WAVEOUT_PIN,HIGH);
//      Serial.println("4");
      break;
    case doubleTap:
      digitalWrite(DOUBLETAP_PIN,HIGH);
//      Serial.println("5");
      break;
   } 
   delay(30);
}
