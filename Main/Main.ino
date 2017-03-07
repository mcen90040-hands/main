// the setup routine runs once when you press reset:
void setup() {
  // Initial serial com
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  int work=1;

  // send data only when you receive data:
  Serial.println("Please make a choice: ");
  Serial.println("1. Action 1");
  Serial.println("1. Action 2");
  Serial.println("1. Action 3");
  Serial.println("1. Action 4");
  // and etc.

  if (Serial.available() > 0) {
    // read the incoming byte:
    int option = Serial.read();

    // say what you got:
    Serial.print("The choice is : ");
    Serial.println(option, DEC);
    work = action(option);
  }
  
}

int action(int option) {
  switch (option) {
    case 1:
      //do something when var equals 1
      break;
    case 2:
      //do something when var equals 2
      break;
    case 3:
      //do something when var equals 3
      break;
    case 4:
      //do something when var equals 4
      break;
    default:
      // if nothing else matches, do the default
      // default is optional
      break;
  }
  // return 1 if no error occurred
  return 1;
}



