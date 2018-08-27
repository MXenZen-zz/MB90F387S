/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Platform Types		 								       		         */
/**
 * 	@file 		LIB/platformtypes.h
 *	@brief		This file contains platform types and type limits.
 */
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
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * Target Hardware Information:
 *
 * Number of bits	:
 * 		bool		: 1 (not supported)
 *		char		: 8
 *		short		: 16
 *		int			: 16
 *		long		: 32
 *		float		: 32 (IEEE 754)
 *		double		: 64 (IEEE 754)
 *		long long	: 64 (not supported)
 *
 * Native word size : 8 or 16
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#ifndef PLATFORMTYPES_H
#define PLATFORMTYPES_H

/* ----------------------------------------------------------------------------
**	Platform Defines.
*/

/* register widths */
#define CPU_TYPE_8 				(8)
#define CPU_TYPE_16 			(16)
#define CPU_TYPE_32 			(32)

/* bit order endianess */
#define MSB_FIRST 				(0)
#define LSB_FIRST 				(1)

/* byte order endianess */
#define HIGH_BYTE_FIRST 		(0)
#define LOW_BYTE_FIRST 			(1)

/* boolean */
#ifndef FALSE
#define FALSE					(0)
#endif
#ifndef TRUE
#define TRUE					(1)
#endif

/* ----------------------------------------------------------------------------
**	CPU Symbols.
*/

/**
 *  @def		CPU_TYPE
 *  @brief		Register width of CPU (16-bit).
 */
#define CPU_TYPE 				CPU_TYPE_16

/**
 *  @def		CPU_BIT_ORDER
 *  @brief		Bit order of CPU (Little Endian).
 */
#define CPU_BIT_ORDER 			LSB_FIRST

/**
 *  @def		CPU_BYTE_ORDER
 *  @brief		Byte order of CPU (Little Endian).
 */
#define CPU_BYTE_ORDER 			LOW_BYTE_FIRST

/* ----------------------------------------------------------------------------
**	Types Definitions.
*/

/* void type */

/**
 *  @brief		Defined type for void.
 */
typedef void					T_void;

/* boolean type */

/**
 *  @brief		Defined type for boolean (TRUE, FALSE) values only.
 */
typedef unsigned char 			T_bool;

/* literal type */

/**
 *  @brief		Defined type for ASCII characters.
 */
typedef char 					T_char;

/* integral types */

/**
 *  @brief		Defined type for 8-bit signed integer.
 */
typedef signed char				T_sint8;

/**
 *  @brief		Defined type for 8-bit unsigned integer.
 */
typedef unsigned char			T_uint8;

/**
 *  @brief		Defined type for 16-bit signed integer.
 */
typedef signed short			T_sint16;

/**
 *  @brief		Defined type for 16-bit unsigned integer.
 */
typedef unsigned short			T_uint16;

/**
 *  @brief		Defined type for 32-bit signed integer.
 */
typedef signed long				T_sint32;

/**
 *  @brief		Defined type for 32-bit unsigned integer.
 */
typedef unsigned long			T_uint32;

/* float types */

/**
 *  @brief		Defined type for single-precision floating-point (IEEE 754).
 */
typedef float					T_float32;

/**
 *  @brief		Defined type for double-precision floating-point (IEEE 754).
 */
typedef double					T_float64;

/* ----------------------------------------------------------------------------
**	Limits.
*/

/* min and max of any unsigned integral type */
#define MIN_UINT(CAST)			((CAST)( 0UL))
#define MAX_UINT(CAST)			((CAST)(~0UL))

/* min and max of any signed integral types */
#define MIN_SINT(CAST)			((CAST)( (1UL << ((8U * sizeof(CAST)) - 1U))))
#define MAX_SINT(CAST)			((CAST)(~(1UL << ((8U * sizeof(CAST)) - 1U))))

/* min, max and nan unsigned integral representation for floating types */
#define MIN_FLOAT				(0xFF800000UL)
#define MAX_FLOAT				(0x7F800000UL)
#define NAN_FLOAT				(0x7FF00000UL)

#endif /* PLATFORMTYPES_H. */
