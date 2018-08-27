/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Analog to Digital Conversion 								             */
/**
 *	@file		ADC/adc.h
 * 	@brief		This file contains ADC flags, types, external constants,
 * 				getters, and API functions.
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

#ifndef ADC_H
#define ADC_H

#include <IO/adc_io.h>
#include <MCU/isr.h>
#include <GPIO/pin.h>
#include <GPIO/port.h>

/* ----------------------------------------------------------------------------
**	ADC Flags.
*/

/**
 * 	@def		ADC_DEF_CT
 *	@brief 		Default compare time for ADC.
 */
#define ADC_DEF_CT				ADC_CT_176T

/**
 * 	@def		ADC_DEF_ST
 *	@brief 		Default sampling time for ADC.
 */
#define ADC_DEF_ST				ADC_ST_128T

/**
 * 	@def		ADC_DEF_RES
 *	@brief 		Default conversion resolution for ADC.
 */
#define ADC_DEF_RES				ADC_RES_10BITS

/* ----------------------------------------------------------------------------
**	ADC Types.
*/

/**
 *	@brief 		Callback type for ADC interrupt user routine functions.
 */
typedef T_void (*T_adcISRHook)(T_void);

/**
 * 	@brief		Defined type for ADC buffer data type width (default: 16 bits).
 */
typedef T_uint16 T_adcBuffer;

/* ----------------------------------------------------------------------------
**	ADC External Constants.
*/

/**
 * 	@var		PRIO_ADC_ISR
 *	@brief		ISR interrupt level/priority of ADC.
 *	@note		The ICR of ADC is shared with RLT0. Unless RLT0 is not used,
 *				they must have the same ICR level at all times. If only ADC
 *				is (or will be) used, then set the ICR level of ADC alone.
 */
extern const T_icrINTLevel PRIO_ADC_ISR;

/**
 * 	@var		pADCBuffer
 *	@brief		Read-only access to converted analog to digital data.
 */
extern volatile T_adcBuffer const * const pADCBuffer;

/* ----------------------------------------------------------------------------
**	ADC Getters.
*/

/**
 *	@def 		GetWordADCRead
 *	@brief 		Converted analog to digital data getter.
 * 	@param[in]	IDX		ADC channel (byte).
 * 	@return		analog data (word).
 */
#define GetWordADCRead(IDX)		(*(pADCBuffer + (IDX)))

/* ----------------------------------------------------------------------------
**	ADC API Functions.
*/

/**
 * 	@fn 		T_void portModeAnalog(T_portNumber)
 *	@brief 		Set analog port's data direction.
 * 	@param[in]	port	Port number (default: PORT5).
 * 	@return		.
 */
extern T_void portModeAnalog(T_portNumber port);

/**
 * 	@fn 		T_void pinModeAnalog(T_pinNumber)
 *	@brief 		Set analog pin's data direction.
 * 	@param[in]	pin		Pin number from an analog port.
 * 	@return		.
 */
extern T_void pinModeAnalog(T_pinNumber pin);

/**
 * 	@fn 		T_void initADC(T_adcCompareTime, T_adcSampleTime, T_adcDataResolution)
 *	@brief 		Initialize ADC timing and resolution which will be held default
 *				or common to all ADC operations.
 * 	@param[in]	compareTime		A/D conversion compare time.
 * 	@param[in]	samplingTime	A/D conversion sampling time.
 * 	@param[in]	resolution		ADC resolution.
 * 	@return		.
 *  @note 		ADC should be initialized once. Since this function sets timing
 *  			and resolution as the default to all succeeding ADC operations,
 *  			this function must be called before	performing any ADC operation.
 */
extern T_void initADC(T_adcCompareTime compareTime,
	T_adcSampleTime samplingTime, T_adcDataResolution resolution);

/**
 * 	@fn 		T_void startADCGroup(T_pinNumber, T_pinNumber,
 *					T_adcStartTrigger, T_adcConvMode, T_adcISRHook)
 *	@brief 		Set up ADC's channels, conversion trigger, and user interrupt
 *  			function with interrupt enabled, then starts ADC.
 * 	@pre		initADC must be called first (or called already).
 *  			Pin must be already set to analog input mode.
 * 	@param[in]	startPin	Start pin number for analog conversion.
 * 	@param[in]	endPin		End pin number for analog conversion.
 * 	@param[in]	trigger		ADC conversion trigger source.
 * 	@param[in]	convMode	ADC conversion mode.
 * 	@param[in]	adcFunc		ADC user interrupt function.
 * 	@return		.
 * 	@warning	Do not run this function with ADC_MD_CONTINUOUS conversion
 *  			mode unless there is a provided workaround on the user
 *  			interrupt function.
 *  @note		This function is intended for multi-channel multi-mode
 *  			multi-triggered multi-data multi-start interrupt-based
 *  			ADC reading.
 *  @see		For single channel reading, use readAnalog instead.
 */
extern T_void startADCGroup(T_pinNumber startPin, T_pinNumber endPin,
	T_adcStartTrigger trigger, T_adcConvMode convMode, T_adcISRHook adcFunc);

/**
 * 	@fn 		T_void stopADCGroup(T_void)
 *	@brief 		Terminates ADC operation and disables ADC interrupt.
 * 	@param		.
 * 	@return		.
 */
extern T_void stopADCGroup(T_void);

/**
 * 	@fn 		T_adcBuffer readAnalog(T_pinNumber)
 *	@brief 		Reads software-triggered ADC data from an analog set pin.
 * 	@pre		initADC must be called first (or called already).
 *  			Pin must be already set to analog input mode.
 * 	@param[in]	pin		Pin number from an analog port.
 * 	@return		A/D converted data.
 *  @note		This function is intended for single-shot single-channel
 *  			software-triggered restartable ADC reading.
 *  @see		For multiple channel reading, use startADCGroup instead.
 */
extern T_adcBuffer readAnalog(T_pinNumber pin);

/**
 * 	@fn 		T_void ADC_IRQHandler(T_void)
 *	@brief		Clears external interrupt flag, saves ADC reading and executes
 *  			interrupt user routine function.
 *  @param		.
 *  @return		.
 */
#if USE_ADC_ISR
#if NOSAVEREG_ADC_ISR
NOSAVEREG
#endif
extern ISR(ADC_IRQHandler);
#endif

#endif /* ADC_H. */
