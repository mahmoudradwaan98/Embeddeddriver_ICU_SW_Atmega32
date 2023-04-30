/*
 *  Application : app.c
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

void LED(void);

void PWM(void);

void main (void){
	
	PORT_voidInit();
	
	TIMER0_voidInit();
	
	//TIMER0_u8setcallback(&LED);
	
	TIMER0_u8setcallback(&PWM);
	
	GIE_voidEnable();
	
	while(1){
		
	}
	
	
}

void LED(void){
	
	static u16 Local_u16Counter = 0;
	static u8 Local_u8LedState  = 0;
	
	counter++;
	
	if(counter == 4000){
		
		/* Toggle led Action */
		
		TOGGLE_BIT(Local_u8LedState,0);
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,Local_u8LedState);
		
		Local_u16Counter = 0;
	}
}

void PWM(void){
	
	static u8 Local_u8Counter = 0;
	counter++;
	if(counter==5){
		
		/* set pin low */
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);
	}
	else if(counter==20){
		
		/* set pin high */
		DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
		counter = 0;
	}
}













