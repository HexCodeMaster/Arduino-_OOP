#ifndef BLUETOOTHUTILS_H
#define BLUETOOTHUTILS_H

#include <Arduino.h>
#include <SoftwareSerial.h>

class BluetoothUtils {
public:
    BluetoothUtils(SoftwareSerial& serial1, SoftwareSerial& serial2);
    void setup();
    char getSerial1();
    char getSerial2();

private:
    SoftwareSerial& btSerial1;
    SoftwareSerial& btSerial2;
};

#endif
