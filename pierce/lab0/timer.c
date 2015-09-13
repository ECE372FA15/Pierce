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
    T1CONbits.TCKPS = 0; 
    
    //initialize timer 1 to zero
    TMR1 = 0;
    
    //Set period register to 1221
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
    T2CONbits.TCKPS = 0; 
    
    //initialize timer 2 to zero
    TMR2 = 0;
    
    //Set period register to 1221
    //PR2 = 1221;
    
    //Enable interrupt
   // IEC0bits.T2IE = ENABLE;
    
    //Initialize timer interrupt flag to off
    IFS0bits.T2IF = FLAGDOWN;
    
    //Set interrupt priority
    //IPC2bits.T2IP = 3;
    
    //Turn timer on
    T2CONbits.ON = 0;
}

void delayMs(unsigned int delay){
    //TODO: Using timer 2, create a delay
    // that is delay amount of ms.
    
    TMR2 = 0;
    PR2 = delay*312;
    IFS0bits.T2IF = 0;
    T2CONbits.ON = 1;
    while(IFS0bits.T2IF == 0);
    T2CONbits.ON = 0;
}