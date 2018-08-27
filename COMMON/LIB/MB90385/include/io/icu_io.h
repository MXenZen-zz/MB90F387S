/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Input Capture Unit			 								             */
/**
 *	@file		IO/icu_io.h
 *	@brief		This file contains types, getters and setters, and other macro
 *				functions for ICU IO registers.
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

#ifndef ICU_IO_H
#define ICU_IO_H

#include <IO/io_mb90385.h>

/* ----------------------------------------------------------------------------
**	ICU IO Types.
*/

/**
 * 	@brief		Defined enumerated type for ICU interrupt request.
 */
typedef enum {
	ICU_IRQ_CLEARED,			/**< clear ICU interrupt request */
	ICU_IRQ_DETECTED			/**< interrupt request generated */
} T_icuIRQ;

/**
 * 	@brief		Defined enumerated type for ICU interrupt enable.
 */
typedef enum {
	ICU_INT_DISABLED,			/**< interrupt request disable */
	ICU_INT_ENABLED				/**< interrupt request enable */
} T_icuINTEnable;

/**
 * 	@brief		Defined enumerated type for ICU detection edge.
 */
typedef enum {
	ICU_DETECT_NONE,			/**< no edge detection (operation disable) */
	ICU_DETECT_RISE,			/**< rising edge detection (operation enable) */
	ICU_DETECT_FALL,			/**< falling edge detection (operation enable) */
	ICU_DETECT_BOTH				/**< both edges detection (operation enable) */
} T_icuDetectEdge;

/* ----------------------------------------------------------------------------
**	ICU IO Getters and Setters.
*/

/**
 *	@def		GetICU_ICS01
 *	@brief		Control Status Register Getter.
 * 	@param 		.
 * 	@return		ICS01 (byte).
 */
#define GetICU_ICS01()			GetIOREGByte(IO_ICS01)

/**
 *	@def		GetICU_ICS23
 *	@brief		Control Status Register Getter.
 * 	@param 		.
 * 	@return		ICS23 (byte).
 */
#define GetICU_ICS23()			GetIOREGByte(IO_ICS23)

/**
 *	@def		SetICU_ICS01
 *	@brief		Control Status Register Setter.
 * 	@param[in]	VAL		Control bits for ICS (byte).
 * 	@return		.
 */
#define SetICU_ICS01(VAL) { \
	SetIOREGByte(IO_ICS01, VAL); \
}

/**
 *	@def		SetICU_ICS23
 *	@brief		Control Status Register Setter.
 * 	@param[in]	VAL		Control bits for ICS (byte).
 * 	@return		.
 */
#define SetICU_ICS23(VAL) { \
	SetIOREGByte(IO_ICS23, VAL); \
}

/* ----------------------------------------------------------------------------
**	ICU IO Register Fields Macro Functions for IN0.
*/

/**
 *	@def		EnableICU0Interrupt
 *	@brief		Interrupt Enabler.
 * 	@param 		.
 * 	@return		.
 */
#define EnableICU0Interrupt() { \
	SetIOREGBitVar(IO_ICS01, ICE0, ICU_INT_ENABLED); \
}

/**
 *	@def		DisableICU0Interrupt
 *	@brief		Interrupt Disabler.
 * 	@param 		.
 * 	@return		.
 */
#define DisableICU0Interrupt() { \
	SetIOREGBitVar(IO_ICS01, ICE0, ICU_INT_DISABLED); \
}

/**
 *	@def		SetICU0InputCaptureEdge
 *	@brief		Input Capture Edge Setter.
 * 	@param[in]	VAL		Input capture edge (bits).
 * 	@return		.
 */
#define SetICU0InputCaptureEdge(VAL) { \
	SetIOREGBitVar(IO_ICS01, EG0, VAL);	\
}

/**
 *	@def		IsICU0IRQActive
 *	@brief		Check if ICU0 request is active.
 * 	@param 		.
 * 	@return 	boolean.
 */
#define IsICU0IRQActive() \
	EQU(GetIOREGBitVar(IO_ICS01, ICP0), ICU_IRQ_DETECTED)

/**
 *	@def		ClearICU0DetectedEdge
 *	@brief		Clear Detected Edge.
 * 	@param 	 	.
 * 	@return		.
 */
#define ClearICU0DetectedEdge() { \
	SetIOREGBitVar(IO_ICS01, ICP0, ICU_IRQ_CLEARED); \
}

/**
 *	@def		ReadICU0Data
 *	@brief		Read Captured Input Data.
 * 	@param 		.
 * 	@return		IPCP0 (word).
 */
#define ReadICU0Data()			GetIOREG(IO_IPCP0)

/* ----------------------------------------------------------------------------
**	ICU IO Register Fields Macro Functions for IN1.
*/

/**
 *	@def		EnableICU1Interrupt
 *	@brief		Interrupt Enabler.
 * 	@param 		.
 * 	@return		.
 */
#define EnableICU1Interrupt() { \
	SetIOREGBitVar(IO_ICS01, ICE1, ICU_INT_ENABLED); \
}

/**
 *	@def		DisableICU1Interrupt
 *	@brief		Interrupt Disabler.
 * 	@param 		.
 * 	@return		.
 */
