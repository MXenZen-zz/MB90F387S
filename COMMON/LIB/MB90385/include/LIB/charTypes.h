/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* C Character Classification and Conversion			       		         */
/**
 * 	@file 		LIB/chartypes.h
 *	@brief		This file is a derivation of C Standard Library's ctypes.h
 *				which declares several functions that are useful for testing
 *				[and mapping] characters. The character classification routines,
 *				however, are written as comparison tests and not written as
 *				static table lookups.
 * 	@note		All macro functions return 1 (true) if the argument CHAR
 * 				satisfies the condition described, and 0 (false) if not.
 * 	@warning	Parameters passed must be guaranteed to have no side-effect.
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

#ifndef CHARTYPES_H
#define CHARTYPES_H

#include <LIB/bitmanip.h>

/* ----------------------------------------------------------------------------
**	Some ASCII Characters.
*/

#define ASCII_NULL				(0x00)
#define ASCII_HT				(0x09)
#define ASCII_LF				(0x0A)
#define ASCII_VT				(0x0B)
#define ASCII_FF				(0x0C)
#define ASCII_CR				(0x0D)
#define ASCII_ESC				(0x1B)
#define ASCII_FS				(0x1C)
#define ASCII_GS				(0x1D)
#define ASCII_RS				(0x1E)
#define ASCII_US				(0x1F)
#define ASCII_SP				(0x20)
#define ASCII_MINUS				(0x2D)
#define ASCII_DOT				(0x2E)
#define ASCII_ZERO				(0x30)
#define ASCII_NINE				(0x39)
#define ASCII_A_UPPER			(0x41)
#define ASCII_F_UPPER			(0x46)
#define ASCII_Z_UPPER			(0x5A)
#define ASCII_A_LOWER			(0x61)
#define ASCII_F_LOWER			(0x66)
#define ASCII_Z_LOWER			(0x7A)
#define ASCII_DEL				(0x7F)
#define ASCII_MASK_UPPER		(0xDF)
#define ASCII_MASK_LOWER		(0x20)

/* ----------------------------------------------------------------------------
**	Macro Functions.
*/

/* classifications */

/**
 *  @def		IsBlank
 *  @brief 		Checks whether the passed character is a space or tab.
 *  @param[in]	CHAR 	character (byte).
 *	@return		Boolean.
 */
#define IsBlank(CHAR) \
	(EQU(CHAR, ASCII_SP) || EQU(CHAR, ASCII_HT))

/**
 *  @def		IsCntrl
 *  @brief 		Checks whether the passed character is control character.
 *  @param[in]	CHAR 	character (byte).
 *	@return		Boolean.
 */
#define IsCntrl(CHAR) \
	(WIN(CHAR, ASCII_NULL, ASCII_US) || EQU(CHAR, ASCII_DEL))

/**
 *  @def		IsDigit
 *  @brief 		Checks whether the passed character is decimal digit.
 *  @param[in]	CHAR 	character (byte).
 *	@return		Boolean.
 */
#define IsDigit(CHAR) \
	(WIN(CHAR, ASCII_ZERO, ASCII_NINE))

/**
 *  @def		IsHexLower
 *  @brief 		Checks whether the passed character is a hexadecimal
 *  			lowercase letter.
 *  @param[in]	CHAR 	character (byte).
 *	@return		Boolean.
 */
#define IsHexLower(CHAR) \
	(WIN(CHAR, ASCII_A_LOWER, ASCII_F_LOWER))

/**
 *  @def		IsHexUpper
 *  @brief 		Checks whether the passed character is a hexadecimal
 *  			uppercase letter.
 *  @param[in]	CHAR 	character (byte).
 *	@return		Boolean.
 */
#define IsHexUpper(CHAR) \
	(WIN(CHAR, ASCII_A_UPPER, ASCII_F_UPPER))

/**
 *  @def		IsLower
 *  @brief 		Checks whether the passed character is lowercase letter.
 *  @param[in]	CHAR 	character (byte).
 *	@return		Boolean.
 */
#define IsLower(CHAR) \
	(WIN(CHAR, ASCII_A_LOWER, ASCII_Z_LOWER))

/**
 *  @def		IsUpper
 *  @brief 		Checks whether the passed character is an uppercase letter.
 *  @param[in]	CHAR 	character (byte).
 *	@return		Boolean.
 */
#define IsUpper(CHAR) \
	(WIN(CHAR, ASCII_A_UPPER, ASCII_Z_UPPER))

/**
 *  @def		IsPunct
 *  @brief 		Checks whether the passed character is a punctuation character.
 *  @param[in]	CHAR 	character (byte).
 *	@return		Boolean.
 */
#define IsPunct(CHAR) \
	( WIN(CHAR, 0x21, 0x2F) || WIN(CHAR, 0x3A, 0x40) \
		|| WIN(CHAR, 0x5B, 0x60) || WIN(CHAR, 0x7B, 0x7E) )

/**
 *  @def		IsSpace
 *  @brief 		Checks whether the passed character is white-space.
 *  @param[in]	CHAR 	character (byte).
 *	@return		Boolean.
 */
