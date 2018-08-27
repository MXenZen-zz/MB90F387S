/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Pins															             */
/**
 *	@file		GPIO/pin.h
 * 	@brief		This file contains PIN flags, types, external constants,
 * 				getters, and macro functions.
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

#ifndef PIN_H
#define PIN_H

#include <IO/pin_io.h>

/* ----------------------------------------------------------------------------
**	PIN Flags.
*/

/**
 * 	@def		PIN_LUT_SIZE
 *	@brief 		Size of LUT buffer.
 */
#define PIN_LUT_SIZE					(0x40U)

/* ----------------------------------------------------------------------------
**	PIN Types.
*/

/**
 * 	@brief		Defined enumerated type for both general purpose IO pin numbers
 * 				and resource IO pin numbers.
 */
typedef enum {
	/* port register 1 */
	PIN10    = 10U,						/**< port 1 bit 0 */
	PIN_IN0  = 10U,						/**< input capture 0 */
	PIN11    = 11U,						/**< port 1 bit 1 */
	PIN_IN1  = 11U,						/**< input capture 1 */
	PIN12    = 12U,						/**< port 1 bit 2 */
	PIN_IN2  = 12U,						/**< input capture 2 */
	PIN13    = 13U,						/**< port 1 bit 3 */
	PIN_IN3  = 13U,						/**< input capture 3 */
	PIN14    = 14U,						/**< port 1 bit 4 */
	PIN_PPG0 = 14U,						/**< PPG channel(s) 0 (and 1) */
	PIN15    = 15U,						/**< port 1 bit 5 */
	PIN_PPG1 = 15U,						/**< PPG channel(s) 1 (and 0) */
	PIN16    = 16U,						/**< port 1 bit 6 */
	PIN_PPG2 = 16U,						/**< PPG channel(s) 2 (and 3) */
	PIN17    = 17U,						/**< port 1 bit 7 */
	PIN_PPG3 = 17U,						/**< PPG channel(s) 3 (and 2) */
	/* port register 2 */
	PIN20    = 20U,						/**< port 2 bit 0 */
	PIN_TIN0 = 20U,						/**< reload timer input 0 */
	PIN21    = 21U,						/**< port 2 bit 1 */
	PIN_TOT0 = 21U,						/**< reload timer output 0 */
	PIN22    = 22U,						/**< port 2 bit 2 */
	PIN_TIN1 = 22U,						/**< reload timer input 1 */
	PIN23    = 23U,						/**< port 2 bit 3 */
	PIN_TOT1 = 23U,						/**< reload timer output 1 */
	PIN24    = 24U,						/**< port 2 bit 4 */
	PIN_INT4 = 24U,						/**< external interrupt 4 */
	PIN25    = 25U,						/**< port 2 bit 5 */
	PIN_INT5 = 25U,						/**< external interrupt 5 */
	PIN26    = 26U,						/**< port 2 bit 6 */
	PIN_INT6 = 26U,						/**< external interrupt 6 */
	PIN27    = 27U,						/**< port 2 bit 7 */
	PIN_INT7 = 27U,						/**< external interrupt 7 */
	/* port register 3 */
	PIN30    = 30U,						/**< port 3 bit 0 */
	PIN31    = 31U,						/**< port 3 bit 1 */
	PIN32    = 32U,						/**< port 3 bit 2 */
	PIN33    = 33U,						/**< port 3 bit 3 */
	PIN35    = 35U,						/**< port 3 bit 5 */
	PIN36    = 36U,						/**< port 3 bit 6 */
	PIN37    = 37U,						/**< port 3 bit 7 */
	PIN_ADTG = 37U,						/**< ADC external trigger */
	/* port register 4 */
	PIN40    = 40U,						/**< port 4 bit 0 */
	PIN_SIN1 = 40U,						/**< serial input 1 */
	PIN41    = 41U,						/**< port 4 bit 1 */
	PIN_SCK1 = 41U,						/**< serial clock 1 */
	PIN42    = 42U,						/**< port 4 bit 2 */
	PIN_SOT1 = 42U,						/**< serial output 1 */
	PIN43    = 43U,						/**< port 4 bit 3 */
	PIN_TX   = 43U,						/**< CAN transmit pin */
	PIN44    = 44U,						/**< port 4 bit 4 */
	PIN_RX   = 44U,						/**< CAN receive pin */
	/* port register 5 */
	PIN50    = 50U,						/**< port 5 bit 0 */
	PIN_AN0  = 50U,						/**< ADC channel 0 */
	PIN51    = 51U,						/**< port 5 bit 1 */
	PIN_AN1  = 51U,						/**< ADC channel 1 */
	PIN52    = 52U,						/**< port 5 bit 2 */
	PIN_AN2  = 52U,						/**< ADC channel 2 */
	PIN53    = 53U,						/**< port 5 bit 3 */
	PIN_AN3  = 53U,						/**< ADC channel 3 */
	PIN54    = 54U,						/**< port 5 bit 4 */
	PIN_AN4  = 54U,						/**< ADC channel 4 */
	PIN55    = 55U,						/**< port 5 bit 5 */
	PIN_AN5  = 55U,						/**< ADC channel 5 */
	PIN56    = 56U,						/**< port 5 bit 6 */
	PIN_AN6  = 56U,						/**< ADC channel 6 */
	PIN57    = 57U,						/**< port 5 bit 7 */
	PIN_AN7  = 57U						/**< ADC channel 7 */
} T_pinNumber;

