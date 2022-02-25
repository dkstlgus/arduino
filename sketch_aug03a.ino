#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <DHT_U.h>
#include <SI114X.h>

DHT mydht(12,DHT11);
SI114X mylight = SI114X();
LiquidCrystal_I2C mylcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  mylcd.init();
  mylcd.backlight();
  
  mydht.begin();

  Serial.println("Beginning Si1145!");
  mylcd.setCursor(0, 0);
  mylcd.print ("Beginning Si1145");
  while(!mylight.Begin())
  {
    Serial.println("Si1145 is not ready!");
    delay(1000);
  }
  mylcd.setCursor(0, 1);
  Serial.println("Si1145 is ready!");
  mylcd.print ("Si1145 is ready!");
  delay(2000);
  mylcd.clear();
}

void loop() {
  float temp = mydht.readTemperature();
  int humi = mydht.readHumidity();

  int vl = mylight.ReadVisible();
  int ir = mylight.ReadIR();
  float uv = mylight.ReadUV()/100;

  Serial.print  ("온도값 : ");
  Serial.print  (temp);
  Serial.print  ("    ");
  Serial.print  ("습도값 : ");
  Serial.println  (humi);

  delay(1000);

  Serial.print  ("기시광선 : ");
  Serial.print  (vl);
  Serial.print  ("    ");
  Serial.print  ("적외선 : ");
  Serial.print  (ir);
  Serial.print  ("    ");
  Serial.print  ("자외선 : ");
  Serial.println  (uv);

  if(analogRead(A0) < 500)
  {
    mylcd.setCursor(0,0);
    mylcd.print("Temp : ");
    mylcd.print(temp);
    mylcd.setCursor(0,1);
    mylcd.print("humi : ");
    mylcd.print(humi);
  }
  else  
  {
    mylcd.setCursor(0,0);
    mylcd.print("visible : ");
    mylcd.print(vl);
    mylcd.setCursor(0,1);
    mylcd.print("IR : ");
    mylcd.print(ir);
    mylcd.print("  ");
    mylcd.print("UV : ");
    mylcd.print(uv);
  }
  delay(1000);
}
