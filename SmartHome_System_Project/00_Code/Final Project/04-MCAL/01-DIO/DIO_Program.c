/*****************************************************************************/
/* Author       	: 	Embedded Tech                                        */
/* Origin Date  	: 	19/10/2023                                           */
/* Layer    	    : 	MCAL Layer	                                         */
/* SWC	            :   DIO                                                  */
/* Version      	: 	2                                                    */
/*****************************************************************************/

#include "../../01-LIB/STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"
#include "DIO_Config.h"
#include "DIO_Interface.h"
#include "DIO_Private.h"

void DIO_voidSetPinDirection(u8 Copy_u8PortNum, u8 Copy_u8PinNum, u8 Copy_u8Mode){
	if (Copy_u8Mode == DIO_u8OUTPUT){
		switch (Copy_u8PortNum)
		{
			case DIO_u8PORTA: SET_BIT(DDRA, Copy_u8PinNum); break;
			case DIO_u8PORTB: SET_BIT(DDRB, Copy_u8PinNum); break;
			case DIO_u8PORTC: SET_BIT(DDRC, Copy_u8PinNum); break;
			case DIO_u8PORTD: SET_BIT(DDRD, Copy_u8PinNum); break;
			default:    /*return error*/      				 break;
		}
	} else if (Copy_u8Mode == DIO_u8INPUT){
		switch (Copy_u8PortNum)
		{
			case DIO_u8PORTA: CLR_BIT(DDRA, Copy_u8PinNum); break;
			case DIO_u8PORTB: CLR_BIT(DDRB, Copy_u8PinNum); break;
			case DIO_u8PORTC: CLR_BIT(DDRC, Copy_u8PinNum); break;
			case DIO_u8PORTD: CLR_BIT(DDRD, Copy_u8PinNum); break;
			default:    /*return error*/      				 break;
		}
	} else{
		/*return error*/
	}
}
void DIO_voidSetPinValue(u8 Copy_u8PortNum, u8 Copy_u8PinNum, u8 Copy_u8Value){
	if (Copy_u8Value == DIO_u8HIGH){
		switch (Copy_u8PortNum)
		{
			case DIO_u8PORTA: SET_BIT(PORTA, Copy_u8PinNum); break;
			case DIO_u8PORTB: SET_BIT(PORTB, Copy_u8PinNum); break;
			case DIO_u8PORTC: SET_BIT(PORTC, Copy_u8PinNum); break;
			case DIO_u8PORTD: SET_BIT(PORTD, Copy_u8PinNum); break;
			default:    /*return error*/      				  break;
		}
	} else if (Copy_u8Value == DIO_u8LOW){
		switch (Copy_u8PortNum)
		{
			case DIO_u8PORTA: CLR_BIT(PORTA, Copy_u8PinNum); break;
			case DIO_u8PORTB: CLR_BIT(PORTB, Copy_u8PinNum); break;
			case DIO_u8PORTC: CLR_BIT(PORTC, Copy_u8PinNum); break;
			case DIO_u8PORTD: CLR_BIT(PORTD, Copy_u8PinNum); break;
			default:    /*return error*/      				  break;
		}
	} else{
		/*return error*/
	}
}
void DIO_voidSetPortDirection(u8 Copy_u8PortNum, u8 Copy_u8Mode){
	switch (Copy_u8PortNum)
	{
		case DIO_u8PORTA: DDRA = Copy_u8Mode; break;
		case DIO_u8PORTB: DDRB = Copy_u8Mode; break;
		case DIO_u8PORTC: DDRC = Copy_u8Mode; break;
		case DIO_u8PORTD: DDRD = Copy_u8Mode; break;
		default:    /*return error*/      	  break;
	}
}
void DIO_voidSetPortValue(u8 Copy_u8PortNum, u8 Copy_u8Value){
	switch (Copy_u8PortNum)
	{
		case DIO_u8PORTA: PORTA = Copy_u8Value; break;
		case DIO_u8PORTB: PORTB = Copy_u8Value; break;
		case DIO_u8PORTC: PORTC = Copy_u8Value; break;
		case DIO_u8PORTD: PORTD = Copy_u8Value; break;
		default:    /*return error*/      	  break;
	}
}
void DIO_voidToggleValue(u8 Copy_u8PortNum, u8 Copy_u8PinNum){
	switch (Copy_u8PortNum)
	{
		case DIO_u8PORTA: TOGGLE_BIT(PORTA,Copy_u8PinNum); break;
		case DIO_u8PORTB: TOGGLE_BIT(PORTB,Copy_u8PinNum); break;
		case DIO_u8PORTC: TOGGLE_BIT(PORTC,Copy_u8PinNum); break;
		case DIO_u8PORTD: TOGGLE_BIT(PORTD,Copy_u8PinNum); break;
		default:    /*return error*/      	  break;
	}
}
u8 DIO_u8GetPinValue(u8 Copy_u8PortNum, u8 Copy_u8PinNum){
	u8 Local_u8Result = 0;

	switch (Copy_u8PortNum)
	{
		case DIO_u8PORTA: Local_u8Result = GET_BIT(PINA, Copy_u8PinNum); break;
		case DIO_u8PORTB: Local_u8Result = GET_BIT(PINB, Copy_u8PinNum); break;
		case DIO_u8PORTC: Local_u8Result = GET_BIT(PINC, Copy_u8PinNum); break;
		case DIO_u8PORTD: Local_u8Result = GET_BIT(PIND, Copy_u8PinNum); break;
		default:    /*return error*/      								   break;
	}
	return Local_u8Result;
}
