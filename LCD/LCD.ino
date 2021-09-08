/*
  Hello friends welcome to "TECHNO-E-SOLUTION"
  Here, is a code to print "Hello World" on LCD using Arduino
  This code helps you to print "YOUR TEXT" on LCD display
*/

#include <LiquidCrystal.h>

const int rs = 7, en = 8, d4 = 9, d5 = 10, d6 = 11, d7 = 12;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  
  lcd.begin(16, 2);  // set up the LCD's number of columns and rows:
  
  lcd.print("Hello World!");  // Print a text to the LCD.
}

void loop() {
  
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
}
