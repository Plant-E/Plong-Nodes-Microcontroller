#include <Arduino.h>
#include "classes/Display/Display.h"
#include "classes/Ball/Ball.h"
#include "classes/Plong/Plong.h"

Display display(15, 19, 100, 50);
Ball ball(20);
Plong plong(display, ball);

void setup() {
    Serial.begin(9600);
    randomSeed(analogRead(A0));

    plong.start();
}

void loop() {
    plong.iterate();
    // plong.display.debug();
    // plong.consoleVisualisation();
    delay(20);
}