/* 
 * File:   timer.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:26 PM
 */



#include "timer.h"

void initTimer1(){
    //TODO: Initialize Timer 1 to have a period of
    // 1 second. Enable its interrupt
    
    //set the prescale to 256
    T1CONbits.TCKPS = 3; 
    
    //initialize timer 1 to zero
    TMR1 = 0;
    
    //Set period register to period of 1 second
    PR1 = 1221;
    
    //Enable interrupt
    IEC0bits.T1IE = ENABLE;
    
    //Initialize timer interrupt flag to off
    IFS0bits.T1IF = DISABLE;
    
    //Set interrupt priority
    IPC1bits.T1IP = 3;
    
    //Turn timer on
    T1CONbits.ON = ENABLE;
}

void initTimer2(){
    //Set prescale to 16 (timer 2 has 8 prescale values.)
    T2CONbits.TCKPS = 4; 
    
    //initialize timer 2 to zero
    TMR2 = 0;
    
    //Set period register to 1221
    //PR2 = 1221;
    
    //Enable interrupt
    //IEC0bits.T2IE = ENABLE;
    
    //Initialize timer interrupt flag to off
    IFS0bits.T2IF = FLAGDOWN;
    
    //Set interrupt priority
    //IPC2bits.T2IP = 3;
    
    //Turn timer on
    T2CONbits.ON = 1;
}

void delayMs(unsigned int delay){
    //TODO: Using timer 2, create a delay
    // that is delay amount of ms.
    
    //reset timer 2 to zero
    TMR2 = 0;
    
    //8 MHz / 2 * 20 / 16 / 8 * 0.001 sec / 16 - 1
    PR2 = delay*39;
    
    //Set interrupt flag down
    IFS0bits.T2IF = FLAGDOWN;
    
    //Start timer 2
    T2CONbits.ON = ENABLE;
    
    //loop while timer 2 flag is down
    while(IFS0bits.T2IF == FLAGDOWN);
    
    //Stop timer 2
    T2CONbits.ON = DISABLE;
}