/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Digital Input / Output										             */
/**
 *	@file		dio.c
 *	@brief		This file contains the sample test program for DIO debugging.
 *	@details	In this test, a dedicated shift register IC or similar module
 *				is required and must be wired correctly to have a stable
 *				master-slave communication. The shifted-out data must match
 *				the shifted-in data (or loopback) regardless of edge trigger
 *				and first transferred significant bit.
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
 *		Outputs		: P15-P16
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
 * 	@def		DIO_SHIFT_CLK
 *  @brief		Shift-clock pin (literal pin number instead of pin macro).
 */
#define DIO_SHIFT_CLK			(15U)		/* TODO:EXPERIMENT: Change pin number! */

/**
 * 	@def		DIO_SHIFT_OUT
 *  @brief		Shift-out pin (literal pin number instead of pin macro).
 */
#define DIO_SHIFT_OUT			(16U)		/* TODO:EXPERIMENT: Change pin number! */

/**
 * 	@def		DIO_SHIFT_IN
 *  @brief		Shift-in pin (literal pin number instead of pin macro).
 */
#define DIO_SHIFT_IN			(17U)		/* TODO:EXPERIMENT: Change pin number! */

/**
 * 	@def		DIO_SHIFT_LSB_FIRST
 *  @brief		Shift first bit transfer.
 */
#define DIO_SHIFT_LSB_FIRST		FALSE		/* TODO:EXPERIMENT: LSB / MSB first! */

/**
 * 	@def		DIO_SHIFT_NEG_TRIG
 *  @brief		Shift data transfer edge trigger.
 */
#define DIO_SHIFT_NEG_TRIG		TRUE		/* TODO:EXPERIMENT: POS / NEG trigger! */

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
	/* initialize numerical pins */
	pinModeDigital(DIO_SHIFT_CLK, PIN_OUTPUT);
	pinModeDigital(DIO_SHIFT_OUT, PIN_OUTPUT);
	pinModeDigital(DIO_SHIFT_IN, PIN_INPUT);

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
	static T_uint8 shiftTX, shiftRX;

	/* increment data to send then shift data out */
	shiftOut(DIO_SHIFT_OUT, DIO_SHIFT_CLK, DIO_SHIFT_LSB_FIRST, DIO_SHIFT_NEG_TRIG, ++shiftTX);
	/* shift data in then store shifted data */
	shiftRX = shiftIn(DIO_SHIFT_IN, DIO_SHIFT_CLK, DIO_SHIFT_LSB_FIRST, DIO_SHIFT_NEG_TRIG);
	/* print shift confirmation */
	sPrint("TX : RX = ");
	iPrint(shiftTX);
	sPrint(" : ");
	iPrint(shiftRX);
	/* print error if loopback data mismatched */
	if (NEQ(shiftTX, shiftRX)) {
		sPrint(" [ERROR]");
	}
	printLn();
	/* next shift delay */
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
