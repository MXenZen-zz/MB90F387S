/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Controller Area Network	    										     */
/**
 *	@file		IO/can_io.h
 * 	@brief		This file contains types, getters and setters, and other
 * 				macro functions for CAN IO registers.
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

#ifndef CAN_IO_H
#define CAN_IO_H

#include <IO/io_mb90385.h>

/* ----------------------------------------------------------------------------
**	CAN IO Control Configuration Types.
*/

/**
 * 	@brief		Defined enumerated type for CAN preconfigured CSR values.
 */
typedef enum {
	CAN_CSR_STOP  = 0x0081U,	/**< stops bus operation (CSR only) */
	CAN_CSR_START = 0x0084U		/**< (re)starts bus operation (CSR only) */
} T_canBus;

/**
 * 	@brief		Defined enumerated type for CAN bus operation stop.
 */
typedef enum {
	CAN_BUS_OP_HALT_CANCELED,	/**< cancel bus operation stop (or not in stop state) */
	CAN_BUS_OP_HALTED			/**< stops bus operation (or in stop state) */
} T_canBusHalt;

/**
 * 	@brief		Defined enumerated type for CAN TX pin output.
 */
typedef enum {
	CAN_TX_PIN_GPIO,			/**< used as general-purpose I/O port */
	CAN_TX_PIN_OUTPUT			/**< used as transmit pin TX */
} T_canTXPin;

/**
 * 	@brief		Defined enumerated type for CAN reception and transmission.
 */
typedef enum {
	CAN_RX_NONE = 0U,			/**< message is not received */
	CAN_TX_NONE = 0U,			/**< message is not transmitted */
	CAN_RX_SET  = 1U,			/**< message is (being) received */
	CAN_TX_SET  = 1U			/**< message is (being) transmitted */
} T_canRXTX;

/**
 * 	@brief		Defined enumerated type for CAN node status.
 */
typedef enum {
	CAN_ERR_ACTIVE,				/**< error active */
	CAN_ERR_WARNING,			/**< warning (error active) */
	CAN_ERR_PASSIVE,			/**< error passive */
	CAN_BUS_OFF					/**< bus off */
} T_canNS;

/**
 * 	@brief		Defined enumerated type for CAN node status transition.
 */
typedef enum {
	CAN_NS_TRANSIT_NONE,		/**< no node status transition */
	CAN_NS_TRANSIT_SET			/**< node status transition */
} T_canNSTransition;

/**
 * 	@brief		Defined enumerated type for CAN node status transition interrupt.
 */
typedef enum {
	CAN_NS_INT_DISABLED,		/**< interrupt output disable by NS transition */
	CAN_NS_INT_ENABLED			/**< interrupt output enable by NS transition */
} T_canNSTransitionINT;

/**
 * 	@brief		Defined enumerated type for CAN last event (reception (RX),
 * 				transmission (TX) or node status (NS) transition).
 */
typedef enum {
	CAN_LAST_EVT_RX_NONE = 0U,	/**< reception is not completed */
	CAN_LAST_EVT_TX_NONE = 0U,	/**< transmission is not completed */
	CAN_LAST_EVT_NS_NONE = 0U,	/**< not node status transition */
	CAN_LAST_EVT_RX_SET  = 1U,	/**< reception is completed */
	CAN_LAST_EVT_TX_SET  = 1U,	/**< transmission is completed */
	CAN_LAST_EVT_NS_SET  = 1U	/**< node status transition */
} T_canLastEvent;

/**
 * 	@brief		Defined enumerated type for CAN preconfigured bit timing speeds.
 */
typedef enum {
	CAN_BTR_10K	  = 0x7FFFU,	/**< Clk=16M, L=25, SP=68, RSJ=3 */
	CAN_BTR_20K	  = 0x7FDFU,	/**< Clk=16M, L=25, SP=68, RSJ=3 */
	CAN_BTR_20K8  = 0x7EDFU,	/**< Clk=16M, L=24, SP=66, RSJ=3 */
	CAN_BTR_25K	  = 0x5CDFU,	/**< Clk=16M, L=20, SP=70, RSJ=3 */
	CAN_BTR_33K3  = 0x7ED3U,	/**< Clk=16M, L=24, SP=66, RSJ=3 */
	CAN_BTR_40K	  = 0x7FCFU,	/**< Clk=16M, L=25, SP=68, RSJ=3 */
	CAN_BTR_50K	  = 0x5CCFU,	/**< Clk=16M, L=20, SP=70, RSJ=3 */
	CAN_BTR_83K3  = 0x7EC7U,	/**< Clk=16M, L=24, SP=66, RSJ=3 */
	CAN_BTR_100K  = 0x5CC7U,	/**< Clk=16M, L=20, SP=70, RSJ=3 */
	CAN_BTR_125K  = 0x4987U,	/**< Clk=16M, L=16, SP=68, RSJ=2 */
	CAN_BTR_200K  = 0x5CC3U,	/**< Clk=16M, L=20, SP=70, RSJ=3 */
	CAN_BTR_250K  = 0x4983U,	/**< Clk=16M, L=16, SP=68, RSJ=2 */
	CAN_BTR_400K  = 0x5CC1U,	/**< Clk=16M, L=20, SP=70, RSJ=3 */
	CAN_BTR_500K  = 0x4981U,	/**< Clk=16M, L=16, SP=68, RSJ=2 */
	CAN_BTR_1M 	  = 0x4980U		/**< Clk=16M, L=16, SP=68, RSJ=2 */
} T_canBitTimingSpeed;

/**
 * 	@brief		Defined enumerated type for CAN data length code.
 */
