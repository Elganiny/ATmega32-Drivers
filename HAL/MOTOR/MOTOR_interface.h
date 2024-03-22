/*
 * MOTOR_interface.h
 *
 * Created: 9/27/2023 5:35:26 AM
 *  Author: ASUS
 */ 


#ifndef MOTOR_INTERFACE_H_
#define MOTOR_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"

#define PINK_PORT		DIO_u8PORTD
#define YELLOW_PORT		DIO_u8PORTD
#define BLUE_PORT		DIO_u8PORTD

#define PINK			DIO_u8PIN0
#define YELLOW			DIO_u8PIN1
#define BLUE			DIO_u8PIN2

void MOTOR_voidInit(void);
void MOTOR_voidStop(void);
void MOTOR_voidCW(void);
void MOTOR_voidCCW(void);


#endif /* MOTOR_INTERFACE_H_ */