/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Input Capture Unit									      			     */
/**
 *	@file		INT/icu.h
 *	@brief		This file contains ICU types, external constants, and API functions.
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

#ifndef ICU_H
#define ICU_H

#include <IO/icu_io.h>
#include <MCU/isr.h>

/* ----------------------------------------------------------------------------
**	ICU Types.
*/

/**
 *	@brief 		Callback type for ICU interrupt user routine functions.
 */
typedef T_void (*T_icuISRHook)(T_void);

/**
 * 	@brief		Defined enumerated type for ICU channel.
 */
typedef enum {
	ICU_CH0 = 10U,				/**< channel 0 */
	ICU_CH1 = 11U,				/**< channel 1 */
	ICU_CH2 = 12U,				/**< channel 2 */
	ICU_CH3 = 13U				/**< channel 3 */
} T_icuChannel;

/* ----------------------------------------------------------------------------
**	ICU External Constants.
*/

/**
 * 	@var		PRIO_ICU0_ISR
 *	@brief		ISR interrupt level/priority of ICU for channel 0.
 *	@note		The ICR of ICU0 is shared with EXI45. Unless EXI45 is not used,
 *				they must have the same ICR level at all times. If only ICU0
 *				is (or will be) used, then set the ICR level of ICU0 alone.
 */
extern const T_icrINTLevel PRIO_ICU0_ISR;

/**
 * 	@var		PRIO_ICU1_ISR
 *	@brief		ISR interrupt level/priority of ICU for channel 1.
 *	@note		The ICR of ICU1 is shared with PPG23. Unless PPG23 is not used,
 *				they must have the same ICR level at all times. If only ICU1
 *				is (or will be) used, then set the ICR level of ICU1 alone.
 */
extern const T_icrINTLevel PRIO_ICU1_ISR;

/**
 * 	@var		PRIO_ICU23_ISR
 *	@brief		ISR interrupt level/priority of ICU for channels 2 and 3.
 */
extern const T_icrINTLevel PRIO_ICU23_ISR;

/* ----------------------------------------------------------------------------
**	ICU API Functions.
*/

/**
 * 	@fn 		T_void initICU(T_void)
 *	@brief 		Initialize ICU.
 * 	@param		.
 * 	@return		.
 */
extern T_void initICU(T_void);

/**
 * 	@fn 		T_void attachICU(T_icuChannel, T_icuDetectEdge, T_icuISRHook)
 *	@brief 		Initializes an input capture module and attaches a function
 *  			for user-specific interrupt actions when interrupt occurs.
 * 	@param[in]	channel		ICU channel.
 * 	@param[in]	edge		ICU detection edge.
 * 	@param[in]	icuFunc		ICU interrupt user function.
 * 	@return		.
 */
extern T_void attachICU(T_icuChannel channel, T_icuDetectEdge edge, T_icuISRHook icuFunc);

/**
 * 	@fn 		T_void detachICU(T_icuChannel)
 *	@brief 		Disables an input capture module and detaches a function
 *  			for user-specific interrupt actions.
 * 	@param[in]	channel		ICU channel.
 * 	@return		.
 */
extern T_void detachICU(T_icuChannel channel);

/**
 * 	@fn 		T_void ICU0_IRQHandler(T_void)
 *	@brief 		Clears input capture flag and executes capture
 *  			interrupt user routine function.
 *  @param		.
 *  @return		.
 */
#if USE_ICU0_ISR
#if NOSAVEREG_ICU0_ISR
NOSAVEREG
#endif
extern ISR(ICU0_IRQHandler);
#endif

/**
 * 	@fn 		T_void ICU1_IRQHandler(T_void)
 *	@brief 		Clears input capture flag and executes capture
 *  			interrupt user routine function.
 *  @param		.
 *  @return		.
 */
#if USE_ICU1_ISR
#if NOSAVEREG_ICU1_ISR
NOSAVEREG
#endif
extern ISR(ICU1_IRQHandler);
#endif

/**
 * 	@fn 		T_void ICU23_IRQHandler(T_void)
 *	@brief 		Clears input capture flag and executes capture
 *  			interrupt user routine function.
 *  @param		.
 *  @return		.
 */
#if (USE_ICU2_ISR || USE_ICU3_ISR)
#if NOSAVEREG_ICU23_ISR
NOSAVEREG
#endif
extern ISR(ICU23_IRQHandler);
#endif

#endif /* ICU_H. */
