/*****************************************************************************/
/* Author       	: 	Embedded Tech                                        */
/* Origin Date  	: 	19/10/2023                                           */
/* Layer    	    : 	MCAL Layer	                                         */
/* SWC	            :   EXT_INT                                              */
/* Version      	: 	2                                                    */
/*****************************************************************************/

#ifndef EXTI_INTERFACE_H_
#define EXTI_INTERFACE_H_

#include "../../01-LIB/BIT_MATH.h"
#include "../../01-LIB/STD_TYPES.h"


void EXTI_init(void);
void EXTI_SetCallBack(void (*ptr_to_fun)(void),u8 IntID);

#endif /* EXTI_INTERFACE_H_ */
