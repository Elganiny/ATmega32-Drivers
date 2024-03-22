/*********************************************************/
/***********		Author: Amgad Samir 	**************/
/***********		Layer: HAL			 	**************/
/***********		Component: CLCD 		**************/
/***********		Version: 1.00		 	**************/
/***********		Date: 14-8/2020		 	**************/
/*********************************************************/

#include "CLCD_interface.h"


void CLCD_voidSendCommand(u8 Copy_u8Command)
{
	#if CLCD_MODE == EIGHT_BITS
	/*Set RS pin to low for command*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);

	/*Set RW pin to low for write*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	/*Set command to data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Command);

	/*Send enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
	#elif CLCD_MODE == FOUR_BITS
	
	/* SET RS PIN TO HIGH FOR DATA */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_LOW);
	
	/* SET RW PIN TO LOW FOR WRITE */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
	
	/* SET COMANDS  TO DATA PINS */

	DIO_u8SetPinValue(CLCD_DATA_PORT,(CLCD_D7),GET_BIT(Copy_u8Command,(7)));
	DIO_u8SetPinValue(CLCD_DATA_PORT,(CLCD_D6),GET_BIT(Copy_u8Command,(6)));
	DIO_u8SetPinValue(CLCD_DATA_PORT,(CLCD_D5),GET_BIT(Copy_u8Command,(5)));
	DIO_u8SetPinValue(CLCD_DATA_PORT,(CLCD_D4),GET_BIT(Copy_u8Command,(4)));
	/* SEND ENABLE PULSE */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
	
	DIO_u8SetPinValue(CLCD_DATA_PORT,(CLCD_D7),GET_BIT(Copy_u8Command,(3)));
	DIO_u8SetPinValue(CLCD_DATA_PORT,(CLCD_D6),GET_BIT(Copy_u8Command,(2)));
	DIO_u8SetPinValue(CLCD_DATA_PORT,(CLCD_D5),GET_BIT(Copy_u8Command,(1)));
	DIO_u8SetPinValue(CLCD_DATA_PORT,(CLCD_D4),GET_BIT(Copy_u8Command,(0)));
	/* SEND ENABLE PULSE */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
	#endif
}

void CLCD_voidSendData(u8 Copy_u8Data)
{
	#if CLCD_MODE == EIGHT_BITS
	/*Set RS pin to high for data*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);

	/*Set RW pin to low for write*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);

	/*Set Data to data pins*/
	DIO_u8SetPortValue(CLCD_DATA_PORT,Copy_u8Data);

	/*Send enable pulse*/
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);

	#elif CLCD_MODE == FOUR_BITS
	/* SET RS PIN TO HIGH FOR  */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_HIGH);
	
	/* SET RW PIN TO LOW FOR WRITE */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_LOW);
	
	/* SET DATA  TO DATA PINS */
	DIO_u8SetPinValue(CLCD_DATA_PORT,(CLCD_D7),GET_BIT(Copy_u8Data,7));
	DIO_u8SetPinValue(CLCD_DATA_PORT,(CLCD_D6),GET_BIT(Copy_u8Data,6));
	DIO_u8SetPinValue(CLCD_DATA_PORT,(CLCD_D5),GET_BIT(Copy_u8Data,5));
	DIO_u8SetPinValue(CLCD_DATA_PORT,(CLCD_D4),GET_BIT(Copy_u8Data,4));
	/* SEND ENABLE PULSE */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(CLCD_DATA_PORT,(CLCD_D7),GET_BIT(Copy_u8Data,3));
	DIO_u8SetPinValue(CLCD_DATA_PORT,(CLCD_D6),GET_BIT(Copy_u8Data,2));
	DIO_u8SetPinValue(CLCD_DATA_PORT,(CLCD_D5),GET_BIT(Copy_u8Data,1));
	DIO_u8SetPinValue(CLCD_DATA_PORT,(CLCD_D4),GET_BIT(Copy_u8Data,0));
	/* SEND ENABLE PULSE */
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_HIGH);
	_delay_ms(2);
	DIO_u8SetPinValue(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_LOW);
	#endif
}

