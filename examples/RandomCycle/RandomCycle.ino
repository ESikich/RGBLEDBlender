/*
	RandomCycle.ino

	This program randomly blends colors added to a list

	The circuit:
	1 RGB LED attached to pins 2, 3, and 4

	Created 21/10/16
	By Erik Sikich
*/

#include "RGBLEDBlender.h"

void setup(){
    srand(analogRead(0));  //Seed random number
}

void loop(){
    Color colorList[6] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};
    //Create object red pin - 2, green pin - 3, blue pin - 4
    RGBLEDBlender myBlender(2, 3, 4);
    //Add colors to list from Color.h
    for(uint8_t i = 0; i < 6; i++){
        myBlender.AddColor(colorList[i]);
    }

    while(true){
        //Fade randomly for 1000 ms
        myBlender.RandomCycle(1000);
    }
}