/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Analog to Digital Conversion 								             */
/**
 *	@file		adc.c
 *	@brief		This file contains the sample test program for ADC debugging.
 *	@details 	In this test, polling-based ADC reads and returns converted
 *				data through the function readAnalog. The function requires a
 *				specific analog channel entered manually every invocation,
 *				making polling-based ADC flexible when it comes to reading
 *				random analog channels. However, it is also a blocking function
 *				which does not permit any other processes to occur in between
 *				conversion (except interrupts), causing (minor) delay in the
 *				main process.
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
 *		Inputs		: AN0-AN7 (P50-P57)
 *		Outputs		: N/A
 *		Driver		: ADC
 *		Helper		: SER (UART), TBT
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <ADC/adc.h>
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
	initSER();
	setSERUsage(SER_APP);
	/* initialize port */
	portModeAnalog(PORT5);
	/* initialize ADC (default settings) */
	initADC(ADC_DEF_CT, ADC_DEF_ST, ADC_DEF_RES);

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
	sPrint("\t ");
	/* print readings from all successive channels (polling-based reading) */
	iPrint(readAnalog(PIN_AN0));
	sPrint(",\t ");
	iPrint(readAnalog(PIN_AN1));
	sPrint(",\t ");
	iPrint(readAnalog(PIN_AN2));
	sPrint(",\t ");
	iPrint(readAnalog(PIN_AN3));
	sPrint(",\t ");
	iPrint(readAnalog(PIN_AN4));
	sPrint(",\t ");
	iPrint(readAnalog(PIN_AN5));
	sPrint(",\t ");
	iPrint(readAnalog(PIN_AN6));
	sPrint(",\t ");
	iPrint(readAnalog(PIN_AN7));
	sPrint("\n");
	/* print delay */
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

/* END OF ADC. */
