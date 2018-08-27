/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Digital Input / Output										             */
/**
 *	@file		dio.c
 *	@brief		This file contains the sample test program for DIO debugging.
 *	@details	In this test, two pins with opposite edge trigger or activation
 *				logic level will undergo counter-based software debouncing. The
 *				logic level returned after debouncing will be the actual pin
 *				data (logic/state).
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
 *		Inputs		: P25, P27
 *		Outputs		: N/A
 *		Driver		: DIO
 *		Helper		: SER (UART)
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <COM/ser.h>
#include <GPIO/dio.h>

/* ----------------------------------------------------------------------------
**	Test Flags.
*/

/**
 * 	@def		DIO_DEBOUNCE_SAMPLES
 *  @brief		Sample count for debouncing (state trigger).
 */
#define DIO_DEBOUNCE_SAMPLES	(8U)		/* TODO:EXPERIMENT: Change debounce sample count! */

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
	initSER();
	setSERUsage(SER_APP);
	/* initialize IO pin modes (write to IO pin mode) */
	WriteBitIOPinMode(PIN_D25, PIN_INPUT);
	WriteBitIOPinMode(PIN_D27, PIN_INPUT);

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
	static T_swDebBuffer swDebPin25, swDebPin27;

	/* wait for positive trigger debounce (read from IO pin data) */
	if (readDebouncedPosTrig(&swDebPin25, DIO_DEBOUNCE_SAMPLES, ReadBitIOPinData(PIN_P25))) {
		/* print positive trigger confirmation */
		sPrintLn("TRIG+");
	}
	/* wait for negative trigger debounce (read from IO pin data) */
	if (NOT(readDebouncedNegTrig(&swDebPin27, DIO_DEBOUNCE_SAMPLES, ReadBitIOPinData(PIN_P27)))) {
		/* print negative trigger confirmation */
		sPrintLn("TRIG-");
	}
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
