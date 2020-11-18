#include "BasicSensors.h"
#include <Arduino.h>

int8_t BasicSensorD::read() {
    return digitalRead(mPin);
}

int BasicSensorA::read() {
    return (int)analogRead(mPin);
}
