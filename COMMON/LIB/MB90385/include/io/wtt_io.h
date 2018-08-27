/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Watch Timer		 									       		         */
/**
 *	@file		IO/wtt_io.h
 *	@brief		This file contains flags, types, getters and setters,
 * 				and other macro functions for WTT IO register.
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

#ifndef WTT_IO_H
#define WTT_IO_H

#include <IO/io_mb90385.h>

/* ----------------------------------------------------------------------------
**	WTT IO Flags.
*/

/**
 * 	@var		WTT_CLEAR_CTR
 *	@brief		Clears watch timer counter.
 */
#define WTT_CLEAR_CTR			STD_CLEAR

/* ----------------------------------------------------------------------------
**	WDT IO Types.
*/

/**
 * 	@brief		Defined enumerated type for WTT interval time.
 */
typedef enum {
	WTT_CLK_2T8,				/**< ~ 31.25 ms @ 8.192 kHz */
	WTT_CLK_2T9,				/**< ~ 62.5 ms @ 8.192 kHz */
	WTT_CLK_2T10,				/**< ~ 125.0 ms @ 8.192 kHz */
	WTT_CLK_2T11,				/**< ~ 250.0 ms @ 8.192 kHz */
	WTT_CLK_2T12,				/**< ~ 500.0 ms @ 8.192 kHz */
	WTT_CLK_2T13,				/**< ~ 1.0 s @ 8.192 kHz */
	WTT_CLK_2T14,				/**< ~ 2.0 s @ 8.192 kHz */
	WTT_CLK_2T15				/**< ~ 4.0 s @ 8.192 kHz */
} T_wttInterval;

/**
 * 	@brief		Defined enumerated type for WTT interrupt request.
 */
typedef enum {
	WTT_IRQ_CLEARED,			/**< clear WTT interrupt request */
	WTT_IRQ_OVERFLOWED			/**< counter overflow generated */
} T_wttIRQ;

/**
 * 	@brief		Defined enumerated type for WTT interrupt enable.
 */
typedef enum {
	WTT_INT_DISABLED,			/**< interrupt request disable */
	WTT_INT_ENABLED				/**< interrupt request enable */
} T_wttINTEnable;

/**
 * 	@brief		Defined enumerated type for WTT oscillation stabilization.
 */
typedef enum {
	WTT_OSC_STAB_WAIT,			/**< oscillation stabilization wait state */
	WTT_OSC_STAB_WAIT_END		/**< oscillation stabilization wait time end */
} T_wttOSCStab;

/**
 * 	@brief		Defined enumerated type for WTT watchdog clock source.
 */
typedef enum {
	WTT_WDG_CLKSRC_WTC,			/**< watch timer (MCLK or PCLK mode) */
	WTT_WDG_CLKSRC_TBT			/**< timebase timer (MCLK or PCLK mode) */
} T_wttWDTClkSrc;

/* ----------------------------------------------------------------------------
**	WDT IO Register Getters and Setters.
*/

/**
 *	@def		GetWTT_WTC
 *	@brief		WTT Control Register Getter.
 * 	@param 		.
 * 	@return		WTC (byte).
 */
#define GetWTT_WTC()			GetIOREGByte(IO_WTC)

/**
 *	@def		SetWTT_WTC
 *	@brief		WTT Control Register Setter.
 * 	@param[in] 	VAL		Control bits for WTC (byte).
 * 	@return		.
 */
#define SetWTT_WTC(VAL) { \
	SetIOREGByte(IO_WTC, VAL); \
}

/* ----------------------------------------------------------------------------
**	WDT IO Register Fields Macro Functions.
*/

/**
 *	@def		SetWTTCountClock
 *	@brief		Count Clock Setter.
 * 	@param[in] 	VAL		Count clock (bits).
 * 	@return		.
 */
#define SetWTTCountClock(VAL) { \
	SetIOREGBitVar(IO_WTC, WTC, VAL); \
}

/**
 *	@def		ClearWTTCounter
 *	@brief		Clear Timer Count.
 * 	@param 		.
 * 	@return		.
 */
#define ClearWTTCounter() { \
	SetIOREGBitVar(IO_WTC, WTR, WTT_CLEAR_CTR); \
}

/**
 *	@def		ClearWTTIRQ
 *	@brief		Clear Interrupt Overflow.
 * 	@param 		.
 * 	@return		.
 */
#define ClearWTTIRQ() { \
	SetIOREGBitVar(IO_WTC, WTOF, WTT_IRQ_CLEARED); \
}

/**
 *	@def		EnableWTTInterrupt
 *	@brief		Interrupt Enabler.
 * 	@param 		.
 * 	@return		.
 */
#define EnableWTTInterrupt() { \
	SetIOREGBitVar(IO_WTC, WTIE, WTT_INT_ENABLED); \
}

/**
 *	@def		DisableWTTInterrupt
 *	@brief		Interrupt Disabler.
 * 	@param 		.
 * 	@return		.
 */
#define DisableWTTInterrupt() { \
	SetIOREGBitVar(IO_WTC, WTIE, WTT_INT_DISABLED); \
}

/**
 *	@def		IsWTTOscStabilized
 *	@brief		Checks for oscillation stabilization.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsWTTOscStabilized() \
	EQU(GetIOREGBitVar(IO_WTC, SCE), WTT_OSC_STAB_WAIT_END)

/**
 *	@def		SetWTTWDGClockSource
 *	@brief		Watchdog Timer Clock Source Setter.
 * 	@param[in] 	VAL		Clock source (bits).
 * 	@return		.
 */
#define SetWTTWDGClockSource(VAL) { \
	SetIOREGBitVar(IO_WTC, WDCS, VAL); \
}

#endif /* WTT_IO_H. */
