#ifndef DISPLAY_H
#define DISPLAY_H

#include <FastLED.h>

class Display {
public:
    int res_x;
    int res_y;

    int visualisation_distance;
    int max_brightness;

    Display(int x, int y, int visualisation_distance, int max_brightness);

    int fullResX();
    int fullResY();

    int middleX();
    int middleY();

    void visualiseBall(int int_x, int pos_y);
    void visualizePaddle(int x_1, int x_2, int width);
    
    void setLed(int x, int y, CRGB color);
    void displayLeds();

    void Animation_Score();
    void Animation_Players();

    void debug();

};

#endif
