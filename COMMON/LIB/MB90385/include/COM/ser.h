/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Universal Asynchronous Receiver/Transmitter							     */
/**
 *	@file		COM/ser.h
 *	@brief		This file contains SER types, external constants and
 *				API functions.
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

#ifndef SER_H
#define SER_H

#include <IO/ser_io.h>
#include <GPIO/pin.h>
#include <MCU/isr.h>

/* ----------------------------------------------------------------------------
**	SER Types.
*/

/**
 * 	@brief		Defined enumerated type for SER number sign.
 */
typedef enum {
	SER_NEGATIVE,				/**< negative number */
	SER_POSITIVE				/**< positive number */
} T_serNumSign;

/**
 * 	@brief		Defined enumerated type for SER numerical base format.
 */
typedef enum {
	SER_BIN =  2U,				/**< binary print format */
	SER_OCT =  8U,				/**< octal print format */
	SER_DEC = 10U,				/**< decimal print format */
	SER_HEX = 16U				/**< hexadecimal print format */
} T_serBaseFormat;

/**
 * 	@brief		Defined enumerated type for SER KernelUART user.
 */
typedef enum {
	SER_ACC,					/**< KernelUART used by Accemic MDE */
	SER_APP						/**< KernelUART used by application */
} T_serKernelUser;

/* ----------------------------------------------------------------------------
**	SER External Constants.
*/

/**
 * 	@var		PRIO_SER_ISR
 *	@brief		ISR interrupt level/priority of SER.
 *	@warning	The interrupt level of SER must not be 7 (or none).
 */
extern const T_icrINTLevel PRIO_SER_ISR;

/* ----------------------------------------------------------------------------
**	SER API Functions.
*/

/**
 * 	@fn 		T_void initSER(T_void)
 *	@brief 		Initialize SER.
 * 	@param		.
 * 	@return		.
 * 	@note		It is not necessary to change UART registers since the
 * 				bootloader already provides the settings needed, primarily
 * 				for debugging through the Accemic MDE. Set UART settings
 * 				compatible with bootloader settings inasmuch as SER is
 * 				dependent on the bootloader settings, is set ahead of any
 * 				application program, and is used by the Accemic MDE debugger.
 */
extern T_void initSER(T_void);

/**
 * 	@fn 		T_void setupSERTiming(T_serMode, T_serBaud, T_serPrescaler,
 * 					T_serPrescaleControl, T_serPin, T_pinDirection)
 *	@brief 		Initialize SER mode, timings, and serial clock I/O pin which
 *				will be held default or common to all SER operations.
 * 	@pre		initSER must be called first (or called already).
 * 	@post		SER usage must be set to work on user instead of Accemic MDE.
 * 	@param[in]	mode		Operation mode.
 * 	@param[in]	baud		Clock input source or baud rate.
 * 	@param[in]	prescale	Communication prescaler division ratio.
 * 	@param[in]	compCtrl	Communication prescaler control.
 * 	@param[in]	clkPin		Serial clock pin enable.
 * 	@param[in]	clkDir		Serial clock I/O direction.
 * 	@return		.
 *  @note		The default operation mode is asynchronous normal mode.
 *  			The default baud rate is 9615, but 38461 is preferable.
 *  			Communication prescaler is enabled and division ratio is 1.
 */
extern T_void setupSERTiming(T_serMode mode, T_serBaud baud, T_serPrescaler prescale,
	T_serPrescaleControl compCtrl, T_serPin clkPin, T_pinDirection clkDir);

/**
 * 	@fn 		T_void setupSERExtended(T_serRXTXEnable, T_serRXTXEnable,
 * 					T_serParityEnable, T_serParity, T_serStopLength,
 * 						T_serDataLength, T_serFrameType, T_serDirection)
 *	@brief 		Set up SER's RX and TX, parity, stop and data length,
 *				frame type, and first transfer significant bit.
 * 	@pre		setupSERTiming must be called first (or called already).
 * 				Also, initSER must be called ahead of setupSERTiming.
 * 	@post		SER usage must be set to work on user instead of Accemic MDE.
 * 	@param[in]	rxEnable	Enable reception (RX), RX interrupt, and RX pin.
 * 	@param[in]	txEnable	Enable transmission (TX), TX interrupt, and TX pin.
 * 	@param[in]	parEnable	Parity enable.
 * 	@param[in]	parity		Parity type.
 * 	@param[in]	sLength		Stop-bit length.
 * 	@param[in]	dLength		Data length.
 * 	@param[in]	frame		Address / data frame.
 * 	@param[in]	transfer	Transfer direction.
 * 	@return		.
 *  @note		The default extended setting is no parity, 1-bit stop length,
 *  			8-bit data frame length, and transfer lsb first.
 */
