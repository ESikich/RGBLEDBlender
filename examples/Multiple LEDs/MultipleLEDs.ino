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
	Color color_list1[4] = {ORANGE, PURPLE, GREEN, RED};
	Color color_list2[3] = {BLUE, YELLOW, CYAN};

    RGBLEDBlender my_blender1(2, 3, 4);
    RGBLEDBlender my_blender2(5, 6, 7);

	for(uint8_t i = 0; i < 4; i++) my_blender1.AddColor(color_list1[i]);
	for(uint8_t i = 0; i < 3; i++) my_blender2.AddColor(color_list2[i]);

    while(true){
        my_blender1.RandomCycle(1000);
        my_blender2.Cycle(750);
    }
}