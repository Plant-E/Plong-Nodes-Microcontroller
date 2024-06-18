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
int Ball::bounce(Display& display, Paddle& paddle){
    if(pos_y <= 0){ // Top, Paddle 1
        if(pos_x < (paddle.getPosX1() - paddle.width) * 100 || pos_x > (paddle.getPosX1() + paddle.width + 1) * 100){ return 2; } //Paddle 2 scores

        direction = 360 - direction;
        pos_y = 100;
    }
    else if(pos_y >= display.fullResY()){ // Bottom, Paddle 2
        if(pos_x < (paddle.getPosX2() - paddle.width) * 100 || pos_x > (paddle.getPosX2() + paddle.width + 1) * 100){ return 1; }

        direction = 360 - direction;
        pos_y = display.fullResY();
    }
    else if(pos_x <= 0){ // Left
        direction = 180 - direction;
        if(direction < 0){ direction += 360; };
        pos_x = 0;
    }
    else if(pos_x >= display.fullResX()){ // Right
        direction = 180 - direction;
        if(direction < 0){  direction += 360; };
        pos_x = display.fullResX();
    }

    return 0;
}

void Ball::setPosition(int x, int y){
    pos_x = x;
    pos_y = y;
}
void Ball::setDirection(int set_direction){
    direction = set_direction;
}
void Ball::setStartingDirection(){
    int player = random(2);
    int left_right = random(2);
    int offset = random(15, 45);

    if(player == 0){
        direction = 90;
    }
    else{
        direction = 270;
    }

    //To avoid the ball going vertically up or down
    if(left_right == 0){
        direction = direction - offset;
    }
    else{
        direction = direction + offset;
    }

}

void Ball::debug(){
    Serial.print("pos_x: ");
    Serial.print(pos_x);
    Serial.print(", pox_y:");
    Serial.println(pos_y);
}
