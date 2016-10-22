/*
	Random.ino

	This program cycles through random colors

	The circuit:
	1 RGB LED attached to pins 2, 3, and 4

	Created 21/10/16
	By Erik Sikich
*/

#include "RGBLEDBlender.h"

void setup(){}

void loop(){
    RGBLEDBlender my_blender(2, 3, 4);

    while(true){
        //Fade through random colors for 1000 ms
        my_blender.Random(1000);
    }
}