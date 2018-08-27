/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Input / Output Ports									           		     */
/**
 *	@file		GPIO/port.h
 *	@brief		This file contains PORT types and API functions.
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

#ifndef PORT_H
#define PORT_H

#include <IO/port_io.h>

/* ----------------------------------------------------------------------------
**	PORT Types.
*/

/**
 * 	@brief		Defined enumerated type for PORT numbers.
 */
typedef enum {
	PORT1 = 1U,					/**< port 1 */
	PORT2 = 2U,					/**< port 2 */
	PORT3 = 3U,					/**< port 3 */
	PORT4 = 4U,					/**< port 4 */
	PORT5 = 5U					/**< port 5 */
} T_portNumber;

/**
 * 	@brief		Defined enumerated type for PORT bit masks.
 */
typedef enum {
	PIN_MASK_BIT0   = 0x01U,	/**< mask for port's bit 0 */
	PIN_MASK_BIT1   = 0x02U,	/**< mask for port's bit 1 */
	PIN_MASK_BIT2   = 0x04U,	/**< mask for port's bit 2 */
	PIN_MASK_BIT3   = 0x08U,	/**< mask for port's bit 3 */
	PORT_MASK_LBYTE = 0x0FU,	/**< mask for port's bits 3 to 0 */
	PIN_MASK_BIT4   = 0x10U,	/**< mask for port's bit 4 */
	PIN_MASK_BIT5   = 0x20U,	/**< mask for port's bit 5 */
	PIN_MASK_BIT6   = 0x40U,	/**< mask for port's bit 6 */
	PIN_MASK_BIT7   = 0x80U,	/**< mask for port's bit 7 */
	PORT_MASK_HBYTE = 0xF0U,	/**< mask for port's bits 7 to 4 */
	PORT_MASK_BYTE  = 0xFFU		/**< mask for all port's bits (pins 7 to 0) */
} T_portMask;

/* ----------------------------------------------------------------------------
**	PORT API Functions.
*/

/**
 * 	@fn 		T_void initPort(T_void)
 *	@brief 		Initialize ports to their defaults.
 * 	@param		.
 * 	@return		.
 */
extern T_void initPort(T_void);

/**
 * 	@fn 		T_void portMode(T_portNumber, T_portDirection, T_portMask)
 *	@brief 		Set port's data direction.
 * 	@param[in]	port	Port number.
 * 	@param[in]	mode	Port mode.
 * 	@param[in]	mask	Pins of the port (masked).
 * 	@return		.
 */
extern T_void portMode(T_portNumber port, T_portDirection mode, T_portMask mask);

/**
 * 	@fn 		T_void writePort(T_portNumber, T_portLevel, T_portMask)
 *	@brief 		Write states (logic levels) to a port.
 * 	@param[in]	port	Port number.
 * 	@param[in]	level	Port states or logic levels.
 * 	@param[in]	mask	Pins of the port (masked).
 * 	@return		.
 */
extern T_void writePort(T_portNumber port, T_portLevel level, T_portMask mask);

/**
 * 	@fn 		T_portLevel readPort(T_portNumber, T_portMask)
 *	@brief 		Read states (logic levels) from a port.
 * 	@param[in]	port	Port number.
 * 	@param[in]	mask	Pins of the port (masked).
 * 	@return		port state or logic levels.
 */
extern T_portLevel readPort(T_portNumber port, T_portMask mask);

#endif /* PORT_H. */
