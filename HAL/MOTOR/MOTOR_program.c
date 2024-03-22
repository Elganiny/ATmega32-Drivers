/*
 * STEPPER_program.c
 *
 * Created: 9/27/2023 5:33:34 AM
 *  Author: ASUS
 */ 

#include "MOTOR_interface.h"
#include "../../MCAL/DIO/DIO_interface.h"
void MOTOR_Init(void)
{
	DIO_u8SetPinDirection(PINK_PORT,PINK,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(YELLOW_PORT,YELLOW,DIO_u8PIN_OUTPUT);
	DIO_u8SetPinDirection(BLUE_PORT,BLUE,DIO_u8PIN_OUTPUT);
}


void MOTOR_Stop(void)
{
	DIO_u8SetPinValue(PINK_PORT,PINK,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(YELLOW_PORT,YELLOW,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(BLUE_PORT,BLUE,DIO_u8PIN_LOW);
}
void MOTOR_CW(void)
{

	DIO_u8SetPinValue(BLUE_PORT,BLUE,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(PINK_PORT,PINK,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(YELLOW_PORT,YELLOW,DIO_u8PIN_HIGH);

}

void MOTOR_CCW(void)
{
	DIO_u8SetPinValue(BLUE_PORT,BLUE,DIO_u8PIN_HIGH);
	DIO_u8SetPinValue(PINK_PORT,PINK,DIO_u8PIN_LOW);
	DIO_u8SetPinValue(YELLOW_PORT,YELLOW,DIO_u8PIN_LOW);
}