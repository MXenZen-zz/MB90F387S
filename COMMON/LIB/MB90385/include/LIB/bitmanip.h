/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Bitwise Operations, Bit Twiddlings and Other Bit Manipulations	         */
/**
 * 	@file 		LIB/bitmanip.h
 *	@brief		This file contains macro definitions such as masks, positions
 *				and sizes, and macro functions such as conditional evaluators,
 *				bitwise operations, bit read and write, and multibit getters
 *				and setters.
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

#ifndef BITMANIP_H
#define BITMANIP_H

#include <LIB/stdtypes.h>

/* ----------------------------------------------------------------------------
**	Masks.
*/

#define Mask_(MSK)				(MSK)
#define Mask_BIT				(0x00000001UL)
#define Mask_PAIR				(0x00000003UL)
#define Mask_NIB				(0x0000000FUL)
#define Mask_BYTE				(0x000000FFUL)
#define Mask_WORD				(0x0000FFFFUL)
#define Mask_24BIT				(0x00FFFFFFUL)
#define Mask_DWORD				(0xFFFFFFFFUL)
#define Mask_HPNIB				(0x0000000CUL)
#define Mask_HPBYTE				(0x000000C0UL)
#define Mask_HNBYTE				(0x000000F0UL)
#define Mask_HPWORD				(0x0000C000UL)
#define Mask_HNWORD				(0x0000F00FUL)
#define Mask_HBWORD				(0x0000FF00UL)
#define Mask_HN24BIT			(0x00C00000UL)
#define Mask_HP24BIT			(0x00F00000UL)
#define Mask_HB24BIT			(0x00FF0000UL)
#define Mask_HW24BIT			(0x00FFFF00UL)
#define Mask_HPDWORD			(0xC0000000UL)
#define Mask_HNDWORD			(0xF000000FUL)
#define Mask_HBDWORD			(0xFF000000UL)
#define Mask_HWDWORD			(0xFFFF0000UL)

/* ----------------------------------------------------------------------------
**	Positions.
*/

#define PosX_(POS)				(POS)
#define PosX_BASE				(0x00U)
#define PosX_LEAST				(0x00U)
#define PosB_MSBIT				(0x07U)
#define PosB_MSPAIR				(0x03U)
#define PosB_MSNIB				(0x01U)
#define PosW_MSBIT				(0x0FU)
#define PosW_MSPAIR				(0x07U)
#define PosW_MSNIB				(0x03U)
#define PosW_MSBYTE				(0x01U)
#define PosDW_MSBIT				(0x1FU)
#define PosDW_MSPAIR			(0x0FU)
#define PosDW_MSNIB				(0x07U)
#define PosDW_MSBYTE			(0x03U)
#define PosDW_MSWORD			(0x01U)

/* ----------------------------------------------------------------------------
**	Sizes.
*/

/* in bits */
#define SzBits_BIT				(0x01U)
#define SzBits_PAIR				(0x02U)
#define SzBits_NIB				(0x04U)
#define SzBits_BYTE				(0x08U)
#define SzBits_WORD				(0x10U)
#define SzBits_DWORD			(0x20U)
#define SzBits_(VAR)			(sizeof(VAR) * 8U)

/* in nibbles */
#define SzNibs_NIB				(0x01U)
#define SzNibs_BYTE				(0x02U)
#define SzNibs_WORD				(0x04U)
#define SzNibs_DWORD			(0x08U)
#define SzNibs_(VAR)			(sizeof(VAR) * 2U)

/* in bytes */
#define SzBytes_BYTE			(0x01U)
#define SzBytes_WORD			(0x02U)
#define SzBytes_DWORD			(0x04U)
#define SzBytes_(VAR)			(sizeof(VAR))

/* in words */
#define SzWords_WORD			(0x01U)
#define SzWords_DWORD			(0x02U)
#define SzWords_(VAR)			(sizeof(VAR) / 2U)

/* in dwords */
#define SzDWords_DWORD			(0x01U)
#define SzDWords_(VAR)			(sizeof(VAR) / 4U)

/* in arrays (bytes) */
#define SzArray_(ELM, TYP)		(sizeof(TYP) * (ELM))
#define SzElems_(VAR, TYP)		(sizeof(VAR) / sizeof(TYP))
#define SzIndices_(VAR)			(sizeof(VAR) / sizeof((VAR)[0U]))

