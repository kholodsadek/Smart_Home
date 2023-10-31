/*****************************************************************************/
/* Author       	: 	Embedded Tech                                        */
/* Origin Date  	: 	19/10/2023                                           */
/* Layer    	    : 	HAL Layer	                                         */
/* SWC	            : 	BUSH BUTTON                                          */
/* Version      	: 	2                                                    */
/*****************************************************************************/

#ifndef BUSHBUTTON_INTERFACE_H_
#define BUSHBUTTON_INTERFACE_H_

#include "../../01-LIB/STD_TYPES.h"
#include "../../04-MCAL/01-DIO/DIO_Interface.h"
#include "util/delay.h"

#define BUSHBUTTON_PORT DIO_u8PORTC

typedef enum {
	Button_PRESSESD =0,
	Button_RELEASED
}button_state;

typedef struct {
	u8 button_pin;
	button_state button;
}Button;

void BushButton_voidInit(Button *button);
u8 BushButton_voidRead(Button *button);

#endif /* BUSHBUTTON_INTERFACE_H_ */
