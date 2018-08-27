/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Number to String Conversion											     */
/**
 *	@file		toString.h
 *	@brief		This file contains API functions of base 10 integer,
 *				base 16 integer and	single precision floating point for
 *				conversion to null-terminated character string.
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

#ifndef TOSTRING_H
#define TOSTRING_H

#include <LIB/charTypes.h>

/* ----------------------------------------------------------------------------
**	API Functions.
*/

/**
 *	@fn 		size_t hex32ToStr(T_char*, const T_char*,
 *					const T_char*, T_uint32)
 *	@brief 		Converts a base 16 number into a null terminated character
 *  			string with prefix and/or postfix hexadecimal symbol.
 *	@details	The number to be converted can only be represented in
 *				unsigned format for hexadecimal only.
 *	@param[in]	buffer	Pointer to the destination character array.
 *	@param[in]	prefix	Appended hexadecimal symbol before number.
 *	@param[in]	postfix	Appended hexadecimal symbol after number.
 *	@param[in]	number	The number to convert (dword).
 *	@return		number of printed characters (word).
 */
extern size_t hex32ToStr(T_char* buffer, const T_char* prefix,
	const T_char* postfix, T_uint32 number);

/**
 *	@fn 		size_t int32ToStr(T_char*, T_sint32, T_bit)
 *	@brief 		Converts a base 10 number into a null terminated character
 *  			string with signed / unsigned option.
 *	@details	The number to be converted can be represented either in signed
 *  			(1) or unsigned (0) format for decimal only.
 *	@param[in]	buffer	Pointer to the destination character array.
 *	@param[in]	number	The number to convert (dword).
 *	@param[in]	sign	Signed or unsigned option (bit).
 *	@return		number of printed characters (word).
 */
extern size_t int32ToStr(T_char* buffer, T_sint32 number, T_bit sign);

/**
 *	@fn 		size_t flt32ToStr(T_char*, T_float32)
 *	@brief 		Converts a single precision floating-point number
 *  			into a null terminated character string.
 *	@details	Precision applies in converting float number to string.
 *  			Its significand has a precision of 24 bits (about 7 decimal
 *  			digits), however only up to 6 digits after the decimal is
 *  			converted. If a number is too large or small, engineering
 *  			or scientific notation also applies in conversion but only
 *  			applicable if base 10 exponent (n) reaches -7 or 9 with 1
 *  			significand (m) (m x 10^n).
 *	@param[in]	buffer	Pointer to the destination character array.
 *	@param[in]	number	The floating number to convert (float).
 *	@return		number of printed characters (word).
 *	@note		This function also checks whether the number is NaN, +Inf
 *  			or -Inf and has corresponding string for each.
 */
extern size_t flt32ToStr(T_char* buffer, T_float32 number);

#endif /* TOSTRING_H. */
