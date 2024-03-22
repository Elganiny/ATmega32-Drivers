/*
 * application.c
 *
 * Created: 8/27/2023 1:49:47 PM
 *  Author: ASUS
 */ 

/* @brief Choose what you will work with
 * @brief LDR or LM35D
 * @brief and set the Macro to 1 and the other to 0
 */
#include "application.h"
#include <avr/io.h>

#define LDR_Test		1
#define LM35D_Test		0

// void InitADC()
// {
// 	ADMUX=(1<<REFS0);                       // For Aref=AVcc;
// 	ADCSRA=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0); //Rrescalar div factor =128
// }
// 
// u16 ReadADC(u8 channel)
// {
// 	//Select ADC Channel channel must be 0-7
// 	channel &= 0b00000111;
// 	ADMUX|=channel;
// 
// 	//Start Single conversion
// 	ADCSRA|=(1<<ADSC);
// 
// 	//Wait for conversion to complete
// 	while(!(ADCSRA & (1<<ADIF)));
// 
// 	//Clear ADIF by writing one to it
// 	//Note you may be wondering why we have write one to clear it
// 	//This is standard way of clearing bits in io as said in datasheets.
// 	//The code writes '1' but it result in setting bit to '0' !!!
// 	ADCSRA|=(1<<ADIF);
// 	return(ADC);
// }

void Seperate_Result (u32 u32Result, u8 * u8array_Result)
{

	u8array_Result[0]= ((u32Result / 10000) % 10) + 48;
	u8array_Result[1]= ((u32Result / 1000 ) % 10) + 48;
	u8array_Result[2]= ((u32Result / 100  ) % 10) + 48;
	u8array_Result[3]= ((u32Result / 10   ) % 10) + 48;
	u8array_Result[4]=  (u32Result % 10   ) + 48;

}

void Wait()
{
	_delay_ms(1500);
}

void main()
{
	u8 i=0;
	u16 adc0_result=0, adc1_result=0;
	u16 Temp_mv=0, Temp_value=0;
	u8 ADC0Result_arr [5] ={0};
	u8 ADC1Result_arr [5]={0};

	u8 ADCequal_arr [3] = {' ','=',' '};
	
	//Initialize LCD
	DIO_u8SetPortDirection(DIO_u8PORTD,0xFF);
	DIO_u8SetPortDirection(DIO_u8PORTC,0x0F);
	CLCD_voidInit();


	//Initialize ADC
	ADC_voidInit();

	//Put some intro text into LCD
	CLCD_voidGoToXY(1,8);
	CLCD_voidSendString(ADCequal_arr);
	CLCD_voidGoToXY(0,1);
	CLCD_voidSendString("Tempreture");

	while(1)
	{
#if LDR_Test==1
		adc0_result=ADC_u8GetChannelRead(0);
		// Read Analog value from channel-0
		Seperate_Result(adc0_result,ADC0Result_arr);
		CLCD_voidGoToXY(1,9);
// 		for (i=0;i<5;i++){
// 			CLCD_voidSendData(ADC0Result_arr[i]); //Print the value in 4th column second line
// 			_delay_ms(2);
// 		}
		CLCD_voidWriteNumber(adc0_result);
		i=0;
		Wait();
#endif
#if LM35D_Test==1
		/*ADC1 for LM35D*/
		adc1_result = ADC_u8GetChannelRead(1);
		CLCD_voidGoToXY(1,11);
		Temp_mv=(adc1_result)/2;
		
		if(Temp_mv > 50 )
		{
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_HIGH);
		} else {
			DIO_u8SetPinValue(DIO_u8PORTC,DIO_u8PIN1,DIO_u8PIN_LOW);
		}
		Seperate_Result(Temp_value,ADC1Result_arr);
// 		for (i=0;i<5;i++)
// 		{
// 			CLCD_voidSendData(ADC1Result_arr[i]); //Print the value in 4th column second line
// 			_delay_ms(2);
// 		}
		CLCD_voidWriteNumber(Temp_mv);
		i=0;
		Wait();
#endif
	}
}

