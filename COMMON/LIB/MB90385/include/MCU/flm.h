/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Flash Memory Control and Status							   		         */
/**
 *	@file		MCU/flm.h
 * 	@brief		This file contains FLM types and API functions.
 * 	@note		Flash memory erase functions such as chip erase and sector
 * 				erases (with or without suspension/resumption support) is
 * 				not supported and implemented in this file.
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

#ifndef FLM_H
#define FLM_H

#include <IO/flm_io.h>
#include <MCU/isr.h>

/* ----------------------------------------------------------------------------
**	FLM Types.
*/

/**
 * 	@brief		Defined enumerated type for FLM write status.
 */
typedef enum {
	FLM_PROG_WAIT,				/**< wait for write cycle completion or error */
	FLM_PROG_SUCCESS,			/**< write cycle finished succesfully */
	FLM_PROG_TIMEOUT,			/**< timeout error / timing limit over */
	FLM_PROG_COMPLETE			/**< write buffer finished successfully */
} T_flmState;

/* ----------------------------------------------------------------------------
**	FLM API Functions.
*/

/**
 * 	@fn 		T_void readFLM(volatile T_word*, volatile T_word*, T_word)
 *	@brief		Reads content from flash memory and saves to word-sized buffer
 *				with specific starting address and specified buffer length.
 *  @param[in]	pSrcAddr	Flash memory source or starting read address (FAR).
 *  @param[in]	pDestBuffer	Word-sized buffer destination starting address (FAR).
 *  @param[in]	wLength		Number of word-sized data to read.
 *  @return		.
 */
extern T_void FAR readFLM(volatile FAR T_word* pSrcAddr,
	volatile FAR T_word* pDestBuffer, T_word wLength);

/**
 * 	@fn 		T_flmState writeFLM(volatile T_word*, volatile T_word*, T_word)
 *	@brief		Writes content from word-sized buffer to flash memory with
 *				specific starting address and specified buffer length.
 *  @param[in]	pDestAddr	Flash memory destination or starting write address (FAR).
 *  @param[in]	pSrcBuffer	Word-sized buffer source starting address (FAR).
 *  @param[in]	wLength		Number of word-sized data to write.
 *  @return		write status.
 *  @note		Only even addresses can be specified esp. to pDestAddr.
 */
extern T_flmState FAR writeFLM(volatile FAR T_word* pDestAddr,
	volatile FAR T_word* pSrcBuffer, T_word wLength);

#endif /* FLM_H. */