typedef enum {
	CAN_DLC_0BYTE ,				/**< 0 byte data length */
	CAN_DLC_1BYTE ,				/**< 1 byte data length */
	CAN_DLC_2BYTES,				/**< 2 bytes data length */
	CAN_DLC_3BYTES,				/**< 3 bytes data length */
	CAN_DLC_4BYTES,				/**< 4 bytes data length */
	CAN_DLC_5BYTES,				/**< 5 bytes data length */
	CAN_DLC_6BYTES,				/**< 6 bytes data length */
	CAN_DLC_7BYTES,				/**< 7 bytes data length */
	CAN_DLC_8BYTES				/**< 8 (max) bytes data length */
} T_canDataLength;

/**
 * 	@brief		Defined enumerated type for CAN message buffer pointer.
 */
typedef enum {
	CAN_MB_0,					/**< message buffer 0 */
	CAN_MB_1,					/**< message buffer 1 */
	CAN_MB_2,					/**< message buffer 2 */
	CAN_MB_3,					/**< message buffer 3 */
	CAN_MB_4,					/**< message buffer 4 */
	CAN_MB_5,					/**< message buffer 5 */
	CAN_MB_6,					/**< message buffer 6 */
	CAN_MB_7,					/**< message buffer 7 */
	CAN_MB_SIZE					/**< message buffer size */
} T_canMsgBuf;

/**
 * 	@brief		Defined enumerated type for CAN message buffer byte data.
 */
typedef enum {
	CAN_MB_BYTE_0,				/**< message buffer byte data 0 */
	CAN_MB_BYTE_1,				/**< message buffer byte data 1 */
	CAN_MB_BYTE_2,				/**< message buffer byte data 2 */
	CAN_MB_BYTE_3,				/**< message buffer byte data 3 */
	CAN_MB_BYTE_4,				/**< message buffer byte data 4 */
	CAN_MB_BYTE_5,				/**< message buffer byte data 5 */
	CAN_MB_BYTE_6,				/**< message buffer byte data 6 */
	CAN_MB_BYTE_7,				/**< message buffer byte data 7 */
	CAN_MB_BYTE_SIZE			/**< message buffer byte data size */
} T_canMsgBufByteData;

/**
 * 	@brief		Defined enumerated type for CAN message buffer word data.
 */
typedef enum {
	CAN_MB_WORD_0,				/**< message buffer word data 0 */
	CAN_MB_WORD_1,				/**< message buffer word data 1 */
	CAN_MB_WORD_2,				/**< message buffer word data 2 */
	CAN_MB_WORD_3,				/**< message buffer word data 3 */
	CAN_MB_WORD_SIZE			/**< message buffer word data size */
} T_canMsgBufWordData;

/**
 * 	@brief		Defined enumerated type for CAN message buffer dword data.
 */
typedef enum {
	CAN_MB_DWORD_0,				/**< message buffer dword data 0 */
	CAN_MB_DWORD_1,				/**< message buffer dword data 1 */
	CAN_MB_DWORD_SIZE			/**< message buffer dword data size */
} T_canMsgBufDWordData;

/**
 * 	@brief		Defined enumerated type for CAN message buffer float32 data.
 */
typedef enum {
	CAN_MB_FLOAT32_0,			/**< message buffer float32 data 0 */
	CAN_MB_FLOAT32_1,			/**< message buffer float32 data 1 */
	CAN_MB_FLOAT32_SIZE			/**< message buffer float32 data size */
} T_canMsgBufFloat32Data;

/**
 * 	@brief		Defined enumerated type for CAN acceptance mask options.
 */
typedef enum {
	CAN_FULL_BIT_CMP,			/**< full-bit comparison */
	CAN_FULL_BIT_MASK,			/**< full-bit mask */
	CAN_USE_AMR0,				/**< uses acceptance mask register 0 (AMR0) */
	CAN_USE_AMR1				/**< uses acceptance mask register 1 (AMR1) */
} T_canAccMaskOp;

/* ----------------------------------------------------------------------------
**	CAN IO Message Buffer Types.
*/

/**
 * 	@brief		Defined enumerated type for CAN message buffer enable.
 */
typedef enum {
	CAN_MSG_BUF_DISABLED,		/**< disables message buffer */
	CAN_MSG_BUF_ENABLED			/**< enables message buffer */
} T_canMsgBufValid;

/**
 * 	@brief		Defined enumerated type for CAN ID format.
 */
typedef enum {
	CAN_ID_STD_FORMAT,			/**< used in standard format */
	CAN_ID_EXT_FORMAT			/**< used in extended format */
} T_canIDFormat;

/**
 * 	@brief		Defined enumerated type for CAN transmission request.
 */
typedef enum {
	CAN_TX_REQ_NONE,			/**< transmission is not requested */
	CAN_TX_REQ_SET				/**< transmission is requested */
} T_canTXReq;

/**
 * 	@brief		Defined enumerated type for CAN transmission RTR.
 */
typedef enum {
	CAN_TX_DATA_FRAME,			/**< transmits as data frame */
	CAN_TX_REMOTE_FRAME			/**< transmits as remote frame */
} T_canTXFrame;

/**
 * 	@brief		Defined enumerated type for CAN remote frame receive wait.
 */
typedef enum {
	CAN_TX_IMMEDIATELY,			/**< transmission starts immediately */
	CAN_TX_WAIT_RF_RECEPTION	/**< transmission starts after receiving remote frame */
} T_canTXRemoteFrameWait;

/**
 * 	@brief		Defined enumerated type for CAN transmission cancel.
 */
typedef enum {
	CAN_TCANR_X,				/**< no effect */
	CAN_TX_CANCEL				/**< cancels transmission request of message buffer */
} T_canTXCancel;

/**
 * 	@brief		Defined enumerated type for CAN transmission complete.
 */
typedef enum {
	CAN_TX_COMPLETE_NONE,		/**< transmission not completed / no transmission */
	CAN_TX_COMPLETE_SET			/**< transmission completed */
} T_canTXComplete;

