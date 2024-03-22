/******************************************************************************
 *
 * Author: Mohammed Ammar
 *
 * Layer: HAL (Hardware Abstraction Layer)
 *
 * SWC: SWITCH (Push Button Switch)
 *
 * Version: 1.0
 *
 * Description:
 *   This header file serves as a bridge between the SWITCH module and the lower-level
 *   hardware abstraction layer. It includes necessary configurations and defines
 *   to establish communication with the SWITCH hardware. Welcome to the world of light
 *   manipulation through LED control!
 *
 ******************************************************************************/

#include "SWITCH_interface.h"  // Include necessary definitions

// Function to get the pressed state of a SWITCH
u8 SWITCH_u8Switchgetpressed(const SWITCH_T *SWITCH, u8 *copySwitchState) {
	u8 local_u8error = 0, local_pinValue;

	if ((copySwitchState != NULL) && (SWITCH != NULL) && (SWITCH->SWITCH_u8pin <= DIO_u8PIN7) && (SWITCH->SWITCH_u8port <= DIO_u8PORTD) && (SWITCH->SWITCH_u8BounceType < 2) && (SWITCH->SWITCH_u8ConnectionType < 3)) {
		// Configure pin as input

		// Apply bounce or debounce based on connection type
		if (SWITCH->SWITCH_u8BounceType == SWITCH_u8Temporary) {
			// Apply bounce handling by reading the pin value after a delay
			DIO_u8GetPinValue(SWITCH->SWITCH_u8port, SWITCH->SWITCH_u8pin, &local_pinValue);
			_delay_ms(70);
			DIO_u8GetPinValue(SWITCH->SWITCH_u8port, SWITCH->SWITCH_u8pin, &local_pinValue);
		} else if (SWITCH->SWITCH_u8BounceType == SWITCH_u8Permenant) {
			// Apply debounce by reading the pin value twice
			DIO_u8GetPinValue(SWITCH->SWITCH_u8port, SWITCH->SWITCH_u8pin, &local_pinValue);
		}

		// Determine the switch state based on connection type and pin value
		switch (SWITCH->SWITCH_u8ConnectionType) {
			case SWITCH_u8PullUp:
				*copySwitchState = (local_pinValue) ? SWITCH_u8NotPressed : SWITCH_u8Pressed;
				break;
			case SWITCH_u8PullDown:
				*copySwitchState = (local_pinValue) ? SWITCH_u8Pressed : SWITCH_u8NotPressed;
				break;
			case SWITCH_u8InternalPullUp:
				DIO_u8SetPinValue(SWITCH->SWITCH_u8port, SWITCH->SWITCH_u8pin, DIO_u8PIN_OUTPUT);
				*copySwitchState = (local_pinValue) ? SWITCH_u8NotPressed : SWITCH_u8Pressed;
				break;
		}
	} else {
		local_u8error = 1;  // Invalid pin, set error flag
	}
	return local_u8error;
}

// Function to initialize a SWITCH
u8 SWITCH_u8Switchinitialize(const SWITCH_T *SWITCH) {
	u8 local_u8error = 0;

	if ((SWITCH != NULL) && (SWITCH->SWITCH_u8pin <= DIO_u8PIN7) && (SWITCH->SWITCH_u8port <= DIO_u8PORTD) && (SWITCH->SWITCH_u8BounceType < 2) && (SWITCH->SWITCH_u8ConnectionType < 3)) {
		DIO_u8SetPinDirection(SWITCH->SWITCH_u8port, SWITCH->SWITCH_u8pin, DIO_u8PIN_INPUT);
		switch (SWITCH->SWITCH_u8ConnectionType) {
			case SWITCH_u8PullUp:
			DIO_u8SetPinValue(SWITCH->SWITCH_u8port, SWITCH->SWITCH_u8pin, DIO_u8PIN_LOW);
			break;
			case SWITCH_u8PullDown:
			DIO_u8SetPinValue(SWITCH->SWITCH_u8port, SWITCH->SWITCH_u8pin, DIO_u8PIN_HIGH);
			break;
			case SWITCH_u8InternalPullUp:
			DIO_u8SetPinValue(SWITCH->SWITCH_u8port, SWITCH->SWITCH_u8pin, DIO_u8PIN_HIGH);
			break;
		}
	} else {
		local_u8error = 1;
	}
	return local_u8error;
}
