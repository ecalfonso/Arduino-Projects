void setup() {
  // Input Pins
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  
  // Output Pins
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  
  // Set Output Pins default state
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  int LEDstate = 0;
  int LEDspeed = 1;
  int switchUp, switchDown;
  
  while (1) {
  switchUp = digitalRead(3);
  if (switchUp == HIGH && LEDspeed < 10)
    LEDspeed++;
  
  switchDown = digitalRead(2);
  if (switchDown == HIGH && LEDspeed > 1)
    LEDspeed--;
  
  delay(250 * LEDspeed);
  
  switch (LEDstate) {
    case 0:
      digitalWrite(11, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(13, LOW);
      LEDstate = 1;
      break;
    case 1:
      digitalWrite(11, LOW);
      digitalWrite(12, HIGH);
      digitalWrite(13, LOW);
      LEDstate = 2;
      break;
    case 2:
      digitalWrite(11, LOW);
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      LEDstate = 0;
      break;
    default:
      LEDstate = 0;
  }
  }
}
