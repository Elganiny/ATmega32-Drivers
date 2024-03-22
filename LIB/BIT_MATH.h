/****************************************************************/
/*    Author:  Mohammed Aljanayni                               */
/*    Layer:   Microcontroller Abstraction Layer (MCAL)         */
/*    SWC:     BIT_MATH                                         */
/*    Version: 2.10                                             */
/****************************************************************/


#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(VAR,BIT_NO)			(VAR|=(1<<BIT_NO))
#define CLR_BIT(VAR,BIT_NO)			(VAR&=(~(1<<BIT_NO)))
#define TOGGLE_BIT(VAR,BIT_NO)		(VAR^=(1<<BIT_NO))
#define GET_BIT(VAR,BIT_NO)			((VAR>>BIT_NO)&0x01)

#endif