/**
 * 	@brief		Defined enumerated type for CAN transmission interrupt.
 */
typedef enum {
	CAN_TX_INT_DISABLED,		/**< disables transmission complete interrupt */
	CAN_TX_INT_ENABLED			/**< enables transmission complete interrupt */
} T_canTXINT;

/**
 * 	@brief		Defined enumerated type for CAN reception complete.
 */
typedef enum {
	CAN_RX_COMPLETE_NONE,		/**< reception not completed / no reception */
	CAN_RX_COMPLETE_SET			/**< reception completed */
} T_canRXComplete;

/**
 * 	@brief		Defined enumerated type for CAN remote frame reception.
 */
typedef enum {
	CAN_RX_REMOTE_FRAME_NONE,	/**< remote frame is not received */
	CAN_RX_REMOTE_FRAME_SET		/**< remote frame is received */
} T_canRXRemoteFrame;

/**
 * 	@brief		Defined enumerated type for CAN reception overrun.
 */
typedef enum {
	CAN_RX_OVERRUN_NONE,		/**< overrun is not occurred */
	CAN_RX_OVERRUN_SET			/**< overrun is occurred */
} T_canRXOverrun;

/**
 * 	@brief		Defined enumerated type for CAN reception interrupt.
 */
typedef enum {
	CAN_RX_INT_DISABLED,		/**< disables reception complete interrupt */
	CAN_RX_INT_ENABLED			/**< enables reception complete interrupt */
} T_canRXINT;

/* ----------------------------------------------------------------------------
**	CAN IO Control Configuration Registers Getters and Setters.
*/

/**
 *	@def 		GetCAN_CSR
 *	@brief 		Control Status Register Getter.
 * 	@param		.
 * 	@return		CANCT.CSR (word).
 */
#define GetCAN_CSR()			GetIOSSREGWord(IO_CANCT, CSR)

/**
 *	@def 		GetCAN_LEIR
 *	@brief 		Last Event Indicate Register Getter.
 * 	@param		.
 * 	@return		CANCT.LEIR (byte).
 */
#define GetCAN_LEIR()			GetIOSSREGByte(IO_CANCT, LEIR)

/**
 *	@def 		GetCAN_BTR
 *	@brief 		Bit Timing Register Getter.
 * 	@param		.
 * 	@return		CANCT.BTR (word).
 */
#define GetCAN_BTR()			GetIOSSREGWord(IO_CANCT, BTR)

/**
 *	@def 		GetCAN_REC
 *	@brief 		Receive Error Counters Getter.
 * 	@param		.
 * 	@return		CANCT.RTEC.REC (byte).
 */
#define GetCAN_REC()			GetIOSSREGVar(IO_CANCT, RTEC, REC)

/**
 *	@def 		GetCAN_TEC
 *	@brief 		Transmit Error Counters Getter.
 * 	@param		.
 * 	@return		CANCT.RTEC.TEC (byte).
 */
#define GetCAN_TEC()			GetIOSSREGVar(IO_CANCT, RTEC, TEC)

/**
 *	@def 		GetCAN_AMR0
 *	@brief 		Acceptance Mask Register 0 Getter.
 * 	@param		.
 * 	@return		CANCT.AMR0 (dword).
 */
#define GetCAN_AMR0()			GetIOSSREGDWord(IO_CANCT, AMR0)

/**
 *	@def 		GetCAN_AMR1
 *	@brief 		Acceptance Mask Register 1 Getter.
 * 	@param		.
 * 	@return		CANCT.AMR1 (dword).
 */
#define GetCAN_AMR1()			GetIOSSREGDWord(IO_CANCT, AMR1)

/**
 *	@def 		SetCAN_CSR
 *	@brief 		Control Status Register Setter.
 * 	@param[in]	VAL		Control bits for CSR (word).
 * 	@return		.
 */
#define SetCAN_CSR(VAL) { \
	SetIOSSREGWord(IO_CANCT, CSR, VAL); \
}

/**
 *	@def 		SetCAN_LEIR
 *	@brief 		Last Event Indicate Register Setter.
 * 	@param[in]	VAL		Control bits for LEIR (byte).
 * 	@return		.
 */
#define SetCAN_LEIR(VAL) { \
	SetIOSSREGByte(IO_CANCT, LEIR, VAL); \
}

/**
 *	@def 		SetCAN_BTR
 *	@brief 		Bit Timing Register Setter.
 * 	@param[in]	VAL		Control bits for BTR (word).
 * 	@return		.
 */
#define SetCAN_BTR(VAL) { \
	SetIOSSREGWord(IO_CANCT, BTR, VAL); \
}

/**
 *	@def 		SetCAN_AMR0
 *	@brief 		Acceptance Mask Register 0 Setter.
 * 	@param[in]	VAL		Acceptance mask bits for AMR (dword).
 * 	@return		.
 */
#define SetCAN_AMR0(VAL) { \
	SetIOSSREGDWord(IO_CANCT, AMR0, VAL); \
}

/**
 *	@def 		SetCAN_AMR1
 *	@brief 		Acceptance Mask Register 1 Setter.
 * 	@param[in]	VAL		Acceptance mask bits for AMR (dword).
 * 	@return		.
 */
#define SetCAN_AMR1(VAL) { \
	SetIOSSREGDWord(IO_CANCT, AMR1, VAL); \
}

/* ----------------------------------------------------------------------------
**	CAN IO Message Buffer Configuration Registers Getters and Setters.
*/

/**
 *	@def 		GetCAN_BVALR
 *	@brief 		Message Buffer Valid Register Getter.
 * 	@param		.
 * 	@return		BVALR (byte).
 */
#define GetCAN_BVALR()			GetIOREGByte(IO_BVALR)

