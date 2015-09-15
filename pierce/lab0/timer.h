/* 
 * File:   timer.h
 * Author: simpspr
 *
 * Created on August 27, 2015, 3:26 PM
 */

#include <xc.h>
#include "vardefs.h"

#ifndef TIMER_H
#define	TIMER_H


//Initializes Timer 1 with a period of 2
void initTimer1();

//Initializes Timer 2
void initTimer2();

void init32bitTimer();

//Starts Timer 1
void startTimer1();

//Stops Timer 1
void stopTimer1();
void delayMs(unsigned int delay);

#endif	/* TIMER_H */

