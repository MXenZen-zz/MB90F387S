/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Programmable Pulse Generator			 						             */
/**
 *	@file		ppg.c
 *	@brief		This file contains the sample test program for PPG debugging.
 *	@details	In this test, two separately controlled LEDs will blink at
 *				their certain interval respectively by means of the PPG timer
 *				interrupt and its callback function. Two 8-bit independent PPG
 *				channels are initialized to execute the callback functions at
 *				different interrupt intervals. Inside the callback function is
 *				an interrupt count condition wherein the LED will toggle if it
 *				has reached the right count. Both callback functions are
 *				intended to cause both separately controlled LEDs to toggle
 *				almost simultaneously. Since PPG only have 1, 2, 4, 8, 16, and
 *				2048 (512/HCLK) divided clocks and a maximum timer count
 *				resolution of 8 bits (for independent PPG channels), any
 *				interval higher than 256 us (other than a factor of 2048)
 *				might not be scheduled to interrupt at the right time.
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
 *		Driver		: PPG (Timer-Only)
 *		Helper		: PIN
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <GPIO/pin.h>
#include <TMR/ppg.h>

/* ----------------------------------------------------------------------------
**	Interrupt Callback Functions.
*/

static T_void ppgAFunc(T_void)
{
	static T_uint32 aIntCount;

	/* check if interrupt count is enough to reach 500 ms at 1 ms interval */
	if (GEQ(++aIntCount, 500UL)) {
		/* toggle LED */
		WriteBitIOPinData(PIN_P10, NOT(ReadBitIOPinData(PIN_P10)));
		/* reset interrupt count */
		aIntCount = 0UL;
	}
}
static T_void ppgBFunc(T_void)
{
	static T_uint32 bIntCount;

	/* check if interrupt count is enough to reach 500 ms at 10 ms interval */
	if (GEQ(++bIntCount, 50UL)) {
		/* toggle LED */
		WriteBitIOPinData(PIN_P11, NOT(ReadBitIOPinData(PIN_P11)));
		/* reset interrupt count */
		bIntCount = 0UL;
	}
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
	initPPG();
	setupPPGTimer(PPG_CH1, 1000UL, &ppgAFunc);				/* 1 ms interval */
	setupPPGTimer(PPG_CH2, 10000UL, &ppgBFunc);				/* 10 ms interval */
	/* run timer */
	runPPGTimer(PPG_CH1);
	runPPGTimer(PPG_CH2);

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

/* END OF PPG. */
