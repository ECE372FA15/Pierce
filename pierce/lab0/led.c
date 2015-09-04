/* 
 * File:   led.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:15 PM
 */
#include <xc.h>

#include "led.h"

void initLEDs(){
    
    //Enables the three LEDs on the PIC32 starter kit as OUTPUTs
    TRISDbits.TRISD0 = OUTPUT;
    TRISDbits.TRISD1 = OUTPUT;
    TRISDbits.TRISD2 = OUTPUT;
    
}

void turnOnLED(int led){
    
    if(led == 1){
    //turns LED on
    //led = ON;
        LATDbits.LATD0 = ON;
        LATDbits.LATD1 = ON;
        LATDbits.LATD2 = ON;
    }
    
}

void turnOffLED(int led){
    
    if(led == 1){
    //turns LED off
    //led = ON;
        LATDbits.LATD0 = OFF;
        LATDbits.LATD1 = OFF;
        LATDbits.LATD2 = OFF;
    }
    
}