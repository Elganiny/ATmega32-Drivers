/******************************************************************************
*
* Author: Mohammed Ammar
*
* Layer: HAL
*
* SWC: LED
*
* Version: 1.0
*
* Description: This code provides functions for turning on and off an LED
*              based on the connection type (source or sink) through an LED module.
*
*******************************************************************************/

#include "LED_interface.h"  // Include necessary definitions

// Function to turn on an LED based on connection type
u8 LED_u8TurnOnLED(const LED_T *LED) {
	u8 local_u8error = 0;  // Initialize error flag
	
	// NULL pointer, set error flag
	if ((LED != NULL) && (LED->LED_u8Pin <= DIO_u8PIN7) && (LED->LED_u8Port <= DIO_u8PORTD)) {
		// Check if the specified pin is within valid range
		// Check if the specified port is within valid range
		// Switch based on the connection type
		switch (LED->LED_u8ConnectionType) {
			case LED_u8SourceConnection: DIO_u8SetPinValue(LED->LED_u8Port, LED->LED_u8Pin, DIO_u8PIN_HIGH); break;
			case LED_u8SinkConnection: DIO_u8SetPinValue(LED->LED_u8Port, LED->LED_u8Pin, DIO_u8PIN_LOW); break;
		}
		} else {
		local_u8error = 1;  // Invalid pin, set error flag
	}
	return local_u8error;
}

// Function to turn off an LED based on connection type
u8 LED_u8TurnOffLED(const LED_T *LED) {
	u8 local_u8error = 0;  // Initialize error flag
	
	// NULL pointer, set error flag
	if ((LED != NULL) && (LED->LED_u8Pin <= DIO_u8PIN7) && (LED->LED_u8Port <= DIO_u8PORTD)) {
		// Check if the specified pin is within valid range
		// Check if the specified port is within valid range
		
		// Switch based on the connection type
		switch (LED->LED_u8ConnectionType) {
			case LED_u8SourceConnection: DIO_u8SetPinValue(LED->LED_u8Port, LED->LED_u8Pin, DIO_u8PIN_LOW); break;
			case LED_u8SinkConnection: DIO_u8SetPinValue(LED->LED_u8Port, LED->LED_u8Pin, DIO_u8PIN_HIGH); break;
		}
		} else {
		local_u8error = 1;  // Invalid pin, set error flag
	}
	return local_u8error;
}

// Function to toggle an LED
u8 LED_u8Toggle(const LED_T *LED) {
	u8 local_u8error = 0;  // Initialize error flag
	
	// NULL pointer, set error flag
	if ((LED != NULL) && (LED->LED_u8Pin <= DIO_u8PIN7) && (LED->LED_u8Port <= DIO_u8PORTD)) {
		DIO_u8TogglePin(LED->LED_u8Port, LED->LED_u8Pin);
		} else {
		local_u8error = 1;
	}
	return local_u8error;
}

u8 LED_u8Initialize(const LED_T *LED) {
	u8 local_u8error = 0;  // Initialize error flag
	
	// NULL pointer, set error flag
	if ((LED != NULL) && (LED->LED_u8Pin <= DIO_u8PIN7) && (LED->LED_u8Port <= DIO_u8PORTD) && (LED->LED_u8ConnectionType<2)) {
		// Check if the specified pin is within valid range
		// Check if the specified port is within valid range
		// Configure pin as an output and set it to low
		DIO_u8SetPinDirection(LED->LED_u8Port,LED->LED_u8Pin,DIO_u8PIN_OUTPUT);
		switch (LED->LED_u8ConnectionType) {
			case LED_u8SourceConnection: DIO_u8SetPinValue(LED->LED_u8Port, LED->LED_u8Pin, DIO_u8PIN_LOW); break;
			case LED_u8SinkConnection: DIO_u8SetPinValue(LED->LED_u8Port, LED->LED_u8Pin, DIO_u8PIN_HIGH); break;
		}	
	}
	else {
		local_u8error = 1;
	}
	return local_u8error;
}