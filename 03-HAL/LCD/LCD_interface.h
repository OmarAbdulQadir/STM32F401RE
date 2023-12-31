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
#ifndef LCD_INTERFACE_H
#define LCD_INTERFACE_H

/**********************************************************************************
 *******************	 			LCD_init						***************
 **********************************************************************************/
void LCD_init(void );

/**********************************************************************************
 *******************	 			LCD_set_cursor					***************
 **********************************************************************************/
void LCD_set_cursor(u8, u8 );

/**********************************************************************************
 *******************	 			LCD_clear						***************
 **********************************************************************************/
void LCD_clear(void );

/**********************************************************************************
 *******************	 			LCD_off							***************
 **********************************************************************************/
void LCD_off(void );

/**********************************************************************************
 *******************	 			LCD_on							***************
 **********************************************************************************/
void LCD_on(void );

/**********************************************************************************
 *******************	 			LCD_create_char					***************
 **********************************************************************************/
void LCD_create_char(u8*, u8 );

/**********************************************************************************
 *******************	 			LCD_write_char					***************
 **********************************************************************************/
void LCD_write_char(u8 );

/**********************************************************************************
 *******************	 			LCD_write_str					***************
 **********************************************************************************/
void LCD_write_str(u8* );

/**********************************************************************************
 *******************	 		LCD_write_s32_number				***************
 **********************************************************************************/
void LCD_write_s32_number(s32 );

/**********************************************************************************
 *******************	 			LCD_write_float					***************
 **********************************************************************************/
void LCD_write_float(f32, u8 );

#endif	//end LCD_INTERFACE_H
