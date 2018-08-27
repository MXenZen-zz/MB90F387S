/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Timebase Timer												             */
/**
 *	@file		TMR/tbt.h
 * 	@brief		This file contains TBT external constants, getters,
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

#ifndef TBT_H
#define TBT_H

#include <IO/tbt_io.h>
#include <TMR/gpt.h>
#include <MCU/isr.h>

/* ----------------------------------------------------------------------------
**	TBT External Constants.
*/

/**
 * 	@var		PRIO_TBT_ISR
 *	@brief		ISR interrupt level/priority of TBT.
 *	@note		The ICR of TBT is shared with EXI RX (CAN Wake-up). Unless
 *				EXI RX (CAN Wake-up) is not used, they must have the same
 *				ICR level at all times. If only TBT is (or will be) used,
 *				then set the ICR level of TBT alone.
 */
extern const T_icrINTLevel PRIO_TBT_ISR;

/**
 * 	@var		pTBTCount
 *	@brief		Read-only access to time near-millisecond tick count.
 */
extern volatile T_gptCount const * const pTBTCount;

/* ----------------------------------------------------------------------------
**	TBT Getters.
*/

/**
 *	@def 		GetDWordTBTTicks
 *	@brief 		Timebase near-millisecond ticks getter.
 * 	@param		.
 * 	@return		ticks (+ 24 us / ms) (dword).
 */
#define GetDWordTBTTicks()				(*pTBTCount)

/**
 *	@def 		GetDWordTBTMillis
 *	@brief 		Timebase millisecond-count getter.
 * 	@param		.
 * 	@return		milliseconds (dword).
 */
#define GetDWordTBTMillis()				((*pTBTCount * 128UL) / (125UL))

/**
 *	@def 		GetDWordTBTSec
 *	@brief 		Timebase second-count getter.
 * 	@param		.
 * 	@return		seconds (dword).
 */
#define GetDWordTBTSec()				((*pTBTCount * 128UL) / (125UL * 1000UL))

/**
 *	@def 		GetDWordTBTMins
 *	@brief 		Timebase minute-count getter.
 * 	@param		.
 * 	@return		minutes (dword).
 */
#define GetDWordTBTMins()				((*pTBTCount * 128UL) / (125UL * 60000UL))

/**
 *	@def 		GetDWordTBTTicksDiff
 *	@brief 		Timecount difference between previous ticks recorded
 *  			and the current ticks upon reading.
 * 	@param		PREV	Previous ticks (dword).
 * 	@return		ticks difference near-milliseconds (+ 24us / ms) (dword).
 */
#define GetDWordTBTTicksDiff(PREV)		(*pTBTCount - (PREV))

/* ----------------------------------------------------------------------------
**	TBT API Functions.
*/

/**
 * 	@fn 		T_void initTBT(T_void)
 *	@brief 		Initializes and starts timebase timer.
 * 	@attention	TBT is initialized with near-millisecond interval clock.
 * 	@param		.
 * 	@return		.
 */
extern T_void initTBT(T_void);


/**
 * 	@fn 		T_void delay(T_gptCount)
 *	@brief 		Near-millisecond delay function.
 * 	@pre		initTBT must be called first (or called already).
 * 	@attention	Do not call this function inside ISRs or schedulers!
 * 	@param[in]	milliseconds 	Delay time.
 * 	@return		.
 *  @note		The delay is based on timebase timer whose interrupt activates
 *  			per 1024 ms. The delay count is calculated to eliminate the
 *  			24 us delay. The longer the delay, the earlier it finishes.
 */
extern T_void delay(T_gptCount milliseconds);

/**
 * 	@fn 		T_void TBT_IRQHandler(T_void)
 * 	@brief		Clears overflow interrupt, increments timecount, and decrements
 *  			delay count (if available).
 *  @param		.
 *  @return		.
 */
#if USE_TBT_ISR
#if NOSAVEREG_TBT_ISR
NOSAVEREG
#endif
extern ISR(TBT_IRQHandler);
#endif

#endif /* TBT_H. */