/* ----------------------------------------------------------------------------
**	Conditions.
*/

/**
 *  @def 		NOT
 *  @brief 		Logical negation.
 *  @param[in]	EXPR 	variable, expression, primary input (or source).
 *	@return		Boolean.
 */
#define NOT(EXPR)				(!(EXPR))

/**
 *  @def 		IS
 *  @brief 		Logical double negation (weak affirmative).
 *  @param[in]	EXPR 	variable, expression, primary input (or source).
 *	@return		Boolean.
 */
#define IS(EXPR)				(!!(EXPR))

/**
 *  @def 		EQU
 *  @brief 		Checks whether the equality expression is true.
 *  @param[in]	LHS		variable, function, primary input (or source).
 *  @param[in]	RHS		variable, function, boolean, status or numeric value.
 *	@return		Boolean.
 */
#define EQU(LHS, RHS)			((LHS) == (RHS))

/**
 *  @def 		NEQ
 *  @brief 		Checks whether the inequality expression is true.
 *  @param[in]	LHS		variable, function, primary input (or source).
 *  @param[in]	RHS		variable, function, boolean, status or numeric value.
 *	@return		Boolean.
 */
#define NEQ(LHS, RHS)			((LHS) != (RHS))

/**
 *  @def 		LT
 *  @brief 		Checks whether LHS is lesser than RHS.
 *  @param[in]	LHS		variable, function, primary input (or source).
 *  @param[in]	RHS		variable, function, boolean, status or numeric value.
 *	@return		Boolean.
 */
#define LT(LHS, RHS)			((LHS) < (RHS))

/**
 *  @def 		GT
 *  @brief 		Checks whether LHS is greater than RHS.
 *  @param[in]	LHS		variable, function, primary input (or source).
 *  @param[in]	RHS		variable, function, boolean, status or numeric value.
 *	@return		Boolean.
 */
#define GT(LHS, RHS)			((LHS) > (RHS))

/**
 *  @def 		LEQ
 *  @brief 		Checks whether LHS is lesser than or equal to RHS.
 *  @param[in]	LHS		variable, function, primary input (or source).
 *  @param[in]	RHS		variable, function, boolean, status or numeric value.
 *	@return		Boolean.
 */
#define LEQ(LHS, RHS)			((LHS) <= (RHS))

/**
 *  @def 		GEQ
 *  @brief 		Checks whether LHS is greater than or equal to RHS.
 *  @param[in]	LHS		variable, function, primary input (or source).
 *  @param[in]	RHS		variable, function, boolean, status or numeric value.
 *	@return		Boolean.
 */
#define GEQ(LHS, RHS)			((LHS) >= (RHS))

/**
 *  @def		WIN
 *  @brief 		Checks whether VAL is "within" the range from LST
 *				(the least value, greater than or equal) to GRT
 *				(the greatest value, lesser than or equal).
 *	@attention	The macro function evaluates parameter(s) (more than) twice.
 *				Ensure that the parameter(s) passed will not yield side effects.
 *  @param[in]	AMT  	number being compared.
 *  @param[in]	LVAL 	lower limit or the least value (number to compare with).
 *  @param[in]	HVAL 	upper limit or the greatest value (number to compare with).
 *	@return		Boolean.
 *	@see		LIM
 */
#define WIN(AMT, LVAL, HVAL)	((((AMT) >= (LVAL)) && ((AMT) <= (HVAL))))

/**
 *  @def 		COND
 *  @brief 		Evaluates EXPR and returns the value of HVAL
 *  			if EXPR is true, or LVAL, otherwise.
 *  @param[in]	EXPR conditional expression.
 *  @param[in]	HVAL 	value if EXPR is true.
 *  @param[in]	LVAL 	value if EXPR is false.
 *  @return		Either HVAL or LVAL.
 */
#define COND(EXPR, HVAL, LVAL) 	(!!(EXPR) ? (HVAL) : (LVAL))

/**
 *  @def 		MIN
 *  @brief 		Compares two values and returns the least value among them.
 *	@attention	The macro function evaluates parameter(s) (more than) twice.
 *				Ensure that the parameter(s) passed will not yield side effects.
 *  @param[in]	LHS		number being compared.
 *  @param[in]	RHS		number to compare with.
 *  @return		Either LHS or RHS.
 */
