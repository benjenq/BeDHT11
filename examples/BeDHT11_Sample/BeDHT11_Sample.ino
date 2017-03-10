
/*
  BeDHT11_Sample.ino - Sample Code of BeDHT11 Library .
  Created by benjenq, March 2, 2017.

  BeDHT11 is a DHT11 library with name parameter and call back method.

  Depends on the following Arduino libraries:
  - SimpleDHT required: https://github.com/winlinvip/SimpleDHT

  How to Use:
  BeDHT11([Name],[#pin]) , can assign name for each DHT11 and callback with name

  Sample:
  BeDHT11 beSensor("MyRoom",2); //-->Use name MyRoom and DHT11 was plun on pin 2

  //Set the instance call back
  beSensor.setBeDHT11Callback(readSensorCallBack);
  void readSensorCallBack(BeDHT11 bedht) {...} //

  beSensor.readValue(); // when read value success then call readSensorCallBack method
*/
#include <BeDHT11.h>

BeDHT11 beSensor("MyRoom", 2); //BeDHT11([Name],[#pin])

void readSensorCallBack(BeDHT11 bedht) {
  if (bedht.readsuccess) {
    Serial.println("=================================");
    Serial.print(bedht.name);
    Serial.print(":");
    Serial.print(bedht.temperatureCelsius); Serial.print(" *C, ");
    Serial.print(bedht.temperatureFahrenheit); Serial.print(" *F, ");
    Serial.print(bedht.humidity); Serial.println(" %");
    Serial.println("==Sample RAW Bits: ");

    for (int i = 0; i < 40; i++) {
      Serial.print((int)bedht.data[i]);
      if (i > 0 && ((i + 1) % 4) == 0) {
        Serial.print(' ');
      }
    }
    Serial.println("");

  }
  else
  {
    Serial.println("===ReadSensor Failed!!=====");
  }

}

void setup() {
  Serial.begin(115200);
  beSensor.setBeDHT11Callback(readSensorCallBack);
}

void loop() {
  // start working...
  beSensor.readValue();

  delay(2000);
}
