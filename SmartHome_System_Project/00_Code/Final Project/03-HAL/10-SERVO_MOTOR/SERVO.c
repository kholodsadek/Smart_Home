/*
 * SERVO.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: AFAQE
 */
#include "../../01-LIB/STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"

#include "../../04-MCAL/04-TIMER1/Timer1_registers.h"
/*****************************************************************************/
/* Author       	: 	Embedded Tech                                        */
/* Origin Date  	: 	19/10/2023                                           */
/* Layer    	    : 	HAL Layer	                                         */
/* SWC	            :   SERVO MOTOR                                          */
/* Version      	: 	2                                                    */
/*****************************************************************************/

#include "SERVO_INTERFACE.h"
void Timer1_FPWM(void)
{
	/*FAST PWM*/
	CLR_BIT(TIMER_u8_TCCR1A_REG ,TCCR1A_WGM10);
	SET_BIT(TIMER_u8_TCCR1A_REG ,TCCR1A_WGM11);
	SET_BIT(TIMER_u8_TCCR1B_REG ,TCCR1B_WGM12);
	SET_BIT(TIMER_u8_TCCR1B_REG ,TCCR1B_WGM13);

	/*clear OSR1A*/
	CLR_BIT(TIMER_u8_TCCR1A_REG ,TCCR1A_COM1A0);
	SET_BIT(TIMER_u8_TCCR1A_REG ,TCCR1A_COM1A1);

	/*Time over flow */
	TIMER_u16_ICR1_REG = 19999;

	/*CLOCK/8*/
	CLR_BIT(TIMER_u8_TCCR1B_REG ,TCCR1B_CS10);
	SET_BIT(TIMER_u8_TCCR1B_REG ,TCCR1B_CS11);
	CLR_BIT(TIMER_u8_TCCR1B_REG ,TCCR1B_CS12);


}


void Servo_Angle(u8 angle )
{
	TIMER_u16_OCR1A_REG = ((50*angle )+8991)/9;

}