/**
 *	@def 		GetCAN_TREQR
 *	@brief 		Transmission Request Register Getter.
 * 	@param		.
 * 	@return		TREQR (byte).
 */
#define GetCAN_TREQR()			GetIOREGByte(IO_TREQR)

/**
 *	@def 		GetCAN_TCANR
 *	@brief 		Transmission Cancel Register Getter.
 * 	@param		.
 * 	@return		TCANR (byte).
 */
#define GetCAN_TCANR()			GetIOREGByte(IO_TCANR)

/**
 *	@def 		GetCAN_TCR
 *	@brief 		Transmission Complete Register Getter.
 * 	@param		.
 * 	@return		TCR (byte).
 */
#define GetCAN_TCR()			GetIOREGByte(IO_TCR)

/**
 *	@def 		GetCAN_RCR
 *	@brief 		Reception Complete Register Getter.
 * 	@param		.
 * 	@return		RCR (byte).
 */
#define GetCAN_RCR()			GetIOREGByte(IO_RCR)

/**
 *	@def 		GetCAN_RRTRR
 *	@brief 		Reception RTR Register Getter.
 * 	@param		.
 * 	@return		RRTRR (byte).
 */
#define GetCAN_RRTRR()			GetIOREGByte(IO_RRTRR)

/**
 *	@def 		GetCAN_ROVRR
 *	@brief 		Reception Overrun Register Getter.
 * 	@param		.
 * 	@return		ROVRR (byte).
 */
#define GetCAN_ROVRR()			GetIOREGByte(IO_ROVRR)

/**
 *	@def 		GetCAN_RIER
 *	@brief 		Reception Complete Interrupt Enable Register Getter.
 * 	@param		.
 * 	@return		RIER (byte).
 */
#define GetCAN_RIER()			GetIOREGByte(IO_RIER)

/**
 *	@def 		GetCAN_IDER
 *	@brief 		IDE Register Getter.
 * 	@param		.
 * 	@return		CANCT.IDER (byte).
 */
#define GetCAN_IDER()			GetIOSSREGByte(IO_CANCT, IDER)

/**
 *	@def 		GetCAN_TRTRR
 *	@brief 		Transmission RTR Register Getter.
 * 	@param		.
 * 	@return		CANCT.TRTRR (byte).
 */
#define GetCAN_TRTRR()			GetIOSSREGByte(IO_CANCT, TRTRR)

/**
 *	@def 		GetCAN_RFWTR
 *	@brief 		Remote Frame Receive Wait Register Getter.
 * 	@param		.
 * 	@return		CANCT.RFWTR (byte).
 */
#define GetCAN_RFWTR()			GetIOSSREGByte(IO_CANCT, RFWTR)

/**
 *	@def 		GetCAN_TIER
 *	@brief 		Transmission Complete Interrupt Enable Register Getter.
 * 	@param		.
 * 	@return		CANCT.TIER (byte).
 */
#define GetCAN_TIER()			GetIOSSREGByte(IO_CANCT, TIER)

/**
 *	@def 		GetCAN_AMSR
 *	@brief 		Acceptance Mask Select Register Getter.
 * 	@param		.
 * 	@return		CANCT.AMSR (word).
 */
#define GetCAN_AMSR()			GetIOSSREGWord(IO_CANCT, AMSR)

/**
 *	@def 		SetCAN_BVALR
 *	@brief 		Message Buffer Valid Register Setter.
 * 	@param[in]	VAL		Control bits for BVALR (byte).
 * 	@return		.
 */
#define SetCAN_BVALR(VAL) { \
	SetIOREGByte(IO_BVALR, VAL); \
}

/**
 *	@def 		SetCAN_TREQR
 *	@brief 		Transmission Request Register Setter.
 * 	@param[in]	VAL		Control bits for TREQR (byte).
 * 	@return		.
 */
#define SetCAN_TREQR(VAL) { \
	SetIOREGByte(IO_TREQR, VAL); \
}

/**
 *	@def 		SetCAN_TCANR
 *	@brief 		Transmission Cancel Register Setter.
 * 	@param[in]	VAL		Control bits for TCANR (byte).
 * 	@return		.
 */
#define SetCAN_TCANR(VAL) { \
	SetIOREGByte(IO_TCANR, VAL); \
}

/**
 *	@def 		SetCAN_TCR
 *	@brief 		Transmission Complete Register Setter.
 * 	@param[in]	VAL		Control bits for TCR (byte).
 * 	@return		.
 */
#define SetCAN_TCR(VAL) { \
	SetIOREGByte(IO_TCR, VAL); \
}

/**
 *	@def 		SetCAN_RCR
 *	@brief 		Reception Complete Register Setter.
 * 	@param[in]	VAL		Control bits for RCR (byte).
 * 	@return		.
 */
#define SetCAN_RCR(VAL) { \
	SetIOREGByte(IO_RCR, VAL); \
}

/**
 *	@def 		SetCAN_RRTRR
 *	@brief 		Reception RTR Register Setter.
 * 	@param[in]	VAL		Control bits for RRTRR (byte).
 * 	@return		.
 */
#define SetCAN_RRTRR(VAL) { \
	SetIOREGByte(IO_RRTRR, VAL); \
}

/**
 *	@def 		SetCAN_ROVRR
 *	@brief 		Reception Overrun Register Setter.
 * 	@param[in]	VAL		Control bits for ROVRR (byte).
 * 	@return		.
 */
#define SetCAN_ROVRR(VAL) { \
	SetIOREGByte(IO_ROVRR, VAL); \
}

/**
 *	@def 		SetCAN_RIER
 *	@brief 		Reception Complete Interrupt Enable Register Setter.
 * 	@param[in]	VAL		Control bits for RIER (byte).
 * 	@return		.
 */
#define SetCAN_RIER(VAL) { \
	SetIOREGByte(IO_RIER, VAL); \
}

