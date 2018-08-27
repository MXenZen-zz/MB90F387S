/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Controller Area Network									   		   	     */
/**
 *	@file		COM/can.h
 *	@brief		This file contains CAN flags, external constants, getters and
 *				setters, and API functions.
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

#ifndef CAN_H
#define CAN_H

#include <IO/can_io.h>
#include <MCU/isr.h>

/* ----------------------------------------------------------------------------
**	CAN Flags.
*/

/**
 *	@def 		CAN_DEF_BUS_SPEED
 *	@brief 		CAN default bit timing speed at 16 MHz.
 */
#define CAN_DEF_BUS_SPEED		CAN_BTR_1M

/**
 *	@def 		CAN_DEF_BUFFER_BITS
 *	@brief 		CAN default buffer bits for both transmission and reception.
 */
#define CAN_DEF_BUFFER_BITS		(0xFFU)

/* ----------------------------------------------------------------------------
**	CAN External Constants.
*/

/**
 * 	@var		PRIO_CAN_ISR
 *	@brief		ISR interrupt level/priority of CAN.
 */
extern const T_icrINTLevel PRIO_CAN_ISR;

/**
 * 	@var		pRXCANBuffer
 *	@brief		Read-only access to CAN reception buffer (DTR copy).
 */
extern volatile T_canid_dtr const * const pRXCANBuffer;

/**
 * 	@var		pTXCANBuffer
 *	@brief		Write-permitted access to CAN transmission buffer (DTR copy).
 */
extern volatile T_canid_dtr * const pTXCANBuffer;

/* ----------------------------------------------------------------------------
**	CAN Getters and Setters.
*/

/**
 *	@def 		ReadCANRXByte
 *	@brief 		Reception buffer byte data getter.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@param[in]	IDX 	Byte index (bits).
 * 	@return		byte data.
 */
#define ReadCANRXByte(MBX, IDX) \
	(pRXCANBuffer[MBX].BYTE[IDX])

/**
 *	@def 		ReadCANRXWord
 *	@brief 		Reception buffer word data getter.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@param[in]	IDX 	Word index (bits).
 * 	@return		word data.
 */
#define ReadCANRXWord(MBX, IDX) \
	(pRXCANBuffer[MBX].WORD[IDX])

/**
 *	@def 		ReadCANRXDWord
 *	@brief 		Reception buffer dword data getter.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@param[in]	IDX 	DWord index (bits).
 * 	@return		dword data.
 */
#define ReadCANRXDWord(MBX, IDX) \
	(pRXCANBuffer[MBX].DWORD[IDX])

/**
 *	@def 		ReadCANRXFloat32
 *	@brief 		Reception buffer single precision float data getter.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@param[in]	IDX 	Float32 index (bits).
 * 	@return		float32 data.
 */
#define ReadCANRXFloat32(MBX, IDX) \
	(pRXCANBuffer[MBX].FLOAT[IDX])

/**
 *	@def 		ReadCANRXFloat64
 *	@brief 		Reception buffer double precision float data getter.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@return		float64 data.
 */
#define ReadCANRXFloat64(MBX) \
	(pRXCANBuffer[MBX].DOUBLE)

/**
 *	@def 		ReadCANRXType
 *	@brief 		Reception buffer multiple data type data getter.
 * 	@param[in]	SDX 	Single linear index (bits).
 * 	@param		CAST 	Data type.
 * 	@return		type-based data.
 */
#define ReadCANRXType(SDX, CAST) \
	(*((CAST*)(pRXCANBuffer[PosX_BASE].BYTE + (SDX))))

/**
 *	@def 		WriteCANTXByte
 *	@brief 		Transmission buffer byte data setter.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@param[in]	IDX 	Byte index (bits).
 * 	@param[in]	VAL		Byte data (byte).
 * 	@return		.
 */
#define WriteCANTXByte(MBX, IDX, VAL) { \
	pTXCANBuffer[MBX].BYTE[IDX] = (T_byte)(VAL); \
}

/**
 *	@def 		WriteCANTXWord
 *	@brief 		Transmission buffer word data setter.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@param[in]	IDX 	Word index (bits).
 * 	@param[in]	VAL		Word data (word).
 * 	@return		.
 */
