[![Open Source Love](https://badges.frapsoft.com/os/v1/open-source.svg?v=103)](https://github.com/ellerbrock/open-source-badge/)    [![GPL Licence](https://badges.frapsoft.com/os/gpl/gpl.svg?v=103)](https://opensource.org/licenses/GPL-3.0/)  

RGBLEDBlender
=====================
RGB blending and color library written for the Arduino.

by Erik Sikich  
2016 November 22  

See Colors.h for color definitions  


Overview of functions
=====================
**Blend**       - Blends two colors together  
**Random**      - Blends randomly generated colors together  
**RandomCycle** - Randomly cycles through a list of colors  
**Cycle**       - Cycles through a list of colors  
**Update**      - Call to update color  
**Hold**        - Holds a color  
**TurnOff**     - Turns off the LED  
**GetColor**    - Returns current color

Usage
=====================
Requires 3 PWM pins per RGBLEDBlender object.  Objects may share the same pins in case of multiplexing or something similar.

To blend arbitrary colors together, call the Blend() fuction once and then repeatedly call Update()

```C++
my_blender.Blend(_RED, _YELLOW, blend_time);

uint32_t blend_time = 1000;
uint32_t done = millis() + blend_time;

while(done > millis()){
    my_blender.Update();
}
```

For Random(), RandomCycle(), and Cycle(), just repeatedly call the function.


```C++
Color color_list[6] = {_RED, _ORANGE, _YELLOW, _GREEN, _BLUE, _PURPLE};

while(true){
    my_blender.RandomCycle(color_list, 6, 1000);
}
```

Color math and assignments
=====================
Colors can be added, subtracted, divided and multiplied either by each other or constants.

```C++
Color my_color = {10, 15, 20};
Color my_color2 = {1, 2 ,3};
my_color *= 2;
//my_color would now be == {20, 30, 40}

my_color += my_color2;
//my_color would now be == {21, 32, 43}
```
**NOTE:  Be vigilant when doing this, as the Color struct is made of int16_t's.  Be sure to check your values as writing values < 0 or > 255 will cause under/overflow issues and you will not get the colors you expect.**


Pre-defined color definitions
=====================
Pulled from [here](http://www.rapidtables.com/web/color/RGB_Color.htm).