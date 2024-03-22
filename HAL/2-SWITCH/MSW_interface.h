/****************************************************************/
/*    Author:  Mohammed Aljanayni                               */
/*    Layer:   HAL (Hardware Abstraction Layer)                 */
/*    SWC:     SWITCH (Push Button Switch)                      */
/*    Version: 2.10                                             */
/****************************************************************/


/**
 * @file MSW_interface.h
 * @brief Push Button Switch Interface
 *
 * This header file provides an interface for interacting with push button switches.
 * It defines function prototypes for getting the state of a push button switch.
 * Additionally, it includes necessary dependencies such as DIO interface for GPIO control.
 */

#include "DIO_interface.h"

#ifndef MSW_INTERFACE_H
#define MSW_INTERFACE_H

/**
 * @brief Deboncer activation options
 */
#define MSW_u8DEACTIVATE_DEBOUNCER          0   /**< Deboncer deactivation option */
#define MSW_u8ACTIVATE_DEBOUNCER            1   /**< Deboncer activation option */

/**
 * @brief Pull type options
 */
#define MSW_u8PULL_DOWN                     0   /**< Pull down option */
#define MSW_u8PULL_UP                       1   /**< Pull up option */

/**
 * @brief Switch state options
 */
#define MSW_u8UNPRESSED                     0   /**< Switch unpressed state */
#define MSW_u8PRESSED                       1   /**< Switch pressed state */

/**
 * @brief Get the state of a push button switch
 * 
 * @param Copy_u8Port       The port where the switch is connected
 * @param Copy_u8Pin        The pin of the switch
 * @param Copy_u8Debouncer  The debouncer activation option
 * @param Copy_u8PullType   The pull type option
 * @param Copy_pu8State     Pointer to store the state of the switch
 * 
 * @return Status of the operation (0 for success, 1 for failure)
 */

u8 MSW_u8GetState(u8 Copy_u8Port, u8 Copy_u8Pin,u8 Copy_u8Debouncer,u8 Copy_u8PullType,u8* Copy_pu8State);

#endif