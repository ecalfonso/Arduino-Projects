#include <string.h>
#include <stdio.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int scrollDelay = 350;
const int msgDelay = 2000;

char toDisplay[16];
char msg1[16] = "Hello world!";

int state = 0;

void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Jumbotronnn");
  
  lcd.setCursor(15,1);
  lcd.print("H");
}

void loop() {
  lcd.setCursor(0,1);
  lcd.print("                ");
  for (int i = 15; i > -1; i--)
  {
    lcd.setCursor(i,1);
    lcd.print(msg1);
    delay(scrollDelay);
  }
  delay(msgDelay);
}
