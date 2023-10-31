/*****************************************************************************/
/* Author       	: 	Embedded Tech                                        */
/* Origin Date  	: 	19/10/2023                                           */
/* Layer    	    : 	APP Layer	                                         */
/* SWC	            : 	SW Function                                          */
/* Version      	: 	2                                                    */
/*****************************************************************************/


#include "app.h"

#define SYSTEM_PSW 1234

void app_init(void){
	/* LCD init */
	CLCD_init();
	/* KPD init */
	KPD_init();
	/* DC_Motor */
	Motor motor;
	motor.motor_port = MOTOR_PORT;
	motor.motor_pin1 = MOTOR_PIN1;
	motor.motor_pin2 = MOTRO_PIN2;
	DCMotor_init(&motor);
	/* ADC init */
	/* LM35 */
	DIO_voidSetPinDirection(DIO_u8PORTA, LM35_PIN, DIO_u8INPUT); //ADC A0 input
	LM35_init();
	/* LDR init */
	DIO_voidSetPinDirection(DIO_u8PORTA, LDR_PIN, DIO_u8INPUT); //ADC A1 input
	LDR_init();
	/* BUZZER init */
	DIO_voidSetPinDirection(DIO_u8PORTA, BUZZER_PIN, DIO_u8OUTPUT);
	/* Servo MOTOR init */
	DIO_voidSetPinDirection(SERVO_MOTOR_PORT, SERVO_MOTOR_PIN, DIO_u8OUTPUT);
	Timer1_FPWM();
	/* LED init */
	LED_voidInit(LED_PIN);
	/* LED Dimmer */
	LED_voidInit(DIMMER_LED);
}

u8 Read_Password(void){
	/*
	 * Read password from keypad
	 * If password is correct, return 0
	 * If password is incorrect, return 1
	 */

    u8 keypad_entry;
    u32 password = 0;
    CLCD_WriteString((u8*)"Your Password: ");
	CLCD_GoTo(2,1);

    while (1) {
        keypad_entry = KPD_GetPressedKey();

        if (keypad_entry == '=') {
            break;
        } else if ((keypad_entry >= '0') && (keypad_entry <= '9')) {
            CLCD_WriteData(keypad_entry);
            _delay_ms(50);
            password += (keypad_entry - 48);
            password *= 10;
        } else { /* Do Nothing */ }
    }

    password /= 10;

    // Check if the entered password is correct
    u8 ret_val = (password == SYSTEM_PSW) ? 0 : 1;
    return ret_val;
}

u32 Get_Tempreture_Value(void){
	u32 ret_val = LM35_CallValue();
	return ret_val;
}

u16 Get_LDR_Value(void){
	u16 adc_val = LDR_CallValue();
	return adc_val;
}

void DC_MOTOR_ON(void){
	Motor motor;
	motor.motor_port = MOTOR_PORT;
	motor.motor_pin1 = MOTOR_PIN1;
	motor.motor_pin2 = MOTRO_PIN2;
	DCMotor_SetCW(&motor);
}
void DC_MOTOR_OFF(void){
	Motor motor;
	motor.motor_port = MOTOR_PORT;
	motor.motor_pin1 = MOTOR_PIN1;
	motor.motor_pin2 = MOTRO_PIN2;
	DCMotor_OFF(&motor);
}

void BUZZER_ON(void){
	DIO_voidSetPinValue(BUZZER_PORT, BUZZER_PIN, DIO_u8HIGH);
}

void LED_DIMMER(void){
	LED_voidON(DIMMER_LED);
}

void Halt_System(void){
	CLCD_DisplayClear();
	CLCD_WriteString((u8*)"System is Halt");
	while(1){
		BUZZER_ON();
	}
}

u32 mapRange(u16 value, u16 fromLow, u16 fromHigh, u16 toLow, u16 toHigh) {
	u16 sourceRange = fromHigh - fromLow;
	u16 targetRange = toHigh - toLow;

    f32 scaledValue = (value - fromLow) / sourceRange;
    u32 result = toLow + scaledValue * targetRange;

    return result;
}

