/*
	Multiple LEDs.ino

	This program randomly blends colors added to a list

	The circuit:
	1 RGB LED attached to pins 2, 3, and 4

	Created 21/10/16
	By Erik Sikich
*/

#include "RGBLEDBlender.h"

void setup(){}

void loop(){
	Color color_list1[4] = {_ORANGE, _PURPLE, _GREEN, _RED};
	Color color_list2[3] = {_BLUE, _YELLOW, _CYAN};

    RGBLEDBlender my_blender1(2, 3, 4);
    RGBLEDBlender my_blender2(5, 6, 7);

    while(true){
        my_blender1.RandomCycle(color_list1, 4, 1000);
        my_blender2.Cycle(color_list2, 3, 750);
    }
}
