#ifndef SRC_H
#define SRC_H

// Define your desired RX and TX pins for Bluetooth communication
#define TX_PIN 8
#define RX_PIN 9
const int buttonPin = 2; 
const int pulsePin = 3; 

#include "BluetoothUtils.h" // Include the header file for your Bluetooth utility functions
#include "Gyroscope.h" // Include the header file for your gyroscope library
#include "Button.h"

extern BluetoothUtils btUtils; // Declare the Bluetooth utility object
extern Gyroscope gyroscope; // Declare the gyroscope object
extern SoftwareSerial bluetooth;// RX, TX
extern Button button; // Declare the button object

#endif

