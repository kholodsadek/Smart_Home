/*****************************************************************************/
/* Author       	: 	Embedded Tech                                        */
/* Origin Date  	: 	19/10/2023                                           */
/* Layer    	    : 	HAL Layer	                                         */
/* SWC	            : 	LCD                                                  */
/* Version      	: 	2                                                    */
/*****************************************************************************/


#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

#include "../../01-LIB/STD_TYPES.h"
#include "../../01-LIB/BIT_MATH.h"
#include "../../04-MCAL/01-DIO/DIO_Interface.h"

#define CLCD_Control_Port DIO_u8PORTD
#define CLCD_RS_PIN       DIO_U8PIN0
#define CLCD_RW_PIN       DIO_U8PIN1
#define CLCD_EN_PIN       DIO_U8PIN2
#define CLCD_Data_Port    DIO_u8PORTB


void CLCD_init(void);
void CLCD_WriteInes(u8 A_u8Command); //SendCommand
void CLCD_WriteData(u8 Data); //SendData
void CLCD_WriteChar(u8 Char); //SendChar
void CLCD_WriteString(u8 * String); //SendString
void CLCD_GoTo(u8 Row, u8 Col); //MoveTo
void CLCD_DisplayClear(void);
u8 ConvertNumToASCII(u8 Input);
void CLCD_WriteNum(u64 NUM); //SendNumber
void CLCD_PrintBinary(u8 num);
void CLCD_Draw_Char(u8 Address_Data, u8* charArray);
void CLCD_printHEXNum(u8 num);
void CLCD_WriteData_Pos(u8 Data, u8 Row, u8 Col);
void CLCD_WriteString_Pos(u8 *String, u8 Row, u8 Col);
void CLCD_WriteNum_Pos(u64 Num, u8 Row, u8 Col);


#endif /* CLCD_INTERFACE_H_ */
