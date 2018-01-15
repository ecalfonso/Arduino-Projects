int ledPin = 13;
int interruptPin = 2;
int state = LOW;
volatile int d = 1;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, RISING);
}

void loop() {
  digitalWrite(ledPin, state);
  delay(250 * d);
  state = !state;
}

void blink() {
  detachInterrupt(digitalPinToInterrupt(interruptPin));
  if (d > 9)
    d = 0;
  d++;
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, RISING);
}
