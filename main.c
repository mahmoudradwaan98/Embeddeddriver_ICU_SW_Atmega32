/*
 *  Application : main.c
 *
 *  Created on : April 23, 2023
 *  Author     : Mahmoud Radwan
 *	version    : 1.0
 */

#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include"PORT_interface.h"
#include "DIO_interface.h"
#include "timers_interface.h"
#include "GIE_interface.h"
#include <util/delay.h>
void PWM(void);
void LED(void);

void main(void){

	PORT_voidInit();

	TIMER0_voidInit();

	//TIMER0_u8setcallback(&PWM);

	//GIE_voidEnable();

    /* Fast PWM example for led intensity , set pin OC0 output direction (Port B3) */

	u8 Local_u8counter;


	while(1){
		
		for(Local_u8counter=0;Local_u8counter<255;Local_u8counter++){
			
			TIMER0_voidSetCompareMatchValue(Local_u8counter);
			_delay_ms(10);
		}
	
	}



}
/*
void PWM(void){

	static u8 Local_u8counter = 0;
	Local_u8counter++;

	if(Local_u8counter==5){

		//set pin to Low 
		DIO_u8SetPinValue(DIO_U8PORTA,DIO_U8PIN0,DIO_U8PIN_LOW);
	}
	else if(Local_u8counter==20){

		//set pin to High
		DIO_u8SetPinValue(DIO_U8PORTA,DIO_U8PIN0,DIO_U8PIN_HIGH);

		Local_u8counter = 0;
	}
}

*/

/*
void LED(void){


	static u16 Local_u16counter = 0;
	static u8 Local_ledstate=0;
	Local_u16counter++;

	if(Local_u16counter==4000){

		// Toggle led 

		TOGGLE_BIT(Local_ledstate,0);

		DIO_u8SetPinValue(DIO_U8PORTA,DIO_U8PIN1,Local_ledstate);

		Local_u16counter=0;

	}

}
*/
