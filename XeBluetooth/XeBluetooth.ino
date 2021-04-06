//Trần Viết An 19CE001
#include <AFMotor.h>
#include<SoftwareSerial.h>;
AF_DCMotor motor1(1,MOTOR12_64KHZ);
AF_DCMotor motor2(2,MOTOR12_64KHZ);
AF_DCMotor motor3(3,MOTOR12_64KHZ);
AF_DCMotor motor4(4,MOTOR12_64KHZ);

//int trig= A4;
//int echo = A5;
int txd = A8;
int rxd = A9;
SoftwareSerial bluetooth(txd,rxd);

char bl;

void setup(){
//  pinMode(9,OUTPUT);
//  motor1.setSpeed(255);
//  motor2.setSpeed(255);
//  motor3.setSpeed(255);
//  motor4.setSpeed(255);
  bluetooth.begin(9600);
  Serial.begin(9600);

}
void sp(int s){     //dieu chinh toc do
  motor1.setSpeed(s);
  motor2.setSpeed(s);
  motor3.setSpeed(s);
  motor4.setSpeed(s);
}
//toi F
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
void onLeght(){
  digitalWrite(9,1);
}
void offLeght(){
  digitalWrite(9,0);
}

void carRun(){
  if(bluetooth.available()){
    bl = bluetooth.read();  
  }
  Serial.println(bl);
  switch(bl){
    case('F'):
      forward();break;
    case('B'):
      backward();break;
    case('L'):
      left();break;
    case('R'):
      right();break;
    case('G'):
      forwardLeft();break;
    case('I'):
      forwardRight();break;
    case('H'):
      backLeft();break;
    case('J'):
      backRight();break;
    case('S'):
      st();break;
    case('U'):
      onLeght();break;
    case('u'):
      offLeght();break;
          case('1'):
      sp(70);break;
          case('2'):
      sp(90);break;
          case('3'):
      sp(100);break;
          case('4'):
      sp(120);break;
          case('5'):
      sp(140);break;
          case('6'):
      sp(160);break;
          case('7'):
      sp(180);break;
          case('8'):
      sp(200);break;
          case('9'):
      sp(230);break;
          case('q'):
      sp(255);break;
      
  }
}

void loop(){
  carRun();
}
