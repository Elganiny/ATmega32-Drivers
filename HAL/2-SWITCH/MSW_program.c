/****************************************************************/
/*    Author:  Mohammed Aljanayni                               */
/*    Layer:   HAL (Hardware Abstraction Layer)                 */
/*    SWC:     SWITCH (Push Button Switch)                      */
/*    Version: 2.10                                             */
/****************************************************************/

#include "MSW_interface.h"
#include "MSW_config.h"
#include "util\delay.h"

u8 MSW_u8GetState(u8 Copy_u8Port, u8 Copy_u8Pin,u8 Copy_u8Debouncer,u8 Copy_u8PullType,u8* Copy_pu8State)
{
    u8 Local_u8ErrorState = OK;
    if((Copy_u8Port<=DIO_u8PORTD) && (Copy_u8Pin<=DIO_u8PIN7) && (Copy_u8Debouncer<=MSW_u8ACTIVATE_DEBOUNCER) && (Copy_pu8State!=NULL))
    {
        if(Copy_u8Debouncer == MSW_u8ACTIVATE_DEBOUNCER)
        {
            // Read the state multiple times with delay for debouncing
           DIO_u8GetPinValue(Copy_u8Port,Copy_u8Pin,&Copy_pu8State);
           __delay__ms(5);
           DIO_u8GetPinValue(Copy_u8Port,Copy_u8Pin,&Copy_pu8State);
           __delay__ms(5);
           DIO_u8GetPinValue(Copy_u8Port,Copy_u8Pin,&Copy_pu8State);
           __delay__ms(5);
        }
        else
        {
           DIO_u8GetPinValue(Copy_u8Port,Copy_u8Pin,&Copy_pu8State);
        }

        // Apply pull-up resistor if specified
        if(Copy_u8PullType == MSW_u8PULL_UP)
        {
            *Copy_pu8State = !(*Copy_pu8State);
        }
    }
    else
    {
        Local_u8ErrorState = NOK;
    }
}