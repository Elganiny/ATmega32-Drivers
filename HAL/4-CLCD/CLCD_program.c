/****************************************************************/
/*    Author:  Mohammed Aljanayni                               */
/*    Layer:   HAL (Hardware Abstraction Layer)                 */
/*    SWC:     CLCD                                             */
/*    Version: 2.00                                             */
/****************************************************************/
/*========================== Libraries Includes ==========================*/

#include "../../Lib/Std_Types.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "CLCD_private.h"
#include "CLCD_config.h"
#include "CLCD_interface.h"

/*========================== Functions Implementation ==========================*/

void CLCD_VidInit(void)
{
    /* Make LCD data port direction as O/P */
    DIO_u8SetPortDirection(CLCD_DATA_PORT, DIO_u8PORT_OUTPUT);

    /* Make LCD ctrl port direction as O/P */
    DIO_u8SetPinDirection(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_u8PIN_OUTPUT);
    DIO_u8SetPinDirection(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_u8PIN_OUTPUT);
    DIO_u8SetPinDirection(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_u8PIN_OUTPUT);

    /* Delay */
    delay_ms(40);

    /* Switching to 4-bit mode */
    if (CLCD_MODE == CLCD_4BIT)
    {
        CLCD_u8SendCommand(0x33);
        CLCD_u8SendCommand(0x32);
    }

    /* Function Set */
    CLCD_u8SendCommand(CLCD_INIT_FUNCTION_SET);

    /* Delay */
    delay_us(49);

    /* Display ON/OFF Control */
    CLCD_u8SendCommand(CLCD_INIT_DISPLAY_CONTROL);

    /* Delay */
    delay_us(49);

    /* Display clear */
    CLCD_VidDisplayClear();

    /* Delay */
    delay_ms(2);
}

u8 CLCD_u8SendCommand(u8 Copy_u8Command)
{
    /* Local Variable to hold the Error State */
    u8 Local_u8ErrorState = OK;

#if (CLCD_MODE == CLCD_4BIT)
    /* Set RS pin as LOW */
    Local_u8ErrorState = DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_u8PIN_LOW);

    /* Set RW pin as LOW to write */
    Local_u8ErrorState = DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_u8PIN_LOW);

    /* Send higher nipple */
    Local_u8ErrorState = DIO_u8SetPortValue(CLCD_DATA_PORT, (Copy_u8Command & 0xF0));

    /* Set Enable pin */
    Local_u8ErrorState = DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_u8PIN_HIGH);

    /* Delay */
    delay_ms(2);

    /* Clearing Enable pin */
    Local_u8ErrorState = DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_u8PIN_LOW);

    /* Delay */
    delay_us(200);

    /* Send lower nipple */
    Local_u8ErrorState = DIO_u8SetPortValue(CLCD_DATA_PORT, ((Copy_u8Command << 4) & 0xF0));

    /* Set Enable pin */
    Local_u8ErrorState = DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_u8PIN_HIGH);

    /* Delay */
    delay_ms(2);

    /* Clearing Enable pin */
    Local_u8ErrorState = DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_u8PIN_LOW);
#endif

#if (CLCD_MODE == CLCD_8BIT)

    /* Set RS pin as LOW */
    Local_u8ErrorState = DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_u8PIN_LOW);

    /* Set RW pin as LOW to write */
    Local_u8ErrorState = DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_u8PIN_LOW);

    /* Send command to data port (pins 0 - 7) */
    Local_u8ErrorState = DIO_u8SetPortValue(CLCD_DATA_PORT, Copy_u8Command);

    /* Set Enable pin */
    Local_u8ErrorState = DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_u8PIN_HIGH);

    /* Delay */
    delay_ms(2);

    /* Clearing Enable pin */
    Local_u8ErrorState = DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_u8PIN_LOW);
#endif

    /* return Error State */
    return Local_u8ErrorState;
}