/**
 *	@def 		SetCAN_IDER
 *	@brief 		IDE Register Setter.
 * 	@param[in]	VAL		Control bits for IDER (byte).
 * 	@return		.
 */
#define SetCAN_IDER(VAL) { \
	SetIOSSREGByte(IO_CANCT, IDER, VAL); \
}

/**
 *	@def 		SetCAN_TRTRR
 *	@brief 		Transmission RTR Register Setter.
 * 	@param[in]	VAL		Control bits for TRTRR (byte).
 * 	@return		.
 */
#define SetCAN_TRTRR(VAL) { \
	SetIOSSREGByte(IO_CANCT, TRTRR, VAL); \
}

/**
 *	@def 		SetCAN_RFWTR
 *	@brief 		Remote Frame Receive Wait Register Setter.
 * 	@param[in]	VAL		Control bits for RFWTR (byte).
 * 	@return		.
 */
#define SetCAN_RFWTR(VAL) { \
	SetIOSSREGByte(IO_CANCT, RFWTR, VAL); \
}

/**
 *	@def 		SetCAN_TIER
 *	@brief 		Transmission Complete Interrupt Enable Register Setter.
 * 	@param[in]	VAL		Control bits for TIER (byte).
 * 	@return		.
 */
#define SetCAN_TIER(VAL) { \
	SetIOSSREGByte(IO_CANCT, TIER, VAL); \
}

/**
 *	@def 		SetCAN_AMSR
 *	@brief 		Acceptance Mask Select Register Setter.
 * 	@param[in]	VAL		Control bits for AMSR (word).
 * 	@return		.
 */
#define SetCAN_AMSR(VAL) { \
	SetIOSSREGWord(IO_CANCT, AMSR, VAL); \
}

/* ----------------------------------------------------------------------------
**	CAN IO Data Configuration Registers Getters and Setters.
*/

/**
 *	@def 		GetCAN_IDR
 *	@brief 		ID Register Getter.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@return		CANID.IDR[MBX] (dword).
 */
#define GetCAN_IDR(MBX)			GetIOSSREGDWord(IO_CANID, IDR[MBX])

/**
 *	@def 		GetCAN_DLCR
 *	@brief 		DLC Register Getter.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@return		CANID.DLCR[MBX] (word).
 */
#define GetCAN_DLCR(MBX)		GetIOSSREGWord(IO_CANID, DLCR[MBX])

/**
 *	@def 		GetCAN_DTR_BYTE
 *	@brief 		Data Register Getter.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@param[in]	IDX 	Byte index (bits).
 * 	@return		CANID.DTR[MBX].BYTE[IDX] (byte).
 */
#define GetCAN_DTR_BYTE(MBX, IDX) \
	GetIOSSREGVar(IO_CANID, DTR[MBX], BYTE[IDX])

/**
 *	@def 		GetCAN_DTR_WORD
 *	@brief 		Data Register Getter.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@param[in]	IDX 	Word index (bits).
 * 	@return		CANID.DTR[MBX].WORD[IDX] (word).
 */
#define GetCAN_DTR_WORD(MBX, IDX) \
	GetIOSSREGVar(IO_CANID, DTR[MBX], WORD[IDX])

/**
 *	@def 		GetCAN_DTR_DWORD
 *	@brief 		Data Register Getter.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@param[in]	IDX 	DWord index (bits).
 * 	@return		CANID.DTR[MBX].DWORD[IDX] (dword).
 */
#define GetCAN_DTR_DWORD(MBX, IDX) \
	GetIOSSREGVar(IO_CANID, DTR[MBX], DWORD[IDX])

/**
 *	@def 		GetCAN_DTR_FLOAT
 *	@brief 		Data Register Getter.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@param[in]	IDX 	Float32 index (bits).
 * 	@return		CANID.DTR[MBX].FLOAT[IDX] (float32).
 */
#define GetCAN_DTR_FLOAT(MBX, IDX) \
	GetIOSSREGVar(IO_CANID, DTR[MBX], FLOAT[IDX])

/**
 *	@def 		GetCAN_DTR_DOUBLE
 *	@brief 		Data Register Getter.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@return		CANID.DTR[MBX].DOUBLE (float64).
 */
#define GetCAN_DTR_DOUBLE(MBX) \
	GetIOSSREGVar(IO_CANID, DTR[MBX], DOUBLE)

/**
 *	@def 		SetCAN_IDR
 *	@brief 		ID Register Setter.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@param[in]	VAL		ID bits for CAN (dword).
 * 	@return		.
 */
#define SetCAN_IDR(MBX, VAL) { \
	SetIOSSREGDWord(IO_CANID, IDR[MBX], VAL); \
}

/**
 *	@def 		SetCAN_DLCR
 *	@brief 		DLC Register Setter.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@param[in]	VAL		Data length bits for CAN (word).
 * 	@return		.
 */
#define SetCAN_DLCR(MBX, VAL) { \
	SetIOSSREGWord(IO_CANID, DLCR[MBX], VAL); \
}

/**
 *	@def 		SetCAN_DTR_WORD
 *	@brief 		Data Register Setter.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@param[in]	IDX 	Word index (bits).
 * 	@param[in]	VAL		Data for CAN DTR (word).
 * 	@return		.
 */
#define SetCAN_DTR_WORD(MBX, IDX, VAL) { \
	SetIOSSREGVar(IO_CANID, DTR[MBX], WORD[IDX], (T_word)(VAL)); \
}

/**
 *	@def 		SetCAN_DTR_DWORD
 *	@brief 		Data Register Setter.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@param[in]	IDX 	DWord index (bits).
 * 	@param[in]	VAL		Data for CAN DTR (dword).
 * 	@return		.
 */
