/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Watch Timer													             */
/**
 *	@file		TMR/wtt.h
 * 	@brief		This file contains WTT external constants and API functions.
 *  @warning	There is no subclock in MB90F387S and MB90387S.
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

#ifndef WTT_H
#define WTT_H

#include <IO/wtt_io.h>
#include <TMR/gpt.h>
#include <MCU/isr.h>

/* ----------------------------------------------------------------------------
**	WTT External Constants.
*/

/**
 * 	@var		PRIO_WTT_ISR
 *	@brief		ISR interrupt level/priority of WTT.
 *	@note		The ICR of WTT is shared with EXI67. Since there is no
 *				subclock in MB90F387S and MB90387S, WTT interrupt level
 *				must be the same as EXI67 interrupt level at all times.
 */
extern const T_icrINTLevel PRIO_WTT_ISR;

/* ----------------------------------------------------------------------------
**	WTT API Functions.
*/


/**
 * 	@fn 		T_void initWTT(T_void)
 *	@brief 		Initialize WTT.
 * 	@attention	WTT is not set to operate.
 * 	@param		.
 * 	@return		.
 */
extern T_void initWTT(T_void);

/**
 * 	@fn 		T_void WTT_IRQHandler(T_void)
 *	@brief 		Clears watch timer interrupt flag.
 *  @param		.
 *  @return		.
 */
#if USE_WTT_ISR
#if NOSAVEREG_WTT_ISR
NOSAVEREG
#endif
extern ISR(WTT_IRQHandler);
#endif

#endif /* WTT_H. */
