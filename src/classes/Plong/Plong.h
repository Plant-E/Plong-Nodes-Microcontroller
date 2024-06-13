#ifndef PLONG_H
#define PLONG_H

#include "Plong.h"
#include "../Display/Display.h"
#include "../Ball/Ball.h"
#include "../Paddle/Paddle.h"

class Plong {
public:

    bool game_state;


    Display& display;
    Ball& ball;
    Paddle& paddle;

    Plong(Display& display, Ball& ball, Paddle& paddle);
    
    void iterate();
    void Booting();
    void Start();
    void Game_Over();
    void visualise();

    void consoleVisualisation();

};

#endif
