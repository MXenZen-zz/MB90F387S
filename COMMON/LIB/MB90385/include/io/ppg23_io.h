/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Programmable Pulse Generator Ch 2 and Ch 3					             */
/**
 *	@file		IO/ppg23_io.h
 *	@brief		This file contains getters and setters, and other macro
 *				functions for PPG23, PPG2, and PPG3 IO registers.
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

#ifndef PPG23_IO_H
#define PPG23_IO_H

#include <IO/ppg_types.h>

/* ----------------------------------------------------------------------------
**	PPG23 IO Getters and Setters.
*/

/**
 *	@def		GetPPG_PPGC23
 *	@brief		PPG23 Operation Mode Control Register Getter.
 * 	@param 		.
 * 	@return		PPGC23 (word).
 */
#define GetPPG_PPGC23()			GetIOREGWord(IO_PPGC23)

/**
 *	@def		GetPPG23
 *	@brief		PPG23 Count Clock Select Register Getter.
 * 	@param 		.
 * 	@return		PPG23 (byte).
 */
#define GetPPG23()				GetIOREGByte(IO_PPG23)

/**
 *	@def		GetPPG_PRL23
 *	@brief		PPG23 PPG Reload Register Getter.
 * 	@param 		.
 * 	@return		PRL23 (dword).
 */
#define GetPPG_PRL23()			GetIOREGDWord(IO_PRL23)

/**
 *	@def		SetPPG_PPGC23
 *	@brief 		PPG23 Operation Mode Control Register Setter.
 * 	@param 		VAL		Control bits for PPGC (word).
 * 	@return 	.
 */
#define SetPPG_PPGC23(VAL) { \
	SetIOREGWord(IO_PPGC23, VAL); \
}

/**
 *	@def		SetPPG23
 *	@brief		PPG23 Count Clock Select Register Setter.
 * 	@param[in]	VAL		Count clock selection bits for PPG (byte).
 * 	@return 	.
 */
#define SetPPG23(VAL) { \
	SetIOREGByte(IO_PPG23, VAL); \
}

/**
 *	@def		SetPPG_PRL23
 *	@brief		PPG23 Reload Register Setter.
 * 	@param[in]	VAL		Reload value for PRL (dword).
 * 	@return 	.
 */
#define SetPPG_PRL23(VAL) { \
	SetIOREGDWord(IO_PRL23, VAL); \
}

/* ----------------------------------------------------------------------------
**	PPG23 IO Register Fields Macro Functions (16-bit PPG Output).
*/

/**
 *	@def		StartPPG23
 *	@brief		Start Programmable Pulse Generator.
 * 	@param 		.
 * 	@return 	.
 */
#define StartPPG23() { \
	SetIOREGBitVar(IO_PPGC23, PEN1, PPG_OP_ENABLED); \
	SetIOREGBitVar(IO_PPGC23, PEN0, PPG_OP_ENABLED); \
}

/**
 *	@def		StopPPG23
 *	@brief		Stop Programmable Pulse Generator.
 * 	@param 		.
 * 	@return 	.
 */
#define StopPPG23() { \
	SetIOREGBitVar(IO_PPGC23, PEN1, PPG_OP_DISABLED); \
	SetIOREGBitVar(IO_PPGC23, PEN0, PPG_OP_DISABLED); \
}

/**
 *	@def		EnablePPG23Interrupt
 *	@brief 		Interrupt Enabler.
 * 	@param 		.
 * 	@return 	.
 */
#define EnablePPG23Interrupt() { \
	SetIOREGBitVar(IO_PPGC23, PIE1, PPG_INT_ENABLED); \
	SetIOREGBitVar(IO_PPGC23, PIE0, PPG_INT_ENABLED); \
}

/**
 *	@def		DisablePPG23Interrupt
 *	@brief		Interrupt Disabler.
 * 	@param 		.
 * 	@return 	.
 */
#define DisablePPG23Interrupt() { \
	SetIOREGBitVar(IO_PPGC23, PIE1, PPG_INT_DISABLED); \
	SetIOREGBitVar(IO_PPGC23, PIE0, PPG_INT_DISABLED); \
}

/**
 *	@def		ClearPPG23IRQ
 *	@brief		Clear Interrupt Underflow.
 * 	@param 		.
 * 	@return 	.
 */
#define ClearPPG23IRQ() { \
	SetIOREGBitVar(IO_PPGC23, PUF1, PPG_IRQ_CLEARED); \
	SetIOREGBitVar(IO_PPGC23, PUF0, PPG_IRQ_CLEARED); \
}

/**
 *	@def		EnablePPG23Output
 *	@brief		Pin Output Enabler.
 * 	@param 		.
 * 	@return 	.
 */
#define EnablePPG23Output() { \
	SetIOREGBitVar(IO_PPGC23, PE1, PPG_PIN_ENABLED); \
	SetIOREGBitVar(IO_PPGC23, PE0, PPG_PIN_ENABLED); \
}

