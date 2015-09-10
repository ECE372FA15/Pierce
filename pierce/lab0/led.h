/* 
 * File:   led.h
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:15 PM
 */

//moved the following include from led.c
#include <xc.h>

#include "vardefs.h"

#ifndef LED_H
#define	LED_H

#define LED1 LATDbits.LATD0
#define LED2 LATDbits.LATD1
#define LED3 LATDbits.LATD2

void initLEDs();
void turnOnLED(int led);
void turnOffLED(int led);

#endif	/* LED_H */

