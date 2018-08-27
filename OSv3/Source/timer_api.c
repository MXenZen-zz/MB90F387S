/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Timer API Function Sample Implementation								     */
/**
 *	@file		OS/timer_api.c
 *	@brief		This file contains OS timer API function implementation.
 *	@details	The timer function must be implemented as it is required by
 *				task scheduler (or called automatically) to ensure that tasks
 *				are executed (cooperatively) according to their respective
 *				period or time interval. Without the timer function or even
 *				correct timing, it is virtually impossible to schedule the
 *				tasks correctly (unless there's a workaround).
 *	@note		The code is for demonstration purpose only. It only contains
 *				bare minimum implementation required by OS and must contain
 *				user implementation if necessary.
 *	@warning	Do not confuse the compiler by implementing two or more similar
 *				OSTimerAPI functions. Remove or exclude other similar
 *				source codes from build except for the current or correct source.
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
 *		Inputs		: ?
 *		Outputs		: ?
 *		Driver		: ?
 *		Helper		: TBT
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <OS/timer.h>
#include <TMR/tbt.h>

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
T_dword OSTimerAPI(T_void)
{
	return (GetDWordTBTMillis());
}

/* END OF TIMER_API. */