/**
 *	@def		DisablePPG23Output
 *	@brief		Pin Output Disabler.
 * 	@param 		.
 * 	@return 	.
 */
#define DisablePPG23Output() { \
	SetIOREGBitVar(IO_PPGC23, PE1, PPG_PIN_GPIO); \
	SetIOREGBitVar(IO_PPGC23, PE0, PPG_PIN_GPIO); \
}

/**
 *	@def		GetPPG23OperationMode
 *	@brief		Operation Mode Getter.
 * 	@param		.
 * 	@return 	Operation mode (bits).
 */
#define GetPPG23OperationMode() \
	GetIOREGBitVar(IO_PPGC23, MD)

/**
 *	@def		SetPPG23OperationMode
 *	@brief		Operation Mode Setter.
 * 	@param[in]	VAL		Operation mode (bits).
 * 	@return 	.
 */
#define SetPPG23OperationMode(VAL) { \
	SetIOREGBitVar(IO_PPGC23, MD, VAL); \
}

/**
 *	@def		GetPPG23CommonCountClock
 *	@brief		Common Count Clock Getter.
 * 	@param		.
 * 	@return 	count clock (bits).
 */
#define GetPPG23CommonCountClock() \
	GetIOREGBitVar(IO_PPG23, PCM)

/**
 *	@def		SetPPG23CountClock
 *	@brief		Count Clock Setter.
 * 	@param[in]	VAL		Count clock (bits).
 * 	@return 	.
 */
#define SetPPG23CountClock(VAL) { \
	SetIOREGBitVar(IO_PPG23, PCM, VAL); \
	SetIOREGBitVar(IO_PPG23, PCS, VAL); \
}

/**
 *	@def		SetPPG23ReloadDWord
 *	@brief		Reload Value Setter.
 * 	@param[in]	VAL		Reload value (dword).
 * 	@return 	.
 */
#define SetPPG23ReloadDWord(VAL) { \
	SetIOREGDWord(IO_PRL23, VAL); \
}

/**
 *	@def		SetPPG23ReloadWords
 *	@brief		Reload Value Setter.
 * 	@param[in]	LVAL Reload value (low word).
 * 	@param[in]	HVAL Reload value (high word).
 * 	@return 	.
 */
#define SetPPG23ReloadWords(LVAL, HVAL) { \
	SetIOREGWordVar(IO_PRL23, PRL2, (LVAL)); \
	SetIOREGWordVar(IO_PRL23, PRL3, (HVAL)); \
}

/* ----------------------------------------------------------------------------
**	PPG2 IO Register Fields Macro Functions (8-bit Independent PPG Output).
*/

/**
 *	@def		StartPPG2
 *	@brief		Start Programmable Pulse Generator.
 * 	@param 		.
 * 	@return 	.
 */
#define StartPPG2() { \
	SetIOREGBitVar(IO_PPGC23, PEN0, PPG_OP_ENABLED); \
}

/**
 *	@def		StopPPG2
 *	@brief		Stop Programmable Pulse Generator.
 * 	@param 		.
 * 	@return 	.
 */
#define StopPPG2() { \
	SetIOREGBitVar(IO_PPGC23, PEN0, PPG_OP_DISABLED); \
}

/**
 *	@def		EnablePPG2Interrupt
 *	@brief		Interrupt Enabler.
 * 	@param 		.
 * 	@return 	.
 */
#define EnablePPG2Interrupt() { \
	SetIOREGBitVar(IO_PPGC23, PIE0, PPG_INT_ENABLED); \
}

/**
 *	@def		DisablePPG2Interrupt
 *	@brief		Interrupt Disabler.
 * 	@param 		.
 * 	@return 	.
 */
#define DisablePPG2Interrupt() { \
	SetIOREGBitVar(IO_PPGC23, PIE0, PPG_INT_DISABLED); \
}

/**
 *	@def		IsPPG2IRQActive
 *	@brief		Check if PPG2 interrupt request is active.
 * 	@param 		.
 * 	@return 	boolean.
 */
#define IsPPG2IRQActive() \
	EQU(GetIOREGBitVar(IO_PPGC23, PUF0), PPG_IRQ_UNDERFLOWED)

/**
 *	@def		ClearPPG2IRQ
 *	@brief		Clear Interrupt Underflow.
 * 	@param 		.
 * 	@return 	.
 */
#define ClearPPG2IRQ() { \
	SetIOREGBitVar(IO_PPGC23, PUF0, PPG_IRQ_CLEARED); \
}

/**
 *	@def		EnablePPG2Output
 *	@brief		Pin Output Enabler.
 * 	@param 		.
 * 	@return 	.
 */
#define EnablePPG2Output() { \
	SetIOREGBitVar(IO_PPGC23, PE0, PPG_PIN_ENABLED); \
}

