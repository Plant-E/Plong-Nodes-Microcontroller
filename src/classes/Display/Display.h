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
    void Animation_Score(int Player_1_Score, int Player_2_Score);
    void Animation_Game_Over_Mode(int Winner);
    
    void debug();

private:
    void Clear_Screen();
    unsigned int Players_Array[44] = {90,91,92,96,98,99,100,104,107,111,114,119,122,126,129,134,136,141,144,149,150,154,155,156,159,162,163,164,165,167,169,171,174,175,177,179,181,184,185,186,189,192,193,194};
    unsigned int Player_1_Zero[14] = {114,115,116,129,131,144,146,159,161,174,176,189,190,191};
    unsigned int Player_2_Zero[14] = {108,109,110,123,125,138,140,153,155,168,170,183,184,185};
    unsigned int Player_1_One[9] = {114,115,116,130,145,160,175,176,190};
    unsigned int Player_2_One[9] = {108,109,110,124,139,154,169,170,184};
    unsigned int Player_1_Two[10] = {99,100,101,116,131,145,159,174,176,190};
    unsigned int Player_2_Two[10] = {93,94,95,110,125,139,153,168,170,184};
    unsigned int Player_1_Three[20] = {108,109,110,116,124,131,139,146,154,159,160,161,169,170,174,176,184,189,190,191};
    unsigned int Player_2_Three[20] = {108,109,110,116,125,131,139,146,153,159,160,161,168,170,174,176,184,189,190,191};
    unsigned int Winner_Player[51] = {109,110,111,112,113,114,115,124,125,126,127,128,129,130,139,140,141,142,143,144,145,154,155,156,157,158,159,160,169,170,171,172,173,174,175,184,185,186,187,188,189,190,199,201,202,203,205,214,217,220,232};



};

#endif
