/*

    Copyright 2020 Alcatraz
    Date: 2020-11-15 

*/

#include "Configuration.h"
#include <inttypes.h>

class LaserSensor;
class VibrationSensor;
class MicSensor;

class BasicSensorD {
    friend class LaserSensor;
    friend class VibrationSensor;

private:
    uint8_t mPin = 0;
public:
    BasicSensorD(uint8_t pin) : mPin(pin) {}
    int8_t read();
};

class BasicSensorA {
    friend class MicSensor;

private:
    uint8_t mPin = 0;
public:
    BasicSensorA(uint8_t pin) : mPin(pin) {}
    int read();
};

class LaserSensor : BasicSensorD {
public:
    using BasicSensorD::BasicSensorD;
    using BasicSensorD::read;
};

class VibrationSensor : BasicSensorD {
public:
    using BasicSensorD::BasicSensorD;
    using BasicSensorD::read;
};

class MicSensor : BasicSensorA {
public:
    using BasicSensorA::BasicSensorA;
    using BasicSensorA::read;
};
