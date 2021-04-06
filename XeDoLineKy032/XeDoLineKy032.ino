#define ssLeft A5
#define ssRight A4
#include<AFMotor.h>;
AF_DCMotor motor1(1,MOTOR12_64KHZ);
AF_DCMotor motor2(2,MOTOR12_64KHZ);
AF_DCMotor motor3(3,MOTOR12_64KHZ);
AF_DCMotor motor4(4,MOTOR12_64KHZ);

void setup() {
  // put your setup code here, to run once:
  pinMode(ssLeft,INPUT);
  pinMode(ssRight,INPUT);
  Serial.begin(9600);
//  motor1.setSpeed(85);
//  motor2.setSpeed(85);
//  motor3.setSpeed(85);
//  motor4.setSpeed(85);
  motor1.setSpeed(100);
  motor2.setSpeed(100);
  motor3.setSpeed(100);
  motor4.setSpeed(100);
}
void forward(){    
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);

}
//lui B 
void backward(){   
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);

}
// trai L
void left(){    
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);

}
//phai R
void right(){   
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);

}
// toi trai  G
void forwardLeft(){  
  motor1.run(FORWARD);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(FORWARD);

}
//toi phai I
void forwardRight(){  
  motor1.run(RELEASE);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(RELEASE);

}
//lui trai  H
void backLeft(){   
  motor1.run(BACKWARD);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(BACKWARD);

}
//lui phai  J
void backRight(){  
  motor1.run(RELEASE);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(RELEASE);

}

//dung S
void st(){    
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}

void loop() {
  int readLeft = analogRead(ssLeft);
  int readRight = analogRead(ssRight);
  // put your main code here, to run repeatedly:
Serial.print("left: ");
Serial.println(readLeft);
Serial.print("right: ");
Serial.println(readRight);
Serial.println("-----------------------");
//delay(500);
if(readLeft <=500 && readRight<= 500) forward();
 else if( readLeft >=500 && readRight<= 500) forwardLeft();
 else if( readLeft <=500 && readRight>= 500) forwardRight();
 else st();
//if(readLeft <=500 )forwardRight();
//else forwardLeft();
}
