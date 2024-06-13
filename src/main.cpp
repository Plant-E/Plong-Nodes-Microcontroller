#include <Arduino.h>
#include "classes/Display/Display.h"
#include "classes/Ball/Ball.h"
#include "classes/Paddle/Paddle.h"
#include "classes/Plong/Plong.h"

enum States{Start, Play, Game_Over,BootMode};
States CurrentState = BootMode;

Display display(10, 6, 90, 250); //x, y, visualization_distance, max_brightness
Ball ball(2); // Speed
Paddle paddle(34, 35, 1, 4095); //Pin 1, Pin 2, Paddle width ( padding on 1 side ), pot upper range
Plong plong(display, ball, paddle);

void setup() {
    Serial.begin(9600);
    randomSeed(analogRead(A0));

    pinMode(paddle.pin_1, INPUT);
    pinMode(paddle.pin_2, INPUT);

    plong.Start();
}

void loop() {

    // plong.iterate();
    // plong.consoleVisualisation();

  switch(CurrentState)
  {
    case BootMode:
      plong.Booting();
      break;
    case Start:
      plong.Start();
      break;
    case Play:
      plong.iterate();
      break;
    case Game_Over:
      plong.Game_Over();
      break;
  }
    delay(20);

}