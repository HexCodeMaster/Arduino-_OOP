#ifndef GYROSCOPE_H
#define GYROSCOPE_H

#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

class Gyroscope {
public:
    Gyroscope(); // Constructor
    void begin(); // Initialization function
    void getMotion6(int16_t* ax, int16_t* ay, int16_t* az, int16_t* gx, int16_t* gy, int16_t* gz); // Get motion data
    int calculateDirection(int16_t ax, int16_t ay, int16_t az); // Declaration of calculateDirection method
private:
    Adafruit_MPU6050 mpu;
};

#endif
