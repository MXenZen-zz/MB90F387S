/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Clock								 						             */
/**
 *	@file		IO/clk_io.h
 *	@brief		This file contains types, getters and setters, and other
 * 				macro functions for CLK IO register.
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

#ifndef CLK_IO_H
#define CLK_IO_H

#include <IO/io_mb90385.h>

/* ----------------------------------------------------------------------------
**	CLK IO Types.
*/

/**
 * 	@brief		Defined enumerated type for CLK multiplication rates.
 */
typedef enum {
	CLK_1xHCLK,					/**< 1 × HCLK (4 MHz  @ 4 MHz HCLK) */
	CLK_2xHCLK,					/**< 2 × HCLK (8 MHz  @ 4 MHz HCLK) */
	CLK_3xHCLK,					/**< 3 × HCLK (12 MHz @ 4 MHz HCLK) */
	CLK_4xHCLK					/**< 4 × HCLK (16 MHz @ 4 MHz HCLK) */
} T_clkRate;

/**
 * 	@brief		Defined enumerated type for CLK selection (for MCS and SCS).
 */
typedef enum {
	CLK_SEL_PLL  = 0U,			/**< PLL clock selected (MCS) */
	CLK_SEL_SUB  = 0U,			/**< subclock selected (SCS) */
	CLK_SEL_MAIN = 1U			/**< main clock selected (MCS, SCS) */
} T_clkSelection;

/**
 * 	@brief		Defined enumerated type for CLK oscillation stabilization
 * 				wait time (n / HCLK).
 */
typedef enum {
	CLK_WAIT_2T10,				/**< ~ 256 us */
	CLK_WAIT_2T13,				/**< ~ 2.05 ms */
	CLK_WAIT_2T15,				/**< ~ 8.19 ms */
	CLK_WAIT_2T17_18			/**< ~ 32.77 ms (except POR), ~ 65.54 ms (only POR) */
} T_clkOscStabWaitTime;

/**
 * 	@brief		Defined enumerated type for CLK operation (for MCM and SCM).
 */
typedef enum {
	CLK_OP_PLL      = 0U,		/**< operating on the PLL clock (MCM) */
	CLK_OP_SUB      = 0U,		/**< operating on the subclock (SCM) */
	CLK_OP_MAIN_SUB = 1U,		/**< operating on the main clock or subclock (MCM) */
	CLK_OP_MAIN_PLL	= 1U		/**< operating on the main clock or PLL clock (SCM) */
} T_clkOperation;

/* ----------------------------------------------------------------------------
**	CLK IO Registers Getters and Setters.
*/

/**
 * 	@def		GetCLK_CKSCR
 * 	@brief		Clock Select Register Getter.
 * 	@param 		.
 * 	@return  	CKSCR (byte).
 */
#define GetCLK_CKSCR()			GetIOREGByte(IO_CKSCR)

/**
 * 	@def		SetCLK_CKSCR
 * 	@brief		Clock Select Register Setter.
 * 	@param[in] 	VAL		Control bits for CKSCR (byte).
 * 	@return  	.
 */
#define SetCLK_CKSCR(VAL) { \
	SetIOREGByte(IO_CKSCR, VAL); \
}

/* ----------------------------------------------------------------------------
**	CLK IO Register Fields Macro Functions.
*/

/**
 *	@def 		SetCLKMultiplier
 *	@brief 		HCLK multiplier setter.
 * 	@param		VAL		HCLK multiplier (byte).
 * 	@return		.
 */
#define SetCLKMultiplier(VAL) { \
	SetIOREGBitVar(IO_CKSCR, CS, VAL); \
}

/**
 *	@def 		SetCLKPLLClockPLL
 *	@brief 		PLL clock for PLL.
 * 	@param		.
 * 	@return		.
 */
#define SetCLKPLLClockPLL() { \
	SetIOREGBitVar(IO_CKSCR, MCS, CLK_SEL_PLL); \
}

/**
 *	@def 		SetCLKPLLClockMain
 *	@brief 		Main clock for PLL.
 * 	@param		.
 * 	@return		.
 */
#define SetCLKPLLClockMain() { \
	SetIOREGBitVar(IO_CKSCR, MCS, CLK_SEL_MAIN); \
}

/**
 *	@def 		SetCLKSubClockSub
 *	@brief 		Subclock for subclock.
 * 	@param		.
 * 	@return		.
 */
#define SetCLKSubClockSub() { \
	SetIOREGBitVar(IO_CKSCR, SCS, CLK_SEL_SUB); \
}

/**
 *	@def 		SetCLKSubClockMain
 *	@brief 		Main clock for subclock.
 * 	@param		.
 * 	@return		.
 */
#define SetCLKSubClockMain() { \
	SetIOREGBitVar(IO_CKSCR, SCS, CLK_SEL_MAIN); \
}

/**
 *	@def 		SetCLKOscStabWaitTime
 *	@brief 		Oscillation stabilization wait time setter.
 * 	@param[in]	VAL		Oscillation stabilization wait time (byte).		.
 * 	@return		.
 */
#define SetCLKOscStabWaitTime(VAL) { \
	SetIOREGBitVar(IO_CKSCR, WS, VAL); \
}

/**
 *	@def 		IsCLKPLLOpClockPLL
 *	@brief 		Check if PLL is operating based on the PLL clock.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsCLKPLLOpClockPLL() \
	EQU(GetIOREGBitVar(IO_CKSCR, MCM), CLK_OP_PLL)

/**
 *	@def 		IsCLKPLLOpClockMain
 *	@brief 		Check if PLL is operating based on the main clock.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsCLKPLLOpClockMain() \
	EQU(GetIOREGBitVar(IO_CKSCR, MCM), CLK_OP_MAIN_SUB)

/**
 *	@def 		IsCLKSubOpClockSub
 *	@brief 		Check if subclock is operating based on the subclock.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsCLKSubOpClockSub() \
	EQU(GetIOREGBitVar(IO_CKSCR, SCM), CLK_OP_SUB)

/**
 *	@def 		IsCLKSubOpClockMain
 *	@brief 		Check if subclock is operating based on the main clock.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsCLKSubOpClockMain() \
	EQU(GetIOREGBitVar(IO_CKSCR, SCM), CLK_OP_MAIN_PLL)

#endif /* CLK_IO_H. */
