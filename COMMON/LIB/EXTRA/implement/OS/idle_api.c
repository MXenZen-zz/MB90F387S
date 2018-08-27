/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Idle API Function Sample Implementation				           	  	     */
/**
 *	@file		OS/idle_api.c
 *	@brief		This file contains OS idle API function implementation.
 *	@details	The idle task routine can be implemented to perform activities
 *				other than the main task but only when no ready or active task
 *				shall execute or have recently executed along with it.
 *	@note		The code is for demonstration purpose only. It only contains
 *				bare minimum implementation required by OS and must contain
 *				user implementation if necessary.
 *	@warning	Do not confuse the compiler by implementing two or more similar
 *				idleTaskRoutine API functions. Remove or exclude other similar
 *				source codes from build except for the current or correct source.
**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <OS/idle.h>

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
	/* TODO: do something crazy and stop procrastinating */
}

/* END OF IDLE_API. */
