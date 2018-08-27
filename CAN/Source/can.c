/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Controller Area Network									   		   	     */
/**
 *	@file		can.c
 *	@brief		This file contains the sample test program for CAN debugging.
 *	@details 	This test requires two nodes / microcontrollers connected
 *				together with their respective CAN transceivers. The test
 *				to perform is a simple reception and transmission of data
 *				between two nodes with minimal configuration involved to
 *				initiate and demonstrate CAN communication. Considering that
 *				the two nodes are already connected and that the software
 *				code to build is ready, here are the steps to perform:
 *				(1) Determine which microcontroller is NODE A or NODE B. The
 *				microcontroller must be consistent as to what NODE it is.
 *				(2) Define CAN_NODE below as either CAN_NODE_A or CAN_NODE_B.
 *				Build the program separately for CAN_NODE_A and CAN_NODE_B.
 *				(3) Run Accemic MDE program and download/flash the program
 *				built with CAN_NODE_A specification to NODE A microcontroller.
 *				(4) Run Accemic MDE program and download/flash the program
 *				built with CAN_NODE_B specification to NODE B microcontroller.
 *				(5) In both running Accemic MDE, browse the I/O registers
 *				section and look for DTR(0) to DTR(7). Right-click on each
 *				then click "add to watch". Dock the Add-to-Watch section to
 *				the corner to make it stay permanent. Close any other section
 *				open other than the Add-to-Watch.
 *				(6) Click the "online watching" button at the Add-to-Watch
 *				section to receive real-time monitoring. Expand(+) all DTRs to
 *				view each byte in the data buffer of every message buffer.
 *				(7) Run/execute the downloaded program (simultaneously) in both
 *				nodes. The Add-to-Watch section will start to highlight changes
 *				in blue. Normally, the DTRs will report incrementing values
 *				which are dependent of the node it came from. So try pausing one
 *				of the nodes and check if any of the successive four DTRs are
 *				frozen (no changes) until you resume the paused node. If there's
 *				no changes or values are frozen in both paused or resumed state,
 *				try resetting both nodes. If the problems persisted, check the
 *				wirings and modify or update the code if necessary.
 *	@warning	The CAN RX and TX pins must be already connected to the working
 *				CAN transceiver before downloading/flashing the program.
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
 *		Inputs		: RX (P44)
 *		Outputs		: TX (P43)
 *		Driver		: CAN
 *		Helper		: TBT
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <COM/can.h>
#include <TMR/tbt.h>

/* ----------------------------------------------------------------------------
**	Test Flags.
*/

/**
 * 	@def		CAN_NODE_A
 *  @brief		Download/flash binary code to NODE A microcontroller.
 */
#define CAN_NODE_A				(1U)

/**
 * 	@def		CAN_NODE_B
 *  @brief		Download/flash binary code to NODE B microcontroller.
 */
#define CAN_NODE_B				(2U)

/**
 * 	@def		CAN_NODE_A_RX_BUFFS
 *  @brief		Reception message buffers for NODE A.
 */
#define CAN_NODE_A_RX_BUFFS		(0x0FU)

/**
 * 	@def		CAN_NODE_A_TX_BUFFS
 *  @brief		Transmission message buffers for NODE A.
 */
#define CAN_NODE_A_TX_BUFFS		(0xF0U)

/**
 * 	@def		CAN_NODE_A_TX_DWORD
 *  @brief		Transmission message buffer dword index for NODE A.
 */
#define CAN_NODE_A_TX_DWORD		(0x01U)

/**
 * 	@def		CAN_NODE_B_RX_BUFFS
 *  @brief		Reception message buffers for NODE B.
 */
#define CAN_NODE_B_RX_BUFFS		(0xF0U)

/**
 * 	@def		CAN_NODE_B_TX_BUFFS
 *  @brief		Transmission message buffers for NODE B.
 */
#define CAN_NODE_B_TX_BUFFS		(0x0FU)

/**
 * 	@def		CAN_NODE_B_TX_DWORD
 *  @brief		Transmission message buffer dword index for NODE B.
 */
#define CAN_NODE_B_TX_DWORD		(0x00U)

/* ----------------------------------------------------------------------------
**	Test Configurations.
*/

/**
 *  @def		CAN_NODE
 *  @brief		Specify NODE microcontroller to download/flash the binary code.
 */
#define CAN_NODE 				(0U)		/* TODO: Specify NODE! */

/* ----------------------------------------------------------------------------
**	Test Variables.
*/

/**
 *  @var		data
 *  @brief		Counter updated per interval assigned to the data buffers of
 *  			various message buffers for checking correct activity and
 *  			identifying proper transmission and reception of data.
 */
static T_uint32 data;

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

	/* initialize variables */
	data = 0UL;
	/* initialize helper modules */
	initTBT();
#if EQU(CAN_NODE, CAN_NODE_A)
	/* initialize CAN for NODE A (default settings) */
	initCAN(CAN_DEF_BUS_SPEED, CAN_NODE_A_RX_BUFFS, CAN_NODE_A_TX_BUFFS);
#elif EQU(CAN_NODE, CAN_NODE_B)
	/* initialize CAN for NODE B (default settings) */
	initCAN(CAN_DEF_BUS_SPEED, CAN_NODE_B_RX_BUFFS, CAN_NODE_B_TX_BUFFS);
#else
#error Invalid Test Configuration!
#endif
	/* attempt starting CAN */
	startCAN();

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

	/* reception delay */
	delay(100U);
	/* check received data */
	checkCANReceived();
	/* loop throughout message buffers */
	for (count = NULL; LT(count, CAN_MB_SIZE); count++) {
#if EQU(CAN_NODE, CAN_NODE_A)
		/* check if correct transmit buffer for NODE A */
		if (ReadBit(CAN_NODE_A_TX_BUFFS, count)) {
			/* prepare data to transmit from NODE A to NODE B */
			WriteCANTXDWord(count, CAN_NODE_A_TX_DWORD, data + count);
		}
#elif EQU(CAN_NODE, CAN_NODE_B)
		/* check if correct transmit buffer for NODE B */
		if (ReadBit(CAN_NODE_B_TX_BUFFS, count)) {
			/* prepare data to transmit from NODE B to NODE A */
			WriteCANTXDWord(count, CAN_NODE_B_TX_DWORD, data + count);
		}
#else
#error Invalid Test Configuration!
#endif
	}
	/* attempt transmit data */
	requestCANTransmit();
	/* update data to transmit next */
	data += CAN_MB_SIZE;
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

/* END OF CAN. */
