/******************************************************************************
*
* Author: Mohammed Ammar
*
* Layer: HAL (Hardware Abstraction Layer)
*
* SWC:LCD
*
* Version: 1.0
*
* Description:
*   This header file serves as a bridge between the 7SEGMENT module and the lower-level
*   hardware abstraction layer. It includes necessary configurations and defines
*   to establish communication with the 7SEGMENT hardware. This module is designed to
*   interface with 7-segment displays for numeric display purposes.
*
******************************************************************************/
#include "interface.h"
#include  <util/delay.h>

// void CLCD_u8Sendcommand(const u8 Copy_u8command)
// {
// 
// 	/* SET RS PIN TO HIGH FOR DATA */
// 	DIO_u8SetPinValue(CLCD_Ctrl_Port,CLCD_RS_pin,DIO_u8PIN_LOW);
// 	
// 	/* SET RW PIN TO LOW FOR WRITE */
// 	DIO_u8SetPinValue(CLCD_Ctrl_Port,CLCD_RW_pin,DIO_u8PIN_LOW);
// 	
// 	/* SET COMANDS  TO DATA PINS */
// 
// 	DIO_u8SetPinValue(CLCD_Data_Port,(CLCD_D7),GET_BIT(Copy_u8command,(7)));
// 	DIO_u8SetPinValue(CLCD_Data_Port,(CLCD_D6),GET_BIT(Copy_u8command,(6)));
// 	DIO_u8SetPinValue(CLCD_Data_Port,(CLCD_D5),GET_BIT(Copy_u8command,(5)));
// 	DIO_u8SetPinValue(CLCD_Data_Port,(CLCD_D4),GET_BIT(Copy_u8command,(4)));
// 	/* SEND ENABLE PULSE */
// 	DIO_u8SetPinValue(CLCD_Ctrl_Port,CLCD_E_pin,DIO_u8PIN_HIGH);
// 	_delay_ms(2);
// 	DIO_u8SetPinValue(CLCD_Ctrl_Port,CLCD_E_pin,DIO_u8PIN_LOW);
// 	
// 	DIO_u8SetPinValue(CLCD_Data_Port,(CLCD_D7),GET_BIT(Copy_u8command,(3)));
// 	DIO_u8SetPinValue(CLCD_Data_Port,(CLCD_D6),GET_BIT(Copy_u8command,(2)));
// 	DIO_u8SetPinValue(CLCD_Data_Port,(CLCD_D5),GET_BIT(Copy_u8command,(1)));
// 	DIO_u8SetPinValue(CLCD_Data_Port,(CLCD_D4),GET_BIT(Copy_u8command,(0)));
// 	/* SEND ENABLE PULSE */
// 	DIO_u8SetPinValue(CLCD_Ctrl_Port,CLCD_E_pin,DIO_u8PIN_HIGH);
// 	_delay_ms(2);
// 	DIO_u8SetPinValue(CLCD_Ctrl_Port,CLCD_E_pin,DIO_u8PIN_LOW);
// }
// 
// void CLCD_u8Senddata(const u8 Copy_u8data)
// {
// 
// 	/* SET RS PIN TO HIGH FOR  */
// 	DIO_u8SetPinValue(CLCD_Ctrl_Port,CLCD_RS_pin,DIO_u8PIN_HIGH);
// 	
// 	/* SET RW PIN TO LOW FOR WRITE */
// 	DIO_u8SetPinValue(CLCD_Ctrl_Port,CLCD_RW_pin,DIO_u8PIN_LOW);
// 	
// 	/* SET DATA  TO DATA PINS */
// 	DIO_u8SetPinValue(CLCD_Data_Port,(CLCD_D7),GET_BIT(Copy_u8data,7));
// 	DIO_u8SetPinValue(CLCD_Data_Port,(CLCD_D6),GET_BIT(Copy_u8data,6));
// 	DIO_u8SetPinValue(CLCD_Data_Port,(CLCD_D5),GET_BIT(Copy_u8data,5));
// 	DIO_u8SetPinValue(CLCD_Data_Port,(CLCD_D4),GET_BIT(Copy_u8data,4));
// 	/* SEND ENABLE PULSE */
// 	DIO_u8SetPinValue(CLCD_Ctrl_Port,CLCD_E_pin,DIO_u8PIN_HIGH);
// 	_delay_ms(2);
// 	DIO_u8SetPinValue(CLCD_Ctrl_Port,CLCD_E_pin,DIO_u8PIN_LOW);
// 	DIO_u8SetPinValue(CLCD_Data_Port,(CLCD_D7),GET_BIT(Copy_u8data,3));
// 	DIO_u8SetPinValue(CLCD_Data_Port,(CLCD_D6),GET_BIT(Copy_u8data,2));
// 	DIO_u8SetPinValue(CLCD_Data_Port,(CLCD_D5),GET_BIT(Copy_u8data,1));
// 	DIO_u8SetPinValue(CLCD_Data_Port,(CLCD_D4),GET_BIT(Copy_u8data,0));
// 	/* SEND ENABLE PULSE */
// 	DIO_u8SetPinValue(CLCD_Ctrl_Port,CLCD_E_pin,DIO_u8PIN_HIGH);
// 	_delay_ms(2);
// 	DIO_u8SetPinValue(CLCD_Ctrl_Port,CLCD_E_pin,DIO_u8PIN_LOW);
// }

