/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* DTP / External Interrupt										             */
/**
 *	@file		INT/exi.h
 *	@brief		This file contains EXI types, external constants, and API functions.
 *	@note		CAN wake-up interrupt is the same as EXI RX interrupt. There's
 *				no distinction between interrupts of CAN Wake-up and EXI RX.
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

#ifndef EXI_H
#define EXI_H

#include <IO/exi_io.h>
#include <MCU/isr.h>

/* ----------------------------------------------------------------------------
**	EXI Types.
*/

/**
 *	@brief 		Callback type for EXI user routine functions.
 */
typedef T_void (*T_exISRHook)(T_void);

/**
 * 	@brief		Defined enumerated type for EXI channel.
 */
typedef enum {
	EXI_CH4 = 24U,				/**< channel 4 */
	EXI_CH5 = 25U,				/**< channel 5 */
	EXI_CH6 = 26U,				/**< channel 6 */
	EXI_CH7 = 27U,				/**< channel 7 */
	EXI_RX  = 44U				/**< channel RX (CAN Wake-up) */
} T_exiChannel;

/* ----------------------------------------------------------------------------
**	EXI External Constants.
*/

/**
 * 	@var		PRIO_EXI45_ISR
 *	@brief		ISR interrupt level/priority of EXI for channels 4 and 5.
 *	@note		The ICR of EXI45 is shared with ICU0. Unless ICU0 is not used,
 *				they must have the same ICR level at all times. If only EXI45
 *				is (or will be) used, then set the ICR level of EXI45 alone.
 */
extern const T_icrINTLevel PRIO_EXI45_ISR;

/**
 * 	@var		PRIO_EXI67_ISR
 *	@brief		ISR interrupt level/priority of EXI for channels 6 and 7.
 *	@note		The ICR of EXI67 is shared with WTT. Since there is no
 *				subclock in MB90F387S and MB90387S, WTT interrupt level
 *				must be the same as EXI67 interrupt level at all times.
 */
extern const T_icrINTLevel PRIO_EXI67_ISR;

/**
 * 	@var		PRIO_EXIRX_ISR
 *	@brief		ISR interrupt level/priority of EXI for channel RX
 *				or interrupt level/priority of of CAN Wake-up.
 *	@note		The ICR of EXI RX (CAN Wake-up) is shared with TBT. Unless
 *				TBT is not used, they must have the same ICR level at all
 *				times. If only EXI RX (CAN Wake-up) is (or will be) used,
 *				then set the ICR level of EXI RX (CAN Wake-up) alone.
 */
extern const T_icrINTLevel PRIO_EXIRX_ISR;

/* ----------------------------------------------------------------------------
**	EXI API Functions.
*/

/**
 * 	@fn 		T_void initEXI(T_void)
 *	@brief 		Initialize EXI.
 * 	@param		.
 * 	@return		.
 */
extern T_void initEXI(T_void);

/**
 * 	@fn 		T_void attachEXI(T_exiChannel, T_exiDetectLevel, T_exISRHook)
 *	@brief 		Initializes an external interrupt module and attaches a function
 *  			for user-specific interrupt actions when interrupt occurs.
 * 	@param[in]	channel		EXI channel.
 * 	@param[in]	level		EXI detection level.
 * 	@param[in]	exiFunc		EXI user function.
 * 	@return		.
 *	@note		CAN wake-up interrupt is the same as EXI RX interrupt.
 */
extern T_void attachEXI(T_exiChannel channel, T_exiDetectLevel level, T_exISRHook exiFunc);

/**
 * 	@fn 		T_void detachEXI(T_exiChannel)
 *	@brief 		Disables an external interrupt module and detaches the function
 *  			for user-specific interrupt actions.
 * 	@param[in]	channel		EXI channel.
 * 	@return		.
 */
extern T_void detachEXI(T_exiChannel channel);

/**
 * 	@fn 		T_void EXI45_IRQHandler(T_void)
 *	@brief		Clears external interrupt flag and executes external
 *  			interrupt user routine function.
 *  @param		.
 *  @return		.
 */
#if (USE_EXI4_ISR || USE_EXI5_ISR)
#if NOSAVEREG_EXI45_ISR
NOSAVEREG
#endif
extern ISR(EXI45_IRQHandler);
#endif

/**
 * 	@fn 		T_void EXI67_IRQHandler(T_void)
 *	@brief		Clears external interrupt flag and executes external
 *  			interrupt user routine function.
 *  @param		.
 *  @return		.
 */
#if (USE_EXI6_ISR || USE_EXI7_ISR)
#if NOSAVEREG_EXI67_ISR
NOSAVEREG
#endif
extern ISR(EXI67_IRQHandler);
#endif

/**
 * 	@fn 		T_void EXIRX_IRQHandler(T_void)
 *	@brief		Clears external interrupt flag and executes external
 *  			interrupt user routine function.
 *  @param		.
 *  @return		.
 *	@note		CAN wake-up interrupt is the same as EXI RX interrupt.
 */
#if USE_EXIRX_ISR
#if NOSAVEREG_EXIRX_ISR
NOSAVEREG
#endif
extern ISR(EXIRX_IRQHandler);
#endif

#endif /* EXI_H. */
