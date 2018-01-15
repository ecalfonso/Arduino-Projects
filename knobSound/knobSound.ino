int knobPin = A0;

void setup() {
  // Setup Serial
  Serial.begin(9600);
}

void loop() {
  int knobVal = analogRead(knobPin);
  
  Serial.print("Knob value: ");
  Serial.println(knobVal);
  
  int pitch = map(knobVal, 1023, 0, 5, 40);
  
  
 Serial.println(pitch);
  tone(13, pitch, 10);
  
  delay(1000);
}
