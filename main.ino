#include <DHT.h>
#include <LiquidCrystal_I2C.h>
const int dhtPin=32;
LiquidCrystal_I2C lcd(0x27,20,4);
#define DHTTYPE DHT22
DHT dht(dhtPin, DHTTYPE);

void setup() {
lcd.init();
lcd.backlight();
dht.begin();
}

void loop() {
  float temp= dht.readTemperature();
  float humidity=dht.readHumidity();

  lcd.setCursor(0, 0);     
  lcd.print("Temp: ");
  lcd.print(temp);         
  lcd.print("C");

  lcd.setCursor(0, 1);    
  lcd.print("Hum:  ");
  lcd.print(humidity);         
  lcd.print("%");

  delay(2000);


}
