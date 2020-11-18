#include "TempSensor.h"

TSensor::TSensor(uint8_t pin) : mWirePin(pin) {
    mWire = new OneWire(pin);
    mSensor = new DallasTemperature(mWire);
    Wire.begin();
    mSensor->begin();
}

float TSensor::getTempC() {
    mSensor->requestTemperatures();
    return mSensor->getTempCByIndex(0);
}

float TSensor::getTempF() {
    mSensor->requestTemperatures();
    return mSensor->getTempFByIndex(0);
}
