/******************************************************************************/
/*****************************************************************************/
/****************    Author    : Mahmoud Radwan        **********************/
/****************    Layer     : MCAL                  *********************/
/****************    SWC       : Timers  / Timer 1     ********************/
/****************    version   : 1.0                   *******************/
/************************************************************************/
/***********************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "timer1_config.h"
#include "timer1_private.h"
#include "timer1_interface.h"
#include "timer1_register.h"

static void(*TIMER0_pvcallbackdfunc)(void) = NULL;

void TIMER1_voidSetTopValue(u16 copy_u16TopValue){
	
	ICR1 = copy_u16TopValue;
}

void TIMER1_voidSetCompareMatchValueChannel_1A(u16 copy_u16CompValue1A){
	
	OCR1A = copy_u16CompValue1A;
}

void TIMER1_voidSetCompareMatchValueChannel_1B(u16 copy_u16CompValue1B){
	
	OCR1B = copy_u16CompValue1B;
}

void TIMER1_voidInit(void){
	
	/* Choose Fast PWM mode in timer 1 (mode 14) we can change top value not constant */
	// CLR_BIT(TCCR1A,TCCR1A_WGM10);
	// SET_BIT(TCCR1A,TCCR1A_WGM11);
	// SET_BIT(TCCR1B,TCCR1B_WGM12);
	// SET_BIT(TCCR1B,TCCR1B_WGM13);
	
	/* choose normal mode by default */
	/* prescaler : division by 8 */

	CLR_BIT(TCCR1B,TCCR1B_CS10);

	SET_BIT(TCCR1B,TCCR1B_CS11);

	CLR_BIT(TCCR1B,TCCR1B_CS12);
	
	/*another way to set prescaler using mask technique */
	
	//  TCCR1B &= PRESCALER_MASK;
	//  TCCR1B |= DIVIDE_BY_8;
	
	/* Non inverted mode : Clear on Compare Match , Set on Top 
	
		                set bit COM1A1 / COM1B1 , clear bit COM1A0 / COM1B0
	
	   Inverted mode : set on Compare Match , clear on Top 
	
	                    set both bits COM1A1 / COM1B1 , COM1A0 / COM1B0
	*/
	
	// CLR_BIT(TCCR1A,TCCR1A_COM1A0);

	// SET_BIT(TCCR1A,TCCR1A_COM1A1);

}

void TIMER1_voidSetTimerValue(u16 copy_u16Value){
	
	TCNT1 = copy_u16Value;
}

u16 TIMER1_u16GetTimerReadValue(void){
	
	return TCNT1;
}
	
u8 TIMER1_u8setcallback(void(*copy_ptrvoidfunc)(void)){
	
	u8 Local_errorstate = OK;
	if(copy_ptrvoidfunc!=NULL){

		TIMER0_pvcallbackdfunc = copy_ptrvoidfunc;

	}
	else{
		Local_errorstate = NULLPOINTER;
	}


	return Local_errorstate;
}
	
void __vector_10(void)  __attribute((signal));

void __vector_10(void){

	if(TIMER0_pvcallbackdfunc!=NULL){

		TIMER0_pvcallbackdfunc();

	}
	else{
		//Do Nothing
	}
}
