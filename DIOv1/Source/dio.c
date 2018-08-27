/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Digital Input / Output										             */
/**
 *	@file		dio.c
 *	@brief		This file contains the sample test program for DIO debugging.
 *	@details	In this test, a pin's mode (data direction) will be set to
 *				output and its pin data (logic/state) will be inverted, checked,
 *				and compared to the expected state (logic test).
**/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *	Copyright (C) 2015-2017 Xeno Xerxes Masong (xxmasong@gmail.com)
 *
 *	This program does not guarantee that it shall fulfill its task
 *	under all circumstances. Thus, the author/developer shall not
 *	be held liable for any damages that might be incurred by the
 *	device using this program, or for any reason whatsoever.
 *
 *	This program is free software: you can redistribute it and/or
 *	modify it under the terms of the GNU General Public License as
 *	published by the Free Software Foundation, either version 3 of
 *	the License, or (at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program. If not, see <https://www.gnu.org/licenses/>.
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *	Target Hardware Information:
 *
 *		MCU			: F2MC-16LX MB90385 Series
 *		CPU			: MB90F387S
 *		Vcc			: 5.0 V
 *		Frequency	: 16 MHz (4 MHz PLLx4)
 *		Inputs		: N/A
 *		Outputs		: P14
 *		Driver		: DIO
 *		Helper		: SER (UART), TBT
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <COM/ser.h>
#include <GPIO/dio.h>
#include <TMR/tbt.h>

/* ----------------------------------------------------------------------------
**	Test Flags.
*/

/**
 * 	@def		DIO_SINGLE_PIN
 *  @brief		Pin for single test (literal pin number instead of pin macro).
 *  @see		PINXX where XX is the literal pin number (e.g. PIN14).
 */
#define DIO_SINGLE_PIN			(14U)		/* TODO:EXPERIMENT: Change pin number! */

/* ----------------------------------------------------------------------------
**	Inline Functions.
*/

/**
 *  @fn			T_void init(T_void)
 *  @brief 		Initialization / setup code runs once.
 *  @param		.
 *	@return		.
 */
#pragma inline init
static T_void init(T_void)
{
	__DI();
	__set_il(7);

	/* initialize helper modules */
	initTBT();
	initSER();
	setSERUsage(SER_APP);
	/* initialize pin mode */
	pinModeDigital(DIO_SINGLE_PIN, PIN_OUTPUT);
	/* initialize pin state */
	writeDigital(DIO_SINGLE_PIN, PIN_LOW);

	__EI();
}

/**
 *  @fn			T_void debug(T_void)
 *  @brief 		Iteration / loop code runs repeatedly.
 *  @param		.
 *	@return		.
 */
#pragma inline debug
static T_void debug(T_void)
{
	/* check for recent pin state */
	if (IS(readDigital(DIO_SINGLE_PIN))) {
		/* print state transition */
		sPrint("[HIGH] -> LOW: ");
		/* set pin data LOW */
		writeDigital(DIO_SINGLE_PIN, PIN_LOW);
		/* check for updated pin state */
		if (NOT(readDigital(DIO_SINGLE_PIN))) {
			/* print state update confirmation */
			sPrintLn("[LOW]");
		} else {
			/* print state update error */
			sPrintLn("[HIGH] (ERROR: Not Cleared!)");
		}
	} else {
		/* print state transition */
		sPrint("[LOW] -> HIGH: ");
		/* set pin data HIGH */
		writeDigital(DIO_SINGLE_PIN, PIN_HIGH);
		/* check for updated pin state */
		if (IS(readDigital(DIO_SINGLE_PIN))) {
			/* print state update confirmation */
			sPrintLn("[HIGH]");
		} else {
			/* print state update error */
			sPrintLn("[LOW] (ERROR: Not Set!)");
		}
	}
	/* next update delay */
	delay(100U);
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
	init();
	/* then iterate indefinitely */
	for (;;) {
		debug();
	}
}

/* END OF DIO. */
