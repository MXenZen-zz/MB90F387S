/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* DTP / External Interrupt										             */
/**
 *	@file		IO/exi_io.h
 *	@brief		This file contains types, getters and setters, and other macro
 *				functions for EXI IO registers.
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

#ifndef EXI_IO_H
#define EXI_IO_H

#include <IO/io_mb90385.h>

/* ----------------------------------------------------------------------------
**	EXI IO Types.
*/

/**
 * 	@brief		Defined enumerated type for external interrupt request.
 */
typedef enum {
	EXI_IRQ_CLEARED,			/**< clear external interrupt request */
	EXI_IRQ_DETECTED			/**< interrupt request generated */
} T_exIRQ;

/**
 * 	@brief		Defined enumerated type for external interrupt enable.
 */
typedef enum {
	EXI_INT_DISABLED,			/**< interrupt request disable */
	EXI_INT_ENABLED				/**< interrupt request enable */
} T_exINTEnable;

/**
 * 	@brief		Defined enumerated type for EXI detection level.
 */
typedef enum {
	EXI_DETECT_LOW,				/**< detects "L" level */
	EXI_DETECT_HIGH,			/**< detects "H" level */
	EXI_DETECT_RISE,			/**< detects rising edge */
	EXI_DETECT_FALL				/**< detects falling edge */
} T_exiDetectLevel;

/* ----------------------------------------------------------------------------
**	EXI IO Getters and Setters.
*/

/**
 *	@def 		GetEXI_EIRR
 *	@brief 		External Interrupt Factor Register Getter.
 * 	@param		.
 * 	@return		EIRR (byte).
 */
#define GetEXI_EIRR()			GetIOREGByte(IO_EIRR)

/**
 *	@def 		GetEXI_ENIR
 *	@brief 		External Interrupt Enable Register Getter.
 * 	@param		.
 * 	@return		ENIR (byte).
 */
#define GetEXI_ENIR()			GetIOREGByte(IO_ENIR)

/**
 *	@def 		GetEXI_ELVR
 *	@brief 		Detection Level Setting Register Getter.
 * 	@param		.
 * 	@return		ELVR (word).
 */
#define GetEXI_ELVR()			GetIOREGWord(IO_ELVR)

/**
 *	@def 		SetEXI_EIRR
 *	@brief 		External Interrupt Factor Register Setter.
 * 	@param[in]	VAL		Enable/disable bits for EIRR (byte).
 * 	@return		.
 */
#define SetEXI_EIRR(VAL) { \
	SetIOREGByte(IO_EIRR, VAL); \
}

/**
 *	@def 		SetEXI_ENIR
 *	@brief 		External Interrupt Enable Register Setter.
 * 	@param[in]	VAL		Enable/disable bits for ENIR (byte).
 * 	@return		.
 */
#define SetEXI_ENIR(VAL) { \
	SetIOREGByte(IO_ENIR, VAL); \
}

/**
 *	@def 		SetEXI_ELVR
 *	@brief 		Detection Level Setting Register Setter.
 * 	@param[in]	VAL		Detection level bits for ELVR (word).
 * 	@return		.
 */
#define SetEXI_ELVR(VAL) { \
	SetIOREGWord(IO_ELVR, VAL); \
}

/* ----------------------------------------------------------------------------
**	EXI IO Register Fields Macro Functions for INT0 (RX).
*/

/**
 *	@def 		EnableEXI0
 *	@brief 		Enable External Interrupt.
 * 	@param		.
 * 	@return		.
 */
#define EnableEXI0() { \
	SetIOREGBitVar(IO_ENIR, EN0, EXI_INT_ENABLED); \
}

/**
 *	@def 		DisableEXI0
 *	@brief 		Disable External Interrupt.
 * 	@param		.
 * 	@return		.
 */
#define DisableEXI0() { \
	SetIOREGBitVar(IO_ENIR, EN0, EXI_INT_DISABLED); \
}

/**
 *	@def		IsEXI0RQActive
 *	@brief		Check if EXI0 request is active.
 * 	@param 		.
 * 	@return 	boolean.
 */
#define IsEXI0RQActive() \
	EQU(GetIOREGBitVar(IO_EIRR, ER0), EXI_IRQ_DETECTED)

/**
 *	@def 		ClearEXI0IRQ
 *	@brief 		Clear External IRQ.
 * 	@param		.
 * 	@return		.
 */
#define ClearEXI0IRQ() { \
	SetIOREGBitVar(IO_EIRR, ER0, EXI_IRQ_CLEARED); \
}

/**
 *	@def 		SetEXI0DetectionLevel
 *	@brief 		Set Detection Level.
 * 	@param[in]	VAL		Detection level bits for EXI0 (bits).
 * 	@return		.
 */
#define SetEXI0DetectionLevel(VAL) { \
	SetIOREGBitVar(IO_ELVR, LALB0, VAL); \
}

/* ----------------------------------------------------------------------------
**	EXI IO Register Fields Macro Functions for INT4.
*/

/**
 *	@def 		EnableEXI4
 *	@brief 		Enable External Interrupt.
 * 	@param		.
 * 	@return		.
 */
#define EnableEXI4() { \
	SetIOREGBitVar(IO_ENIR, EN4, EXI_INT_ENABLED); \
}

/**
 *	@def 		DisableEXI4
 *	@brief 		Disable External Interrupt.
 * 	@param		.
 * 	@return		.
 */
#define DisableEXI4() { \
	SetIOREGBitVar(IO_ENIR, EN4, EXI_INT_DISABLED); \
}

/**
 *	@def		IsEXI4RQActive
 *	@brief		Check if EXI4 request is active.
 * 	@param 		.
 * 	@return 	boolean.
 */
