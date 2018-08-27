/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Common CPU Operation											             */
/**
 *	@file		MCU/cpu.h
 * 	@brief		This file contains inline assembly macro functions of
 * 				common CPU operations.
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

#ifndef CPU_H
#define CPU_H

/* ----------------------------------------------------------------------------
**	CPU Inline Assembly Macro Functions.
*/

/**
 * 	@def		NoOperation
 * 	@brief		Executes "no operation" command in 1 machine cycle.
 * 	@param		.
 * 	@return		.
 * 	@see		__wait_nop()
 */
#define NoOperation() { \
	__asm("	NOP "); \
}

/**
 * 	@def		EnableGlobalInterrupt
 * 	@brief		Sets interrupt enable flag of PS-CCR.
 * 	@param		.
 * 	@return		.
 * 	@note		All interrupts except software interrupts are enabled when
 * 				the interrupt enable flag (CCR: I) is set to "1". This flag
 * 				is cleared to "0" by a reset.
 * 	@see		__EI()
 */
#define EnableGlobalInterrupt() { \
	__asm("	OR		CCR, #H'40 "); \
}

/**
 * 	@def		DisableGlobalInterrupt
 * 	@brief		Clears interrupt enable flag of PS-CCR.
 * 	@param		.
 * 	@return		.
 * 	@note		All interrupts except software interrupts are disabled when
 * 				the interrupt enable flag is set to "0". This flag is cleared
 * 				to "0" by a reset.
 * 	@see		__DI()
 */
#define DisableGlobalInterrupt() { \
	__asm("	AND		CCR, #H'BF "); \
}

/**
 * 	@def		SetInterruptLevelMask
 * 	@brief		Sets interrupt level mask register (ILM) which indicates
 * 				the level of an interrupt that the CPU is accepting for
 * 				comparison with the values of the interrupt level setting
 * 				bits set according to interrupt requests from each resource.
 * 	@param[in]	VAL		Interrupt Level Mask (byte, digit only).
 * 	@return		.
 * 	@see		__set_il(#)
 */
#define SetInterruptLevelMask(VAL) { \
	__asm("	MOV		ILM, #"#VAL); \
}

/**
 * 	@def		SaveProcessorStatus
 * 	@brief		Saves current processor status (PS) pushed to stack.
 * 	@param		.
 * 	@return		.
 */
#define SaveProcessorStatus() { \
	__asm("	PUSHW	PS "); \
}

/**
 * 	@def		RestoreProcessorStatus
 * 	@brief		Restores (previous) processor status (PS) popped from stack.
 * 	@param		.
 * 	@return		.
 */
#define RestoreProcessorStatus() { \
	__asm("	POPW	PS "); \
}

/**
 * 	@def		EnterCriticalSection
 * 	@brief		Enters critical code section by saving current processor
 * 				status and disabling some interrupts that may affect execution.
 * 	@param		.
 * 	@return		.
 */
#define EnterCriticalSection() { \
	SaveProcessorStatus(); \
	SetInterruptLevelMask(6); \
}

/**
 * 	@def		ExitCriticalSection
 * 	@brief		Exits from critical code section by restoring processor	status.
 * 	@param		.
 * 	@return		.
 */
#define ExitCriticalSection() { \
	RestoreProcessorStatus(); \
}

/**
 * 	@def		ReturnFromInterrupt
 * 	@brief		Return from interrupt which only applies to functions called
 * 				within a NOSAVEREG interrupt.
 * 	@param		.
 * 	@return		.
 */
#define ReturnFromInterrupt() { \
	__asm("	RETI "); \
}

#endif /* CPU_H. */