#define WriteCANTXWord(MBX, IDX, VAL) { \
	pTXCANBuffer[MBX].WORD[IDX] = (T_word)(VAL); \
}

/**
 *	@def 		WriteCANTXDWord
 *	@brief 		Transmission buffer dword data setter.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@param[in]	IDX 	DWord index (bits).
 * 	@param[in]	VAL		DWord data (dword).
 * 	@return		.
 */
#define WriteCANTXDWord(MBX, IDX, VAL) { \
	pTXCANBuffer[MBX].DWORD[IDX] = (T_dword)(VAL); \
}

/**
 *	@def 		WriteCANTXFloat32
 *	@brief 		Transmission buffer single precision float data setter.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@param[in]	IDX 	Float index (bits).
 * 	@param[in]	VAL		Float32 data (float32).
 * 	@return		.
 */
#define WriteCANTXFloat32(MBX, IDX, VAL) { \
	pTXCANBuffer[MBX].FLOAT[IDX] = (T_float32)(VAL); \
}

/**
 *	@def 		WriteCANTXFloat64
 *	@brief 		Transmission buffer double precision float data setter.
 * 	@param[in]	MBX 	Message buffer index (bits).
 * 	@param[in]	VAL		Float64 data (float64).
 * 	@return		.
 */
#define WriteCANTXFloat64(MBX, VAL) { \
	pTXCANBuffer[MBX].DOUBLE = (T_float64)(VAL); \
}

/**
 *	@def 		WriteCANTXType
 *	@brief 		Transmission buffer multiple data type data setter.
 * 	@param[in]	SDX 	Single linear index (bits).
 * 	@param		CAST 	Data type.
 * 	@param[in]	VAL		Data (type-based).
 * 	@return		.
 */
#define WriteCANTXType(SDX, CAST, VAL) { \
	*((CAST*)(pTXCANBuffer[PosX_BASE].BYTE + (SDX))) = (CAST)(VAL); \
}

/* ----------------------------------------------------------------------------
**	CAN API Functions.
*/

/**
 * 	@fn 		T_void initCAN(T_canBitTimingSpeed, T_byte, T_byte)
 *	@brief 		Performs default initialization of CAN peripheral.
 * 	@param[in]	speed			Bit timing speed at 16 MHz.
 * 	@param[in]	rxBufferBits 	Reception message buffer bits.
 * 	@param[in]	txBufferBits 	Transmission message buffer bits.
 * 	@return		.
 * 	@note		CAN is initialized with standard data frame format with
 * 				full-bit comparison on acceptance masks; node transition,
 * 				reception, and transmission interrupts are enabled; data
 * 				length code of 8 bytes; and all eight message buffers are
 * 				used in the process.
 *  @note		If there's no need to specify the formatted ID, acceptance
 *  			mask or data length, then there's no need to execute
 *  			setupCANAcceptMask and setupCANMessageBuffer. This
 *  			function already provides default settings.
 */
extern T_void initCAN(T_canBitTimingSpeed speed, T_byte rxBufferBits, T_byte txBufferBits);

/**
 * 	@fn 		T_void setupCANAcceptanceMask(T_canAccMaskOp, T_byte, T_word)
 *	@brief 		Set up CAN's acceptance mask registers AMR0 or AMR1.
 * 	@pre		initCAN must be called first (or called already).
 * 	@param[in]	maskNumber	Acceptance mask register number.
 * 	@param[in]	maskPrefix	Standard ID priority "prefix" mask.
 * 	@param[in]	maskSuffix	Extended ID priority "suffix" mask.
 * 	@return		.
 * 	@note		The default acceptance mask settings is full-bit comparison.
 *  @note		If the AMSx.1 and AMSx.0 bits are set to "10B" or "11B", always
 *  			set the acceptance mask register (AMR0 or AMR1) to be used, too.
 *  @see		Refer to formattedCANID for prefix and suffix parameter details.
 */
extern T_void setupCANAcceptanceMask(T_canAccMaskOp maskNumber,
	T_byte maskPrefix, T_word maskSuffix);

