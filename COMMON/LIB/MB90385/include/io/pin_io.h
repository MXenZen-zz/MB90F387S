/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* General Purpose Input / Output								             */
/**
 *	@file		IO/pin_io.h
 * 	@brief		This file contains types, macro registers, and macro functions
 * 				for General Purpose (PIN) IO registers.
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

#ifndef PIN_IO_H
#define PIN_IO_H

#include <IO/io_mb90385.h>

/* ----------------------------------------------------------------------------
**	PIN IO Types.
*/

/**
 * 	@brief		Defined enumerated type for PIN direction.
 */
typedef enum {
	PIN_INPUT,					/**< input pin */
	PIN_OUTPUT					/**< output pin */
} T_pinDirection;

/**
 * 	@brief		Defined enumerated type for PIN data output.
 */
typedef enum {
	PIN_LOW,					/**< low level ouput */
	PIN_HIGH					/**< high level output */
} T_pinLevel;

/* ----------------------------------------------------------------------------
**	PIN IO Port Register 1.
*/

/* direction */
#define PIN_D10					(IO_DDR1.bit.D10)
#define PIN_D11					(IO_DDR1.bit.D11)
#define PIN_D12					(IO_DDR1.bit.D12)
#define PIN_D13					(IO_DDR1.bit.D13)
#define PIN_D14					(IO_DDR1.bit.D14)
#define PIN_D15					(IO_DDR1.bit.D15)
#define PIN_D16					(IO_DDR1.bit.D16)
#define PIN_D17					(IO_DDR1.bit.D17)
#define PIN_D_IN0				(IO_DDR1.bit.D10)
#define PIN_D_IN1				(IO_DDR1.bit.D11)
#define PIN_D_IN2				(IO_DDR1.bit.D12)
#define PIN_D_IN3				(IO_DDR1.bit.D13)
#define PIN_D_PPG0				(IO_DDR1.bit.D14)
#define PIN_D_PPG1				(IO_DDR1.bit.D15)
#define PIN_D_PPG2				(IO_DDR1.bit.D16)
#define PIN_D_PPG3				(IO_DDR1.bit.D17)

/* data */
#define PIN_P10					(IO_PDR1.bit.P10)
#define PIN_P11					(IO_PDR1.bit.P11)
#define PIN_P12					(IO_PDR1.bit.P12)
#define PIN_P13					(IO_PDR1.bit.P13)
#define PIN_P14					(IO_PDR1.bit.P14)
#define PIN_P15					(IO_PDR1.bit.P15)
#define PIN_P16					(IO_PDR1.bit.P16)
#define PIN_P17					(IO_PDR1.bit.P17)
#define PIN_P_IN0				(IO_PDR1.bit.P10)
#define PIN_P_IN1				(IO_PDR1.bit.P11)
#define PIN_P_IN2				(IO_PDR1.bit.P12)
#define PIN_P_IN3				(IO_PDR1.bit.P13)
#define PIN_P_PPG0				(IO_PDR1.bit.P14)
#define PIN_P_PPG1				(IO_PDR1.bit.P15)
#define PIN_P_PPG2				(IO_PDR1.bit.P16)
#define PIN_P_PPG3				(IO_PDR1.bit.P17)

/* ----------------------------------------------------------------------------
**	PIN IO Port Register 2.
*/

/* direction */
#define PIN_D20					(IO_DDR2.bit.D20)
#define PIN_D21					(IO_DDR2.bit.D21)
#define PIN_D22					(IO_DDR2.bit.D22)
#define PIN_D23					(IO_DDR2.bit.D23)
#define PIN_D24					(IO_DDR2.bit.D24)
#define PIN_D25					(IO_DDR2.bit.D25)
#define PIN_D26					(IO_DDR2.bit.D26)
#define PIN_D27					(IO_DDR2.bit.D27)
#define PIN_D_TIN0				(IO_DDR2.bit.D20)
#define PIN_D_TOT0				(IO_DDR2.bit.D21)
#define PIN_D_TIN1				(IO_DDR2.bit.D22)
#define PIN_D_TOT1				(IO_DDR2.bit.D23)
#define PIN_D_INT4				(IO_DDR2.bit.D24)
#define PIN_D_INT5				(IO_DDR2.bit.D25)
#define PIN_D_INT6				(IO_DDR2.bit.D26)
#define PIN_D_INT7				(IO_DDR2.bit.D27)

