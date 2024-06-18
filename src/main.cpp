#include <Arduino.h>
#include "classes/Display/Display.h"
#include "classes/Ball/Ball.h"
#include "classes/Paddle/Paddle.h"
#include "classes/Plong/Plong.h"
#include "classes/Heartbeat/Heartbeat.h"

enum States{Start, Play, Game_Over,BootMode};
States CurrentState = BootMode;

Display display(15, 18, 120, 255); //x, y, visualization_distance, max_brightness
Ball ball(25); // Speed
Paddle paddle(35, 34, 2); //Pin 1, Pin 2, Paddle width ( padding per side )
Heartbeat heartbeat(32,25);// Pin 32 Hearbeatsensor 1, Pin 33 Hearbeatsensor 2
Plong plong(display, ball, paddle, heartbeat);


void setup() {
    Serial.begin(115200);
    randomSeed(analogRead(A0));
    pinMode(paddle.pin_1, INPUT);
    pinMode(paddle.pin_2, INPUT);
    heartbeat.Initialize();
    plong.Setup();
}

void loop() {
  switch(CurrentState)
  {
    case BootMode:
      if(plong.Booting() == 1){CurrentState = Start;};//Game start in Boots when heartbeat detects move to Start.
      break;
    case Start: //In start the game startsup when it did run a startup program it goes to play.
      if(plong.Start() == 1){CurrentState = Play;}
      else if(plong.Start() == 2){CurrentState = BootMode;} // when the player hits the 3 points it shows the winner and goes back to the BootMode
      break;
    case Play: // when it scores it goes back to the start to show the player and the score
      if(plong.PlayMode() == 1){CurrentState = Start;}
      break;
  }
}