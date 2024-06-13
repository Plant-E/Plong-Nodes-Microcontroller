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
    Clear_Screen();
    for(unsigned int j = 0; j<NUM_LEDS;j++)
    {
        for(unsigned int i = 0; i<sizeof(Players_Array)/sizeof(Players_Array[0]); i++)
        {
            if(j == Players_Array[i])
            {
                Serial.println(i);
                leds[j] = CRGB::Yellow;
            }
        }
    }
    FastLED.show();

}

void Display::Animation_Score(int Player_1_Score, int Player_2_Score)
{
    Clear_Screen();
    if(Player_1_Score == 0)
    {
        for(unsigned int j = 0; j<NUM_LEDS;j++)
        {
            for(unsigned int i = 0; i < sizeof(Player_1_Zero)/sizeof(Player_1_Zero[0]); i++)
            {
                if(j == Player_1_Zero[i])
                {
                    leds[j] = CRGB::Yellow;
                }

            }
        }
    }
    else if(Player_1_Score == 1)
    {
        for(unsigned int j = 0; j<NUM_LEDS;j++)
        {
            for(unsigned int i = 0; i< sizeof(Player_1_One)/sizeof(Player_1_One[0]); i++)
            {
                if(j == Player_1_One[i])
                {
                    leds[j] = CRGB::Yellow;
                }

            }
        }
    }
    else if(Player_1_Score == 2)
    {
        for(unsigned int j = 0; j<NUM_LEDS;j++)
        {
            for(unsigned int i = 0; i< sizeof(Player_1_Two)/sizeof(Player_1_Two[0]); i++)
            {
                if(j == Player_1_Two[i])
                {
                    leds[j] = CRGB::Blue;
                }

            }
        }
    }




//player 2
    if(Player_2_Score == 0)
    {
        for(unsigned int j = 0; j<NUM_LEDS;j++)
        {
            for(unsigned int i = 0; i< sizeof(Player_2_Zero)/sizeof(Player_2_Zero[0]); i++)
            {
                if(j == Player_2_Zero[i])
                {
                    leds[j] = CRGB::Yellow;
                }

            }
        }
    }
    else if(Player_2_Score == 1)
    {
        for(unsigned int j = 0; j<NUM_LEDS;j++)
        {
            for(unsigned int i = 0; i< sizeof(Player_2_One)/sizeof(Player_2_One[0]); i++)
            {
                if(j == Player_2_One[i])
                {
                    leds[j] = CRGB::Yellow;
                }

            }
        }
    }
    else if(Player_2_Score == 2)
    {
        for(unsigned int j = 0; j<NUM_LEDS;j++)
        {
            for(unsigned int i = 0; i< sizeof(Player_2_Two)/sizeof(Player_2_Two[0]); i++)
            {
                if(j == Player_2_Two[i])
                {
                    leds[j] = CRGB::Blue;
                }

            }
        }
    }
    FastLED.show();
}

void Display::Animation_Game_Over_Mode(int Winner)
{
    unsigned long Animation_Game_Over_Millis;
    static int Game_Over_Loop = 5000;
    static uint8_t colorIndex = 0;

    Serial.print("millis: ");
    Serial.println(millis());
    Serial.print("Animation_Game_Over_Millis: ");
    Serial.println(Animation_Game_Over_Millis);
    if(Winner == 1)
    {
        Clear_Screen();
        while(millis() - Animation_Game_Over_Millis <= Game_Over_Loop)
        {

            colorIndex = colorIndex + 1;
            for(unsigned int j = 0; j < NUM_LEDS; ++j)
            {
                for(unsigned int i = 0; i< sizeof(Player_1_Three)/sizeof(Player_1_Three[0]); i++) 
                {
                    if(j == Player_1_Three[i])
                    {
                        leds[j] = CRGB::Black; 
                        Serial.print("Black: ");
                        Serial.println(i);
                    }
                    else
                    {
                        leds[j] = ColorFromPalette(currentPalette, colorIndex, 64, currentBlending);
                        Serial.print("Color: ");
                        Serial.println(j);
                        colorIndex += 3;
                    }
                }
            }
            FastLED.show();
            FastLED.delay(10);
        }


        delay(2000);

        for(unsigned int j = 0; j < NUM_LEDS; ++j)
        {
            for(unsigned int i = 0; i< sizeof(Winner_Player)/sizeof(Winner_Player[0]); i++) 
            {
                if(j == Winner_Player[i])
                {
                    leds[j] = CRGB::Black;                        
                }
                else
                {
                    leds[j] = ColorFromPalette( RainbowColors_p, 0, 255, LINEARBLEND);
                }
            }
        }

        // CurrentState = Bootingmode
    }

    else if(Winner == 2)
    {
        Clear_Screen();
        for(unsigned int j = 0; j < NUM_LEDS; ++j)
        {
            for(unsigned int i = 0; i< sizeof(Player_1_Three)/sizeof(Player_1_Three[0]); i++) 
            {
                if(j == Player_1_Three[i])
                {
                    leds[j] = CRGB::Black;                        
                }
                else
                {
                    leds[i] = ColorFromPalette( RainbowColors_p, 0, 255, LINEARBLEND);
                }
            }
        }

        delay(2000);

        for(unsigned int j = 0; j < NUM_LEDS; ++j)
        {
            for(unsigned int i = 0; i< sizeof(Winner_Player)/sizeof(Winner_Player[0]); i++) 
            {
                if(j == Winner_Player[i])
                {
                    leds[j] = CRGB::Black;                        
                }
                else
                {
                    leds[i] = ColorFromPalette( RainbowColors_p, 0, 255, LINEARBLEND);
                }
            }
        }
        // CurrentState = Bootingmode
    }
}

void Display::Clear_Screen()
{
    for(unsigned int j = 0; j < NUM_LEDS;j++)
    {
        leds[j] = CRGB(0,0,0);
    }
    FastLED.show();
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

