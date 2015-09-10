/* 
 * File:   switch.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:12 PM
 */

#include "switch.h"

void initSwitches(){
    
    //Enable all three switches on the PIC32 starter kit as inputs
    TRISDbits.TRISD6 = INPUT;
    TRISDbits.TRISD7 = INPUT;
    TRISDbits.TRISD13 = INPUT;
    
    //Enable change notice control on PORTD register
    CNCONDbits.ON = ON;
    
    //Enable change notice interrupt on pins attached to switches
    CNENDbits.CNIED6 = ON;
    CNENDbits.CNIED7 = ON;
    CNENDbits.CNIED13 = ON;
    
    //Enable all pullup resistors on switches
    CNPUDbits.CNPUD6 = ON;
    CNPUDbits.CNPUD7 = ON;
    CNPUDbits.CNPUD13 = ON;
    
    //Enable interrupt flag on PORTD change notification register
    IEC1bits.CNDIE = ON;
    
    //Initialized interrupt flag to off
    IFS1bits.CNDIF = OFF;
    
    
}