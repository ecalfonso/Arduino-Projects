#include <SoftwareSerial.h>
#include <LiquidCrystal.h>

int BT_TX_PIN=11;
int BT_RX_PIN=10;
SoftwareSerial BT (BT_TX_PIN, BT_RX_PIN);

LiquidCrystal LCD (13, 12, 5, 4, 3, 2);


void setup() {
  LCD.clear();
  LCD.print("Setting up System..");
  
  BT.begin(9600); // Set BT baud
  delay(5000);
  
  BT.print("AT+NAMEtestBT"); // Change HC-06 Name
  delay(1000);

  LCD.clear();
  LCD.print("Waiting for BT..");
}

String str, sub1, sub2;

void loop() {
  // put your main code here, to run repeatedly:
  delay(50);
  
  if (BT.available() > 0)
  {
    str=BT.readString();
    LCD.clear();
    LCD.print(str);
  }  
}
