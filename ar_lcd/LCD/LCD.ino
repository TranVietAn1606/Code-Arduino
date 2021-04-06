#include<Wire.h>
#include<LiquidCrystal_I2C.h>;
LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  // put your setup code here, to run once:
Wire.begin(D1,D2);
lcd.init();
lcd.clear();
lcd.backlight();
lcd.setCursor(1,0);
lcd.print("Tran Viet An");
lcd.print((char)223);lcd.print("C");
lcd.setCursor(1,1);
lcd.print("Doan xa");
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.display();
  delay(1000);
  lcd.noDisplay();
  delay(500);

}
