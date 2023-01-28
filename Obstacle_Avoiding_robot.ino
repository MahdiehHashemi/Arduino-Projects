
#include <Servo.h>
Servo myservo;
void setup() {
pinMode(5,OUTPUT);//trig
pinMode(6,INPUT); //echo 
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
pinMode(9, OUTPUT);
pinMode(10, OUTPUT);

myservo.attach(3);
Serial.begin(9600);
}
void loop()
{
digitalWrite(5, HIGH);
delayMicroseconds(10);
digitalWrite(5, LOW);
delayMicroseconds(2);
int duration= pulseIn(6,HIGH); //echo
delay(100);
int distance=duration*0.034/2;
Serial.println(distance);
if(distance<=20)
{
digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(9, LOW);
digitalWrite(10, LOW);
delay(300);
digitalWrite(7,HIGH);
digitalWrite(8, LOW);
digitalWrite(9, HIGH);
digitalWrite(10, LOW);
delay(350);
digitalWrite(7, LOW);
digitalWrite(8, LOW);
digitalWrite(9, LOW);
digitalWrite(10, LOW);
myservo.write(0);
delay(500);
digitalWrite(5, HIGH);
delayMicroseconds(10);
digitalWrite(5, LOW);
delayMicroseconds(2);
int firstduration= pulseIn(6,HIGH);
delay(100);
int firstdistance=firstduration*0.034/2;
int first = firstdistance;
Serial.println(firstdistance);
myservo.write(90);
delay(500);
myservo.write(180);
delay(500);
digitalWrite(5, HIGH);
delayMicroseconds(10);
digitalWrite(5, LOW);
delayMicroseconds(2);
int secondduration= pulseIn(6,HIGH);
delay(100);
int seconddistance=secondduration*0.034/2;
int second = seconddistance;
Serial.println(seconddistance);
myservo.write(90);
delay(500);
if(first < second ) { digitalWrite(7, LOW); digitalWrite(8, HIGH); digitalWrite(9, LOW); digitalWrite(10, LOW); delay(500); } else if(first >   second  )
{
digitalWrite(7, LOW);
digitalWrite(8,LOW);
digitalWrite(9, LOW);
digitalWrite(10, HIGH);
delay(500);
}
}
else
{
digitalWrite(7,LOW);
digitalWrite(8, HIGH);
digitalWrite(9, LOW);
digitalWrite(10, HIGH);
}
}
