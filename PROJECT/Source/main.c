/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Main		   									               	   	     	 */
/**
 *	@file		main.c
 *	@brief		This file contains the designated start of the program.
**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <MCU/mcu.h>

/* ----------------------------------------------------------------------------
**	Inline Functions.
*/

/**
 *  @fn			T_void setup(T_void)
 *  @brief 		Initialization / setup code runs once.
 *  @param		.
 *	@return		.
 */
#pragma inline setup
static T_void setup(T_void)
{
	__DI();
	__set_il(7);

	/* TODO: Add initialization code here. */

	__EI();
}

/**
 *  @fn			T_void loop(T_void)
 *  @brief 		Iteration / loop code runs repeatedly.
 *  @param		.
 *	@return		.
 */
#pragma inline loop
static T_void loop(T_void)
{
	/* TODO: Add iteration code here. */
}

/* ----------------------------------------------------------------------------
**	Main Function.
*/

/**
 *  @fn			T_void main(T_void)
 *  @brief 		Main / program entry point.
 *  @param		.
 *	@return		.
 */
T_void FAR main(T_void)
{
	/* initialize first */
	setup();
	/* then iterate indefinitely */
	for (;;) {
		loop();
	}
}

/* END OF MAIN. */
