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
    TRISDbits.TRISD1 = OUTPUT;
    TRISDbits.TRISD2 = OUTPUT;

}

void turnOnLED(int led) {

    if (led == 1) {
        LATDbits.LATD0 = ON;
    }
    
    else if (led == 2) {
        LATDbits.LATD1 = ON;
    }
    
    else {
        LATDbits.LATD2 = ON;
    }

}

void turnOffLED(int led) {

    if (led == 1) {
        LATDbits.LATD0 = OFF;
    }
    
    else if (led == 2) {
        LATDbits.LATD1 = OFF;
    }
    
    else {
        LATDbits.LATD2 = OFF;
    }

}