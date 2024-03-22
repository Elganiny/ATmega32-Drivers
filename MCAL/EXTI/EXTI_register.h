/*
 * EXTI_regesters.h
 *
 * Created: 9/27/2023 2:56:21 AM
 *  Author: ASUS
 */ 


#ifndef EXTI_REGESTERS_H_
#define EXTI_REGESTERS_H_


/* MCU Control Register */
#define MCUCR	*( (volatile u8*) 0x55)
/* Bits number 7:4 are not used in this driver */
#define MCUCR_ISC00		0
#define MCUCR_ISC01		1
#define MCUCR_ISC10		2
#define MCUCR_ISC11		3

/* MCU Control and Status Register */
#define MCUCSR *( (volatile u8*) 0x54)
/* Bit 5 is reserved , Other bits are not used in this driver */
#define MCUCSR_ISC2 6

/* GICR Register */
#define GICR	*( (volatile u8*) 0x5B)
/* bits 4,3,2 are reserved , bits 1,0 are for another peripheral */
#define GICR_INT1		7
#define GICR_INT0		6
#define GICR_INT2		5

/*GIFR Register */
#define GIFR *( (volatile u8 *) 0x5A)
/* Other bits are not used in this driver */
#define GIFR_INTF1 7
#define GIFR_INTF0 6
#define GIFR_INTF2 5

#endif /* EXTI_REGESTERS_H_ */