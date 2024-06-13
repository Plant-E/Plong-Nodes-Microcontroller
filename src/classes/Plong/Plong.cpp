#include <Arduino.h>
#include "Plong.h"

Plong::Plong(Display& display_instance, Ball& ball_instance, Paddle& paddle_instnace) 
    : display(display_instance), ball(ball_instance), paddle(paddle_instnace){

    game_state = false;

    paddle.setResolutionWidth(display.res_x);
}

void Plong::Start()
{
    //TODO: remove;
    game_state = true;

    ball.setPosition(display.middleX(), display.middleY());
    ball.setStartingDirection();
    //CurrentState = Play;  //Need to be added in main - overleg met PIOTR.
}

void Plong::iterate(){
    if(!game_state){ return; }

    ball.move();
    int paddle_scored = ball.bounce(display, paddle);

    //0 = Bounced, 1 = P1 scored, 2 = p2 scored
    if(paddle_scored){

        //TODO: Implement game state & score
        Start();
    }

    visualise();
}

void Plong::visualise(){
    
    //Set led stated of each component
    display.visualiseBall(ball.pos_x, ball.pos_y);
    display.visualizePaddle(paddle.getPosX1(), paddle.getPosX2(), paddle.width);

    //Display the leds
    display.displayLeds();
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