/* data */
#define PIN_P20					(IO_PDR2.bit.P20)
#define PIN_P21					(IO_PDR2.bit.P21)
#define PIN_P22					(IO_PDR2.bit.P22)
#define PIN_P23					(IO_PDR2.bit.P23)
#define PIN_P24					(IO_PDR2.bit.P24)
#define PIN_P25					(IO_PDR2.bit.P25)
#define PIN_P26					(IO_PDR2.bit.P26)
#define PIN_P27					(IO_PDR2.bit.P27)
#define PIN_P_TIN0				(IO_PDR2.bit.P20)
#define PIN_P_TOT0				(IO_PDR2.bit.P21)
#define PIN_P_TIN1				(IO_PDR2.bit.P22)
#define PIN_P_TOT1				(IO_PDR2.bit.P23)
#define PIN_P_INT4				(IO_PDR2.bit.P24)
#define PIN_P_INT5				(IO_PDR2.bit.P25)
#define PIN_P_INT6				(IO_PDR2.bit.P26)
#define PIN_P_INT7				(IO_PDR2.bit.P27)

/* ----------------------------------------------------------------------------
**	PIN IO Port Register 3.
*/

/* direction */
#define PIN_D30					(IO_DDR3.bit.D30)
#define PIN_D31					(IO_DDR3.bit.D31)
#define PIN_D32					(IO_DDR3.bit.D32)
#define PIN_D33					(IO_DDR3.bit.D33)
#define PIN_D35					(IO_DDR3.bit.D35)
#define PIN_D36					(IO_DDR3.bit.D36)
#define PIN_D37					(IO_DDR3.bit.D37)
#define PIN_D_ADTG				(IO_DDR3.bit.D37)

/* data */
#define PIN_P30					(IO_PDR3.bit.P30)
#define PIN_P31					(IO_PDR3.bit.P31)
#define PIN_P32					(IO_PDR3.bit.P32)
#define PIN_P33					(IO_PDR3.bit.P33)
#define PIN_P35					(IO_PDR3.bit.P35)
#define PIN_P36					(IO_PDR3.bit.P36)
#define PIN_P37					(IO_PDR3.bit.P37)
#define PIN_P_ADTG				(IO_PDR3.bit.P37)

/* ----------------------------------------------------------------------------
**	PIN IO Port Register 4.
*/

/* direction */
#define PIN_D40					(IO_DDR4.bit.D40)
#define PIN_D41					(IO_DDR4.bit.D41)
#define PIN_D42					(IO_DDR4.bit.D42)
#define PIN_D43					(IO_DDR4.bit.D43)
#define PIN_D44					(IO_DDR4.bit.D44)
#define PIN_D_SIN1				(IO_DDR4.bit.D40)
#define PIN_D_SCK1				(IO_DDR4.bit.D41)
#define PIN_D_SOT1				(IO_DDR4.bit.D42)
#define	PIN_D_TX				(IO_DDR4.bit.D43)
#define PIN_D_RX				(IO_DDR4.bit.D44)

/* data */
#define PIN_P40					(IO_PDR4.bit.P40)
#define PIN_P41					(IO_PDR4.bit.P41)
#define PIN_P42					(IO_PDR4.bit.P42)
#define PIN_P43					(IO_PDR4.bit.P43)
#define PIN_P44					(IO_PDR4.bit.P44)
#define PIN_P_SIN1				(IO_PDR4.bit.P40)
#define PIN_P_SCK1				(IO_PDR4.bit.P41)
#define PIN_P_SOT1				(IO_PDR4.bit.P42)
#define	PIN_P_TX				(IO_PDR4.bit.P43)
#define PIN_P_RX				(IO_PDR4.bit.P44)

