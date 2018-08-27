/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* 16-bit Reload Timer			 								             */
/**
 *	@file		IO/rlt_types.h
 *	@brief		This file contains flags and types for RLT IO register.
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

#ifndef RLT_TYPES_H
#define RLT_TYPES_H

#include <IO/io_mb90385.h>

/* ----------------------------------------------------------------------------
**	RLT IO Flags.
*/

/**
 * 	@def		RLT_TRIG_SW_START
 * 	@brief		Software trigger starts counting after reloading.
 */
#define RLT_TRIG_SW_START		STD_ON

/* ----------------------------------------------------------------------------
**	RLT IO Types.
*/

/**
 * 	@brief		Defined enumerated type for RLT operation modes.
 */
typedef enum {
	RLT_MOD_TRIG_DISABLED,		/**< no valid edge or level */
	RLT_MOD_TRIG_RISE,			/**< rising edge */
	RLT_MOD_TRIG_FALL,			/**< falling edge */
	RLT_MOD_TRIG_BOTH,			/**< both edges */
	RLT_MOD_GATE_LOW,			/**< low level (not for external event clock) */
	RLT_MOD_GATE_HIGH			/**< high level (not for external event clock) */
} T_rltOpMode;

/**
 * 	@brief		Defined enumerated type for RLT count clock (n / Machine Cycle).
 */
typedef enum {
	RLT_CLK_2T,					/**< ~ 125.0 ns @ 16 MHz internal clock */
	RLT_CLK_8T,					/**< ~ 500.0 ns @ 16 MHz internal clock*/
	RLT_CLK_32T,				/**< ~   2.0 us @ 16 MHz internal clock*/
	RLT_CLK_EXT_EVT				/**< external event clock */
} T_rltCntClk;

/**
 * 	@brief		Defined enumerated type for RLT operation.
 */
typedef enum {
	RLT_OP_DISABLED,			/**< timer operation disable */
	RLT_OP_ENABLED				/**< timer operation enable (start trigger wait) */
} T_rltOperation;

/**
 * 	@brief		Defined enumerated type for RLT interrupt request.
 */
typedef enum {
	RLT_IRQ_CLEARED,			/**< clear RLT interrupt request */
	RLT_IRQ_UNDERFLOWED			/**< counter underflow generated */
} T_rltIRQ;

/**
 * 	@brief		Defined enumerated type for RLT interrupt enable.
 */
typedef enum {
	RLT_INT_DISABLED,			/**< interrupt request disable */
	RLT_INT_ENABLED				/**< interrupt request enable */
} T_rltINTEnable;

/**
 * 	@brief		Defined enumerated type for RLT underflow operation.
 */
typedef enum {
	RLT_ONESHOT,				/**< one-shot mode */
	RLT_RELOAD					/**< reload mode */
} T_rltOpAtUF;

/**
 * 	@brief		Defined enumerated type for RLT TOT pin output level.
 * 	@note		In one-shot mode, output is a rectangular wave during
 * 				counting while in reload mode, output is a toggle at
 * 				starting reload timer.
 */
typedef enum {
	RLT_TOT_OUT_HRECT 	= 0U,	/**< high rectangular wave output  */
	RLT_TOT_OUT_LTOGGLE = 0U,	/**< low toggle output */
	RLT_TOT_OUT_LRECT   = 1U,	/**< low rectangular wave output */
	RLT_TOT_OUT_HTOGGLE = 1U	/**< high toggle output */
} T_rltTOTOutLevel;

/**
 * 	@brief		Defined enumerated type for RLT TOT pin output enable.
 */
typedef enum {
	RLT_TOT_GPIO,				/**< TOT is general-purpose IO pin */
	RLT_TOT_ENABLED				/**< TOT output enable */
} T_rltTOTPin;

#endif /* RLT_TYPES_H. */
