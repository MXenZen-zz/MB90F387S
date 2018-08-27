/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Universal Asynchronous Receiver/Transmitter							     */
/**
 *	@file		IO/ser_io.h
 * 	@brief		This file contains types, getters and setters, and other
 * 				macro functions for SER IO registers.
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

#ifndef SER_IO_H
#define SER_IO_H

#include <IO/io_mb90385.h>

/* ----------------------------------------------------------------------------
**	SER IO Types.
*/

/**
 * 	@brief		Defined enumerated type for SER enable.
 */
typedef enum {
	SER_DISABLED,				/**< disable transmit / receive */
	SER_ENABLED					/**< enable transmit / receive */
} T_serRXTXEnable;

/**
 * 	@brief		Defined enumerated type for SER pin output.
 */
typedef enum {
	SER_PIN_GPIO,				/**< serves as general-purpose I/O port */
	SER_PIN_OUTPUT				/**< serves as serial data or clock output */
} T_serPin;

/**
 * 	@brief		Defined enumerated type for SER clock input source.
 */
typedef enum {
	SER_BAUD_ASYNC_76923 = 0U,	/**< 76,923 bps or (f / 1) / (8 x 13 x 2) */
	SER_BAUD_SYNC_2000K	 = 0U,	/**< 2 Mbps or (f / 8) / 1 */
	SER_BAUD_ASYNC_38461 = 1U,	/**< 38,461 bps or (f / 1) / (8 x 13 x 4)*/
	SER_BAUD_SYNC_1000K	 = 1U,	/**< 1 Mbps or (f / 8) / 2 */
	SER_BAUD_ASYNC_19230 = 2U,	/**< 19,230 bps or (f / 1) / (8 x 13 x 8) */
	SER_BAUD_SYNC_500K	 = 2U,	/**< 500 kbps or (f / 8) / 4 */
	SER_BAUD_ASYNC_9615  = 3U,	/**< 9,615 bps or (f / 1) / (8 x 13 x 16) */
	SER_BAUD_SYNC_250K   = 3U,	/**< 250 kbps or (f / 8) / 8 */
	SER_BAUD_ASYNC_500K  = 4U,	/**< 500 kbps or (f / 1) / (8 x 2 x 2) */
	SER_BAUD_SYNC_125K   = 4U,	/**< 125 kbps or (f / 8) / 16 */
	SER_BAUD_ASYNC_250K  = 5U,	/**< 250 kbps or (f / 1) / (8 x 2 x 4) */
	SER_BAUD_SYNC_62500  = 5U,	/**< 62.5 kbps or (f / 8) / 32 */
	SER_BAUD_INTERNAL    = 6U,	/**< baud rate by internal timer (RLT1) */
	SER_BAUD_EXTERNAL    = 7U	/**< baud rate by external clock */
} T_serBaud;

/**
 * 	@brief		Defined enumerated type for SER operation mode.
 */
typedef enum {
	SER_MODE_ASYNC,				/**< asynchronous mode (normal mode) */
	SER_MODE_ASYNC_MULTI,		/**< asynchronous multiprocessor mode */
	SER_MODE_SYNC_CLK,			/**< clock synchronous mode */
	SER_MODE_DISABLED			/**< setting disabled */
} T_serMode;

/**
 * 	@brief		Defined enumerated type for SER comm. prescaler division ratio.
 */
typedef enum {
	SER_PRESCALE_DIV_1,			/**< 1-divided clock */
	SER_PRESCALE_DIV_2,			/**< 2-divided clock */
	SER_PRESCALE_DIV_3,			/**< 3-divided clock */
	SER_PRESCALE_DIV_4,			/**< 4-divided clock */
	SER_PRESCALE_DIV_5,			/**< 5-divided clock */
	SER_PRESCALE_DIV_6,			/**< 6-divided clock */
	SER_PRESCALE_DIV_7,			/**< 7-divided clock */
	SER_PRESCALE_DIV_8			/**< 8-divided clock */
} T_serPrescaler;

/**
 * 	@brief		Defined enumerated type for SER comm. prescaler control.
 */
