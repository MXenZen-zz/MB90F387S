/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Scheduler															     */
/**
 *	@file		OS/scheduler.h
 *	@brief		This file contains types and API functions for creating
 *				and managing schedulers.
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

#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <OS/task.h>

/* ----------------------------------------------------------------------------
**	Types.
*/

/**
 * 	@brief		Defined type for scheduler flags data type width (default: 8-bit).
 */
typedef T_bit	T_schedFlag;

/**
 *	@brief		Defined structured type for schedulers.
 */
typedef struct scheduler_t {
	/* scheduler control */
	T_schedFlag scheduling	: 1;
	/* task link */
	T_task* linkedTask;
} T_scheduler;

/* ----------------------------------------------------------------------------
**	API Functions.
*/

/**
 *	@fn			T_schedID initScheduler(T_scheduler*)
 *	@brief 		Initialize a scheduler.
 *	@param		scheduler	Scheduler handler.
 *	@return		scheduler ID.
 */
extern T_void initScheduler(T_scheduler* scheduler);

/**
 *	@fn 		T_bit addSchedulerTask(T_scheduler*, T_task*)
 *	@brief 		Appends task to the tail of the execution chain.
 *	@param		scheduler	Scheduler handler.
 *	@param		task 		Reference to the task handler to be appended.
 *	@return		append success.
 *	@note 		A task can only be part of the chain once.
 */
extern T_bit addSchedulerTask(T_scheduler* scheduler, T_task* task);

/**
 *	@fn 		T_bit deleteSchedulerTask(T_scheduler*, T_task*)
 *	@brief 		Deletes specific task from the execution chain.
 *	@param		scheduler	Scheduler handler.
 *	@param		task 		Reference to the task handler to be deleted from the chain.
 *	@return		delete success.
 *	@note 		A task can only be removed from its registered scheduler.
 */
extern T_bit deleteSchedulerTask(T_scheduler* scheduler, T_task* task);

/**
 *	@fn 		T_void readyAllSchedulerTasks(T_scheduler*)
 *	@brief 		Enables all the tasks in the execution chain.
 *	@param		scheduler	Scheduler handler.
 *	@return		.
 */
extern T_void readyAllSchedulerTasks(T_scheduler* scheduler);

/**
 *	@fn 		T_void suspendAllSchedulerTasks(T_scheduler*)
 *	@brief 		Disables all tasks in the execution chain.
 *	@param		scheduler	Scheduler handler.
 *	@return		.
 */
extern T_void suspendAllSchedulerTasks(T_scheduler* scheduler);

/**
 *	@fn 		T_bit runSchedulerInit(T_scheduler* scheduler)
 *	@brief 		Runs task's initializer to initialize tasks in sequence.
 *	@param		scheduler		Scheduler handler.
 *	@return		task initialized.
 *	@note		Tasks must be initialized first before scheduling main task
 *				functions. All task are initialized run-through.
 */
extern T_bit runSchedulerInit(T_scheduler* scheduler);

/**
 *	@fn 		T_bit runSchedulerExec(T_scheduler*)
 *	@brief 		Runs task's executioner to executes tasks in sequence.
 *	@param		scheduler		Scheduler handler.
 *	@return		task executed (TRUE for main tasks, FALSE for idle tasks).
 *	@note
 *	@note		The scheduler executes based on timer-based prioritized
 *				cooperative tasking. The task, once running, will run up to
 *				completion. Tasks don’t run all the time but periodically.
 *				If there's no ready task to execute, the idle task will be
 *				executed. Different pseudo "priority" could be achieved by
 *				running task more frequently.
 */
extern T_bit runSchedulerExec(T_scheduler* scheduler);

#endif /* SCHEDULER_H. */
