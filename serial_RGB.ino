int r;
int g;
int b;
void setup() {
  Serial.begin(9600);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop() {
  while(Serial.available()){
  r=Serial.parseInt();
  g=Serial.parseInt();
  b=Serial.parseInt();
  analogWrite(9,r);
  analogWrite(10,g);
  analogWrite(11,b);
 
  }
}