#define MIN(LHS, RHS) 			(((LHS) < (RHS)) ? (LHS) : (RHS))

/**
 *  @def 		MAX
 *  @brief 		Compares two values and returns the greatest value among them.
 *	@attention	The macro function evaluates parameter(s) (more than) twice.
 *				Ensure that the parameter(s) passed will not yield side effects.
 *  @param[in]	LHS		number being compared.
 *  @param[in]	RHS		number to compare with.
 *  @return		Either LHS or RHS.
 */
#define MAX(LHS, RHS) 			(((LHS) > (RHS)) ? (LHS) : (RHS))

/**
 *  @def		LIM
 *  @brief 		Compares the amount to its bounds and returns either
 *  			(a) the	upper limit if the amount is greater than the range,
 *  			(b) the lower limit if the amount is lesser than the range, or
 *  			(c) the amount itself if within range.
 *	@attention	The macro function evaluates parameter(s) (more than) twice.
 *				Ensure that the parameter(s) passed will not yield side effects.
 *  @param[in]	AMT  	number being compared.
 *  @param[in]	LVAL 	lower limit, bound or value (number to compare with).
 *  @param[in]	HVAL 	upper limit, bound or value (number to compare with).
 *  @return		Either AMT, HVAL or LVAL.
 *  @see		WIM
 */
#define LIM(AMT, LVAL, HVAL) \
	(((AMT) < (LVAL)) ? (LVAL) : (((AMT) > (HVAL)) ? (HVAL) : (AMT)))

/* ----------------------------------------------------------------------------
**	Bitwise Operations.
*/

/**
 *  @def 		Invert
 *  @brief 		Turn all bits to their complement.
 *  @param[in]	VAR		primary input (or source).
 *	@return		(~VAR).
 */
#define Invert(VAR)				(~(VAR))

/**
 *  @def 		Toggle
 *  @brief 		Turn certain bits ON from OFF or OFF from ON by 1's in ALT
 * 				or leave certain bits unchanged by 0's in ALT.
 *  @param[in]	VAR		primary input (or source).
 *  @param[in]	ALT		bit(s) to toggle by XORing.
 *	@return		(VAR ^ ALT).
 */
#define Toggle(VAR, ALT)		((VAR) ^ (ALT))

/**
 *  @def 		MaskOff
 *  @brief 		Turn certain bits OFF by 0's in MASK or leave certain bits
 *  			unchanged by 1's in MASK.
 *  @param[in]	VAR		primary input (or source).
 *	@param[in]	MASK	bit(s) to masked off by ANDing.
 *	@return		(VAR & MASK).
 */
#define MaskOff(VAR, MASK)		((VAR) & (MASK))

/**
 *  @def 		MaskOn
 *  @brief 		Turn certain bits ON by 1's in MASK or leave certain bits
 *  			unchanged by 0's in MASK.
 *  @param[in]	VAR		primary input (or source).
 *	@param[in]	MASK	bit(s) to masked on by ORing.
 *	@return		(VAR | VAL).
 */
#define MaskOn(VAR, MASK)		((VAR) | (MASK))

/**
 *  @def 		Mask
 *  @brief 		Generates mask - turn consecutive bits ON by 1's based on
 *  			starting and ending bit position.
 *  @param[in]	HBIT	High, end bit position (GEQ to LBIT but LT WIDTH).
 *	@param[in]	LBIT	Low, start bit position (starts with 0).
 *	@return		(((~0UL) >> (31U - HBIT)) & ~((1UL << LBIT) - 1U)).
 */
#define Mask(HBIT, LBIT) \
	(((~0UL) >> (31U - (HBIT))) & (~(((1UL) << (LBIT)) - 1U)))

/**
 *  @def 		FlipFlop
 *  @brief 		JK flip-flop (or latch operation).
 *	@attention	The macro function evaluates parameter(s) (more than) twice.
 *				Ensure that the parameter(s) passed will not yield side effects.
 *  @param[in]	Q		current state(s).
 *  @param[in]	J		J-bits.
 *  @param[in]	K		K-bits.
 *  @return		((J & ~Q) | (~K & Q)).
 *  @note		Refer to JK transition table.
 *  @deprecated	Use conditional evaluators instead.
 */
