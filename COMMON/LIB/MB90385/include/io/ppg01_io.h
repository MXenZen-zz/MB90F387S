/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Programmable Pulse Generator Ch 0 and Ch 1					             */
/**
 *	@file		IO/ppg01_io.h
 *	@brief		This file contains getters and setters, and other macro
 *				functions for PPG01, PPG0, and PPG1 IO registers.
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

#ifndef PPG01_IO_H
#define PPG01_IO_H

#include <IO/ppg_types.h>

/* ----------------------------------------------------------------------------
**	PPG01 IO Getters and Setters.
*/

/**
 *	@def		GetPPG_PPGC01
 *	@brief		PPG01 Operation Mode Control Register Getter.
 * 	@param 		.
 * 	@return		PPGC01 (word).
 */
#define GetPPG_PPGC01()			GetIOREGWord(IO_PPGC01)

/**
 *	@def		GetPPG01
 *	@brief		PPG01 Count Clock Select Register Getter.
 * 	@param 		.
 * 	@return		PPG01 (byte).
 */
#define GetPPG01()				GetIOREGByte(IO_PPG01)

/**
 *	@def		GetPPG_PRL01
 *	@brief		PPG01 PPG Reload Register Getter.
 * 	@param 		.
 * 	@return		PRL01 (dword).
 */
#define GetPPG_PRL01()			GetIOREGDWord(IO_PRL01)

/**
 *	@def		SetPPG_PPGC01
 *	@brief 		PPG01 Operation Mode Control Register Setter.
 * 	@param 		VAL		Control bits for PPGC (word).
 * 	@return 	.
 */
#define SetPPG_PPGC01(VAL) { \
	SetIOREGWord(IO_PPGC01, VAL); \
}

/**
 *	@def		SetPPG01
 *	@brief		PPG01 Count Clock Select Register Setter.
 * 	@param[in]	VAL		Count clock selection bits for PPG (byte).
 * 	@return 	.
 */
#define SetPPG01(VAL) { \
	SetIOREGByte(IO_PPG01, VAL); \
}

/**
 *	@def		SetPPG_PRL01
 *	@brief		PPG01 Reload Register Setter.
 * 	@param[in]	VAL		Reload value for PRL (dword).
 * 	@return 	.
 */
#define SetPPG_PRL01(VAL) { \
	SetIOREGDWord(IO_PRL01, VAL); \
}

/* ----------------------------------------------------------------------------
**	PPG01 IO Register Fields Macro Functions (16-bit PPG Output).
*/

/**
 *	@def		StartPPG01
 *	@brief		Start Programmable Pulse Generator.
 * 	@param 		.
 * 	@return 	.
 */
#define StartPPG01() { \
	SetIOREGBitVar(IO_PPGC01, PEN1, PPG_OP_ENABLED); \
	SetIOREGBitVar(IO_PPGC01, PEN0, PPG_OP_ENABLED); \
}

/**
 *	@def		StopPPG01
 *	@brief		Stop Programmable Pulse Generator.
 * 	@param 		.
 * 	@return 	.
 */
#define StopPPG01() { \
	SetIOREGBitVar(IO_PPGC01, PEN1, PPG_OP_DISABLED); \
	SetIOREGBitVar(IO_PPGC01, PEN0, PPG_OP_DISABLED); \
}

/**
 *	@def		EnablePPG01Interrupt
 *	@brief 		Interrupt Enabler.
 * 	@param 		.
 * 	@return 	.
 */
#define EnablePPG01Interrupt() { \
	SetIOREGBitVar(IO_PPGC01, PIE1, PPG_INT_ENABLED); \
	SetIOREGBitVar(IO_PPGC01, PIE0, PPG_INT_ENABLED); \
}

/**
 *	@def		DisablePPG01Interrupt
 *	@brief		Interrupt Disabler.
 * 	@param 		.
 * 	@return 	.
 */
#define DisablePPG01Interrupt() { \
	SetIOREGBitVar(IO_PPGC01, PIE1, PPG_INT_DISABLED); \
	SetIOREGBitVar(IO_PPGC01, PIE0, PPG_INT_DISABLED); \
}

/**
 *	@def		ClearPPG01IRQ
 *	@brief		Clear Interrupt Underflow.
 * 	@param 		.
 * 	@return 	.
 */
#define ClearPPG01IRQ() { \
	SetIOREGBitVar(IO_PPGC01, PUF1, PPG_IRQ_CLEARED); \
	SetIOREGBitVar(IO_PPGC01, PUF0, PPG_IRQ_CLEARED); \
}

/**
 *	@def		EnablePPG01Output
 *	@brief		Pin Output Enabler.
 * 	@param 		.
 * 	@return 	.
 */
#define EnablePPG01Output() { \
	SetIOREGBitVar(IO_PPGC01, PE1, PPG_PIN_ENABLED); \
	SetIOREGBitVar(IO_PPGC01, PE0, PPG_PIN_ENABLED); \
}

