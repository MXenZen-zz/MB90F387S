/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Digital Input / Output										             */
/**
 *	@file		dio.c
 *	@brief		This file contains the sample test program for DIO debugging.
 *	@details	In this test, all pin's mode (data direction) will be set to
 *				output and their pin data (logic/states) will be inverted and
 *				reflected on the built-in LEDs (logic test).
**/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *	Copyright (C) 2015-2017 Xeno Xerxes Masong (xxmasong@gmail.com)
 *
 *	This program does not guarantee that it shall fulfill its task
 *	under all circumstances. Thus, the author/developer shall not
 *	be held liable for any damages that might be incurred by the
 *	device using this program, or for any reason whatsoever.
 *
 *	This program is free software: you can redistribute it and/or
 *	modify it under the terms of the GNU General Public License as
 *	published by the Free Software Foundation, either version 3 of
 *	the License, or (at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program. If not, see <https://www.gnu.org/licenses/>.
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *	Target Hardware Information:
 *
 *		MCU			: F2MC-16LX MB90385 Series
 *		CPU			: MB90F387S
 *		Vcc			: 5.0 V
 *		Frequency	: 16 MHz (4 MHz PLLx4)
 *		Inputs		: N/A
 *		Outputs		: P10-P13
 *		Driver		: DIO
 *		Helper		: TBT
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <GPIO/dio.h>
#include <TMR/tbt.h>

/* ----------------------------------------------------------------------------
**	Test Flags.
*/

/**
 * 	@def		DIO_GROUP_SIZE
 *  @brief		Size of the array to hold pins, states, and modes.
 */
#define DIO_GROUP_SIZE 			(4U)

/* ----------------------------------------------------------------------------
**	Test Variables.
*/

/**
 *  @var		groupPins
 *  @brief		Group of pins.
 */
static T_pinNumber groupPins[DIO_GROUP_SIZE] = {PIN10, PIN11, PIN12, PIN13};

/**
 *  @var		groupModes
 *  @brief		Group of pin modes.
 */
static T_pinDirection groupModes[DIO_GROUP_SIZE] = {PIN_OUTPUT, PIN_OUTPUT, PIN_OUTPUT, PIN_OUTPUT};

/**
 *  @var		groupLogic
 *  @brief		Group of pin logic or states.
 */
static T_pinLevel groupLogic[DIO_GROUP_SIZE] = {PIN_LOW, PIN_LOW, PIN_LOW, PIN_LOW};

/* ----------------------------------------------------------------------------
**	Inline Functions.
*/

/**
 *  @fn			T_void init(T_void)
 *  @brief 		Initialization / setup code runs once.
 *  @param		.
 *	@return		.
 */
#pragma inline init
static T_void init(T_void)
{
	__DI();
	__set_il(7);

	/* initialize helper modules */
	initTBT();
	/* initialize group of pin modes */
	pinModeDigitalGroup(groupPins, groupModes, DIO_GROUP_SIZE);
	/* initialize pin states */
	writeDigitalGroup(groupPins, groupLogic, DIO_GROUP_SIZE);

	__EI();
}

/**
 *  @fn			T_void debug(T_void)
 *  @brief 		Iteration / loop code runs repeatedly.
 *  @param		.
 *	@return		.
 */
#pragma inline debug
static T_void debug(T_void)
{
	T_uint8 count;

	/* read pin states and update group logic */
	readDigitalGroup(groupPins, groupLogic, DIO_GROUP_SIZE);
	/* loop throughout pin group and inverse each pin state / logic */
	for(count = 0U; LT(count, DIO_GROUP_SIZE); count++) {
		groupLogic[count] = NOT(groupLogic[count]);
	}
	/* write back pin states */
	writeDigitalGroup(groupPins, groupLogic, DIO_GROUP_SIZE);
	/* next update delay */
	delay(100U);
}

/* ----------------------------------------------------------------------------
**	Main Function.
*/

/**
 *  @fn			T_void main(T_void)
 *  @brief 		Main / program entry point.
 *  @param		.
 *	@return		.
 */
T_void FAR main(T_void)
{
	/* initialize first */
	init();
	/* then iterate indefinitely */
	for (;;) {
		debug();
	}
}

/* END OF DIO. */
