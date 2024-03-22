/****************************************************************/
/*    Author:  Mohammed Aljanayni                               */
/*    Layer:   HAL (Hardware Abstraction Layer)                 */
/*    SWC:     Seven Segment display                            */
/*    Version: 2.10                                             */
/****************************************************************/

/**
 * @file SSD_interface.h
 * @brief Seven Segment Display Interface
 *
 * This header file provides an interface for controlling seven-segment displays.
 * It defines a structure to hold the configuration of a seven-segment display,
 * as well as function prototypes for displaying numbers on the display.
 */

#include "STD_TYPES.h"

#ifndef SSD_INTERFACE_H
#define SSD_INTERFACE_h

/**
 * @brief Structure to hold Seven Segment Display configuration
 */
typedef struct 
{
    u8 SSD_u8CommonType:1;      /**< Common type (0 for common cathode, 1 for common anode) */
    u8 SSD_u8EnablePort:2;      /**< Enable port */
    u8 SSD_u8DisplPort :2;      /**< Display port */
    u8 SSD_u8EnaplePin :3;      /**< Enable pin */
    u8 SSD_u8Number;            /**< Number to display */
}SSD;

/**
 * @brief: Types of Seven Segment Display
*/
#define SSD_u8COMMON_CATHOD     0
#define SSD_u8COMMON_ANODE      1

/**
 * @brief Seven Segment Display Numbers
 */
#define SSD_u8NUMBER0			0x3F    /**< Number 0 */
#define SSD_u8NUMBER1			0x06    /**< Number 1 */
#define SSD_u8NUMBER2           0x5B    /**< Number 2 */
#define SSD_u8NUMBER3           0x4F    /**< Number 3 */
#define SSD_u8NUMBER4           0x66    /**< Number 4 */
#define SSD_u8NUMBER5           0x6D    /**< Number 5 */
#define SSD_u8NUMBER6           0xFD    /**< Number 6 */
#define SSD_u8NUMBER7           0x07    /**< Number 7 */
#define SSD_u8NUMBER8           0xFF    /**< Number 8 */
#define SSD_u8NUMBER9           0x6F    /**< Number 9 */

/**
 * @brief Display a number on the Seven Segment Display
 * 
 * @param Copy_pu8SSD Pointer to the SSD structure
 * @param Copy_u8Number Number to display (0-9)
 * @return Status of the operation (0 for success, non-zero for failure)
 */
u8 SSD_u8DisplayNumber(SSD* Copy_pu8SSD,u8 Copy_u8Number);

#endif