#define FlipFlop(Q, J, K)		(((J) & (~Q)) | ((~K) & (Q)))

/**
 *  @def 		LShift
 *  @brief 		Performs arithmetic left shift operation.
 *  @param[in]	VAR		primary input (or source).
 *  @param[in]	POS		shift count or position.
 *	@return		(VAR << POS).
 */
#define LShift(VAR, POS)		((VAR) << (POS))

/**
 *  @def 		RShift
 *  @brief 		Performs arithmetic right shift operation.
 *  @param[in]	VAR		primary input (or source).
 *  @param[in]	POS		shift count or position.
 *	@return		(VAR >> POS).
 */
#define RShift(VAR, POS)		((VAR) >> (POS))

/**
 *  @def 		RollOnLeft
 *  @brief 		Perform left circular shift.
 *	@attention	The macro function evaluates parameter(s) (more than) twice.
 *				Ensure that the parameter(s) passed will not yield side effects.
 *  @param[in]	VAR		primary input.
 *  @param[in]	COUNT	roll count.
 *	@return		(VAR << COUNT | VAR >> (SzBits_(VAR) - COUNT)).
 */
#define RollOnLeft(VAR, COUNT) \
	(((VAR) << (COUNT)) | ((VAR) >> ((8U * sizeof(VAR)) - (COUNT))))

/**
 *  @def 		RollOnRight
 *  @brief 		Perform right circular shift.
 *	@attention	The macro function evaluates parameter(s) (more than) twice.
 *				Ensure that the parameter(s) passed will not yield side effects.
 *  @param[in]	VAR		primary input.
 *  @param[in]	COUNT	roll count.
 *	@return		(VAR >> COUNT | VAR << (SzBits_(VAR) - COUNT)).
 */
#define RollOnRight(VAR, COUNT) \
	(((VAR) >> (COUNT)) | ((VAR) << ((8U * sizeof(VAR)) - (COUNT))))

/**
 *  @def 		ReversePair
 *  @brief 		Reverses pair bit order.
 *  @param[in]	SRC		primary input or source.
 *	@return   	2-bit reversed.
 */
#define ReversePair(SRC) \
	((T_pair)(((SRC) == (0x00U)) || ((SRC) == (0x03U))) ? (SRC) \
		: (((SRC) == (0x01U)) ? (0x02U) : (0x01U)))

/**
 *  @def 		ReverseNibble
 *  @brief 		Reverses nibble bit order.
 *  @param[in]	SRC		primary input or source.
 *	@return   	4-bit reversed.
 */
#define ReverseNibble(SRC) \
	((T_nib)(ReversePair(((SRC) & Mask_HPNIB) >> SzBits_PAIR)) \
		| (((T_nib)ReversePair((SRC) & Mask_PAIR)) << SzBits_PAIR))

/**
 *  @def 		ReverseByte
 *  @brief 		Reverses byte bit order.
 *	@attention	The macro function evaluates parameter(s) (more than) twice.
 *				Ensure that the parameter(s) passed will not yield side effects.
 *  @param[in]	SRC		primary input or source.
 *	@return   	8-bit reversed.
 */
#define ReverseByte(SRC) \
	((T_byte)(ReverseNibble(((SRC) & Mask_HNBYTE) >> SzBits_NIB)) \
		| (((T_byte)ReverseNibble((SRC) & Mask_NIB)) << SzBits_NIB))

/**
 *  @def 		ReverseWord
 *  @brief 		Reverses word bit order.
 *	@attention	The macro function evaluates parameter(s) (more than) twice.
 *				Ensure that the parameter(s) passed will not yield side effects.
 *  @param[in]	SRC		primary input or source.
 *	@return   	16-bit reversed.
 */
#define ReverseWord(SRC) \
	((T_word)(ReverseByte(((SRC) & Mask_HBWORD) >> SzBits_BYTE)) \
		| (((T_word)ReverseByte((SRC) & Mask_BYTE)) << SzBits_BYTE))

/**
 *  @def 		ReverseDWord
 *  @brief 		Reverses dword bit order.
 *	@attention	The macro function evaluates parameter(s) (more than) twice.
 *				Ensure that the parameter(s) passed will not yield side effects.
 *  @param[in]	SRC		primary input or source.
 *	@return   	32-bit reversed.
 */
