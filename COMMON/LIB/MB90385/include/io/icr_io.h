/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Interrupt Controller with Enhanced Intelligent IO Service			     */
/**
 *	@file		IO/icr_io.h
 * 	@brief		This file contains types, macro registers, getters and setters,
 * 				and other macro functions for ICR IO register with EI2OS support.
 *	@note		When you describe the application program which refers to ISDn,
 *				please compile all the I/O register definition files with
 *				"-D FFMC_ISD" option.
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

#ifndef ICR_IO_H
#define ICR_IO_H

#include <IO/io_mb90385.h>

/* ----------------------------------------------------------------------------
**	ICR IO Types.
*/

/**
 * 	@brief		Defined enumerated type for ICR interrupt level.
 */
typedef enum {
	ICR_LVL_0,					/**< interrupt level 0 (highest) */
	ICR_LVL_1,					/**< interrupt level 1 (higher) */
	ICR_LVL_2,					/**< interrupt level 2 (high) */
	ICR_LVL_3,					/**< interrupt level 3 (fair) */
	ICR_LVL_4,					/**< interrupt level 4 (low) */
	ICR_LVL_5,					/**< interrupt level 5 (lower) */
	ICR_LVL_6,					/**< interrupt level 6 (lowest) */
	ICR_LVL_7					/**< interrupt level 7 (no interrupt) */
} T_icrINTLevel;

/**
 * 	@brief		Defined enumerated type for ICR EI2OS enable.
 */
typedef enum {
	ICR_INT_NORMAL,				/**< normal interrupt processing at an interrupt */
	ICR_INT_EI2OS				/**< EI2OS at an interrupt */
} T_icrINT;

/**
 * 	@brief		Defined enumerated type for ICR EI2OS channel.
 */
typedef enum {
	ICR_EI2OS_CH0,				/**< EI2OS channel 00: 100h */
	ICR_EI2OS_CH1,				/**< EI2OS channel 01: 108h */
	ICR_EI2OS_CH2,				/**< EI2OS channel 02: 110h */
	ICR_EI2OS_CH3,				/**< EI2OS channel 03: 118h */
	ICR_EI2OS_CH4,				/**< EI2OS channel 04: 120h */
	ICR_EI2OS_CH5,				/**< EI2OS channel 05: 128h */
	ICR_EI2OS_CH6,				/**< EI2OS channel 06: 130h */
	ICR_EI2OS_CH7,				/**< EI2OS channel 07: 138h */
	ICR_EI2OS_CH8,				/**< EI2OS channel 08: 140h */
	ICR_EI2OS_CH9,				/**< EI2OS channel 09: 148h */
	ICR_EI2OS_CH10,				/**< EI2OS channel 10: 150h */
	ICR_EI2OS_CH11,				/**< EI2OS channel 11: 158h */
	ICR_EI2OS_CH12,				/**< EI2OS channel 12: 160h */
	ICR_EI2OS_CH13,				/**< EI2OS channel 13: 168h */
	ICR_EI2OS_CH14,				/**< EI2OS channel 14: 170h */
	ICR_EI2OS_CH15				/**< EI2OS channel 15: 178h */
} T_icrEI2OSChannel;

/**
 * 	@brief		Defined enumerated type for ICR EI2OS status.
 */
typedef enum {
	ICR_EI2OS_OPERATING,		/**< when EI2OS in operation or not started */
	ICR_EI2OS_STOP_EOC,			/**< stop state by end of counting */
	ICR_EI2OS_RSV,				/**< (reserved or unused) */
	ICR_EI2OS_STOP_RES_REQ 		/**< stop state by request from resource */
} T_icrEI2OSState;

/**
 * 	@brief		Defined enumerated type for ICR EI2OS termination control.
 */
typedef enum {
	ICR_EI2OS_NOTERM,			/**< not terminated by a request from resource */
	ICR_EI2OS_TERM_RES_REQ		/**< terminated by a request from resource */
} T_icrEI2OSTermCtrl;

/**
 * 	@brief		Defined enumerated type for ICR EI2OS data transfer direction.
 */
typedef enum {
	ICR_EI2OS_IOA_TO_BUF,		/**< IO address pointer -> buffer address pointer */
	ICR_EI2OS_BUF_TO_IOA		/**< buffer address pointer -> IO address pointer */
} T_icrEI2OSDTrans;

/**
 * 	@brief		Defined enumerated type for ICR EI2OS transfer data length.
 */
