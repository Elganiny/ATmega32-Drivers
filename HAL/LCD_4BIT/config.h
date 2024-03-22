/******************************************************************************
 *
 * Author: Mohammed Ammar
 *
 * Layer: HAL (Hardware Abstraction Layer)
 *
 * SWC:LCD
 *
 * Version: 1.0
 *
 * Description:
 *   This header file serves as a bridge between the 7SEGMENT module and the lower-level
 *   hardware abstraction layer. It includes necessary configurations and defines
 *   to establish communication with the 7SEGMENT hardware. This module is designed to
 *   interface with 7-segment displays for numeric display purposes.
 *
 ******************************************************************************/

#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#define  CLCD_Data_Port DIO_u8PORTB
#define  CLCD_D4		DIO_u8PIN4
#define  CLCD_D5		DIO_u8PIN5
#define  CLCD_D6		DIO_u8PIN6
#define  CLCD_D7		DIO_u8PIN7

#define  CLCD_Ctrl_Port DIO_u8PORTB
#define  CLCD_RS_pin    DIO_u8PIN0
#define  CLCD_RW_pin	DIO_u8PIN1
#define  CLCD_E_pin		DIO_u8PIN2
 
 #define ClCd_n_oflines ClCD_u8twolines
 #define  CLCD_font_size CLCD_5x8
 
 #define CLCD_cursor     ClCD_u8_cursordisable
 #define CLCD_cursorblink CLCD_cursorblink
 

#endif  