#define IsSpace(CHAR) \
	( EQU(CHAR, ASCII_SP) || EQU(CHAR, ASCII_HT) || EQU(CHAR, ASCII_LF) \
		|| EQU(CHAR, ASCII_HT) || EQU(CHAR, ASCII_FF) || EQU(CHAR, ASCII_CR) )

/* compound classifications */

/**
 *  @def		IsAlpha
 *  @brief 		Checks whether the passed character is alphabetic.
 *  @param[in]	CHAR 	character (byte).
 *	@return		Boolean.
 */
#define IsAlpha(CHAR) \
	(IsLower(CHAR) || IsUpper(CHAR))

/**
 *  @def		IsAlNum
 *  @brief 		Checks whether the passed character is alphanumeric.
 *  @param[in]	CHAR 	character (byte).
 *	@return		Boolean.
 */
#define IsAlNum(CHAR) \
	(IsDigit(CHAR) || IsAlpha(CHAR))

/**
 *  @def		IsGraph
 *  @brief 		Checks whether the passed character has
 *  			graphical representation using locale.
 *  @param[in]	CHAR 	character (byte).
 *	@return		Boolean.
 */
#define IsGraph(CHAR) \
	(IsAlNum(CHAR) || IsPunct(CHAR))

/**
 *  @def		IsPrint
 *  @brief 		Checks whether the passed character is printable.
 *  @param[in]	CHAR 	character (byte).
 *	@return		Boolean.
 */
#define IsPrint(CHAR) \
	(IsGraph(CHAR) || IsSpace(CHAR))

/**
 *  @def		IsXDigit
 *  @brief 		Checks whether the passed character is a hexadecimal digit.
 *  @param[in]	CHAR 	character (byte).
 *	@return		Boolean.
 */
#define IsXDigit(CHAR) \
	(IsDigit(CHAR) || IsHexUpper(CHAR) || IsHexLower(CHAR))

/* conversions */

/**
 *  @def		ToDecimal
 *  @brief 		Converts a character digit to decimal.
 *  @param[in]	CHAR 	character (byte).
 *	@return		decimal number (0 - 9), zero if out of range.
 */
#define ToDecimal(CHAR)	\
	(COND(IsDigit(CHAR), (CHAR - ASCII_ZERO), ASCII_NULL))

/**
 *  @def		ToDigit
 *  @brief 		Converts decimal to a character digit.
 *  @param[in]	NUM 	number (byte).
 *	@return		digit ('0' - '9').
 */
#define ToDigit(NUM) \
	(COND(IsDigit(NUM + ASCII_ZERO), (NUM + ASCII_ZERO), ASCII_ZERO))

/**
 *  @def		ToLower
 *  @brief 		Converts uppercase letters to lowercase.
 *  @param[in]	CHAR 	character (byte).
 *	@return		lowercase letters ('a' - 'z'), no change if out of range.
 */
#define ToLower(CHAR) \
	(COND(IsAlpha(CHAR), MaskOn(CHAR, ASCII_MASK_LOWER), (CHAR)))

/**
 *  @def		ToUpper
 *  @brief 		Converts lowercase letters to uppercase.
 *  @param[in]	CHAR 	character (byte).
 *	@return		uppercase letters ('A' - Z'), no change if out of range.
 */
#define ToUpper(CHAR) \
	(COND(IsAlpha(CHAR), MaskOff(CHAR, ASCII_MASK_UPPER), (CHAR)))

/**
 *  @def		ToXDecimal
 *  @brief 		Converts a character or digit to hexadecimal number.
 *  @param[in]	CHAR 	character (byte).
 *	@return		hexadecimal number (0 - 15), zero if out of range.
 */
#define ToXDecimal(CHAR) \
	( COND(IsDigit(CHAR), (CHAR - ASCII_ZERO), \
		(COND((IsHexUpper(CHAR)||IsHexLower(CHAR)), \
			(ToUpper(CHAR) - ASCII_A_UPPER + 0x0A), \
				ASCII_NULL))) )

/**
 *  @def		ToXLDigit
 *  @brief 		Converts hexadecimal to a character / digit with lowercase hexdigit.
 *  @param[in]	NUM 	number (byte).
 *	@return		digit ('0' - '9'), hexdigit ('a' - 'f'), zero if out of range.
 */
#define ToXLDigit(NUM) \
	( COND(IsDigit(NUM + ASCII_ZERO), (NUM + ASCII_ZERO), \
		(COND(IsHexLower(NUM + ASCII_A_LOWER - 0x0A), \
			(ToLower(NUM) + ASCII_A_LOWER - 0x0A), ASCII_ZERO))) )

/**
 *  @def		ToXUDigit
 *  @brief 		Converts hexadecimal to a character / digit with uppercase hexdigit.
 *  @param[in]	NUM 	number (byte).
 *	@return		digit ('0' - '9'), hexdigit ('A' - 'F'), zero if out of range.
 */
#define ToXUDigit(NUM) \
	( COND(IsDigit(NUM + ASCII_ZERO), (NUM + ASCII_ZERO), \
		(COND(IsHexUpper(NUM + ASCII_A_UPPER - 0x0A), \
			(ToUpper(NUM) + ASCII_A_UPPER - 0x0A), ASCII_ZERO))) )

#endif /* CHARTYPES_H. */