typedef enum {
	ICR_EI2OS_DL_BYTE,			/**< byte data length */
	ICR_EI2OS_DL_WORD			/**< word data length */
} T_icrEI2OSDLength;

/**
 * 	@brief		Defined enumerated type for ICR EI2OS BAP updating / fixing.
 */
typedef enum {
	ICR_EI2OS_BAP_UPDATED,		/**< BAP updated after data transfer */
	ICR_EI2OS_BAP_FIXED			/**< BAP not updated after data transfer */
} T_icrEI2OSBAPUpdate;

/**
 * 	@brief		Defined enumerated type for ICR EI2OS IOA updating / fixing.
 */
typedef enum {
	ICR_EI2OS_IOA_UPDATED,		/**< IOA pointer updated after data transfer */
	ICR_EI2OS_IOA_FIXED			/**< IOA pointer not updated after data transfer */
} T_icrEI2OSIOAUpdate;

/* ----------------------------------------------------------------------------
**	ICR IO Registers.
*/

#define ICR_PBASE				(&IO_ICR00)
#define ICR_CAN					(IO_ICR00)
#define ICR_EXIRX				(IO_ICR02)
#define ICR_TBT					(IO_ICR02)
#define ICR_RLT0				(IO_ICR03)
#define ICR_ADC					(IO_ICR03)
#define ICR_IOT					(IO_ICR04)
#define ICR_PPG01				(IO_ICR05)
#define ICR_ICU0				(IO_ICR06)
#define ICR_EXI45				(IO_ICR06)
#define ICR_ICU1				(IO_ICR07)
#define ICR_PPG23				(IO_ICR07)
#define ICR_EXI67				(IO_ICR08)
#define ICR_WTT					(IO_ICR08)
#define ICR_ICU23				(IO_ICR09)
#define ICR_RLT1				(IO_ICR12)
#define ICR_SER					(IO_ICR13)
#define ICR_DIG					(IO_ICR15)
#define ICR_PTOP				(&IO_ICR15)

/* ----------------------------------------------------------------------------
**	ICR IO Registers Getters and Setters.
*/

/**
 *	@def		GetICR
 *	@brief		Interrupt Control Register Getter.
 * 	@param		ICRX	Interrupt control register name (byte).
 * 	@return		ICR (byte).
 */
#define GetICR(ICRX)			GetIOREGByte(ICRX)

/**
 *	@def		GetISD_BAP
 *	@brief		EI2OS Buffer Address Pointer Getter.
 * 	@param[in]	CH		EI2OS channel (byte).
 * 	@return		BAP (dword).
 */
#define GetISD_BAP(CH) \
	(MaskOn(LShift((T_uint32)GetIOREGVar(IO_ISD[CH], BAPH), SzBits_WORD), \
		GetIOREGVar(IO_ISD[CH], BAPML)))

/**
 *	@def		GetISD_ISCS
 *	@brief		EI2OS Status Register Getter.
 * 	@param[in]	CH		EI2OS channel (byte).
 * 	@return		ISCS (byte).
 */
#define GetISD_ISCS(CH)		GetIOSSREGByte(IO_ISD[CH], ISCS)

/**
 *	@def		GetISD_IOA
 *	@brief		EI2OS IO Address Pointer Getter.
 * 	@param[in]	CH		EI2OS channel (byte).
 * 	@return		IOA (word).
 */
#define GetISD_IOA(CH)		GetIOREGVar(IO_ISD[CH], IOA)

/**
 *	@def		GetISD_DCT
 *	@brief		EI2OS Data Counter Getter.
 * 	@param[in]	CH		EI2OS channel (byte).
 * 	@return		DCT (word).
 */
#define GetISD_DCT(CH)		GetIOREGVar(IO_ISD[CH], DCT)

/**
 *	@def		SetICR
 *	@brief		Interrupt Control Register Setter.
 * 	@param		ICRX	Interrupt control register name (byte).
 * 	@param[in] 	VAL		Configuration bits for ICR (byte).
 * 	@return		.
 */
#define SetICR(ICRX, VAL) { \
	SetIOREGByte(ICRX, VAL); \
}

/**
 *	@def		SetISD_BAP
 *	@brief		EI2OS Buffer Address Pointer Setter.
 * 	@param[in]	CH		EI2OS channel (byte).
 * 	@param[in]	HADD	Address bits for EI2OS BAPH (byte).
 * 	@param[in]	MLADD	Address bits for EI2OS BAPML (word).
 * 	@return		.
 */
