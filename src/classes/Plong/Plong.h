#ifndef PLONG_H
#define PLONG_H

#include "Plong.h"
#include "../Display/Display.h"
#include "../Ball/Ball.h"
#include "../Paddle/Paddle.h"
#include "../Heartbeat/Heartbeat.h"

class Plong {
public:

    bool game_state;

    Display& display;
    Ball& ball;
    Paddle& paddle;
    Heartbeat& heartbeat;

    Plong(Display& display, Ball& ball, Paddle& paddle, Heartbeat& heartbeat);
    void Setup();
    int Booting();
    int Start();
    int PlayMode();
    void visualise();

    void consoleVisualisation();


private:

    int Score_Player_1;
    int Score_Player_2;
};
#endif
