 #include<SoftwareSerial.h>;
int txd = 0;
int rxd = 1;

#include <Servo.h> 
#define SERVO_PIN 9
Servo gServo;

SoftwareSerial bluetooth(txd,rxd); //khi báo chân vào ra blt
int in1=10, in2=11, in3=12, in4=13; //khai báo các chân ra của rơ le động cơ
char bl;

void setup(){
  pinMode(in1, OUTPUT); //khai báo tín hiệu ra cho các chân rơ le
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  bluetooth.begin(9600);
  Serial.begin(9600);
  gServo.attach(SERVO_PIN); 

}
void servoOn(){
    gServo.write(100); 
}
void servoOff(){
    gServo.write(0); 
}
void m1lui(){
  digitalWrite(in1, LOW); digitalWrite(in2,HIGH);
}
void m2lui(){
  digitalWrite(in3, LOW); digitalWrite(in4,HIGH);
}
void m1tien(){
  digitalWrite(in1, HIGH); digitalWrite(in2,LOW);
}
void m2tien(){
  digitalWrite(in3, HIGH); digitalWrite(in4,LOW);
}

void m1dung(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}
void m2dung(){
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
void dung(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
//void tien(){
//  m1tien(); m2tien();  
//}
//void lui(){
//  m1lui(); m2lui();
//}
void tien(){
  m1tien(); m2tien();  
}
void lui(){
  m1lui(); m2lui();
}
void phai(){
  m1tien(); m2lui();  
}
void trai(){
  m1lui(); m2tien();
}

void tienphai(){
  m2dung(); m1tien();
}
void tientrai(){
  m1dung(); m2tien();
}
void luiphai(){
  m1lui(); m2dung();
}
void luitrai(){
  m1dung(); m2lui();
}


//void tienphai(){
//  m2dung(); m1tien();
//}
//void tientrai(){
//  m1dung(); m2tien();
//}
//void luiphai(){
//  m2dung(); m1lui();
//}
//void luitrai(){
//  m1dung(); m2lui();
//}
//void phai(){
//  m1tien(); m2lui();  
//}
//void trai(){
//  m1lui(); m2tien();
//}

void carRun(){
  if(bluetooth.available()){   //kết nối nhân tín hiệu blt từ ứng dụng 
    bl = bluetooth.read();      //đọc và gán tín hiện nhận đc cho biến bl
  }
  Serial.println(bl);

  //dùng switch để điều khiển động cơ từ tín hiệu blt nhận đc 
  switch(bl){
    case('F'):
      tien();break;
    case('B'):
      lui();break;
    case('L'):
      trai();break;
    case('R'):
      phai();break;
    case('G'):
      tientrai();break;
    case('I'):
      tienphai();break;
    case('H'):
      luitrai();break;
    case('J'):  
      luiphai();break;
    case('S'):
      dung();break;
    case('X'):
      servoOn();break;
    case('x'):
      servoOff();break;
  }
}

void loop(){
  carRun();
}
