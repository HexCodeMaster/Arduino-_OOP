// BluetoothUtils.h
#ifndef BLUETOOTHUTILS_H
#define BLUETOOTHUTILS_H

#include <Arduino.h>
#include <SoftwareSerial.h>

class BluetoothUtils {
public:
    BluetoothUtils(int rxPin, int txPin);
    void setup();
    char read(); // Function to read data from Bluetooth
    void sendCommand(char command);
    bool isBluetoothConnected();

private:
    SoftwareSerial bluetooth;
};

#endif
