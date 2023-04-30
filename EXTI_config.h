/******************************************************************************/
/*****************************************************************************/
/****************    Author    : Mahmoud Radwan       ***********************/
/****************    Layer     : MCAL                 **********************/
/****************    SWC       : EXTI                  *********************/
/****************    version   : 1.0                  ********************/
/************************************************************************/
/***********************************************************************/

#ifndef EXTI_CONFIG_H_
#define EXTI_CONFIG_H_
/*options : sense control
  1- LOW_LEVEL
  2- ON_CHANGE
  3- FALLING_EDGE
  4- RISING_EDGE
 * */
/*intial state options:
 * 1- ENABLED
 * 2- DISABLED
 * */

#define INT0_SENSE                 RISING_EDGE
#define INT0_INTIAL_STATE          ENABLED



#define INT1_SENSE FALLING_EDGE

#define INT2_SENSE FALLING_EDGE

#endif
