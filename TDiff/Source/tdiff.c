/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Time Difference								               		   	     */
/**
 *	@file		tdiff.c
 *	@brief		This file contains the sample test program for time difference
 *				measurement.
 *	@details	In this test, the IOT will be used to measure the elapsed or
 *				execution time of a certain process, i.e, the near-microsecond
 *				delay function. This delay function is not accurate at very
 *				fast delay times and very slow delay times. Thus, this test will
 *				be useful in correcting near-microsecond delays to make it more
 *				accurate as required. Since IOT has a maximum timer count
 *				resolution of 16 bits, any duration higher than 65536 us might
 *				not be measured accurately. Thus, having slower delays will
 *				greatly affect the granularity of the computed time difference.
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
 *		Outputs		: N/A
 *		Driver		: IOT (inline assembly)
 *		Helper		: SER (UART), TBT
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <COM/ser.h>
#include <MCU/mcu.h>
#include <TMR/iot.h>
#include <TMR/tbt.h>

/* ----------------------------------------------------------------------------
**	Test Flags.
*/

/**
 * 	@def		TDIFF_DELAY
 *  @brief		Near-microsecond delay time to test.
 */
#define TDIFF_DELAY		(1000UL)		/* TODO:EXPERIMENT: Change delay time (524288 us MAX)! */

/* ----------------------------------------------------------------------------
**	Test Variables.
*/

/**
 *  @var		time
 *  @brief		Time elapsed in microseconds since delay started.
 */
static T_float32 time;

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

	/* initialize timer */
	initIOT();

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
	__DI();
#if LEQ(TDIFF_DELAY, 4096UL)
	/* start timer with 16 MHz count clock */
	__asm("	MOV		I:_IO_TCCS, #8 ");
#elif LEQ(TDIFF_DELAY, 8192UL)
	/* start timer with 8 MHz count clock */
	__asm("	MOV		I:_IO_TCCS, #9 ");
#elif LEQ(TDIFF_DELAY, 16384UL)
	/* start timer with 4 MHz count clock */
	__asm("	MOV		I:_IO_TCCS, #10 ");
#elif LEQ(TDIFF_DELAY, 32768UL)
	/* start timer with 2 MHz count clock */
	__asm("	MOV		I:_IO_TCCS, #11 ");
#elif LEQ(TDIFF_DELAY, 65536UL)
	/* start timer with 1 MHz count clock */
	__asm("	MOV		I:_IO_TCCS, #12 ");
#elif LEQ(TDIFF_DELAY, 131072UL)
	/* start timer with 500 kHz count clock */
	__asm("	MOV		I:_IO_TCCS, #13 ");
#elif LEQ(TDIFF_DELAY, 262144UL)
	/* start timer with 250 kHz count clock */
	__asm("	MOV		I:_IO_TCCS, #14 ");
#else
	/* start timer with 125 kHz count clock */
	__asm("	MOV		I:_IO_TCCS, #15 ");
#endif
/* --------------------------- START OF TEST CODE --------------------------- */

	__wait_us(TDIFF_DELAY);

/* ---------------------------- END OF TEST CODE ---------------------------- */
	/* stop timer */
	__asm("	MOV		I:_IO_TCCS, #32 ");
#if LEQ(TDIFF_DELAY, 4096UL)
	/* compute time from 16 MHz count clock */
	time = 1.0F * ((T_float32)IO_TCDT - 5.0F) / 16.0F;
#elif LEQ(TDIFF_DELAY, 8192UL)
	/* compute time from 8 MHz count clock */
	time = 2.0F * ((T_float32)IO_TCDT - 5.0F) / 16.0F;
#elif LEQ(TDIFF_DELAY, 16384UL)
	/* compute time from 4 MHz count clock */
	time = 4.0F * ((T_float32)IO_TCDT - 5.0F) / 16.0F;
#elif LEQ(TDIFF_DELAY, 32768UL)
	/* compute time from 2 MHz count clock */
	time = 8.0F * ((T_float32)IO_TCDT - 5.0F) / 16.0F;
#elif LEQ(TDIFF_DELAY, 65536UL)
	/* compute time from 1 MHz count clock */
	time = 16.0F * ((T_float32)IO_TCDT - 5.0F) / 16.0F;
#elif LEQ(TDIFF_DELAY, 131072UL)
	/* compute time from 500 kHz count clock */
	time = 32.0F * ((T_float32)IO_TCDT - 5.0F) / 16.0F;
#elif LEQ(TDIFF_DELAY, 262144UL)
	/* compute time from 250 kHz count clock */
	time = 64.0F * ((T_float32)IO_TCDT - 5.0F) / 16.0F;
#else
	/* compute time from 125 kHz count clock */
	time = 128.0F * ((T_float32)IO_TCDT - 5.0F) / 16.0F;
#endif
	__EI();

	/* print time elapsed */
	dPrint(time, 4U);
	printLn();
	/* next measurement delay */
	delay(100UL);
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

/* END OF TDIFF. */
