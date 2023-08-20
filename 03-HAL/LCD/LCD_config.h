/**********************************************************************************/
/***						Date: 17/8/2023	Day: Thursday						***/
/***			LCD display driver for the microcontroller STM32F401			***/
/***    			 Created By: Omar Abdul Qadir	 Version= 2.0	            ***/
/**********************************************************************************/
/***		         Note: All the data in the file is readable,				***/
/***			And any editing will affect the controller's behavior,			***/
/***				  So It's not recommended to edit any data,					***/
/***			Unless you are sure of what is the effect on behaviors.			***/
/**********************************************************************************/

/**********************************************************************************
 ******************* 	guard of file will call on time in .c		***************
 **********************************************************************************/
#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H
	

/**********************************************************************************
 *******************	 	   LCD interfacing mode					***************
 **********************************************************************************/
	// LCD 8bit mode value
	#define _8bit_interface 0
	// LCD 4bit mode value
	#define _4bit_interface 1
	// LCD Selection of the mode
	#define _LCD_interface_ _4bit_interface
	
	
/**********************************************************************************
 *******************	 	   		Ports definition				***************
 **********************************************************************************/
	// Control port connection
	#define lcd_ctrl_port 	GPIOA_PORT
	// Data port connection
	#define lcd_data_port 	GPIOA_PORT


/**********************************************************************************
 *******************	 	   Control pins definition			***************
 **********************************************************************************/
	// Enable pin
	#define lcd_EN 			PIN0
	// Read/Write pin
	#define lcd_RW 			PIN1
	// Register select pin
	#define lcd_RS 			PIN2


/**********************************************************************************
 *******************	 	   Data pins definition					***************
 **********************************************************************************/
	// Pin data 0
	#define lcd_d0			PIN3
	// Pin data 1
	#define lcd_d1			PIN4
	// Pin data 2
	#define lcd_d2			PIN5
	// Pin data 3
	#define lcd_d3			PIN6
	// Pin data 4
	#define lcd_d4			PIN7
	// Pin data 5
	#define lcd_d5			PIN8
	// Pin data 6
	#define lcd_d6			PIN9
	// Pin data 7
	#define lcd_d7			PIN10
	
#endif	//End LCD_CONFIG_H
