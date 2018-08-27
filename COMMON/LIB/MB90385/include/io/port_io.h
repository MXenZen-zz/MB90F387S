/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Input / Output Ports									           		     */
/**
 *	@file		IO/port_io.h
 *	@brief		This file contains types, and getters and setters
 * 				for PORT IO registers.
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

#ifndef PORT_IO_H
#define PORT_IO_H

#include <IO/io_mb90385.h>

/* ----------------------------------------------------------------------------
**	PORT IO Types.
*/

/**
 * 	@brief		Defined enumerated type for PORT direction (byte width).
 */
typedef enum {
	PORT_INPUT  = 0x00U,		/**< input port (all pins in port) */
	PORT_OUTPUT = 0xFFU			/**< output port (all pins in port) */
} T_portDirection;

/**
 * 	@brief		Defined enumerated type for PORT data output (byte width).
 */
typedef enum {
	PORT_LOW  = 0x00U,			/**< low level ouput (all pins in port) */
	PORT_HIGH = 0xFFU			/**< high level output (all pins in port) */
} T_portLevel;

/* ----------------------------------------------------------------------------
**	PORT IO Registers Getters and Setters.
*/

/**
 *	@def 		GetPORT_DDR1
 *	@brief 		IO port 1 data direction getter.
 * 	@param		.
 * 	@return		data direction of port 1 (byte).
 */
#define GetPORT_DDR1()			GetIOREGByte(IO_DDR1)

/**
 *	@def 		GetPORT_DDR2
 *	@brief 		IO port 2 data direction getter.
 * 	@param		.
 * 	@return		data direction of port 2 (byte).
 */
#define GetPORT_DDR2()			GetIOREGByte(IO_DDR2)

/**
 *	@def 		GetPORT_DDR3
 *	@brief 		IO port 3 data direction getter.
 * 	@param		.
 * 	@return		data direction of port 3 (byte).
 */
#define GetPORT_DDR3()			GetIOREGByte(IO_DDR3)

/**
 *	@def 		GetPORT_DDR4
 *	@brief 		IO port 4 data direction getter.
 * 	@param		.
 * 	@return		data direction of port 4 (byte).
 */
#define GetPORT_DDR4()			GetIOREGByte(IO_DDR4)

/**
 *	@def 		GetPORT_DDR5
 *	@brief 		IO port 5 data direction getter.
 * 	@param		.
 * 	@return		data direction of port 5 (byte).
 */
#define GetPORT_DDR5()			GetIOREGByte(IO_DDR5)

/**
 *	@def 		GetPORT_PDR1
 *	@brief 		IO port 1 state getter.
 * 	@param		.
 * 	@return		state of port 1 (byte).
 */
#define GetPORT_PDR1()			GetIOREGByte(IO_PDR1)

/**
 *	@def 		GetPORT_PDR2
 *	@brief 		IO port 2 state getter.
 * 	@param		.
 * 	@return		state of port 2 (byte).
 */
#define GetPORT_PDR2()			GetIOREGByte(IO_PDR2)

/**
 *	@def 		GetPORT_PDR3
 *	@brief 		IO port 3 state getter.
 * 	@param		.
 * 	@return		state of port 3 (byte).
 */
#define GetPORT_PDR3()			GetIOREGByte(IO_PDR3)

/**
 *	@def 		GetPORT_PDR4
 *	@brief 		IO port 4 state getter.
 * 	@param		.
 * 	@return		state of port 4 (byte).
 */
#define GetPORT_PDR4()			GetIOREGByte(IO_PDR4)

/**
 *	@def 		GetPORT_PDR5
 *	@brief 		IO port 5 state getter.
 * 	@param		.
 * 	@return		state of port 5 (byte).
 */
#define GetPORT_PDR5()			GetIOREGByte(IO_PDR5)

/**
 *	@def 		SetPORT_DDR1
 *	@brief 		IO port 1 data direction setter.
 * 	@param[in]	DIR  	Data direction of the port (byte).
 * 	@return		.
 */
#define SetPORT_DDR1(DIR) { \
	SetIOREGByte(IO_DDR1, DIR); \
}

/**
 *	@def 		SetPORT_DDR2
 *	@brief 		IO port 2 data direction setter.
 * 	@param[in]	DIR  	Data direction of the port (byte).
 * 	@return		.
 */
#define SetPORT_DDR2(DIR) { \
	SetIOREGByte(IO_DDR2, DIR); \
}

/**
 *	@def 		SetPORT_DDR3
 *	@brief 		IO port 3 data direction setter.
 * 	@param[in]	DIR  	Data direction of the port (byte).
 * 	@return		.
 */
#define SetPORT_DDR3(DIR) { \
	SetIOREGByte(IO_DDR3, DIR); \
}

/**
 *	@def 		SetPORT_DDR4
 *	@brief 		IO port 4 data direction setter.
 * 	@param[in]	DIR  	Data direction of the port (byte).
 * 	@return		.
 */
#define SetPORT_DDR4(DIR) { \
	SetIOREGByte(IO_DDR4, DIR); \
}

/**
 *	@def 		SetPORT_DDR5
 *	@brief 		IO port 5 data direction setter.
 * 	@param[in]	DIR  	Data direction of the port (byte).
 * 	@return		.
 */
#define SetPORT_DDR5(DIR) { \
	SetIOREGByte(IO_DDR5, DIR); \
}

/**
 *	@def 		SetPORT_PDR1
 *	@brief 		IO port 1 state setter.
 * 	@param[in]	STATE  	State of the port (byte).
 * 	@return		.
 */
#define SetPORT_PDR1(STATE) { \
	SetIOREGByte(IO_PDR1, STATE); \
}

/**
 *	@def 		SetPORT_PDR2
 *	@brief 		IO port 2 state setter.
 * 	@param[in]	STATE  	State of the port (byte).
 * 	@return		.
 */
#define SetPORT_PDR2(STATE) { \
	SetIOREGByte(IO_PDR2, STATE); \
}

/**
 *	@def 		SetPORT_PDR3
 *	@brief 		IO port 3 state setter.
 * 	@param[in]	STATE  	State of the port (byte).
 * 	@return		.
 */
#define SetPORT_PDR3(STATE) { \
	SetIOREGByte(IO_PDR3, STATE); \
}

/**
 *	@def 		SetPORT_PDR4
 *	@brief 		IO port 4 state setter.
 * 	@param[in]	STATE  	State of the port (byte).
 * 	@return		.
 */
#define SetPORT_PDR4(STATE) { \
	SetIOREGByte(IO_PDR4, STATE); \
}

/**
 *	@def 		SetPORT_PDR5
 *	@brief 		IO port 5 state setter.
 * 	@param[in]	STATE  	State of the port (byte).
 * 	@return		.
 */
#define SetPORT_PDR5(STATE) { \
	SetIOREGByte(IO_PDR5, STATE); \
}

#endif /* PORT_IO_H. */
