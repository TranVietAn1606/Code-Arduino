#include<DHT.h>
const int DHTPIN = 3;
const int DHTTYPE = DHT11;
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  
  Serial.begin(9600);
  dht.begin();// khoi dong cam bien

}

void loop() {
  float h = dht.readHumidity();  //doc do am
  float t = dht.readTemperature();//doc nhiet do
  Serial.print("Nhiet do: ");
  Serial.println(t);
  Serial.print("Do am: ");
  Serial.println(h);
  Serial.println("---------------------");
  delay(1000);
}
