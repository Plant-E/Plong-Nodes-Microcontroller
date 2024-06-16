#include "Display.h"
#include <FastLED.h>

#define NUM_LEDS 285
#define DATA_PIN 4

CRGB leds[NUM_LEDS];
CRGBPalette16 currentPalette = RainbowColors_p;
TBlendType    currentBlending = LINEARBLEND;

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
            
            float distance = sqrt(pow((x * 100 + 50) - pos_x, 2) + pow((y * 100 + 50) - pos_y, 2));

            if(distance > visualisation_distance){
                setLed(x, y, CRGB::Black);
            }
            else{
                int brightness = static_cast<int>(max_brightness * (1 - (distance / visualisation_distance)));
                setLed(x, y, CRGB(brightness, 0, 0));
            }

        }
    }

}
void Display::visualizePaddle(int x_1, int x_2, int width){

    for(int x = x_1 - width; x <= x_1 + width; x++){
        setLed(x, 0, CRGB(0, 100, 100));
    }
    for(int x = x_2 - width; x <= x_2 + width; x++){
        setLed(x, res_y - 1, CRGB(0, 100, 100));
    }

}
void Display::setLed(int x, int y, CRGB color){
    int led;
    if (y % 2 == 0) {
        led = y * res_x + x;
    } else {
        led = y * res_x + (res_x - 1 - x);
    }

    leds[led] = color;
}
void Display::displayLeds(){
    FastLED.show();
}
void Display::setArray()
{

}
void Display::Animation_Players()
{
    Make_Screen_Background(CRGB::Blue);
    for(unsigned i = 0; i < sizeof(Players_Array)/sizeof(Players_Array[0]); i++)
    {
        leds[Players_Array[i]] = CRGB::Yellow;
    }
    FastLED.show();
}
int Display::Animation_Score(int Player_1_Score, int Player_2_Score)
{
    Make_Screen_Background(CRGB::Purple);
    
    if(Player_1_Score == 3)
    {
        Animation_Game_Over_Mode(1);
        return 2;
    }
    if(Player_2_Score == 3)
    {
        Animation_Game_Over_Mode(2);
        return 2;
    }

    if(Player_1_Score == 0)
    {

        for(unsigned int i = 0; i < sizeof(Player_1_Zero)/sizeof(Player_1_Zero[0]); i++)
        {
            leds[Player_1_Zero[i]] = CRGB::Yellow;
        }

    }
    else if(Player_1_Score == 1)
    {
        for(unsigned int i = 0; i< sizeof(Player_1_One)/sizeof(Player_1_One[0]); i++)
        {
            leds[Player_1_One[i]] = CRGB::Yellow;
        }
    }
    else if(Player_1_Score == 2)
    {
        for(unsigned int i = 0; i< sizeof(Player_1_Two)/sizeof(Player_1_Two[0]); i++)
        {
            leds[Player_1_Two[i]] = CRGB::Blue;
        }
    }

//player 2
    if(Player_2_Score == 0)
    {
        for(unsigned int i = 0; i< sizeof(Player_2_Zero)/sizeof(Player_2_Zero[0]); i++)
        {
            leds[Player_2_Zero[i]] = CRGB::Yellow;
        }
    }
    else if(Player_2_Score == 1)
    {
        for(unsigned int i = 0; i< sizeof(Player_2_One)/sizeof(Player_2_One[0]); i++)
        {
            leds[Player_2_One[i]] = CRGB::Yellow;
        }
    }
    else if(Player_2_Score == 2)
    {
        for(unsigned int i = 0; i< sizeof(Player_2_Two)/sizeof(Player_2_Two[0]); i++)
        {
            leds[Player_2_Two[i]] = CRGB::Blue;
        }
    }
    FastLED.show();
    return 1;
}
void Display::Animation_Game_Over_Mode(int Winner)
{
    unsigned long Animation_Game_Over_Millis = millis();
    static int Game_Over_Loop = 5000;

    while(millis() - Animation_Game_Over_Millis <= Game_Over_Loop)
    {
        static uint8_t startIndex = 0;
        startIndex = startIndex + 1; /* motion speed */
        int Winner_Crown_array_size = sizeof(Winner_Crown) / sizeof(Winner_Crown[0]);
        Rainbowcolor_Background_And_Winner_Animations(startIndex, Winner_Crown,Winner_Crown_array_size);

        delay(1000);
        int Winner_Player_1_array_size = sizeof(Winner_Player_1) / sizeof(Winner_Player_1[0]);
        int Winner_Player_2_array_size = sizeof(Winner_Player_2) / sizeof(Winner_Player_2[0]);
        if(Winner == 1){Rainbowcolor_Background_And_Winner_Animations(startIndex, Winner_Player_1, Winner_Player_1_array_size);}
        if(Winner == 2){Rainbowcolor_Background_And_Winner_Animations(startIndex, Winner_Player_2, Winner_Player_2_array_size);}
        delay(1000);
    }
}
void Display::Make_Screen_Background(CRGB color)
{
    for(unsigned int j = 0; j < NUM_LEDS;j++)
    {
        leds[j] = color;
    }
    FastLED.show();
}
void Display::Rainbowcolor_Background_And_Winner_Animations(uint8_t colorIndex, unsigned int show_array[], int show_array_size) 
{
    uint8_t brightness = 64;
    
    for (int i = 0; i < NUM_LEDS; ++i) 
    {
        leds[i] = ColorFromPalette(currentPalette, colorIndex, brightness, currentBlending);
        colorIndex += 3;
    }
    FastLED.show();
    for (int j = 0; j < show_array_size; j++) 
    {
        Serial.println(j);
        leds[show_array[j]] = CRGB::Black;
    }

    FastLED.show();
    FastLED.delay(10);
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

