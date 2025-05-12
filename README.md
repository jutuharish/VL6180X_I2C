# VL6180X I2C Interface

This library provides an I2C interface for the VL6180X time-of-flight sensor. It includes functions to initialize the sensor, read the range, and check sensor status.

## Features

* I2C communication protocol
* Read distance in millimeters
* Check sensor status

## Hardware Connections

* VCC → 3.3V/5V
* GND → GND
* SDA → A4 (Arduino)
* SCL → A5 (Arduino)

## Usage

1. Include the header file:

   ```cpp
   #include "VL6180X_I2C.h"
   ```
2. Create an instance and initialize:

   ```cpp
   VL6180X_I2C sensor(0x29);
   sensor.begin();
   sensor.configureSensor();
   ```
3. Read distance:

   ```cpp
   uint8_t distance = sensor.readRange();
   ```

## Dependencies

* Wire.h

## License

MIT License
