/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Kalman Filter				 								             */
/**
 *	@file		klm.c
 *	@brief		This file contains the sample test program for KLM debugging.
 *	@details 	In this test, the system will generate a noisy data from an
 *				ADC source (potentiometer / volume) to demonstrate Kalman
 *				filtering of the data thereof. The ADC source, however, does
 *				not exhibit "noisy" data enough. Thus, a +/-10 random peak-to-
 *				peak value is added to the read ADC value. The Kalman filtering
 *				parameters (process and measurement noise) can be adjusted to
 *				suit balance between response time and smoothing output. The
 *				original unfiltered and the Kalman filtered result will be
 *				printed through the serial plotter for best viewed graphical
 *				comparison between the two.
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
 *		Inputs		: AN0 (P50)
 *		Outputs		: N/A
 *		Driver		: N/A
 *		Helper		: ADC, SER (UART), TBT
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <ADC/adc.h>
#include <COM/ser.h>
#include <TMR/tbt.h>

#include <KLM/klm.h>
#include <stdlib.h>

/* ----------------------------------------------------------------------------
**	Test Variables.
*/

/**
 *	@var		kfTest
 *	@brief		Kalman filter test variable.
 */
static T_kalman kfTest;

/**
 *	@var		unfiltered
 *	@brief		Unfiltered noisy original data.
 *	@var		filtered
 *	@brief		Kalman-filtered result.
 */
static T_float32 unfiltered, filtered;

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

	/* initialize variables */
	memset(&kfTest, NULL, SzBytes_(kfTest));
	initKalman(&kfTest, KLM_DEF_PROC_NOISE, KLM_DEF_MEA_NOISE);			/* TODO:EXPERIMENT: Change the PROC_NOISE and MEA_NOISE! */
	/* initialize analog pin */
	pinModeAnalog(PIN50);
	/* initialize helper modules */
	initADC(ADC_DEF_CT, ADC_DEF_ST, ADC_DEF_RES);
	initTBT();
	initSER();
	setSERUsage(SER_APP);
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
	/* get unfiltered noisy data */
	unfiltered = readAnalog(PIN50) + (T_float32)(((rand() - rand()) / 100) % 10);
	/* apply kalman filter to unfiltered data */
	filtered = computeKalman(&kfTest, unfiltered);

	/* print result */
	sPrint("unfiltered : filtered = ");
	iPrint(unfiltered);
	sPrint(" : ");
	iPrint(filtered);
	printLn();
	/* next step delay */
	delay(10U);
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

/* END OF KLM. */
