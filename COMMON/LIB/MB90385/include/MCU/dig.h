/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Delayed Interrupt Generation									             */
/**
 *	@file		MCU/dig.h
 * 	@brief		This file contains DIG types, external constants, and API functions.
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

#ifndef DIG_H
#define DIG_H

#include <IO/dig_io.h>
#include <MCU/isr.h>

/* ----------------------------------------------------------------------------
**	DIG Types.
*/

/**
 *	@brief 		Callback type for DIG interrupt user function.
 */
typedef T_void (*T_digISRHook)(T_void);

/* ----------------------------------------------------------------------------
**	DIG External Constants.
*/

/**
 * 	@var		PRIO_DIG_ISR
 *	@brief		ISR interrupt level/priority of DIG.
 */
extern const T_icrINTLevel PRIO_DIG_ISR;

/* ----------------------------------------------------------------------------
**	DIG API Functions.
*/

/**
 * 	@fn 		T_void initDIG(T_void)
 *	@brief 		Initialize DIG.
 * 	@param		.
 * 	@return		.
 */
extern T_void initDIG(T_void);

/**
 * 	@fn 		T_void setDIGFunction(T_digISRHook digFunc)
 *	@brief 		Sets the interrupt user function that will be executed upon
 *				interrupt generation.
 * 	@param[in]	digFunc		DIG user function.
 * 	@return		.
 */
extern T_void setDIGFunction(T_digISRHook digFunc);

/**
 * 	@fn 		T_void DIG_IRQHandler(T_void)
 *	@brief		Clears external interrupt flag and executes interrupt user function.
 *  @param		.
 *  @return		.
 */
#if USE_DIG_ISR
#if NOSAVEREG_DIG_ISR
NOSAVEREG
#endif
extern ISR(DIG_IRQHandler);
#endif

#endif /* DIG_H. */
