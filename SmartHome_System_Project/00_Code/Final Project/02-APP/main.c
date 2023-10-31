/*****************************************************************************/
/* Author       	: 	Embedded Tech                                        */
/* Origin Date  	: 	19/10/2023                                           */
/* Layer    	    : 	APP Layer	                                         */
/* SWC	            : 	main                                                 */
/* Version      	: 	2                                                    */
/*****************************************************************************/

#include "app.h"


int main(void){
	u8 login_tries = 0;
	u32 temp_value = 0;
	u16 light_value = 0;
	app_init();

	while(1){
		if(Read_Password()){
			login_tries++;
			if(MAX_LOGIN_TRIES <= login_tries)
				Halt_System();
			else{
				CLCD_DisplayClear();
				CLCD_WriteString((u8*)"Try Again!");
				_delay_ms(500);
				CLCD_DisplayClear();
				continue;
			}
		}
		else{
			CLCD_DisplayClear();
			CLCD_WriteString((u8*)"You can Access!");
			_delay_ms(500);
			CLCD_DisplayClear();
			Servo_Angle(180);
			CLCD_WriteString((u8*)"Door is Opened!");
			_delay_ms(1000);
			CLCD_DisplayClear();
			Servo_Angle(0);
			CLCD_WriteString((u8*)"Door is Closed!");
			_delay_ms(1000);
			CLCD_DisplayClear();
			break;
		}
	}


	CLCD_WriteString_Pos((u8*)"Temperature: ",1,1);
	CLCD_WriteString_Pos((u8*)"Light: ",3,1);

	while(1){
		LED_DIMMER();
		temp_value = Get_Tempreture_Value();
		CLCD_WriteNum_Pos(temp_value,1,14);
		CLCD_WriteData_Pos('C',1,16);
		if (temp_value >= 28){
			DC_MOTOR_ON();
			CLCD_WriteString_Pos((u8*)"Air-Condition is ON ",2,1);
		}else if (temp_value < 21){
			DC_MOTOR_OFF();
			CLCD_WriteString_Pos((u8*)"Air-Condition is OFF",2,1);
		}

		light_value = Get_LDR_Value();
		mapRange(light_value, 0, 1024, 0, 100);
		CLCD_WriteNum_Pos(light_value, 3, 8);
		CLCD_WriteData_Pos('%',3,10);
		if (light_value < 50){
			LED_voidON(LED_PIN);
			CLCD_WriteString_Pos((u8*)"LEDs is ON ",4,1);
		}else if (light_value >= 50){
			LED_voidOFF(LED_PIN);
			CLCD_WriteString_Pos((u8*)"LEDs is OFF",4,1);
		}
	}
}
