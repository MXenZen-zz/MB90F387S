/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Flash Memory Control and Status							   		         */
/**
 *	@file		IO/flm_io.h
 *	@brief		This file contains types, getters and setters, and other
 * 				macro functions for Flash Memory IO register.
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

#ifndef FLM_IO_H
#define FLM_IO_H

#include <IO/io_mb90385.h>

/* ----------------------------------------------------------------------------
**	FLM IO Types.
*/

/**
 * 	@brief		Defined enumerated type for FLM programming/erasing enable.
 */
typedef enum {
	FLM_PROG_ERASE_DISABLED,	/**< programming/erasing flash memory area disabled */
	FLM_PROG_ERASE_ENABLED		/**< programming/erasing flash memory area enabled */
} T_flmProgEraseEnable;

/**
 * 	@brief		Defined enumerated type for FLM programming/erasing status
 * 				and operation flag.
 */
typedef enum {
	FLM_RDYINT_CLEARED = 0U,	/**< RDYINT bit cleared */
	FLM_PROGRAMMING    = 0U,	/**< programming (next data programming/erasing disabled) */
	FLM_ERASING        = 0U,	/**< erasing (next data programming/erasing disabled) */
	FLM_TERMINATED	   = 1U		/**< Programming/erasing terminated
	 	 	 	 	 	 	 	 	 (next data programming/erasing enabled) */
} T_flmOpStatus;

/**
 * 	@brief		Defined enumerated type for FLM programming/erasing interrupt enable.
 */
typedef enum {
	FLM_INT_DISABLED,			/**< interrupt disabled at end of programming/erasing */
	FLM_INT_ENABLED				/**< interrupt enabled at end of programming/erasing */
} T_flmINTEnable;

/* ----------------------------------------------------------------------------
**	FLM IO Registers Getters and Setters.
*/

/**
 *	@def		GetFLM_FMCS
 *	@brief		Flash Memory Control Status Register Getter.
 * 	@param 		.
 * 	@return		FLM (byte).
 */
#define GetFLM_FMCS()			GetIOREGByte(IO_FMCS)

/**
 *	@def		SetFLM_FMCS
 *	@brief		Flash Memory Control Status Register Setter.
 * 	@param[in] 	VAL		Control and Status bits for FLM (byte).
 * 	@return		.
 */
#define SetFLM_FMCS(VAL) { \
	SetIOREGByte(IO_FMCS, VAL); \
}

/* ----------------------------------------------------------------------------
**	FLM IO Register Fields Macro Functions.
*/

/**
 *	@def		IsFLMEnabled
 *	@brief		Checks if programming/erasing flash memory area is enabled.
 * 	@param		.
 * 	@return		.
 */
#define IsFLMEnabled() \
	EQU(GetIOREGBitVar(IO_FMCS, WE), FLM_PROG_ERASE_ENABLED)

/**
 *	@def		EnableFLM
 *	@brief		Enables programming/erasing flash memory area.
 * 	@param		.
 * 	@return		.
 */
#define EnableFLM() { \
	SetIOREGBitVar(IO_FMCS, WE, FLM_PROG_ERASE_ENABLED); \
}

/**
 *	@def		DisableFLM
 *	@brief		Disables programming/erasing flash memory area.
 * 	@param		.
 * 	@return		.
 */
#define DisableFLM() { \
	SetIOREGBitVar(IO_FMCS, WE, FLM_PROG_ERASE_DISABLED); \
}

/**
 *	@def 		EnableFLMInterrupt
 *	@brief 		Interrupt enabled at end of programming/erasing.
 * 	@param		.
 * 	@return		.
 */
#define EnableFLMInterrupt() { \
	SetIOREGBitVar(IO_FMCS, INTE, FLM_INT_ENABLED); \
}

/**
 *	@def 		DisableFLMInterrupt
 *	@brief 		Interrupt disabled at end of programming/erasing.
 * 	@param		.
 * 	@return		.
 */
#define DisableFLMInterrupt() { \
	SetIOREGBitVar(IO_FMCS, INTE, FLM_INT_DISABLED); \
}

/**
 *	@def		IsFLMStatusProgramming
 *	@brief		Checks if programming or next data programming/erasing disabled.
 * 	@param		.
 * 	@return		.
 */
#define IsFLMStatusProgramming() \
	EQU(GetIOREGBitVar(IO_FMCS, RDY), FLM_PROGRAMMING)

/**
 *	@def		IsFLMStatusErasing
 *	@brief		Checks if erasing or next data programming/erasing disabled.
 * 	@param		.
 * 	@return		.
 */
#define IsFLMStatusErasing() \
	EQU(GetIOREGBitVar(IO_FMCS, RDY), FLM_ERASING)

/**
 *	@def		IsFLMStatusTerminated
 *	@brief		Checks if programming/erasing is terminated or next data
 *				programming/erasing enabled.
 * 	@param		.
 * 	@return		.
 */
#define IsFLMStatusTerminated() \
	EQU(GetIOREGBitVar(IO_FMCS, RDY), FLM_TERMINATED)

/**
 *	@def		IsFLMOperationProgramming
 *	@brief		Checks if operation is programming.
 * 	@param		.
 * 	@return		.
 */
#define IsFLMOperationProgramming() \
	EQU(GetIOREGBitVar(IO_FMCS, RDYINT), FLM_PROGRAMMING)

/**
 *	@def		IsFLMOperationErasing
 *	@brief		Checks if operation is erasing.
 * 	@param		.
 * 	@return		.
 */
#define IsFLMOperationErasing() \
	EQU(GetIOREGBitVar(IO_FMCS, RDYINT), FLM_ERASING)

/**
 *	@def		IsFLMOperationTerminated
 *	@brief		Checks if operation is programming/erasing terminated.
 * 	@param		.
 * 	@return		.
 */
#define IsFLMOperationTerminated() \
	EQU(GetIOREGBitVar(IO_FMCS, RDYINT), FLM_TERMINATED)

/**
 *	@def 		ClearFLMOperationFlag
 *	@brief 		Clear RDYINT bit.
 * 	@param		.
 * 	@return		.
 */
#define ClearFLMOperationFlag() { \
	SetIOREGBitVar(IO_FMCS, RDYINT, FLM_RDYINT_CLEARED); \
}

#endif /* FLM_IO_H. */
