#include <Arduino.h>
#include "Plong.h"

Plong::Plong(Display& display_instance, Ball& ball_instance) : display(display_instance), ball(ball_instance){
    game_state = false;
}

void Plong::Start()
{

    ball.setPosition(display.middleX(), display.middleY());
    // ball.setStartingDirection();

    display.Animation_Game_Over_Mode(1);
    //CurrentState = Play;  //Need to be added in main - overleg met PIOTR.
}

void Plong::iterate(){

    ball.move();
    ball.bounce(display.fullResX(), display.fullResY());

    visualise();
}

void Plong::visualise(){
    display.visualiseBall(ball.pos_x, ball.pos_y);
}

void Plong::consoleVisualisation(){
    Serial.print("X: ");
    Serial.print(ball.pos_x);
    Serial.print(" Y: ");
    Serial.print(ball.pos_y);
    Serial.print(" Direction:");
    Serial.print(ball.direction);
    Serial.println(" ");

    // Print the top border
    for (int i = 0; i < display.res_x + 2; i++) {
        Serial.print("-");
    }
    Serial.println();

    for (int y = 0; y < display.res_y; y++) {
        Serial.print("|");

        for (int x = 0; x < display.res_x; x++) {
            if (ball.pos_x >= (x * 100) && ball.pos_x < ((x + 1) * 100) &&
                ball.pos_y >= (y * 100) && ball.pos_y < ((y + 1) * 100)) {
                Serial.print("*");
            } else {
                Serial.print(" ");
            }
        }

        Serial.println("|");
    }

    // Print the bottom border
    for (int i = 0; i < display.res_x + 2; i++) {
        Serial.print("-");
    }
    Serial.println();
}