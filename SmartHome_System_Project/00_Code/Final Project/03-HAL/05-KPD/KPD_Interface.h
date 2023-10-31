/*****************************************************************************/
/* Author       	: 	Embedded Tech                                        */
/* Origin Date  	: 	19/10/2023                                           */
/* Layer    	    : 	HAL Layer	                                         */
/* SWC	            : 	KPD                                                  */
/* Version      	: 	2                                                    */
/*****************************************************************************/

#ifndef KPD_INTERFACE_H_
#define KPD_INTERFACE_H_

#include "../../01-LIB/BIT_MATH.h"
#include "../../01-LIB/STD_TYPES.h"
#include "../../04-MCAL/01-DIO/DIO_Interface.h"
#include "util/delay.h"

#define KPD_PORT DIO_u8PORTC

void KPD_init(void);
u8 KPD_GetPressedKey(void);

#endif /* KPD_INTERFACE_H_ */
