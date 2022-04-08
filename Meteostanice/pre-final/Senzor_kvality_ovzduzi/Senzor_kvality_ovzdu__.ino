#include "MQ135.h"

#define pinA A0
#define pinD 2

MQ135 senzorMQ = MQ135(pinA);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(pinD), prerus, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
  float ppm = senzorMQ.getPPM(); //parts per million, also can be mg/L

  long cas = millis()/1000;

  Serial.print("Koncentrace plynu: ");
  Serial.print(ppm);
  Serial.print(" ppm | cas od spusteni Arduina: ");
  Serial.print(cas/60);
  Serial.print("minut");
  Serial.print(cas%60);
  Serial.println("sekund.");

  delay(3000);
}

void prerus() {
  Serial.println("Detekovano preruseni hranice"); //velmi spatne ovzdusi
