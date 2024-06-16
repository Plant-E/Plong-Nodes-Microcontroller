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

    void Animation_Players();
    int Animation_Score(int Player_1_Score, int Player_2_Score);

    
    void debug();

private:
    int Winner_Crown_array_size;
    void Make_Screen_Background(CRGB color);
    void setArray();
    void Animation_Game_Over_Mode(int Winner);
    void Rainbowcolor_Background_And_Winner_Animations(uint8_t colorIndex, unsigned int show_array[], int show_array_size);
    unsigned int Players_Array[44] = {90,91,92,96,98,99,100,104,107,111,114,119,122,126,129,134,136,141,144,149,150,154,155,156,159,162,163,164,165,167,169,171,174,175,177,179,181,184,185,186,189,192,193,194};
    unsigned int Player_1_Zero[14] = {114,115,116,129,131,144,146,159,161,174,176,189,190,191};
    unsigned int Player_2_Zero[14] = {108,109,110,123,125,138,140,153,155,168,170,183,184,185};
    unsigned int Player_1_One[9] = {114,115,116,130,145,160,175,176,190};
    unsigned int Player_2_One[9] = {108,109,110,124,139,154,169,170,184};
    unsigned int Player_1_Two[10] = {99,100,101,116,131,145,159,174,176,190};
    unsigned int Player_2_Two[10] = {93,94,95,110,125,139,153,168,170,184};
    unsigned int Player_1_Three[20] = {108,109,110,116,124,131,139,146,154,159,160,161,169,170,174,176,184,189,190,191};
    unsigned int Player_2_Three[20] = {108,109,110,116,125,131,139,146,153,159,160,161,168,170,174,176,184,189,190,191};
    unsigned int Winner_Crown[58] = {79,80,81,82,83,84,85,94,95,96,97,98,99,100,109,110,111,112,113,114,115,124,125,126,127,128,129,130,139,140,141,142,143,144,145,154,155,156,157,158,159,160,169,170,171,172,173,174,175,184,186,187,188,190,199,202,205,217};
    unsigned int Winner_Player_1[29] = {77,78,79,86,92,93,94,101,108,116,123,131,138,146,153,159,160,161,168,174,176,183,184,189,191,198,204,205,206};
    unsigned int Winner_Player_2[33] = {77,78,79,80,86,92,93,94,95,101,110,116,124,131,138,146,152,159,160,161,167,170,174,176,182,185,189,191,198,199,204,205,206};
};

#endif