/**
 *	@def		DisablePPG01Output
 *	@brief		Pin Output Disabler.
 * 	@param 		.
 * 	@return 	.
 */
#define DisablePPG01Output() { \
	SetIOREGBitVar(IO_PPGC01, PE1, PPG_PIN_GPIO); \
	SetIOREGBitVar(IO_PPGC01, PE0, PPG_PIN_GPIO); \
}

/**
 *	@def		GetPPG01OperationMode
 *	@brief		Operation Mode Getter.
 * 	@param		.
 * 	@return 	Operation mode (bits).
 */
#define GetPPG01OperationMode() \
	GetIOREGBitVar(IO_PPGC01, MD)

/**
 *	@def		SetPPG01OperationMode
 *	@brief		Operation Mode Setter.
 * 	@param[in]	VAL		Operation mode (bits).
 * 	@return 	.
 */
#define SetPPG01OperationMode(VAL) { \
	SetIOREGBitVar(IO_PPGC01, MD, VAL); \
}

/**
 *	@def		GetPPG01CommonCountClock
 *	@brief		Common Count Clock Getter.
 * 	@param		.
 * 	@return 	count clock (bits).
 */
#define GetPPG01CommonCountClock() \
	GetIOREGBitVar(IO_PPG01, PCM)

/**
 *	@def		SetPPG01CountClock
 *	@brief		Count Clock Setter.
 * 	@param[in]	VAL		Count clock (bits).
 * 	@return 	.
 */
#define SetPPG01CountClock(VAL) { \
	SetIOREGBitVar(IO_PPG01, PCM, VAL); \
	SetIOREGBitVar(IO_PPG01, PCS, VAL); \
}

/**
 *	@def		SetPPG01ReloadDWord
 *	@brief		Reload Value Setter.
 * 	@param[in]	VAL		Reload value (dword).
 * 	@return 	.
 */
#define SetPPG01ReloadDWord(VAL) { \
	SetIOREGDWord(IO_PRL01, VAL); \
}

/**
 *	@def		SetPPG01ReloadWords
 *	@brief		Reload Value Setter.
 * 	@param[in]	LVAL Reload value (low word).
 * 	@param[in]	HVAL Reload value (high word).
 * 	@return 	.
 */
#define SetPPG01ReloadWords(LVAL, HVAL) { \
	SetIOREGWordVar(IO_PRL01, PRL0, (LVAL)); \
	SetIOREGWordVar(IO_PRL01, PRL1, (HVAL)); \
}

/* ----------------------------------------------------------------------------
**	PPG0 IO Register Fields Macro Functions (8-bit Independent PPG Output).
*/

/**
 *	@def		StartPPG0
 *	@brief		Start Programmable Pulse Generator.
 * 	@param 		.
 * 	@return 	.
 */
#define StartPPG0() { \
	SetIOREGBitVar(IO_PPGC01, PEN0, PPG_OP_ENABLED); \
}

/**
 *	@def		StopPPG0
 *	@brief		Stop Programmable Pulse Generator.
 * 	@param 		.
 * 	@return 	.
 */
#define StopPPG0() { \
	SetIOREGBitVar(IO_PPGC01, PEN0, PPG_OP_DISABLED); \
}

/**
 *	@def		EnablePPG0Interrupt
 *	@brief		Interrupt Enabler.
 * 	@param 		.
 * 	@return 	.
 */
#define EnablePPG0Interrupt() { \
	SetIOREGBitVar(IO_PPGC01, PIE0, PPG_INT_ENABLED); \
}

/**
 *	@def		DisablePPG0Interrupt
 *	@brief		Interrupt Disabler.
 * 	@param 		.
 * 	@return 	.
 */
#define DisablePPG0Interrupt() { \
	SetIOREGBitVar(IO_PPGC01, PIE0, PPG_INT_DISABLED); \
}

/**
 *	@def		IsPPG0IRQActive
 *	@brief		Check if PPG0 interrupt request is active.
 * 	@param 		.
 * 	@return 	boolean.
 */
#define IsPPG0IRQActive() \
	EQU(GetIOREGBitVar(IO_PPGC01, PUF0), PPG_IRQ_UNDERFLOWED)

/**
 *	@def		ClearPPG0IRQ
 *	@brief		Clear Interrupt Underflow.
 * 	@param 		.
 * 	@return 	.
 */
#define ClearPPG0IRQ() { \
	SetIOREGBitVar(IO_PPGC01, PUF0, PPG_IRQ_CLEARED); \
}

/**
 *	@def		EnablePPG0Output
 *	@brief		Pin Output Enabler.
 * 	@param 		.
 * 	@return 	.
 */
#define EnablePPG0Output() { \
	SetIOREGBitVar(IO_PPGC01, PE0, PPG_PIN_ENABLED); \
}

