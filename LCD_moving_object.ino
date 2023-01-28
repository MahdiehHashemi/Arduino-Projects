#include <LiquidCrystal.h>
/* Create object named lcd of the class LiquidCrystal */
LiquidCrystal lcd(13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3);  /* For 8-bit mode */
//LiquidCrystal lcd(13, 12, 11, 6, 5, 4, 3);  /* For 4-bit mode */

byte arrowhead[]={
  B00001,
  B00011,
  B00111,
  B01111,
  B00111,
  B00011,
  B00001,
  B00000
};

byte arrowbody[]={
  B00000,
  B00000,
  B00000,
  B11111,
  B11111,
  B00000,
  B00000,
  B00000
};

byte arrowtail[]={
  B00011,
  B00111,
  B11111,
  B11111,
  B11111,
  B00111,
  B00011,
  B00000
};

byte man[] = {
  B01110,
  B01110,
  B00100,
  B01110,
  B10101,
  B00100,
  B01010,
  B10001
};

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.createChar(0,arrowhead);
  lcd.createChar(1,arrowbody);
  lcd.createChar(2,arrowtail);
  lcd.createChar(3,man);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  //lcd.print("hello, world!");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  //lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  //lcd.print(millis() / 1000);
  int n;
  n=15;
  while(n!=-1){
    lcd.clear();
    delay(10);
    lcd.setCursor(0,0);
    lcd.print("By Me");
    lcd.setCursor(1,1);
    lcd.write(byte(3));
    lcd.setCursor(n,1);
    lcd.write(byte(0));
    lcd.write(byte(1));
    lcd.write(byte(2));
    delay(65);
    n--;
  }
}
