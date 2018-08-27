/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Microcontroller					      			   			   		     */
/**
 *	@file		MCU/mcu.h
 *	@brief		This file contains MCU API functions.
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

#ifndef MCU_H
#define MCU_H

#include <IO/amd_io.h>
#include <IO/clk_io.h>
#include <IO/lpm_io.h>
#include <IO/romm_io.h>

/* ----------------------------------------------------------------------------
**	MCU API Functions.
*/

/**
 * 	@fn 		T_void initMCU(T_void)
 *	@brief 		Initialize MCU.
 * 	@param		.
 * 	@return		.
 * 	@note		Initialization includes ROM mirroring, address match detection,
 *  			system clock, and IRQ levels.
 */
extern T_void initMCU(T_void);

/**
 * 	@fn 		T_void initClock(T_void)
 *	@brief 		Initialize clock compatible with bootloader specification.
 * 	@param		.
 * 	@return		.
 */
extern T_void initClock(T_void);

/**
 * 	@fn 		T_void resetMCU(T_void)
 *	@brief 		Generates software internal reset at 3 clock cycles.
 * 	@param		.
 * 	@return		.
 */
extern T_void resetMCU(T_void);

/**
 * 	@fn 		T_void sleepMCU(T_void)
 *	@brief 		Transit to sleep mode.
 * 	@param		.
 * 	@return		.
 *  @note		The sleep mode stops the operating clock to the CPU during
 *  			an operation in each clock mode. The CPU stops and the
 *  			resources continue to operate.
 */
extern T_void sleepMCU(T_void);

/**
 * 	@fn 		T_void tbtModeMCU(T_bit pinHeld)
 *	@brief 		Transit to timebase timer mode.
 * 	@param[in]	pinHeld		Hold pin state (boolean, byte).
 * 	@return		.
 *  @note		The timebase timer mode operates only the oscillation clock
 *  			(HCLK), subclock (SCLK), timebase timer, and watch timer.
 *  			Resources other than the timebase timer and watch timer stops.
 */
extern T_void tbtModeMCU(T_bit pinHeld);

/**
 * 	@fn 		T_void stopMCU(T_bit pinHeld)
 *	@brief 		Transit to stop mode.
 * 	@param[in]	pinHeld		Hold pin state (boolean, byte).
 * 	@return		.
 *  @note		The stop mode stops the oscillation clock (HCLK) and subclock
 *  			(SCLK) during operation in each clock mode. Data can be held
 *  			with the minimum power consumption.
 */
extern T_void stopMCU(T_bit pinHeld);

/**
 * 	@fn 		T_void __wait_us(T_uint32)
 *	@brief 		Near-microsecond delay function.
 * 	@attention	This function is intended for microsecond-level delays only.
 * 				If the delay time is greater than 100 milliseconds, or if
 * 				the delay does not require microsecond-level of accuracy, better
 * 				use the delay function instead.
 * 	@param[in]	microseconds 	Delay time in microseconds. Numbers only!
 * 	@return		.
 * 	@note		The minimum delay time is 6 microseconds. Delays shorter than
 * 				the mentioned will yield around 4 - 5 microseconds. This
 * 				function does not have full microsecond correspondence but
 *  			just a closer one. However, the longer the delay, the more
 *  			it deviates from the intended microsecond delay time.
 *  @note		The delay is based on execution clock cycles of each inline
 *  			assembly instructions with considerations on looping. Some
 *  			assembly instructions' execution clock cycles are internally
 *  			compensated depending on the accessing, addressing or execution.
 *  			This makes this function's exact delay capabilities challenging
 *  			to compute which may result in longer or even shorter delays.
 * 	@warning	Do not call this function inside ISRs or schedulers! Inasmuch
 * 				as possible, let no ISR execute while this delay function is
 * 				running. Note that once this function executes, it cannot be
 * 				aborted. Thus, any interruptions while this function is running
 * 				will cause an even longer delay.
 */
extern T_void FAR __wait_us(T_uint32 microseconds);

#endif /* MCU_H. */
