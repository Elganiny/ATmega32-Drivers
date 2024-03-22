/****************************************************************/
/*    Author:  Mohammed Aljanayni                               */
/*    Layer:   HAL (Hardware Abstraction Layer)                 */
/*    SWC:     LED (Light Emitting Diode)                       */
/*    Version: 2.10                                             */
/****************************************************************/

/**
 * @file LED_interface.h
 * @brief LED Control Interface
 *
 * This header file provides an interface for controlling LEDs (Light Emitting Diodes).
 * It defines function prototypes for turning on, turning off, initializing, and toggling LEDs.
 * Additionally, it includes necessary dependencies such as DIO configurations and LED configurations.
 */

#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

// Include necessary dependencies
#include "../../MCAL/DIO/DIO_interface.h"  // Include DIO configurations for GPIO control
#include "LED_configration.h"              // Include the LED interface for function declarations

/**
 * @brief LED connection types
 */
#define LED_u8SourceConnection  1  /**< Source connection type for LEDs */
#define LED_u8SinkConnection    0  /**< Sink connection type for LEDs */

/**
 * @brief Structure to hold LED information
 */
typedef struct
{
    u8 LED_u8Port;           /**< Port of the LED */
    u8 LED_u8Pin;            /**< PIN of the LED */
    u8 LED_u8ConnectionType; /**< Connection type of the LED (source/sink)*/
} LED_T;

/**
 * @brief Initialize the LED
 * 
 * @param LED Pointer to the LED structure
 * @return Status of the operation (0 for success, non-zero for failure)
 */
u8 LED_u8Initialize(const LED_T *LED);

/**
 * @brief Turn on the LED
 * 
 * @param LED Pointer to the LED structure
 * @return Status of the operation (0 for success, 1 for failure)
 */
u8 LED_u8TurnOnLED(const LED_T *LED);

/**
 * @brief Turn off the LED
 * 
 * @param LED Pointer to the LED structure
 * @return Status of the operation (0 for success, non-zero for failure)
 */
u8 LED_u8TurnOffLED(const LED_T *LED);

/**
 * @brief Toggle the LED
 * 
 * @param LED Pointer to the LED structure
 * @return Status of the operation (0 for success, non-zero for failure)
 */
u8 LED_u8Toggle(const LED_T *LED);

#endif  // LED_INTERFACE_H
