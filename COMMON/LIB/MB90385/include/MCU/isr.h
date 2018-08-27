/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Interrupt Service Routine						           			     */
/**
 *	@file		MCU/isr.h
 * 	@brief		This file contains ISR macro template and API functions.
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

#ifndef ISR_H
#define ISR_H

#include <IO/icr_io.h>
#include <isr_cfg.h>

/* ----------------------------------------------------------------------------
**	ISR Macro Template.
*/

/**
 * 	@def		ISR
 * 	@brief		ISR function declaration (qualified with INTERRUPT).
 * 	@param		NAME	Name of the interrupt handler.
 * 	@return		function declaration.
 */
#define ISR(NAME)				INTERRUPT T_void NAME(T_void)

/* ----------------------------------------------------------------------------
**	ISR API Functions.
*/

/**
 * 	@fn			T_void initIRQLevels(T_void)
 * 	@brief 		This function pre-sets all interrupt control registers (ICRs)
 * 				to level 7 (no interrupt) with no EI2OS support.
 *	@param 		.
 *	@return		.
 *	@note		The ICR	interrupt level used by the kernel UART is unmodified,
 *				and it is not intended to be changed.
 */
extern T_void initIRQLevels(T_void);

/**
 * 	@fn			T_void _start(T_void)
 * 	@brief 		The startup routine is a program that performs initialization
 * 				before executing the main program.
 *	@param 		.
 *	@return		.
 *	@note		The startup routine transfers the initial value from ROM to the
 *				variable area in RAM. Although the startup routine provided as
 *				a sample initializes all uninitialized variables to 0, perform
 *				initialization based on the program system that is to be created.
 */
extern ISR(_start);

/**
 * 	@fn 		T_void DEFAULT_IRQHandler(T_void)
 * 	@brief 		This function is a placeholder for all other vector definitions
 * 				that has not been specified using pragma intvect.
 *  @param		.
 *  @return		.
 *  @note		This function disables global interrupt, then transits to sleep
 *  			mode or loops indefinitely without leaving the function.
 */
extern ISR(DEFAULT_IRQHandler);

#endif /* ISR_H. */
