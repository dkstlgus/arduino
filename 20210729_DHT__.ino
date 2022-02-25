//1분마다 측정한 온도값 화면에 보여주기
#include <DHT.h>
#include <DHT_U.h>
#include <LiquidCrystal_I2C.h>

DHT mydht(12,DHT11);
LiquidCrystal_I2C mylcd(0x27,16,2);

void setup() {
  Serial.begin(9600);
  mydht.begin();
  mylcd.init();

  mylcd.backlight();
  mylcd.setCursor(0,0);
  mylcd.print("Weather project!");
  delay(5000);
  mylcd.clear();
}

float temp_array[6];  //실수값으로 온도값을 저장하기 위한 배열
float humi_array[6];  //실수값으로 습도값을 저장하기 위한 배열
float temp_sum = 0; //온도값 총합 
float humi_sum = 0; //습도값 총합

void loop() {
  
  for(int i = 0; i < 6; i++)
  {
    temp_array[i] = mydht.readTemperature();
    humi_array[i] = mydht.readHumidity();
    temp_sum = temp_sum + temp_array[i];
    humi_sum = humi_sum + humi_array[i];
    delay(10000);
  }

  float temp = temp_sum /6;
  float humi = humi_sum /6;

  mylcd.setCursor(0,0);
  mylcd.print("Temp : ");
  mylcd.print(temp);
  mylcd.setCursor(0,1);
  mylcd.print("Humi : ");
  mylcd.print(humi);
  
  temp_sum = 0;
  humi_sum = 0;
  
}
