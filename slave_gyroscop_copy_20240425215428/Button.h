#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button {
  public:
    Button(int buttonPin, int pulsePin);
    void begin();
    void update();
    bool isPressed();
  
  private:
    int _buttonPin;
    int _pulsePin;
    bool _buttonState;
    bool _lastButtonState;
};

#endif
