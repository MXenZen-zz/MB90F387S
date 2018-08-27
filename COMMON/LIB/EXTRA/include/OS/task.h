/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Task																	     */
/**
 *	@file		OS/task.h
 *	@brief		This file contains flags, types, getters and setters,
 *				other macro functions, and API functions for creating
 *				and managing tasks.
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

#ifndef TASK_H
#define TASK_H

#include <LIB/bitmanip.h>

/* ----------------------------------------------------------------------------
**	Flags.
*/

/**
 * 	@def		TASK_THIS
 * 	@brief		The dereferenced parameter or pointer variable of T_task* type
 *				known as 'task' which is present and is accessible in both task
 *				run and task wait function code blocks.
 *	@note		Task run and task wait functions are required to use this macro
 *				alias instead of using 'task' to refer to the parameter variable.
 */
#define TASK_THIS						(*task)

/**
 * 	@def		TASK_STATE_UNKNOWN
 * 	@brief		Task control block variable is not yet initialized and might
 *				contain unknown or unreadable values (task state is undefined).
 */
#define TASK_STATE_UNKNOWN				(0U)

/**
 * 	@def		TASK_STATE_INVALID_INIT_FUN
 * 	@brief		Task control block variable is being initialized but its task
 *				property contains no initialization function to be executed
 *				before the execution function.
 */
#define TASK_STATE_INVALID_INIT_FUN		(1U)

/**
 * 	@def		TASK_STATE_INVALID_EXEC_FUN
 * 	@brief		Task control block variable is being initialized and migh have
 *				task initialization function but its task property contains no
 *				execution function which contains the main task process.
 */
#define TASK_STATE_INVALID_EXEC_FUN		(2U)

/**
 * 	@def		TASK_STATE_UNINITIALIZED
 * 	@brief		Task initialization function is not yet executed (which is a
 *				requirement before executing the main task process).
 */
#define TASK_STATE_UNINITIALIZED		(3U)

/**
 * 	@def		TASK_STATE_READY
 * 	@brief		Task is ready to be executed (not waiting nor suspended)
 *				or not yet executed due to a different task of the same or
 *				higher activation period or priority is currently running.
 */
#define TASK_STATE_READY				(4U)

/**
 * 	@def		TASK_STATE_RUNNING
 * 	@brief		Task is currently being executed (running) or currently
 *				utilizing the processor (processing resource).
 */
#define TASK_STATE_RUNNING				(5U)

/**
 * 	@def		TASK_STATE_WAITING
 * 	@brief		Task cannot be executed (as of the moment) because it is
 *				currently blocked from executing by the wait function which,
 *				in place of the task, is validating a certain logical condition
 *				(either temporal or event-caused expression) to end the waiting.
 */
#define TASK_STATE_WAITING				(6U)

/**
 * 	@def		TASK_STATE_SUSPENDED
 * 	@brief		Task will not be executed as requested by the application, user
 *				or system but can be resumed if requested also.
 */
#define TASK_STATE_SUSPENDED			(7U)

/**
 * 	@def		TASK_SCHED_ALWAYS
 * 	@brief		Task can run all the time (no time constraints).
 */
#define TASK_SCHED_ALWAYS				(0U)

/**
 * 	@def		TASK_PRIO_LOWEST
 * 	@brief		The least priority any task can have.
 */
#define TASK_PRIO_LOWEST				(0U)

/**
 * 	@def		TASK_PRIO_HIGHEST
 * 	@brief		The greatest priority any task can have.
 */
#define TASK_PRIO_HIGHEST				(255U)

/**
 * 	@def		TASK_FIRST_EXEC_DELAY
 * 	@brief		Default first execution delay.
 */
#define TASK_FIRST_EXEC_DELAY			(1000UL)

/* ----------------------------------------------------------------------------
**	Types.
*/

/* forward declaration */
struct task_t;

/**
 *	@brief		Callback type for regular task functions.
 */
typedef	T_void	(*T_taskCBRun)(struct task_t*);

/**
 *	@brief		Callback type for wait task functions.
 */
typedef	T_bit	(*T_taskCBWait)(struct task_t*);

/**
 * 	@brief		Defined type for task ID data type width (default: 8 bits).
 */
typedef T_uint8	T_taskID;

/**
 * 	@brief		Defined type for task name data type (default: 16-bit pointer).
 */
typedef T_char*	T_taskName;

/**
 * 	@brief		Defined type for task priority data type width (default: 8 bits).
 */
typedef T_uint8	T_taskPrio;

/**
 * 	@brief		Defined type for task flags data type width (default: 8-bit).
 */
typedef T_bit	T_taskFlag;

