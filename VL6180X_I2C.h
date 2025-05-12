#ifndef VL6180X_I2C_H
#define VL6180X_I2C_H

#include <Wire.h>

class VL6180X_I2C {
public:
    VL6180X_I2C(uint8_t address = 0x29);
    bool begin();
    uint8_t readRange();
    uint8_t readStatus();
    void configureSensor();

private:
    uint8_t i2cAddress;
    void writeRegister(uint16_t reg, uint8_t value);
    uint8_t readRegister(uint16_t reg);
};

#endif // VL6180X_I2C_H
