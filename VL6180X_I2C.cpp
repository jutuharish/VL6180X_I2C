#include "VL6180X_I2C.h"

VL6180X_I2C::VL6180X_I2C(uint8_t address) : i2cAddress(address) {}

bool VL6180X_I2C::begin() {
    Wire.begin();
    // Check if sensor is responding
    Wire.beginTransmission(i2cAddress);
    return (Wire.endTransmission() == 0);
}

void VL6180X_I2C::configureSensor() {
    // Example configuration (adjust as needed)
    writeRegister(0x0207, 0x01);
    writeRegister(0x0208, 0x01);
}

uint8_t VL6180X_I2C::readRange() {
    return readRegister(0x62);
}

uint8_t VL6180X_I2C::readStatus() {
    return readRegister(0x4F);
}

void VL6180X_I2C::writeRegister(uint16_t reg, uint8_t value) {
    Wire.beginTransmission(i2cAddress);
    Wire.write((reg >> 8) & 0xFF);  // MSB
    Wire.write(reg & 0xFF);         // LSB
    Wire.write(value);
    Wire.endTransmission();
}

uint8_t VL6180X_I2C::readRegister(uint16_t reg) {
    Wire.beginTransmission(i2cAddress);
    Wire.write((reg >> 8) & 0xFF);  // MSB
    Wire.write(reg & 0xFF);         // LSB
    Wire.endTransmission();
    
    Wire.requestFrom(i2cAddress, (uint8_t)1);
    return Wire.available() ? Wire.read() : 0;
}
