#include<SoftwareSerial.h>;
int in1 = 8;
int in2 = 9;
int in3 = 10;
int in4 = 11;

void setup() {
pinMode(in1, OUTPUT);
pinMode(in2, OUTPUT);
pinMode(in3, OUTPUT);
pinMode(in4, OUTPUT);
Serial.begin(9600);

}
void m1tien(){
  digitalWrite(in1, LOW); digitalWrite(in2,HIGH);
}
void m2tien(){
  digitalWrite(in3, LOW); digitalWrite(in4,HIGH);
}
void m1lui(){
  digitalWrite(in1, HIGH); digitalWrite(in2,LOW);
}
void m2lui(){
  digitalWrite(in3, HIGH); digitalWrite(in4,LOW);
}
void dung(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void loop() {
dung();
}
