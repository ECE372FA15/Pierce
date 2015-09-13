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
    int currLED = 1;


    //This function is necessary to use interrupts. 
    //enableInterrupts();

    //TODO: Write each initialization function
    initSwitch1();
    initLEDs();
    initTimer2();
    initTimer1();
    turnOnLED(1);

    while (1) {
        turnOnLED(3);
        delayMs(1000);
        turnOffLED(3);
        delayMs(1000);
        switch (state) {

            case wait:
                delayMs(10000);
                if (SW1 == PRESSED) {
                    state = debouncePress;

                }

                break;

            case debouncePress:

                delayMs(10000);
                state = wait2;

                break;

            case wait2:
                delayMs(10000);
                if (SW1 == RELEASED) {

                    state = debounceRelease;

                }
                break;

            case debounceRelease:
                IFS1bits.CNDIF = FLAGDOWN;
                delayMs(500);
                if (currLED == 1) {
                    state = led2;

                } else if (currLED == 2) {
                    state = led3;

                } else if (currLED == 3) {
                    state = led1;

                }
                break;


            case led1:
                delayMs(1000);
                turnOnLED(1);
                turnOffLED(currLED);

                currLED = 1;
                state = led2;

                break;

            case led2:
                delayMs(1000);
                turnOnLED(2);
                turnOffLED(currLED);

                currLED = 2;
                state = led3;

                break;

            case led3:
                delayMs(1000);
                turnOnLED(3);
                turnOffLED(currLED);

                currLED = 3;
                state = led1;

                break;
        }
        //TODO: Implement a state machine to create the desired functionality

    }

    return 0;
}

//void __ISR(_TIMER_1_VECTOR, IPL7SRS) T1Interrupt(){
//    IFS0bits.T1IF = 0;
//    LATDbits.LATD0 = !LATDbits.LATD0; // 
//}


