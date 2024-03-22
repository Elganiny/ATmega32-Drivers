/*
 * EXTI_config.h
 *
 * Created: 9/27/2023 2:39:05 AM
 *  Author: ASUS
 */ 


#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_

/*Options:
			1- LOW_LEVEL
			2- ON_CHANGE
			3- FALLING_EDGE
			4- RISING_EDGE
								*/
#define INT0_SENSE		RISING_EDGE
#define INT1_SENSE		RISING_EDGE

/*Options:
			1- ENABLED
			2- DISABLED
								*/
#define INT0_INITIAL_STATE		ENABLED
#define INT1_INITIAL_STATE		ENABLED

#endif /* EXTI_CONFIG_H_ */