#define ReverseDWord(SRC) \
	((T_dword)(ReverseWord(((SRC) & Mask_HWDWORD) >> SzBits_WORD)) \
		| (((T_dword)ReverseWord((SRC) & Mask_WORD)) << SzBits_WORD))

/**
 *  @def 		SwapBlock
 *  @brief 		Swap high and low blocks of any standard data size.
 *	@attention	The macro function evaluates parameter(s) (more than) twice.
 *				Ensure that the parameter(s) passed will not yield side effects.
 *  @param[in]	SRC		primary input or source.
 *	@param[in]	SZ		bits to swap (must be one half of SRC's data size).
 *  @param[in]	CAST	typecast based on SRC's size (see standard types).
 *	@param[in]	MASK	mask bit(s) based on SZ (lower bits mask).
 *	@return   	(((CAST)SRC >> SZ) | ((CAST(SRC) & MASK) << SZ)).
 */
#define SwapBlock(SRC, SZ, CAST, MASK)	\
    (((CAST)(SRC) >> (SZ)) | (((CAST)(SRC) & (MASK)) << (SZ)))

/**
 *  @def 		SwapBit
 *  @brief 		Swap high and low bits in a pair.
 *  @param[in]	SRC		primary input or source (must be pair).
 *	@return   	swap result in pair.
 */
#define SwapBit(SRC) \
	SwapBlock(SRC, SzBits_BIT, T_pair, Mask_BIT)

/**
 *  @def 		SwapPair
 *  @brief 		Swap high and low pair in a nibble.
 *  @param[in]	SRC		primary input or source (must be nibble).
 *	@return   	swap result in nibble.
 */
#define SwapPair(SRC) \
	SwapBlock(SRC, SzBits_PAIR, T_nib, Mask_PAIR)

/**
 *  @def 		SwapNibble
 *  @brief 		Swap high and low nibble in a byte.
 *  @param[in]	SRC		primary input or source (must be byte).
 *	@return   	swap result in byte.
 */
#define SwapNibble(SRC) \
	SwapBlock(SRC, SzBits_NIB, T_byte, Mask_NIB)

/**
 *  @def 		SwapByte
 *  @brief 		Swap high and low byte in a word.
 *  @param[in]	SRC		primary input or source (must be word).
 *	@return   	swap result in word.
 */
#define SwapByte(SRC) \
	SwapBlock(SRC, SzBits_BYTE, T_word, Mask_BYTE)

/**
 *  @def 		SwapWord
 *  @brief 		Swap high and low word in a dword.
 *  @param[in]	SRC		primary input or source (must be dword).
 *	@return   	swap result in dword.
 */
#define SwapWord(SRC) \
	SwapBlock(SRC, SzBits_WORD, T_dword, Mask_WORD)

/**
 *  @def 		SWAP
 *  @brief 		Swaps two numbers of the same width (result persistent).
 *	@attention	The macro function evaluates parameter(s) (more than) twice.
 *				Ensure that the parameter(s) passed will not yield side effects.
 *  @param		LHS		variable to swap with (same width with RHS).
 *  @param		RHS		variable to swap with (same width with LHS).
 *  @return		.
 */
#define SWAP(LHS, RHS) { \
	(LHS) = (LHS) ^ (RHS); \
	(RHS) = (RHS) ^ (LHS); \
	(LHS) = (LHS) ^ (RHS); \
}

/* ----------------------------------------------------------------------------
**	Bit Read & Write.
*/

/**
 *  @def 		ToBit
 *  @brief 		Converts numerical position to binary position
 *  			or as powers of two (position as the exponent).
 *	@param[in]	POS		position of the bit (starts with 0).
 *	@return		2^POS.
 */
#define ToBit(POS) 				(1UL << (POS))

/**
 *  @def 		ReadBit
 *  @brief 		Reads bit of any position.
 *  @param[in]	SRC		primary input or source.
 *	@param[in]	POS		position of the bit (starts with 0).
 *	@return		Bit.
 */
#define ReadBit(SRC, POS) 		(((SRC) >> (POS)) & 1UL)

/**
 *  @def 		ModBit
 *  @brief 		Modifies bit of any position.
 *	@attention	The macro function evaluates parameter(s) (more than) twice.
 *				Ensure that the parameter(s) passed will not yield side effects.
 *  @param[in]	SRC		primary output (or destination).
 *	@param[in]	POS		position of the bit (starts with 0).
 *  @param[in]	VAL		bit value (set or clear).
 *	@return		.
 */
