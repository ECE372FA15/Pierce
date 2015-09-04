/* 
 * File:   led.h
 * Author: gvanhoy
 *
 * Created on August 27, 2015, 3:15 PM
 */

//moved the following include from led.c


#include "vardefs.h"

#ifndef LED_H
#define	LED_H

void initLEDs();
void turnOnLED(int led);
void turnOffLED(int led);

#endif	/* LED_H */

