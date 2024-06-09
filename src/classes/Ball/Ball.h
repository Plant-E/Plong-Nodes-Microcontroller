#ifndef BALL_H
#define BALL_H

class Ball {
public:
    

    int speed;
    int direction;

    int pos_x;
    int pos_y;

    Ball(int speed);

    void move();
    void bounce(int full_res_x, int full_res_y);

    void setPosition(int x, int y);
    void setDirection(int direction);
    void setStartingDirection();

    void debug();

};

#endif
