/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Delayed Interrupt Generation									             */
/**
 *	@file		IO/dig_io.h
 *	@brief		This file contains types, getters and setters, and other
 * 				macro functions for DIG IO register.
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

#ifndef DIG_IO_H
#define DIG_IO_H

#include <IO/io_mb90385.h>

/* ----------------------------------------------------------------------------
**	DIG IO Types.
*/

/**
 * 	@brief		Defined enumerated type for DIG interrupt request.
 */
typedef enum {
	DIG_IRQ_CLEARED,			/**< cancels DIG interrupt request */
	DIG_IRQ_ENABLED				/**< generates delayed interrupt request */
} T_digIRQ;

/* ----------------------------------------------------------------------------
**	DIG IO Registers Getters and Setters.
*/

/**
 *	@def 		GetDIG_DIRR
 *	@brief 		DIG Request Generate/Cancel Register Getter.
 * 	@param		.
 * 	@return		R0 bit of DIRR (byte).
 */
#define GetDIG_DIRR()			GetIOREGByte(IO_DIRR)

/**
 *	@def 		SetDIG_DIRR
 *	@brief 		DIG Request Generate/Cancel Register Setter.
 * 	@param		VAL		DIG enable / disable bit (bit).
 * 	@return		.
 */
#define SetDIG_DIRR(VAL) { \
	SetIOREGByte(IO_DIRR, VAL); \
}

/* ----------------------------------------------------------------------------
**	DIG IO Register Fields Macro Functions.
*/

/**
 *	@def 		RequestDIG
 *	@brief 		Generate delayed interrupt request.
 * 	@param		.
 * 	@return		.
 */
#define RequestDIG() { \
	SetIOREGBitVar(IO_DIRR, R0, DIG_IRQ_ENABLED); \
}

/**
 *	@def 		ClearDIG
 *	@brief 		Clear delayed interrupt generated.
 * 	@param		.
 * 	@return		.
 */
#define ClearDIG() { \
	SetIOREGBitVar(IO_DIRR, R0, DIG_IRQ_CLEARED); \
}

#endif /* DIG_IO_H. */
