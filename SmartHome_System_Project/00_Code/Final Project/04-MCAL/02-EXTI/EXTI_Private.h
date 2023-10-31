/*****************************************************************************/
/* Author       	: 	Embedded Tech                                        */
/* Origin Date  	: 	19/10/2023                                           */
/* Layer    	    : 	MCAL Layer	                                         */
/* SWC	            :   EXT_INT                                              */
/* Version      	: 	2                                                    */
/*****************************************************************************/


#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_

#define MCUCR       *((volatile u8 *)0x55) //GIE INTERUPT1
#define MCUCUR      *((volatile u8 *)0x54) //GIE INTERUPT2
#define GICR        *((volatile u8 *)0x5B) //PIE
#define GIFR        *((volatile u8 *)0x5A) //PIF
#define SREG        *((volatile u8 *)0x5F) //GIE

#define ISC00   0
#define ISC01   1
#define ISC10   2
#define ISC11   3
#define INT0    6
#define INT1    7
#define INT2    5
#define ISC2    6

void __vector_1 (void) __attribute__((signal));
void __vector_2 (void) __attribute__((signal));
void __vector_3 (void) __attribute__((signal));


#endif /* EXTI_PRIVATE_H_ */
