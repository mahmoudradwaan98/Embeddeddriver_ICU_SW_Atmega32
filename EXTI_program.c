/******************************************************************************/
/*****************************************************************************/
/****************    Author    : Mahmoud Radwan       ***********************/
/****************    Layer     : MCAL                 **********************/
/****************    SWC       : EXTI                 *********************/
/****************    version   : 1.0                  ********************/
/************************************************************************/
/***********************************************************************/


#include "STD_TYPES.h"
#include "BIT_MATHS.h"

#include "EXTI_config.h"
#include "EXTI_private.h"
#include "EXTI_interface.h"
#include "EXTI_register.h"

/* Global pointer to function to hold INT0 ISR address */
void(*EXTI_PtrINT0Func)(void) = NULL;

u8 EXTI_u8INT0SetCallback(void(*copy_PtrINT0Func)(void)){

	u8 LocalErrorState = OK ;
	if(copy_PtrINT0Func!=NULL){

		EXTI_PtrINT0Func = copy_PtrINT0Func;

	}
	else {
		LocalErrorState= NULLPOINTER;
	}



	return LocalErrorState;
}


void EXTI_voidINT0Init_prebuild(void){
/* Check INT0 sense control */
#if INT0_SENSE == LOW_LEVEL

	CLR_BIT(MCUCR,MCUCR_ISC00);
	CLR_BIT(MCUCR,MCUCR_ISC01);

#elif INT0_SENSE == ON_CHANGE

	CLR_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);


#elif INT0_SENSE == RISING_EDGE

	SET_BIT(MCUCR,MCUCR_ISC01);
	SET_BIT(MCUCR,MCUCR_ISC00);

#elif INT0_SENSE == FALLING_EDGE

	SET_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);
#else

    #error "Wrong INT0 sense control configuration option"

#endif

/* Check peripheral interrupt enable initial state */

#if INT0_INTIAL_STATE == DISABLED

    #error "Wrong peripheral interrupt enable initial state configuration option"


#elif INT0_INTIAL_STATE == ENABLED

	SET_BIT(GICR,GICR_INT0);


#else

#endif

}
u8 EXTI_u8INT0SetSenseControl(u8 copy_u8SenseControl){

	u8 Local_ErrorState = OK;

	switch(copy_u8SenseControl){
	case LOW_LEVEL:    CLR_BIT(MCUCR,MCUCR_ISC00);CLR_BIT(MCUCR,MCUCR_ISC01);break;
	case ON_CHANGE:    CLR_BIT(MCUCR,MCUCR_ISC01);SET_BIT(MCUCR,MCUCR_ISC00);break;
	case FALLING_EDGE: SET_BIT(MCUCR,MCUCR_ISC01);CLR_BIT(MCUCR,MCUCR_ISC00);break;
	case RISING_EDGE:  SET_BIT(MCUCR,MCUCR_ISC01);SET_BIT(MCUCR,MCUCR_ISC00);break;
	default:           Local_ErrorState = NOK;break;
	}

/*	if(copy_u8SenseControl==LOW_LEVEL){
		CLR_BIT(MCUCR,MCUCR_ISC00);
		CLR_BIT(MCUCR,MCUCR_ISC01);
	}
	else if(copy_u8SenseControl==ON_CHANGE){
		CLR_BIT(MCUCR,MCUCR_ISC01);
		SET_BIT(MCUCR,MCUCR_ISC00);
	}
	else if(copy_u8SenseControl==FALLING_EDGE){
		SET_BIT(MCUCR,MCUCR_ISC01);
		CLR_BIT(MCUCR,MCUCR_ISC00);
	}
	else if(copy_u8SenseControl==RISING_EDGE){
		SET_BIT(MCUCR,MCUCR_ISC01);
		SET_BIT(MCUCR,MCUCR_ISC00);
	}
	else{
		 Local_ErrorState = NOK;
	}*/


	return Local_ErrorState;

}
void EXTI_voidINT0Init(void){

		/* Set sense control for INT0 to falling edge */
		SET_BIT(MCUCR,MCUCR_ISC01);
		CLR_BIT(MCUCR,MCUCR_ISC00);


		/* Peripheral Interrupt Enable for INT0 */
		SET_BIT(GICR,GICR_INT0);


	}
	
void EXTI_voidINT1Init(void){
		
		/* Set sense control for INT1 to falling edge */
		SET_BIT(MCUCR,MCUCR_ISC01);
		CLR_BIT(MCUCR,MCUCR_ISC00);


		/* Peripheral Interrupt Enable for INT1 */
		SET_BIT(GICR,GICR_INT1);

	}
	
void EXTI_voidINT2Init(void){
		
		/* Set sense control for INT2 to falling edge */
		CLR_BIT(MCUCSR,MCUCSR_INT2);


		/* Peripheral Interrupt Enable for INT2 */
		SET_BIT(GICR,GICR_INT2);

	}

u8 EXTI_u8DisableInterrupt(u8 copy_IntNum){
	
	u8 Local_u8ErrorState = OK;
	
	if((copy_IntNum >= INT2)&&(copy_IntNum <= INT1)){
		/* Clear required bit */
	    CLR_BIT(GICR,copy_IntNum);
	}
	else{
		Local_u8ErrorState = NOK;
	}
	
	return Local_u8ErrorState;
}

u8 EXTI_u8EnableInterrupt(u8 copy_IntNum){
	
	u8 Local_u8ErrorState = OK;
	
	if((copy_IntNum >= INT2)&&(copy_IntNum <= INT1)){
		/* Clear required bit */
	    SET_BIT(GICR,copy_IntNum);
	}
	else{
		Local_u8ErrorState = NOK;
	}
	
	return Local_u8ErrorState;
}

void __Vector_1 (void) __attribute__((signal));

void __Vector_1 (void){

	if(EXTI_PtrINT0Func!=NULL){

		EXTI_PtrINT0Func();

	}
	else {
		/* Do Nothing */
	}
}
