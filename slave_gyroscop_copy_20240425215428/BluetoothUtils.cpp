#include "BluetoothUtils.h"

BluetoothUtils::BluetoothUtils(int rxPin, int txPin) : bluetooth(rxPin, txPin) {
    // Constructor definition
    // Initialize Bluetooth communication here using rxPin and txPin
}
 
void BluetoothUtils::setup() {
    // Any setup code for the Bluetooth module
}

void BluetoothUtils::sendCommand(char command) {
    bluetooth.write(command);
}

bool BluetoothUtils::isBluetoothConnected() {
    // Implementation for checking Bluetooth connection
    // Return true if connected, false otherwise
}
