#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>
#include "Ultrasonic.h"

class Sensor {
  public:
    Sensor(int frontTriggerPin, int frontEchoPin, int leftTriggerPin, int leftEchoPin, int rightTriggerPin, int rightEchoPin);
    void update();
    void printReadings();
    long getReading(int sensorIndex);

  private:
    Ultrasonic frontSensor;
    Ultrasonic leftSensor;
    Ultrasonic rightSensor;
    long frontDistance;
    long leftDistance;
    long rightDistance;
};

#endif
