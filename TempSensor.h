/*

    Copyright 2020 Alcatraz
    Date: 2020-11-15 

*/

#include <Wire.h>
#include <OneWire.h>
#include <DallasTemperature.h>

class TSensor
{
public:
    TSensor(uint8_t pin);

private:
    uint8_t mWirePin = 0;
    OneWire* mWire;
    DallasTemperature* mSensor;

public:
    float getTempC();
    float getTempF();
};
