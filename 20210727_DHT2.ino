//2초마다 측정한 온도, 습도값 화면에 보여주기
#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal_I2C.h>

DHT mydht(12,DHT11);

LiquidCrystal_I2C mytlcd (0x27,16,2);

void setup() {
  mydht.begin();
  mytlcd.init();
  mytlcd.backlight();
  Serial.begin(9600);
  delay(2000);
}

void loop() {
  int temp = mydht.readTemperature();
  int humi = mydht.readHumidity();
  mytlcd.init();
  mytlcd.backlight();
  mytlcd.setCursor(0,0);
  mytlcd.print("temperature : ");
  mytlcd.print(temp);
  mytlcd.setCursor(0,1);
  mytlcd.print("Humidity : ");
  mytlcd.print(humi);
}
