/****************************************************************/
/*    Author:  Mohammed Aljanayni                               */
/*    Layer:   HAL (Hardware Abstraction Layer)                 */
/*    SWC:     CLCD                                             */
/*    Version: 2.00                                             */
/****************************************************************/

#ifndef CLCD_PRIVATE_H
#define CLCD_PRIVATE_H

/**
 * @brief: Options for the modes of the CLCD
 */
#define CLCD_4BIT                   0
#define CLCD_8BIT                   1

/**
 * @brief: Macros for defining the CLCD function set commands
 */
#define CLCD_8BIT_1LINE             0x30
#define CLCD_8BIT_2LINES            0x38
#define CLCD_4BIT_1LINE             0x20
#define CLCD_4BIT_2LINES            0x28

/**
 * @brief: Macros for defining the CLCD display control commands 
 */
#define CLCD_DISPLAY_OFF_CURSOR_OFF 0x08
#define CLCD_DISPLAY_ON_CURSOR_OFF  0x0C
#define CLCD_DISPLAY_ON_CURSOR_ON   0x0E

#endif /* CLCD_PRIVATE_H */