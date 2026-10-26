#ifndef I2C_MANAGER_H
#define I2C_MANAGER_H

#include <Arduino.h>
#include <Wire.h>
#include "config.h"

inline void initI2C() {
    Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);
    Wire.setClock(I2C_FREQUENCY_HZ);
    Serial.printf("[I2C] bus listo SDA=%d SCL=%d\n", I2C_SDA_PIN, I2C_SCL_PIN);
}

inline void scanI2C() {
    uint8_t count = 0;
    Serial.println(F("[I2C] escaneando 0x01 a 0x7F"));
    for (uint8_t addr = 1; addr < 127; addr++) {
        Wire.beginTransmission(addr);
        if (Wire.endTransmission() == 0) {
            Serial.printf("[I2C] dispositivo en 0x%02X\n", addr);
            count++;
        }
    }
    Serial.printf("[I2C] escaneo completo, %d dispositivos\n", count);
}

inline void testI2CDevice() {
    Wire.beginTransmission(OLED_I2C_ADDRESS);
    if (Wire.endTransmission() == 0) {
        Serial.printf("[POST] OLED en 0x%02X responde\n", OLED_I2C_ADDRESS);
    } else {
        Serial.printf("[POST] FATAL: OLED en 0x%02X no responde, arranque detenido\n", OLED_I2C_ADDRESS);
        while (true) {
            delay(1000);
        }
    }
}

#endif