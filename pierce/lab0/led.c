/* 
 * File:   led.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:15 PM
 */


#include "led.h"

void initLEDs() {

    //Enables the three LEDs on the PIC32 starter kit as OUTPUTs
    TRISDbits.TRISD0 = OUTPUT;
    turnOffLED(1);
    TRISDbits.TRISD1 = OUTPUT;
    turnOffLED(2);
    TRISDbits.TRISD2 = OUTPUT;
    turnOffLED(3);
}

void turnOnLED(int led) {

    if (led == 1) {
        LED1 = LEDON;
    }
    
    else if (led == 2) {
        LED2 = LEDON;
    }
    
    else {
        LED3 = LEDON;
    }

}

void turnOffLED(int led) {

    if (led == 1) {
        LED1 = LEDOFF;
    }
    
    else if (led == 2) {
        LED2 = LEDOFF;
    }
    
    else {
        LED3 = LEDOFF;
    }

}