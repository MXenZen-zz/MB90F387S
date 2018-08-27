/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Pins															             */
/**
 *	@file		pin.c
 *	@brief		This file contains the sample test program for PIN debugging.
 *	@details	In this test, two built-in buttons and two built-in LEDs will
 *				be used to demonstrate two different ways to access and modify
 *				the pin's mode (data direction) and data (logic/state): the
 *				IO register level access and the LUT volatile pointer access.
 *				LED will turn ON whenever the push button is pressed, and
 *				conversely if the push button is released or floating.
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
 *		Outputs		: P10, P11
 *		Driver		: PIN
 *		Helper		: N/A
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <GPIO/pin.h>

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

	/* IO Register Level Access */
	/* initialize IO pin modes */
	WriteBitIOPinMode(PIN_D10, PIN_OUTPUT);
	WriteBitIOPinMode(PIN_D25, PIN_INPUT);
	/* initialize IO pin state */
	WriteBitIOPinData(PIN_P10, PIN_LOW);

	/* LUT Volatile Pointer Access */
	/* initialize pin modes */
	SetPINMode(PIN11);
	ClearPINMode(PIN27);
	/* initialize pin state */
	ClearPINData(PIN11);

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
	/* IO Register Level Access */
	/* check for recent pin state */
	if (IS(ReadBitIOPinData(PIN_P25))) {
		/* set pin data HIGH */
		WriteBitIOPinData(PIN_P10, PIN_HIGH);
	} else {
		/* set pin data LOW */
		WriteBitIOPinData(PIN_P10, PIN_LOW);
	}

	/* LUT Volatile Pointer Access */
	/* check for recent pin state */
	if (IS(GetPINData(PIN27))) {
		/* set pin data (HIGH) */
		SetPINData(PIN11);
	} else {
		/* clear pin data (LOW) */
		ClearPINData(PIN11);
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

/* END OF PIN. */
