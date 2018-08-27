/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Idle API Function Implementation for Operating System Test     	  	     */
/**
 *	@file		idle.c
 *	@brief		This file contains OS idle API function implementation.
 *	@details	The idle task routine can be implemented to perform activities
 *				other than the main task but only when no ready or active task
 *				shall execute or have recently executed along with it. In this
 *				case, the routine is implemented to check the pin state of the
 *				pushbutton of each task. If the pushbutton is not pressed,
 *				the task will be disabled (suspended) and the execution function
 *				will not run regardless of the scheduled interval. Conversely,
 *				if the pushbutton is pressed, the task will be enabled (ready)
 *				and the execution function will run according to its scheduled
 *				interval.
 *	@warning	Do not confuse the compiler by implementing two or more similar
 *				idleTaskRoutine API functions. Remove or exclude other similar
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
 *		Inputs		: P25, P27
 *		Outputs		: N/A
 *		Driver		: N/A
 *		Helper		: DIO
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <GPIO/dio.h>

#include <OS/task.h>
#include <OS/idle.h>

/* ----------------------------------------------------------------------------
**	Test Variables.
*/

/**
 *	@var 		task1
 *	@brief		Tasks of port 1.
 */
extern T_task task1[2];

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
T_void idleTaskRoutine(T_void)
{
	static T_swDebBuffer swDebPin25, swDebPin27;

	/* check button debounce state of pin 25 */
	if (NOT(readDebouncedNegTrig(&swDebPin25, 8U, ReadBitIOPinData(PIN_P25)))) {
		/* enable task10 */
		SetTaskReady(task1[0]);
	} else {
		/* disable task10 */
		SetTaskSuspended(task1[0]);
	}

	/* check button debounce state of pin 27 */
	if (NOT(readDebouncedNegTrig(&swDebPin27, 8U, ReadBitIOPinData(PIN_P27)))) {
		/* enable task11 */
		SetTaskReady(task1[1]);
	} else {
		/* disable task11 */
		SetTaskSuspended(task1[1]);
	}
}

/* END OF IDLE. */
