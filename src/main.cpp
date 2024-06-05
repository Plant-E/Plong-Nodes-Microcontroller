#include <Arduino.h>
#include "classes/Display/Display.h"
#include "classes/Ball/Ball.h"
#include "classes/Plong/Plong.h"

Plong plong = Plong(
  Display(10, 1),
  Ball(25)
);





void setup() {
    Serial.begin(9600);
    randomSeed(analogRead(A0));

    plong.start();
    plong.ball.setDirection(0);
}

void loop() {
    plong.iterate();
    plong.consoleVisualisation();
}