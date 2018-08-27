/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* ROM Mirroring											   		         */
/**
 *	@file		IO/romm_io.h
 *	@brief		This file contains types, getters and setters, and other
 * 				macro functions for ROM Mirroring IO register.
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

#ifndef ROMM_IO_H
#define ROMM_IO_H

#include <IO/io_mb90385.h>

/* ----------------------------------------------------------------------------
**	ROMM IO Types.
*/

/**
 * 	@brief		Defined enumerated type for ROMM control.
 */
typedef enum {
	ROMM_DISABLE,				/**< ROM mirroring function disabled */
	ROMM_ENABLE					/**< ROM mirroring function enabled */
} T_mirEnable;

/* ----------------------------------------------------------------------------
**	ROMM IO Registers Getters and Setters.
*/

/**
 *	@def		GetROMM
 *	@brief		ROM Mirroring Function Select Register Getter.
 * 	@param 		.
 * 	@return		ROMM (byte).
 */
#define GetROMM()				GetIOREGByte(IO_ROMM)

/**
 *	@def		SetROMM
 *	@brief		ROM Mirroring Function Select Register Setter.
 * 	@param[in] 	VAL		Select bits for ROMM (byte).
 * 	@return		.
 */
#define SetROMM(VAL) { \
	SetIOREGByte(IO_ROMM, VAL); \
}

/* ----------------------------------------------------------------------------
**	ROMM IO Register Fields Macro Functions.
*/

/**
 *	@def		EnableROMM
 *	@brief		Enables ROM mirroring function.
 * 	@param		.
 * 	@return		.
 */
#define EnableROMM() { \
	SetIOREGBitVar(IO_ROMM, MI, ROMM_ENABLE); \
}


/**
 *	@def		DisableROMM
 *	@brief		Disables ROM mirroring function.
 * 	@param		.
 * 	@return		.
 */
#define DisableROMM() { \
	SetIOREGBitVar(IO_ROMM, MI, ROMM_DISABLE); \
}

#endif /* ROMM_IO_H. */
