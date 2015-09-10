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
    
//    //Enable change notice control on PORTD register
//    CNCONDbits.ON = ENABLE;
//    
//    //Enable change notice interrupt on pins attached to switches
//    CNENDbits.CNIED6 = ENABLE;
//    CNENDbits.CNIED7 = ENABLE;
//    CNENDbits.CNIED13 = ENABLE;
    
    //Enable all pullup resistors on switches
    CNPUDbits.CNPUD6 = ENABLE;
    CNPUDbits.CNPUD7 = ENABLE;
    CNPUDbits.CNPUD13 = ENABLE;
    
//    //Enable interrupt flag on PORTD change notification register
//    IEC1bits.CNDIE = ENABLE;
//    
//    //Initialize interrupt flag to off
//    IFS1bits.CNDIF = DISABLE;
    
    
}