#define SetCAN_DTR_DWORD(MBX, IDX, VAL) { \
	SetIOSSREGVar(IO_CANID, DTR[MBX], DWORD[IDX], (T_dword)(VAL)); \
}

/**
 *	@def 		SetCAN_DTR_FLOAT
 *	@brief 		Data Register Setter.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@param[in]	IDX 	Float32 index (bits).
 * 	@param[in]	VAL		Data for CAN DTR (float32).
 * 	@return		.
 */
#define SetCAN_DTR_FLOAT(MBX, IDX, VAL) { \
	SetIOSSREGVar(IO_CANID, DTR[MBX], FLOAT[IDX], (T_float32)(VAL)); \
}

/**
 *	@def 		SetCAN_DTR_DOUBLE
 *	@brief 		Data Register Setter.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@param[in]	VAL		Data for CAN DTR (float64).
 * 	@return		.
 */
#define SetCAN_DTR_DOUBLE(MBX, VAL) { \
	SetIOSSREGVar(IO_CANID, DTR[MBX], DOUBLE, (T_float64)(VAL)); \
}

/* ----------------------------------------------------------------------------
**	CAN IO Control Configuration Register Fields Macro Functions.
*/

/**
 *	@def 		IsCANBusOpHalted
 *	@brief 		Check if CAN bus operation is halted!
 * 	@param		.
 * 	@return		boolean.
 */
#define IsCANBusOpHalted() \
	EQU(GetIOSSREGBitVar(IO_CANCT, CSR, HALT), CAN_BUS_OP_HALTED)

/**
 *	@def 		StartCANBusOp
 *	@brief 		Start CAN Bus Operation.
 * 	@param		.
 * 	@return		.
 */
#define StartCANBusOp() { \
	SetIOSSREGBitVar(IO_CANCT, CSR, HALT, CAN_BUS_OP_HALT_CANCELED); \
}

/**
 *	@def 		StopCANBusOp
 *	@brief 		Stop CAN Bus Operation.
 * 	@param		.
 * 	@return		.
 */
#define StopCANBusOp() { \
	SetIOSSREGBitVar(IO_CANCT, CSR, HALT, CAN_BUS_OP_HALTED); \
}

/**
 *	@def 		EnableCANNSInterrupt
 *	@brief 		CAN Node Status Interrupt Enabler.
 * 	@param		.
 * 	@return		.
 */
#define EnableCANNSInterrupt() { \
	SetIOSSREGBitVar(IO_CANCT, CSR, NIE, CAN_NS_INT_ENABLED); \
}

/**
 *	@def 		DisableCANNSInterrupt
 *	@brief 		CAN Node Status Interrupt Disabler.
 * 	@param		.
 * 	@return		.
 */
#define DisableCANNSInterrupt() { \
	SetIOSSREGBitVar(IO_CANCT, CSR, NIE, CAN_NS_INT_DISABLED); \
}

/**
 *	@def 		IsCANNSTransition
 *	@brief 		Check if CAN Node Status Transition Interrupt Active.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsCANNSTransition() \
	EQU(GetIOSSREGBitVar(IO_CANCT, CSR, NT), CAN_NS_TRANSIT_SET)

/**
 *	@def 		ClearCANNSTransition
 *	@brief 		Clear CAN Node Status Transition Interrupt.
 * 	@param		.
 * 	@return		.
 */
#define ClearCANNSTransition() { \
	SetIOSSREGBitVar(IO_CANCT, CSR, NT, CAN_NS_TRANSIT_NONE); \
}

/**
 *	@def 		EnableCANTxOutputPin
 *	@brief 		CAN Transmit Output Pin Enabler.
 * 	@param		.
 * 	@return		.
 */
#define EnableCANTxOutputPin() { \
	SetIOSSREGBitVar(IO_CANCT, CSR, TOE, CAN_TX_PIN_OUTPUT); \
}

/**
 *	@def 		DisableCANTxOutputPin
 *	@brief 		CAN Transmit Output Pin Disabler.
 * 	@param		.
 * 	@return		.
 */
#define DisableCANTxOutputPin() { \
	SetIOSSREGBitVar(IO_CANCT, CSR, TOE, CAN_TX_PIN_GPIO); \
}

/**
 *	@def 		GetCANNodeStatus
 *	@brief 		Gets CAN node status transition.
 * 	@param		.
 * 	@return		node status (bits).
 */
#define GetCANNodeStatus() \
	GetIOSSREGBitVar(IO_CANCT, CSR, NS)

/**
 *	@def 		IsCANNSErrActive
 *	@brief 		Check if CAN NS Transition to Error Active.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsCANNSErrActive() \
	EQU(GetIOSSREGBitVar(IO_CANCT, CSR, NS), CAN_ERR_ACTIVE)

/**
 *	@def 		IsCANNSWarning
 *	@brief 		Check if CAN NS Transition to Warning.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsCANNSWarning() \
	EQU(GetIOSSREGBitVar(IO_CANCT, CSR, NS), CAN_ERR_WARNING)

/**
 *	@def 		IsCANNSErrPassive
 *	@brief 		Check if CAN NS Transition to Error Passive.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsCANNSErrPassive() \
	EQU(GetIOSSREGBitVar(IO_CANCT, CSR, NS), CAN_ERR_PASSIVE)

/**
 *	@def 		IsCANNSBusOff
 *	@brief 		Check if CAN NS Transition to Bus Off.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsCANNSBusOff() \
	EQU(GetIOSSREGBitVar(IO_CANCT, CSR, NS), CAN_BUS_OFF)

/**
 *	@def 		IsCANMsgOnReception
 *	@brief 		Receive Status Checker.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsCANMsgOnReception() \
	EQU(GetIOSSREGBitVar(IO_CANCT, CSR, RS), CAN_RX_SET)

/**
 *	@def 		IsCANMsgOnTransmission
 *	@brief 		Trasmit Status Checker.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsCANMsgOnTransmission() \
	EQU(GetIOSSREGBitVar(IO_CANCT, CSR, TS), CAN_TX_SET)

/**
 *	@def 		IsCANLEReception
 *	@brief 		Last Event is Reception Complete Checker.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsCANLEReception() \
	EQU(GetIOSSREGBitVar(IO_CANCT, LEIR, RCE), CAN_LAST_EVT_RX_SET)

/**
 *	@def 		ClearCANLEReception
 *	@brief 		Clear CAN Last Event - Reception Complete.
 * 	@param		.
 * 	@return		.
 */
