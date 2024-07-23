#include "src.h"

// Initialize BluetoothUtils object with RX and TX pins
BluetoothUtils btUtils(RX_PIN, TX_PIN);

// Initialize Gyroscope object
Gyroscope gyroscope;
SoftwareSerial bluetooth(RX_PIN, TX_PIN);  // RX, TX