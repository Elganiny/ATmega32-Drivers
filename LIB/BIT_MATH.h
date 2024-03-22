/****************************************************************/
/*    Author:  Mohammed Aljanayni                               */
/*    Layer:   Microcontroller Abstraction Layer (MCAL)         */
/*    SWC:     BIT_MATH                                         */
/*    Version: 2.10                                             */
/****************************************************************/

/**
 * @file BIT_MATH.h
 * @brief Bit Manipulation Macros
 *
 * This header file provides macros for convenient bit manipulation operations.
 * It includes macros for setting, clearing, toggling, and getting the value of a bit.
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

/**
 * @brief Set a bit in a variable
 * 
 * @param VAR The variable to modify
 * @param BIT_NO The bit number to set
 */
#define SET_BIT(VAR,BIT_NO)			(VAR|=(1<<BIT_NO))

/**
 * @brief Clear a bit in a variable
 * 
 * @param VAR The variable to modify
 * @param BIT_NO The bit number to clear
 */
#define CLR_BIT(VAR,BIT_NO)			(VAR&=(~(1<<BIT_NO)))

/**
 * @brief Toggle a bit's value in a variable
 * 
 * @param VAR The variable to modify
 * @param BIT_NO The bit number to toggle
 */
#define TOGGLE_BIT(VAR,BIT_NO)		(VAR^=(1<<BIT_NO))

/**
 * @brief Get a bit's value in a variable
 * 
 * @param VAR The variable to modify
 * @param BIT_NO The bit number to get
 */
#define GET_BIT(VAR,BIT_NO)			((VAR>>BIT_NO)&0x01)

#endif