/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Watchdog Timer		 									   		         */
/**
 *	@file		MCU/wdt.h
 *	@brief		This file contains WDT API functions.
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

#ifndef WDT_H
#define WDT_H

#include <IO/wdt_io.h>

/* ----------------------------------------------------------------------------
**	WDT API Functions.
*/

/**
 * 	@fn 		T_void initWDT(T_void)
 *	@brief 		Initializes and starts watchdog timer.
 * 	@param		.
 * 	@return		.
 *  @note		The set interval for watchdog timer using timebase timer
 *  			as its clock is around 400 ms. This time is very short but
 *  			this is the longest interval option. Strategic clearing of
 *  			the watchdog is a must. If the watchdog is intended to cause
 *  			a system reset on a much shorter interval, then initialize it
 *  			manually and don't use this function. The acc_WatchdogEnable
 *  			function is called before starting the watchdog timer so that
 *  			Accemic MDE can update the watchdog timer automatically if the
 *  			normal application program flow is interrupted by Accemic MDE
 *  			(e.g. breakpoint entered, stop command, single stepping).
 */
extern T_void initWDT(T_void);

/**
 * 	@fn 		T_void kickWDT(T_void)
 *	@brief 		Clears the watchdog timer preventing system reset.
 * 	@attention	Call this function so often, lesser than the reset interval!
 * 	@param		.
 * 	@return		.
 */
extern T_void kickWDT(T_void);

#endif /* WDT_H. */