#define SetISD_BAP(CH, HADD, MLADD) { \
	SetIOREGVar(IO_ISD[CH], BAPH, (HADD)); \
	SetIOREGVar(IO_ISD[CH], BAPML, (MLADD)); \
}

/**
 *	@def		SetISD_ISCS
 *	@brief		EI2OS Status Register Setter.
 * 	@param[in]	CH		EI2OS channel (byte).
 * 	@param[in] 	VAL		Configuration bits for EI2OS ISCS (byte).
 * 	@return		.
 */
#define SetISD_ISCS(CH, VAL) { \
	SetIOSSREGByte(IO_ISD[CH], ISCS, VAL); \
}

/**
 *	@def		SetISD_IOA
 *	@brief		EI2OS IO Address Pointer Setter.
 * 	@param[in]	CH		EI2OS channel (byte).
 * 	@param[in] 	VAL		Address bits for EI2OS IOA (word).
 * 	@return		.
 */
#define SetISD_IOA(CH, VAL) { \
	SetIOREGVar(IO_ISD[CH], IOA, VAL); \
}

/**
 *	@def		SetISD_DCT
 *	@brief		EI2OS Data Counter Setter.
 * 	@param[in]	CH		EI2OS channel (byte).
 * 	@param[in] 	VAL		Count bits for EI2OS DCT (word).
 * 	@return		.
 */
#define SetISD_DCT(CH, VAL) { \
	SetIOREGVar(IO_ISD[CH], DCT, VAL); \
}

/* ----------------------------------------------------------------------------
**	ICR IO Register Fields Macro Functions.
*/

/**
 *	@def 		GetICRIntLevel
 *	@brief 		ICR interrupt level getter.
 * 	@param[in]	ICRX	Interrupt control register (byte).
 * 	@return		interrupt level (IL) (byte).
 */
#define GetICRIntLevel(ICRX)	GetIOREGBitVar(ICRX, read.IL)

/**
 *	@def 		SetICRIntLevel
 *	@brief 		ICR interrupt level setter.
 * 	@param[in]	ICRX	Interrupt control register (byte).
 * 	@param[in]	VAL		Interrupt level (byte).
 * 	@return		.
 */
#define SetICRIntLevel(ICRX, VAL) { \
	SetIOREGBitVar(ICRX, write.IL, VAL); \
}

/**
 *	@def		IsEI2OSEnabled
 *	@brief		Check if EI2OS starts at an interrupt.
 * 	@param[in]	ICRX	Interrupt control register (byte).
 * 	@return		boolean.
 */
#define IsEI2OSEnabled(ICRX) \
	EQU(GetIOREGBitVar(ICRX, read.ISE), ICR_INT_EI2OS)

/**
 *	@def 		EnableEI2OS
 *	@brief 		Starts EI2OS at an interrupt.
 * 	@param[in]	ICRX	Interrupt control register (byte).
 * 	@return		.
 */
#define EnableEI2OS(ICRX) { \
	SetIOREGBitVar(ICRX, write.ISE, ICR_INT_EI2OS); \
}

/**
 *	@def 		DisableEI2OS
 *	@brief 		Starts normal interrupt processing at an interrupt.
 * 	@param[in]	ICRX	Interrupt control register (byte).
 * 	@return		.
 */
#define DisableEI2OS(ICRX) { \
	SetIOREGBitVar(ICRX, write.ISE, ICR_INT_NORMAL); \
}

/**
 *	@def 		SetEI2OSChannel
 *	@brief 		EI2OS Channel Setter.
 * 	@param[in]	ICRX	Interrupt control register (byte).
 * 	@param[in]	VAL		EI2OS Channel (byte).
 * 	@return		.
 */
#define SetEI2OSChannel(ICRX, VAL) { \
	SetIOREGBitVar(ICRX, write.ICS, VAL); \
}

/**
 *	@def		IsEI2OSInOperation
 *	@brief		Check if EI2OS in operation or not started.
 * 	@param[in]	ICRX	Interrupt control register (byte).
 * 	@return		boolean.
 */
#define IsEI2OSInOperation(ICRX) \
	EQU(GetIOREGBitVar(ICRX, read.S), ICR_EI2OS_OPERATING)

/**
 *	@def		IsEI2OSInStopByEOC
 *	@brief		Check if EI2OS in stop state by end of counting.
 * 	@param[in]	ICRX	Interrupt control register (byte).
 * 	@return		boolean.
 */
#define IsEI2OSInStopByEOC(ICRX) \
	EQU(GetIOREGBitVar(ICRX, read.S), ICR_EI2OS_STOP_EOC)

