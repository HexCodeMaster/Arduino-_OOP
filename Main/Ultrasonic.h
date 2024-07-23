#ifndef ULTRASONIC_H
#define ULTRASONIC_H

#include <Arduino.h>

class Ultrasonic {
  public:
    Ultrasonic(int triggerPin, int echoPin);
    long measureDistance();

  private:
    int triggerPin;
    int echoPin;
};

#endif
