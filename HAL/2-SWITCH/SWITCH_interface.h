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
 *******************************************************************************/

#ifndef SWITCH_INTERFACE_H
#define SWITCH_INTERFACE_H

// Include necessary dependencies
#include "../../MCAL/DIO/DIO_interface.h"  // Include DIO configurations for GPIO control
#include "SWITCH_configration.h"  
#include <util/delay.h>


// Definitions for SWITCH debounce types
#define SWITCH_u8Temporary 1
#define SWITCH_u8Permenant 0

// Definitions for SWITCH pull-up/pull-down types
#define SWITCH_u8PullUp 0
#define SWITCH_u8PullDown 1
#define SWITCH_u8InternalPullUp 2

// Definitions for SWITCH states
#define SWITCH_u8Pressed 1
#define SWITCH_u8NotPressed 0

// Structure to hold SWITCH information
typedef struct  
{
    u8 SWITCH_u8port;           // Port of the SWITCH
    u8 SWITCH_u8pin;            // Pin of the SWITCH
    u8 SWITCH_u8ConnectionType; // Connection type of the SWITCH
    u8 SWITCH_u8BounceType;     // Bounce type of the SWITCH
} SWITCH_T;

// Variable to store SWITCH state
u8 SWITCH_state;

// Function prototype to get the pressed state of a SWITCH
u8 SWITCH_u8Switchgetpressed(const SWITCH_T *SWITCH, u8 *copySwitchState);

// Function prototype to initialize a SWITCH
u8 SWITCH_u8Switchinitialize(const SWITCH_T *SWITCH);

#endif  // SWITCH_INTERFACE_H
