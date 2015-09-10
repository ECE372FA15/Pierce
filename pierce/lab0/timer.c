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
    
    //set the prescaler to 256
    T1CONbits.TCKPS = 3; 
    
    //initialize timer 1 to zero
    TMR1 = 0;
    
    //Set period register to 1221
    PR1 = 1221;
    
    //Enable interrupt
    IEC0bits.T1IE = ON;
    
    //Initialize timer interrupt flag to off
    IFS0bits.T1IF = OFF;
    
    //Set 
    IPC1bits.T1IP = 3;
    
    //Turn timer on
    T1CONbits.ON = ON;
}

initTimer2(){
    T2CONbits.TCKPS = 3; 
    
    //initialize timer 2 to zero
    TMR2 = 0;
    
    //Set period register to 1221
    PR2 = 1221;
    
    //Enable interrupt
    IEC0bits.T2IE = ON;
    
    //Initialize timer interrupt flag to off
    IFS0bits.T2IF = OFF;
    
    //Set 
    IPC2bits.T2IP = 3;
    
    //Turn timer on
    T2CONbits.ON = ON;
}

delayMs(int delay){
    //TODO: Using timer 2, create a delay
    // that is delay amount of ms.
}