#define IsEXI4RQActive() \
	EQU(GetIOREGBitVar(IO_EIRR, ER4), EXI_IRQ_DETECTED)

/**
 *	@def 		ClearEXI4IRQ
 *	@brief 		Clear External IRQ.
 * 	@param		.
 * 	@return		.
 */
#define ClearEXI4IRQ() { \
	SetIOREGBitVar(IO_EIRR, ER4, EXI_IRQ_CLEARED); \
}

/**
 *	@def 		SetEXI4DetectionLevel
 *	@brief 		Set Detection Level.
 * 	@param[in]	VAL		Detection level bits for EXI4 (bits).
 * 	@return		.
 */
#define SetEXI4DetectionLevel(VAL) { \
	SetIOREGBitVar(IO_ELVR, LALB4, VAL); \
}

/* ----------------------------------------------------------------------------
**	EXI IO Register Fields Macro Functions for INT5.
*/

/**
 *	@def 		EnableEXI5
 *	@brief 		Enable External Interrupt.
 * 	@param		.
 * 	@return		.
 */
#define EnableEXI5() { \
	SetIOREGBitVar(IO_ENIR, EN5, EXI_INT_ENABLED); \
}

/**
 *	@def 		DisableEXI5
 *	@brief 		Disable External Interrupt.
 * 	@param		.
 * 	@return		.
 */
#define DisableEXI5() { \
	SetIOREGBitVar(IO_ENIR, EN5, EXI_INT_DISABLED); \
}

/**
 *	@def		IsEXI5RQActive
 *	@brief		Check if EXI5 request is active.
 * 	@param 		.
 * 	@return 	boolean.
 */
#define IsEXI5RQActive() \
	EQU(GetIOREGBitVar(IO_EIRR, ER5), EXI_IRQ_DETECTED)

/**
 *	@def 		ClearEXI5IRQ
 *	@brief 		Clear External IRQ.
 * 	@param		.
 * 	@return		.
 */
#define ClearEXI5IRQ() { \
	SetIOREGBitVar(IO_EIRR, ER5, EXI_IRQ_CLEARED); \
}

/**
 *	@def 		SetEXI5DetectionLevel
 *	@brief 		Set Detection Level.
 * 	@param[in]	VAL		Detection level bits for EXI5 (bits).
 * 	@return		.
 */
#define SetEXI5DetectionLevel(VAL) { \
	SetIOREGBitVar(IO_ELVR, LALB5, VAL); \
}

/* ----------------------------------------------------------------------------
**	EXI IO Register Fields Macro Functions for INT6.
*/

/**
 *	@def 		EnableEXI6
 *	@brief 		Enable External Interrupt.
 * 	@param		.
 * 	@return		.
 */
#define EnableEXI6() { \
	SetIOREGBitVar(IO_ENIR, EN6, EXI_INT_ENABLED); \
}

/**
 *	@def 		DisableEXI6
 *	@brief 		Disable External Interrupt.
 * 	@param		.
 * 	@return		.
 */
#define DisableEXI6() { \
	SetIOREGBitVar(IO_ENIR, EN6, EXI_INT_DISABLED); \
}

/**
 *	@def		IsEXI6RQActive
 *	@brief		Check if EXI6 request is active.
 * 	@param 		.
 * 	@return 	boolean.
 */
#define IsEXI6RQActive() \
	EQU(GetIOREGBitVar(IO_EIRR, ER6), EXI_IRQ_DETECTED)

/**
 *	@def 		ClearEXI6IRQ
 *	@brief 		Clear External IRQ.
 * 	@param		.
 * 	@return		.
 */
#define ClearEXI6IRQ() { \
	SetIOREGBitVar(IO_EIRR, ER6, EXI_IRQ_CLEARED); \
}

/**
 *	@def 		SetEXI6DetectionLevel
 *	@brief 		Set Detection Level.
 * 	@param[in]	VAL		Detection level bits for EXI6 (bits).
 * 	@return		.
 */
#define SetEXI6DetectionLevel(VAL) { \
	SetIOREGBitVar(IO_ELVR, LALB6, VAL); \
}

/* ----------------------------------------------------------------------------
**	EXI IO Register Fields Macro Functions for INT7.
*/

/**
 *	@def 		EnableEXI7
 *	@brief 		Enable External Interrupt.
 * 	@param		.
 * 	@return		.
 */
#define EnableEXI7() { \
	SetIOREGBitVar(IO_ENIR, EN7, EXI_INT_ENABLED); \
}

/**
 *	@def 		DisableEXI7
 *	@brief 		Disable External Interrupt.
 * 	@param		.
 * 	@return		.
 */
#define DisableEXI7() { \
	SetIOREGBitVar(IO_ENIR, EN7, EXI_INT_DISABLED); \
}

/**
 *	@def		IsEXI7RQActive
 *	@brief		Check if EXI7 request is active.
 * 	@param 		.
 * 	@return 	boolean.
 */
#define IsEXI7RQActive() \
	EQU(GetIOREGBitVar(IO_EIRR, ER7), EXI_IRQ_DETECTED)

/**
 *	@def 		ClearEXI7IRQ
 *	@brief 		Clear External IRQ.
 * 	@param		.
 * 	@return		.
 */
#define ClearEXI7IRQ() { \
	SetIOREGBitVar(IO_EIRR, ER7, EXI_IRQ_CLEARED); \
}

/**
 *	@def 		SetEXI7DetectionLevel
 *	@brief 		Set Detection Level.
 * 	@param[in]	VAL		Detection level bits for EXI7 (bits).
 * 	@return		.
 */
#define SetEXI7DetectionLevel(VAL) { \
	SetIOREGBitVar(IO_ELVR, LALB7, VAL); \
}

#endif /* EXI_IO_H. */
