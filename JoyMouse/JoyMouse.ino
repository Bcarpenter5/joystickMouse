// this is my personal joystick library
#include "control.h"
/**
 * This example turns the ESP32 into a Bluetooth LE mouse that continuously moves the mouse.
 */
#include <BleMouse.h>

#define xPin 6
#define yPin 7
#define cPin 8

const int moveSpeed = 10; // the speed of the mouse movement

// define the movement direction
int x;
int y;
bool c;


BleMouse bleMouse;

control joystick(xPin, yPin, cPin);
void setup() {

    Serial.begin(115200);
    Serial.println("Starting BLE work!");
    bleMouse.begin();
}

void loop() {
    // initialize values
    x = 0;
    y = 0;
    c = false;
    // this is to check if the mouse is connected
    if(bleMouse.isConnected()) {

        c = joystick.AnalogMove(&x,&y,moveSpeed);
        bleMouse.move(x, y);
        // check if the button is pressed
        if(c){
            bleMouse.click(MOUSE_LEFT);
        }
    }
}
