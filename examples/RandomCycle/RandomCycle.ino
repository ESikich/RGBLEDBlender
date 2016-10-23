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
    Color color_list[6] = {_RED, _ORANGE, _YELLOW, _GREEN, _BLUE, _PURPLE};

    RGBLEDBlender my_blender(2, 3, 4);
    
    while(true){
        //Fade randomly for 1000 ms
        my_blender.RandomCycle(color_list, 6, 1000);
    }
}