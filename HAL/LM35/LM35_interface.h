/*-------------------------------------------------------
 * [FILE NAME]: LM35_TEMP_SENSOR.h
 *
 * [AUTHOR]: YOUSEF KHALED
 *
 * [DATE CREATED]: 10/10/2021
 *
 * [DESCRIPTION]: Header file for LM35_TEMP_SENSOR
 -------------------------------------------------------*/

#ifndef LM35_TEMP_SENSOR_H_
#define LM35_TEMP_SENSOR_H_
#include "../../LIB/STD_TYPES.h"
/*------------------------------------*
 *        functions prototype         *
 *------------------------------------*/

u8 LM35_getTemperature (void);

/*------------------------------------*
 *            Definition              *
 *------------------------------------*/

#define SENSOR_CHANNEL_ID         1
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150

#endif /* LM35_TEMP_SENSOR_H_ */