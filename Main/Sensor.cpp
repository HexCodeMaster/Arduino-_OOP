#include "Sensor.h"

Sensor::Sensor(int frontTriggerPin, int frontEchoPin, int leftTriggerPin, int leftEchoPin, int rightTriggerPin, int rightEchoPin)
    : frontSensor(frontTriggerPin, frontEchoPin), leftSensor(leftTriggerPin, leftEchoPin), rightSensor(rightTriggerPin, rightEchoPin) {
}

void Sensor::update() {
    frontDistance = frontSensor.measureDistance();
    leftDistance = leftSensor.measureDistance();
    rightDistance = rightSensor.measureDistance();
}

void Sensor::printReadings() {
    Serial.print("Front Distance: ");
    Serial.println(frontDistance);
    Serial.print("Left Distance: ");
    Serial.println(leftDistance);
    Serial.print("Right Distance: ");
    Serial.println(rightDistance);
}

long Sensor::getReading(int sensorIndex) {
    switch (sensorIndex) {
        case 0:
            return frontDistance;
        case 1:
            return leftDistance;
        case 2:
            return rightDistance;
        default:
            return -1; // Invalid sensor index
    }
}
