#include <Arduino.h>
#include "classes/Display/Display.h"
#include "classes/Ball/Ball.h"
#include "classes/Plong/Plong.h"


enum States{Start, Play, Game_Over,BootMode};
States CurrentState = BootMode;

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
     plong.display.debug();
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
    delay(20);

}