/****************************************************************/
/*    Author:  Mohammed Aljanayni                               */
/*    Layer:   Microcontroller Abstraction Layer (MCAL)         */
/*    SWC:     STD_Types                                        */
/*    Version: 2.10                                             */
/****************************************************************/

/**
 * @file STD_Types.h
 * @brief Standard Data Types Definitions
 *
 * This header file defines standard data types used throughout the project.
 * It includes typedefs for various integer types and floating-point types.
 * Additionally, it defines common macros such as F_CPU, NULL, OK, and NOK.
 */


/**
 * @brief 8-bit unsigned integer type
 */
typedef unsigned char u8;

/**
 * @brief 8-bit signed integer type
 */
typedef signed char s8;

/**
 * @brief 16-bit unsigned integer type
 */
typedef unsigned short int u16;

/**
 * @brief 16-bit signed integer type
 */
typedef signed short int s16;

/**
 * @brief 32-bit unsigned integer type
 */
typedef unsigned long int u32;

/**
 * @brief 32-bit signed integer type
 */
typedef signed long int s32;

/**
 * @brief 32-bit floating-point type
 */
typedef float f32;

/**
 * @brief 64-bit floating-point type
 */
typedef double f64;

/**
 * @brief Default CPU frequency (Hz)
 */
# define F_CPU 800000UL

/**
 * @brief Null pointer
 */
#define NULL 0

/**
 * @brief Operation success code
 */
#define OK	0

/**
 * @brief Operation failure code
 */
#define NOK 1