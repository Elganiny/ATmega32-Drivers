/****************************************************************/
/*    Author:  Mohammed Aljanayni                               */
/*    Layer:   HAL (Hardware Abstraction Layer)                 */
/*    SWC:     CLCD                                             */
/*    Version: 2.00                                             */
/****************************************************************/

/* Include Guard */
#ifndef CLCD_INTERFACE_H
#define CLCD_INTERFACE_H

void CLCD_VidInit(void);

u8 CLCD_u8SendCommand(u8 Copy_u8Command);

u8 CLCD_u8SendData(u8 Copy_u8Data);

void CLCD_VidDisplayClear(void);

void CLCD_VidGotoXY(u8 Copy_u8XPos, u8 Copy_u8YPos);

u8 CLCD_u8CreatSpecialChar(u8 *Copy_u8Pattern, u8 Copy_u8PatternNumber);

u8 CLCD_u8SendString(u8 *Copy_u8Str);

#endif /* CLCD_INTERFACE_H */