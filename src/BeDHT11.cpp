#include "BeDHT11.h"

BeDHT11::BeDHT11(char *cname, int pin) {
  pinMode(pin,INPUT);
  this->_pin = pin;
  this->name = cname;
  this->readsuccess = false;
}

void BeDHT11::readValue() {
  if (_dht11.read(_pin, &_temp, &_humi, data)) {
    Serial.println("Read DHT11 failed.");
    readsuccess = false;
    _rcb(*this); //Read failed
  }
  else {
    temperatureCelsius = (float)_temp;
    temperatureFahrenheit = temperatureCelsius * 1.8 + 32;
    humidity = (float)_humi;
    readsuccess = true;
    _rcb(*this); //Read success
  }
}


void BeDHT11::setBeDHT11Callback(callbackread rcb) {
  _rcb = rcb;
}
