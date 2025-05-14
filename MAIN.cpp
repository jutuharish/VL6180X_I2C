#include "VL6180X_I2C.h"
#include "pico/stdlib.h"
#include "hardware/i2c.h"

#define I2C_PORT i2c0
#define SDA_PIN 4
#define SCL_PIN 5

VL6180X_I2C sensor(0x29);

int main() {
    stdio_init_all();
    i2c_init(I2C_PORT, 100 * 1000);
    gpio_set_function(SDA_PIN, GPIO_FUNC_I2C);
    gpio_set_function(SCL_PIN, GPIO_FUNC_I2C);
    gpio_pull_up(SDA_PIN);
    gpio_pull_up(SCL_PIN);

    printf("VL6180X I2C Example\n");

    sensor.begin();
    sensor.configureSensor();

    while (1) {
        uint8_t distance = sensor.readRange();
        uint8_t status = sensor.readStatus();
        printf("Distance: %d mm, Status: %d\n", distance, status);
        sleep_ms(500);
    }
}
