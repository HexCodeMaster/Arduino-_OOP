#include "Signals.h"

// Constructor definition
Signals::Signals(int pin13) {
    Led = pin13;
    pinMode(Led, OUTPUT);
}


// Function to turn on the LED
void Signals::turnOnLed() {
    digitalWrite(Led, HIGH);
    delay (100);
     digitalWrite(Led, LOW);
    delay (50);
     digitalWrite(Led, HIGH);
    delay (100);
    digitalWrite(Led, LOW);
    delay (50);

}
void Signals::goingBack() {
    digitalWrite(Led, HIGH);
    delay (400);
     digitalWrite(Led, LOW);
    delay (400);
     digitalWrite(Led, HIGH);
    delay (400);
    digitalWrite(Led, LOW);
    delay (400);

}
void Signals::stopping() {
    digitalWrite(Led, HIGH);
    delay (400);
     digitalWrite(Led, LOW);
    delay (400);
     digitalWrite(Led, HIGH);
    delay (400);
    digitalWrite(Led, LOW);
    delay (400);
}
void Signals::blink(){
     digitalWrite(Led, HIGH);
    delay (80);
     digitalWrite(Led, LOW);
    delay (80);

}