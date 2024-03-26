/*
 * ADC_config.h
 *
 * Created: 9/24/2023 8:25:58 PM
 *  Author: Elganainy
 */ 


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_


/
/* Choosing which channel you need */

#define ADC_CHANNEL 1

/* ### this ADC_CHANNEL should be completed as there are more cases should be handled ### */

/* setting or clearing the ADC left adjust result, it should be put by zero if no shift   *
 * will be applied on the ADC register and one if shift is applied on the ADC register.   */
#define ADC_LEFT_ADJUST_RESULT OFF

/*
 * enable ADC Auto trigger by 1 or disable it by 0
 * also setting Auto trigger mode by picking a number from 0 to 7:
 * 0: free running mode
 * 1: analog comparator
 * 2: external interrupt request 0
 * 3: timer/counter0 compare match
 * 4: timer/counter0 overflow
 * 5: timer/counter1 compare match B
 * 6: timer/counter1 overflow
 * 7: timer/counter1 capture event
 */

#define ADC_AUTO_TRIGGER_ENABLE OFF
#define AUTO_TRIGGER_MODE 0

/* ADC interrupt enable by 1 or disable by 0 */

#define ADC_INTERRUPT_ENABLE OFF

/* ADC pre-scaler selection */

#define DEVISION_FACTOR 3


#endif /* ADC_CONFIG_H_ */