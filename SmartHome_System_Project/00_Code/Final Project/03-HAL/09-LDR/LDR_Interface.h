/*****************************************************************************/
/* Author       	: 	Embedded Tech                                        */
/* Origin Date  	: 	19/10/2023                                           */
/* Layer    	    : 	HAL Layer	                                         */
/* SWC	            : 	LDR                                                  */
/* Version      	: 	2                                                    */
/*****************************************************************************/



#ifndef LDR_INTERFACE_H_
#define LDR_INTERFACE_H_

#define ADC_CHANNEL_LDR ADC_CHANNEL_A1

void LDR_init(void);
u16 LDR_CallValue(void);

#endif /* LDR_INTERFACE_H_ */
