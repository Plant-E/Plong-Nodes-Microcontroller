#include <Arduino.h>
#include "classes/Display/Display.h"
#include "classes/Ball/Ball.h"
#include "classes/Plong/Plong.h"

enum States{Start, Play, Game_Over,BootMode};
States CurrentState = BootMode;

Display display(10, 6, 90, 20); //x, y, visualization_distance, max_brightness
Ball ball(2); // Speed
Plong plong(display, ball);

void setup() {
    Serial.begin(9600);
    randomSeed(analogRead(A0));

    plong.Start();
}

void loop() {
    plong.Start();
    // plong.display.debug();
    plong.iterate();
    // plong.consoleVisualisation();

  // switch(CurrentState)
  // {
  //   case BootMode:
  //     Plong.Booting();
  //     break;
  //   case Start:
  //     Plong.Start();
  //     break;
  //   case Play:
  //     Plong.iterate();
  //     break;
  // }
  //   delay(20);

}