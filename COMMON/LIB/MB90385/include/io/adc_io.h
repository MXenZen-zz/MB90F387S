/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Analog to Digital Conversion 								             */
/**
 *	@file		IO/adc_io.h
 * 	@brief		This file contains types, getters and setters, and other
 * 				macro functions for ADC IO registers.
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

#ifndef ADC_IO_H
#define ADC_IO_H

#include <IO/io_mb90385.h>

/* ----------------------------------------------------------------------------
**	ADC IO Types.
*/

/**
 * 	@brief		Defined enumerated type for ADC software start.
 */
typedef enum {
	ADC_STOP,					/**< does not start A/D conversion */
	ADC_START					/**< starts A/D conversion */
} T_adcSWStart;

/**
 * 	@brief		Defined enumerated type for ADC start trigger.
 */
typedef enum {
	ADC_STS_SW,					/**< by software */
	ADC_STS_SW_XTRIG,			/**< by software and ext. trigger */
	ADC_STS_SW_TMR,				/**< by software and timer */
	ADC_STS_SW_XTRIG_TMR		/**< by software, ext. trigger and timer */
} T_adcStartTrigger;

/**
 * 	@brief		Defined enumerated type for ADC pause conversion.
 */
typedef enum {
	ADC_NO_PAUSE,				/**< A/D conversion does not pause */
	ADC_PAUSE					/**< A/D conversion pauses */
} T_adcConvPause;

/**
 * 	@brief		Defined enumerated type for ADC interrupt enable.
 */
typedef enum {
	ADC_INT_DISABLED,			/**< interrupt request disable */
	ADC_INT_ENABLED				/**< interrupt request enable */
} T_adcINTEnable;

/**
 * 	@brief		Defined enumerated type for ADC interrupt request.
 */
typedef enum {
	ADC_IRQ_CLEARED,			/**< clear ADC interrupt request */
	ADC_IRQ_CONV_TERMINATED		/**< A/D conversion terminated */
} T_adcIRQ;

/**
 * 	@brief		Defined enumerated type for A/D conversion operation.
 */
typedef enum {
	ADC_CONV_TERMINATED,		/**< terminates A/D conversion forcibly */
	ADC_CONV_OPERATING			/**< A/D conversion in operation */
} T_adcConvOperation;

/**
 * 	@brief		Defined enumerated type for ADC conversion start / end channel.
 */
typedef enum {
	ADC_AN0,					/**< AN0 pin */
	ADC_AN1,					/**< AN1 pin */
	ADC_AN2,					/**< AN2 pin */
	ADC_AN3,					/**< AN3 pin */
	ADC_AN4,					/**< AN4 pin */
	ADC_AN5,					/**< AN5 pin */
	ADC_AN6,					/**< AN6 pin */
	ADC_AN7						/**< AN7 pin */
} T_adcConvChannel;

/**
 * 	@brief		Defined enumerated type for ADC conversion mode.
 */
typedef enum {
	ADC_MD_SINGLE_REACTIVE,		/**< single conversion mode (restartable during conversion) */
	ADC_MD_SINGLE_ONCE,			/**< single conversion mode (not-restartable during conversion) */
	ADC_MD_CONTINUOUS,			/**< continuous conversion mode (not-restartable during conversion) */
	ADC_MD_PAUSE_CONVERT		/**< pause-conversion mode (not-restartable during conversion) */
} T_adcConvMode;

/**
 * 	@brief		Defined enumerated type for ADC compare time (n / Machine Cycle).
 */
typedef enum {
	ADC_CT_44T,					/**< 5.5  μs compare time @  8MHz Machine Clock */
	ADC_CT_66T,					/**< 4.12 μs compare time @ 16MHz Machine Clock */
	ADC_CT_88T,					/**< 5.5  μs compare time @ 16MHz Machine Clock */
	ADC_CT_176T					/**< 11.0 μs compare time @ 16MHz Machine Clock */
} T_adcCompareTime;

/**
 * 	@brief		Defined enumerated type for ADC sampling time (n / Machine Cycle).
 */
typedef enum {
	ADC_ST_20T,					/**< 2.5 μs sampling time @  8MHz Machine Clock */
	ADC_ST_32T,					/**< 2.0 μs sampling time @ 16MHz Machine Clock */
	ADC_ST_48T,					/**< 3.0 μs sampling time @ 16MHz Machine Clock */
	ADC_ST_128T					/**< 8.0 μs sampling time @ 16MHz Machine Clock */
} T_adcSampleTime;

/**
 * 	@brief		Defined enumerated type for ADC data resolution.
 */
typedef enum {
	ADC_RES_10BITS,				/**< 10-bit resolution */
	ADC_RES_8BITS				/**<  8-bit resolution */
} T_adcDataResolution;

/**
 * 	@brief		Defined enumerated type for ADC input enable.
 */
