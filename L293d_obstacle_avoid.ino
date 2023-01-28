#include <AFMotor.h>
#include <Servo.h> 
Servo myservo;
AF_DCMotor motor4(4);
AF_DCMotor motor3(3);
AF_DCMotor motor2(2);
AF_DCMotor motor1(1);
void setup() {
  Serial.begin(9600);
    pinMode(A0,OUTPUT);//trig
    pinMode(A3,INPUT);//echo
    myservo.attach(10);   
    motor4.run(RELEASE);motor3.run(RELEASE);motor2.run(RELEASE);motor1.run(RELEASE);
    motor4.setSpeed(200);motor3.setSpeed(200);motor2.setSpeed(200);motor1.setSpeed(200); 

}

void loop() {
digitalWrite(A0, HIGH);
delayMicroseconds(10);
digitalWrite(A0, LOW);
delayMicroseconds(2);
int duration= pulseIn(A3,HIGH); //echo
delay(100);
int distance=duration*0.034/2;
Serial.println(distance);
if(distance<=20 && distance >1)
{
motor4.run(RELEASE);motor3.run(RELEASE);motor2.run(RELEASE);motor1.run(RELEASE);
delay(300);
motor4.run(BACKWARD);motor3.run(BACKWARD);motor2.run(BACKWARD);motor1.run(BACKWARD);
delay(350);
motor4.run(RELEASE);motor3.run(RELEASE);motor2.run(RELEASE);motor1.run(RELEASE);
myservo.write(0);
delay(500);
digitalWrite(A0, HIGH);
delayMicroseconds(10);
digitalWrite(A0, LOW);
delayMicroseconds(2);
int firstduration= pulseIn(A3,HIGH);
delay(100);
int firstdistance=firstduration*0.034/2;
int first = firstdistance;
myservo.write(90);
delay(500);
myservo.write(180);
delay(500);
digitalWrite(A0, HIGH);
delayMicroseconds(10);
digitalWrite(A0, LOW);
delayMicroseconds(2);
int secondduration= pulseIn(A3,HIGH);
delay(100);
int seconddistance=secondduration*0.034/2;
int second2 = seconddistance;
Serial.println(seconddistance);
myservo.write(90);
delay(500);
if(first < second2 ) { motor4.run(RELEASE);motor3.run(RELEASE);motor2.run(FORWARD);motor1.run(FORWARD); delay(500); } else if(first >   second2  )
{
  motor1.run(RELEASE);motor2.run(RELEASE);motor3.run(FORWARD);motor4.run(FORWARD); delay(500);
delay(500);
}
}
else
{
  motor4.run(FORWARD);motor3.run(FORWARD);motor2.run(FORWARD);motor1.run(FORWARD);
}
}
