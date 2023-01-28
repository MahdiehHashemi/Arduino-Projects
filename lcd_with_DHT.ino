#include <DFRobot_DHT11.h>
#include <LiquidCrystal.h>
/* Create object named lcd of the class LiquidCrystal */
LiquidCrystal lcd(13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3);  /* For 8-bit mode */
//LiquidCrystal lcd(13, 12, 11, 6, 5, 4, 3);  /* For 4-bit mode */
DFRobot_DHT11 DHT;
#define DHT11_PIN A0

void setup(){
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop(){
  DHT.read(DHT11_PIN);
  Serial.print("temp:");
  Serial.print(DHT.temperature);
  Serial.print("  humi:");
  Serial.println(DHT.humidity);
  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  // print the number of seconds since reset:
  lcd.print(DHT.temperature); 
  lcd.setCursor(0, 1);
  lcd.print("Humid: ");
  // print the number of seconds since reset:
  lcd.print(DHT.humidity); 
}
