#include "Display.h"
#include <FastLED.h>

#define NUM_LEDS 10
#define DATA_PIN 18

CRGB leds[NUM_LEDS];

Display::Display() {
    res_x = 0;
    res_y = 0;

    visualisation_distance = 0;
    max_brightness = 0;
}
Display::Display(int x, int y, int v_distance, int brightness) {
    res_x = x;
    res_y = y;

    full_res_x = x * 100;
    full_res_y = y * 100;

    visualisation_distance = v_distance;
    max_brightness = brightness;


    FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
}

int Display::middleX(){
    return full_res_x / 2;
}
int Display::middleY(){
    return full_res_y / 2;
}

void Display::visualiseBall(int pos_x, int pos_y){
    for(int y = 0; y < res_y; y++){
        for(int x = 0; x < res_x; x++){
            
            int led = y * res_y + x;
            if(y % 2 == 1){
                led = (y + 1) * res_y - x;
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
