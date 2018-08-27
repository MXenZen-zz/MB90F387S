/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Input / Output Timer									      			     */
/**
 *	@file		TMR/iot.h
 * 	@brief		This file contains IOT external constants and API functions.
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

#ifndef IOT_H
#define IOT_H

#include <IO/iot_io.h>
#include <TMR/gpt.h>
#include <MCU/isr.h>

/* ----------------------------------------------------------------------------
**	IOT External Constants.
*/

/**
 * 	@var		PRIO_IOT_ISR
 *	@brief		ISR interrupt level/priority of IOT.
 */
extern const T_icrINTLevel PRIO_IOT_ISR;

/* ----------------------------------------------------------------------------
**	IOT API Functions.
*/

/**
 * 	@fn 		T_void initIOT(T_void)
 *	@brief 		Initialize IOT.
 * 	@param		.
 * 	@return		.
 */
extern T_void initIOT(T_void);

/**
 * 	@fn 		T_void setupIOTimer(T_gptInterval, T_gptISRHook)
 *	@brief 		Initializes the IO timer module and the callback function
 *  			for user-specific interrupt actions.
 * 	@param[in]	interval	GPT interval duration in microseconds.
 * 	@param[in]	iotFunc		IOT interrupt user function.
 * 	@return		.
 *  @note		Do not exceed beyond 524288 us interval.
 */
extern T_void setupIOTimer(T_gptInterval interval, T_gptISRHook iotFunc);

/**
 * 	@fn 		T_iotCntClk setupIOTimeCapture(T_gptInterval, T_gptISRHook)
 *	@brief 		Initializes the IO timer module and the callback function
 *  			for pulse duration/input capture.
 * 	@param[in]	interval	GPT interval duration in microseconds.
 * 	@param[in]	iotFunc		IOT interrupt user function.
 * 	@return		count clock.
 *  @note		Do not exceed beyond 524288 us interval.
 */
extern T_iotCntClk setupIOTimeCapture(T_gptInterval interval, T_gptISRHook iotFunc);

/**
 * 	@fn 		T_void runIOTimer(T_void)
 *	@brief 		Starts the IO timer if routine is present.
 * 	@pre		setupIOTimer must be called first (or called already).
 * 	@param		.
 * 	@return		.
 */
extern T_void runIOTimer(T_void);

/**
 * 	@fn 		T_void haltIOTimer(T_void)
 *	@brief 		Stops and disables the IO timer module.
 * 	@param		.
 * 	@return		.
 */
extern T_void haltIOTimer(T_void);

/**
 * 	@fn 		T_void IOT_IRQHandler(T_void)
 *	@brief 		Clears IO timer interrupt flag and executes user interrupt
 *  			routine function.
 *  @param		.
 *  @return		.
 */
#if USE_IOT_ISR
#if NOSAVEREG_IOT_ISR
NOSAVEREG
#endif
extern ISR(IOT_IRQHandler);
#endif

#endif /* IOT_H. */
