#include "BluetoothUtils.h"

BluetoothUtils::BluetoothUtils(SoftwareSerial& serial1, SoftwareSerial& serial2)
    : btSerial1(serial1), btSerial2(serial2) {}

void BluetoothUtils::setup() {
    btSerial1.begin(9600);
    btSerial2.begin(9600);
}

char BluetoothUtils::getSerial1() {
    if (btSerial1.available() > 0) {
      char data1 = btSerial1.read();
        return btSerial1.read();
    }
    return '\0';

}

char BluetoothUtils::getSerial2() {
    if (btSerial2.available() > 0) {
        return btSerial2.read();
    }
    return '\0';
}
