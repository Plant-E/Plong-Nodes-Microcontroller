#include <Arduino.h>
#include "classes/Display/Display.h"
#include "classes/Ball/Ball.h"
#include "classes/Plong/Plong.h"

enum States{Start, Play, Game_Over,BootMode};
States CurrentState = BootMode;

Plong plong = Plong(
  Display(10, 1, 100, 50),
  Ball(5)
);





void setup() {
    Serial.begin(9600);
    randomSeed(analogRead(A0));

    plong.start();
    plong.ball.setDirection(0);
}

void loop() {
    plong.iterate();
    delay(25);
    // plong.consoleVisualisation();
  switch(CurrentState)
  {
    case BootMode:
      Plong.Booting();
      break;
    case Start:
      Plong.Start();
      break;
    case Play:
      Plong.iterate();
      break;
    case Game_Over:
      Plong.Game_Over();
      break;
  }

}