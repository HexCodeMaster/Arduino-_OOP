#ifndef SRC_H
#define SRC_H

#include "MotorController.h"
#include "Ultrasonic.h"
#include "BluetoothUtils.h"
#include "Signals.h"
#include "Sensor.h"  
#include "NeuralNetwork.h"  
#include <Wire.h>
#include <SoftwareSerial.h>

// Define pin constants
#define MOTOR_PIN_1 A0
#define MOTOR_PIN_2 A1
#define MOTOR_PIN_3 A2
#define MOTOR_PIN_4 A5

#define TRIG_PIN_1 2
#define ECHO_PIN_1 3

#define TRIG_PIN_2 4
#define ECHO_PIN_2 5

#define TRIG_PIN_3 6
#define ECHO_PIN_3 7

#define RX_PIN1 0
#define TX_PIN1 1
#define RX_PIN2 8  
#define TX_PIN2 9  

#define LED_PIN 13
#define MOTION_SENSOR_PIN 2

// Declare instances of your components
extern MotorController motorController;
extern Ultrasonic ultrasonicSensor1;
extern Ultrasonic ultrasonicSensor2;
extern Ultrasonic ultrasonicSensor3;
extern BluetoothUtils btUtils;
extern Signals signal;
extern Sensor sensor;
extern NeuralNetwork neuralNetwork;

#endif
