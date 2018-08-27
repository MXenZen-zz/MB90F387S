/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Programmable Pulse Generator			 						             */
/**
 *	@file		IO/ppg_types.h
 *	@brief		This file contains types for PPG IO registers.
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

#ifndef PPG_TYPES_H
#define PPG_TYPES_H

#include <IO/io_mb90385.h>

/* ----------------------------------------------------------------------------
**	PPG IO Types.
*/

/**
 * 	@brief		Defined enumerated type for PPG count clock.
 */
typedef enum {
	PPG_MCLK_1T,				/**< ~ 62.5 ns @ 16 MHz */
	PPG_MCLK_2T,				/**< ~ 125.0 ns @ 16 MHz */
	PPG_MCLK_4T,				/**< ~ 250.0 ns @ 16 MHz */
	PPG_MCLK_8T,				/**< ~ 500.0 ns @ 16 MHz */
	PPG_MCLK_16T,				/**< ~ 1.0 us @ 16 MHz */
	PPG_CLK_DISABLED,			/**< clock settings disabled */
	PPG_CLK_NO_CLOCK,			/**< clock settings disabled */
	PPG_HCLK_512T				/**< ~ 128.0 us @ 4 MHz */
} T_ppgCntClk;

/**
 * 	@brief		Defined enumerated type for PPG operation modes.
 */
typedef enum {
	PPG_MOD_8BIT_2CH,			/**< 8-bit PPG output 2-ch independent */
	PPG_MOD_8_8BIT_1CH,			/**< 8 + 8-bit PPG output */
	PPG_MOD_DISABLED,			/**< operation setting disable */
	PPG_MOD_16BIT_1CH			/**< 16-bit PPG output */
} T_ppgOpMode;

/**
 * 	@brief		Defined enumerated type for PPG interrupt request.
 */
typedef enum {
	PPG_IRQ_CLEARED,			/**< clear PPG interrupt request */
	PPG_IRQ_UNDERFLOWED			/**< counter underflow generated */
} T_ppgIRQ;

/**
 * 	@brief		Defined enumerated type for PPG interrupt enable.
 */
typedef enum {
	PPG_INT_DISABLED,			/**< interrupt request disable */
	PPG_INT_ENABLED				/**< interrupt request enable */
} T_ppgINTEnable;

/**
 * 	@brief		Defined enumerated type for PPG pin output enable.
 */
typedef enum {
	PPG_PIN_GPIO,				/**< PPG is general-purpose IO pin */
	PPG_PIN_ENABLED				/**< PPG pulse output enable */
} T_ppgPin;

/**
 * 	@brief		Defined enumerated type for PPG operation.
 */
typedef enum {
	PPG_OP_DISABLED,			/**< counting disable (holds "L" level output) */
	PPG_OP_ENABLED				/**< counting enable */
} T_ppgOperation;

#endif /* PPG_TYPES_H. */