/**
 * 	@fn 		T_void setupCANMessageBuffer(T_canMsgBuf, T_canIDFormat, T_byte,
 * 					T_word, T_canAccMaskOp, T_canDataLength, T_canTXINT,
 * 					T_canRXINT, T_canTXRemoteFrameWait, T_canTXFrame)
 *	@brief 		Set up CAN's ID, acceptance mask option, data length,
 *				RX and TX interrupt, and some remote frame options.
 * 	@pre		initCAN must be called first (or called already).
 * 	@param[in]	msgBuf		Mailbox or message buffer.
 * 	@param[in]	idFormat	ID format.
 * 	@param[in]	idPrefix	Standard ID priority "prefix".
 * 	@param[in]	idSuffix	Extended ID priority "suffix".
 * 	@param[in]	maskOption	Acceptance mask option comparison.
 * 	@param[in]	dataLength	Number of bytes in a data buffer.
 * 	@param[in]	txINTEnable	Transmission complete interrupt enable.
 * 	@param[in]	rxINTEnable	Reception complete interrupt enable.
 * 	@param[in]	remoteWait	Transmission wait for remote frame reception.
 * 	@param[in]	frame		Frame type.
 * 	@return		.
 * 	@note		The default message buffer setting is 8-byte standard data
 * 				frame format with full-bit acceptance mask comparison. Reception
 * 				and transmission completion interrupts are enabled.
 */
extern T_void setupCANMessageBuffer(T_canMsgBuf msgBuf, T_canIDFormat idFormat,
	T_byte idPrefix, T_word idSuffix, T_canAccMaskOp maskOption,
	T_canDataLength dataLength, T_canTXINT txINTEnable, T_canRXINT rxINTEnable,
	T_canTXRemoteFrameWait remoteWait, T_canTXFrame frame);

/**
 * 	@fn 		T_void startCAN(T_void)
 *	@brief 		Cancels halt or start bus operation.
 * 	@param		.
 * 	@return		.
 */
extern T_void startCAN(T_void);

/**
 * 	@fn 		T_void stopCAN(T_void)
 *	@brief 		Halt bus operation.
 * 	@param		.
 * 	@return		.
 */
extern T_void stopCAN(T_void);

/**
 * 	@fn 		T_void requestCANTransmit(T_void)
 *	@brief 		Loads TX buffer to DTR then performs transmission request
 *				of specified message buffers.
 * 	@param		.
 * 	@return		.
 */
extern T_void requestCANTransmit(T_void);

/**
 * 	@fn 		T_uint8 checkCANReceived(T_void)
 *	@brief 		Checks for recent data received then stores DTR to RX buffer
 *				of specified message buffers.
 * 	@param		.
 * 	@return		received message buffer count.
 */
extern T_uint8 checkCANReceived(T_void);

/**
 * 	@fn 		T_dword formattedCANID(T_canMsgBuf, T_byte, T_word)
 *	@brief 		Creates a customized formatted ID.
 * 	@param[in]	msgBuf		Mailbox or message buffer.
 * 	@param[in]	idPrefix	Standard ID priority "prefix".
 * 	@param[in]	idSuffix	Extended ID priority "suffix".
 * 	@return		formatted ID.
 *  @note		In order to generate a unique ID for every message buffers
 *  			across nodes, the message buffer number or index (BUFFER),
 *  			the standard ID priority (PREFIX) and the extended ID
 *  			priority (SUFFIX) shall provide formatted ID or mask for
 *  			both standard ID format (bits 28 to 18) and extended ID
 *  			format (bits 28 to 0). The BUFFER in bits 20 to 18 (3 bits)
 *  			ensures location or index of the message buffer securely
 *  			present in the formatted ID regardless of the ID format.
 *  			However, BUFFER alone does not provide uniqueness of message
 *  			buffers. Hence, PREFIX (standard and extended ID) and SUFFIX
 *  			(extended ID only) shall provide unique addressing, priority,
 *  			and filtering of message to transmit or receive. The PREFIX
 *  			in bits 28 to 21 (8 bits) provides the highest priority while
 *  			SUFFIX in bits 15 to 0 (16 bits) provides extended priority
 *  			(for nodes greater than 255). On the other hand, acceptance
 *  			mask filters must follow this ID format for compatibility. <br>
 *				| 31 - 29 | 28 - 21 | 20 - 18 |    17 - 16    | 15 - 0 |
 *				| :-----: | :-----: | :-----: | :-----------: | :----: |
 *				|    X    |	PREFIX	| BUFFER  | reserved (3H) | SUFFIX |
 */
