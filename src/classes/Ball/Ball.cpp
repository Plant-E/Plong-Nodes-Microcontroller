#include <Arduino.h>
#include "Ball.h"

Ball::Ball() {
    speed = 10;
}
Ball::Ball(int set_speed) {
    speed = set_speed;
}

void Ball::move(){
    float angle_rad = radians(direction);

    float delta_x = speed * cos(angle_rad);
    float delta_y = speed * sin(angle_rad);

    pos_x += round(delta_x);
    pos_y += round(delta_y);
}
void Ball::bounce(){
    if(pos_y >= display.full_res_y){ //Bottom
        direction = 360 - direction;
        pos_y = display.full_res_y;
    }
    else if(pos_y <= 0){ //Top
        direction = 360 - direction;
        pos_y = 0;
    }
    else if(pos_x <= 0){ //Left
        // TODO: Check for paddle
        direction = 180 - direction;
        if(direction < 0){ direction += 360; };
        pos_x = 0;
    }
    else if(pos_x >= display.full_res_x){ // Right
        // TODO: Check for paddle
        direction = 180 - direction;
        if(direction < 0){  direction += 360; };
        pos_x = display.full_res_x;
    }
}

void Ball::setPosition(int x, int y){
    pos_x = x;
    pos_y = y;
}
void Ball::setDirection(int set_direction){
    direction = set_direction;
}
void Ball::setDisplay(Display display_instance){
    display = display_instance;
}
void Ball::setStartingDirection(){
    int player = random(2);

    if(player == 0){
        direction = random(-45, 45);
    }
    else{
        direction = random(135, 215);
    }

}