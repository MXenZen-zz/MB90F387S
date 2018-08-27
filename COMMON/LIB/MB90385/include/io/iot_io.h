/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Input / Output Timer			 								             */
/**
 *	@file		IO/iot_io.h
 *	@brief		This file contains flags, types, getters and setters,
 * 				and other macro functions for IO Timer register.
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

#ifndef IOT_IO_H
#define IOT_IO_H

#include <IO/io_mb90385.h>

/* ----------------------------------------------------------------------------
**	IO Timer Flags.
*/

/**
 * 	@def		IOT_CLEAR_CTR
 *	@brief 		Initialize counter to "0000H".
 */
#define IOT_CLEAR_CTR			STD_HIGH

/* ----------------------------------------------------------------------------
**	IO Timer IO Types.
*/

/**
 * 	@brief		Defined enumerated type for IOT count clock (n / Machine Cycle).
 */
typedef enum {
	IOT_CLK_1T,					/**< ~ 62.5 ns @ 16 MHz */
	IOT_CLK_2T,					/**< ~ 125.0 ns @ 16 MHz */
	IOT_CLK_4T,					/**< ~ 250.0 ns @ 16 MHz */
	IOT_CLK_8T,					/**< ~ 500.0 ns @ 16 MHz */
	IOT_CLK_16T,				/**< ~ 1.0 us @ 16 MHz */
	IOT_CLK_32T,				/**< ~ 2.0 us @ 16 MHz */
	IOT_CLK_64T,				/**< ~ 4.0 us @ 16 MHz */
	IOT_CLK_128T				/**< ~ 8.0 us @ 16 MHz */
} T_iotCntClk;

/**
 * 	@brief		Defined enumerated type for IOT timer count.
 */
typedef enum {
	IOT_CNT_ENABLED,			/**< counting enabled */
	IOT_CNT_DISABLED			/**< counting disabled (stop)*/
} T_iotSWStart;

/**
 * 	@brief		Defined enumerated type for IOT interrupt enable.
 */
typedef enum {
	IOT_INT_DISABLED,			/**< interrupt request disable */
	IOT_INT_ENABLED				/**< interrupt request enable */
} T_iotINTEnable;

/**
 * 	@brief		Defined enumerated type for IOT interrupt request.
 */
typedef enum {
	IOT_IRQ_CLEARED,			/**< clear IOT interrupt request */
	IOT_IRQ_OVERFLOWED			/**< counter overflow generated */
} T_iotIRQ;

/* ----------------------------------------------------------------------------
**	IO Timer Register Getters and Setters.
*/

/**
 *	@def		GetIOT_TCCS
 *	@brief		IOT Control Status Register Getter.
 * 	@param 		.
 * 	@return		TCCS (byte).
 */
#define GetIOT_TCCS()			GetIOREGByte(IO_TCCS)

/**
 *	@def		GetIOT_TCDT
 *	@brief		IOT Counter Data Getter.
 * 	@param 		.
 * 	@return		TCDT (word).
 */
#define GetIOT_TCDT()			GetIOREG(IO_TCDT)

/**
 *	@def		SetIOT_TCCS
 *	@brief		IOT Control Status Register Setter.
 * 	@param[in] 	VAL		Control bits for TCCS (byte).
 * 	@return		.
 */
#define SetIOT_TCCS(VAL) { \
	SetIOREGByte(IO_TCCS, VAL); \
}

/**
 *	@def		SetIOT_TCDT
 *	@brief		IOT Counter Data Setter.
 * 	@param[in] 	VAL		Reload value for TCDT (word).
 * 	@return		.
 */
#define SetIOT_TCDT(VAL) { \
	SetIOREG(IO_TCDT, (T_word)(VAL)); \
}

/* ----------------------------------------------------------------------------
**	IO Timer Register Fields Macro Functions.
*/

/**
 *	@def		SetIOTCountClock
 *	@brief		Count Clock Setter.
 * 	@param[in] 	VAL		Count clock (bits).
 * 	@return		.
 */
#define SetIOTCountClock(VAL) { \
	SetIOREGBitVar(IO_TCCS, CLK, VAL); \
}

/**
 *	@def		ClearIOTCounter
 *	@brief		Clear Timer Count.
 * 	@param 		.
 * 	@return		.
 */
#define ClearIOTCounter() { \
	SetIOREGBitVar(IO_TCCS, CLR, IOT_CLEAR_CTR); \
}

/**
 *	@def		StartIOT
 *	@brief		Start Freerun Timer.
 * 	@param 		.
 * 	@return		.
 */
#define StartIOT() { \
	SetIOREGBitVar(IO_TCCS, STOP, IOT_CNT_ENABLED); \
}

/**
 *	@def		StopIOT
 *	@brief		Stop Freerun Timer.
 * 	@param 		.
 * 	@return		.
 */
#define StopIOT() { \
	SetIOREGBitVar(IO_TCCS, STOP, IOT_CNT_DISABLED); \
}

/**
 *	@def		EnableIOTInterrupt
 *	@brief		Interrupt Enabler.
 * 	@param 		.
 * 	@return		.
 */
#define EnableIOTInterrupt() { \
	SetIOREGBitVar(IO_TCCS, IVFE, IOT_INT_ENABLED); \
}

/**
 *	@def		DisableIOTInterrupt
 *	@brief		Interrupt Disabler.
 * 	@param 		.
 * 	@return		.
 */
#define DisableIOTInterrupt() { \
	SetIOREGBitVar(IO_TCCS, IVFE, IOT_INT_DISABLED); \
}

/**
 *	@def		ClearIOTIRQ
 *	@brief		Clear Interrupt Overflow.
 * 	@param 		.
 * 	@return		.
 */
#define ClearIOTIRQ() { \
	SetIOREGBitVar(IO_TCCS, IVF, IOT_IRQ_CLEARED); \
}

#endif /* IOT_IO_H. */
