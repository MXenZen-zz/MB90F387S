/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Timebase Timer		 								       		         */
/**
 *	@file		IO/tbt_io.h
 *	@brief		This file contains flags, types, getters and setters,
 * 				and other macro functions for TBT IO register.
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

#ifndef TBT_IO_H
#define TBT_IO_H

#include <IO/io_mb90385.h>

/* ----------------------------------------------------------------------------
**	TBT IO Flags.
*/

/**
 * 	@def		TBT_CLEAR_CTR
 *	@brief 		Clears timebase timer counter and TBOF bit.
 */
#define TBT_CLEAR_CTR			STD_CLEAR

/* ----------------------------------------------------------------------------
**	TBT IO Types.
*/

/**
 * 	@brief		Defined enumerated type for TBT interval time (2/HCLK count clock).
 */
typedef enum {
	TBT_CLK_2T12,				/**< ~ 1.0 ms @ 4 MHz */
	TBT_CLK_2T14,				/**< ~ 4.1 ms @ 4 MHz */
	TBT_CLK_2T16,				/**< ~ 16.4 ms @ 4 MHz */
	TBT_CLK_2T19				/**< ~ 131.1 ms @ 4 MHz */
} T_tbtInterval;

/**
 * 	@brief		Defined enumerated type for TBT interrupt request.
 */
typedef enum {
	TBT_IRQ_CLEARED,			/**< clear TBT interrupt request */
	TBT_IRQ_OVERFLOWED			/**< counter overflow generated */
} T_tbtIRQ;

/**
 * 	@brief		Defined enumerated type for TBT interrupt enable.
 */
typedef enum {
	TBT_INT_DISABLED,			/**< interrupt request disable */
	TBT_INT_ENABLED				/**< interrupt request enable */
} T_tbtINTEnable;

/* ----------------------------------------------------------------------------
**	TBT IO Register Getters and Setters.
*/

/**
 *	@def		GetTBT_TBTC
 *	@brief		TBT Control Register Getter.
 * 	@param 		.
 * 	@return		TBTC (byte).
 */
#define GetTBT_TBTC()			GetIOREGByte(IO_TBTC)

/**
 *	@def		SetTBT_TBTC
 *	@brief		TBT Control Register Setter.
 * 	@param[in] 	VAL		Control bits for TBTC (byte).
 * 	@return		.
 */
#define SetTBT_TBTC(VAL) { \
	SetIOREGByte(IO_TBTC, VAL); \
}

/* ----------------------------------------------------------------------------
**	TBT IO Register Fields Macro Functions.
*/

/**
 *	@def		SetTBTCountClock
 *	@brief		Count Clock Setter.
 * 	@param[in] 	VAL		Count clock (bits).
 * 	@return		.
 */
#define SetTBTCountClock(VAL) { \
	SetIOREGBitVar(IO_TBTC, TBC, VAL); \
}

/**
 *	@def		ClearTBTCounter
 *	@brief		Clear Timer Count.
 * 	@param 		.
 * 	@return		.
 */
#define ClearTBTCounter() { \
	SetIOREGBitVar(IO_TBTC, TBR, TBT_CLEAR_CTR); \
}

/**
 *	@def		ClearTBTIRQ
 *	@brief		Clear Interrupt Overflow.
 * 	@param 		.
 * 	@return		.
 */
#define ClearTBTIRQ() { \
	SetIOREGBitVar(IO_TBTC, TBOF, TBT_IRQ_CLEARED); \
}

/**
 *	@def		EnableTBTInterrupt
 *	@brief		Interrupt Enabler.
 * 	@param 		.
 * 	@return		.
 */
#define EnableTBTInterrupt() { \
	SetIOREGBitVar(IO_TBTC, TBIE, TBT_INT_ENABLED); \
}

/**
 *	@def		DisableTBTInterrupt
 *	@brief		Interrupt Disabler.
 * 	@param 		.
 * 	@return		.
 */
#define DisableTBTInterrupt() { \
	SetIOREGBitVar(IO_TBTC, TBIE, TBT_INT_DISABLED); \
}

#endif /* TBT_IO_H. */