/* ----------------------------------------------------------------------------
**	PIN External Constants.
*/

/**
 * 	@var 		pinToPDRAddLUT
 *	@brief 		Look-up table for extracting port data register (PDR) address
 *  			from pin number index.
 */
extern const T_byte pinToPDRAddLUT[PIN_LUT_SIZE];

/**
 * 	@var 		pinToDDRAddLUT
 *	@brief 		Look-up table for extracting data direction register (DDR) address
 *  			from pin number index.
 */
extern const T_byte pinToDDRAddLUT[PIN_LUT_SIZE];

/**
 * 	@var 		pinToPortNumLUT
 *	@brief 		Look-up table for extracting port number from pin number index.
 */
extern const T_byte pinToPortNumLUT[PIN_LUT_SIZE];

/**
 * 	@var 		pinToBitNumLUT
 *	@brief 		Look-up table for extracting pin bit number from pin number index.
 */
extern const T_byte pinToBitNumLUT[PIN_LUT_SIZE];

/**
 * 	@var 		pinToBitSetLUT
 *	@brief 		Look-up table for converting pin bit number into set (HIGH)
 *  			bit binary position.
 */
extern const T_byte pinToBitSetLUT[PIN_LUT_SIZE];

/**
 * 	@var 		pinToBitClrLUT
 *	@brief 		Look-up table for converting pin bit number into clear (LOW)
 *  			bit binary position.
 */
extern const T_byte pinToBitClrLUT[PIN_LUT_SIZE];

/* ----------------------------------------------------------------------------
**	PIN Getters.
*/

/**
 *	@def 		GetBytePDRAddress
 *	@brief 		Port data register address getter.
 * 	@param		PIN		Pin Number (byte).
 * 	@return		port data register address (byte).
 */
#define GetBytePDRAddress(PIN)			(pinToPDRAddLUT[PIN])

/**
 *	@def 		GetByteDDRAddress
 *	@brief 		Data direction register address getter.
 * 	@param		PIN		Pin Number (byte).
 * 	@return		data direction register address (byte).
 */
#define GetByteDDRAddress(PIN)			(pinToDDRAddLUT[PIN])

/**
 *	@def 		GetBytePortNumber
 *	@brief 		Port number getter.
 * 	@param		PIN		Pin Number (byte).
 * 	@return		port number (byte).
 */
#define GetBytePortNumber(PIN) 			(pinToPortNumLUT[PIN])

/**
 *	@def 		GetBytePinBitNumber
 *	@brief 		Pin bit number getter.
 * 	@param		PIN		Pin Number (byte).
 * 	@return		pin bit number (byte).
 */
#define GetBytePinBitNumber(PIN) 		(pinToBitNumLUT[PIN])

/**
 *	@def 		GetBytePinSetBitPosition
 *	@brief 		Set (HIGH) bit binary position (2^BIT) getter.
 * 	@param		PIN		Pin Number (byte).
 * 	@return		set bit position (byte).
 */
#define GetBytePinSetBitPosition(PIN)	(pinToBitSetLUT[PIN])

/**
 *	@def 		GetBytePinClearBitPosition
 *	@brief 		Clear (LOW) bit binary position [~(2^BIT)] getter.
 * 	@param		PIN		Pin Number (byte).
 * 	@return		clear bit position (byte).
 */
#define GetBytePinClearBitPosition(PIN)	(pinToBitClrLUT[PIN])

/* ----------------------------------------------------------------------------
**	PIN Macro Functions.
*/

