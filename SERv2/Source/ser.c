/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Universal Asynchronous Receiver/Transmitter							     */
/**
 *	@file		ser.c
 *	@brief		This file contains the sample test program for SER debugging.
 *	@details	In this test (loopback), the user must send a string or text in
 *				the serial terminal transmitted at once. The text message will
 *				be received using basic serial read function then will be sent
 *				(printed back) to the serial terminal using basic serial write
 *				function. A serial break character specified by the user may
 *				force the serial terminal to print newline characters and split
 *				the string to print.
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
**	Test Flags.
*/

/**
 * 	@def		SER_BREAK_CH
 *  @brief		Break character for UART serial loopback.
 */
#define SER_BREAK_CH			('\\')		/* TODO: Change break character! */

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
	T_char message[64U];
	T_uint8 count = 0U;

	/* check if reception count is getting bigger */
	while (GT(countSERReceived(), count)) {
		/* update reception count */
		count = countSERReceived();
		/* reception count delay */
		delay(1);
	}
	/* check if reception count is sufficient */
	if (IS(count)) {
		/* receive the message (basic serial read) first, */
		/* then transmit back the message (basic serial write) */
		(T_void)writeSERBytes((T_uint8*)message,
			readSERBytes((T_uint8*)message, SzIndices_(message), SER_BREAK_CH, TRUE));
		/* print carriage return and line feed */
		(T_void)requestSERTransmit('\r');
		(T_void)requestSERTransmit('\n');
	}
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