void CLCD_voidInit(void)
{
	#if CLCD_MODE == EIGHT_BITS
	DIO_u8SetPortDirection(DIO_u8PORTC,DIO_u8PORT_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN0,DIO_u8PORT_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN1,DIO_u8PORT_OUTPUT);
	DIO_u8SetPinDirection(DIO_u8PORTB,DIO_u8PIN2,DIO_u8PORT_OUTPUT);
	
	/*Wait for more than 30 ms*/
	_delay_ms(40);

	/*Function set command: 2 lines, 5*8 Font size*/
	CLCD_voidSendCommand(0b00111000);

	/*Display on off control: display enable, disable cursor, no blink cursor*/
	CLCD_voidSendCommand(0b00001100);

	/*Clear display*/
	CLCD_voidSendCommand(1);

	#elif CLCD_MODE == FOUR_BITS
	DIO_u8SetPinDirection(CLCD_DATA_PORT,CLCD_D4,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_DATA_PORT,CLCD_D5,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_DATA_PORT,CLCD_D6,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_DATA_PORT,CLCD_D7,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_CTRL_PORT,CLCD_E_PIN,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_CTRL_PORT,CLCD_RS_PIN,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(CLCD_CTRL_PORT,CLCD_RW_PIN,DIO_u8PIN_OUTPUT);
	/* WAIT FOR MORE THAN 30MS */
	_delay_ms(40);
	
	/*FUNCTION SET COMMANDS: */
	
	CLCD_voidSendCommand(0b00000010);
	CLCD_voidSendCommand(0b00100000);
	#if ((ClCd_n_oflines == ClCD_u8twolines) && (CLCD_font_size == CLCD_5x11))
	CLCD_voidSendCommand(0b11000000);
	#elif ((ClCd_n_oflines ==ClCD_u8twolines) && (CLCD_font_size == CLCD_5x8))
	CLCD_voidSendCommand(0b10000000);
	#elif ((ClCd_n_oflines ==CLCD_u8oneline) &&(CLCD_font_size == CLCD_5x11))
	CLCD_voidSendCommand(0b01000000);
	#elif ((ClCd_n_oflines ==CLCD_u8oneline) &&(CLCD_font_size == CLCD_5x8))
	CLCD_voidSendCommand(0b00000000);
	#endif

	/* DISPLAY ON OFF CONTROL */

	#if ((CLCD_cursor==ClCD_u8_cursorenable) && (CLCD_cursorblink==ClCD_u8_cursornoblink))
	CLCD_voidSendCommand(0b00001110);
	#elif ((CLCD_cursor==ClCD_u8_cursorenable) && (CLCD_cursorblink==ClCD_u8_cursorblink))
	CLCD_voidSendCommand(0b00001111);
	#elif ((CLCD_cursor==ClCD_u8_cursordisable))
	CLCD_voidSendCommand(0b00001100);
	#endif

	/* CLEAR DISPLAY */
	  CLCD_voidSendCommand(1);
	  /*0b00000010*/
	  CLCD_voidSendCommand(0x02);
	  /*0b00101000*/
	  CLCD_voidSendCommand(0x28);
	  /*0b00001100*/
	  CLCD_voidSendCommand(0x0C);
	  /*0b00000110*/
	  CLCD_voidSendCommand(0x06);
	  /*0b00000110*/
	  CLCD_voidSendCommand(0x06);
	  /*0b00000001*/
	  CLCD_voidSendCommand(0x01);
	 #endif
}

void CLCD_voidSendString(char* Copy_pcString)
{
	u8 local_u8counter = 0;
	while(Copy_pcString[local_u8counter] != '\0')
	{
		CLCD_voidSendData(Copy_pcString[local_u8counter]);
		local_u8counter++;
	}
}

void CLCD_voidGoToXY(u8 Copy_u8XPos, u8 Copy_u8YPos)
{
#if CLCD_MODE == EIGHT_BITS
	u8 local_u8Address = 0;
	if (Copy_u8XPos == 0)
	{
		local_u8Address = Copy_u8YPos;
	} 
	else if (Copy_u8XPos == 1)
	{
		local_u8Address = Copy_u8YPos + 0x40;
	}
	CLCD_voidSendCommand(local_u8Address + 128);

#elif CLCD_MODE == FOUR_BITS
u8 Local_u8Address=0;
switch(Copy_u8XPos)
{
	case 0: Local_u8Address=Copy_u8YPos;break;
	case 1: Local_u8Address=(Copy_u8YPos+0x40);break;
}
CLCD_voidSendCommand((0x80+Local_u8Address));
 #endif
}

void CLCD_voidWriteSpecialCharacter(u8* Copy_u8Pattern, u8 Copy_u8PatternNumber,u8 Copy_u8XPos, u8 Copy_u8YPos)
{
	u8 local_u8CGRAMAddress = 0, local_u8Iterator = 0;
	
	/*Calculate the CG Ram address whose each block is 8 bytes*/
	local_u8CGRAMAddress = Copy_u8PatternNumber * 8;
	
	/*Send CG Ram address command to LCD, with setting bit 6 , and clearing bit 7*/
	CLCD_voidSendCommand(local_u8CGRAMAddress + 64);
	
	/*Write the pattern into the CG Ram*/
	for (local_u8Iterator = 0;local_u8Iterator < 8;local_u8Iterator++)
	{
		CLCD_voidSendData(Copy_u8Pattern[local_u8Iterator]);
	}
	
	/*Go back to the DDRAM to display the pattern*/
	CLCD_voidGoToXY(Copy_u8XPos,Copy_u8YPos);
	
	/*Display the pattern written in the CG RAM*/
	CLCD_voidSendData(Copy_u8PatternNumber);
	
}

void CLCD_voidWriteNumber(s32 Copy_s32Number)
{
	#if CLCD_MODE == EIGHT_BITS
	s32 temp = 1;
	if (Copy_s32Number==0)
	{
		CLCD_voidSendData('0');
	}
	else if (Copy_s32Number<0)
	{
		CLCD_voidSendData('-');
		Copy_s32Number*=-1;
	}
	while(Copy_s32Number!=0)
	{
		temp = ((temp*10)+(Copy_s32Number%10));
		Copy_s32Number/=10;
	}
	while(temp!=1)
	{
		CLCD_voidSendData((temp%10)+48);
		temp = temp/10;
	}
	
	#elif CLCD_MODE == FOUR_BITS
	u32 number_1=Copy_s32Number;
	u16 counter=0;
	u32  number_2=0;
	while(number_1>0)
	{
		number_2=(number_2*10)+(number_1%10);
		number_1/=10;
		counter++;
	}
	while(counter!=0)
	{
		CLCD_voidSendData((number_2%10)+'0');
		number_2/=10;
		counter--;
	}
	#endif
}