#include "Button.h"

Button::Button(int buttonPin, int pulsePin) {
  _buttonPin = buttonPin;
  _pulsePin = pulsePin;
}

void Button::begin() {
  pinMode(_buttonPin, INPUT_PULLUP);
  pinMode(_pulsePin, OUTPUT);
}

void Button::update() {
  _buttonState = digitalRead(_buttonPin);
  
  // Check if the button state has changed
  if (_buttonState != _lastButtonState) {
    // If the button is pressed (LOW state), activate pulse
    if (_buttonState == LOW) {
      digitalWrite(_pulsePin, HIGH);
    }
    // If the button is released (HIGH state), deactivate pulse
    else {
      digitalWrite(_pulsePin, LOW);
    }
    _lastButtonState = _buttonState;  // Update the previous button state
  }
}

bool Button::isPressed() {
  return _buttonState == LOW;
}








