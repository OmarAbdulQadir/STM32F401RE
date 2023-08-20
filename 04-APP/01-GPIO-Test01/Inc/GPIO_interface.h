/**********************************************************************************/
/***						Date: 16/8/2023	Day: Wednesday						***/
/***		General purpose I/O driver for the microcontroller STM32F401		***/
/***    			 Created By: Omar Abdul Qadir	 Version= 2.0	            ***/
/**********************************************************************************/
/***		         Note: All the data in the file is readable,				***/
/***			And any editing will affect the controller's behavior,			***/
/***				  So It's not recommended to edit any data,					***/
/***			Unless you are sure of what is the effect on behaviors.			***/
/**********************************************************************************/



/************************************************************************************************
		
-The Functionality Of Pines : 
		
		- Input		: (Defult= PullUp | PullDowen | Floating ---> When To Use ????? )  .
		- Floating	: (Not Connect High Or Low Between (0:1) ) When Used ---> With Sensor To Be Sensetive For Zero And 1 And Between  .
		- Pull_Up&Dowen ( To Treat The Floating On The Pin To Read Only ( 1 | 0 ) Nothing In Between ) .
		- OutPut    : Can Be (PushPull | OpenDrain ) .
		- PushPull  : The OutPut From This Case High=1 | LOW = 0  .
		- OpenDrain : The OutPut From This Case At( Pull_Up & PullDowen )  .
							- At Pull_UP   0 == Ground & 1 == Floating .
							- The Advantage Of This Case When You Make OutPut Pin out Floating you Can Connect Vcc From Out Not Micro So Any Volt You Need Connect It Direct And Any Current ( Configrable - High Level Volt) .
							- Must Connect Resistance For The Case Of Zero Not Make Short Circuit At  ( Configrable - High Level Volt) .
							- Open Drain Bus Not Make Short Circuit Between Two Micro At The Same Bus When One Send 1 And Oher Send 0 .
							- At PullDowen 1 == Vcc & 0 == Floating  -----> So Will give Output Only In This Case  .
							
		- Altternative Function : Every Pin Can Make 16 Function Anther (InPut , OutPut , Analog)  As ( Uart , Spi , Can , Timer , ADC , I2C , ........)        Every Pin Need 4 Bit 
		- ALF : From GPIO Choice Bit AS ALF But The Function From -----> ????????
				
	
************************************************************************************************/ 


#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H

/**********************************************************************************
 ******************* 			GPIO_voidSetPinModc					***************
 **********************************************************************************/ 
void GPIO_voidSetPinMode(u8 copy_u8PORT ,u8 copy_u8PIN,u8 copy_u8MODE)  ;


/**********************************************************************************
 *******************		 	GPIO_voidSetOutType					***************
 **********************************************************************************/ 
void GPIO_voidSetOutType(u8 copy_u8PORT ,u8 copy_u8PIN,u8 copy_u8Type)  ;


/**********************************************************************************
 *******************		 	GPIO_voidSetOutSpee					***************
 **********************************************************************************/ 
void GPIO_voidSetOutSpeed(u8 copy_u8PORT ,u8 copy_u8PIN,u8 copy_u8Speed)  ;


/**********************************************************************************
 *******************		 	GPIO_voidSetPull					***************
 **********************************************************************************/ 
void GPIO_voidSetPull(u8 copy_u8PORT ,u8 copy_u8PIN,u8 copy_u8PULL_TYPE)  ;


/**********************************************************************************
 *******************		 	GPIO_u8ReadData						***************
 **********************************************************************************/ 
u8 GPIO_u8ReadData(u8 copy_u8PORT ,u8 copy_u8PIN)  ;


/**********************************************************************************
 *******************		 	GPIO_voidWriteData					***************
 **********************************************************************************/ 
void GPIO_voidWriteData(u8 copy_u8PORT ,u8 copy_u8PIN , u8 copy_u8Value )  ;


/**********************************************************************************
 *******************		 	GPIO_voidPinSetAltFn				***************
 **********************************************************************************/  
void GPIO_voidPinSetAltFn(u8 copy_u8PORT ,u8 copy_u8PIN,u8 copy_u8AlT)  ;


/**********************************************************************************
 *******************		 	GPIO_voidSetOutType					***************
 **********************************************************************************/ 
			/* Macros Of Port */
			
#define  GPIOA_PORT										0
#define  GPIOB_PORT										1
#define  GPIOC_PORT										2
#define  GPIOD_PORT										3
#define  GPIOE_PORT										4
#define  GPIOH_PORT								 		5

/**********************************************************************************
 ******************* 	guard of file will call on time in .c		***************
 **********************************************************************************/ 
			/* Macros Of Pins */

#define  PIN0									   		0
#define  PIN1									   		1
#define  PIN2									   		2
#define  PIN3									   		3
#define  PIN4									   		4
#define  PIN5									   		5
#define  PIN6									   		6
#define  PIN7									   		7
#define  PIN8									   		8
#define  PIN9									   		9
#define  PIN10											10
#define  PIN11											11
#define  PIN12											12
#define  PIN13											13
#define  PIN14											14
#define  PIN15											15

/**********************************************************************************
 ******************* 	guard of file will call on time in .c		***************
 **********************************************************************************/ 
			/*Macros Of Mode*/
#define MODE_INPUT							 			(0b00u)
#define MODE_OUTPUT							 			(0b01u)
#define MODE_ALTF									 	(0b10u)
#define MODE_ANALOG							 			(0b11u)

/**********************************************************************************
 ******************* 	guard of file will call on time in .c		***************
 **********************************************************************************/ 
			/*Macros Of Type*/

#define  OUTPUT_TYPE_PUSH_PULL							(0b0u)
#define  OUTPUT_TYPE_OPEN_DRAIN							(0b1u)

/**********************************************************************************
 ******************* 	guard of file will call on time in .c		***************
 **********************************************************************************/ 
			/*Macros Of Speed*/

#define OUTPUT_LOW_SPEED								(0b00u)
#define OUTPUT_MEDUIM_SPEED								(0b01u)
#define OUTPUT_HIGH_SPEED								(0b10u)
#define OUTPUT_VERY_HIGH_SPEED							(0b11u)

/**********************************************************************************
 ******************* 	guard of file will call on time in .c		***************
 **********************************************************************************/ 
			/*Macros Of PULL*/	

#define PULL_OFF										(0b00)
#define PULL_UP											(0b01)
#define PULL_DOWN										(0b10)

/**********************************************************************************
 ******************* 	guard of file will call on time in .c		***************
 **********************************************************************************/ 				
			/*Macros Write Data */	

#define  HIGH											(0b1)
#define  LOW											(0b0)

#endif /* GPIO_INTERFACE_H*/
/************************************************************************************************/
