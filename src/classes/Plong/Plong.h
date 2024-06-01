#ifndef PLONG_H
#define PLONG_H

#include "Plong.h"
#include "../Display/Display.h"
#include "../Ball/Ball.h"

class Plong {
public:

    bool game_state;

    Display display;
    Ball ball;

    Plong(Display display, Ball ball);
    void iterate();
    void start();

    void consoleVisualisation();

};

#endif
