/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Interrupt Service Routine Configuration			           			     */
/**
 *	@file		isr_cfg.h
 * 	@brief		This file contains ISR flags and usage macros.
 * 	@note		The CPU performs interrupt processing only when an interrupt
 * 				with a lower value (interrupt level) than that indicated by
 * 				the interrupt level mask register (ILM) is requested with an
 * 				interrupt enable (CCR: I = 1). Also, ensure that the ISR usage
 * 				of the ISR functions is set or enabled. Interrupt levels or
 * 				priorities must not be set to 7 (or none) and ILM must not be
 * 				set to 0 (or interrupts disabled, globally).
 *	@warning	Do not modify NOSAVEREG option. It is only applicable to
 *				library creation and will not affect user implementation.
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

#ifndef ISR_CFG_H
#define ISR_CFG_H

/* ----------------------------------------------------------------------------
**	ISR Flags.
*/

/**
 * 	@def		ISR_ENABLE
 *	@brief 		Enable flag for ISR.
 */
#define ISR_ENABLE				(1U)

/**
 * 	@def		ISR_DISABLE
 *	@brief 		Disable flag for ISR.
 */
#define ISR_DISABLE				(0U)

/* ----------------------------------------------------------------------------
**	ISR Option.
*/

#define NOSAVEREG_ADC_ISR		ISR_DISABLE
#define NOSAVEREG_CAN_ISR		ISR_DISABLE
#define NOSAVEREG_DIG_ISR		ISR_DISABLE
#define NOSAVEREG_EXI45_ISR		ISR_DISABLE
#define NOSAVEREG_EXI67_ISR		ISR_DISABLE
#define NOSAVEREG_EXIRX_ISR		ISR_DISABLE
#define NOSAVEREG_ICU0_ISR		ISR_DISABLE
#define NOSAVEREG_ICU1_ISR		ISR_DISABLE
#define NOSAVEREG_ICU23_ISR		ISR_DISABLE
#define NOSAVEREG_IOT_ISR		ISR_DISABLE
#define NOSAVEREG_PPG01_ISR		ISR_DISABLE
#define NOSAVEREG_PPG23_ISR		ISR_DISABLE
#define NOSAVEREG_RLT0_ISR		ISR_DISABLE
#define NOSAVEREG_RLT1_ISR		ISR_DISABLE
#define NOSAVEREG_SER_ISR		ISR_DISABLE
#define NOSAVEREG_TBT_ISR		ISR_DISABLE
#define NOSAVEREG_WTT_ISR		ISR_DISABLE

/* ----------------------------------------------------------------------------
**	ISR Usage.
*/

#ifdef USE_PREDEF_ADC_ISR
#define USE_ADC_ISR				ISR_ENABLE
#endif
#ifdef USE_PREDEF_CAN_ISR
#define USE_CAN_ISR				ISR_ENABLE
#endif
#ifdef USE_PREDEF_DIG_ISR
#define USE_DIG_ISR				ISR_ENABLE
#endif
#ifdef USE_PREDEF_EXI4_ISR
#define USE_EXI4_ISR			ISR_ENABLE
#endif
#ifdef USE_PREDEF_EXI5_ISR
#define USE_EXI5_ISR			ISR_ENABLE
#endif
#ifdef USE_PREDEF_EXI6_ISR
#define USE_EXI6_ISR			ISR_ENABLE
#endif
#ifdef USE_PREDEF_EXI7_ISR
#define USE_EXI7_ISR			ISR_ENABLE
#endif
#ifdef USE_PREDEF_EXIRX_ISR
#define USE_EXIRX_ISR			ISR_ENABLE
#endif
#ifdef USE_PREDEF_ICU0_ISR
#define USE_ICU0_ISR			ISR_ENABLE
#endif
#ifdef USE_PREDEF_ICU1_ISR
#define USE_ICU1_ISR			ISR_ENABLE
#endif
#ifdef USE_PREDEF_ICU2_ISR
#define USE_ICU2_ISR			ISR_ENABLE
#endif
#ifdef USE_PREDEF_ICU3_ISR
#define USE_ICU3_ISR			ISR_ENABLE
#endif
#ifdef USE_PREDEF_IOT_ISR
#define USE_IOT_ISR				ISR_ENABLE
#endif
#ifdef USE_PREDEF_PPG0_ISR
#define USE_PPG0_ISR			ISR_ENABLE
#endif
#ifdef USE_PREDEF_PPG1_ISR
#define USE_PPG1_ISR			ISR_ENABLE
#endif
#ifdef USE_PREDEF_PPG2_ISR
#define USE_PPG2_ISR			ISR_ENABLE
#endif
#ifdef USE_PREDEF_PPG3_ISR
#define USE_PPG3_ISR			ISR_ENABLE
#endif
#ifdef USE_PREDEF_PPG01_ISR
#define USE_PPG01_ISR			ISR_ENABLE
#endif
#ifdef USE_PREDEF_PPG23_ISR
#define USE_PPG23_ISR			ISR_ENABLE
#endif
#ifdef USE_PREDEF_RLT0_ISR
#define USE_RLT0_ISR			ISR_ENABLE
#endif
#ifdef USE_PREDEF_RLT1_ISR
#define USE_RLT1_ISR			ISR_ENABLE
#endif
#ifdef USE_PREDEF_SER_ISR
#define USE_SER_ISR				ISR_ENABLE
#endif
#ifdef USE_PREDEF_TBT_ISR
#define USE_TBT_ISR				ISR_ENABLE
#endif
#ifdef USE_PREDEF_WTT_ISR
#define USE_WTT_ISR				ISR_ENABLE
#endif

#endif /* ISR_CFG_H. */