void CLCD_u8Intialize()
{
	DIO_u8SetPinDirection(CLCD_Data_Port,CLCD_D4,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_Data_Port,CLCD_D5,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_Data_Port,CLCD_D6,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_Data_Port,CLCD_D7,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_Ctrl_Port,CLCD_E_pin,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_Ctrl_Port,CLCD_RS_pin,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_Ctrl_Port,CLCD_RW_pin,DIO_u8PIN_OUTPUT);
	/* WAIT FOR MORE THAN 30MS */
	_delay_ms(40);
	
	/*FUNCTION SET COMMANDS: */
	
	CLCD_u8Sendcommand(0b00000010);
	CLCD_u8Sendcommand(0b00100000);
	#if ((ClCd_n_oflines == ClCD_u8twolines) && (CLCD_font_size == CLCD_5x11))
	CLCD_u8Sendcommand(0b11000000);
	#elif ((ClCd_n_oflines ==ClCD_u8twolines) && (CLCD_font_size == CLCD_5x8))
	CLCD_u8Sendcommand(0b10000000);
	#elif ((ClCd_n_oflines ==CLCD_u8oneline) &&(CLCD_font_size == CLCD_5x11))
	CLCD_u8Sendcommand(0b01000000);
	#elif ((ClCd_n_oflines ==CLCD_u8oneline) &&(CLCD_font_size == CLCD_5x8))
	CLCD_u8Sendcommand(0b00000000);
	#endif

	/* DISPLAY ON OFF CONTROL */

	#if ((CLCD_cursor==ClCD_u8_cursorenable) && (CLCD_cursorblink==ClCD_u8_cursornoblink))
	CLCD_u8Sendcommand(0b00001110);
	#elif ((CLCD_cursor==ClCD_u8_cursorenable) && (CLCD_cursorblink==ClCD_u8_cursorblink))
	CLCD_u8Sendcommand(0b00001111);
	#elif ((CLCD_cursor==ClCD_u8_cursordisable))
	CLCD_u8Sendcommand(0b00001100);
	#endif

	/* CLEAR DISPLAY */
	  CLCD_u8Sendcommand(1);
	  /*0b00000010*/
	  CLCD_u8Sendcommand(0x02);
	  /*0b00101000*/
	  CLCD_u8Sendcommand(0x28);
	  /*0b00001100*/
	  CLCD_u8Sendcommand(0x0C);
	  /*0b00000110*/
	  CLCD_u8Sendcommand(0x06);
	  /*0b00000110*/
	  CLCD_u8Sendcommand(0x06);
	  /*0b00000001*/
	  CLCD_u8Sendcommand(0x01);
  
	
}
void CLCD_u8Sendstring(char* copy_u8string)
{
	while(*copy_u8string!=NULL)
	{
		CLCD_u8Senddata((*copy_u8string));
		copy_u8string++;
	}
}

void CLCD_u8Movecursor(const u8 copy_u8Xcordinates,const u8 copy_u8Ycordinates)
{
	u8 Local_u8Address=0;
	switch(copy_u8Xcordinates)
	{
		case 0: Local_u8Address=copy_u8Ycordinates;break;
		case 1: Local_u8Address=(copy_u8Ycordinates+0x40);break;
	}
	CLCD_u8Sendcommand((0x80+Local_u8Address));
}

void CLCD_u8Sendspecialcharacter(const char* copy_u8character,const u8 copy_u8block,const u8 copy_u8Xcordinates,const u8 copy_u8Ycordinates)
{
	u8 Local_u8CGRam_Address,i;
	Local_u8CGRam_Address=(copy_u8block*8);
	CLCD_u8Sendcommand((64+Local_u8CGRam_Address));
	for (i=0;i<8;i++)
	{
		
		CLCD_u8Senddata((copy_u8character[i]));
	}
	CLCD_u8Movecursor(copy_u8Xcordinates,copy_u8Ycordinates);
	CLCD_u8Senddata(copy_u8block);
}


void CLCD_u8Sendnumber(u32 Copy_s32Number)
{
	s32 temp = 1;
	if (Copy_s32Number==0)
	{
		CLCD_u8Senddata('0');
	}
	else if (Copy_s32Number<0)
	{
		CLCD_u8Senddata('-');
		Copy_s32Number*=-1;
	}
	while(Copy_s32Number!=0)
	{
		temp = ((temp*10)+(Copy_s32Number%10));
		Copy_s32Number/=10;
	}
	while(temp!=1)
	{
		CLCD_u8Senddata((temp%10)+48);
		temp = temp/10;
	}
}