/**
 * 	@brief		Defined type for task time data type width (default: 32 bits).
 */
typedef T_uint32 T_taskTime;

/**
 *	@brief		Data structure for task properties.
 */
typedef struct {
	/* task identification */
	T_taskID id;
	T_taskName name;
	/* task control */
	T_taskPrio priority;
	/* task timings */
	T_taskTime period;
	/* task callbacks */
	T_taskCBRun initialize;
	T_taskCBRun execute;
	T_taskCBWait wait;
} T_taskProp;

/**
 *	@brief		Data structure for tasks control block.
 */
struct task_t {
	/* task properties */
	const T_taskProp* properties;
	/* task control */
	T_taskFlag state	: 3;
	T_taskFlag hiPrio	: 1;
	/* task timings */
	T_taskTime nextTime;
	/* task links */
	struct task_t* nextTask;
};

/**
 *	@brief		Defined structured type for tasks.
 */
typedef struct task_t T_task;

/* ----------------------------------------------------------------------------
**	Getters and Setters.
*/

/**
 *	@def 		GetByteTaskID
 *	@brief		Gets task specified ID.
 *	@param		TASK	Task control block handler.
 *	@return		task ID (byte).
 */
#define GetByteTaskID(TASK)				((TASK).properties->id)

/**
 *	@def 		GetStringTaskName
 *	@brief		Gets task specified name.
 *	@param		TASK	Task control block handler.
 *	@return		task name (char pointer).
 */
#define GetStringTaskName(TASK)			((TASK).properties->name)

/**
 *	@def 		GetByteTaskPriority
 *	@brief		Gets task priority (execution rank).
 *	@param		TASK	Task control block handler.
 *	@return		task priority (byte).
 */
#define GetByteTaskPriority(TASK)		((TASK).properties->priority)

/**
 *	@def 		GetDWordTaskPeriod
 *	@brief		Gets task execution period.
 *	@param		TASK	Task control block handler.
 *	@return		task period (dword).
 */
#define GetDWordTaskPeriod(TASK)		((TASK).properties->period)

/**
 *	@def		IsTaskUnknown
 *	@brief		Check if task control block variable is not yet initialized.
 *	@param		TASK	 Task control block handler.
 *	@return		boolean.
 */
#define IsTaskUnknown(TASK)				EQU((TASK).state, TASK_STATE_UNKNOWN)

/**
 *	@def		IsTaskInitInvalid
 *	@brief		Check if task control block variable's property has no or
 *				invalid initialization function.
 *	@param		TASK	 Task control block handler.
 *	@return		boolean.
 */
#define IsTaskInitInvalid(TASK)			EQU((TASK).state, TASK_STATE_INVALID_INIT_FUN)

/**
 *	@def		IsTaskExecInvalid
 *	@brief		Check if task control block variable's property has no or
 *				invalid execution function.
 *	@param		TASK	 Task control block handler.
 *	@return		boolean.
 */
#define IsTaskExecInvalid(TASK)			EQU((TASK).state, TASK_STATE_INVALID_EXEC_FUN)

/**
 *	@def		IsTaskInitNotYetRun
 *	@brief		Check if task initialization function is not yet executed.
 *	@param		TASK	 Task control block handler.
 *	@return		boolean.
 */
#define IsTaskInitNotYetRun(TASK)		EQU((TASK).state, TASK_STATE_UNINITIALIZED)

/**
 *	@def		IsTaskReady
 *	@brief		Check if task is ready to be executed.
 *	@param		TASK	 Task control block handler.
 *	@return		boolean.
 */
#define IsTaskReady(TASK)				EQU((TASK).state, TASK_STATE_READY)

/**
 *	@def		IsTaskRunning
 *	@brief		Check if task is currently being executed.
 *	@param		TASK	 Task control block handler.
 *	@return		boolean.
 */
#define IsTaskRunning(TASK)				EQU((TASK).state, TASK_STATE_RUNNING)

/**
 *	@def		IsTaskWaiting
 *	@brief		Check if task is currently blocked from executing by the wait function.
 *	@param		TASK	 Task control block handler.
 *	@return		boolean.
 */
#define IsTaskWaiting(TASK)				EQU((TASK).state, TASK_STATE_WAITING)

/**
 *	@def		IsTaskSuspended
 *	@brief		Check if task will not be executed as requested (or disabled).
 *	@param		TASK	 Task control block handler.
 *	@return		boolean.
 */
#define IsTaskSuspended(TASK)			EQU((TASK).state, TASK_STATE_SUSPENDED)

/**
 *	@def		IsTaskHighPriority
 *	@brief		Check if task will always execute regardless of priority or period.
 *	@param		TASK	 Task control block handler.
 *	@return		boolean.
 */
