/*
	Random.ino

	This program cycles through random colors

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

    while(true){
        //Fade through random colors for 1000 ms
        myBlender.Random(1000);
    }
}