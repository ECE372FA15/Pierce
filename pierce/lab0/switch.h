/* 
 * File:   switch.h
 * Author: simpspr
 *
 * Created on August 27, 2015, 3:12 PM
 */

//moved the following includes from switch.c
#include <proc/p32mx470f512l.h>
#include <xc.h>

#include "vardefs.h"

#ifndef SWITCH_H
#define	SWITCH_H

//define the three switches on the USB Starter Kit to appropriate pins on the PIC
#define SW1 PORTDbits.RD6
#define SW2 PORTDbits.RD7
#define SW3 PORTDbits.RD13

//Enables SW1
void initSwitch1();

//Enables all three switches and their change notice registers
void initSwitches();

#endif	/* SWITCH_H */

