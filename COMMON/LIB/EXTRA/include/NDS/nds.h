/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Node Data Sharing													     */
/**
 *	@file		NDS/nds.h
 *	@brief		This file contains NDS types and API functions.
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

#ifndef NDS_H
#define NDS_H

#include <LIB/bitmanip.h>

/* ----------------------------------------------------------------------------
**	API Functions.
*/

/**
 *	@fn			T_void initNDS(T_void)
 *	@brief 		Initialize node data sharing.
 *	@details	Sets variables to their initial values and invokes
 *				shared data allocation.
 *	@post		CAN must be initialized and running after NDS initialization!
 *	@param		.
 *	@return		.
 */
extern T_void initNDS(T_void);

/**
 *	@fn			T_void manageNDSIncoming(T_uint8)
 *	@brief 		Manage reception of shared data.
 *	@details	Performs CAN message reception in order to keep data across
 *				nodes updated or sychronized.
 *	@param[in]	rxWaitCount		Reception wait count (0 for no waiting).
 *	@return		.
 */
extern T_void manageNDSIncoming(T_uint8 rxWaitCount);

/**
 *	@fn			T_void manageNDSOutgoing(T_uint8)
 *	@brief 		Manage transmission of shared data.
 *	@details	Performs CAN message transmission in order to keep data across
 *				nodes updated or sychronized.
 *	@param[in]	txWaitCount		Transmission wait count (0 for no waiting).
 *	@return		.
 */
extern T_void manageNDSOutgoing(T_uint8 txWaitCount);

/**
 *	@fn			T_void* NDSAllocIncoming(T_uint8)
 *	@brief 		Allocates data space of any type of limited size to CAN
 *				reception data buffer.
 *	@details	Returns the starting address of allocation from the RX data
 *				buffer. The address increments based on the allocated size up
 *				to 64 bytes or the last byte that can be dedicated. The assigned
 *				address, together with the size specified, is the allocated data
 *				space reserved for use by the pointer receiving the address.
 *	@pre		Initialize NDS first!
 *	@param[in]	size		Allocation size in bytes.
 *	@return		memory location.
 *	@note		Allocation performed is not the same as performed by dynamic
 *				allocation since the data buffer is a static variable which
 *				can't be released, relocated or reallocated at runtime. The
 *				data buffer, however, act as free memory area which can be
 *				accessed through pointers which in turn can modify the contents
 *				of the memory location.
 */
extern T_void* NDSAllocIncoming(T_uint8 size);

/**
 *	@fn			T_void* NDSAllocOutgoing(T_uint8)
 *	@brief 		Allocates data space of any type of limited size to CAN
 *				transmission data buffer.
 *	@details	Returns the starting address of allocation from the TX data
 *				buffer. The address increments based on the allocated size up
 *				to 64 bytes or the last byte that can be dedicated. The assigned
 *				address, together with the size specified, is the allocated data
 *				space reserved for use by the pointer receiving the address.
 *	@pre		Initialize NDS first!
 *	@param[in]	size		Allocation size in bytes.
 *	@return		memory location.
 *	@note		Allocation performed is not the same as performed by dynamic
 *				allocation since the data buffer is a static variable which
 *				can't be released, relocated or reallocated at runtime. The
 *				data buffer, however, act as free memory area which can be
 *				accessed through pointers which in turn can modify the contents
 *				of the memory location.
 */
extern T_void* NDSAllocOutgoing(T_uint8 size);

/**
 *	@fn			T_void NDSSharedData(T_void)
 *	@brief 		NDS API function of allocating shared data.
 *	@attention	Shared data allocation is only intended to work on CAN if it can
 *				utilize all eight message buffers. Each message buffer must be
 *				able to access all eight bytes of data. Otherwise, CAN might not
 *				be able to transmit or receive data properly to the extent that
 *				system will malfunction.
 *	@param		.
 *	@return		.
 *	@warning	Do not mix incoming and outgoing messages together since
 *				transmission and reception is performed by eight bytes of
 *				data per message buffer. Thus, group all outgoing and incoming
 *				data into a single data structure inasmuch as possible so that
 *				allocation can be made safe and simple.
 *	@note		The overall grouped incoming or outgoing data size must be a
 *				multiple of 8 and must not exceed the maximum size of the data
 *				buffer (64 bytes). Always fit the total size of the grouped data
 *				by either adding dummy bytes or reducing the size of the grouped
 *				data. If the grouped data size is already a multiple of 8,
 *				divide the size by 8 to get the total consecutive message buffer
 *				count. This will help indicate the remaining message buffers that
 *				can still be used for the opposite direction if there's any.
 *	@note		All incoming or outgoing data of a certain node must correspond
 *				similarly with the other node(s) but in opposite direction (i.e
 *				32 bytes or 4 message buffers of outgoing data in node A while
 *				32 bytes or 4 message buffers of incoming data in node B).
 *				Another way is to use acceptance mask to receive data to
 *				specific message buffer and other reception options. If multiple
 *				nodes are involved, consider adding header data, checksum or
 *				intended recepient of the data together with the payload before
 *				transmitting. When receiving, confirm that the entire data is
 *				received correctly since message buffers ight be transmitted
 *				one-by-one but the entire data covers many message buffers that
 *				might take longer time to receive.
 */
extern T_void NDSSharedData(T_void);

#endif /* NDS_H. */
