void setup() 
{
  Serial.begin(9600);//Mở cổng Serial ở mức 960
  pinMode(2,INPUT);
  pinMode(A0,INPUT);
//  ​pinMode (2, INPUT)
//  ​pinMode(A0, INPUT)
//  ​pinMode (13, OUTPUT)
}
 
void loop() 
{
  int value = analogRead(A0);
  value=map(value,1023,0,100,0);
  
Serial.println(value);
delay(1000);

  
//  ​// Đọc giá trị D0 rồi điều khiển Led 13...Các bạn cũng có thể điều khiển bơm nước thông qua rơle...
//  ​if (digitalRead (2) == 0
//  ​
// ​  digitalWrite (13, HIGH)
//  ​
//  ​else
// ​  digitalWrite (13, LOW)
//       ​
}