typedef enum {
	ADC_INPUT_DISABLED,			/**< analog input disable */
	ADC_INPUT_ENABLED			/**< analog input enable */
} T_adcInputEnable;

/* ----------------------------------------------------------------------------
**	ADC IO Registers Getters and Setters.
*/

/**
 *	@def 		GetADC_ADER
 *	@brief 		Analog Input Enable Register Getter.
 * 	@param		.
 * 	@return		ADER (byte).
 */
#define GetADC_ADER()			GetIOREGByte(IO_ADER)

/**
 *	@def 		GetADC_ADCSL
 *	@brief 		A/D Control Status Register (Low) Getter.
 * 	@param		.
 * 	@return		ADCSL (byte).
 */
#define GetADC_ADCSL()			GetIOREGByte(IO_ADCSL)

/**
 *	@def 		GetADC_ADCSH
 *	@brief 		A/D Control Status Register (High) Getter.
 * 	@param		.
 * 	@return		ADCSH (byte).
 */
#define GetADC_ADCSH()			GetIOREGByte(IO_ADCSH)

/**
 *	@def 		GetADC_ADCRH
 *	@brief 		A/D Data Register (High) Getter.
 * 	@param		.
 * 	@return		ADCRH (byte).
 */
#define GetADC_ADCRH()			GetIOREGByteVar(IO_ADCRLH, ADCRH)

/**
 *	@def 		SetADC_ADER
 *	@brief 		Analog Input Enable Register Setter.
 * 	@param[in]	VAL		Enable/disable bits for ADER (byte).
 * 	@return		.
 */
#define SetADC_ADER(VAL) { \
	SetIOREGByte(IO_ADER, VAL); \
}

/**
 *	@def 		SetADC_ADCSL
 *	@brief 		A/D Control Status Register (Low) Setter.
 * 	@param[in]	VAL		Control bits for ADCSL (byte).
 * 	@return		.
 */
#define SetADC_ADCSL(VAL) { \
	SetIOREGByte(IO_ADCSL, VAL); \
}

/**
 *	@def 		SetADC_ADCSH
 *	@brief 		A/D Control Status Register (High) Setter.
 * 	@param[in]	VAL		Control bits for ADCSH (byte).
 * 	@return		.
 */
#define SetADC_ADCSH(VAL) { \
	SetIOREGByte(IO_ADCSH, VAL); \
}

/**
 *	@def 		SetADC_ADCRH
 *	@brief 		A/D Data Register (High) Setter.
 * 	@param[in]	VAL		Control bits for ADCRH (byte).
 * 	@return		.
 */
#define SetADC_ADCRH(VAL) { \
	SetIOREGByteVar(IO_ADCRLH, ADCRH, VAL); \
}

/* ----------------------------------------------------------------------------
**	ADC IO Register Fields Macro Functions.
*/

/**
 *	@def		IsADConversionStarted
 *	@brief		Check if AD conversion is started or running.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsADConversionStarted() \
	EQU(GetIOREGBitVar(IO_ADCSH, STRT), ADC_START) \

/**
 *	@def		IsADConversionPaused
 *	@brief		Check if AD conversion is suspended or finished.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsADConversionPaused() \
	EQU(GetIOREGBitVar(IO_ADCSH, PAUS), ADC_PAUSE) \

/**
 *	@def		IsADConversionDone
 *	@brief		Check if AD conversion in progress or terminated.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsADConversionDone() \
	EQU(GetIOREGBitVar(IO_ADCSH, BUSY), ADC_CONV_TERMINATED) \

/**
 *	@def 		StartADC
 *	@brief 		Starts A/D Conversion.
 * 	@param		.
 * 	@return		.
 */
#define StartADC() { \
	SetIOREGBitVar(IO_ADCSH, PAUS, ADC_NO_PAUSE); \
	SetIOREGBitVar(IO_ADCSH, STRT, ADC_START); \
}

/**
 *	@def 		StopADC
 *	@brief 		Stops A/D Conversion.
 * 	@param		.
 * 	@return		.
 */
#define StopADC() { \
	SetIOREGBitVar(IO_ADCSH, BUSY, ADC_STOP); \
}

/**
 *	@def 		EnableADCInterrupt
 *	@brief 		A/D Conversion Interrupt Enabler.
 * 	@param		.
 * 	@return		.
 */
#define EnableADCInterrupt() { \
	SetIOREGBitVar(IO_ADCSH, INTE, ADC_INT_ENABLED); \
}

/**
 *	@def 		DisableADCInterrupt
 *	@brief 		A/D Conversion Interrupt Disabler.
 * 	@param		.
 * 	@return		.
 */
#define DisableADCInterrupt() { \
	SetIOREGBitVar(IO_ADCSH, INTE, ADC_INT_DISABLED); \
}

