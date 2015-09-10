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
#include "config.h"
#include "vardefs.h"

//The following definitions are already defined in vardefs.h
//#define OUTPUT 0
//#define INPUT 1

//TODO: Define states of the state machine

typedef enum stateTypeEnum {
    led1, led2, led3, wait, wait2, debouncePress, debounceRelease, debounceRelease2
} stateType;

//TODO: Use volatile variables that change within interrupts

volatile stateType state = wait;

int main() {
    //Create current and last LED placeholders
    int lastLED = 1;
    
    //This function is necessary to use interrupts. 
    enableInterrupts();

    //TODO: Write each initialization function
    initSwitches();
    initLEDs();
    initTimer2();
    initTimer1();
    turnOnLED(1);

    while (1) {

        switch (state) {
            case wait:
                if (IFS1bits.CNDIF == ON) {
                    
                    state = debouncePress;
                }
                break;

            case debouncePress:
                if (IFS0bits.T1IF == ON) {
                    state = led1;
                }
                break;
                
            case led1:
                turnOnLED(1);
                turnOffLED(lastLED);
                lastLED = 1;
                state = wait2;
                break;
                
            case led2:
                turnOnLED(2);
                turnOffLED(lastLED);
                lastLED = 2;
                state = wait;
                break;
                
            case led3:
                turnOnLED(3);
                turnOffLED(lastLED);
                lastLED = 3;
                state = wait;
                break;
        }
        //TODO: Implement a state machine to create the desired functionality

    }

    return 0;
}

void __ISR(_TIMER_1_VECTOR, IPL7SRS) T1Interrupt(){
    IFS0bits.T1IF = 0;
    LATDbits.LATD0 = !LATDbits.LATD0; // 
}

