

/*Preprocessor file guard*/
#ifndef CLCD_CONFIG_H_
#define CLCD_CONFIG_H_

//Control pins
#define CLCD_CTRL_PORT		DIO_u8PORTC
#define CLCD_RS_PIN			DIO_u8PIN7
#define CLCD_RW_PIN			DIO_u8PIN6
#define CLCD_E_PIN			DIO_u8PIN5


//Data port
#define CLCD_DATA_PORT		DIO_u8PORTD

//Mode
#define CLCD_MODE			EIGHT_BITS

//Data pin in FOUR_BITS mode
#define  CLCD_D4		DIO_u8PIN4
#define  CLCD_D5		DIO_u8PIN5
#define  CLCD_D6		DIO_u8PIN6
#define  CLCD_D7		DIO_u8PIN7


#endif