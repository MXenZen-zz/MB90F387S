/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* 16-bit Reload Timer									      			     */
/**
 *	@file		rlt.c
 *	@brief		This file contains the sample test program for RLT debugging.
 *	@details	In this test, two separately controlled LEDs will blink at their
 *				certain interval respectively by means of the RLT interrupt and
 *				its callback function. Since RLT only have 2, 8, and 32 divided
 *				clocks and a maximum timer count resolution of 16 bits, any
 *				interval higher than 32768 us (other than a factor of 32) might
 *				not be scheduled to interrupt at the right time, unless the
 *				timer is using an external clock source (event mode). Only
 *				reload and software trigger mode is demonstrated in this test.
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
 *		Outputs		: P10-P11
 *		Driver		: RLT
 *		Helper		: PIN
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <GPIO/pin.h>
#include <TMR/rlt.h>

/* ----------------------------------------------------------------------------
**	Interrupt Callback Functions.
*/

static T_void rlt0Func(T_void)
{
	/* toggle LED */
	WriteBitIOPinData(PIN_P10, NOT(ReadBitIOPinData(PIN_P10)));
}

static T_void rlt1Func(T_void)
{
	/* toggle LED */
	WriteBitIOPinData(PIN_P11, NOT(ReadBitIOPinData(PIN_P11)));
}

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

	/* initialize IO pin mode */
	WriteBitIOPinMode(PIN_D10, PIN_OUTPUT);
	WriteBitIOPinMode(PIN_D11, PIN_OUTPUT);
	/* initialize timer */
	initRLT();
	setupReloadTimer(RLT_CH0, 50000UL, &rlt0Func);	/* TODO:EXPERIMENT: Change the interval duration (131072 us MAX)! */
	setupReloadTimer(RLT_CH1, 100000UL, &rlt1Func);	/* TODO:EXPERIMENT: Change the interval duration (131072 us MAX)! */
	/* run timer */
	runReloadTimer(RLT_CH0);
	runReloadTimer(RLT_CH1);

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
	/* nothing to do */
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

/* END OF RLT. */
