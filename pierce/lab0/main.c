/* 
 * File:   main.c
 * Author: simpspr
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

//State machine states:
//wait: Waits for SW1 to be pressed. When SW1 is pressed, Timer 1 starts.
//debouncePress: Delay for 100ms to prevent switch bouncing.
//wait2: Waits for SW1 to be released
//debounceRelease: Delay for 100ms to prevent switch bouncing. Checks which LED
//is currently on and goes to the appropriate ledx state.
//debounceRelease2: Access through Timer1 ISR. Waits for SW1 to be released,
//debounces for 100ms, checks which LED is currently on a goes to the appropriate
//ledx state.
//led1: Turns on LED1 and turns off the currently lit LED
//led1: Turns on LED2 and turns off the currently lit LED
//led1: Turns on LED3 and turns off the currently lit LED

typedef enum stateTypeEnum {
    led1, led2, led3, wait, wait2, debouncePress, debounceRelease, debounceRelease2
} stateType;

//TODO: Use volatile variables that change within interrupts

volatile stateType state = wait;

int main() {
    //Create current LED placeholders
    int currLED = 1;

    //This function is necessary to use interrupts. 
    enableInterrupts();

    //Initialize SW1
    initSwitch1();
    
    //Initialize all LEDs
    initLEDs();
    
   //Initialize Timer 2
    initTimer2();
    
    //Initialize Timer 1
    initTimer1();
    
    //Turn on LED 1 before starting the state machine
    turnOnLED(1);

    while (1) {
        
        //See state descriptions above
        switch (state) {

            case wait:

                if (SW1 == PRESSED) {
                    startTimer1();
                    state = debouncePress;
                }

                break;

            case debouncePress:

                delayMs(100);
                state = wait2;
                break;

            case wait2:
//                if (IFS0bits.T1IF == FLAGUP){
//                    stopTimer1();
//                    state = debounceRelease2;
//                }
                if (SW1 == RELEASED) {
                   // stopTimer1();
                    state = debounceRelease;

                }
                break;

            case debounceRelease:

                delayMs(100);
                if (currLED == 1) {
                    state = led2;

                } else if (currLED == 2) {
                    state = led3;

                } else if (currLED == 3) {
                    state = led1;

                }
                break;

            case debounceRelease2:

                if (SW1 == RELEASED) {
                    delayMs(100);
                    if (currLED == 1) {
                        state = led3;

                    } else if (currLED == 2) {
                        state = led1;

                    } else if (currLED == 3) {
                        state = led2;

                    }
                }
                break;


            case led1:
              
                turnOnLED(1);
                turnOffLED(currLED);

                currLED = 1;
                state = wait;

                break;

            case led2:
               
                turnOnLED(2);
                turnOffLED(currLED);

                currLED = 2;
                state = wait;

                break;

            case led3:
           
                turnOnLED(3);
                turnOffLED(currLED);

                currLED = 3;
                state = wait;

                break;
        }
    }

    return 0;
}

//Interrupt service routine for Timer1. Puts the flag down when it goes up,
//goes to debounceRelease2 state.
void __ISR(_TIMER_1_VECTOR, IPL7SRS) T1Interrupt() {
    IFS0bits.T1IF = FLAGDOWN;
    stopTimer1();
    if(state == wait2){
        state = debounceRelease2;
    }
}


