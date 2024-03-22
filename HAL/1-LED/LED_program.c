/****************************************************************/
/*    Author:  Mohammed Aljanayni                               */
/*    Layer:   HAL (Hardware Abstraction Layer)         		*/
/*    SWC:     LED (Light Emitting Diode)                       */
/*    Version: 2.10                                             */
/****************************************************************/

#include "LED_interface.h" // Include necessary definitions


u8 LED_u8Initialize(const LED_T *LED)
{
	u8 local_u8error = OK; // Initialize error flag

	// NULL pointer or invalid pin/port, set error flag
	if ((LED != NULL) && (LED->LED_u8Pin <= DIO_u8PIN7) && (LED->LED_u8Port <= DIO_u8PORTD) && (LED->LED_u8ConnectionType < 2))
	{
		// Configure pin as an output and set initial value
		DIO_u8SetPinDirection(LED->LED_u8Port, LED->LED_u8Pin, DIO_u8PIN_OUTPUT);
		switch (LED->LED_u8ConnectionType)
		{
		case LED_u8SourceConnection:
			DIO_u8SetPinValue(LED->LED_u8Port, LED->LED_u8Pin, DIO_u8PIN_LOW);
			break;
		case LED_u8SinkConnection:
			DIO_u8SetPinValue(LED->LED_u8Port, LED->LED_u8Pin, DIO_u8PIN_HIGH);
			break;
		}
	}
	else
	{
		local_u8error = NOK;
	}
	return local_u8error;
}

u8 LED_u8TurnOnLED(const LED_T *LED)
{
	u8 local_u8error = OK; // Initialize error flag

	// NULL pointer or invalid pin/port, set error flag
	if ((LED != NULL) && (LED->LED_u8Pin <= DIO_u8PIN7) && (LED->LED_u8Port <= DIO_u8PORTD))
	{

		// Switch based on the connection type
		switch (LED->LED_u8ConnectionType)
		{
		case LED_u8SourceConnection:
			DIO_u8SetPinValue(LED->LED_u8Port, LED->LED_u8Pin, DIO_u8PIN_HIGH);
			break;
		case LED_u8SinkConnection:
			DIO_u8SetPinValue(LED->LED_u8Port, LED->LED_u8Pin, DIO_u8PIN_LOW);
			break;
		}
	}
	else
	{
		local_u8error = NOK; // Invalid pin, set error flag
	}
	return local_u8error;
}

u8 LED_u8TurnOffLED(const LED_T *LED)
{
	u8 local_u8error = OK; // Initialize error flag

	// NULL pointer or invalid pin/port, set error flag
	if ((LED != NULL) && (LED->LED_u8Pin <= DIO_u8PIN7) && (LED->LED_u8Port <= DIO_u8PORTD))
	{

		// Switch based on the connection type
		switch (LED->LED_u8ConnectionType)
		{
		case LED_u8SourceConnection:
			DIO_u8SetPinValue(LED->LED_u8Port, LED->LED_u8Pin, DIO_u8PIN_LOW);
			break;
		case LED_u8SinkConnection:
			DIO_u8SetPinValue(LED->LED_u8Port, LED->LED_u8Pin, DIO_u8PIN_HIGH);
			break;
		}
	}
	else
	{
		local_u8error = NOK; // Invalid pin, set error flag
	}
	return local_u8error;
}

// Function to toggle an LED
u8 LED_u8Toggle(const LED_T *LED)
{
	u8 local_u8error = OK; // Initialize error flag

	// NULL pointer or invalid pin/port, set error flag
	if ((LED != NULL) && (LED->LED_u8Pin <= DIO_u8PIN7) && (LED->LED_u8Port <= DIO_u8PORTD))
	{
		DIO_u8TogglePin(LED->LED_u8Port, LED->LED_u8Pin);
	}
	else
	{
		local_u8error = NOK;
	}
	return local_u8error;
}