#include "Display.h"
#include <FastLED.h>

#define NUM_LEDS 285
#define DATA_PIN 18

CRGB leds[NUM_LEDS];

Display::Display(int x, int y, int v_distance, int brightness) {
    res_x = x;
    res_y = y;

    visualisation_distance = v_distance;
    max_brightness = brightness;


    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
}

int Display::fullResX(){
    return res_x * 100;
}
int Display::fullResY(){
    return res_y * 100;
}

int Display::middleX(){
    return fullResX() / 2;
}
int Display::middleY(){
    return fullResY() / 2;
}

void Display::visualiseBall(int pos_x, int pos_y){
    for(int y = 0; y < res_y; y++){
        for(int x = 0; x < res_x; x++){
            
            int led;
            if (y % 2 == 0) {
                led = y * res_x + x;
            } else {
                led = y * res_x + (res_x - 1 - x);
            }

            float distance = sqrt(pow((x * 100 + 50) - pos_x, 2) + pow((y * 100 + 50) - pos_y, 2));

            if(distance > visualisation_distance){
                leds[led] = CRGB::Black;
            }
            else{
                int brightness = static_cast<int>(max_brightness * (1 - (distance / visualisation_distance)));
                leds[led] = CRGB(brightness, 0, 0);
            }

            // Serial.print("Distance: LED(x");
            // Serial.print((x * 100 + 50));
            // Serial.print(", ");
            // Serial.print((y * 100 + 50));
            // Serial.print(") to BALL(");
            // Serial.print(pos_x);
            // Serial.print(", ");
            // Serial.print(pos_y);
            // Serial.print(") is ");
            // Serial.println(distance);

        }
    }

    FastLED.show();
}


void Display::Animation_Players()
{

}

void Display::Animation_Score()
{
    
}

void Display::debug(){
    Serial.print("X:");
    Serial.print(res_x);
    Serial.print(" , Y:");
    Serial.println(res_y);

    Serial.print("full_X:");
    Serial.print(fullResX());
    Serial.print(" , full_Y:");
    Serial.println(fullResY());

    Serial.print("middle_X:");
    Serial.print(middleX());
    Serial.print(" , middle_Y:");
    Serial.println(middleY());
}

