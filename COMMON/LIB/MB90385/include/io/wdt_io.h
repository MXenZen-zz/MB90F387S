/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Watchdog Timer		 									   		         */
/**
 *	@file		IO/wdt_io.h
 * 	@brief		This file contains flags, types, getters and setters,
 * 				and other macro functions for WDT IO register.
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

#ifndef WDT_IO_H
#define WDT_IO_H

#include <IO/io_mb90385.h>

/* ----------------------------------------------------------------------------
**	WDT IO Flags.
*/

/**
 *	@def		WDT_START_CLEAR
 *	@brief		Starts or clears the watchdog timer.
 */
#define WDT_START_CLEAR			STD_CLEAR

/* ----------------------------------------------------------------------------
**	WDT IO Types.
*/

/**
 * 	@brief		Defined enumerated type for WDT interval time.
 */
typedef enum {
	WDT_WT_TBT_2T14_2T11,		/**< ~ 3.58 -  4.61 ms @ 4 MHz HCLK */
	WDT_WT_TBT_2T16_2T13,		/**< ~ 14.33 - 18.3 ms @ 4 MHz HCLK */
	WDT_WT_TBT_2T18_2T15,		/**< ~ 57.23 - 73.73 ms @ 4 MHz HCLK */
	WDT_WT_TBT_2T21_2T18		/**< ~ 458.75 - 589.82 ms @ 4 MHz HCLK */
} T_wdtInterval;

/* ----------------------------------------------------------------------------
**	WDT IO Register Getters and Setters.
*/

/**
 *	@def		GetWDT_WDTC
 *	@brief		WDT Control Register Getter.
 * 	@param 		.
 * 	@return		WDTC (byte).
 */
#define GetWDT_WDTC()			GetIOREGByte(IO_WDTC)

/**
 *	@def		SetWDT_WDTC
 *	@brief		WDT Control Register Setter.
 * 	@param[in] 	VAL		Control bits for WDTC (byte).
 * 	@return		.
 */
#define SetWDT_WDTC(VAL) { \
	SetIOREGByte(IO_WDTC, VAL); \
}

/* ----------------------------------------------------------------------------
**	WDT IO Register Fields Macro Functions.
*/

/**
 *	@def		SetWDTIntervalTime
 *	@brief		Interval time selection.
 * 	@param[in]	VAL		Interval time selection (bits).
 * 	@return		.
 */
#define SetWDTIntervalTime(VAL) { \
	SetIOREGBitVar(IO_WDTC, WT, VAL); \
}

/**
 *	@def		StartWDT
 *	@brief		Starts the watchdog timer (first write after reset only).
 * 	@param		.
 * 	@return		.
 */
#define StartWDT() { \
	SetIOREGBitVar(IO_WDTC, WTE, WDT_START_CLEAR); \
}

/**
 *	@def		ClearWDT
 *	@brief		Clears the watchdog timer (subsequent writes after reset).
 * 	@param		.
 * 	@return		.
 */
#define ClearWDT() { \
	SetIOREGBitVar(IO_WDTC, WTE, WDT_START_CLEAR); \
}

/**
 *	@def		IsResetWDTPowerOnCaused
 *	@brief		Check if power-on caused reset.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsResetWDTPowerOnCaused() \
	IS(GetIOREGBitVar(IO_WDTC, PONR))

/**
 *	@def		IsResetWDTWatchdogCaused
 *	@brief		Check if watchdog caused reset.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsResetWDTWatchdogCaused() \
	IS(GetIOREGBitVar(IO_WDTC, WRST))

/**
 *	@def		IsResetWDTExternalPinCaused
 *	@brief		Check if external pin caused reset.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsResetWDTExternalPinCaused() \
	IS(GetIOREGBitVar(IO_WDTC, ERST))

/**
 *	@def		IsResetWDTSoftwareCaused
 *	@brief		Check if software caused reset.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsResetWDTSoftwareCaused() \
	IS(GetIOREGBitVar(IO_WDTC, SRST))

#endif /* WDT_IO_H. */