/**
 *	@def		DisablePPG0Output
 *	@brief		Pin Output Disabler.
 * 	@param 		.
 * 	@return 	.
 */
#define DisablePPG0Output() { \
	SetIOREGBitVar(IO_PPGC01, PE0, PPG_PIN_GPIO);  \
}

/**
 *	@def		SetPPG0CountClock
 *	@brief		Count Clock Setter.
 * 	@param[in]	VAL		Count clock (bits).
 * 	@return 	.
 */
#define SetPPG0CountClock(VAL) { \
	SetIOREGBitVar(IO_PPG01, PCM, VAL); \
}

/**
 *	@def		GetPPG0ReloadWord
 *	@brief		Reload Value Getter.
 * 	@param		.
 * 	@return 	reload (word).
 */
#define GetPPG0ReloadWord() \
	GetIOREGWordVar(IO_PRL01, PRL0)

/**
 *	@def		SetPPG0ReloadWord
 *	@brief		Reload Value Setter.
 * 	@param[in]	VAL		Reload value (word).
 * 	@return 	.
 */
#define SetPPG0ReloadWord(VAL) { \
	SetIOREGWordVar(IO_PRL01, PRL0, VAL); \
}

/* ----------------------------------------------------------------------------
**	PPG1 IO Register Fields Macro Functions (8-bit Independent PPG Output).
*/

/**
 *	@def		StartPPG1
 *	@brief		Start Programmable Pulse Generator.
 * 	@param 		.
 * 	@return 	.
 */
#define StartPPG1() { \
	SetIOREGBitVar(IO_PPGC01, PEN1, PPG_OP_ENABLED); \
}

/**
 *	@def		StopPPG1
 *	@brief		Stop Programmable Pulse Generator.
 * 	@param 		.
 * 	@return 	.
 */
#define StopPPG1() { \
	SetIOREGBitVar(IO_PPGC01, PEN1, PPG_OP_DISABLED); \
}

/**
 *	@def		EnablePPG1Interrupt
 *	@brief		Interrupt Enabler.
 * 	@param 		.
 * 	@return 	.
 */
#define EnablePPG1Interrupt() { \
	SetIOREGBitVar(IO_PPGC01, PIE1, PPG_INT_ENABLED); \
}

/**
 *	@def		DisablePPG1Interrupt
 *	@brief		Interrupt Disabler.
 * 	@param 		.
 * 	@return 	.
 */
#define DisablePPG1Interrupt() { \
	SetIOREGBitVar(IO_PPGC01, PIE1, PPG_INT_DISABLED); \
}

/**
 *	@def		IsPPG1IRQActive
 *	@brief		Check if PPG1 interrupt request is active.
 * 	@param 		.
 * 	@return 	boolean.
 */
#define IsPPG1IRQActive() \
	EQU(GetIOREGBitVar(IO_PPGC01, PUF1), PPG_IRQ_UNDERFLOWED)

/**
 *	@def		ClearPPG1IRQ
 *	@brief		Clear Interrupt Underflow.
 * 	@param 		.
 * 	@return 	.
 */
#define ClearPPG1IRQ() { \
	SetIOREGBitVar(IO_PPGC01, PUF1, PPG_IRQ_CLEARED); \
}

/**
 *	@def		EnablePPG1Output
 *	@brief		Pin Output Enabler.
 * 	@param 		.
 * 	@return 	.
 */
#define EnablePPG1Output() { \
	SetIOREGBitVar(IO_PPGC01, PE1, PPG_PIN_ENABLED); \
}

/**
 *	@def		DisablePPG1Output
 *	@brief		Pin Output Disabler.
 * 	@param 		.
 * 	@return 	.
 */
#define DisablePPG1Output() { \
	SetIOREGBitVar(IO_PPGC01, PE1, PPG_PIN_GPIO);  \
}

/**
 *	@def		SetPPG1CountClock
 *	@brief		Count Clock Setter.
 * 	@param[in]	VAL		Count clock (bits).
 * 	@return 	.
 */
#define SetPPG1CountClock(VAL) { \
	SetIOREGBitVar(IO_PPG01, PCS, VAL); \
}

/**
 *	@def		GetPPG1ReloadWord
 *	@brief		Reload Value Getter.
 * 	@param		.
 * 	@return 	reload (word).
 */
#define GetPPG1ReloadWord() \
	GetIOREGWordVar(IO_PRL01, PRL1)

/**
 *	@def		SetPPG1ReloadWord
 *	@brief		Reload Value Setter.
 * 	@param[in]	VAL		Reload value (word).
 * 	@return 	.
 */
#define SetPPG1ReloadWord(VAL) { \
	SetIOREGWordVar(IO_PRL01, PRL1, VAL); \
}

#endif /* PPG01_IO_H. */
