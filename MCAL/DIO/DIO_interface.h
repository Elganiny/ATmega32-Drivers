/***********************************/
/*    Author: Mohammed Aljanayni   */
/*    Layer:  MCAL                 */
/*    Version: 2.00                */
/***********************************/


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "DIO_config.h"
#include "DIO_private.h"
#include "DIO_register.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"


#define DIO_u8PIN_OUTPUT		1
#define DIO_u8PIN_INPUT			0

#define DIO_u8PIN_HIGH			1
#define DIO_u8PIN_LOW			0

#define DIO_u8PORT_OUTPUT		0xFF
#define DIO_u8PORT_INPUT		0

#define DIO_u8PORT_HIGH 		0xFF
#define DIO_u8PORT_LOW  		0

#define DIO_u8PORTA				0
#define DIO_u8PORTB				1
#define DIO_u8PORTC				2
#define DIO_u8PORTD				3

#define DIO_u8PIN0				0
#define DIO_u8PIN1				1
#define DIO_u8PIN2				2
#define DIO_u8PIN3				3
#define DIO_u8PIN4				4
#define DIO_u8PIN5				5
#define DIO_u8PIN6				6
#define DIO_u8PIN7				7

/**
 * @brief Sets the direction of a specific pin in a given port.
 * 
 * This function is used to set the direction (input or output) of a specific pin
 * in a given port.
 * 
 * @param Copy_u8Port: The port number where the pin belongs (0 to 3 for AVR microcontrollers).
 * @param Copy_u8Pin: The pin number to set its direction (0 to 7).
 * @param Copy_u8Direction: The direction to set for the pin (0 for input, 1 for output).
 * 
 * @return u8: Returns the status of the operation (0 for success, 1 for failure).
 */
u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);

/**
 * @brief Sets the direction of a whole given port.
 * 
 * This function is used to set the direction (input or output) of a whole given port.
 * 
 * @param Copy_u8Port: The port number that will change its direction.
 * @param Copy_u8Direction: The directioin to set for the port.
 * 
 * @return u8: Returns the status of the operation (0 for success, 1 for failure).
*/
u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);

u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);

u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);

u8 DIO_u8GetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin, u8* Copy_pu8Value);

u8 DIO_u8TogglePin(const u8 Copy_u8Port, const u8 Copy_u8Pin);

#endif
