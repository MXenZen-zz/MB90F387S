/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Timebase Timer												             */
/**
 *	@file		tbt.c
 *	@brief		This file contains the sample test program for TBT debugging.
 *	@details	In this test, an LED will blink at random intervals by means
 *				of the delay function. The elapsed time from the start will
 *				also be printed in minutes, seconds and milliseconds.
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
 *		Outputs		: P12
 *		Driver		: TBT
 *		Helper		: SER (UART), PIN
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <COM/ser.h>
#include <GPIO/pin.h>
#include <TMR/tbt.h>
#include <stdlib.h>

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
	WriteBitIOPinMode(PIN_D12, PIN_OUTPUT);
	/* initialize helper modules */
	initSER();
	setSERUsage(SER_APP);
	/* initialize timer */
	initTBT();
	/* initialize random number generator */
	srand(*((volatile T_uint16*)0x56U));

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
	/* toggle LED */
	WriteBitIOPinData(PIN_P12, NOT(ReadBitIOPinData(PIN_P12)));
	/* print elapsed time */
	uPrint(GetDWordTBTMins());
	sPrint(":");
	uPrint(GetDWordTBTSec() % 60UL);
	sPrint(".");
	uPrint(GetDWordTBTMillis() % 1000UL);
	printLn();
	/* random delay (5 ms MIN, 5 sec MAX) */
	delay((rand() + 5) % 5000);
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

/* END OF TBT. */
