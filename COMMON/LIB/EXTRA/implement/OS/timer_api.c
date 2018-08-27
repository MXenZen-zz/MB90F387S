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
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

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
