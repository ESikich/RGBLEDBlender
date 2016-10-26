/*
Candle.ino

Program to simluate a flickering candle.

The circuit:
1 RGB LED attached to pins 2, 3, and 4

Created 16/10/26
By Erik Sikich
*/

#define COLORS_ 7

#include "RGBLEDBlender.h"

struct Candle{
        Candle(uint8_t last_color = 0
                , uint8_t rand_add = 250
                , uint16_t vary = 0
                , uint8_t rand_color = 0
                , uint16_t timer = 0) 
                : last_color(last_color)
                , vary(vary)
                , rand_color(rand_color)
                , color_list(color_list)
                , timer(timer)
                {}
                
    Color color_list[COLORS_];
    RGBLEDBlender blender;
    
    uint8_t last_color;
    uint16_t timer;
    uint16_t vary;
    uint8_t rand_color;
    
    void RandColor(void){do{rand_color = rand() % COLORS_;}while(rand_color == last_color);}  //make sure next random number is different than last
    void RandTimer(void){timer = (rand() %  (vary * 2 + 50)) + vary; Serial.println(timer);}  //randomness
    void Blend(Color* c_list) {blender.Blend(c_list[last_color], c_list[rand_color], timer);} //blend colors
    void Reset(void){
        last_color = rand_color; //save last color
        vary = rand() % (timer);  //random number variance
        if(vary > 32718) vary = 32717;  //prevents overflow on next random number;
    }
};

void setup(){Serial.begin(9600);}

void loop(){
    
    Candle candle;
    candle.blender.SetPins(2, 3, 4);
    Color color_list[COLORS_] = {{255, 235, 0}  //RGB colors
                                , {145, 64, 0}
                                , {225, 105, 0}
                                , {235, 205, 12}
                                , {128, 95, 0}
                                , {64, 50 ,0}
                                , {32, 10, 0}};

    while(true){
        candle.RandColor();  //set random color from list
        candle.RandTimer();  //set random blend time
        candle.Blend(color_list);  //set color blend       
        while(!candle.blender.Update()){}; // loop until done
        candle.Reset(); //reset vars
    }
}
