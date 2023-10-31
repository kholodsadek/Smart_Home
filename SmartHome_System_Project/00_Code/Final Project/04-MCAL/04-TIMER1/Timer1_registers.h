/*****************************************************************************/
/* Author       	: 	Embedded Tech                                        */
/* Origin Date  	: 	19/10/2023                                           */
/* Layer    	    : 	MCAL Layer	                                         */
/* SWC	            :   TIMER                                                */
/* Version      	: 	2                                                    */
/*****************************************************************************/

#ifndef TIMER1_REGISTERS_H
#define TIMER1_REGISTERS_H

#define HWREG8(X)       *((volatile u8*)(X))
#define HWREG16(X)      *((volatile u16*)(X))

#define TIMER_u8_TCCR1A_REG    HWREG8(0x4F)
#define TCCR1A_WGM10           0
#define TCCR1A_WGM11           1
#define TCCR1A_COM1B0          4
#define TCCR1A_COM1B1          5
#define TCCR1A_COM1A0          6
#define TCCR1A_COM1A1          7

#define TIMER_u8_TCCR1B_REG    HWREG8(0x4E)
#define TCCR1B_CS10            0
#define TCCR1B_CS11            1
#define TCCR1B_CS12            2
#define TCCR1B_WGM12           3
#define TCCR1B_WGM13           4

#define TIMER_u8_TCNT1L_REG    HWREG8(0x4C)
#define TIMER_u8_TCNT1H_REG    HWREG8(0x4D)
#define TIMER_u16_TCNT1_REG    HWREG16(0x4C)

#define TIMER_u8_OCR1AL_REG    HWREG8(0x4A)
#define TIMER_u8_OCR1AH_REG    HWREG8(0x4B)
#define TIMER_u16_OCR1A_REG    HWREG16(0x4A)

#define TIMER_u8_OCR1BL_REG    HWREG8(0x48)
#define TIMER_u8_OCR1BH_REG    HWREG8(0x49)
#define TIMER_u16_OCR1B_REG    HWREG16(0x48)
 
#define TIMER_u8_ICR1L_REG     HWREG8(0x46)
#define TIMER_u8_ICR1H_REG     HWREG8(0x47)
#define TIMER_u16_ICR1_REG     HWREG16(0x46)
 
#define TIMER_u8_TIMSK_REG     HWREG8(0x59)

#define TIMER_u8_TIFR_REG      HWREG8(0x85)


#endif
