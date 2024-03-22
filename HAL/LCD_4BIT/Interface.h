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

#ifndef INTERFACE_H
#define INTERFACE_H

#include "../../MCAL/DIO/DIO_interface.h" // Include DIO configurations for GPIO control
#include "config.h"

#define ClCD_u8twolines 1
#define CLCD_u8oneline 0

#define ClCD_u8_displayenable 1
#define ClCD_u8_displaydisable 0

#define ClCD_u8_cursorenable 1
#define ClCD_u8_cursordisable 0

#if ClCD_u8_cursorenable
 #define ClCD_u8_cursorblink 1
 #define ClCD_u8_cursornoblink 0
 #endif

#define CLCD_5x11 1
#define CLCD_5x8 0

#define CLCD_4bit 1
#define clcd_8bit 0

void CLCD_u8Sendcommand(const u8 Copy_u8command);
void CLCD_u8Senddata(const u8 Copy_u8data);
void CLCD_u8Intialize();
void CLCD_u8Sendstring(char* copy_u8string);
void CLCD_u8Movecursor(const u8 copy_x,const u8 copy_y);
void CLCD_u8Sendspecialcharacter(const char* copy_u8character,const u8 copy_u8block,const u8 copy_u8Xcordinates,const u8 copy_u8Ycordinates);
void CLCD_u8Sendnumber(u32 Copy_s32Number);

#endif  