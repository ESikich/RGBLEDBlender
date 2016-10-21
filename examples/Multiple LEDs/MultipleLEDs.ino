/*
	Multiple LEDs.ino

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
    //Create object red pin - 2, green pin - 3, blue pin - 4
    RGBLEDBlender myBlender(2, 3, 4);
    RGBLEDBlender myBlender2(5, 6, 7);
    //Add colors to list from Color.h
    myFader.AddColor(ORANGE);
    myFader.AddColor(PURPLE);
    myFader.AddColor(GREEN);
    myFader.AddColor(RED);
    myFader2.AddColor(YELLOW);
    myFader2.AddColor(BLUE);
    myFader2.AddColor(RED);

    while(true){
        //Fade randomly for 1000 ms
        myFader.RandomCycle(1000);
        myFader2.Cycle();
    }
}