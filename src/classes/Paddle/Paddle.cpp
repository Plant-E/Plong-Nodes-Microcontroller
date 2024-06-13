#include <Arduino.h>
#include "Paddle.h"

Paddle::Paddle(int paddle_pin_1, int paddle_pin_2, int paddle_width, int pot_upper_limit){
    pin_1 = paddle_pin_1;
    pin_2 = paddle_pin_2;

    width = paddle_width;
    pot_limit = pot_upper_limit;
}

void Paddle::setResolutionWidth(int x){
    res_width = x;
}

int Paddle::getPosX1(){
    return getPosX(analogRead(pin_1));
}
int Paddle::getPosX2(){
    return getPosX(analogRead(pin_2));
}
int Paddle::getPosX(int pot){
    int usable_leds = res_width - (width * 2) - 1;
    float pot_fraction = (float)pot / (float)pot_limit;
    
    return round(pot_fraction * usable_leds) + width;
}

