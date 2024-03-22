/*
 * ADC_private.h
 *
 * Created: 9/24/2023 8:25:19 PM
 *  Author: ASUS
 */ 


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#define ADC_ReferenceVolatge u8

#define OFF 0
#define ON  1

typedef enum {
	FCPU_2 = 1 , FCPU_4 , FCPU_8 , FCPU_16 , FCPU_32 , FCPU_64 , FCPU_128
}ADC_Prescaler;

typedef enum {
	TURN_OFF_INTERNAL_REFERENCE_VOLTAGE , AVCC_REFERENCE_VOLTAGE , RESERVED_MODE , INTERNAL_REFERENCE_VOLTAGE
}ADC_REF_VOLT;

#endif /* ADC_PRIVATE_H_ */