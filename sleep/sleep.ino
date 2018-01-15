#include <avr/interrupt.h>
#include <avr/power.h>
#include <avr/sleep.h>
#include <avr/io.h>

void setup() {
  DDRD &= B00000011;       // set Arduino pins 2 to 7 as inputs, leaves 0 & 1 (RX & TX) as is
  DDRB = B00000000;        // set pins 8 to 13 as inputs
  PORTD |= B11111100;      // enable pullups on pins 2 to 7, leave pins 0 and 1 alone
  PORTB |= B11111111;      // enable pullups on pins 8 to 13
  
  // Set pin13 as LED output
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  
  // Set pin2 as switch input
  pinMode(2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  sleepNow();
  delay(1000);
}

void sleepNow() {
  // Set pin 2 as interrupt and attach handler:
  attachInterrupt(0, pinInterrupt, LOW);
  delay(100);
  //
  // Choose our preferred sleep mode:
  set_sleep_mode(SLEEP_MODE_IDLE);
  //
  // Set sleep enable (SE) bit:
  sleep_enable();
  //
  // Put the device to sleep:
  digitalWrite(13,LOW);   // turn LED off to indicate sleep
  sleep_mode();
  //
  // Upon waking up, sketch continues from this point.
  sleep_disable();
  digitalWrite(13,HIGH);   // turn LED on to indicate awake
}

void pinInterrupt(void)
{
    detachInterrupt(0);
}
