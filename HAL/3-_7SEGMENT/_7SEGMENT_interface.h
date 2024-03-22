/******************************************************************************
 *
 * Author: Mohammed Ammar
 *
 * Layer: HAL (Hardware Abstraction Layer)
 *
 * SWC: 7SEGMENT 
 *
 * Version: 1.0
 *
 *
 ******************************************************************************/





#ifndef _7SEGMENT_INTERFACE_H
#define _7SEGMENT_INTERFACE_H

// Include necessary dependencies
#include "../../MCAL/DIO/DIO_interface.h"  // Include DIO configurations for GPIO control
#include "_7SEGMENT_configration.h"  // Include the 7SEGMENT interface for function declarations

/* Constants for common cathode and common anode connection types */
#define _7SEGMENT_u8COMMONCATHODE 1
#define _7SEGMENT_u8COMMONANODE   0

/* Structure defining the 7SEGMENT properties */
typedef struct  
{
    u8 _7SEGMENT_u8port;        // Port to which the 7SEGMENT is connected
    u8 _7SEGMENT_u8enableport;  // Port for the enable pin
    u8 _7SEGMENT_u8enablepin;   // Pin for enabling the 7SEGMENT
    u8 _7SEGMENT_u8commontype;  // Type of common connection (Cathode/Anode)
} _7SEGMENT_T;

/**
 * Function to display a specific number on the 7SEGMENT display.
 * 
 * @param _7SEGMENT Pointer to the _7SEGMENT_T structure.
 * @param copy_u8number The number to be displayed.
 * @return Status indicating success (1) or failure (0).
 */
u8 _7SEGMENT_u8ShowNumber(_7SEGMENT_T *_7SEGMENT, u8 copy_u8number);

/**
 * Function to hide the number displayed on the 7SEGMENT.
 * 
 * @param _7SEGMENT Pointer to the _7SEGMENT_T structure.
 * @return Status indicating success (1) or failure (0).
 */
u8 _7SEGMENT_u8HideNumber(_7SEGMENT_T *_7SEGMENT);

/**
 * Function to initialize the 7SEGMENT display.
 * 
 * @param _7SEGMENT Pointer to the _7SEGMENT_T structure.
 * @return Status indicating success (1) or failure (0).
 */
u8 _7SEGMENT_u8Initialize(const _7SEGMENT_T  *_7SEGMENT);

#endif
