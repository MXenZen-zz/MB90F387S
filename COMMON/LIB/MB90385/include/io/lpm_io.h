/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Low-power Consumption Mode 									             */
/**
 *	@file		IO/lpm_io.h
 * 	@brief		This file contains getters for LPM IO register and other
 * 				inline assembly macro functions.
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

#ifndef LPM_IO_H
#define LPM_IO_H

#include <IO/io_mb90385.h>
#include <_standby.h>

/* ----------------------------------------------------------------------------
**	LPM IO Getters.
*/

/**
 * 	@def		GetLPM_LPMCR
 * 	@brief		Low-power Consumption Mode Control Register Getter.
 * 	@param 		.
 * 	@return  	LPM (byte).
 */
#define GetLPM_LPMCR()			GetIOREGByte(IO_LPMCR)

/* ----------------------------------------------------------------------------
**	LPM Inline Assembly Standby Control Macro Functions.
*/

/**
 *	@def 		LPMStopModeHeldIO
 *	@brief 		Transits to stop mode with pin state held.
 * 	@param		.
 * 	@return		.
 */
#define LPMStopModeHeldIO() { \
	IO_STOP_HOLD; \
}

/**
 *	@def 		LPMStopModeHiZ
 *	@brief 		Transits to stop mode with pin state high impedance.
 * 	@param		.
 * 	@return		.
 */
#define LPMStopModeHiZ() { \
	IO_STOP_Z; \
}

/**
 *	@def 		LPMSleepMode
 *	@brief 		Transits to sleep mode.
 * 	@param		.
 * 	@return		.
 */
#define LPMSleepMode() { \
    IO_SLEEP; \
}

/**
 *	@def 		LPMTBTModeHeldIO
 *	@brief 		Transits to watch or timebase timer mode with pin state held.
 * 	@param		.
 * 	@return		.
 */
#define LPMTBTModeHeldIO() { \
	IO_TMD_HOLD; \
}

/**
 *	@def 		LPMTBTModeHiZ
 *	@brief 		Transits to watch or timebase timer mode with pin state high impedance.
 * 	@param		.
 * 	@return		.
 */
#define LPMTBTModeHiZ() { \
	IO_TMD_Z; \
}

/**
 *	@def 		LPMConfig
 *	@brief 		Set Low-power Consumption Mode Control.
 * 	@param[in]	VAL		Control bits for LPMCR (number only).
 * 	@return		.
 */
#define LPMConfig(VAL) { \
	IO_SET_LPMCR(VAL); \
}

/* ----------------------------------------------------------------------------
**	LPM Inline Assembly Software Reset Macro Functions.
*/

/**
 *	@def 		LPMReset
 *	@brief 		Generates internal reset signal of 3 machine cycles.
 * 	@param		.
 * 	@return		.
 */
#define LPMReset() { \
   IO_RESET; \
}

/* ----------------------------------------------------------------------------
**	LPM Inline Assembly Intermittent CPU Operation Control Macro Functions.
*/

/**
 *	@def 		LPMHalt0Cycle
 *	@brief 		CPU 0 Halt Cycles (CPU clock = resource clock).
 * 	@param		.
 * 	@return		.
 */
#define LPMHalt0Cycle() { \
	IO_CG_0; \
}

/**
 *	@def 		LPMHalt8Cycles
 *	@brief 		CPU 8 Halt Cycles (CPU clock: resource clock = 1: approx. 3 to 4).
 * 	@param		.
 * 	@return		.
 */
#define LPMHalt8Cycles() { \
	IO_CG_1; \
}

/**
 *	@def 		LPMHalt16Cycles
 *	@brief 		CPU 16 Halt Cycles (CPU clock: resource clock = 1: approx. 5 to 6).
 * 	@param		.
 * 	@return		.
 */
#define LPMHalt16Cycles() { \
	IO_CG_2; \
}

/**
 *	@def 		LPMHalt32Cycles
 *	@brief 		CPU 32 Halt Cycles (CPU clock: resource clock = 1: approx. 9 to 10).
 * 	@param		.
 * 	@return		.
 */
#define LPMHalt32Cycles() { \
	IO_CG_3; \
}

#endif /* LPM_IO_H. */