#define ModBit(SRC, POS, VAL) \
	(!!(VAL) ? ((SRC) | (1UL << (POS))) : ((SRC) & (~(1UL << (POS)))))

/**
 *  @def 		WriteBit
 *  @brief 		Sets or clears bit of any position.
 *	@attention	The macro function evaluates parameter(s) (more than) twice.
 *				Ensure that the parameter(s) passed will not yield side effects.
 *  @param 		DST		primary output (or destination).
 *	@param[in]	POS		position of the bit (starts with 0).
 *  @param[in]	VAL		bit value (set or clear).
 *	@return		.
 */
#define WriteBit(DST, POS, VAL) { \
	DST = (!!(VAL) ? ((DST) | (1UL << (POS))) : ((DST) & (~(1UL << (POS))))); \
}

/* ----------------------------------------------------------------------------
**	Multibit Getters.
*/

/**
 *  @def 		Get
 *  @brief 		Get bits (or block) of any data size and position.
 *	@attention	The macro function evaluates parameter(s) (more than) twice.
 *				Ensure that the parameter(s) passed will not yield side effects.
 *  @param[in]	SRC		primary input or source.
 *	@param[in]	BLK		position of the data (starts with 0).
 *	@param[in]	SZ		no. of bits in a block (or size).
 *	@param[in]	OFFSET	alignment, leap bits from block (or offset).
 *  @param[in]	CAST	typecast based on SRC's size (see standard types).
 *	@param[in]	MASK	(block of lower) bit(s) to keep (or mask).
 *	@return		(SRC >> (BLK * SZ + OFFSET)) & MASK.
 */
#define Get(SRC, BLK, SZ, OFFSET, CAST, MASK) \
	(((SRC) >> (((BLK) * (SZ)) + (OFFSET))) & ((CAST)(MASK)))

/**
 *  @def 		GetBit
 *  @brief 		Gets bit from source.
 *  @param[in]	SRC		primary input or source.
 *	@param[in]	POS		position of the bit.
 *	@return		Bit value.
 *	@see		ReadBit
 */
#define GetBit(SRC, POS) \
	Get(SRC, POS, SzBits_BIT, PosX_BASE, T_bit, Mask_BIT)

/**
 *  @def 		GetPair
 *  @brief 		Gets pair-of-bits from source.
 *  @param[in]	SRC		primary input or source.
 *	@param[in]	POS		position of the pair-of-bits.
 *	@return		Pair-of-bits value.
 */
#define GetPair(SRC, POS) \
	Get(SRC, POS, SzBits_PAIR, PosX_BASE, T_pair, Mask_PAIR)

/**
 *  @def 		GetNib
 *  @brief 		Gets nibble from source.
 *  @param[in]	SRC		primary input or source.
 *	@param[in]	POS		position of the nibble.
 *	@return		Nibble value.
 */
#define GetNib(SRC, POS) \
	Get(SRC, POS, SzBits_NIB, PosX_BASE, T_nib, Mask_NIB)

/**
 *  @def 		GetByte
 *  @brief 		Gets byte from source.
 *  @param[in]	SRC		primary input or source.
 *	@param[in]	POS		position of the byte.
 *	@return		Byte value.
 */
#define GetByte(SRC, POS) \
	Get(SRC, POS, SzBits_BYTE, PosX_BASE, T_byte, Mask_BYTE)

/**
 *  @def 		GetWord
 *  @brief 		Gets word from source.
 *  @param[in]	SRC		primary input or source.
 *	@param[in]	POS		position of the word.
 *	@return		Word value.
 */
#define GetWord(SRC, POS) \
	Get(SRC, POS, SzBits_WORD, PosX_BASE, T_word, Mask_WORD)

/**
 *  @def 		GetDWord
 *  @brief 		Gets dword from source.
 *  @param[in]	SRC		primary input or source.
 *	@param[in]	POS		position of the dword (write 0).
 *	@return		DWord value.
 */
#define GetDWord(SRC, POS) \
	Get(SRC, POS, SzBits_DWORD, PosX_BASE, T_dword, Mask_DWORD)

