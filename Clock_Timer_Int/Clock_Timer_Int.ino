#include <string.h>
#include <stdio.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int setButton = 6;
const int hourButton = 7;
const int minButton = 8;

volatile int hrs = 0;
volatile int mins = 0;
volatile int secs  = 0;

int timer1_counter;

int setMode = 0;

char toDisplay[16];

void setup() {
  noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;
  
  timer1_counter = 65536;
  
  TCNT1 = timer1_counter;
  TCCR1B |= (1 << CS12);
  TIMSK1 |= (1 << TOIE1);
  interrupts();
}

ISR(TIMER1_OVF_vect)
{
  TCNT1 = timer1_counter;
  lcd.setCursor(0,1);
  sprintf(toDisplay, "%02d h %02d m %02d s", hrs++, mins++, secs++);
  lcd.print(toDisplay);
}

void loop() {

}
