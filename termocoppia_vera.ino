// this example is public domain. enjoy!
// https://learn.adafruit.com/thermocouple/

#include "max6675.h"

int thermoDO = 6;
int thermoCS = 5;
int thermoCLK = 4;

MAX6675 thermocouple(thermoCLK, thermoCS, thermoDO);

int VccPin = 3;
int GndPin = 2;
unsigned long old_millis=0;
unsigned long delta=6000;
int minuti=1;

void setup() {
  Serial.begin(9600);

  pinMode(VccPin, OUTPUT);
  pinMode(GndPin, OUTPUT);

  digitalWrite(VccPin, HIGH);
  digitalWrite(GndPin, LOW);

  Serial.println("MAX6675 test");
  Serial.println("Tempo ,C°");
  // wait for MAX chip to stabilize
  delay(500);
}

void loop() {
  // basic readout test, just print the current temp
  unsigned long now=millis();
  if(now>=old_millis+delta){
   //Serial.print("C = "); 
   Serial.print(minuti);
   Serial.print(",");
   Serial.println(thermocouple.readCelsius());
   //Serial.print("F = ");
   //Serial.println(thermocouple.readFahrenheit());
   old_millis=now;
   minuti=minuti+1;
  }
   // For the MAX6675 to update, you must delay AT LEAST 250ms between reads!
   delay(1000);
}