typedef enum {
	SER_PRESCALE_STOPPED,		/**< communication prescaler stopped */
	SER_PRESCALE_ENABLED		/**< communication prescaler enabled */
} T_serPrescaleControl;

/**
 * 	@brief		Defined enumerated type for SER frame type.
 */
typedef enum {
	SER_FRAME_DATA,				/**< data frame */
	SER_FRAME_ADDRESS			/**< address frame */
} T_serFrameType;

/**
 * 	@brief		Defined enumerated type for SER data length.
 */
typedef enum {
	SER_DL_7BITS,				/**< 7 bits data length */
	SER_DL_8BITS				/**< 8 bits data length */
} T_serDataLength;

/**
 * 	@brief		Defined enumerated type for SER stop length.
 */
typedef enum {
	SER_SL_1BIT,				/**< 1-bit stop length */
	SER_SL_2BITS				/**< 2-bit stop length */
} T_serStopLength;

/**
 * 	@brief		Defined enumerated type for SER parity.
 */
typedef enum {
	SER_PARITY_EVEN,			/**< even parity */
	SER_PARITY_ODD				/**< odd parity */
} T_serParity;

/**
 * 	@brief		Defined enumerated type for SER parity enable.
 */
typedef enum {
	SER_PARITY_NONE,			/**< no parity */
	SER_PARITY_SET				/**< with parity */
} T_serParityEnable;

/**
 * 	@brief		Defined enumerated type for SER transfer direction.
 */
typedef enum {
	SER_LSB_FIRST,				/**< transfer from LSB first */
	SER_MSB_FIRST				/**< transfer from MSB first */
} T_serDirection;

/**
 * 	@brief		Defined enumerated type for SER interrupt enable.
 */
typedef enum {
	SER_INT_DISABLED,			/**< disables transmit / receive interrupt */
	SER_INT_ENABLED				/**< enables transmit / receive interrupt */
} T_serINT;

/**
 * 	@brief		Defined enumerated type for SER data loading and writing flags.
 */
typedef enum {
	SER_TX_WITHDATA = 0U,		/**< with transmit data */
	SER_RX_NODATA   = 0U,		/**< no receive data */
	SER_TX_NODATA   = 1U,		/**< no transmit data */
	SER_RX_WITHDATA = 1U		/**< with receive data */
} T_serRXLoadTXWrite;

/**
 * 	@brief		Defined enumerated type for SER error flags.
 */
typedef enum {
	SER_ERR_NONE    = 0U,		/**< no typical error */
	SER_ERR_CLEAR   = 0U,		/**< clear PE and ORE, FRE, bits */
	SER_ERR_FRAME   = 1U,		/**< frame error */
	SER_ERR_OVERRUN = 1U,		/**< overrun error */
	SER_ERR_PARITY  = 1U		/**< parity error */
} T_serError;

/* ----------------------------------------------------------------------------
**	SER IO Registers Getters and Setters.
*/

/**
 *	@def 		GetSER_SCR
 *	@brief 		Serial Control Register Getter.
 * 	@param		.
 * 	@return		SCR1 (byte).
 */
#define GetSER_SCR()			GetIOREGByte(IO_SCR1)

/**
 *	@def 		GetSER_SMR
 *	@brief 		Serial Mode Register Getter.
 * 	@param		.
 * 	@return		SMR1 (byte).
 */
#define GetSER_SMR()			GetIOREGByte(IO_SMR1)

/**
 *	@def 		GetSER_SIDR
 *	@brief 		Serial Input Data Register Getter.
 * 	@param		.
 * 	@return		SIDR1 (byte).
 */
#define GetSER_SIDR()			GetIOREGByte(IO_SIODR1)

/**
 *	@def 		GetSER_SSR
 *	@brief 		Serial Status Register Getter.
 * 	@param		.
 * 	@return		SSR1 (byte).
 */
#define GetSER_SSR()			GetIOREGByte(IO_SSR1)

/**
 *	@def 		GetSER_CDCR
 *	@brief 		Communication Prescaler Control Register Getter.
 * 	@param		.
 * 	@return		CDCR1 (byte).
 */
