/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* 16-bit Reload Timer Ch 1		 								             */
/**
 *	@file		IO/rlt1_io.h
 *	@brief		This file contains getters and setters, and other macro
 *				functions for RLT1 IO register.
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

#ifndef RLT1_IO_H
#define RLT1_IO_H

#include <IO/rlt_types.h>

/* ----------------------------------------------------------------------------
**	RLT1 IO Getters and Setters.
*/

/**
 *	@def		GetRLT_TMCSR1
 *	@brief		RLT1 Control Status Register Getter.
 * 	@param		.
 * 	@return		TMCSR1 (word).
 */
#define GetRLT_TMCSR1()			GetIOREGWord(IO_TMCSR1)

/**
 *	@def		GetRLT_TMR1
 *	@brief		RLT1 Count Register Getter.
 * 	@param		.
 * 	@return		IO_TMR[1] (word).
 */
#define GetRLT_TMR1()			GetIOREG(IO_TMR[1])

/**
 *	@def		SetRLT_TMCSR1
 *	@brief		RLT1 Control Status Register Setter.
 * 	@param[in]	VAL		Control bits for timer (word).
 * 	@return		.
 */
#define SetRLT_TMCSR1(VAL) { \
	SetIOREGWord(IO_TMCSR1, VAL); \
}

/**
 *	@def		SetRLT_TMR1
 *	@brief		RLT1 Count Register Setter.
 * 	@param[in]	VAL		Reload value for timer (word).
 * 	@return		.
 */
#define SetRLT_TMR1(VAL) { \
	SetIOREG(IO_TMR[1], (T_word)(VAL)); \
}

/* ----------------------------------------------------------------------------
**	RLT1 IO Register Fields Macro Functions.
*/

/**
 *	@def		StartRLT1Software
 *	@brief		Start Reload Timer.
 * 	@param		.
 * 	@return		.
 */
#define StartRLT1Software() { \
	SetIOREGBitVar(IO_TMCSR1, CNTE, RLT_OP_ENABLED); \
	SetIOREGBitVar(IO_TMCSR1, TRG, RLT_TRIG_SW_START); \
}

/**
 *	@def		StartRLT1Counter
 *	@brief		Enabled Reload Timer Counter.
 * 	@param		.
 * 	@return		.
 */
#define StartRLT1Counter() { \
	SetIOREGBitVar(IO_TMCSR1, CNTE, RLT_OP_ENABLED); \
}

/**
 *	@def		StopRLT1
 *	@brief		Stop Reload Timer.
 * 	@param		.
 * 	@return		.
 */
#define StopRLT1() { \
	SetIOREGBitVar(IO_TMCSR1, CNTE, RLT_OP_DISABLED); \
}

/**
 *	@def		ClearRLT1IRQ
 *	@brief		Clear Interrupt Underflow.
 * 	@param		.
 * 	@return		.
 */
#define ClearRLT1IRQ() { \
	SetIOREGBitVar(IO_TMCSR1, UF, RLT_IRQ_CLEARED); \
}

/**
 *	@def		EnableRLT1Interrupt
 *	@brief		Reload Timer Interrupt Enabler.
 * 	@param		.
 * 	@return		.
 */
#define EnableRLT1Interrupt() { \
	SetIOREGBitVar(IO_TMCSR1, INTE, RLT_INT_ENABLED); \
}

/**
 *	@def		DisableRLT1Interrupt
 *	@brief		Reload Timer Interrupt Disabler.
 * 	@param		.
 * 	@return		.
 */
#define DisableRLT1Interrupt() { \
	SetIOREGBitVar(IO_TMCSR1, INTE, RLT_INT_DISABLED); \
}

/**
 *	@def		IsRLT1OneShotMode
 *	@brief		Check if RLT1 Mode is One Shot.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsRLT1OneShotMode() \
	EQU(GetIOREGBitVar(IO_TMCSR1, RELD), RLT_ONESHOT) \

/**
 *	@def		SetRLT1OneShotMode
 *	@brief		One Shot Mode Setter.
 * 	@param		.
 * 	@return		.
 */
#define SetRLT1OneShotMode() { \
	SetIOREGBitVar(IO_TMCSR1, RELD, RLT_ONESHOT); \
}

/**
 *	@def		IsRLT1ReloadMode
 *	@brief		Check if RLT1 Mode is Reload.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsRLT1ReloadMode() \
	EQU(GetIOREGBitVar(IO_TMCSR1, RELD), RLT_RELOAD) \

/**
 *	@def		SetRLT1ReloadMode
 *	@brief		Reload Mode Setter.
 * 	@param		.
 * 	@return		.
 */
#define SetRLT1ReloadMode() { \
	SetIOREGBitVar(IO_TMCSR1, RELD, RLT_RELOAD); \
}

/**
 *	@def		EnableRLT1TOTPinOutput
 *	@brief		TOT Pin Output Enabler
 * 	@param[in]	VAL		TOT pin output level (bits).
 * 	@return		.
 */
#define EnableRLT1TOTPinOutput(VAL) { \
	SetIOREGBitVar(IO_TMCSR1, OUTL, VAL); \
	SetIOREGBitVar(IO_TMCSR1, OUTE, RLT_TOT_ENABLED); \
}

/**
 *	@def		DisableRLT1TOTPinOutput
 *	@brief		TOT Pin Output Disabler.
 * 	@param		.
 * 	@return		.
 */
#define DisableRLT1TOTPinOutput() { \
	SetIOREGBitVar(IO_TMCSR1, OUTE, RLT_TOT_GPIO); \
}

/**
 *	@def		SetRLT1OperationMode
 *	@brief		Timer Operation Mode Setter.
 * 	@param[in]	VAL		Operation mode (bits).
 * 	@return		.
 */
#define SetRLT1OperationMode(VAL) { \
	SetIOREGBitVar(IO_TMCSR1, MOD, VAL); \
}

/**
 *	@def		SetRLT1CountClock
 *	@brief		Count Clock Setter.
 * 	@param[in] 	VAL		Count clock (bits).
 * 	@return		.
 */
#define SetRLT1CountClock(VAL) { \
	SetIOREGBitVar(IO_TMCSR1, CSL, VAL); \
}

#endif /* RLT1_IO_H. */
