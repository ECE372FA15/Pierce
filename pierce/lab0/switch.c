/* 
 * File:   switch.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:12 PM
 */

#include <proc/p32mx470f512l.h>
#include <xc.h>

#include "switch.h"

void initSwitches(){
    
    //Enables all three switches on the PIC32 starter kit as inputs
    TRISDbits.TRISD6 = INPUT;
    TRISDbits.TRISD7 = INPUT;
    TRISDbits.TRISD13 = INPUT;
    
    CNCONDbits.ON = ON;
    CNENDbits.CNIED6 = ON;
    IFS1bits.CNDIF = OFF;
    CNPUDbits.CNPUD6 = ON;
    IEC1bits.CNDIE = ON;
}