#define DisableICU1Interrupt() { \
	SetIOREGBitVar(IO_ICS01, ICE1, ICU_INT_DISABLED); \
}

/**
 *	@def		SetICU1InputCaptureEdge
 *	@brief		Input Capture Edge Setter.
 * 	@param[in]	VAL		Input capture edge (bits).
 * 	@return		.
 */
#define SetICU1InputCaptureEdge(VAL) { \
	SetIOREGBitVar(IO_ICS01, EG1, VAL);	\
}

/**
 *	@def		IsICU1IRQActive
 *	@brief		Check if ICU1 request is active.
 * 	@param 		.
 * 	@return 	boolean.
 */
#define IsICU1IRQActive() \
	EQU(GetIOREGBitVar(IO_ICS01, ICP1), ICU_IRQ_DETECTED)

/**
 *	@def		ClearICU1DetectedEdge
 *	@brief		Clear Detected Edge.
 * 	@param 	 	.
 * 	@return		.
 */
#define ClearICU1DetectedEdge() { \
	SetIOREGBitVar(IO_ICS01, ICP1, ICU_IRQ_CLEARED); \
}

/**
 *	@def		ReadICU1Data
 *	@brief		Read Captured Input Data.
 * 	@param 		.
 * 	@return		IPCP1 (word).
 */
#define ReadICU1Data()			GetIOREG(IO_IPCP1)

/* ----------------------------------------------------------------------------
**	ICU IO Register Fields Macro Functions for IN2.
*/

/**
 *	@def		EnableICU2Interrupt
 *	@brief		Interrupt Enabler.
 * 	@param 		.
 * 	@return		.
 */
#define EnableICU2Interrupt() { \
	SetIOREGBitVar(IO_ICS23, ICE0, ICU_INT_ENABLED); \
}

/**
 *	@def		DisableICU2Interrupt
 *	@brief		Interrupt Disabler.
 * 	@param 		.
 * 	@return		.
 */
#define DisableICU2Interrupt() { \
	SetIOREGBitVar(IO_ICS23, ICE0, ICU_INT_DISABLED); \
}

/**
 *	@def		SetICU2InputCaptureEdge
 *	@brief		Input Capture Edge Setter.
 * 	@param[in]	VAL		Input capture edge (bits).
 * 	@return		.
 */
#define SetICU2InputCaptureEdge(VAL) { \
	SetIOREGBitVar(IO_ICS23, EG0, VAL);	\
}

/**
 *	@def		IsICU2IRQActive
 *	@brief		Check if ICU2 request is active.
 * 	@param 		.
 * 	@return 	boolean.
 */
#define IsICU2IRQActive() \
	EQU(GetIOREGBitVar(IO_ICS23, ICP0), ICU_IRQ_DETECTED)

/**
 *	@def		ClearICU2DetectedEdge
 *	@brief		Clear Detected Edge.
 * 	@param 	 	.
 * 	@return		.
 */
#define ClearICU2DetectedEdge() { \
	SetIOREGBitVar(IO_ICS23, ICP0, ICU_IRQ_CLEARED); \
}

/**
 *	@def		ReadICU2Data
 *	@brief		Read Captured Input Data.
 * 	@param 		.
 * 	@return		IPCP2 (word).
 */
#define ReadICU2Data()			GetIOREG(IO_IPCP2)

/* ----------------------------------------------------------------------------
**	ICU IO Register Fields Macro Functions for IN3.
*/

/**
 *	@def		EnableICU3Interrupt
 *	@brief		Interrupt Enabler.
 * 	@param 		.
 * 	@return		.
 */
#define EnableICU3Interrupt() { \
	SetIOREGBitVar(IO_ICS23, ICE1, ICU_INT_ENABLED); \
}

/**
 *	@def		DisableICU3Interrupt
 *	@brief		Interrupt Disabler.
 * 	@param 		.
 * 	@return		.
 */
#define DisableICU3Interrupt() { \
	SetIOREGBitVar(IO_ICS23, ICE1, ICU_INT_DISABLED); \
}

/**
 *	@def		SetICU3InputCaptureEdge
 *	@brief		Input Capture Edge Setter.
 * 	@param[in]	VAL		Input capture edge (bits).
 * 	@return		.
 */
#define SetICU3InputCaptureEdge(VAL) { \
	SetIOREGBitVar(IO_ICS23, EG1, VAL);	\
}

/**
 *	@def		IsICU3IRQActive
 *	@brief		Check if ICU3 request is active.
 * 	@param 		.
 * 	@return 	boolean.
 */
#define IsICU3IRQActive() \
	EQU(GetIOREGBitVar(IO_ICS23, ICP1), ICU_IRQ_DETECTED)

/**
 *	@def		ClearICU3DetectedEdge
 *	@brief		Clear Detected Edge.
 * 	@param 	 	.
 * 	@return		.
 */
#define ClearICU3DetectedEdge() { \
	SetIOREGBitVar(IO_ICS23, ICP1, ICU_IRQ_CLEARED); \
}

/**
 *	@def		ReadICU3Data
 *	@brief		Read Captured Input Data.
 * 	@param 		.
 * 	@return		IPCP3 (word).
 */
#define ReadICU3Data()			GetIOREG(IO_IPCP3)

#endif /* ICU_IO_H. */