extern T_dword formattedCANID(T_canMsgBuf msgBuf, T_byte idPrefix, T_word idSuffix);

/**
 * 	@fn 		T_dword toIDRegMap(T_dword)
 *	@brief 		Converts bit-ordered ID to register-mapped ID.
 * 	@param[in]	ID 		Bit-ordered ID.
 * 	@return		register-mapped ID.
 *  @note		The conversion produces a bit order which can then be mapped to
 *  			the register using assignment operator. <br>
 *				|BYTE| 7    | 6    | 5    | 4    | 3    | 2    | 1    | 0    |
 *				|:--:| :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
 *				| 3  | 4    | 3    | 2    | 1    | 0    |      |      |      |
 *				| 2  | 12   | 11   | 10   | 9    | 8    | 7    | 6    | 5    |
 *				| 1  | 20   | 19   | 18   | 17   | 16   | 15   | 14   | 13   |
 *				| 0  | 28   | 27   | 26   | 25   | 24   | 23   | 22   | 21   |
 */
extern T_dword toIDRegMap(T_dword ID);

/**
 * 	@fn 		T_dword toIDBitOrder(T_dword)
 *	@brief 		Converts register-mapped ID to bit-ordered ID.
 * 	@param[in]	ID 		Register-mapped ID.
 * 	@return		bit-ordered ID.
 *	@note		The conversion produces a bit order from the IDR, following the
 *				conventional MSB to LSB order. <br>
 *				|BYTE| 7    | 6    | 5    | 4    | 3    | 2    | 1    | 0    |
 *				|:--:| :--: | :--: | :--: | :--: | :--: | :--: | :--: | :--: |
 *				| 3  |      |      |      | 28   | 27   | 26   | 25   | 24   |
 *				| 2  | 23   | 22   | 21   | 20   | 19   | 18   | 17   | 16   |
 *				| 1  | 15   | 14   | 13   | 12   | 11   | 10   | 9    | 8    |
 *				| 0  | 7    | 6    | 5    | 4    | 3    | 2    | 1    | 0    |
 */
extern T_dword toIDBitOrder(T_dword ID);

/**
 * 	@fn 		T_void CANRX_IRQHandler(T_void)
 *	@brief 		Checks for last event interrupt - reception, appends
 *  			reception bits, then clears all reception completion
 *  			bits and reception overrun bits (if there's any).
 *  @param		.
 *  @return		.
 */
#if USE_CAN_ISR
#if NOSAVEREG_CAN_ISR
NOSAVEREG
#endif
extern ISR(CANRX_IRQHandler);
#endif

/**
 * 	@fn 		T_void CANTX_IRQHandler(T_void)
 *	@brief 		Checks for last event interrupts - transmission and node status
 *  			transition, then clears all transmit completion bits and node
 *  			status transition bits (if there's any).
 *  @param		.
 *  @return		.
 *	@note 		CAN will (re)start if bus off node status yields bus halt.
 *				Other node status might not be a concern, but necessary
 *				operations can be inserted under the case.
 *  @note		Node status transition flag bit is set to "1" when node
 *				status transits, that is:
 *  				1. Error active  (0) --> Warning  		(1)
 *  				2. Warning 		 (1) --> Error Passive	(2)
 *  				3. Error Passive (2) --> Bus off 		(3)
 *  				4. Bus off 		 (3) --> Error active 	(0)
 */
#if USE_CAN_ISR
#if NOSAVEREG_CAN_ISR
NOSAVEREG
#endif
extern ISR(CANTX_IRQHandler);
#endif

#endif /* CAN_H. */
