/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Timer																     */
/**
 *	@file		OS/timer.h
 *	@brief		This file contains timer API function for task.
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

#ifndef TIMER_H
#define TIMER_H

#include <LIB/bitmanip.h>

/* ----------------------------------------------------------------------------
**	Macro Functions.
*/

/**
 *	@def 		GetDWordSchedulerMSTicks
 *	@brief 		Elapsed time / ticks in near-milliseconds.
 *	@param		.
 *	@return		time in near-milliseconds (dword).
 */
#define GetDWordSchedulerMSTicks()		(OSTimerAPI())

/* ----------------------------------------------------------------------------
**	API Functions.
*/

/**
 *	@fn 		T_dword OSTimerAPI(T_void)
 *	@brief 		An API returning the elapsed time in near-milliseconds (around
 *				1 tick / ms) since the microcontroller timer is started.
 *	@param		.
 *	@return		time in milliseconds (dword).
 */
extern T_dword OSTimerAPI(T_void);

#endif /* TIMER_H. */