/**
 *	@def		DisablePPG2Output
 *	@brief		Pin Output Disabler.
 * 	@param 		.
 * 	@return 	.
 */
#define DisablePPG2Output() { \
	SetIOREGBitVar(IO_PPGC23, PE0, PPG_PIN_GPIO);  \
}

/**
 *	@def		SetPPG2CountClock
 *	@brief		Count Clock Setter.
 * 	@param[in]	VAL		Count clock (bits).
 * 	@return 	.
 */
#define SetPPG2CountClock(VAL) { \
	SetIOREGBitVar(IO_PPG23, PCM, VAL); \
}

/**
 *	@def		GetPPG2ReloadWord
 *	@brief		Reload Value Getter.
 * 	@param		.
 * 	@return 	reload (word).
 */
#define GetPPG2ReloadWord() \
	GetIOREGWordVar(IO_PRL23, PRL2)

/**
 *	@def		SetPPG2ReloadWord
 *	@brief		Reload Value Setter.
 * 	@param[in]	VAL		Reload value (word).
 * 	@return 	.
 */
#define SetPPG2ReloadWord(VAL) { \
	SetIOREGWordVar(IO_PRL23, PRL2, VAL); \
}

/* ----------------------------------------------------------------------------
**	PPG3 IO Register Fields Macro Functions (8-bit Independent PPG Output).
*/

/**
 *	@def		StartPPG3
 *	@brief		Start Programmable Pulse Generator.
 * 	@param 		.
 * 	@return 	.
 */
#define StartPPG3() { \
	SetIOREGBitVar(IO_PPGC23, PEN1, PPG_OP_ENABLED); \
}

/**
 *	@def		StopPPG3
 *	@brief		Stop Programmable Pulse Generator.
 * 	@param 		.
 * 	@return 	.
 */
#define StopPPG3() { \
	SetIOREGBitVar(IO_PPGC23, PEN1, PPG_OP_DISABLED); \
}

/**
 *	@def		EnablePPG3Interrupt
 *	@brief		Interrupt Enabler.
 * 	@param 		.
 * 	@return 	.
 */
#define EnablePPG3Interrupt() { \
	SetIOREGBitVar(IO_PPGC23, PIE1, PPG_INT_ENABLED); \
}

/**
 *	@def		DisablePPG3Interrupt
 *	@brief		Interrupt Disabler.
 * 	@param 		.
 * 	@return 	.
 */
#define DisablePPG3Interrupt() { \
	SetIOREGBitVar(IO_PPGC23, PIE1, PPG_INT_DISABLED); \
}

/**
 *	@def		IsPPG3IRQActive
 *	@brief		Check if PPG3 interrupt request is active.
 * 	@param 		.
 * 	@return 	boolean.
 */
#define IsPPG3IRQActive() \
	EQU(GetIOREGBitVar(IO_PPGC23, PUF1), PPG_IRQ_UNDERFLOWED)

/**
 *	@def		ClearPPG3IRQ
 *	@brief		Clear Interrupt Underflow.
 * 	@param 		.
 * 	@return 	.
 */
#define ClearPPG3IRQ() { \
	SetIOREGBitVar(IO_PPGC23, PUF1, PPG_IRQ_CLEARED); \
}

/**
 *	@def		EnablePPG3Output
 *	@brief		Pin Output Enabler.
 * 	@param 		.
 * 	@return 	.
 */
#define EnablePPG3Output() { \
	SetIOREGBitVar(IO_PPGC23, PE1, PPG_PIN_ENABLED); \
}

/**
 *	@def		DisablePPG3Output
 *	@brief		Pin Output Disabler.
 * 	@param 		.
 * 	@return 	.
 */
#define DisablePPG3Output() { \
	SetIOREGBitVar(IO_PPGC23, PE1, PPG_PIN_GPIO);  \
}

/**
 *	@def		SetPPG3CountClock
 *	@brief		Count Clock Setter.
 * 	@param[in]	VAL		Count clock (bits).
 * 	@return 	.
 */
#define SetPPG3CountClock(VAL) { \
	SetIOREGBitVar(IO_PPG23, PCS, VAL); \
}

/**
 *	@def		GetPPG3ReloadWord
 *	@brief		Reload Value Getter.
 * 	@param		.
 * 	@return 	reload (word).
 */
#define GetPPG3ReloadWord() \
	GetIOREGWordVar(IO_PRL23, PRL3)

/**
 *	@def		SetPPG3ReloadWord
 *	@brief		Reload Value Setter.
 * 	@param[in]	VAL		Reload value (word).
 * 	@return 	.
 */
#define SetPPG3ReloadWord(VAL) { \
	SetIOREGWordVar(IO_PRL23, PRL3, VAL); \
}

#endif /* PPG23_IO_H. */
