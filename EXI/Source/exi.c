/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* DTP / External Interrupt										             */
/**
 *	@file		exi.c
 *	@brief		This file contains the sample test program for EXI debugging.
 *	@details	In this test, all five external interrupt input channels
 *				will be used to demonstrate external interrupt activation
 *				(edge trigger only) and execution of customized (user-defined)
 *				external interrupt callback function. The callback function
 *				which corresponds to the activated external interrupt input
 *				channel will print activation confirmation whenever rising
 *				or falling edge is detected.
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
 *		Inputs		: INT4-INT7 (P24-P27), RX (P44)
 *		Outputs		: N/A
 *		Driver		: EXI
 *		Helper	 	: SER (UART)
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <COM/ser.h>
#include <INT/exi.h>

/* ----------------------------------------------------------------------------
**	Interrupt Callback Functions.
*/

static T_void exi4Func(T_void)
{
	/* print activation */
	sPrintLn("INT4 Triggered!");
}

static T_void exi5Func(T_void)
{
	/* print activation */
	sPrintLn("INT5 Triggered!");
}

static T_void exi6Func(T_void)
{
	/* print activation */
	sPrintLn("INT6 Triggered!");
}

static T_void exi7Func(T_void)
{
	/* print activation */
	sPrintLn("INT7 Triggered!");
}

static T_void exi0Func(T_void)
{
	/* print activation */
	sPrintLn("INT0 (RX) Triggered!");
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
	/* initialize all external interrupts */
	initEXI();
	/* attach external interrupts */
	/* IO pin mode set as input automatically for P24-P27, P44 */
	attachEXI(EXI_CH4, EXI_DETECT_FALL, &exi4Func);
	attachEXI(EXI_CH5, EXI_DETECT_FALL, &exi5Func);
	attachEXI(EXI_CH6, EXI_DETECT_RISE, &exi6Func);
	attachEXI(EXI_CH7, EXI_DETECT_RISE, &exi7Func);
	attachEXI(EXI_RX,  EXI_DETECT_FALL, &exi0Func);

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

/* END OF EXI. */
