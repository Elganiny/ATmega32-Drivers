/*********************************************************/
/***********		Author: Amgad Samir 	**************/
/***********		Layer: HAL			 	**************/
/***********		Component: CLCD 		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 14-8/2020		 	**************/
/*********************************************************/


/*Preprocessor file guard*/
#ifndef CLCD_INTERFACE_H_
#define CLCD_INTERFACE_H_

#include "CLCD_config.h"
#include "CLCD_private.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include <util/delay.h>

void CLCD_voidSendCommand(u8 Copy_u8Command);

void CLCD_voidSendData(u8 Copy_u8Data);

void CLCD_voidInit(void);

void CLCD_voidSendString(char* Copy_pcString);

void CLCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos);

void CLCD_voidWriteSpecialCharacter(u8* Copy_u8Pattern, u8 Copy_u8PatternNumber,u8 Copy_u8XPos, u8 Copy_u8YPos);

void CLCD_voidWriteNumber(s32 Copy_u32Number);

#endif