/* ----------------------------------------------------------------------------
**	Multibit Modifiers.
*/

/**
 *  @def 		New
 *  @brief 		Modifies bits (or block) of any data size and position.
 *	@attention	The macro function evaluates parameter(s) (more than) twice.
 *				Ensure that the parameter(s) passed will not yield side effects.
 *  @param[in]	SRC		primary input or source.
 *	@param[in]	BLK		position of the data (starts with 0).
 *	@param[in]	SZ		no. of bits in a block (or size).
 *	@param[in]	OFFSET	alignment, leap bits from block (or offset).
 *  @param[in]	CAST	typecast based on SRC's size (see standard types).
 *	@param[in]	MASK	(block of) bit(s) to keep (or mask).
 *  @param[in]	VAL		data to be inserted (or value).
 *	@return		(SRC & ~(MASK << (BLK * SZ)) | ((VAL & MASK) << (BLK * SZ))).
 */
#define New(SRC, BLK, SZ, OFFSET, CAST, MASK, VAL) \
	(((SRC) & (~(((CAST)(MASK)) << (((BLK) * (SZ)) + (OFFSET))))) \
		| (((VAL) & ((CAST)(MASK))) << (((BLK) * (SZ)) + (OFFSET))))

/**
 *  @def 		NewBit
 *  @brief 		Modifies bit from source.
 *  @param[in]	SRC		primary input or source.
 *	@param[in]	POS		position of the bit.
 *  @param[in]	CAST	typecast based on DST's size.
 *  @param[in]	VAL		value to set at position.
 *	@return		New data modified from SRC.
 *	@see		ModBit
 */
#define NewBit(SRC, POS, CAST, VAL) \
	New(SRC, POS, SzBits_BIT, PosX_BASE, CAST, Mask_BIT, VAL)

/**
 *  @def 		NewPair
 *  @brief 		Modifies pair-of-bits from source.
 *  @param[in]	SRC		primary input or source.
 *	@param[in]	POS		position of the pair-of-bits.
 *  @param[in]	CAST	typecast based on DST's size.
 *  @param[in]	VAL		value to set at position.
 *	@return		New data modified from SRC.
 */
#define NewPair(SRC, POS, CAST, VAL) \
	New(SRC, POS, SzBits_PAIR, PosX_BASE, CAST, Mask_PAIR, VAL)

/**
 *  @def 		NewNib
 *  @brief 		Modifies nibble from source.
 *  @param[in]	SRC		primary input or source.
 *	@param[in]	POS		position of the nibble.
 *  @param[in]	CAST	typecast based on DST's size.
 *  @param[in]	VAL		value to set at position.
 *	@return		New data modified from SRC.
 */
#define NewNib(SRC, POS, CAST, VAL) \
	New(SRC, POS, SzBits_NIB, PosX_BASE, CAST, Mask_NIB, VAL)

/**
 *  @def 		NewByte
 *  @brief 		Modifies byte from source.
 *  @param[in]	SRC		primary input or source.
 *	@param[in]	POS		position of the byte.
 *  @param[in]	CAST	typecast based on DST's size.
 *  @param[in]	VAL		value to set at position.
 *	@return		New data modified from SRC.
 */
#define NewByte(SRC, POS, CAST, VAL) \
	New(SRC, POS, SzBits_BYTE, PosX_BASE, CAST, Mask_BYTE, VAL)

/**
 *  @def 		NewWord
 *  @brief 		Modifies word from source.
 *  @param[in]	SRC		primary input or source.
 *	@param[in]	POS		position of the word.
 *  @param[in]	CAST	typecast based on DST's size.
 *  @param[in]	VAL		value to set at position.
 *	@return		New data modified from SRC.
 */
#define NewWord(SRC, POS, CAST, VAL) \
	New(SRC, POS, SzBits_WORD, PosX_BASE, CAST, Mask_WORD, VAL)

/**
 *  @def 		NewDWord
 *  @brief 		Modifies dword from source.
 *  @param[in]	SRC		primary input or source.
 *	@param[in]	POS		position of the dword.
 *  @param[in]	CAST	typecast based on DST's size.
 *  @param[in]	VAL		value to set at position.
 *	@return		New data modified from SRC.
 */
#define NewDWord(SRC, POS, CAST, VAL) \
	New(SRC, POS, SzBits_DWORD, PosX_BASE, CAST, Mask_DWORD, VAL)

