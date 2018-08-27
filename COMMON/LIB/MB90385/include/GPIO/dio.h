/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Digital Input / Output										             */
/**
 *	@file		GPIO/dio.h
 * 	@brief		This file contains DIO types and API functions.
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

#ifndef DIO_H
#define DIO_H

#include <GPIO/pin.h>

/* ----------------------------------------------------------------------------
**	DIO Types.
*/

/**
 * 	@brief		Defined type for pin group array size.
 */
typedef T_uint8					T_pinGroupSize;

/**
 * 	@brief		Defined type for software deboucing sampling buffer.
 */
typedef T_byte					T_swDebBuffer;

/**
 * 	@brief		Defined type for software deboucing sampling count.
 */
typedef T_byte					T_swDebSampCnt;

/**
 * 	@brief		Defined type for IO_PDRn bit pin.
 */
typedef T_bit					T_ioBitPin;

/**
 * 	@brief		Defined type for shift data type width (default: 8 bits).
 */
typedef T_byte					T_shiftData;

/* ----------------------------------------------------------------------------
**	DIO API Functions.
*/

/**
 * 	@fn 		T_void pinModeDigital(T_pinNumber, T_pinDirection)
 *	@brief 		Set digital pin's data direction.
 * 	@param[in]	pin		Pin number.
 * 	@param[in]	mode	Pin mode.
 * 	@return		.
 */
extern T_void pinModeDigital(T_pinNumber pin, T_pinDirection mode);

/**
 * 	@fn 		T_void pinModeDigitalGroup(T_pinNumber*, T_pinDirection*, T_pinGroupSize)
 *	@brief 		Set digital data direction of a group of pins.
 * 	@param[in]	pins	Pin number array (pin mode correspondence).
 * 	@param[in]	modes	Pin mode array (pin number correspondence).
 * 	@param[in]	size	Pin group array size.
 * 	@return		.
 */
extern T_void pinModeDigitalGroup(T_pinNumber* pins,
	T_pinDirection* modes, T_pinGroupSize size);

/**
 * 	@fn 		T_void writeDigital(T_pinNumber, T_pinLevel)
 *	@brief 		Writes state (logic level) to a digitally set pin.
 * 	@pre		Pin must be already set to output mode.
 * 	@param[in]	pin		Pin number.
 * 	@param[in]	level	Pin state or logic level.
 * 	@return		.
 */
extern T_void writeDigital(T_pinNumber pin, T_pinLevel level);

/**
 * 	@fn 		T_void writeDigitalGroup(T_pinNumber*, T_pinLevel*, T_pinGroupSize)
 *	@brief 		Write states (logic levels) to a group of digitally set pins.
 * 	@pre		Pins of the group must be already set to output mode.
 * 	@param[in]	pins	Pin number array (pin state or logic level correspondence).
 * 	@param[in]	levels	Pin state or logic level array (pin number correspondence).
 * 	@param[in]	size	Pin group array size.
 * 	@return		.
 */
extern T_void writeDigitalGroup(T_pinNumber* pins,
	T_pinLevel* levels, T_pinGroupSize size);

/**
 * 	@fn 		T_bit readDigital(T_pinNumber)
 *	@brief 		Reads state (logic level) of a digitally set pin.
 * 	@pre		Pin must be already set to input mode (output mode issues?).
 * 	@param[in]	pin		Pin number.
 * 	@return		logic level.
 */
extern T_bit readDigital(T_pinNumber pin);

/**
 * 	@fn 		T_void readDigitalGroup(T_pinNumber*, T_pinLevel*, T_pinGroupSize)
 *	@brief 		Read states (logic levels) to a group of digitally set pins.
 * 	@pre		Pins of the group must be already set to output mode.
 * 	@param[in]	pins	Pin number array (pin state or logic level correspondence).
 * 	@param[out]	levels	Pin state or logic level array (pin number correspondence).
 * 	@param[in]	size	Pin group array size.
 * 	@return		see levels (param).
 */
extern T_void readDigitalGroup(T_pinNumber* pins,
	T_pinLevel* levels, T_pinGroupSize size);

/**
 * 	@fn 		T_bit readDebouncedPosTrig(T_swDebBuffer*, T_swDebSampCnt, T_ioBitPin)
 * 	@brief		Reads SW debounced positive logic level of a digitally set pin.
 * 	@pre		The sampling buffer should be initialized first.
 * 	@attention	Use different buffer for different pins.
 * 	@param[in]	sample	Sampling buffer pointer.
 * 	@param[in]	count	Sampling count (smaller means faster).
 * 	@param[in]	IOPin	IO_PDRn pin.
 * 	@return		logic level.				.
 * 	@note		This function is intended to be used on software debouncing
 * 				positive logic pins. The resulting logic is transparent.
 */
extern T_bit readDebouncedPosTrig(T_swDebBuffer* sample,
	T_swDebSampCnt count, T_ioBitPin IOPin);

/**
 * 	@fn 		T_bit readDebouncedNegTrig(T_swDebBuffer*, T_swDebSampCnt, T_ioBitPin)
 * 	@brief		Reads SW debounced negative logic level of a digitally set pin.
 * 	@pre		The sampling buffer should be initialized first.
 * 	@attention	Use different buffer for different pins.
 * 	@param[in]	sample	Sampling buffer pointer.
 * 	@param[in]	count	Sampling count (smaller means faster).
 * 	@param[in]	IOPin	IO_PDRn pin.
 * 	@return		logic level.						.
 * 	@note		This function is intended to be used on software debouncing
 * 				negative logic pins. The resulting logic is inverted. To make
 * 				the conditional statement TRUE, invert (!, NOT) the result.
 */
extern T_bit readDebouncedNegTrig(T_swDebBuffer* sample,
	T_swDebSampCnt count, T_ioBitPin IOPin);

/**
 * 	@fn 		T_void shiftOut(T_pinNumber, T_pinNumber, T_bit, T_bit, T_shiftData)
 *	@brief 		Shifts out a byte of data one bit at a time.
 * 	@pre		Set both data and clock pin as OUTPUT.
 * 	@param[in]	dataPin		Shift data pin number.
 * 	@param[in]	clockPin	Shift clock pin number.
 * 	@param[in]	lsbFirst	LSB first shift option.
 * 	@param[in]	activeLow	Negative edge trigger shift option.
 * 	@param[in]	data		Data to shift.
 * 	@return		.
 *  @note		Shift starts from either the most or least significant bit.
 *  			Make sure that the clock pin is set to idle state.
 */
extern T_void shiftOut(T_pinNumber dataPin, T_pinNumber clockPin, T_bit lsbFirst,
	T_bit activeLow, T_shiftData data);

/**
 * 	@fn 		T_shiftData shiftIn(T_pinNumber, T_pinNumber, T_bit, T_bit)
 *	@brief 		Shifts in a byte of data one bit at a time.
 * 	@pre		Set data pin as INPUT and clock pin as OUTPUT.
 * 	@param[in]	dataPin		Shift data pin number.
 * 	@param[in]	clockPin	Shift clock pin number.
 * 	@param[in]	lsbFirst	LSB first shift option.
 * 	@param[in]	activeLow	Negative edge trigger shift option.
 * 	@return		data shifted.
 *  @note		Shift starts from either the most or least significant bit.
 *  			Make sure that the clock pin is set to idle state.
 */
extern T_shiftData shiftIn(T_pinNumber dataPin, T_pinNumber clockPin,
	T_bit lsbFirst, T_bit activeLow);

#endif /* DIO_H. */
