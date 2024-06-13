#ifndef BALL_H
#define BALL_H

#include "../Display/Display.h"
#include "../Paddle/Paddle.h"


class Ball {
public:
    

    int speed;
    int direction;

    int pos_x;
    int pos_y;

    Ball(int speed);

    void move();
    int bounce(Display& display, Paddle& paddle);

    void setPosition(int x, int y);
    void setDirection(int direction);
    void setStartingDirection();

    void debug();

};

#endif
