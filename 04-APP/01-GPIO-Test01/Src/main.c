/*
 * main.c
 *
 *  Created on: Aug 16, 2023
 *      Author: Omar A.Qadir
 */

#include "../Inc/STD_TYPES.h"
#include "../Inc/BIT_MATH.h"

#include "../Inc/RCC_interface.h"
#include "../Inc/GPIO_interface.h"


int main(void){

	RCC_voidInitSysClock();

	GPIO_voidSetPinMode(GPIOA_PORT, PIN5, MODE_OUTPUT);
	GPIO_voidWriteData(GPIOA_PORT, PIN5, HIGH);


	while(1){

	}
	return 0;
}