/* ----------------------------------------------------------------------------
**	Multibit Setters.
*/

/**
 *  @def 		Set
 *  @brief 		Set bits (or block) of any data size and position.
 *	@attention	The macro function evaluates parameter(s) (more than) twice.
 *				Ensure that the parameter(s) passed will not yield side effects.
 *  @param		DST		primary output (or destination).
 *	@param[in]	MASK	(block of) bit(s) to keep (or mask).
 *	@param[in]	BLK		position of the data (starts with 0).
 *	@param[in]	SZ		no. of bits in a block (or size).
 *	@param[in]	OFFSET	alignment, leap bits from block (or offset).
 *  @param[in]	CAST	typecast based on DST's size (see standard types).
 *  @param[in]	VAL		data to be inserted (or value).
 *	@return		.
 */
#define Set(DST, BLK, SZ, OFFSET, CAST, MASK, VAL) { \
	(DST) = (((DST) & (~(((CAST)MASK) << (((BLK) * (SZ)) + (OFFSET))))) \
				| (((VAL) & ((CAST)MASK)) << (((BLK) * (SZ)) + (OFFSET)))); \
}

/**
 *  @def 		SetBit
 *  @brief 		Sets bit to destination.
 *  @param 		DST		variable to store result.
 *	@param[in]	POS		position of the bit.
 *  @param[in]	CAST	typecast based on DST's size.
 *  @param[in]	VAL		value to set at position.
 *	@return		.
 *	@see		WriteBit
 */
#define SetBit(DST, POS, CAST, VAL) { \
	Set(DST, POS, SzBits_BIT, PosX_BASE, CAST, Mask_BIT, VAL); \
}

/**
 *  @def 		SetPair
 *  @brief 		Sets pair-of-bits to destination.
 *  @param 		DST		variable to store result.
 *	@param[in]	POS		position of the pair-of-bits.
 *  @param[in]	CAST	typecast based on DST's size.
 *  @param[in]	VAL		value to set at position.
 *	@return		.
 */
#define SetPair(DST, POS, CAST, VAL) { \
	Set(DST, POS, SzBits_PAIR, PosX_BASE, CAST, Mask_PAIR, VAL); \
}

/**
 *  @def 		SetNib
 *  @brief 		Sets nibble to destination.
 *  @param 		DST		variable to store result.
 *	@param[in]	POS		position of the nibble.
 *  @param[in]	CAST	typecast based on DST's size.
 *  @param[in]	VAL		value to set at position.
 *	@return		.
 */
#define SetNib(DST, POS, CAST, VAL) { \
	Set(DST, POS, SzBits_NIB, PosX_BASE, CAST, Mask_NIB, VAL); \
}

/**
 *  @def 		SetByte
 *  @brief 		Sets byte to destination.
 *  @param 		DST		variable to store result.
 *	@param[in]	POS		position of the byte.
 *  @param[in]	CAST	typecast based on DST's size.
 *  @param[in]	VAL		value to set at position.
 *	@return		.
 */
#define SetByte(DST, POS, CAST, VAL) { \
	Set(DST, POS, SzBits_BYTE, PosX_BASE, CAST, Mask_BYTE, VAL); \
}

/**
 *  @def 		SetWord
 *  @brief 		Sets word to destination.
 *  @param 		DST		variable to store result.
 *	@param[in]	POS		position of the word.
 *  @param[in]	CAST	typecast based on DST's size.
 *  @param[in]	VAL		value to set at position.
 *	@return		.
 */
#define SetWord(DST, POS, CAST, VAL) { \
	Set(DST, POS, SzBits_WORD, PosX_BASE, CAST, Mask_WORD, VAL); \
}

/**
 *  @def 		SetDWord
 *  @brief 		Sets dword to destination.
 *  @param 		DST		variable to store result.
 *	@param[in]	POS		position of the dword.
 *  @param[in]	CAST	typecast based on DST's size.
 *  @param[in]	VAL		value to set at position.
 *	@return		.
 */
#define SetDWord(DST, POS, CAST, VAL) { \
	Set(DST, POS, SzBits_DWORD, PosX_BASE, CAST, Mask_DWORD, VAL); \
}

#endif /* BITMANIP_H. */
