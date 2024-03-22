/*
 * EXTI_program.c
 *
 * Created: 9/27/2023 2:38:55 AM
 *  Author: ASUS
 */ 

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"
#include "EXTI_register.h"

/*Global pointer to function to hold INT0 ISR address*/
void (*EXTI_pvInt0Func)(void) = NULL;
/*Global pointer to function to hold INT1 ISR address*/
void (*EXTI_pvInt1Func)(void) = NULL;
/*Global pointer to function to hold INT2 ISR address*/
void (*EXTI_pvInt2Func)(void) = NULL;


void EXTI_voidInt0Init()
{
	/*1- Check Sense control*/
	#if INT0_SENSE == LOW_LEVEL
		CLR_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
		
	#elif INT0_SENSE == ON_CAHNGE
		SET_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
		
	#elif INT0_SENSE == FALLING_EDGE
			SET_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC01);

	#elif INT0_SENSE == RISING_EDGE
			SET_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC01);
	
	#else
	#error "Wrong INT0_SENSE configuration option"
	#endif
	
	/*1- Check Enable*/
	#if INT0_INITIAL_STATE == ENABLED
		SET_BIT(GICR, GICR_INT0);
	#elif INT0_INITIAL_STATE == DISABLED
		CLR_BIT(GICR, GICR_INT0);
	#else
	#error "Wrong INT0_INITIAL_STATE configuration option"
	#endif
}

void EXTI_voidInt1Init()
{
	/*1- Check Sense control*/
	#if INT1_SENSE == LOW_LEVEL
	CLR_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);
	
	#elif INT1_SENSE == ON_CAHNGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);
	
	#elif INT1_SENSE == FALLING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);

	#elif INT1_SENSE == RISING_EDGE
	SET_BIT(MCUCR,MCUCR_ISC10);
	CLR_BIT(MCUCR,MCUCR_ISC11);
	
	#else
	#error "Wrong INT1_SENSE configuration option"
	#endif
	
	/*1- Check Enable*/
	#if INT1_INITIAL_STATE == ENABLED
	SET_BIT(GICR, GICR_INT1);
	#elif INT1_INITIAL_STATE == DISABLED
	CLR_BIT(GICR, GICR_INT1);
	#else
	#error "Wrong INT1_INITIAL_STATE configuration option"
	#endif
}

u8 EXTI_u8Int0SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;
	
	switch(Copy_u8Sense)
	{
		case LOW_LEVEL:
			CLR_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC01);
			break;
		case ON_CAHNGE:
			SET_BIT(MCUCR,MCUCR_ISC00);
			CLR_BIT(MCUCR,MCUCR_ISC01);
			break;
		case FALLING_EDGE:
			CLR_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
			break;
		case RISING_EDGE:
			SET_BIT(MCUCR,MCUCR_ISC00);
			SET_BIT(MCUCR,MCUCR_ISC01);
			break;
		default: Local_u8ErrorState = NOK;
	}
	
	return Local_u8ErrorState;
}

u8 EXTI_u8Int1SetSenseControl(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;
	
	switch(Copy_u8Sense)
	{
		case LOW_LEVEL:
		CLR_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);
		break;
		case ON_CAHNGE:
		SET_BIT(MCUCR,MCUCR_ISC10);
		CLR_BIT(MCUCR,MCUCR_ISC11);
		break;
		case FALLING_EDGE:
		CLR_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);
		break;
		case RISING_EDGE:
		SET_BIT(MCUCR,MCUCR_ISC10);
		SET_BIT(MCUCR,MCUCR_ISC11);
		break;
		default: Local_u8ErrorState = NOK;
	}
	
	return Local_u8ErrorState;
}

u8 EXTI_u8IntEnable(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;
	
	switch(Copy_u8Sense)
	{
		case INT0: SET_BIT(GICR, GICR_INT0); break;
		case INT1: SET_BIT(GICR, GICR_INT1); break;
		case INT2: SET_BIT(GICR, GICR_INT2); break;
		default: Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8IntDisable(u8 Copy_u8Sense)
{
	u8 Local_u8ErrorState = OK;
	
	switch(Copy_u8Sense)
	{
		case INT0: CLR_BIT(GICR, GICR_INT0); break;
		case INT1: CLR_BIT(GICR, GICR_INT1); break;
		case INT2: CLR_BIT(GICR, GICR_INT2); break;
		default: Local_u8ErrorState = NOK;
	}
	return Local_u8ErrorState;
}

u8 EXTI_u8Int0SetCallBack(void(*Copy_pvInt0Func)(void))
{
	u8 Local_u8ErrorState = OK;
	
	if(Copy_pvInt0Func != NULL)
	{
		EXTI_pvInt0Func = Copy_pvInt0Func;
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	
	return Local_u8ErrorState;
}

u8 EXTI_u8Int1SetCallBack(void(*Copy_pvInt1Func)(void))
{
	u8 Local_u8ErrorState = OK;
	
	if(Copy_pvInt1Func != NULL)
	{
		EXTI_pvInt1Func = Copy_pvInt1Func;
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	
	return Local_u8ErrorState;
}

u8 EXTI_u8Int2SetCallBack(void(*Copy_pvInt2Func)(void))
{
	u8 Local_u8ErrorState = OK;
	
	if(Copy_pvInt2Func != NULL)
	{
		EXTI_pvInt2Func = Copy_pvInt2Func;
	}
	else
	{
		Local_u8ErrorState = NOK;
	}
	
	return Local_u8ErrorState;
}

/*ISR of INT0*/
void __vector_1 (void)  __attribute__((signal));
void __vector_1 (void)
{
	if(EXTI_pvInt0Func != NULL)
	{
		EXTI_pvInt0Func();
	}
	else
	{
		/*Do nothing*/
	}
}

/*ISR of INT1*/
void __vector_2 (void)  __attribute__((signal));
void __vector_2 (void)
{
	if(EXTI_pvInt1Func != NULL)
	{
		EXTI_pvInt1Func();
	}
	else
	{
		/*Do nothing*/
	}
}

/*ISR of INT2*/
void __vector_3 (void)  __attribute__((signal));
void __vector_3 (void)
{
	if(EXTI_pvInt2Func != NULL)
	{
		EXTI_pvInt2Func();
	}
	else
	{
		/*Do nothing*/
	}
}