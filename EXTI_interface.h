/******************************************************************************/
/*****************************************************************************/
/****************    Author    : Mahmoud Radwan       ***********************/
/****************    Layer     : MCAL                 **********************/
/****************    SWC       : EXTI                  *********************/
/****************    version   : 1.0                  ********************/
/************************************************************************/
/***********************************************************************/


#ifndef EXTI_interface_H_

 #define EXTI_interface_H_


	#define  LOW_LEVEL          1
	#define  ON_CHANGE          2
	#define  FALLING_EDGE       3
	#define  RISING_EDGE        4
	
	#define  INT0               6        // GICR : general interrupt control register , address : 0x5B
	#define  INT1               7
	#define  INT2               5
 
    void EXTI_voidINT0Init_prebuild(void);

/*Description : function to set required sense control for INT0 using Post build Configuration Technique
 * Input : copy_u8SenseControl , InPut options : 1- LOW_LEVEL
 *                                               2- ON_CHANGE
 *                                               3- FALLING_EDGE
 *                                               4- RISING_EDGE
 * */
    u8 EXTI_u8INT0SetSenseControl(u8 copy_u8SenseControl);

	void EXTI_voidINT0Init(void);
	
	void EXTI_voidINT1Init(void);
	
	void EXTI_voidINT2Init(void);
	
	/* callback function for ISR */

	u8 EXTI_u8INT0SetCallback(void(*copy_PtrINT0Func)(void));
	
	/* Disable interrupt */
	u8 EXTI_u8DisableInterrupt(u8 copy_IntNum);

	
#endif
