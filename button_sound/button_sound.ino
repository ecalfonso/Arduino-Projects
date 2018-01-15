#include <avr/sleep.h>

const int butPin1 = 2;
const int butPin2 = 3;

const int soundPin = 13;

void setup() {
  Serial.begin(9600);
  
  pinMode(butPin1, INPUT_PULLUP);
  pinMode(butPin2, INPUT_PULLUP);
  
  pinMode(soundPin, OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(butPin1), makeNoise1, RISING);
  attachInterrupt(digitalPinToInterrupt(butPin2), makeNoise2, RISING);
}

void loop() {
}

void makeNoise1() {
  detachInterrupt(digitalPinToInterrupt(butPin1));
  tone(soundPin, 40, 75);
  attachInterrupt(digitalPinToInterrupt(butPin1), makeNoise1, RISING);
}

void makeNoise2() {
  detachInterrupt(digitalPinToInterrupt(butPin2));
  tone(soundPin, 255, 75);
  attachInterrupt(digitalPinToInterrupt(butPin2), makeNoise2, RISING);
}

