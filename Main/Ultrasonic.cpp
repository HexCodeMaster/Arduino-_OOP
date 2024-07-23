#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(int triggerPin, int echoPin) {
  this->triggerPin = triggerPin;
  this->echoPin = echoPin;
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

long Ultrasonic::measureDistance() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}
