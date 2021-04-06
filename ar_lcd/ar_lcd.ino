#include <DHT.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); //đặt ddicwj chỉ cho LCD và số hàng số cột của LCD

const int DHTPIN = 3;
const int DHTTYPE = DHT11;
DHT dht(DHTPIN, DHTTYPE);

byte degree[8] = {
  0B01110,
  0B01010,
  0B01110,
  0B00000,
  0B00000,
  0B00000,
  0B00000,
  0B00000
};

void setup() {
  lcd.init();  // khởi động mh, bất đầu cho ar sử dụng lcd
  lcd.backlight(); // bật đèn nền
  
  lcd.print("Nhiet do: ");
  lcd.setCursor(0,1); // xuất chữ nhiệt độ tại hàng 2 cột 1
  lcd.print("Do am: ");
  lcd.createChar(1, degree);

  dht.begin();  
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(t) || isnan(h)) { // Kiểm tra xem thử việc đọc giá trị có bị thất bại hay không. Hàm isnan bạn xem tại đây http://arduino.vn/reference/isnan
  } 
  else {
    lcd.setCursor(10,0);
    lcd.print(round(t));
    lcd.print(" ");
    lcd.write(1);
    lcd.print("C");

    lcd.setCursor(10,1);
    lcd.print(round(h));
    lcd.print(" %");    
  }
}
