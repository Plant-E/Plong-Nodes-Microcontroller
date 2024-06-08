#include <Arduino.h>
#include "Ball.h"

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
void Ball::bounce(int full_res_x, int full_res_y){
    if(pos_y >= full_res_y){ //Bottom
        direction = 360 - direction;
        pos_y = full_res_y;
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
    else if(pos_x >= full_res_x){ // Right
        // TODO: Check for paddle
        direction = 180 - direction;
        if(direction < 0){  direction += 360; };
        pos_x = full_res_x;
    }
}

void Ball::setPosition(int x, int y){
    pos_x = x;
    pos_y = y;

    debug();
}
void Ball::setDirection(int set_direction){
    direction = set_direction;
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

void Ball::debug(){
    Serial.print("pos_x: ");
    Serial.print(pos_x);
    Serial.print(", pox_y:");
    Serial.println(pos_y);
}