/*****************************************************************************/
/* Author       	: 	Embedded Tech                                        */
/* Origin Date  	: 	19/10/2023                                           */
/* Layer    	    : 	HAL Layer	                                         */
/* SWC	            : 	LED                                                  */
/* Version      	: 	2                                                    */
/*****************************************************************************/


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

#define LED_PORT DIO_u8PORTA

void LED_voidInit(u8 u8PinNum);
void LEDs_voidInit(u8 u8PinNum);
void LED_voidON(u8 u8PinNum);
void LEDs_voidON(u8 u8PinNum);
void LED_voidOFF(u8 u8PinNum);
void LEDs_voidOFF(u8 u8PinNum);

#endif /* LED_INTERFACE_H_ */
