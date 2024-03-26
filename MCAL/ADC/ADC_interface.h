/*
 * ADC_interface.h
 *
 * Created: 9/24/2023 8:25:58 PM
 *  Author: Elganainy
 */ 

#ifndef ADC_H_
#define ADC_H_

#include "ADC_register.h"
#include "ADC_config.h"
#include "ADC_private.h"
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
/*-----------------------------------*
 *           DEFINITIONS             *
 *-----------------------------------*/

typedef struct{
	ADC_ReferenceVolatge ref_volt;
	ADC_Prescaler prescaler;
}ADC_ConfigType;

/*-----------------------------------*
 *        FUNCTION PROTOTYPE         *
 *-----------------------------------*/
void ADC_init(const ADC_ConfigType* config_ptr);
u16 ADC_readChannel(u8 ch_num);

#endif