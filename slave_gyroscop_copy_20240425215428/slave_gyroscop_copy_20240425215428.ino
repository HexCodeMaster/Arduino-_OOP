#include <Arduino.h>
#include "Src.h"

int previousDirection;
char previousChar; // Initialize previous character to 'S' for stop
Button button(buttonPin, pulsePin);

void setup() {
    Serial.begin(38400);
     Serial.println("Initialized");
    while (!Serial);

    bluetooth.begin(38400); // Initialize software serial for Bluetooth module
    gyroscope.begin();
    Serial.println("Initialized");

    // Initialize the button
    button.begin();

    // Additional debug statements
    Serial.println("Setup complete");
}

void loop() {
    // Update button state
    button.update();

    // Check if the button is pressed
    if (button.isPressed()) {
        // Send "1" over Bluetooth only if the previous character is not '0'
        if (previousChar != '0') {
            bluetooth.println("1");

            // Update previous character
            previousChar = '1';

            // Additional debug statements
            Serial.println("Sending character: 1");
        }
    } else {
        // Get motion data from the gyroscope
        int16_t ax, ay, az, gx, gy, gz;
        gyroscope.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

        // Calculate direction based on the motion data
        int direction = gyroscope.calculateDirection(ax, ay, az);

        // Convert direction to character
        char currentChar;
            switch (direction) {
            case 2:
                currentChar = '1'; // Forward
                Serial.println("Direction: Forward");
                break;
            case 1:
                currentChar = '2'; // Backward
                Serial.println("Direction: Backward");
                break;
            case 3:
                currentChar = '3'; // Left
                Serial.println("Direction: Left");
                break;
            case 4:
                currentChar = '4'; // Right
                Serial.println("Direction: Right");
                break;
            case 0:
                currentChar = '0'; // Stop
                Serial.println("Direction: Stop");
                break;
            default:
                currentChar = 'X'; // Unknown direction
                Serial.println("Direction: Unknown");
                break;
        }

        // Send character over Bluetooth only if it's different from the previous one and not '1'
        if (currentChar != previousChar && currentChar != '1') {
            bluetooth.println(currentChar);

            // Additional debug statements
            Serial.print("Sending character: ");
            Serial.println(currentChar);

            // Update previous character
            previousChar = currentChar;
        }
    }

    // Additional debug statements
    Serial.print("Direction: ");
    Serial.println(previousDirection);

    delay(100); // Adjust delay as needed
}
