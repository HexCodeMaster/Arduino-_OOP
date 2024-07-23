#include <Arduino.h>
#include "src.h"

    // Check for data from Bluetooth module 1
    char data1 = btUtils.getSerial1();
    char data2 = btUtils.getSerial2(); // Initialize data2 to '\0'


void setup() {
    Serial.begin(9600); // Initialize serial communication for debugging

    // Initialize BluetoothUtils
    btUtils.setup();
    motorController.stop();
}
void loop() {

    dataRecived();
    noDataRecived();


  
}

void dataRecived(){
      // Process commands from Bluetooth module 1 if available
    if (data1 != '\0') {
        switch (data1) {
            case '2':
                // Process command for moving forward
                motorController.forward();
                 Serial.println("Moving forward from Bluetooth module 1.");
                signal.turnOnLed();
               
                break;
            case '1':
                // Process command for moving backward
                motorController.backward();
                Serial.println("Moving backward from Bluetooth module 1.");
                signal.goingBack();
                  
                break;
            case '3':
                // Process command for turning left
                motorController.left();
                 Serial.println("Turning left from Bluetooth module 1.");
                signal.turnOnLed();
               
                break;
            case '4':
                // Process command for turning right
                motorController.right();
                 Serial.println("Turning right from Bluetooth module 1.");
                signal.turnOnLed();
               
                break;
            case '0':
                // Enter neural network mode
                    motorController.stop();
                    Serial.println("stopt from Bluetooth module 1.");
                signal.turnOnLed();
                
                break;
            default:
                // Serial.println("Unrecognized command from Bluetooth module 1.");
                break;
        }
    }

}
void noDataRecived(){

    // If no data from Bluetooth module 1, process data from module 2
   if (data2 != '\0') {
        switch (data2) {
            case '2':
                // Process command for moving forward
                motorController.forward();
                signal.turnOnLed();
                Serial.println("Moving forward from Bluetooth module 2.");
                break;
            case '1':
                // Process command for moving backward
                motorController.backward();
                signal.goingBack();
                Serial.println("Moving backward from Bluetooth module 2.");
                break;
            case '3':
                // Process command for turning left
                motorController.left();
                signal.turnOnLed();
                Serial.println("Turning left from Bluetooth module 2.");
                break;
            case '4':
                // Process command for turning right
                motorController.right();
                signal.turnOnLed();
                Serial.println("Turning right from Bluetooth module 2.");
                break;
            case '0':
                // STOP
                
                break;
            default:
                // Serial.println("Unrecognized command from Bluetooth module 2.");
                break;
        }
    }

}