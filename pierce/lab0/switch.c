/* 
 * File:   switch.c
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:12 PM
 */


#include "switch.h"

void initSwitches(){
    
    //Enables all three switches on the PIC32 starter kit as inputs
    TRISDbits.TRISD6 = INPUT;
    TRISDbits.TRISD7 = INPUT;
    TRISDbits.TRISD13 = INPUT
}