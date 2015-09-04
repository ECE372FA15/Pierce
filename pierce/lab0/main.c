/* 
 * File:   main.c
 * Author: gvanhoy
 * Description: lab 0.
 * Created on August 27, 2015, 10:14 AM
 */

#include <xc.h>
#include <sys/attribs.h>
#include "switch.h"
#include "timer.h"
#include "led.h"
#include "interrupt.h"
//#include "config.h"

//The following definitions are already defined in vardefs.h
//#define OUTPUT 0
//#define INPUT 1

//TODO: Define states of the state machine

typedef enum stateTypeEnum {
    led1, led2, led3, wait, wait2, debouncePress, debounceRelease, debounceRelease2
} stateType;

//TODO: Use volatile variables that change within interrupts

volatile state = wait;

int main() {

    //This function is necessary to use interrupts. 
    enableInterrupts();

    //TODO: Write each initialization function
    initSwitches();
    initLEDs();
    initTimer2();
    initTimer1();

    while (1) {

        switch (state) {
            case wait:
                if (IFS1bits.CNDIF == ON) {
                    
                    state = wait2;
                }
                break;

            case wait2:
                if (IFS1bits.CNDIF == ON) {
                    turnOnLED(1);
                }
                break;
        }
        //TODO: Implement a state machine to create the desired functionality

    }

    return 0;
}