#define GetSER_CDCR()			GetIOREGByte(IO_CDCR1)

/**
 *	@def 		SetSER_SCR
 *	@brief 		Serial Control Register Setter.
 * 	@param[in]	VAL		Control bits for SCR (byte).
 * 	@return		.
 */
#define SetSER_SCR(VAL) { \
	SetIOREGByte(IO_SCR1, VAL); \
}

/**
 *	@def 		SetSER_SMR
 *	@brief 		Serial Mode Register Setter.
 * 	@param[in]	VAL		Control bits for SMR (byte).
 * 	@return		.
 */
#define SetSER_SMR(VAL) { \
	SetIOREGByte(IO_SMR1, VAL);	\
}

/**
 *	@def 		SetSER_SODR
 *	@brief 		Serial Output Data Register Setter.
 * 	@param[in]	VAL		Data bits for SODR1 (byte).
 * 	@return		.
 */
#define SetSER_SODR(VAL) { \
	SetIOREGByte(IO_SIODR1, VAL); \
}

/**
 *	@def 		SetSER_SSR
 *	@brief 		Serial Status Register Setter.
 * 	@param[in]	VAL		Control bits for SSR (byte).
 * 	@return		.
 */
#define SetSER_SSR(VAL) { \
	SetIOREGByte(IO_SSR1, VAL); \
}

/**
 *	@def 		SetSER_CDCR
 *	@brief 		Communication Prescaler Control Register Setter.
 * 	@param[in]	VAL		Control bits for CDCR (byte).
 * 	@return		.
 */
#define SetSER_CDCR(VAL) { \
	SetIOREGByte(IO_CDCR1, VAL); \
}

/* ----------------------------------------------------------------------------
**	SER IO Register Fields Macro Functions.
*/

/**
 *	@def 		InitializeSERRegisters
 *	@brief 		UART Registers Initializer.
 * 	@param		.
 * 	@return		.
 * 	@warning	Do not initialiaze SER if Accemic MDE is using UART.
 */
#define InitializeSERRegisters() { \
	SetIOREGBitVar(IO_SMR1, RST, STD_HIGH); \
}

/**
 *	@def 		EnableSERTransmit
 *	@brief 		Transmit Enabler.
 * 	@param		.
 * 	@return		.
 */
#define EnableSERTransmit() { \
	SetIOREGBitVar(IO_SCR1, TXE, SER_ENABLED); \
}

/**
 *	@def 		DisableSERTransmit
 *	@brief 		Transmit Disabler.
 * 	@param		.
 * 	@return		.
 */
#define DisableSERTransmit() { \
	SetIOREGBitVar(IO_SCR1, TXE, SER_DISABLED); \
}

/**
 *	@def 		EnableSERReceive
 *	@brief 		Receive Enabler.
 * 	@param		.
 * 	@return		.
 */
#define EnableSERReceive() { \
	SetIOREGBitVar(IO_SCR1, RXE, SER_ENABLED); \
}

/**
 *	@def 		DisableSERReceive
 *	@brief 		Receive Disabler.
 * 	@param		.
 * 	@return		.
 */
#define DisableSERReceive() { \
	SetIOREGBitVar(IO_SCR1, RXE, SER_DISABLED); \
}

/**
 *	@def 		EnableSERDataOutputPin
 *	@brief 		Serial Data Output Enabler.
 * 	@param		.
 * 	@return		.
 */
#define EnableSERDataOutputPin() { \
	SetIOREGBitVar(IO_SMR1, SOE, SER_PIN_OUTPUT); \
}

/**
 *	@def 		DisableSERDataOutputPin
 *	@brief 		Serial Data Output Disabler.
 * 	@param		.
 * 	@return		.
 */
#define DisableSERDataOutputPin() { \
	SetIOREGBitVar(IO_SMR1, SOE, SER_PIN_GPIO); \
}

/**
 *	@def 		EnableSERClockPin
 *	@brief 		Serial Clock Pin Enabler.
 * 	@param		.
 * 	@return		.
 */
#define EnableSERClockPin() { \
	SetIOREGBitVar(IO_SMR1, SCKE, SER_PIN_OUTPUT); \
}

