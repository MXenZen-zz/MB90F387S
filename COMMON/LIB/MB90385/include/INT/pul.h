/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Pulse												      			     */
/**
 *	@file		INT/pul.h
 * 	@brief		This file contains PUL external constants, macro functions,
 * 				and API functions.
**/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *	This file is part of LibMB90385 (Software Library for MB90385 Series).
 *
 *	Copyright (C) 2015-2017 Xeno Xerxes Masong (xxmasong@gmail.com)
 *
 *	LibMB90385 does not guarantee that it shall fulfill its task under all
 *	circumstances. Thus, the author/developer shall not be held liable for
 *	any damages that might be incurred by the device using LibMB90385, or
 *	for any reason whatsoever.
 *
 *	LibMB90385 is free software: you can redistribute it and/or modify it
 *	under the terms of the GNU General Public License as published by the
 *	Free Software Foundation, either version 3 of the License, or (at your
 *	option) any later version.
 *
 *	LibMB90385 is distributed in the hope that it will be useful, but WITHOUT
 *	ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 *	FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 *	for more details.
 *
 *	You should have received a copy of the GNU General Public License along
 *	with LibMB90385. If not, see <https://www.gnu.org/licenses/>.
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#ifndef PUL_H
#define PUL_H

#include <INT/icu.h>
#include <TMR/iot.h>

/* ----------------------------------------------------------------------------
**	PUL External Constants.
*/

/**
 * 	@var		pPULCaptureStarted
 * 	@brief		Read-only access to pulse capture data start.
 */
extern volatile T_bit const * const pPULCaptureStarted;

/**
 * 	@var		pPULCaptureEnded
 * 	@brief		Read-only access to pulse capture data end.
 */
extern volatile T_bit const * const pPULCaptureEnded;

/**
 * 	@var		pPULCaptureExpired
 * 	@brief		Read-only access to pulse capture data expire.
 */
extern volatile T_bit const * const pPULCaptureExpired;

/**
 * 	@var		pPULCaptureLocked
 * 	@brief		Read-only access to pulse capture data lock.
 */
extern volatile T_bit const * const pPULCaptureLocked;

/* ----------------------------------------------------------------------------
**	PUL Macro Functions.
*/

/**
 * 	@def 		IsPulseCaptureLocked
 * 	@brief		Checks whether other channel is currently using the input
 * 				capture unit or input capture is done acquiring duration.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsPulseCaptureLocked()			IS(*pPULCaptureLocked)

/**
 * 	@def 		IsPulseCaptureExpired
 * 	@brief		Checks whether recent input capture did not succeed acquiring
 * 				duration (also implies input capture is not complete).
 * 	@param		.
 * 	@return		boolean.
 */
#define IsPulseCaptureExpired()			IS(*pPULCaptureExpired)

/**
 * 	@def 		IsPulseCaptureCompleted
 * 	@brief		Checks whether capture was started and ended or succeeded
 * 				acquiring duration (also implies input capture is complete).
 * 	@param		.
 * 	@return		boolean.
 */
#define IsPulseCaptureCompleted() \
	(IS(*pPULCaptureStarted) && IS(*pPULCaptureEnded))

/**
 * 	@def 		IsPulseCaptureFinished
 * 	@brief		Checks whether capture is done acquiring pulse duration,
 * 				whether successful or not and capture lock is released.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsPulseCaptureFinished() \
	(NOT(*pPULCaptureLocked) && ((IS(*pPULCaptureStarted) && IS(*pPULCaptureEnded)) \
		|| IS(*pPULCaptureExpired)))

/* ----------------------------------------------------------------------------
**	PUL API Functions.
*/

/**
 * 	@fn 		T_void initPUL(T_void)
 *	@brief 		Initialize PUL.
 * 	@attention	This will also initialize IOT and all channels of ICU.
 * 	@param		.
 * 	@return		.
 */
extern T_void initPUL(T_void);

/**
 * 	@fn			T_void setupPULCapture(T_icuChannel, T_icuDetectEdge, T_gptInterval)
 * 	@brief		Sets up pulse capture channel for capturing pulse duration,
 * 				then starts and locks pulse capture module to avoid switching
 * 				channels while capturing takes place.
 * 	@pre		initPUL must be called first (or called already).
 * 	@param[in]	channel		ICU channel.
 * 	@param[in]	trigger		ICU edge trigger (rising or falling only).
 * 	@param[in]	interval	GPT maximum wait or capture duration in microseconds.
 * 	@return		.
 * 	@note		Only one pulse capture channel can be set up at a time. The
 * 				channel will be locked since there's only one IO timer and
 * 				will be released after recording pulse immediately.
 *  @note		This function may probably capture errors in shorter pulses.
 *  			Works on pulses from 10 microseconds to 500 milliseconds, with
 *  			the highest resolution obtained in shorter intervals.
 * 	@warning 	Do not use IOT and ICU channel currently used in pulse capture.
 * 				Do not execute this function if IOT setting is modified outside
 * 				pulse capture usage. Otherwise, setupPULCapture must be executed
 * 				again to reconfigure IOT correctly for pulse capturing.
 * 	@see		Use pulseDetected function to determine the captured pulse
 * 				duration and/or whether recent pulse capture is valid or not.
 */
extern T_void setupPULCapture(T_icuChannel channel,
	T_icuDetectEdge trigger, T_gptInterval interval);

/**
 * 	@fn			T_gptInterval pulseDetected(T_void)
 * 	@brief		Returns the duration if pulse has settled down (valid duration) or
 * 				timer expired before finishing reading pulse (invalid duration).
 * 	@pre		initPUL must be called already and pulse capture channel
 * 				must be set up through setupPULCapture to get correct readings.
 * 	@param		.
 * 	@return		duration of pulse read.
 * 	@note		This function returns (-1) if pulse capture is not yet done,
 * 				0 if pulse capture has expired, or other than the
 * 				mentioned which implies pulse capture was completed and
 * 			 	valid duration is expected.
 */
extern T_gptInterval pulseDetected(T_void);

#endif /* PUL_H. */
