/*****************************************************************************/
/* Author       	: 	Embedded Tech                                        */
/* Origin Date  	: 	19/10/2023                                           */
/* Layer    	    : 	MCAL Layer	                                         */
/* SWC	            :   DIO                                                  */
/* Version      	: 	2                                                    */
/*****************************************************************************/


#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

#define DIO_u8PORTA 1
#define DIO_u8PORTB 2
#define DIO_u8PORTC 3
#define DIO_u8PORTD 4

#define DIO_u8OUTPUT 1
#define DIO_u8INPUT  0

#define DIO_u8HIGH 1
#define DIO_u8LOW  0

#define DIO_U8PIN0 0
#define DIO_U8PIN1 1
#define DIO_U8PIN2 2
#define DIO_U8PIN3 3
#define DIO_U8PIN4 4
#define DIO_U8PIN5 5
#define DIO_U8PIN6 6
#define DIO_U8PIN7 7

void DIO_voidSetPinDirection(u8 Copy_u8PortNum, u8 Copy_u8PinNum, u8 Copy_u8Mode);
void DIO_voidSetPinValue(u8 Copy_u8PortNum, u8 Copy_u8PinNum, u8 Copy_u8Value);
void DIO_voidSetPortDirection(u8 Copy_u8PortNum, u8 Copy_u8Mode);
void DIO_voidSetPortValue(u8 Copy_u8PortNum, u8 Copy_u8Value);
void DIO_voidToggleValue(u8 Copy_u8PortNum, u8 Copy_u8PinNum);
u8 DIO_u8GetPinValue(u8 Copy_u8PortNum, u8 Copy_u8PinNum);


#endif //DIO_INTERFACE_H
