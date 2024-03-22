/*
 * app2.c
 *
 * Created: 9/30/2023 3:27:14 PM
 *  Author: ASUS
 */ 


#include "application.h"

int main(void)
{
	u8 temp = 0 ;

	/* initializing the LCD */
	CLCD_voidInit();


	while(1)
	{
		/* getting the value measured by the LM35 sensor */
		temp = LM35_getTemperature();

		if(temp >= 60)
		{
			CLCD_voidGoToXY(1,2);
			CLCD_voidSendString("60 degreea");
		}
		else if(temp >= 30)
		{
			CLCD_voidGoToXY(1,2);
			CLCD_voidSendString("30 degreea");
		}
		else
		{
			CLCD_voidGoToXY(1,2);
			CLCD_voidSendString("Notttttttt");
		}
	}
}