/**
 *	@def		IsEI2OSInStopByReqRes
 *	@brief		Check if EI2OS in stop state by request from resource.
 * 	@param[in]	ICRX	Interrupt control register (byte).
 * 	@return		boolean.
 */
#define IsEI2OSInStopByReqRes(ICRX) \
	EQU(GetIOREGBitVar(ICRX, read.S), ICR_EI2OS_STOP_RES_REQ)

/**
 *	@def		SetISDNoTermination
 *	@brief		Set EI2OS not terminated by a request from resource.
 * 	@param[in]	CH		EI2OS channel (byte).
 * 	@return		.
 */
#define SetISDNoTermination(CH) { \
	SetIOSSREGBitVar(IO_ISD[CH], ISCS, SE, ICR_EI2OS_NOTERM); \
}

/**
 *	@def		SetISDTerminatedByResReq
 *	@brief		Set EI2OS terminated by a request from resource.
 * 	@param[in]	CH		EI2OS channel (byte).
 * 	@return		.
 */
#define SetISDTerminatedByResReq(CH) { \
	SetIOSSREGBitVar(IO_ISD[CH], ISCS, SE, ICR_EI2OS_TERM_RES_REQ); \
}

/**
 *	@def		SetISDTransferIOAtoBUF
 *	@brief		Set EI2OS data transfer from IOA pointer to BAP.
 * 	@param[in]	CH		EI2OS channel (byte).
 * 	@return		.
 */
#define SetISDTransferIOAtoBUF(CH) { \
	SetIOSSREGBitVar(IO_ISD[CH], ISCS, DIR, ICR_EI2OS_IOA_TO_BUF); \
}

/**
 *	@def		SetISDTransferBUFtoIOA
 *	@brief		Set EI2OS data transfer from BAP to IOA pointer.
 * 	@param[in]	CH		EI2OS channel (byte).
 * 	@return		.
 */
#define SetISDTransferBUFtoIOA(CH) { \
	SetIOSSREGBitVar(IO_ISD[CH], ISCS, DIR, ICR_EI2OS_BUF_TO_IOA); \
}

/**
 *	@def		SetISDTransferByteLength
 *	@brief		Set EI2OS byte transfer data length.
 * 	@param[in]	CH		EI2OS channel (byte).
 * 	@return		.
 */
#define SetISDTransferByteLength(CH) { \
	SetIOSSREGBitVar(IO_ISD[CH], ISCS, BW, ICR_EI2OS_DL_BYTE); \
}

/**
 *	@def		SetISDTransferWordLength
 *	@brief		Set EI2OS word transfer data length.
 * 	@param[in]	CH		EI2OS channel (byte).
 * 	@return		.
 */
#define SetISDTransferWordLength(CH) { \
	SetIOSSREGBitVar(IO_ISD[CH], ISCS, BW, ICR_EI2OS_DL_WORD); \
}

/**
 *	@def		SetISDBAPUpdated
 *	@brief		Set EI2OS buffer address pointer updated after data transfer.
 * 	@param[in]	CH		EI2OS channel (byte).
 * 	@return		.
 */
#define SetISDBAPUpdated(CH) { \
	SetIOSSREGBitVar(IO_ISD[CH], ISCS, BF, ICR_EI2OS_BAP_UPDATED); \
}

/**
 *	@def		SetISDBAPFixed
 *	@brief		Set EI2OS buffer address pointer fixed after data transfer.
 * 	@param[in]	CH		EI2OS channel (byte).
 * 	@return		.
 */
#define SetISDBAPFixed(CH) { \
	SetIOSSREGBitVar(IO_ISD[CH], ISCS, BF, ICR_EI2OS_BAP_FIXED); \
}

/**
 *	@def		SetISDIOAUpdated
 *	@brief		Set EI2OS IO address pointer updated after data transfer.
 * 	@param[in]	CH		EI2OS channel (byte).
 * 	@return		.
 */
#define SetISDIOAUpdated(CH) { \
	SetIOSSREGBitVar(IO_ISD[CH], ISCS, IF, ICR_EI2OS_IOA_UPDATED); \
}

/**
 *	@def		SetISDIOAFixed
 *	@brief		Set EI2OS IO address pointer fixed after data transfer.
 * 	@param[in]	CH		EI2OS channel (byte).
 * 	@return		.
 */
#define SetISDIOAFixed(CH) { \
	SetIOSSREGBitVar(IO_ISD[CH], ISCS, IF, ICR_EI2OS_IOA_FIXED); \
}

#endif /* ICR_IO_H. */
