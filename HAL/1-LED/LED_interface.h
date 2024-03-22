/******************************************************************************
 *
 * Author: Mohammed Ammar
 *
 * Layer: HAL (Hardware Abstraction Layer)
 *
 * SWC: LED (Light Emitting Diode)
 *
 * Version: 1.0
 *
 * Description:
 *   This header file defines the interface for controlling LEDs in the context of
 *   the HAL layer. It includes the necessary structures and function prototypes
 *   to facilitate turning LEDs on and off based on connection type.
 *
 ******************************************************************************/

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

// Include necessary dependencies
#include "../../MCAL/DIO/DIO_interface.h"  // Include DIO configurations for GPIO control
#include "LED_configration.h"  // Include the LED interface for function declarations

// Definitions for LED connection types
#define LED_u8SourceConnection 1
#define LED_u8SinkConnection 0

// Structure to hold LED information
typedef struct
{
    u8 LED_u8Port;           // Port of the LED
    u8 LED_u8Pin;            // Pin of the LED
    u8 LED_u8ConnectionType; // Connection type of the LED (source/sink)
} LED_T;

// Function prototypes for LED control
u8 LED_u8TurnOnLED(const LED_T *LED);   // Turn on the LED
u8 LED_u8TurnOffLED(const LED_T *LED);  // Turn off the LED
u8 LED_u8Initialize(const LED_T *LED);   // Initialize the LED
u8 LED_u8Toggle(const LED_T *LED);       // Toggle the LED

#endif  // LED_INTERFACE_H
