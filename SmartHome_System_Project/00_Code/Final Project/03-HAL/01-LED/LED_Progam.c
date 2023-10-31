/*****************************************************************************/
/* Author       	: 	Embedded Tech                                        */
/* Origin Date  	: 	19/10/2023                                           */
/* Layer    	    : 	HAL Layer	                                         */
/* SWC	            : 	LED                                                  */
/* Version      	: 	2                                                    */
/*****************************************************************************/

#include "../../01-LIB/STD_TYPES.h"
#include "../../04-MCAL/01-DIO/DIO_Interface.h"
#include "../01-LED/LED_Interface.h"

void LED_voidInit(u8 u8PinNum){
	DIO_voidSetPinDirection(LED_PORT, u8PinNum, DIO_u8OUTPUT);
}

void LEDs_voidInit(u8 u8PinNum){
	//DDRC = 0b00000111; //output(C0,C1,C2)
	DIO_voidSetPortDirection(LED_PORT, u8PinNum);
}

void LED_voidON(u8 u8PinNum){
	//PORTC = 0b00000001; //high(C0,C1,C2)
	DIO_voidSetPinValue(LED_PORT, u8PinNum, DIO_u8HIGH);
}

void LEDs_voidON(u8 u8PinNum){
	DIO_voidSetPortValue(LED_PORT, u8PinNum);
}

void LED_voidOFF(u8 u8PinNum){
	//PORTC = 0b00000000; //low(C0,C1,C2)
	DIO_voidSetPinValue(LED_PORT, u8PinNum, DIO_u8LOW);
}

void LEDs_voidOFF(u8 u8PinNum){
	DIO_voidSetPortValue(LED_PORT, u8PinNum);
}
