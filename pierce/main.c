/* 
 * File:   main.c
 * Author: pierce
 *
 * Created on August 27, 2015, 8:35 PM
 */

#include <xc.h>
#include <sys/attribs.h>

#define OUTPUT 0
#define INPUT 1

/*
 * 
 */
int main() {
    
    TRISDbits.TRISD6 = INPUT;
    TRISDbits.TRISD7 = INPUT;
    TRISDbits.TRISD13 = INPUT;
    
    //Initializes switches RD6, RD7, RD13 as inputs on tristate registers
    
    TRISDbits.TRISD0 = OUTPUT;   
    TRISDbits.TRISD1 = OUTPUT;   
    TRISDbits.TRISD2 = OUTPUT;
    
    //Initializes LEDs RD0, RD1, RD2 as outputs on tristate registers
    
    CNPUDbits.CNPUD6 = 1;
    CNPUDbits.CNPUD7 = 1;
    CNPUDbits.CNPUD13 = 1;
    
    //Enables pullup resistors for all switches
    
    while(1){
        
        if(PORTDbits.RD6 == 0){
            LATDbits.LATD0 = 1;
        }
        else {
            LATDbits.LATD0 = 0;
        }
        
        if(PORTDbits.RD7 == 0){
            LATDbits.LATD1 = 1;
        }
        else {
            LATDbits.LATD1 = 0;
        }
        
        if(PORTDbits.RD13 == 0){
            LATDbits.LATD2 = 1;
        }
        else {
            LATDbits.LATD2 = 0;
        }
        
    }
    return 0;
}

