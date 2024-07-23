#ifndef MotorController_h
#define MotorController_h

#include <Arduino.h>

class MotorController {
  private:
    int in1, in2, in3, in4;

  public:
    MotorController(int pin1, int pin2, int pin3, int pin4);
    void forward();
    void backward();
    void left();
    void right();
    void stop();
};

#endif
