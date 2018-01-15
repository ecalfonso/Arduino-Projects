#include <string.h>
#include <stdio.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int setButton = 6;
const int hourButton = 7;
const int minButton = 8;

int hrs = 0;
int mins = 0;
int secs  = 0;

int setMode = 0;

char toDisplay[16];

void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Clock: ");
  lcd.setCursor(0,1);
  sprintf(toDisplay, "%02d:%02d", hrs, mins);
  lcd.print(toDisplay);
}

void loop() {
  // Print
  lcd.setCursor(0,1);
  sprintf(toDisplay, "%02d h %02d m %02d s", hrs, mins, secs);
  lcd.print(toDisplay);
  
  // Delay
  delay(1000);
  
  // Increment
  secs++;
  if (secs == 60) {
    secs = 0;
    if (mins == 60) {
      mins = 0;
      if (hrs == 13)
        hrs = 0;
      else
        hrs ++;
    }
    else
      mins++;
    
  }
}
