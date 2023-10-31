/*****************************************************************************/
/* Author       	: 	Embedded Tech                                        */
/* Origin Date  	: 	19/10/2023                                           */
/* Layer    	    : 	APP Layer	                                         */
/* SWC	            : 	SW Function                                          */
/* Version      	: 	2                                                    */
/*****************************************************************************/


#ifndef APP_H_
#define APP_H_

/* Section Includes */
/* we use drivers:
 * from MCAL:
 * 1- DIO
 * 2- ADC
 * 3- TIMER1
 * from HAL:
 * 1- LCD
 * 2- KPD
 * 3- DC_MOTOR
 * 4- LM35
 * 5- LED
 * 6- LDR
 * 7- SERVO_MOTOR
 *  */
#include "../01-LIB/BIT_MATH.h"
#include "../01-LIB/STD_TYPES.h"
#include "../04-MCAL/01-DIO/DIO_Interface.h"
#include "../04-MCAL/03-ADC/ADC_Interface.h"
#include "../03-HAL/01-LED/LED_Interface.h"
#include "../03-HAL/03-BUSH_BUTTON/BushButton_Interface.h"
#include "../03-HAL/04-CLCD/CLCD_Interface.h"
#include "../03-HAL/05-KPD/KPD_Interface.h"
#include "../03-HAL/06-DC_MOTOR/DC_Motor_Interface.h"
#include "../03-HAL/07-LM35/LM35_Interface.h"
#include "../03-HAL/09-LDR/LDR_Interface.h"
#include "../03-HAL/10-SERVO_MOTOR/SERVO_INTERFACE.h"

/* Section Macro */
#define MAX_LOGIN_TRIES 3
#define BUZZER_PORT DIO_u8PORTA
#define BUZZER_PIN  DIO_U8PIN7
#define MOTOR_PORT  DIO_u8PORTA
#define MOTOR_PIN1  DIO_U8PIN5
#define MOTRO_PIN2  DIO_U8PIN6
#define LED_PIN     DIO_U8PIN2
#define DIMMER_LED  DIO_U8PIN3
#define LM35_PIN    DIO_U8PIN0
#define LDR_PIN     DIO_U8PIN1
#define SERVO_MOTOR_PORT DIO_u8PORTD
#define SERVO_MOTOR_PIN  DIO_U8PIN5


/* APIs Supported by "APP" */
void app_init(void);
u8 Read_Password(void);
u32 Get_Tempreture_Value(void);
u16 Get_LDR_Value(void);
void DC_MOTOR_ON(void);
void DC_MOTOR_OFF(void);
void BUZZER_ON(void);
void LED_DIMMER(void);
void Halt_System(void);
u32 mapRange(u16 value, u16 fromLow, u16 fromHigh, u16 toLow, u16 toHigh);

#endif /* APP_H_ */
