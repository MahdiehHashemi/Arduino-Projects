// Arduino Line Follower Robot Code

#define enA 5//Enable1 L293 Pin enA 

#define in1 6 //Motor1  L293 Pin in1 

#define in2 7 //Motor1  L293 Pin in1 

#define in3 9 //Motor2  L293 Pin in1 

#define in4 10 //Motor2  L293 Pin in1 

#define enB 8 //Enable2 L293 Pin enB 

#define R_S 4//ir sensor Right**right sensor is connected to the left wheel

#define L_S 2 //ir sensor Left**left sensor is connected to the right wheel

#define M_S 3 

void setup(){ 
Serial.begin(9600);

pinMode(R_S, INPUT); 

pinMode(L_S, INPUT); 

pinMode(M_S, INPUT); 

pinMode(enA, OUTPUT); 

pinMode(in1, OUTPUT); 

pinMode(in2, OUTPUT); 

pinMode(in3, OUTPUT); 

pinMode(in4, OUTPUT); 

pinMode(enB, OUTPUT);

digitalWrite(enA, HIGH); 

digitalWrite(enB, HIGH); 

delay(1000);

}

void loop(){  
  Serial.print("RS= ");
  Serial.print( digitalRead(R_S) );
  Serial.print(" LS= ");
  Serial.print(digitalRead(L_S));
  Serial.print(" MS= ");
  Serial.println(digitalRead(M_S));

if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 0)&& (digitalRead(M_S) == 1)){forward();}   //if Right Sensor and Left Sensor are at White color then it will call forword function

if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 0)&& (digitalRead(M_S) == 1) ){turnRight();} //if Right Sensor is Black and Left Sensor is White then it will call turn Right function  

if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 0)&&(digitalRead(M_S) == 0)){turnRight();}

if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 1)&& (digitalRead(M_S) == 1)){turnLeft();}  //if Right Sensor is White and Left Sensor is Black then it will call turn Left function

if((digitalRead(R_S) == 0)&&(digitalRead(L_S) == 1)&&(digitalRead(M_S) == 0)){turnLeft();}

if((digitalRead(R_S) == 1)&&(digitalRead(L_S) == 1)&& (digitalRead(M_S) == 1)){Stop();} //if Right Sensor and Left Sensor are at Black color then it will call Stop function


}

void forward(){  //forword

digitalWrite(in1,LOW); //Right Motor forword Pin 

digitalWrite(in2, HIGH);  //Right Motor backword Pin 

digitalWrite(in3, LOW);  //Left Motor backword Pin 

digitalWrite(in4, HIGH); //Left Motor forword Pin 

}

void turnRight(){ //turnRight

digitalWrite(in1, LOW);  //Right Motor forword Pin 

digitalWrite(in2, LOW); //Right Motor backword Pin  

digitalWrite(in3, LOW);  //Left Motor backword Pin 

digitalWrite(in4, HIGH); //Left Motor forword Pin 
delay(100);

}

void turnLeft(){ //turnLeft

digitalWrite(in1, LOW); //Right Motor forword Pin 

digitalWrite(in2, HIGH);  //Right Motor backword Pin 

digitalWrite(in3, LOW); //Left Motor backword Pin 

digitalWrite(in4, LOW);  //Left Motor forword Pin 
delay(100);

}

void Stop(){ //stop

digitalWrite(in1, LOW); //Right Motor forword Pin 

digitalWrite(in2, LOW); //Right Motor backword Pin 

digitalWrite(in3, LOW); //Left Motor backword Pin 

digitalWrite(in4, LOW); //Left Motor forword Pin 

}
