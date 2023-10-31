/*****************************************************************************/
/* Author       	: 	Embedded Tech                                        */
/* Origin Date  	: 	19/10/2023                                           */
/* Layer    	    : 	HAL Layer	                                         */
/* SWC	            : 	DC MOTOR                                             */
/* Version      	: 	2                                                    */
/*****************************************************************************/

#ifndef DC_MOTOR_INTERFACE_H_
#define DC_MOTOR_INTERFACE_H_

#include "../../01-LIB/STD_TYPES.h"
#include "../../04-MCAL/01-DIO/DIO_Interface.h"

typedef struct{
	u8 motor_port;
	u8 motor_pin1;
	u8 motor_pin2;
} Motor;


void DCMotor_init(Motor *motor);
void DCMotor_OFF(Motor *motor);
void DCMotor_SetCW(Motor *motor);
void DCMotor_SetCCW(Motor *motor);


#endif /* DC_MOTOR_INTERFACE_H_ */
