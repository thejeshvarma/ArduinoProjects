#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27,16,2);
char a[15]="Hello_World";
int i = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lcd.begin(16,2);
lcd.backlight();
lcd.setBacklight(HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
lcd.setCursor(0,0);
lcd.blink();
lcd.print("Here is text");
lcd.setCursor(2,1);
lcd.print("its text again");
delay(3000);
lcd.clear();
delay(500);
for(i = 0;i<11;i++){
  lcd.setCursor(i,0);
  delay(500);
  lcd.print(a[i]);
}
delay(2000);
lcd.clear();
}