/* ----------------------------------------------------------------------------
**	PIN IO Port Register 5.
*/

/* direction */
#define PIN_D50					(IO_DDR5.bit.D50)
#define PIN_D51					(IO_DDR5.bit.D51)
#define PIN_D52					(IO_DDR5.bit.D52)
#define PIN_D53					(IO_DDR5.bit.D53)
#define PIN_D54					(IO_DDR5.bit.D54)
#define PIN_D55					(IO_DDR5.bit.D55)
#define PIN_D56					(IO_DDR5.bit.D56)
#define PIN_D57					(IO_DDR5.bit.D57)
#define PIN_D_AN0				(IO_DDR5.bit.D50)
#define PIN_D_AN1				(IO_DDR5.bit.D51)
#define PIN_D_AN2				(IO_DDR5.bit.D52)
#define PIN_D_AN3				(IO_DDR5.bit.D53)
#define PIN_D_AN4				(IO_DDR5.bit.D54)
#define PIN_D_AN5				(IO_DDR5.bit.D55)
#define PIN_D_AN6				(IO_DDR5.bit.D56)
#define PIN_D_AN7				(IO_DDR5.bit.D57)

/* data */
#define PIN_P50					(IO_PDR5.bit.P50)
#define PIN_P51					(IO_PDR5.bit.P51)
#define PIN_P52					(IO_PDR5.bit.P52)
#define PIN_P53					(IO_PDR5.bit.P53)
#define PIN_P54					(IO_PDR5.bit.P54)
#define PIN_P55					(IO_PDR5.bit.P55)
#define PIN_P56					(IO_PDR5.bit.P56)
#define PIN_P57					(IO_PDR5.bit.P57)
#define PIN_P_AN0				(IO_PDR5.bit.P50)
#define PIN_P_AN1				(IO_PDR5.bit.P51)
#define PIN_P_AN2				(IO_PDR5.bit.P52)
#define PIN_P_AN3				(IO_PDR5.bit.P53)
#define PIN_P_AN4				(IO_PDR5.bit.P54)
#define PIN_P_AN5				(IO_PDR5.bit.P55)
#define PIN_P_AN6				(IO_PDR5.bit.P56)
#define PIN_P_AN7				(IO_PDR5.bit.P57)

/* ----------------------------------------------------------------------------
**	PIN IO Register Fields Macro Functions.
*/

/**
 *	@def 		ReadBitIOPinMode
 *	@brief 		Reads IO pin data direction.
 * 	@param		DX		DDR pin (IO_DDRn.bit.Dm).
 * 	@return		data direction (bit).
 */
#define ReadBitIOPinMode(DX) 	GetIOREG(DX)

/**
 *	@def 		ReadBitIOPinData
 *	@brief 		Reads IO pin logic level or state.
 * 	@param		PX		PDR pin (IO_PDRn.bit.Dm).
 * 	@return		logic level or state (bit).
 */
#define ReadBitIOPinData(PX)	GetIOREG(PX)

/**
 *	@def 		WriteBitIOPinMode
 *	@brief 		Writes IO pin data direction.
 * 	@param		DX		DDR pin (IO_DDRn.bit.Dm).
 * 	@param[in]	DIR  	Data direction (bit).
 * 	@return		.
 */
#define WriteBitIOPinMode(DX, DIR) { \
	SetIOREG(DX, (T_bit)(DIR)); \
}

/**
 *	@def 		WriteBitIOPinData
 *	@brief 		Writes IO pin logic level or state.
 * 	@param		PX		PDR pin (IO_PDRn.bit.Dm).
 * 	@param[in]	STATE  	Logic level or state (bit).
 * 	@return		.
 */
#define WriteBitIOPinData(PX, STATE) { \
	SetIOREG(PX, (T_bit)(STATE)); \
}

#endif /* PIN_IO_H. */
