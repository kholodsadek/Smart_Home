/*****************************************************************************/
/* Author       	: 	Embedded Tech                                        */
/* Origin Date  	: 	19/10/2023                                           */
/* Layer    	    : 	MCAL Layer	                                         */
/* SWC	            :   ADC                                                  */
/* Version      	: 	2                                                    */
/*****************************************************************************/


#include "../../01-LIB/STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"

#include "ADC_Interface.h"
#include "ADC_Private.h"
#include "ADC_Config.h"

void ADC_voidInit(void){
 	 /*select vref : AVCC at reference voltage*/
	SET_BIT(ADMUX, ADMUX_REFS0);
	CLR_BIT(ADMUX, ADMUX_REFS1);

	 /*Activate left adjust result*/
	//CLR_BIT(ADMUX, ADMUX_ADLAR);

	/* no auto trigger */
	CLR_BIT(ADCSRA, ADCSRA_ADATE);

	/* ADC Prescaler Select Bits*/
	SET_BIT(ADCSRA, ADCSRA_ADPS0);
	SET_BIT(ADCSRA, ADCSRA_ADPS1);
	SET_BIT(ADCSRA, ADCSRA_ADPS2);


	ADCSRA &= ADC_PRESC_MASK;
	ADCSRA |= ADC_PRESC;

	/*ADC Enable*/
	SET_BIT(ADCSRA, ADCSRA_ADEN);
}

u16 ADC_u8StartConversion(u8 Copy_u8ChannelNumber){

	/* ADC Set Channel*/
	ADMUX &= ADC_CHANNEL_MASK;
	ADMUX |= Copy_u8ChannelNumber;

	 /*ADC Start Conversion*/
	SET_BIT(ADCSRA, ADCSRA_ADSC);

	/* Wait for conversion Complete flag*/
	while(GET_BIT(ADCSRA, ADCSRA_ADIF) == 0);
	SET_BIT(ADCSRA, ADCSRA_ADIF);

	/* ENABLE ADC*/
	//SET_BIT(ADCSRA, ADCSRA_ADEN);

	return ADC; //ADC Value

}
