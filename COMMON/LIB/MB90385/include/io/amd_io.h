/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Address Match Detection Function / ROM Correction		   		         */
/**
 *	@file		IO/amd_io.h
 *	@brief		This file contains types, getters and setters, and other
 * 				macro functions for AMD IO registers.
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

#ifndef AMD_IO_H
#define AMD_IO_H

#include <IO/io_mb90385.h>

/* ----------------------------------------------------------------------------
**	AMD IO Types.
*/

/**
 * 	@brief		Defined enumerated type for AMD control.
 */
typedef enum {
	AMD_DISABLE,				/**< disables address match detection */
	AMD_ENABLE					/**< enables address match detection */
} T_amdEnable;

/* ----------------------------------------------------------------------------
**	AMD IO Registers Getters and Setters.
*/

/**
 *	@def		GetAMD_PACSR
 *	@brief		Address Detection Control Register Getter.
 * 	@param 		.
 * 	@return		PACSR (byte).
 */
#define GetAMD_PACSR()			GetIOREGByte(IO_PACSR)

/**
 *	@def		SetAMD_PACSR
 *	@brief		Address Detection Control Register Setter.
 * 	@param[in] 	VAL		Control bits for PACSR (byte).
 * 	@return		.
 */
#define SetAMD_PACSR(VAL) { \
	SetIOREGByte(IO_PACSR, VAL); \
}

/* ----------------------------------------------------------------------------
**	AMD IO Register Fields Macro Functions.
*/

/**
 *	@def		EnableAMD0
 *	@brief		Enables address match detection in PADR0.
 * 	@param[in]	HADD 	23rd bit to 16th bit of address (byte).
 * 	@param[in]	MADD 	15th bit to 8th bit of address (byte).
 * 	@param[in]	LADD 	7th bit to 0th bit of address (byte).
 * 	@return		.
 */
#define EnableAMD0(HADD, MADD, LADD) { \
	SetIOREGBitVar(IO_PACSR, AD0E, AMD_DISABLE); \
	SetIOREGVar(IO_PADR[0], LOW, (T_byte)(LADD)); \
	SetIOREGVar(IO_PADR[0], MID, (T_byte)(MADD)); \
	SetIOREGVar(IO_PADR[0], HIGH, (T_byte)(HADD)); \
	SetIOREGBitVar(IO_PACSR, AD0E, AMD_ENABLE); \
}

/**
 *	@def		DisableAMD0
 *	@brief		Disables address match detection in PADR0.
 * 	@param		.
 * 	@return		.
 */
#define DisableAMD0() { \
	SetIOREGBitVar(IO_PACSR, AD0E, AMD_DISABLE); \
}

/**
 *	@def		EnableAMD1
 *	@brief		Enables address match detection in PADR1.
 * 	@param[in]	HADD 	23rd bit to 16th bit of address (byte).
 * 	@param[in]	MADD 	15th bit to 8th bit of address (byte).
 * 	@param[in]	LADD 	7th bit to 0th bit of address (byte).
 * 	@return		.
 */
#define EnableAMD1(HADD, MADD, LADD) { \
	SetIOREGBitVar(IO_PACSR, AD1E, AMD_DISABLE); \
	SetIOREGVar(IO_PADR[1], LOW, (T_byte)(LADD)); \
	SetIOREGVar(IO_PADR[1], MID, (T_byte)(MADD)); \
	SetIOREGVar(IO_PADR[1], HIGH, (T_byte)(HADD)); \
	SetIOREGBitVar(IO_PACSR, AD1E, AMD_ENABLE); \
}

/**
 *	@def		DisableAMD1
 *	@brief		Disables address match detection in PADR1.
 * 	@param		.
 * 	@return		.
 */
#define DisableAMD1() { \
	SetIOREGBitVar(IO_PACSR, AD1E, AMD_DISABLE); \
}

#endif /* AMD_IO_H. */
