/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Proportional Integral Derivative Controller					             */
/**
 *	@file		pid.c
 *	@brief		This file contains the sample test program for PID debugging.
 *	@details 	In this test, the system will simulate simple PID control by
 *				means of a 10-bit ADC for the input or sensor, an 8-bit PWM
 *				for the output or actuator, and another 10-bit ADC for the
 *				feedback. Unlike DACs, PWM output is required to be a fairly
 *				stable voltage ranging from	ground (+0V) to logic high (+5V).
 *				Thus, a simple low-pass filter must be used between the PWM
 *				output (input to low-pass filter) and the feedback input
 *				(output from low-pass filter). However,	designing the right
 *				low-pass filter is not part of this test. Also, PWM frequency
 *				and duty cycle must be accounted for in designing the filter.
 *				This will greatly affect the three basic coefficients:
 *				proportional, integral, and derivative, which are varied in
 *				order to guarantee system stability and to get optimal response.
 *				Adjusting these coefficients are tedious and repetitive, and
 *				finding the right values might take a long time to accomplish.
 *				If there's a better alternative to this example, feel free to
 *				modify and try the alternative test. Both the setpoint and
 *				process value will be printed through the serial plotter for
 *				best viewed graphical comparison between the two.
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
 *		Inputs		: AN0 (P50), AN7 (P57)
 *		Outputs		: PPG3 (P17)
 *		Driver		: N/A
 *		Helper		: ADC, PPG-PWM (internal), SER (UART), TBT
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <ADC/adc.h>
#include <COM/ser.h>
#include <PWM/pwm.h>
#include <TMR/tbt.h>

#include <PID/pid.h>

/* ----------------------------------------------------------------------------
**	Test Variables.
*/

/**
 *	@var		kfTest
 *	@brief		PID test variable requiring continuously modulated control.
 */
static T_pid pidTest;

/**
 *	@var		setPoint
 *	@brief		Target value for the process value of a system.
 *	@var		processValue
 *	@brief		Current measured value of the process being monitored or controlled.
 *	@var		controlValue
 *	@brief		Input to the process which is the output from the PID controller.
 */
static T_float32 setPoint, processValue, controlValue;

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
	memset(&pidTest, NULL, SzBytes_(pidTest));
	initPID(&pidTest, PID_DEF_KP, PID_DEF_KI, PID_DEF_KD,
		(T_float32)ToBit(0U), (T_float32)ToBit(8U));		/* TODO:EXPERIMENT: Vary the KP, KI, and KD to optimize PID control! */
	/* initialize analog pin */
	pinModeAnalog(PIN50);
	pinModeAnalog(PIN57);
	/* initialize helper modules */
	initADC(ADC_DEF_CT, ADC_DEF_ST, ADC_DEF_RES);
	initPPG();
	initTBT();
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
	/* read setpoint from ADC potentiometer / volume control */
	setPoint = readAnalog(PIN50);
	/* read process value from ADC */
	processValue = readAnalog(PIN57);
	/* determine control value by computing PID */
	controlValue = computePID(&pidTest, setPoint, processValue);
	/* update PWM duty cycle from control value */
	writeAnalog(PWM_CH3, controlValue, PWM_FREQ_3k9);

	/* print result */
	sPrint("setPoint : processValue = ");
	iPrint(setPoint);
	sPrint(" : ");
	iPrint(processValue);
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

/* END OF PID. */
