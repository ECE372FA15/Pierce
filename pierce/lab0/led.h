/* 
 * File:   led.h
 * Author: simpspr
 *
 * Created on August 27, 2015, 3:15 PM
 */

//moved the following include from led.c
#include <xc.h>

#include "vardefs.h"

#ifndef LED_H
#define	LED_H

//Define the three LEDs on the USB Starter Kit to appropriate pins on the PIC
#define LED1 LATDbits.LATD0
#define LED2 LATDbits.LATD1
#define LED3 LATDbits.LATD2

//Initializes all LEDs as outputs and turns them off
void initLEDs();

//Turns led parameter on
void turnOnLED(int led);

//Turns led parameter off
void turnOffLED(int led);

#endif	/* LED_H */

