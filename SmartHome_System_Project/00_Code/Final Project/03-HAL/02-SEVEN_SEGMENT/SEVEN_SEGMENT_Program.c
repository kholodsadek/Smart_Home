/*****************************************************************************/
/* Author       	: 	Embedded Tech                                        */
/* Origin Date  	: 	19/10/2023                                           */
/* Layer    	    : 	HAL Layer	                                         */
/* SWC	            : 	SSD                                                  */
/* Version      	: 	2                                                    */
/*****************************************************************************/

#include "../../01-LIB/STD_TYPES.h"
#include "../../04-MCAL/01-DIO/DIO_Interface.h"
#include "SEVEN_SEGMENT_Interface.h"
#include "util/delay.h"

u32 SSD_Arr[10] = {ZERO,ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};

void SevenSegments_voidInit(){
	DIO_voidSetPortDirection(SEVEN_SEGMENT_PORT, 0xff);
	DIO_voidSetPortDirection(SEVEN_SEGMENT_PORT2, 0xff);
}

void SevenSegments_voidDispalyDecreasecount(u8 Copy_u8Seconds){
	u8 i;
	if (Copy_u8Seconds < 10){
		for(i = Copy_u8Seconds; i > 0; i--)
		{
			DIO_voidSetPortValue(SEVEN_SEGMENT_PORT, SSD_Arr[i]);
			_delay_ms(500);
		}
	} else if (Copy_u8Seconds < 99){
		u8 fnum,snum;
		for(i = Copy_u8Seconds; i > 0; i--)
		{
			fnum = i/10;
			snum = i%10;
			DIO_voidSetPortValue(SEVEN_SEGMENT_PORT, SSD_Arr[fnum]);
			DIO_voidSetPortValue(SEVEN_SEGMENT_PORT2, SSD_Arr[snum]);
			_delay_ms(500);
		}
	}
}

void SevenSegments_voidDispaly(u8 Copy_u8Value){
	if (Copy_u8Value < 10){
		DIO_voidSetPortValue(SEVEN_SEGMENT_PORT2, SSD_Arr[Copy_u8Value]);
		DIO_voidSetPortValue(SEVEN_SEGMENT_PORT, SSD_Arr[0]);
		_delay_ms(200);
	} else if (Copy_u8Value < 100){
		u8 fnum = 0 , snum = 0;
		fnum = Copy_u8Value/10;
		snum = Copy_u8Value%10;
		DIO_voidSetPortValue(SEVEN_SEGMENT_PORT, SSD_Arr[fnum]);
		DIO_voidSetPortValue(SEVEN_SEGMENT_PORT2, SSD_Arr[snum]);
		_delay_ms(200);
	}
}

void SevenSegment_voidInit(void){
	DIO_voidSetPortDirection(SEVEN_SEGMENT_PORT, 0xff);
}

void SevenSegment_voidDispaly(u8 Copy_u8Value){
	DIO_voidSetPortValue(SEVEN_SEGMENT_PORT, SSD_Arr[Copy_u8Value]);
}
