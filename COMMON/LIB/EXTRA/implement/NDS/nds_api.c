/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Node Data Sharing Shared API Functions Implementation				   	 */
/**
 *	@file		NDS/nds_api.c
 *	@brief		This file contains NDS API function implementation.
 *	@details	The shared data allocation can be configured to setup RX or TX
 *				data buffer to be accessed in any type of any size of any random
 *				address through user defined pointers in order to retrieve or
 *				modify contents for node data sharing.
 *	@note		The code is for demonstration purpose only. It only contains
 *				bare minimum implementation required by NDS and must contain
 *				user implementation if necessary.
 *	@warning	Do not confuse the compiler by implementing two or more similar
 *				NDS-related API functions. Remove or exclude other similar
 *				source codes from build except for the current or correct source.
**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <NDS/nds.h>

/* ----------------------------------------------------------------------------
**	API Functions.
*/

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
T_void NDSSharedData(T_void)
{
	/* TODO: add data sharing memory allocation here through allocNDS() */
}

/* END OF NDS_API. */
