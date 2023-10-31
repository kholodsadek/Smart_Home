/*****************************************************************************/
/* Author       	: 	Embedded Tech                                        */
/* Origin Date  	: 	19/10/2023                                           */
/* Layer    	    : 	HAL Layer	                                         */
/* SWC	            : 	LCD                                                  */
/* Version      	: 	2                                                    */
/*****************************************************************************/

#include "util/delay.h"
#include "../04-CLCD/CLCD_Interface.h"

void CLCD_init(void){
	/* data port output */
	DIO_voidSetPortDirection(CLCD_Data_Port, 255);
	/* RS output */
	DIO_voidSetPinDirection(CLCD_Control_Port, CLCD_RS_PIN, DIO_u8OUTPUT);
	/* RW output */
	DIO_voidSetPinDirection(CLCD_Control_Port, CLCD_RW_PIN, DIO_u8OUTPUT);
	/* EN output */
	DIO_voidSetPinDirection(CLCD_Control_Port, CLCD_EN_PIN, DIO_u8OUTPUT);
	_delay_ms(50);
	CLCD_WriteInes(0x38); //0b00111000 //FUNCTION_SET
	CLCD_WriteInes(0x0C); //0b00001111 //DISPLAY_ON
	CLCD_WriteInes(0x01); //0b00000001 //DISPLAY_CLEAR
	_delay_ms(1);
	CLCD_WriteInes(0x06); //0b00000110 //ENTRY_MODE_SET
}

void CLCD_WriteInes(u8 A_u8Command){
	/* RS = 0 (Command mode) */
	DIO_voidSetPinValue(CLCD_Control_Port, CLCD_RS_PIN, DIO_u8LOW); //send commend
	/* RW = 0 (Write mode) */
	DIO_voidSetPinValue(CLCD_Control_Port, CLCD_RW_PIN, DIO_u8LOW);
	/* send command through the port */
	DIO_voidSetPortValue(CLCD_Data_Port, A_u8Command); //function set
	/* Enable sequence */
	DIO_voidSetPinValue(CLCD_Control_Port, CLCD_EN_PIN, DIO_u8HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(CLCD_Control_Port,CLCD_EN_PIN, DIO_u8LOW);
	_delay_ms(1);
}

void CLCD_WriteData(u8 Data){
	/* RS = 1 (Command mode) */
	DIO_voidSetPinValue(CLCD_Control_Port, CLCD_RS_PIN, DIO_u8HIGH); //send commend
	/* RW = 0 (Write mode) */
	DIO_voidSetPinValue(CLCD_Control_Port, CLCD_RW_PIN, DIO_u8LOW);
	/* send command through the port */
	DIO_voidSetPortValue(CLCD_Data_Port, Data); //function set
	/* Enable sequence */
	DIO_voidSetPinValue(CLCD_Control_Port, CLCD_EN_PIN, DIO_u8HIGH);
	_delay_ms(1);
	DIO_voidSetPinValue(CLCD_Control_Port,CLCD_EN_PIN, DIO_u8LOW);
	_delay_ms(1);
}

void CLCD_WriteChar(u8 Char){
	CLCD_WriteData(Char);
}

void CLCD_WriteString(u8 * String){
	while (*String != '\0'){
		CLCD_WriteData(*String);
		String++;
	}
}

void CLCD_GoTo(u8 Row, u8 Col){
	Col--;
	Row--;

	switch(Row)
	{
		case 0: CLCD_WriteInes(0x80+Col); break;
		case 1: CLCD_WriteInes(0xC0+Col); break;
		case 2: CLCD_WriteInes(0x94+Col); break;
		case 3: CLCD_WriteInes(0xD4+Col); break;
	}
}

void CLCD_DisplayClear(void){
	CLCD_WriteInes(0x01);
}

u8 ConvertNumToASCII(u8 Input){
	return Input+0x30;
}

s32 CLCD_ReverseNumber(s32 NUM){
	u32 reverse=1;
	while(NUM!=0)
	{
		reverse=(reverse*10)+(NUM%10);
		NUM/=10;
	}
	return reverse;
}

void CLCD_WriteNum(u64 NUM) {
	if (NUM == 0){
		CLCD_WriteData((NUM%10)+48);
	}
	else{
		u64 reverse=1;
		reverse = CLCD_ReverseNumber(NUM);
		while(reverse!=1)
		{
			CLCD_WriteData((reverse%10)+48);
			reverse/=10;
		}
	}
}

void CLCD_PrintBinary(u8 num){
	for(s8 i=7; i>=0; i--){
		CLCD_WriteData(GET_BIT(num,i)?'1':'0');
	}
}

/*u8 arr[] = {
		0x00,
		0x00,
		0x07,
		0x04,
		0x1F,
		0x00,
		0x00,
		0x00
};//-----------print*/
u8 arr_2[] = {
  0x00,
  0x00,
  0x07,
  0x05,
  0x1F,
  0x10,
  0x10,
  0x10
};

void CLCD_Draw_Char(u8 Address_Data, u8* charArray) {
    CLCD_WriteInes(0x40 | (Address_Data * 8)); // Set CGRAM address
    for (u8 j = 0; j < 8; j++) {
        CLCD_WriteData(charArray[j]);
    }
    CLCD_WriteInes(0x80); // Set DDRAM address to return to the display area
}

void CLCD_printHEXNum(u8 num){
	u8 decimalS[] = "Decimal: ";
	u8 hexS[] = 	"Hex: ";
	u8 st[] = "0x";
	u8 Upper =0 , Lower = 0;
	Upper = num >>4;
	Lower = num &0x0f;

	CLCD_WriteString(decimalS);
	CLCD_WriteNum(num);
	CLCD_GoTo(2,1);
	CLCD_WriteString(hexS);
	CLCD_WriteString(st);

	if (Upper < 10){
		CLCD_GoTo(2,8);
		CLCD_WriteData(Upper + '0');
	}
	else {
		CLCD_GoTo(2,8);
		CLCD_WriteData(Upper + 'A'-10);
	}
	if (Lower < 10){
		CLCD_GoTo(2,9);
		CLCD_WriteData(Lower + '0');
	}
	else {
		CLCD_GoTo(2,9);
		CLCD_WriteData(Lower + 'A'-10);
	}
}

void CLCD_WriteData_Pos(u8 Data, u8 Row, u8 Col){
	CLCD_GoTo(Row,Col);
	CLCD_WriteData(Data);
}

void CLCD_WriteString_Pos(u8 *String, u8 Row, u8 Col){
	CLCD_GoTo(Row,Col);
	CLCD_WriteString(String);
}

void CLCD_WriteNum_Pos(u64 Num, u8 Row, u8 Col){
	CLCD_GoTo(Row,Col);
	CLCD_WriteNum(Num);
}
