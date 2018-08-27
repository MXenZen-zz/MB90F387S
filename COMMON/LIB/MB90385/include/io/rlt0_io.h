/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* 16-bit Reload Timer Ch 0		 								             */
/**
 *	@file		IO/rlt0_io.h
 *	@brief		This file contains getters and setters, and other macro
 *				functions for RLT0 IO register.
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

#ifndef RLT0_IO_H
#define RLT0_IO_H

#include <IO/rlt_types.h>

/* ----------------------------------------------------------------------------
**	RLT0 IO Getters and Setters.
*/

/**
 *	@def		GetRLT_TMCSR0
 *	@brief		RLT0 Control Status Register Getter.
 * 	@param		.
 * 	@return		TMCSR0 (word).
 */
#define GetRLT_TMCSR0()			GetIOREGWord(IO_TMCSR0)

/**
 *	@def		GetRLT_TMR0
 *	@brief		RLT0 Count Register Getter.
 * 	@param		.
 * 	@return		IO_TMR[0] (word).
 */
#define GetRLT_TMR0()			GetIOREG(IO_TMR[0])

/**
 *	@def		SetRLT_TMCSR0
 *	@brief		RLT0 Control Status Register Setter.
 * 	@param[in]	VAL		Control bits for timer (word).
 * 	@return		.
 */
#define SetRLT_TMCSR0(VAL) { \
	SetIOREGWord(IO_TMCSR0, VAL); \
}

/**
 *	@def		SetRLT_TMR0
 *	@brief		RLT0 Count Register Setter.
 * 	@param[in]	VAL		Reload value for timer (word).
 * 	@return		.
 */
#define SetRLT_TMR0(VAL) { \
	SetIOREG(IO_TMR[0], (T_word)(VAL)); \
}

/* ----------------------------------------------------------------------------
**	RLT0 IO Register Fields Macro Functions.
*/

/**
 *	@def		StartRLT0Software
 *	@brief		Start Reload Timer.
 * 	@param		.
 * 	@return		.
 */
#define StartRLT0Software() { \
	SetIOREGBitVar(IO_TMCSR0, CNTE, RLT_OP_ENABLED); \
	SetIOREGBitVar(IO_TMCSR0, TRG, RLT_TRIG_SW_START); \
}

/**
 *	@def		StartRLT0Counter
 *	@brief		Enabled Reload Timer Counter.
 * 	@param		.
 * 	@return		.
 */
#define StartRLT0Counter() { \
	SetIOREGBitVar(IO_TMCSR0, CNTE, RLT_OP_ENABLED); \
}

/**
 *	@def		StopRLT0
 *	@brief		Stop Reload Timer.
 * 	@param		.
 * 	@return		.
 */
#define StopRLT0() { \
	SetIOREGBitVar(IO_TMCSR0, CNTE, RLT_OP_DISABLED); \
}

/**
 *	@def		ClearRLT0IRQ
 *	@brief		Clear Interrupt Underflow.
 * 	@param		.
 * 	@return		.
 */
#define ClearRLT0IRQ() { \
	SetIOREGBitVar(IO_TMCSR0, UF, RLT_IRQ_CLEARED); \
}

/**
 *	@def		EnableRLT0Interrupt
 *	@brief		Reload Timer Interrupt Enabler.
 * 	@param		.
 * 	@return		.
 */
#define EnableRLT0Interrupt() { \
	SetIOREGBitVar(IO_TMCSR0, INTE, RLT_INT_ENABLED); \
}

/**
 *	@def		DisableRLT0Interrupt
 *	@brief		Reload Timer Interrupt Disabler.
 * 	@param		.
 * 	@return		.
 */
#define DisableRLT0Interrupt() { \
	SetIOREGBitVar(IO_TMCSR0, INTE, RLT_INT_DISABLED); \
}

/**
 *	@def		IsRLT0OneShotMode
 *	@brief		Check if RLT0 Mode is One Shot.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsRLT0OneShotMode() \
	EQU(GetIOREGBitVar(IO_TMCSR0, RELD), RLT_ONESHOT) \

/**
 *	@def		SetRLT0OneShotMode
 *	@brief		One Shot Mode Setter.
 * 	@param		.
 * 	@return		.
 */
#define SetRLT0OneShotMode() { \
	SetIOREGBitVar(IO_TMCSR0, RELD, RLT_ONESHOT); \
}

/**
 *	@def		IsRLT0ReloadMode
 *	@brief		Check if RLT0 Mode is Reload.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsRLT0ReloadMode() \
	EQU(GetIOREGBitVar(IO_TMCSR0, RELD), RLT_RELOAD) \

/**
 *	@def		SetRLT0ReloadMode
 *	@brief		Reload Mode Setter.
 * 	@param		.
 * 	@return		.
 */
#define SetRLT0ReloadMode() { \
	SetIOREGBitVar(IO_TMCSR0, RELD, RLT_RELOAD); \
}

/**
 *	@def		EnableRLT0TOTPinOutput
 *	@brief		TOT Pin Output Enabler.
 * 	@param[in]	VAL		TOT pin output level (bits).
 * 	@return		.
 */
#define EnableRLT0TOTPinOutput(VAL) { \
	SetIOREGBitVar(IO_TMCSR0, OUTL, VAL); \
	SetIOREGBitVar(IO_TMCSR0, OUTE, RLT_TOT_ENABLED); \
}

/**
 *	@def		DisableRLT0TOTPinOutput
 *	@brief		TOT Pin Output Disabler.
 * 	@param		.
 * 	@return		.
 */
#define DisableRLT0TOTPinOutput() { \
	SetIOREGBitVar(IO_TMCSR0, OUTE, RLT_TOT_GPIO); \
}

/**
 *	@def		SetRLT0OperationMode
 *	@brief		Timer Operation Mode Setter.
 * 	@param[in]	VAL		Operation mode (bits).
 * 	@return		.
 */
#define SetRLT0OperationMode(VAL) { \
	SetIOREGBitVar(IO_TMCSR0, MOD, VAL); \
}

/**
 *	@def		SetRLT0CountClock
 *	@brief		Count Clock Setter.
 * 	@param[in] 	VAL		Count clock (bits).
 * 	@return		.
 */
#define SetRLT0CountClock(VAL) { \
	SetIOREGBitVar(IO_TMCSR0, CSL, VAL); \
}

#endif /* RLT0_IO_H. */
