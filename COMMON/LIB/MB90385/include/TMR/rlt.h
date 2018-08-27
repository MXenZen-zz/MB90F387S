/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* 16-bit Reload Timer									      			     */
/**
 *	@file		TMR/rlt.h
 * 	@brief		This file contains RLT types, external constants, and API functions.
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

#ifndef RLT_H
#define RLT_H

#include <IO/rlt0_io.h>
#include <IO/rlt1_io.h>
#include <TMR/gpt.h>
#include <MCU/isr.h>

/* ----------------------------------------------------------------------------
**	RLT Types.
*/

/**
 * 	@brief		Defined enumerated type for RLT channel.
 */
typedef enum {
	RLT_CH0 = 2021U,			/**< channel 0 */
	RLT_CH1 = 2223U				/**< channel 1 */
} T_rltChannel;

/* ----------------------------------------------------------------------------
**	RLT External Constants.
*/

/**
 * 	@var		PRIO_RLT0_ISR
 *	@brief		ISR interrupt level/priority of RLT for channel 0.
 *	@note		The ICR of RLT0 is shared with ADC. Unless ADC is not used,
 *				they must have the same ICR level at all times. If only RLT0
 *				is (or will be) used, then set the ICR level of RLT0 alone.
 */
extern const T_icrINTLevel PRIO_RLT0_ISR;

/**
 * 	@var		PRIO_RLT1_ISR
 *	@brief		ISR interrupt level/priority of RLT for channel 1.
 */
extern const T_icrINTLevel PRIO_RLT1_ISR;

/* ----------------------------------------------------------------------------
**	RLT API Functions.
*/

/**
 * 	@fn 		T_void initRLT(T_void)
 *	@brief 		Initialize RLT.
 * 	@param		.
 * 	@return		.
 */
extern T_void initRLT(T_void);

/**
 * 	@fn 		T_void setupReloadTimer(T_rltChannel, T_gptInterval, T_gptISRHook)
 *	@brief 		Initializes the reload timer module to its default operation
 *  			and the callback function for user-specific interrupt actions.
 * 	@param[in]	channel 	RLT channel.
 * 	@param[in]	interval	GPT interval duration in microseconds.
 * 	@param[in]	rltFunc		RLT interrupt user function.
 * 	@return		.
 *  @warning	Do not exceed beyond 131072 us interval.
 */
extern T_void setupReloadTimer(T_rltChannel channel,
	T_gptInterval interval, T_gptISRHook rltFunc);

/**
 * 	@fn 		T_void setupReloadTimerExtended(T_rltChannel, T_bit,
 * 					T_bit, T_bit, T_rltOpMode, T_rltTOTOutLevel)
 *	@brief 		Configures the advanced features of the reload timer module.
 * 	@pre		setupReloadTimer must be called first (or called already).
 * 	@param[in]	channel 	RLT channel.
 * 	@param[in]	isEventMode	RLT event mode option.
 * 	@param[in]	isOneShot	RLT one-shot mode option.
 * 	@param[in]	isPulseOut	RLT generate output waveform option.
 * 	@param[in]	trigLevel	RLT input trigger level.
 * 	@param[in]	outLevel	RLT type of output square wave to generate.
 * 	@return		.
 * 	@note		When setting up event mode, trigger input must be specified
 * 				while one-shot option can be set optionally. When setting up
 * 				output pulse (optional), output level must be specified.
 *  @remark		It is not necessary to call this function if reload timer is
 *  			set as "reload", operates at internal clock mode, no pulse
 *  			output, and no trigger input.
 */
extern T_void setupReloadTimerExtended(T_rltChannel channel, T_bit isEventMode,
	T_bit isOneShot, T_bit isPulseOut, T_rltOpMode trigLevel, T_rltTOTOutLevel outLevel);

/**
 * 	@fn 		T_void runReloadTimer(T_rltChannel)
 *	@brief 		Starts the reload timer if routine is present.
 * 	@pre		setupReloadTimer must be called first (or called already).
 * 				If necessary, call setupReloadTimerExtended ahead also.
 * 	@param[in]	channel 	RLT channel.
 * 	@return		.
 */
extern T_void runReloadTimer(T_rltChannel channel);

/**
 * 	@fn 		T_void haltReloadTimer(T_rltChannel)
 *	@brief 		Stops and disables the reload timer module.
 * 	@param[in]	channel 	RLT channel.
 * 	@return		.
 */
extern T_void haltReloadTimer(T_rltChannel channel);

/**
 * 	@fn 		T_void RLT0_IRQHandler(T_void)
 *	@brief 		Clears reload timer interrupt flag and executes reload timer
 *  			user interrupt routine function.
 *  @param		.
 *  @return		.
 */
#if USE_RLT0_ISR
#if NOSAVEREG_RLT0_ISR
NOSAVEREG
#endif
extern ISR(RLT0_IRQHandler);
#endif

/**
 * 	@fn 		T_void RLT1_IRQHandler(T_void)
 *	@brief 		Clears reload timer interrupt flag and executes reload timer
 *  			user interrupt routine function.
 *  @param		.
 *  @return		.
 */
#if USE_RLT1_ISR
#if NOSAVEREG_RLT1_ISR
NOSAVEREG
#endif
extern ISR(RLT1_IRQHandler);
#endif

#endif /* RLT_H. */
