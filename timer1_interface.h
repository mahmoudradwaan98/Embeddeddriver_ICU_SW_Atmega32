/******************************************************************************/
/*****************************************************************************/
/****************    Author    : Mahmoud Radwan       ***********************/
/****************    Layer     : MCAL                 **********************/
/****************    SWC       : Timers  / Timer 1    *********************/
/****************    version   : 1.0                  ********************/
/************************************************************************/
/***********************************************************************/


#ifndef TIMER1_interface_H_

 #define TIMER1_interface_H_
 
	void TIMER1_voidInit(void);
	
	void TIMER1_voidSetTimerValue(u16 copy_u16Value);
	
    void TIMER1_voidSetTopValue(u16 copy_u16TopValue);

    void TIMER1_voidSetCompareMatchValueChannel_1A(u16 copy_u16CompValue1A);

    void TIMER1_voidSetCompareMatchValueChannel_1B(u16 copy_u16CompValue1B);
	
	u8   TIMER1_u8setcallback(void(*copy_ptrvoidfunc)(void));
		
#endif