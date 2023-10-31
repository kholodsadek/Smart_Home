/*****************************************************************************/
/* Author       	: 	Embedded Tech                                        */
/* Origin Date  	: 	19/10/2023                                           */
/* Layer    	    : 	HAL Layer	                                         */
/* SWC	            : 	POT                                                  */
/* Version      	: 	2                                                    */
/*****************************************************************************/


#include "../../01-LIB/STD_TYPES.h"
#include "../../04-MCAL/03-ADC/ADC_Interface.h"
#include "POT_Interface.h"

void POT_init(void){
	ADC_voidInit();
}

void POT_CallValue(u32 * Copy_u8Digital, u32 * Copy_u8Volt){
	u32 Local_u32Digital = ADC_u8StartConversion(ADC_CHANNEL);
	u32 Local_u32Volt    = (Local_u32Digital*5)/1023;

	*Copy_u8Digital = Local_u32Digital;
	*Copy_u8Volt    = Local_u32Volt;
}