#define IsTaskHighPriority(TASK)		IS((TASK).hiPrio)

/**
 *	@def		SetTaskReady
 *	@brief		Sets task as ready to be executed.
 *	@param		TASK	 Task control block handler.
 *	@return		.
 */
#define SetTaskReady(TASK) { \
	(TASK).state = TASK_STATE_READY; \
}

/**
 *	@def		SetTaskSuspended
 *	@brief		Sets task not to be executed or disabled.
 *	@param		TASK	Task control block handler.
 *	@return		.
 */
#define SetTaskSuspended(TASK) { \
	(TASK).state = TASK_STATE_SUSPENDED; \
}

/**
 *	@def		SetTaskNormalPriority
 *	@brief		Sets task to execute according to priority and period.
 *	@param		TASK	Task control block handler.
 *	@return		.
 */
#define SetTaskNormalPriority(TASK) { \
	(TASK).hiPrio = (T_taskFlag)FALSE; \
}

/**
 *	@def		SetTaskHighPriority
 *	@brief		Sets task to execute regardless of priority or period.
 *	@param		TASK	Task control block handler.
 *	@return		.
 */
#define SetTaskHighPriority(TASK) { \
	(TASK).hiPrio = (T_taskFlag)TRUE; \
}

/* ----------------------------------------------------------------------------
**	Macro Functions.
*/

/**
 *	@def		TASK
 *	@brief		Task function declaration and definition macro alias.
 *	@param		NAME	Task function name.
 *	@return		(void-type).
 */
#define TASK(NAME)						T_void NAME(T_task *task)

/**
 *	@def		TASK_WAIT
 *	@brief		Wait function declaration and definition macro alias.
 *	@param		NAME	Wait function name.
 *	@return		(bit-type) (TRUE(1) if task will be waiting or FALSE(0) if
 *				waiting is over (no more waiting) and task can now proceed).
 */
#define TASK_WAIT(NAME)					T_bit NAME(T_task *task)

/**
 * 	@def		TASK_PRIO
 * 	@brief		Custom task priority.
 * 	@param[in]	PP	Priority (byte).
 * 	@return		Task priority (byte).
 */
#define TASK_PRIO(PP)					(PP)

/**
 * 	@def		TASK_SCHED
 * 	@brief		Task schedule period.
 * 	@param[in]	MM	Minutes (dword).
 * 	@param[in]	SS	Seconds (dword).
 * 	@param[in]	MS	Milliseconds (dword).
 * 	@return		Interval in milliseconds (dword).
 */
#define TASK_SCHED(MM, SS, MS)			(60000UL * (MM) + 1000UL * (SS) + (MS))

/* ----------------------------------------------------------------------------
**	API Functions.
*/

/**
 *	@fn			T_task* initTask(T_task*, const T_taskProp*, T_taskTime)
 *	@brief		Initialize a task.
 *	@param		task		Task control block handler.
 *	@param[in]	properties  Task properties handler (must be constant).
 *	@param		startDelay	Task execution delay on first run.
 *	@return		task-pointer (same with first parameter).
 *	@note		Task will never execute if both the initialization and execution
 *				function are absent in the task property.
 */
extern T_task* initTask(T_task* task, const T_taskProp* properties, T_taskTime startDelay);

 /**
  *	@fn			T_bit runTaskInit(T_task*)
  *	@brief		Initialize single task.
  *	@attention	This function must be executed first before runTaskExec.
  *	@param		task	  Task control block handler.
  *	@return		initialization success.
  *	@note		Task will never execute if both the initialization and execution
  *				function are absent in the task property.
  */
extern T_bit runTaskInit(T_task* task);

/**
 *	@fn			T_bit runTaskExec(T_task*)
 *	@brief		Executes single task.
 *	@pre		runTaskInit already called.
 *	@param		task	  Task control block handler.
 *	@return		execute success.
 *	@note		Task will never execute if both the initialization and execution
 *				function are absent in the task property.
 *	@note		The task will only execute if task is runnable, executable,
 *				ready to run this time, or run always. It will not execute
 *				if the task is currently running, suspended or waiting.
 *				Treat appropriately suspended tasks by resuming them if needed.
 *				Similarly, to break long wait from the wait function, set task
 *				to ready ahead of the function's call to release from wait
 *				temporarily (or at once).
 */
extern T_bit runTaskExec(T_task* task);

/**
 *	@brief		Logs (through serial output) latest task activation and other
 *				task information.
 *	@note		When executed within the task, parameter is &TASK_THIS.
 */
extern TASK(logActiveTask);

#endif /* TASK_H. */