/**
 *	@def 		DisableSERClockPin
 *	@brief 		Serial Clock Pin Disabler.
 * 	@param		.
 * 	@return		.
 */
#define DisableSERClockPin() { \
	SetIOREGBitVar(IO_SMR1, SCKE, SER_PIN_GPIO); \
}

/**
 *	@def 		SetSERClockInputSource
 *	@brief 		Clock Input Source Setter.
 * 	@param[in]	VAL		Control bits for SMR (bits).
 * 	@return		.
 */
#define SetSERClockInputSource(VAL) { \
	SetIOREGBitVar(IO_SMR1, CS, VAL); \
}

/**
 *	@def 		SetSEROperationMode
 *	@brief 		Operation Mode Setter.
 * 	@param[in]	VAL		Control bits for SMR (bits).
 * 	@return		.
 */
#define SetSEROperationMode(VAL) { \
	SetIOREGBitVar(IO_SMR1, MD, VAL); \
}

/**
 *	@def 		EnableSERCommPrescaler
 *	@brief 		Communication Prescaler Division Ratio (DIV)
 *  			Bits Setter / Operation Enabler.
 * 	@param[in]	VAL		Control bits for CDRC (bits).
 * 	@return		.
 */
#define EnableSERCommPrescaler(VAL) { \
	SetIOREGBitVar(IO_CDCR1, DIV, VAL); \
	SetIOREGBitVar(IO_CDCR1, MD, SER_PRESCALE_ENABLED); \
}

/**
 *	@def 		StopSERCommPrescaler
 *	@brief 		Communication Prescaler Operation Disabler.
 * 	@param		.
 * 	@return		.
 */
#define StopSERCommPrescaler() { \
	SetIOREGBitVar(IO_CDCR1, MD, SER_PRESCALE_STOPPED); \
}

/**
 *	@def 		SetSERAsDataFrame
 *	@brief 		Data Frame Setter.
 * 	@param		.
 * 	@return		.
 */
#define SetSERAsDataFrame() { \
	SetIOREGBitVar(IO_SCR1, AD, SER_FRAME_DATA); \
}

/**
 *	@def 		SetSERAsAddressFrame
 *	@brief 		Address Frame Setter.
 * 	@param		.
 * 	@return		.
 */
#define SetSERAsAddressFrame() { \
	SetIOREGBitVar(IO_SCR1, AD, SER_FRAME_ADDRESS); \
}

/**
 *	@def 		SetSER7bitDataLength
 *	@brief 		7-bit Data Length Setter.
 * 	@param		.
 * 	@return		.
 */
#define SetSER7bitDataLength() { \
	SetIOREGBitVar(IO_SCR1, CL, SER_DL_7BITS); \
}

/**
 *	@def 		SetSER8bitDataLength
 *	@brief 		8-bit Data Length Setter.
 * 	@param		.
 * 	@return		.
 */
#define SetSER8bitDataLength() { \
	SetIOREGBitVar(IO_SCR1, CL, SER_DL_8BITS); \
}

/**
 *	@def 		SetSER1bitStopLength
 *	@brief 		1-bit Stop Setter.
 * 	@param		.
 * 	@return		.
 */
#define SetSER1bitStopLength() { \
	SetIOREGBitVar(IO_SCR1, SBL, SER_SL_1BIT); \
}

/**
 *	@def 		SetSER2bitStopLength
 *	@brief 		2-bit Stop Setter.
 * 	@param		.
 * 	@return		.
 */
#define SetSER2bitStopLength() { \
	SetIOREGBitVar(IO_SCR1, SBL, SER_SL_2BITS); \
}

/**
 *	@def 		SetSEROddParity
 *	@brief 		Odd Parity Setter.
 * 	@param		.
 * 	@return		.
 */
#define SetSEROddParity() { \
	SetIOREGBitVar(IO_SCR1, PEN, SER_PARITY_SET); \
	SetIOREGBitVar(IO_SCR1, P, SER_PARITY_ODD); \
}

/**
 *	@def 		SetSEREvenParity
 *	@brief 		Even Parity Setter.
 * 	@param		.
 * 	@return		.
 */
