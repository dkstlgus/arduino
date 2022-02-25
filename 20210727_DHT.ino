//온도, 습도 측정
#include <DHT.h>
#include <DHT_U.h>

DHT mydht(12,DHT11);


void setup() {
  mydht.begin();
  Serial.begin(9600);
  delay(2000);

}

void loop() {
  float temp = mydht.readTemperature();
  int humi = mydht.readHumidity();
  Serial.print("온도값 : ");
  Serial.print(temp);
  Serial.print("  ");
  Serial.print("습도값 : ");
  Serial.println(humi);
  delay(500);
}
