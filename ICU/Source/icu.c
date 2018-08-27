/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Input Capture Unit									      			     */
/**
 *	@file		icu.c
 *	@brief		This file contains the sample test program for ICU debugging.
 *	@details	In this test, all four input capture unit interrupt channels
 *				will be used to demonstrate input capture unit interrupt
 *				activation (edge trigger only) and execution of customized
 *				(user-defined) input capture unit interrupt callback function.
 *				The callback function which corresponds to the activated
 *				input capture unit interrupt channel will print activation
 *				confirmation whenever rising or falling edge is detected.
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
 *		Inputs		: IN0-IN3 (P10-P13)
 *		Outputs		: N/A
 *		Driver		: ICU (Interrupt-Only)
 *		Helper		: SER (UART)
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <COM/ser.h>
#include <INT/icu.h>

/* ----------------------------------------------------------------------------
**	Interrupt Callback Functions.
*/

static T_void icu0Func(T_void)
{
	/* print activation */
	sPrintLn("IN0 Triggered!");
}

static T_void icu1Func(T_void)
{
	/* print activation */
	sPrintLn("IN1 Triggered!");
}

static T_void icu2Func(T_void)
{
	/* print activation */
	sPrintLn("IN2 Triggered!");
}

static T_void icu3Func(T_void)
{
	/* print activation */
	sPrintLn("IN3 Triggered!");
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

	/* initialize helper modules */
	initSER();
	setSERUsage(SER_APP);
	/* initialize all input capture unit interrupts */
	initICU();
	/* attach input capture unit interrupts */
	/* IO pin mode set as input automatically for P10-P13 */
	attachICU(ICU_CH0, ICU_DETECT_FALL, &icu0Func);
	attachICU(ICU_CH1, ICU_DETECT_FALL, &icu1Func);
	attachICU(ICU_CH2, ICU_DETECT_RISE, &icu2Func);
	attachICU(ICU_CH3, ICU_DETECT_RISE, &icu3Func);

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

/* END OF ICU. */