/**
 * 	@def		GetPINMode
 * 	@brief		Gets data direction of any pin.
 *	@attention	The macro function evaluates parameter(s) (more than) twice.
 *				Ensure that the parameter(s) passed will not yield side effects.
 *				Ensure that PIN's range is below the maximum size of LUT.
 * 	@param[in]	PIN 	Pin number (numeric, constant or variable) (byte).
 * 	@return		data direction (bit).
 *	@remark		The macro function executes around 2.0 microseconds.
 * 	@see		ReadBitIOPinMode.
 */
#define GetPINMode(PIN) \
	IS(MaskOff(*((volatile T_byte*)((T_word)pinToDDRAddLUT[PIN])), pinToBitSetLUT[PIN]))

/**
 * 	@def		GetPINData
 * 	@brief		Gets data state (logic level) of any pin.
 *	@attention	The macro function evaluates parameter(s) (more than) twice.
 *				Ensure that the parameter(s) passed will not yield side effects.
 *				Ensure that PIN's range is below the maximum size of LUT.
 * 	@param[in]	PIN 	Pin number (numeric, constant or variable) (byte).
 * 	@return		data state (bit).
 *	@remark		The macro function executes around 2.0 microseconds.
 * 	@see		ReadBitIOPinData.
 */
#define GetPINData(PIN) \
	IS(MaskOff(*((volatile T_byte*)((T_word)pinToPDRAddLUT[PIN])), pinToBitSetLUT[PIN]))

/**
 * 	@def		SetPINMode
 * 	@brief		Sets OUTPUT data direction to any pin.
 *	@attention	The macro function evaluates parameter(s) (more than) twice.
 *				Ensure that the parameter(s) passed will not yield side effects.
 *				Ensure that PIN's range is below the maximum size of LUT.
 * 	@param[in]	PIN 	Pin number (numeric, constant or variable) (byte).
 * 	@return		.
 *	@remark		The macro function executes around 1.3 microseconds.
 * 	@see		WriteBitIOPinMode.
 */
#define SetPINMode(PIN) { \
	(*((volatile T_byte*)((T_word)pinToDDRAddLUT[PIN]))) \
		= MaskOn(*((volatile T_byte*)((T_word)pinToDDRAddLUT[PIN])), pinToBitSetLUT[PIN]); \
}

/**
 * 	@def		SetPINData
 * 	@brief		Sets HIGH state (logic level) to any pin.
 *	@attention	The macro function evaluates parameter(s) (more than) twice.
 *				Ensure that the parameter(s) passed will not yield side effects.
 *				Ensure that PIN's range is below the maximum size of LUT.
 * 	@param[in]	PIN 	Pin number (numeric, constant or variable) (byte).
 * 	@return		.
 *	@remark		The macro function executes around 1.3 microseconds.
 * 	@see		WriteBitIOPinData.
 */
#define SetPINData(PIN) { \
	(*((volatile T_byte*)((T_word)pinToPDRAddLUT[PIN]))) \
		= MaskOn(*((volatile T_byte*)((T_word)pinToPDRAddLUT[PIN])), pinToBitSetLUT[PIN]); \
}

/**
 * 	@def		ClearPINMode
 * 	@brief		Sets INPUT data direction to any pin.
 *	@attention	The macro function evaluates parameter(s) (more than) twice.
 *				Ensure that the parameter(s) passed will not yield side effects.
 *				Ensure that PIN's range is below the maximum size of LUT.
 * 	@param[in]	PIN 	Pin number (numeric, constant or variable) (byte).
 * 	@return		.
 *	@remark		The macro function executes around 1.3 microseconds.
 * 	@see		WriteBitIOPinMode.
 */
#define ClearPINMode(PIN) { \
	(*((volatile T_byte*)((T_word)pinToDDRAddLUT[PIN]))) \
		= MaskOff(*((volatile T_byte*)((T_word)pinToDDRAddLUT[PIN])), pinToBitClrLUT[PIN]); \
}

/**
 * 	@def		ClearPINData
 * 	@brief		Sets LOW state (logic level) to any pin.
 *	@attention	The macro function evaluates parameter(s) (more than) twice.
 *				Ensure that the parameter(s) passed will not yield side effects.
 *				Ensure that PIN's range is below the maximum size of LUT.
 * 	@param[in]	PIN 	Pin number (numeric, constant or variable) (byte).
 * 	@return		.
 *	@remark		The macro function executes around 1.3 microseconds.
 * 	@see		WriteBitIOPinData.
 */
#define ClearPINData(PIN) { \
	(*((volatile T_byte*)((T_word)pinToPDRAddLUT[PIN]))) \
		= MaskOff(*((volatile T_byte*)((T_word)pinToPDRAddLUT[PIN])), pinToBitClrLUT[PIN]); \
}

#endif /* PIN_H. */
