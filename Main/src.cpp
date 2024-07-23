#include "src.h"

// Define instances of your components
MotorController motorController(MOTOR_PIN_1, MOTOR_PIN_2, MOTOR_PIN_3, MOTOR_PIN_4);
Ultrasonic ultrasonicSensor1(TRIG_PIN_1, ECHO_PIN_1);
Ultrasonic ultrasonicSensor2(TRIG_PIN_2, ECHO_PIN_2);
Ultrasonic ultrasonicSensor3(TRIG_PIN_3, ECHO_PIN_3);
Signals signal(LED_PIN);
Sensor sensor(TRIG_PIN_1, ECHO_PIN_1, TRIG_PIN_2, ECHO_PIN_2, TRIG_PIN_3, ECHO_PIN_3);
NeuralNetwork neuralNetwork(new int[4]{3, 5, 4, 2}, 4);

// Initialize Bluetooth modules
SoftwareSerial btSerial1(RX_PIN1, TX_PIN1);
SoftwareSerial btSerial2(RX_PIN2, TX_PIN2);

// Initialize BluetoothUtils with SoftwareSerial instances
BluetoothUtils btUtils(btSerial1, btSerial2);
