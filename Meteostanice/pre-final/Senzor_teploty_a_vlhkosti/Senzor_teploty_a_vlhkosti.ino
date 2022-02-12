#include "DHT.h";

#define DHTPIN 8
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

float humidity;
float temp;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  humidity = dht.readHumidity();
  temp = dht.readTemperature();

  if(isnan(hum) || isnan(temp))
  {
    Serial.println("Chyba čtení");
  }
  else
  {
    Serial.print("Vlhkost: ");
    Serial.println(humidity);
    Serial.print("Teplota: ");
    Serial.print(temp);
    Serial.println(" Celsius"); 
  }

  delay(2000);
}
