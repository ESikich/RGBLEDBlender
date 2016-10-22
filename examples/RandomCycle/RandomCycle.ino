/*
	RandomCycle.ino

	This program randomly blends colors added to a list

	The circuit:
	1 RGB LED attached to pins 2, 3, and 4

	Created 21/10/16
	By Erik Sikich
*/

#include "RGBLEDBlender.h"

void setup(){}

void loop(){
    Color color_list[6] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};

    RGBLEDBlender my_blender(2, 3, 4);

    for(uint8_t i = 0; i < 6; i++) my_blender.AddColor(color_list[i]);
    
    while(true){
        //Fade randomly for 1000 ms
        my_blender.RandomCycle(1000);
    }
}