#define ClearCANLEReception() { \
	SetIOSSREGBitVar(IO_CANCT, LEIR, RCE, CAN_LAST_EVT_RX_NONE); \
}

/**
 *	@def 		IsCANLETransmission
 *	@brief 		Last Event is Transmission Complete Checker.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsCANLETransmission() \
	EQU(GetIOSSREGBitVar(IO_CANCT, LEIR, TCE), CAN_LAST_EVT_TX_SET)

/**
 *	@def 		ClearCANLETransmission
 *	@brief 		Clear CAN Last Event - Transmission Complete.
 * 	@param		.
 * 	@return		.
 */
#define ClearCANLETransmission() { \
	SetIOSSREGBitVar(IO_CANCT, LEIR, TCE, CAN_LAST_EVT_TX_NONE); \
}

/**
 *	@def 		IsCANLENodeTransition
 *	@brief 		Last Event is Node Status Transmission Checker.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsCANLENodeTransition() \
	EQU(GetIOSSREGBitVar(IO_CANCT, LEIR, NTE), CAN_LAST_EVT_NS_SET)

/**
 *	@def 		ClearCANLENodeTransition
 *	@brief 		Clear CAN Last Event - Node Status Transition.
 * 	@param		.
 * 	@return		.
 */
#define ClearCANLENodeTransition() { \
	SetIOSSREGBitVar(IO_CANCT, LEIR, NTE, CAN_LAST_EVT_NS_NONE); \
}

/**
 *	@def 		SetCANTimeSegment2
 *	@brief 		Bit Timing - Phase Buffer Segment 2 Setter.
 * 	@param[in]	VAL		Timing bits for CAN (3 bits).
 * 	@return		.
 */
#define SetCANTimeSegment2(VAL) { \
	SetIOSSREGBitVar(IO_CANCT, BTR, TS2, VAL); \
}

/**
 *	@def 		SetCANTimeSegment1
 *	@brief 		Bit Timing - Phase Buffer Segment 1 Setter.
 * 	@param[in]	VAL		Timing bits for BTR (4 bits).
 * 	@return		.
 */
#define SetCANTimeSegment1(VAL) { \
	SetIOSSREGBitVar(IO_CANCT, BTR, TS1, VAL); \
}

/**
 *	@def 		SetCANResyncJumpWidth
 *	@brief 		Bit Timing - Synchronization Segment Setter.
 * 	@param[in]	VAL		Timing bits for BTR (2 bits).
 * 	@return		.
 */
#define SetCANResyncJumpWidth(VAL) { \
	SetIOSSREGBitVar(IO_CANCT, BTR, RSJ, VAL); \
}

/**
 *	@def 		SetCANPrescaler
 *	@brief 		Bit Timing - Propagation Time Segment Setter.
 * 	@param[in]	VAL		Timing bits for BTR (6 bits).
 * 	@return		.
 */
#define SetCANPrescaler(VAL) { \
	SetIOSSREGBitVar(IO_CANCT, BTR, PSC, VAL); \
}

/* ----------------------------------------------------------------------------
**	CAN IO Message Buffer Configuration Register Fields Macro Functions.
*/

/**
 *	@def 		EnableCANMsgBuff
 *	@brief 		Message Buffer Valid Enabler.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@return		.
 */
#define EnableCANMsgBuff(MBX) { \
	SetCAN_BVALR(ModBit(GetCAN_BVALR(), MBX, CAN_MSG_BUF_ENABLED)); \
}

/**
 *	@def 		DisableCANMsgBuff
 *	@brief 		Message Buffer Valid Disabler.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@return		.
 */
#define DisableCANMsgBuff(MBX) { \
	SetCAN_BVALR(ModBit(GetCAN_BVALR(), MBX, CAN_MSG_BUF_DISABLED)); \
}

/**
 *	@def 		SetCANIDEExtendedFormat
 *	@brief 		IDE Extended Format Setter.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@return		.
 */
#define SetCANIDEExtendedFormat(MBX) { \
	SetCAN_IDER(ModBit(GetCAN_IDER(), MBX, CAN_ID_EXT_FORMAT)); \
}

/**
 *	@def 		SetCANIDEStandardFormat
 *	@brief 		IDE Standard Format Setter.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@return		.
 */
#define SetCANIDEStandardFormat(MBX) { \
	SetCAN_IDER(ModBit(GetCAN_IDER(), MBX, CAN_ID_STD_FORMAT)); \
}

/**
 *	@def 		RequestCANTransmit
 *	@brief 		Transmission Request Generator.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@return		.
 */
#define RequestCANTransmit(MBX) { \
	SetCAN_TREQR(ModBit(GetCAN_TREQR(), MBX, CAN_TX_REQ_SET)); \
}

/**
 *	@def 		RequestCANNoTransmit
 *	@brief 		Transmission Request Disabler.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@return		.
 */
#define RequestCANNoTransmit(MBX) { \
	SetCAN_TREQR(ModBit(GetCAN_TREQR(), MBX, CAN_TX_REQ_NONE)); \
}

/**
 *	@def 		TransmitAsCANRemoteFrame
 *	@brief 		Transmission RTR (Remote Frame).
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@return		.
 */