u8 CLCD_u8SendData(u8 Copy_u8Data)
{
    /* Local Variable to hold the Error State */
    u8 Local_u8ErrorState = OK;

#if (CLCD_MODE == CLCD_4BIT)
    /* Send higher nipple */
    DIO_u8SetPortValue(CLCD_DATA_PORT, Copy_u8Data & 0xF0);

    /* Set RS pin as HIGH */
    DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_u8PIN_HIGH);

    /* Set RW pin as LOW to write */
    DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_u8PIN_LOW);

    /* Set Enable pin */
    DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_u8PIN_HIGH);

    /* Delay */
    delay_ms(2);

    /* Clearing Enable pin */
    DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_u8PIN_LOW);

    /* Delay */
    delay_us(200);

    /* Send lower nipple */
    DIO_u8SetPortValue(CLCD_DATA_PORT, (Copy_u8Data << 4) & 0xF0);

    /* Set RS pin as HIGH */
    DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_u8PIN_HIGH);

    /* Set RW pin as LOW to write */
    DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_u8PIN_LOW);

    /* Set Enable pin */
    DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_u8PIN_HIGH);

    /* Delay */
    delay_ms(2);

    /* Clearing Enable pin */
    DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_u8PIN_LOW);
#endif

#if (CLCD_MODE == CLCD_8BIT)
    /* Set RS pin as HIGH */
    DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RS_PIN, DIO_u8PIN_HIGH);

    /* Set RW pin as LOW to write */
    DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_RW_PIN, DIO_u8PIN_LOW);

    /* Send command to data port (pins 0 - 7) */
    DIO_u8SetPortValue(CLCD_DATA_PORT, Copy_u8Data);

    /* Set Enable pin */
    DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_u8PIN_HIGH);

    /* Delay */
    delay_ms(2);

    /* Clearing Enable pin */
    DIO_u8SetPinValue(CLCD_CTRL_PORT, CLCD_EN_PIN, DIO_u8PIN_LOW);
#endif

    /* return Error State */
    return Local_u8ErrorState;
}

void CLCD_VidDisplayClear(void)
{
    CLCD_u8SendCommand(0b00000001);
    /* Delay */
    delay_ms(2);
}

void CLCD_VidGotoXY(u8 Copy_u8XPos, u8 Copy_u8YPos)
{

    u8 Local_u8Address = 0;

    if (Copy_u8XPos == 0)
    {
        Local_u8Address = Copy_u8YPos;
    }

    else if (Copy_u8XPos == 1)
    {

        Local_u8Address = 0x40 + Copy_u8YPos;
    }

    /* Send this address to the DDram  128 + Local_u8Address because of the 1st in bit 7 of datasheet */

    CLCD_u8SendCommand(0b010000000 + Local_u8Address);
}

u8 CLCD_u8CreatSpecialChar(u8 *Copy_u8Pattern, u8 Copy_u8PatternNumber)
{
    /* Local Variable to hold the Error State */
    u8 Local_u8ErrorState = OK;

    /* Local Variable to hold the CGRAM Address */
    u8 Local_u8CGRAMAddress = 0;

    /* Calculate the CGRAM Address */
    Local_u8CGRAMAddress = Copy_u8PatternNumber * 8;

    /* Send CGRAM address command to LCD with setting bit 6 to 1 -----> 64 */
    CLCD_u8SendCommand(Local_u8CGRAMAddress + 64);

    /* Write pattern into CGRAM */
    for (u8 i = 0; i < 8; i++)
    {
        CLCD_u8SendData(Copy_u8Pattern[i]);
    }

    /* return Error State */
    return Local_u8ErrorState;
}

u8 CLCD_u8SendString(u8 *Copy_u8Str)
{
    /* Local Variable to hold the Error State */
    u8 Local_u8ErrorState = OK;

    while (*Copy_u8Str != '\0')
    {
        Local_u8ErrorState = CLCD_u8SendData(*Copy_u8Str);
        Copy_u8Str++;
    }

    /* return Error State */
    return Local_u8ErrorState;
}