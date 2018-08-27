/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Pulse												      			     */
/**
 *	@file		pul.c
 *	@brief		This file contains the sample test program for PUL debugging.
 *	@details	In this test, only a single pulse capture channel can be tested
 *				at a time since there's only one IOT shared among the channels.
 *				Testing and validating captured pulse requires several helper
 *				modules to participate such as the ADC, SER (UART), and PPG.
 *				First, the ADC will be used to vary the period of the generated
 *				pulse. The PPG will then generate the requested pulse period.
 *				Finally, the result (period vs actual) will be printed through
 *				SER (UART). Since both PPG and IOT have a maximum timer count
 *				resolution of 16 bits, any pulse period higher than 65536 us
 *				(other than a factor of 32, 64, and 128) might not be generated
 *				or captured correctly. Thus, changing the count clock division
 *				higher than 16 will greatly affect the granularity of the
 *				requested pulse period and the actual captured time duration.
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
 *		Inputs		: IN3 (P13), AN0 (P50)
 *		Outputs		: PPG23 (P16 & P17)
 *		Driver		: PUL (ICU & IOT)
 *		Helper		: ADC, SER (UART), PIN, PPG
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <ADC/adc.h>
#include <COM/ser.h>
#include <GPIO/pin.h>
#include <INT/pul.h>
#include <TMR/ppg.h>

/* ----------------------------------------------------------------------------
**	Test Flags.
*/

/**
 * 	@def		PUL_CLK_DIVISION
 *  @brief		Count clock division (power of 2).
 */
#define PUL_CLK_DIVISION		GPT_CLK_DIV_1		/* TODO:EXPERIMENT: Change count clock division GPT_CLK_DIV_N! */

/* ----------------------------------------------------------------------------
**	Test Macro.
*/

/**
 * 	@def		PUL_MAX_DURATION
 *  @brief		Maximum timer count or full duration (required internally).
 *  @warning	Do not edit!
 */
#define PUL_MAX_DURATION 		GetDWordGPTFullDuration(GPT_RES_16BIT, PUL_CLK_DIVISION, GPT_FCLK, GPT_USEC_IN_SEC)

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
	initADC(ADC_DEF_CT, ADC_DEF_ST, ADC_DEF_RES);
	initPPG();
	initSER();
	setSERUsage(SER_APP);
	/* initialize all pulse capture */
	initPUL();

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
	static T_dword generated, captured;

	/* read requested pulse period to generate */
	generated = ((T_dword)readAnalog(PIN_AN0) * PUL_MAX_DURATION) / ToBit(10UL);
	/* generate requested pulse period */
	pulseOutByPeriod(PPG_CH23, generated, generated);
	/* (re)initialize pulse capture channel */
	setupPULCapture(ICU_CH3, ICU_DETECT_FALL, PUL_MAX_DURATION);
	/* block-wait for pulse capture to finish */
	while (NOT(IsPulseCaptureFinished()));
	/* capture pulse duration */
	captured = pulseDetected();

	/* print generated pulse and captured time */
	sPrint("generated : captured = ");
	iPrint(generated);
	sPrint(" us : ");
	iPrint(captured);
	sPrint(" us ");
	/* print advanced if capture finished early */
	if (GT(generated, captured)) {
		sPrint("(");
		iPrint(generated - captured);
		sPrint(" us advanced)");
	}
	/* print delayed if capture finished late */
	if (LT(generated, captured)) {
		sPrint("(");
		iPrint(captured - generated);
		sPrint(" us delayed)");
	}
	printLn();
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

/* END OF PUL. */