#define TransmitAsCANRemoteFrame(MBX) 	{ \
	SetCAN_TRTRR(ModBit(GetCAN_TRTRR(), MBX, CAN_TX_REMOTE_FRAME)); \
}

/**
 *	@def 		TransmitAsCANDataFrame
 *	@brief 		Transmission RTR (Data Frame).
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@return		.
 */
#define TransmitAsCANDataFrame(MBX) { \
	SetCAN_TRTRR(ModBit(GetCAN_TRTRR(), MBX, CAN_TX_DATA_FRAME)); \
}

/**
 *	@def 		StartCANAfterRFReceived
 *	@brief 		Remote Frame Receive Wait Enabler.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@return		.
 */
#define StartCANAfterRFReceived(MBX) { \
	SetCAN_RFWTR(ModBit(GetCAN_RFWTR(), MBX, CAN_TX_WAIT_RF_RECEPTION)); \
}

/**
 *	@def 		StartCANTransmitImm
 *	@brief 		Remote Frame Receive Wait Disabler.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@return		.
 */
#define StartCANTransmitImm(MBX) { \
	SetCAN_RFWTR(ModBit(GetCAN_RFWTR(), MBX, CAN_TX_IMMEDIATELY)); \
}

/**
 *	@def 		CancelCANTransmit
 *	@brief 		Transmission Cancel.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@return		.
 */
#define CancelCANTransmit(MBX) { \
	SetCAN_TCANR(ModBit(GetCAN_TCANR(), MBX, CAN_TX_CANCEL)); \
}

/**
 *	@def 		IsCANTransmitComp
 *	@brief 		Transmission Complete Checker.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@return		TCR bit.
 */
#define IsCANTransmitComp(MBX) \
	EQU(ReadBit(GetCAN_TCR(), MBX), CAN_TX_COMPLETE_SET)

/**
 *	@def 		ClearCANTransmitComp
 *	@brief 		Clear Transmission Complete.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@return		.
 */
#define ClearCANTransmitComp(MBX) { \
	SetCAN_TCR(ModBit(GetCAN_TCR(), MBX, CAN_TX_COMPLETE_NONE)); \
}

/**
 *	@def 		EnableCANTransmitINT
 *	@brief 		Transmission Complete Interrupt Enabler.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@return		.
 */
#define EnableCANTransmitINT(MBX) { \
	SetCAN_TIER(ModBit(GetCAN_TIER(), MBX, CAN_TX_INT_ENABLED)); \
}

/**
 *	@def 		DisableCANTransmitINT
 *	@brief 		Transmission Complete Interrupt Disabler.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@return		.
 */
#define DisableCANTransmitINT(MBX) { \
	SetCAN_TIER(ModBit(GetCAN_TIER(), MBX, CAN_TX_INT_DISABLED)); \
}

/**
 *	@def 		IsCANReceiveComp
 *	@brief 		Reception Complete Checker.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@return		RCR bit.
 */
#define IsCANReceiveComp(MBX) \
	EQU(ReadBit(GetCAN_RCR(), MBX), CAN_RX_COMPLETE_SET)

/**
 *	@def 		ClearCANReceiveComp
 *	@brief 		Clear Reception Complete.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@return		.
 */
#define ClearCANReceiveComp(MBX) { \
	SetCAN_RCR(ModBit(GetCAN_RCR(), MBX, CAN_RX_COMPLETE_NONE)); \
}

/**
 *	@def 		IsCANReceiveRTRComp
 *	@brief 		Reception RTR Checker.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@return		RRTRR bit.
 */
#define IsCANReceiveRTRComp(MBX) \
	EQU(ReadBit(GetCAN_RRTRR(), MBX), CAN_RX_REMOTE_FRAME_SET)

/**
 *	@def 		ClearCANReceiveRTRComp
 *	@brief 		Clear Reception RTR Complete.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@return		.
 */
#define ClearCANReceiveRTRComp(MBX) { \
	SetCAN_RRTRR(ModBit(GetCAN_RRTRR(), MBX, CAN_RX_REMOTE_FRAME_NONE)); \
}

/**
 *	@def 		IsCANReceiveOvr
 *	@brief 		Reception Overrun Checker.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@return		ROVRR bit.
 */
#define IsCANReceiveOvr(MBX) \
	EQU(ReadBit(GetCAN_ROVRR(), MBX), CAN_RX_OVERRUN_SET)

/**
 *	@def 		ClearCANReceiveOvr
 *	@brief 		Clear Reception Overrun.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@return		.
 */
#define ClearCANReceiveOvr(MBX) { \
	SetCAN_ROVRR(ModBit(GetCAN_ROVRR(), MBX, CAN_RX_OVERRUN_NONE)); \
}

/**
 *	@def 		EnableCANReceptionINT
 *	@brief 		Reception Complete Interrupt Enabler.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@return		.
 */
#define EnableCANReceptionINT(MBX) { \
	SetCAN_RIER(ModBit(GetCAN_RIER(), MBX, CAN_RX_INT_ENABLED)); \
}

/**
 *	@def 		DisableCANReceptionINT
 *	@brief 		Reception Complete Interrupt Disabler.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@return		.
 */
#define DisableCANReceptionINT(MBX) { \
	SetCAN_RIER(ModBit(GetCAN_RIER(), MBX, CAN_RX_INT_DISABLED)); \
}

/**
 *	@def 		SetCANAccMaskOption
 *	@brief 		Acceptance Mask Selection Setter.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@param[in]	VAL		Acceptance Mask Option (word).
 * 	@return		.
 */
#define SetCANAccMaskOption(MBX, VAL) { \
	SetCAN_AMSR(NewPair(GetCAN_AMSR(), MBX, T_word, VAL)); \
}

#endif /* CAN_IO_H. */
