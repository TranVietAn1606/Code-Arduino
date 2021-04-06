#include <AFMotor.h>
#include<SoftwareSerial.h>;
AF_DCMotor motor1(1,MOTOR12_64KHZ);
AF_DCMotor motor2(2,MOTOR12_64KHZ);
AF_DCMotor motor3(3,MOTOR12_64KHZ);
AF_DCMotor motor4(4,MOTOR12_64KHZ);

//int trig= A4;
//int echo = A5;
int txd = A5;
int rxd = A4;
SoftwareSerial bluetooth(txd,rxd);

char bl;

void setup(){
//  pinMode(9,OUTPUT);
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  bluetooth.begin(9600);
  Serial.begin(9600);

}


void carRundemo(){


}
void loop(){
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
//  motor1.run(BACKWARD);
//  motor2.run(BACKWARD);
//  motor3.run(BACKWARD);
//  motor4.run(BACKWARD);

}
