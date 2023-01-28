
int Green=10;
int Yellow=11;
int Red=12;

void setup() {
  pinMode(Green,OUTPUT);
  pinMode(Yellow,OUTPUT);  
  pinMode(Red,OUTPUT); 
}

void loop() {
  digitalWrite(Green,HIGH);
  digitalWrite(Yellow,LOW);
  digitalWrite(Red,LOW);
  delay(2000);
  digitalWrite(Yellow,HIGH);
  digitalWrite(Red,LOW);
  digitalWrite(Green,LOW);
  delay(500);
  digitalWrite(Red,HIGH);
  digitalWrite(Yellow,LOW);
  digitalWrite(Green,LOW);
  delay(2000);

}