#define SetSEREvenParity() { \
	SetIOREGBitVar(IO_SCR1, PEN, SER_PARITY_SET); \
	SetIOREGBitVar(IO_SCR1, P, SER_PARITY_EVEN); \
}

/**
 *	@def 		SetSERNoParity
 *	@brief 		No Parity Setter.
 * 	@param		.
 * 	@return		.
 */
#define SetSERNoParity() { \
	SetIOREGBitVar(IO_SCR1, PEN, SER_PARITY_NONE); \
}

/**
 *	@def 		TransferSERLSBFirst
 *	@brief 		Transfer LSB First.
 * 	@param		.
 * 	@return		.
 */
#define TransferSERLSBFirst() { \
	SetIOREGBitVar(IO_SSR1, BDS, SER_LSB_FIRST); \
}

/**
 *	@def 		TransferSERMSBFirst
 *	@brief 		Transfer MSB First.
 * 	@param		.
 * 	@return		.
 */
#define TransferSERMSBFirst() { \
	SetIOREGBitVar(IO_SSR1, BDS, SER_MSB_FIRST); \
}

/**
 *	@def 		EnableSERTransmitInterrupt
 *	@brief 		Transmit Interrupt Enabler.
 * 	@param		.
 * 	@return		.
 */
#define EnableSERTransmitInterrupt() { \
	SetIOREGBitVar(IO_SSR1, TIE, SER_INT_ENABLED); \
}

/**
 *	@def 		DisableSERTransmitInterrupt
 *	@brief 		Transmit Interrupt Disabler.
 * 	@param		.
 * 	@return		.
 */
#define DisableSERTransmitInterrupt() { \
	SetIOREGBitVar(IO_SSR1, TIE, SER_INT_DISABLED); \
}

/**
 *	@def 		EnableSERReceiveInterrupt
 *	@brief 		Receive Interrupt Enabler.
 * 	@param		.
 * 	@return		.
 */
#define EnableSERReceiveInterrupt() { \
	SetIOREGBitVar(IO_SSR1, RIE, SER_INT_ENABLED); \
}

/**
 *	@def 		DisableSERReceiveInterrupt
 *	@brief 		Receive Interrupt Disabler.
 * 	@param		.
 * 	@return		.
 */
#define DisableSERReceiveInterrupt() { \
	SetIOREGBitVar(IO_SSR1, RIE, SER_INT_DISABLED); \
}

/**
 *	@def 		IsSERTransmitDataRegEmpty
 *	@brief 		Transmit Data Register Empty Checker.
 * 	@param		.
 * 	@return		.
 */
#define IsSERTransmitDataRegEmpty() \
  EQU(GetIOREGBitVar(IO_SSR1, TDRE), SER_TX_NODATA)

/**
 *	@def 		IsSERReceiveDataRegFull
 *	@brief 		Receive Data Register Full Checker.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsSERReceiveDataRegFull() \
  EQU(GetIOREGBitVar(IO_SSR1, RDRF), SER_RX_WITHDATA)

/**
 *	@def 		IsSERFramingError
 *	@brief 		Framing Error Checker.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsSERFramingError() \
  EQU(GetIOREGBitVar(IO_SSR1, FRE), SER_ERR_FRAME)

/**
 *	@def 		IsSEROverrunError
 *	@brief 		Overrun Error Checker.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsSEROverrunError() \
  EQU(GetIOREGBitVar(IO_SSR1, ORE), SER_ERR_OVERRUN)

/**
 *	@def 		IsSERParityError
 *	@brief 		Parity Error Checker.
 * 	@param		.
 * 	@return		boolean.
 */
#define IsSERParityError() \
  EQU(GetIOREGBitVar(IO_SSR1, PE), SER_ERR_PARITY)

/**
 *	@def 		ClearSERReceiveErrorFlag
 *	@brief 		Clear Receive Error Flag.
 * 	@param		.
 * 	@return		.
 */
#define ClearSERReceiveErrorFlag() { \
	SetIOREGBitVar(IO_SCR1, REC, SER_ERR_CLEAR); \
}

#endif /* SER_IO_H. */
