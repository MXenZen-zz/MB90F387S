/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Standard Types		 								       		         */
/**
 * 	@file 		LIB/stdtypes.h
 *	@brief		This file contains standard types and macro definitions.
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
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#ifndef STDTYPES_H
#define STDTYPES_H

#include <LIB/compiler.h>
#include <LIB/platformtypes.h>

/* ----------------------------------------------------------------------------
**	Standard Defines.
*/

/**
 *  @def 		STD_NOK
 *  @brief 		Not ok state.
 */
#define STD_NOK 				(0U)

/**
 *  @def 		STD_OK
 *  @brief 		Ok state.
 */
#define STD_OK 					(1U)

/**
 *  @def 		STD_LOW
 *  @brief 		Physical state 0V.
 */
#define STD_LOW 				(0U)

/**
 *  @def 		STD_HIGH
 *  @brief 		Physical state 5V or 3.3V.
 */
#define STD_HIGH 				(1U)

/**
 *  @def 		STD_IDLE
 *  @brief 		Logical state idle.
 */
#define STD_IDLE 				(0U)

/**
 *  @def 		STD_ACTIVE
 *  @brief 		Logical state active.
 */
#define STD_ACTIVE 				(1U)

/**
 *  @def 		STD_OFF
 *  @brief 		Positive logic off.
 */
#define STD_OFF 				(0U)

/**
 *  @def 		STD_ON
 *  @brief 		Positive logic on.
 */
#define STD_ON					(1U)

/**
 *  @def 		STD_ON
 *  @brief 		Clear interrupt flag.
 */
#define STD_CLEAR				(0U)

/* ----------------------------------------------------------------------------
**	Types Definitions.
*/

/* unit types */

/**
 *  @brief		Bit (1-bit) is unsigned 8-bit contained.
 */
typedef T_bool					T_bit;

/**
 *  @brief		Pair (2-bit) is unsigned 8-bit contained.
 */
typedef T_uint8					T_pair;

/**
 *  @brief		Nibble (4-bit) is unsigned 8-bit contained.
 */
typedef T_uint8					T_nib;

/**
 *  @brief		Byte is unsigned 8 bits wide.
 */
typedef T_uint8					T_byte;

/**
 *  @brief		Word is unsigned 16 bits wide.
 */
typedef T_uint16				T_word;

/**
 *  @brief		Double-word is unsigned 32 bits wide.
 */
typedef T_uint32				T_dword;

/* alias integral types */

/**
 *  @brief		Alias 8-bit signed integer type.
 */
typedef T_sint8					T_s8;

/**
 *  @brief		Alias 8-bit unsigned integer type.
 */
typedef T_uint8					T_u8;

/**
 *  @brief		Alias 16-bit signed integer type.
 */
typedef T_sint16				T_s16;

/**
 *  @brief		Alias 16-bit unsigned integer type.
 */
typedef T_uint16				T_u16;

/**
 *  @brief		Alias 32-bit signed integer type.
 */
typedef T_sint32				T_s32;

/**
 *  @brief		Alias 32-bit unsigned integer type.
 */
typedef T_uint32				T_u32;

/* alias float types */

/**
 *  @brief		Alias single-precision floating-point type.
 */
typedef T_float32				T_f32;

/**
 *  @brief		Alias double-precision floating-point type.
 */
typedef T_float64				T_f64;

#endif /* STDTYPES_H. */