/**
 *	@def 		ClearADCIRQ
 *	@brief 		Clear A/D Conversion Interrupt Request.
 * 	@param		.
 * 	@return		.
 */
#define ClearADCIRQ() { \
	SetIOREGBitVar(IO_ADCSH, INT, ADC_IRQ_CLEARED); \
}

/**
 *	@def 		SetADCStartTrigger
 *	@brief 		Start Trigger Setter.
 * 	@param[in]	VAL		Trigger bits of ADC (bits).
 * 	@return		.
 */
#define SetADCStartTrigger(VAL) { \
	SetIOREGBitVar(IO_ADCSH, STS, VAL); \
}

/**
 *	@def 		EnableADCChannel
 *	@brief 		ADC Channel Enabler.
 * 	@param		VAL		Analog input channel of ADC (bits).
 * 	@return		.
 */
#define EnableADCChannel(VAL) { \
	SetADC_ADER(ModBit(GetADC_ADER(), VAL, ADC_INPUT_ENABLED)); \
}

/**
 *	@def 		DisableADCChannel
 *	@brief 		ADC Channel Disabler.
 * 	@param		VAL		Analog input channel of ADC (bits).
 * 	@return		.
 */
#define DisableADCChannel(VAL) { \
	SetADC_ADER(ModBit(GetADC_ADER(), VAL, ADC_INPUT_DISABLED)); \
}

/**
 *	@def 		GetADCChannelPointer
 *	@brief 		ADC Current Channel Getter.
 * 	@param		.
 * 	@return		boolean.
 */
#define GetADCChannelPointer() \
	GetIOREGBitVar(IO_ADCSL, ANS)

/**
 *	@def 		SetADCStartChannel
 *	@brief 		ADC Start Channel Setter.
 * 	@param		VAL		Analog input channel of ADC (bits).
 * 	@return		.
 */
#define SetADCStartChannel(VAL) { \
	SetIOREGBitVar(IO_ADCSL, ANS, VAL); \
}

/**
 *	@def 		SetADCEndChannel
 *	@brief 		ADC End Channel Setter.
 * 	@param		VAL		Analog input channel of ADC (bits).
 * 	@return		.
 */
#define SetADCEndChannel(VAL) { \
	SetIOREGBitVar(IO_ADCSL, ANE, VAL); \
}

/**
 *	@def 		SetADConversionMode
 *	@brief 		ADC Conversion Mode Setter.
 * 	@param[in]	VAL		Conversion mode bits of ADC (bits).
 * 	@return		.
 */
#define SetADConversionMode(VAL) { \
	SetIOREGBitVar(IO_ADCSL, MD, VAL); \
}

/**
 *	@def 		SetADCCompareTime
 *	@brief 		ADC Compare Time Setter.
 * 	@param[in]	VAL		Compare time bits of ADC (bits).
 * 	@return		.
 */
#define SetADCCompareTime(VAL) { \
	SetIOREGBitVar(IO_ADCRLH, CT, VAL); \
}

/**
 *	@def 		SetADCSamplingTime
 *	@brief 		ADC Sampling Time Setter.
 * 	@param[in]	VAL		Sampling time bits of ADC (bits).
 * 	@return		.
 */
#define SetADCSamplingTime(VAL) { \
	SetIOREGBitVar(IO_ADCRLH, ST, VAL); \
}

/**
 *	@def		IsADC8bitDataResolution
 *	@brief		Check if ADC resolution is 8-bits.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsADC8bitDataResolution() \
	EQU(GetIOREGBitVar(IO_ADCRLH, S10), ADC_RES_8BITS)

/**
 *	@def 		SetADC8bitDataResolution
 *	@brief 		ADC 8-bit Data Resolution Setter.
 * 	@param		.
 * 	@return		.
 */
#define SetADC8bitDataResolution() { \
	SetIOREGBitVar(IO_ADCRLH, S10, ADC_RES_8BITS); \
}

/**
 *	@def 		SetADC10bitDataResolution
 *	@brief 		ADC 10-bit Data Resolution Setter.
 * 	@param		.
 * 	@return		.
 */
#define SetADC10bitDataResolution() { \
	SetIOREGBitVar(IO_ADCRLH, S10, ADC_RES_10BITS); \
}

/**
 *	@def 		ReadADC8bitData
 *	@brief 		A/D Conversion 8-bit Data Reader.
 * 	@param		.
 * 	@return		8 bits A/D conversion (byte).
 */
#define ReadADC8bitData()		GetIOREGByteVar(IO_ADCRLH, DATA8)

/**
 *	@def 		ReadADC10bitData
 *	@brief 		A/D Conversion 10-bit Data Reader.
 * 	@param		.
 * 	@return		10 bits A/D conversion (word).
 */
#define ReadADC10bitData()		GetIOREGWordVar(IO_ADCRLH, DATA10)

#endif /* ADC_IO_H. */