extern T_void setupSERExtended(T_serRXTXEnable rxEnable, T_serRXTXEnable txEnable,
	T_serParityEnable parEnable, T_serParity parity, T_serStopLength sLength,
	T_serDataLength dLength, T_serFrameType frame, T_serDirection transfer);

/**
 * 	@fn 		T_void setSERUsage(T_serKernelUser)
 *	@brief 		Sets usage of KernelUART either by the application (APP) for
 *				customized operations or by the Accemic MDE (ACC) for debugging.
 * 	@pre		initSER, setupSERTiming and/or setupSERExtended (if necessary)
 * 				must be called first (or called already).
 * 	@param[in]	user	KernelUART usage.
 * 	@return		.
 */
extern T_void setSERUsage(T_serKernelUser user);

/**
 * 	@fn 		T_bit requestSERTransmit(T_uint8)
 *	@brief 		Reloads data to transmit buffer then performs transmission
 *				request by enabling SER TX interrupt.
 * 	@param		data	Data to transmit.
 * 	@return		transmission status.
 */
extern T_bit requestSERTransmit(T_uint8 data);

/**
 * 	@fn 		T_uint8 writeSERBytes(const T_uint8*, T_uint8)
 *	@brief 		Write bytes to transmission buffer.
 * 	@param[in]	pBuff	Pointer to array to retrieve data.
 * 	@param[in]	len		Desired bytes to write or size of array.
 * 	@return     number of bytes placed in the array.
 *  @note		This might become a blocking function if the transmission
 *  			buffer gets full. It shall wait for free queue space to
 *  			enqueue remaining data to transmit.
 *	@warning	Do not call this function consecutively without a delay of
 *				at least 1 millisecond in between function calls.
 */
extern T_uint8 writeSERBytes(const T_uint8* pBuff, T_uint8 len);

/**
 * 	@fn 		T_uint8 countSERReceived(T_void)
 *	@brief 		Counts newly received data stored in reception buffer.
 * 	@param		.
 * 	@return		bytes received.
 */
extern T_uint8 countSERReceived(T_void);

/**
 * 	@fn 		T_bit checkSERReceived(T_uint8*)
 *	@brief 		Checks for newly received data as SER RX interrupt
 *  			handler was recently called for receiving new data.
 * 	@param[out]	pData 	Pointer to variable to store received data.
 * 	@return		reception status.
 */
extern T_bit checkSERReceived(T_uint8* pData);

/**
 * 	@fn 		T_uint8 readSERBytes(T_uint8*, T_uint8, T_uint8, T_bit)
 *	@brief 		Read bytes from reception buffer and terminates if the desired
 *  			length have been read or if the terminator character is detected.
 * 	@param[out]	pBuff		Pointer to array to store data.
 * 	@param[in]	len			Desired bytes to read or size of array.
 * 	@param[in]	term		Terminating character for checkTerm option.
 * 	@param[in]	checkTerm	Check terminating character option.
 * 	@return     number of bytes placed in the array.
 */
extern T_uint8 readSERBytes(T_uint8* pBuff, T_uint8 len, T_uint8 term, T_bit checkTerm);

/**
 * 	@fn 		size_t cPrint(const T_char)
 *	@brief 		Prints a single character through the serial driver.
 * 	@param[in]	ch		Character.
 * 	@return		number of printed characters (1).
 */
extern size_t cPrint(const T_char ch);

/**
 * 	@fn 		size_t sPrint(const T_char*)
 *	@brief 		Prints a string (character-array) through the serial driver.
 * 	@param[in]	str		Character-array.
 * 	@return		number of printed characters.
 */
extern size_t sPrint(const T_char* str);

