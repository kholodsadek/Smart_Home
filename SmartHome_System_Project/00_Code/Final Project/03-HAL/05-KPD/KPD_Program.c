/*****************************************************************************/
/* Author       	: 	Embedded Tech                                        */
/* Origin Date  	: 	19/10/2023                                           */
/* Layer    	    : 	HAL Layer	                                         */
/* SWC	            : 	KPD                                                  */
/* Version      	: 	2                                                    */
/*****************************************************************************/


#include "KPD_Interface.h"


u8 static KPD_Arr[4][4] = { {'7','8','9','/'},
							{'4','5','6','*'},
							{'1','2','3','-'},
							{'C','0','=','+'} };

void KPD_init(void){
	//R0->R3 (rows)    //C0->C3 //0x0f
	//C0->C3 (columns) //C4->C7 //0xf0
	for (u8 i=0;i<4;i++){
		DIO_voidSetPinDirection(KPD_PORT, i, DIO_u8OUTPUT);
	}
	for (u8 i=4;i<8;i++){
		DIO_voidSetPinDirection(KPD_PORT, i, DIO_u8INPUT);
	}
	DIO_voidSetPortValue(KPD_PORT, 0xff); //PORTC =
}

u8 KPD_GetPressedKey(void){
	u8 Key = 0;
	u8 row,col;
	for (row = 0; row < 4; row++){
		DIO_voidSetPinValue(KPD_PORT, row, DIO_u8LOW);
		for(col = 4; col < 8; col++){
			if (DIO_u8GetPinValue(KPD_PORT, col) == 0){
				_delay_ms(30);
				if (DIO_u8GetPinValue(KPD_PORT, col) == 0){
					while(DIO_u8GetPinValue(KPD_PORT, col) == 0);
					Key = KPD_Arr[row][col-4];
					DIO_voidSetPinValue(KPD_PORT,row,DIO_u8HIGH);
				}
			}
		}
		DIO_voidSetPinValue(KPD_PORT,row,DIO_u8HIGH);
	}
	//not pressed
	return Key;
}
