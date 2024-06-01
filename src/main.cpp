#include <Arduino.h>
#include "classes/Display/Display.h"
#include "classes/Ball/Ball.h"
#include "classes/Plong/Plong.h"

Plong plong = Plong(
  Display(30, 10),
  Ball(150)
);

void setup() {
    Serial.begin(9600);
    randomSeed(analogRead(A0));

    //Based on user input
    plong.start();
}

void loop() {
    plong.iterate();
    plong.consoleVisualisation();

    delay(200);
}