#include "Gyroscope.h"
#include <Wire.h>

Gyroscope::Gyroscope() {}

void Gyroscope::begin() {
    if (!mpu.begin()) {
        Serial.println("Failed to find MPU6050 chip");
        while (1) {
            delay(10);
        }
    }
    Serial.println("MPU6050 Found!");

    // Set up motion detection
    mpu.setHighPassFilter(MPU6050_HIGHPASS_0_63_HZ);
    mpu.setMotionDetectionThreshold(1);
    mpu.setMotionDetectionDuration(20);
    mpu.setInterruptPinLatch(true); // Keep it latched.  Will turn off when reinitialized.
    mpu.setInterruptPinPolarity(true);
    mpu.setMotionInterrupt(true);
}

void Gyroscope::getMotion6(int16_t* ax, int16_t* ay, int16_t* az, int16_t* gx, int16_t* gy, int16_t* gz) {
    sensors_event_t accel, gyro, temp;
    mpu.getEvent(&accel, &gyro, &temp); // Get accelerometer and gyroscope events

    // Extract accelerometer data
    *ax = accel.acceleration.x;
    *ay = accel.acceleration.y;
    *az = accel.acceleration.z;

    // Extract gyroscope data
    *gx = gyro.gyro.x;
    *gy = gyro.gyro.y;
    *gz = gyro.gyro.z;
}

int Gyroscope::calculateDirection(int16_t ax, int16_t ay, int16_t az) {
    // Define dead zone and minimum change thresholds
    const int16_t deadZoneThreshold = 0;
    const int16_t minChangeThreshold = 2;

    // Initialize direction to no movement
    int direction = 0;

    // Check if the absolute value of ax is greater than the dead zone threshold and minimum change threshold
    if (abs(ax) > deadZoneThreshold && abs(ax) > minChangeThreshold) {
        // Determine direction based on the sign of ax
        direction = (ax > 0) ? 2 : 1; // Forward or Backward
    }

    // Check if the absolute value of ay is greater than the dead zone threshold and minimum change threshold
    if (abs(ay) > deadZoneThreshold && abs(ay) > minChangeThreshold) {
        // Determine direction based on the sign of ay
        int leftOrRight = (ay > 0) ? 4 : 3; // Left or Right

        // Prioritize left or right movements over forward or backward movements if ay magnitude is larger
        if (abs(ay) > abs(ax)) {
            direction = leftOrRight;
        }
    }

    return direction;
}