/**
 * 	@fn 		size_t printLn(T_void)
 *	@brief 		Prints line feed and carriage return characters as the newline.
 * 	@param		.
 * 	@return		number of printed characters (2).
 */
extern size_t printLn(T_void);

/**
 * 	@fn 		size_t sPrintLn(const T_char*)
 *	@brief 		Prints a string with newline.
 * 	@param[in]	str		Character-array.
 * 	@return		number of printed characters plus newline.
 */
extern size_t sPrintLn(const T_char* str);

/**
 * 	@fn 		size_t nPrint(T_sint32, T_serBaseFormat, T_serNumSign)
 *	@brief 		Prints a number with different sizes, bases, and signs.
 * 	@param[in]	number	The number to print.
 * 	@param[in]	base	Print number base format.
 * 	@param[in]	sign	Sign of the number.
 * 	@return		number of printed characters.
 *  @note		Signed numbers can only be printed in decimal format.
 *  			Other base formats are unsigned by default.
 *  @note		Base greater than 16 is not guaranteed to print correct
 *  			representation of the number.
 *  @see		To print signed integers only, use iPrint instead.
 *  			To print unsigned integers only, use uPrint instead.
 */
extern size_t nPrint(T_sint32 number, T_serBaseFormat base, T_serNumSign sign);

/**
 * 	@fn 		size_t iPrint(T_sint32)
 *	@brief 		Prints a signed number.
 * 	@param[in]	number	The number to print.
 * 	@return		number of printed characters.
 *  @note		The number to be printed should only be a signed decimal.
 *  @see		To print in other different base format, use nPrint instead.
 */
extern size_t iPrint(T_sint32 number);

/**
 * 	@fn 		size_t uPrint(T_uint32)
 *	@brief 		Prints an unsigned number.
 * 	@param[in]	number	The number to print.
 * 	@return		number of printed characters.
 *  @note		The number to be printed should only be an unsigned number.
 *  @see		To print in hexadecimal format, use xPrint instead.
 */
extern size_t uPrint(T_uint32 number);

/**
 * 	@fn 		size_t xPrint(T_uint32, const T_char*, const T_char*)
 *	@brief 		Prints an unsigned number in hexadecimal format.
 * 	@param[in]	number	The number to print.
 * 	@param[in]	prefix	Prefix string.
 * 	@param[in]	suffix	Suffix string.
 * 	@return		number of printed characters.
 *	@note		The number to be printed should only be an unsigned number.
 *  @see		To print in decimal, use either uPrint or iPrint instead.
 */
extern size_t xPrint(T_uint32 number, const T_char* prefix, const T_char* suffix);

/**
 * 	@fn 		size_t dPrint(T_float32, T_uint8)
 *	@brief 		Prints a single precision floating-point number.
 * 	@param[in]	number	The number to print.
 * 	@param[in]	digits	Number of digits to print after decimal point.
 * 	@return		number of printed characters.
 *  @note		Decimal digits greater than 7 is not guaranteed to print
 *  			correct representation of the number. Thus, printing is
 *  			limited to 7 decimal digits at most.
 */
extern size_t dPrint(T_float32 number, T_uint8 digits);

/**
 * 	@fn 		T_void SERRX_IRQHandler(T_void)
 *	@brief 		Checks for parity, framing or overrun error and performs
 *  			reading of new and valid data received, clearing all
 *  			related reception completion or error bits in the process.
 *  @param		.
 *  @return		.
 *  @note 		Some entries might be dequeued or overwritten with recently
 *  			received data when buffer gets full.
 */
#if USE_SER_ISR
#if NOSAVEREG_SER_ISR
NOSAVEREG
#endif
extern ISR(SERRX_IRQHandler);
#endif

/**
 * 	@fn 		T_void SERTX_IRQHandler(T_void)
 *	@brief		Extracts all data from transmit buffer, writes to data
 *  			register to transmit, then disables transmit interrupt.
 *  @param		.
 *  @return		.
 *  @note 		Routine may take a longer time to empty the transmit buffer.
 */
#if USE_SER_ISR
#if NOSAVEREG_SER_ISR
NOSAVEREG
#endif
extern ISR(SERTX_IRQHandler);
#endif

#endif /* SER_H. */
