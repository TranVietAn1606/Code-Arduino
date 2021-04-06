//#define cambien A4
//void setup() {
//pinMode(cambien, INPUT);
//Serial.begin(9600);
//
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//  int value = analogRead(cambien);
//Serial.println(value);
//
//}


const int trig = 8;
const int echo = 7;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned long duration;
  int distance;
  digitalWrite(trig,0);
  delayMicroseconds(2);
  digitalWrite(trig,1);

    delayMicroseconds(5);
    digitalWrite(trig,0);

    duration = pulseIn(echo,HIGH);

    distance = int(duration/2/27);
    Serial.print(distance);
    Serial.println("cm");
    delay(100);


}
