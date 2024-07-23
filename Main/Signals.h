#ifndef SIGNALS_H
#define SIGNALS_H

#include <Arduino.h>

class Signals {
private:
    int Led;

public:
    Signals(int pin13); // Constructor
    void turnOnLed();
    void goingBack(); // Function to turn on the LED
    void stopping();
    void blink();
};



#endif
