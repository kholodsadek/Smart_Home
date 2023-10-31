/*****************************************************************************/
/* Author       	: 	Embedded Tech                                        */
/* Origin Date  	: 	19/10/2023                                           */
/* Layer    	    : 	HAL Layer	                                         */
/* SWC	            : 	LM35                                                 */
/* Version      	: 	2                                                    */
/*****************************************************************************/


#ifndef LM35_INTERFACE_H_
#define LM35_INTERFACE_H_

#define ADC_CHANNEL ADC_CHANNEL_A0

void LM35_init(void);
u32 LM35_CallValue(void);

#endif /* LM35_INTERFACE_H_ */
