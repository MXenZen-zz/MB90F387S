/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Universal Asynchronous Receiver/Transmitter							     */
/**
 *	@file		ser.c
 *	@brief		This file contains the sample test program for SER debugging.
 *	@details	In this test (serial printing), characters, strings, and numbers
 *				(signed and unsigned format, integral and floating types, and
 *				common base formats), will be printed to the serial terminal.
 *	@note		All serial print functions use and depend on the basic serial
 *				write function to transmit data.
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
 *		Inputs		: SIN1 (P40)
 *		Outputs		: SOT1 (P42)
 *		Driver		: SER (UART)
 *		Helper		: TBT
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <COM/ser.h>
#include <TMR/tbt.h>

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
	/* initialize SER (default settings) for use by application (APP) */
	initSER();
	setSERUsage(SER_APP);

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
	/* test printing string and character */
	sPrint("[SER]"); cPrint('\n');
	/* test printing binary number */
	sPrint("nPrint(0x12345678UL, SER_BIN, NULL): ");
	nPrint(0x12345678UL, SER_BIN, NULL);
	printLn();
	/* test printing octal number */
	sPrint("nPrint(0x12345678UL, SER_OCT, NULL): ");
	nPrint(0x12345678UL, SER_OCT, NULL);
	printLn();
	/* test printing decimal number */
	sPrint("nPrint(0x12345678UL, SER_DEC, NULL): ");
	nPrint(0x12345678UL, SER_DEC, NULL);
	printLn();
	/* test printing hexadecimal number */
	sPrint("nPrint(0x12345678UL, SER_HEX, NULL): ");
	nPrint(0x12345678UL, SER_HEX, NULL);
	printLn();
	/* test printing signed decimal number */
	sPrint("iPrint(-1): ");
	iPrint(-1);
	printLn();
	/* test printing unsigned decimal number */
	sPrint("uPrint(-1): ");
	uPrint(-1);
	printLn();
	/* test printing hexadecimal number with prefix and postfix */
	sPrint("xPrint(-1, \"0x\", \"H\"): ");
	xPrint(-1, "0x", "H");
	printLn();
	/* test printing hexadecimal number with no prefix and no postfix */
	sPrint("xPrint(0x12345678UL, NULL, NULL): ");
	xPrint(0x12345678UL, NULL, NULL);
	printLn();
	/* test printing float with 7 decimal places */
	sPrint("dPrint(-3.14159265354, 7): ");
	dPrint(-3.14159265354, 7);
	printLn();
	/* test printing float with no decimal place */
	sPrint("dPrint(2.718281828459, 0): ");
	dPrint(2.718281828459, 0);
	printLn();
	/* additional newline */
	printLn();
	/* print interval */
	delay(100);
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

/* END OF SER. */
