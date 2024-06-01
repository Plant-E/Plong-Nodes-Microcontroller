#ifndef BALL_H
#define BALL_H

#include "../Display/Display.h"

class Ball {
public:
    
    Display display;

    int speed;
    int direction;

    int pos_x;
    int pos_y;

    Ball();
    Ball(int speed);

    void move();
    void bounce();

    void setPosition(int x, int y);
    void setDirection(int direction);
    void setDisplay(Display display);
    void setStartingDirection();

};

#endif
