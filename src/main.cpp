#include <Arduino.h>
#include "classes/Display/Display.h"
#include "classes/Ball/Ball.h"
#include "classes/Plong/Plong.h"

Display display(10, 6, 90, 20); //x, y, visualization_distance, max_brightness
Ball ball(2); // Speed
Plong plong(display, ball);

void setup() {
    Serial.begin(9600);
    randomSeed(analogRead(A0));

    plong.start();
}

void loop() {
    plong.iterate();
    // plong.consoleVisualisation();
}