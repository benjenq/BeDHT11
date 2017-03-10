/*
  BeDHT11.h - DHT11 Library code.
  Created by benjenq, March 2, 2017.

  Depends on the following Arduino libraries:
  - SimpleDHT required: https://github.com/winlinvip/SimpleDHT
*/

#ifndef BeDHT11_n
#define BeDHT11_n

#include "Arduino.h"
#include <SimpleDHT.h>

class BeDHT11 {
  public:
    BeDHT11(char *cname, int pin);
    void readValue();
    typedef void(*callbackread)(BeDHT11 bedht11);
    void setBeDHT11Callback(callbackread rcb);
    //protected:
    char *name;
    float temperatureCelsius;
    float temperatureFahrenheit;
    float humidity;
    byte data[40];
    bool readsuccess;

  private:
    int _pin;
    callbackread _rcb;
    byte _temp;
    byte _humi;
    SimpleDHT11 _dht11;
};
#endif
