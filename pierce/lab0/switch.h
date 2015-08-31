/* 
 * File:   switch.h
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:12 PM
 */

#include "vardefs.h"

//moved the following includes from switch.c
#include <proc/p32mx470f512l.h>
#include <xc.h>

#ifndef SWITCH_H
#define	SWITCH_H

#define SW1 PORTDbits.RD6
#define PRESSED 0
#define RELEASED 1

void initSwitches();

#endif	/* SWITCH_H */

