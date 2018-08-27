/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Programmable Pulse Generator			 						             */
/**
 *	@file		ppg.c
 *	@brief		This file contains the sample test program for PPG debugging.
 *	@details	In this test, two 16-bit dual PPG channels will generate the
 *				same pulse but differ on how each channels are initialized.
 *				The first dual channel is initialized based on period's mark
 *				and space while the second dual channel is initialized based
 *				on frequency and duty cycle. Both period and frequency directly
 *				corresponds each other while mark and space are computed to
 *				match the desired duty cycle. Since PPG only have 1, 2, 4, 8,
 *				16, and 2048 (512/HCLK) divided clocks and a maximum timer
 *				count resolution of 16 bits (for dual PPG channels), any
 *				interval higher than 65536 us (other than a factor of 2048)
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
 *		Outputs		: PPG0-PPG1 (P14-P15), PPG2-PPG3 (P16-P17)
 *		Driver		: PPG (Output-Only)
 *		Helper		: N/A
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <TMR/ppg.h>

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

	/* initialize timer */
	initPPG();
	/* mark  = period * duty cycle = (1 ms) * (50 % D.C.) = 500 us */
	/* space = period * (1 - duty cycle) = (1 ms) * ([100 - 50] % D.C.) = 500 us */
	pulseOutByPeriod(PPG_CH01, 500UL, 500UL);
	/* period = mark + space = 500 us + 500 us = 1 ms */
	/* frequency = 1 / period = 1 / 1 ms = 1 kHz */
	/* duty cycle = mark / period = 500 us / 1 ms = 50 % D.C. */
	pulseOutByFrequency(PPG_CH23, 1000UL, ToBit(8UL)/2UL);

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
