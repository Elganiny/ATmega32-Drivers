/****************************************************************/
/*    Author:  Mohammed Aljanayni                               */
/*    Layer:   HAL (Hardware Abstraction Layer)                 */
/*    SWC:     CLCD                                             */
/*    Version: 2.00                                             */
/****************************************************************/

/* Include Guard */
#ifndef CLCD_INTERFACE_H
#define CLCD_INTERFACE_H

/**
 * @brief Initialize the CLCD
 *
 * This function initializes the Character LCD (CLCD) by configuring its pins and settings.
 */
void CLCD_VidInit(void);

/**
 * @brief Send a command to the CLCD
 *
 * @param Copy_u8Command The command to be sent to the CLCD
 * @return Status of the operation (0 for success, non-zero for failure)
 */
u8 CLCD_u8SendCommand(u8 Copy_u8Command);

/**
 * @brief Send data to display on the CLCD
 *
 * @param Copy_u8Data The data to be displayed on the CLCD
 * @return Status of the operation (0 for success, non-zero for failure)
 */
u8 CLCD_u8SendData(u8 Copy_u8Data);

/**
 * @brief Clear the display of the CLCD
 *
 * This function clears the entire display of the CLCD and returns the cursor to the home position.
 */
void CLCD_VidDisplayClear(void);

/**
 * @brief Move the cursor to a specific position on the CLCD
 *
 * @param Copy_u8XPos The column position (0-15) to move the cursor to
 * @param Copy_u8YPos The row position (0 or 1) to move the cursor to
 */
void CLCD_VidGotoXY(u8 Copy_u8XPos, u8 Copy_u8YPos);

/**
 * @brief Create a custom character and store it in CGRAM
 *
 * This function allows creating custom characters and storing them in the CGRAM of the CLCD.
 *
 * @param Copy_u8Pattern Pointer to the pattern array representing the custom character
 * @param Copy_u8PatternNumber The pattern number (0-7) to assign to the custom character
 * @return Status of the operation (0 for success, non-zero for failure)
 */
u8 CLCD_u8CreatSpecialChar(u8 *Copy_u8Pattern, u8 Copy_u8PatternNumber);

/**
 * @brief Display a string on the CLCD
 *
 * This function displays a null-terminated string on the CLCD starting from the current cursor position.
 *
 * @param Copy_u8Str Pointer to the string to be displayed
 * @return Status of the operation (0 for success, non-zero for failure)
 */
u8 CLCD_u8SendString(u8 *Copy_u8Str);

#endif /* CLCD_INTERFACE_H */