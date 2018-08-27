/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Idle																  	     */
/**
 *	@file		OS/idle.h
 *	@brief		This file contains idle API function for scheduler.
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

#ifndef IDLE_H
#define IDLE_H

#include <LIB/bitmanip.h>

/* ----------------------------------------------------------------------------
**	Macro Functions.
*/

/**
 *	@def 		OSIdleTask
 *	@brief 		Executes idle task routine.
 *	@param		.
 *	@return		.
 */
#define OSIdleTask()		(idleTaskRoutine())

/* ----------------------------------------------------------------------------
**	API Functions.
*/

/**
 *	@fn 		T_void idleTaskRoutine(T_void)
 *	@brief 		Idle task routine for scheduler.
 *	@details	The idle task routine is the default function which executes
 *				whenever there's no ready task to execute. It does not have
 *				priority nor period of execution but only executes after the
 *				scheduler wasn't able to find any ready task as of the moment.
 *  @attention	Only the scheduler has the right to call this function!
 *	@param		.
 *	@return		.
 *	@warning	Do not implement any scheduling inside this function! The idle
 *				task should not consumes more CPU time per execution cycle.
 *				Another workaround is to reduce the processes inside the
 *				function to consume less time.
 */
extern T_void idleTaskRoutine(T_void);

#endif /* IDLE_H. */
