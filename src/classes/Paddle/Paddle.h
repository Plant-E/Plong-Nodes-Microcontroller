#ifndef PADDLE_H
#define PADDLE_H

#include "../Display/Display.h"


class Paddle {
public:
    int pin_1;
    int pin_2;

    int width;
    int pot_limit;

    int res_width;

    Paddle(int paddle_1_pin, int paddle_2_pin, int width);
    
    void setResolutionWidth(int res_x);

    int getPosX1();
    int getPosX2();
    int getPosX(int pot);

};

#endif
