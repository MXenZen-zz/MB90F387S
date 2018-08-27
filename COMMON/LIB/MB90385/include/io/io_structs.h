/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* MB90385 Series IO Data and Register Defined Types 		   			     */
/**
 *	@file		IO/io_structs.h
 * 	@brief		This file contains types, and getters and setters for
 * 				F2MC-16LX MB90385 Series MB90F387S IO data and registers.
 */
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

#ifndef IO_STRUCTS_H
#define IO_STRUCTS_H

#include <LIB/bitmanip.h>

/* ----------------------------------------------------------------------------
**	IO Types.
*/

/**
 *	@brief		Port 1 serves as both general-purpose IO port and
 *  			PPG timer output, or input capture input.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 P10 : 1;
		T_uint8 P11 : 1;
		T_uint8 P12 : 1;
		T_uint8 P13 : 1;
		T_uint8 P14 : 1;
		T_uint8 P15 : 1;
		T_uint8 P16 : 1;
		T_uint8 P17 : 1;
	} bit;
} T_pdr1;

/**
 *	@brief		Port 2 serves as both general-purpose IO port and
 *  			reload timer IO, or external interrupt input pin.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 P20 : 1;
		T_uint8 P21 : 1;
		T_uint8 P22 : 1;
		T_uint8 P23 : 1;
		T_uint8 P24 : 1;
		T_uint8 P25 : 1;
		T_uint8 P26 : 1;
		T_uint8 P27 : 1;
	} bit;
} T_pdr2;

/**
 *	@brief		Port 3 serves as both general-purpose IO port or
 *  			A/D converter start trigger pin.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 P30 : 1;
		T_uint8 P31 : 1;
		T_uint8 P32 : 1;
		T_uint8 P33 : 1;
		T_uint8 P34 : 1;
		T_uint8 P35 : 1;
		T_uint8 P36 : 1;
		T_uint8 P37 : 1;
	} bit;
} T_pdr3;

/**
 *	@brief		Port 4 serves as both general-purpose IO port
 *  			and UART1 IO or CAN controller transmit/receive pin.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 P40 : 1;
		T_uint8 P41 : 1;
		T_uint8 P42 : 1;
		T_uint8 P43 : 1;
		T_uint8 P44 : 1;
		T_uint8 P45 : 1;
		T_uint8 P46 : 1;
		T_uint8 P47 : 1;
	} bit;
} T_pdr4;

/**
 *	@brief		Port 5 serves as both general-purpose IO port
 *  			and analog input pin.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 P50 : 1;
		T_uint8 P51 : 1;
		T_uint8 P52 : 1;
		T_uint8 P53 : 1;
		T_uint8 P54 : 1;
		T_uint8 P55 : 1;
		T_uint8 P56 : 1;
		T_uint8 P57 : 1;
	} bit;
} T_pdr5;

/**
 *	@brief		The port 1 direction register sets the input/output
 *  			directions (set pin to "1" for input and "0" for output).
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 D10 : 1;
		T_uint8 D11 : 1;
		T_uint8 D12 : 1;
		T_uint8 D13 : 1;
		T_uint8 D14 : 1;
		T_uint8 D15 : 1;
		T_uint8 D16 : 1;
		T_uint8 D17 : 1;
	} bit;
} T_ddr1;

/**
 *	@brief		The port 2 direction register sets the input/output
 *  			directions (set pin to "1" for output and "0" for input).
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 D20 : 1;
		T_uint8 D21 : 1;
		T_uint8 D22 : 1;
		T_uint8 D23 : 1;
		T_uint8 D24 : 1;
		T_uint8 D25 : 1;
		T_uint8 D26 : 1;
		T_uint8 D27 : 1;
	} bit;
} T_ddr2;

/**
 *	@brief		The port 3 direction register sets the input/output
 *  			directions (set pin to "1" for output and "0" for input).
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 D30 : 1;
		T_uint8 D31 : 1;
		T_uint8 D32 : 1;
		T_uint8 D33 : 1;
		T_uint8 D34 : 1;
		T_uint8 D35 : 1;
		T_uint8 D36 : 1;
		T_uint8 D37 : 1;
	} bit;
} T_ddr3;

/**
 *	@brief		The port 4 direction register sets the input/output
 *  			directions (set pin to "1" for output and "0" for input).
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 D40 : 1;
		T_uint8 D41 : 1;
		T_uint8 D42 : 1;
		T_uint8 D43 : 1;
		T_uint8 D44 : 1;
		T_uint8 D45 : 1;
		T_uint8 D46 : 1;
		T_uint8 D47 : 1;
	} bit;
} T_ddr4;

/**
 *	@brief		The port 5 direction register sets the input/output
 *  			directions (set pin to "1" for output and "0" for input).
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 D50 : 1;
		T_uint8 D51 : 1;
		T_uint8 D52 : 1;
		T_uint8 D53 : 1;
		T_uint8 D54 : 1;
		T_uint8 D55 : 1;
		T_uint8 D56 : 1;
		T_uint8 D57 : 1;
	} bit;
} T_ddr5;

/**
 *	@brief		The analog input enable register (ADER) enables or
 * 				disables the analog input pins to be used in the
 * 				8-/10-bit A/D converter.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 ADE0 : 1;
		T_uint8 ADE1 : 1;
		T_uint8 ADE2 : 1;
		T_uint8 ADE3 : 1;
		T_uint8 ADE4 : 1;
		T_uint8 ADE5 : 1;
		T_uint8 ADE6 : 1;
		T_uint8 ADE7 : 1;
	} bit;
} T_ader;

/**
 *	@brief		The serial mode register 1 (SMR1) performs selecting
 * 				operation mode, selecting baud rate clock, and
 * 				disabling/enabling of output of serial data and clock
 * 				to pin.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 SOE  : 1;
		T_uint8 SCKE : 1;
		T_uint8 RST  : 1;
		T_uint8 CS   : 3;
		T_uint8 MD   : 2;
	} bit;
} T_smr;

/**
 *	@brief		The serial control register 1 (SCR1) performs the
 * 				following: setting parity bit, selecting stop bit length
 * 				and data length, selecting frame data format in operation
 * 				mode 1 (asynchronous multiprocessor mode), clearing
 * 				receive error flag, and enabling/disabling of transmitting
 * 				/ receiving.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 TXE : 1;
		T_uint8 RXE : 1;
		T_uint8 REC : 1;
		T_uint8 AD  : 1;
		T_uint8 CL  : 1;
		T_uint8 SBL : 1;
		T_uint8 P   : 1;
		T_uint8 PEN : 1;
	} bit;
} T_scr;

/**
 *	@brief		Allocated to the same address, the register functions as
 *  			SIDR1 at read and functions as SODR1 at write.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 D : 7;
		T_uint8   : 1;
	} bit;
} T_siodr;

/**
 *	@brief		The serial status register 1 (SSR1) checks the
 * 				transmission/reception status and error status
 * 				and enables/disables interrupts.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 TIE  : 1;
		T_uint8 RIE  : 1;
		T_uint8 BDS  : 1;
		T_uint8 TDRE : 1;
		T_uint8 RDRF : 1;
		T_uint8 FRE  : 1;
		T_uint8 ORE  : 1;
		T_uint8 PE   : 1;
	} bit;
} T_ssr;

/**
 *	@brief		The communication prescaler control register 1
 * 				(CDCR1) is used to set the baud rate of the
 * 				dedicated baud rate generator for the UART1.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 DIV : 4;
		T_uint8     : 3;
		T_uint8 MD  : 1;
	} bit;
} T_cdcr;

/**
 *	@brief		The DTP/external interrupt enable register (ENIR)
 * 				enables/disables the DTP/external interrupt request
 * 				for external interrupt pins (INT7 to INT4) and the
 * 				INT0 (RX) pin respectively.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 EN0 : 1;
		T_uint8     : 3;
		T_uint8 EN4 : 1;
		T_uint8 EN5 : 1;
		T_uint8 EN6 : 1;
		T_uint8 EN7 : 1;
	} bit;
} T_enir;

/**
 *	@brief		The DTP/external interrupt factor register (EIRR)
 * 				holds DTP/external interrupt factors.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 ER0 : 1;
		T_uint8     : 3;
		T_uint8 ER4 : 1;
		T_uint8 ER5 : 1;
		T_uint8 ER6 : 1;
		T_uint8 ER7 : 1;
	} bit;
} T_eirr;

/**
 *	@brief		The detection level setting register (High) sets
 * 				the levels or edges of input signals that cause
 * 				interrupt factors in INT7 to INT4 and INT0 (RX)
 * 				of the DTP / external interrupt pins.
 */
typedef union {
	T_uint16 word;
	struct {
		T_uint16 LALB0 : 2;
		T_uint16       : 6;
		T_uint16 LALB4 : 2;
		T_uint16 LALB5 : 2;
		T_uint16 LALB6 : 2;
		T_uint16 LALB7 : 2;
	} bit;
} T_elvr;

/**
 *	@brief		The A/D control status register (Low) (ADCS: L)
 * 				provides selection of A/D conversion mode and
 * 				selection of start and end channel of A/D conversion.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 ANE : 3;
		T_uint8 ANS : 3;
		T_uint8 MD  : 2;
	} bit;
} T_adcsl;

/**
 *	@brief		The A/D control status register (High) (ADCS: H)
 * 				provides (1) starting A/D conversion function by
 * 				software, (2) selecting start trigger for A/D
 * 				conversion, (3) storing A/D conversion results in
 * 				A/D data register to enable or disable interrupt
 * 				request, (4) storing A/D conversion results in A/D
 * 				data register to check and clear interrupt request
 * 				flag, and (5) pausing A/D conversion and checking
 * 				state during conversion.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 	 : 1;
		T_uint8 STRT : 1;
		T_uint8 STS  : 2;
		T_uint8 PAUS : 1;
		T_uint8 INTE : 1;
		T_uint8 INT  : 1;
		T_uint8 BUSY : 1;
	} bit;
} T_adcsh;

/**
 *	@brief		The A/D data register (Low) (ADCR: L) stores the A/D
 *  			conversion results and the higher five bits in the A/D
 *  			data register (ADCR: H) select the compare time, sampling
 *  			time and resolution of A/D conversion.
 */
typedef union {
	struct {
		T_uint16 DATA10 : 10;
		T_uint16 	    : 6;
	} word;
	struct {
		T_uint16 DATA8  : 8;
		T_uint16 ADCRH  : 8;
	} byte;
	struct {
		T_uint16        : 11;
		T_uint16 CT     : 2;
		T_uint16 ST     : 2;
		T_uint16 S10    : 1;
	} bit;
} T_adcrlh;

/**
 *	@brief		The PPG operation mode control register (PPGC) provides
 *  			(1) enabling or disabling operation of 8-/16-bit PPG timer,
 *  			(2) switching between pin functions (enabling or disabling
 *  			pulse output), (3) enabling or disabling underflow interrupt,
 * 				(4) setting underflow interrupt request flag, and (5) setting
 * 				the operation mode of the 8-/16-bit PPG timer.
 */
typedef union {
	T_uint16 word;
	struct {
		T_uint16 	  : 3;
		T_uint16 PUF0 : 1;
		T_uint16 PIE0 : 1;
		T_uint16 PE0  : 1;
		T_uint16 	  : 1;
		T_uint16 PEN0 : 1;
		T_uint16 	  : 1;
		T_uint16 MD   : 2;
		T_uint16 PUF1 : 1;
		T_uint16 PIE1 : 1;
		T_uint16 PE1  : 1;
		T_uint16 	  : 1;
		T_uint16 PEN1 : 1;
	} bit;
} T_ppgc;

/**
 *	@brief		The PPG count clock select register selects the
 * 				count clock of the 8-/16-bit PPG timer.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8	    : 2;
		T_uint8 PCM : 3;
		T_uint8 PCS : 3;
	} bit;
} T_ppg;

/**
 *	@brief		The timer counter control status register (TCCS)
 * 				selects the count clock and conditions for clearing
 * 				the counter, clears the counter, enables the count
 * 				operation or interrupt, and checks the interrupt
 * 				request flag.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 CLK  : 3;
		T_uint8 CLR  : 1;
		T_uint8      : 1;
		T_uint8 STOP : 1;
		T_uint8 IVFE : 1;
		T_uint8 IVF  : 1;
	} bit;
} T_tccs;

/**
 *	@brief		The input capture control status registers provides
 *  			(1) selecting the edge to be detected, (2) enabling
 *  			or disabling an interrupt when the edge is detected,
 *  			and (3) checking and clearing the valid edge detection
 *  			flag when the edge is detected.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 EG0  : 2;
		T_uint8 EG1  : 2;
		T_uint8 ICE0 : 1;
		T_uint8 ICE1 : 1;
		T_uint8 ICP0 : 1;
		T_uint8 ICP1 : 1;
	} bit;
} T_ics;

/**
 *	@brief		The timer control status registers (Low) (TMCSR0: L,
 * 				TMCSR1: L) enables or disables the timer operation,
 * 				checks the generation of a software trigger or an
 * 				underflow, enables or disables an underflow interrupt,
 * 				selects the reload mode, and sets the output of the
 * 				TOT pin.
 */
typedef union {
	T_uint16 word;
	struct {
		T_uint16 TRG  : 1;
		T_uint16 CNTE : 1;
		T_uint16 UF   : 1;
		T_uint16 INTE : 1;
		T_uint16 RELD : 1;
		T_uint16 OUTL : 1;
		T_uint16 OUTE : 1;
		T_uint16 MOD  : 3;
		T_uint16 CSL  : 2;
		T_uint16      : 4;
	} bit;
} T_tmcsr;

/**
 *	@brief		The ROM mirroring function select register (ROMM) enables
 *  			or disables ROM data in the FF bank be read by access to
 *  			the 00 bank.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 MI : 1;
		T_uint8    : 7;
	} bit;
} T_romm;

/**
 *	@brief		The message buffer valid register (BVALR) enables
 * 				or disables the message buffers and indicates their
 * 				status.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 BVAL0 : 1;
		T_uint8 BVAL1 : 1;
		T_uint8 BVAL2 : 1;
		T_uint8 BVAL3 : 1;
		T_uint8 BVAL4 : 1;
		T_uint8 BVAL5 : 1;
		T_uint8 BVAL6 : 1;
		T_uint8 BVAL7 : 1;
	} bit;
} T_bvalr;

/**
 *	@brief		The transmission request register (TREQR) sets a
 * 				transmit request for each message buffer and indicates
 * 				its status.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 TREQ0 : 1;
		T_uint8 TREQ1 : 1;
		T_uint8 TREQ2 : 1;
		T_uint8 TREQ3 : 1;
		T_uint8 TREQ4 : 1;
		T_uint8 TREQ5 : 1;
		T_uint8 TREQ6 : 1;
		T_uint8 TREQ7 : 1;
	} bit;
} T_treqr;

/**
 *	@brief		The transmission cancel register (TCANR) sets
 * 				cancellation of a transmission request for the
 * 				message buffer in the transmit wait state.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 TCAN0 : 1;
		T_uint8 TCAN1 : 1;
		T_uint8 TCAN2 : 1;
		T_uint8 TCAN3 : 1;
		T_uint8 TCAN4 : 1;
		T_uint8 TCAN5 : 1;
		T_uint8 TCAN6 : 1;
		T_uint8 TCAN7 : 1;
	} bit;
} T_tcanr;

/**
 *	@brief		The transmission complete register (TCR) indicates
 * 				whether transmitting a data from the message buffer
 * 				completes.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 TC0 : 1;
		T_uint8 TC1 : 1;
		T_uint8 TC2 : 1;
		T_uint8 TC3 : 1;
		T_uint8 TC4 : 1;
		T_uint8 TC5 : 1;
		T_uint8 TC6 : 1;
		T_uint8 TC7 : 1;
	} bit;
} T_tcr;

/**
 *	@brief		The reception complete register (RCR) indicates
 * 				whether the reception a data to the message buffer
 * 				(x) completes receiving.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 RC0 : 1;
		T_uint8 RC1 : 1;
		T_uint8 RC2 : 1;
		T_uint8 RC3 : 1;
		T_uint8 RC4 : 1;
		T_uint8 RC5 : 1;
		T_uint8 RC6 : 1;
		T_uint8 RC7 : 1;
	} bit;
} T_rcr;

/**
 *	@brief		The reception RTR register (RRTRR) indicates that
 * 				the remote frame is stored in the message buffer.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 RRTR0 : 1;
		T_uint8 RRTR1 : 1;
		T_uint8 RRTR2 : 1;
		T_uint8 RRTR3 : 1;
		T_uint8 RRTR4 : 1;
		T_uint8 RRTR5 : 1;
		T_uint8 RRTR6 : 1;
		T_uint8 RRTR7 : 1;
	} bit;
} T_rrtrr;

/**
 *	@brief		The reception overrun register (ROVRR) indicates
 * 				that an overrun occurs (the corresponding message
 * 				buffer is in the receive complete state) at storing
 * 				the received message in the message buffer.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 ROVR0 : 1;
		T_uint8 ROVR1 : 1;
		T_uint8 ROVR2 : 1;
		T_uint8 ROVR3 : 1;
		T_uint8 ROVR4 : 1;
		T_uint8 ROVR5 : 1;
		T_uint8 ROVR6 : 1;
		T_uint8 ROVR7 : 1;
	} bit;
} T_rovrr;

/**
 *	@brief		The reception complete interrupt enable register (RIER)
 * 				enables or disables a reception complete interrupt for
 * 				each message buffer.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 RIE0 : 1;
		T_uint8 RIE1 : 1;
		T_uint8 RIE2 : 1;
		T_uint8 RIE3 : 1;
		T_uint8 RIE4 : 1;
		T_uint8 RIE5 : 1;
		T_uint8 RIE6 : 1;
		T_uint8 RIE7 : 1;
	} bit;
} T_rier;

/**
 *	@brief		The address detection control register (PACSR) enables
 * 				or disables output of an interrupt at an address match.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8      : 1;
		T_uint8 AD0E : 1;
		T_uint8      : 1;
		T_uint8 AD1E : 1;
		T_uint8      : 4;
	} bit;
} T_pacsr;

/**
 *	@brief		The delayed interrupt request generate/cancel register
 * 				(DIRR) generates or cancels a delayed interrupt request.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 R0 : 1;
		T_uint8    : 7;
	} bit;
} T_dirr;

/**
 *	@brief		The low-power consumption mode control register (LPMCR)
 * 				transits an operation mode to and cancels the low-power
 * 				consumption modes, generates an internal reset signal,
 * 				and sets the halt cycle count in the CPU intermittent
 * 				operation mode.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8     : 1;
		T_uint8 CG  : 2;
		T_uint8 TMD : 1;
		T_uint8 RST : 1;
		T_uint8 SPL : 1;
		T_uint8 SLP : 1;
		T_uint8 STP : 1;
	} bit;
	struct {
		T_uint8        : 6;
		T_uint8 SLPSTP : 2;
	} bitc;
} T_lpmcr;

/**
 *	@brief		The clock select register (CKSCR) switches between
 *  			the main clock, subclock, and PLL clock, selects
 *  			the oscillation stabilization wait time and the
 * 				multiplication rate of PLL clock.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 CS  : 2;
		T_uint8 MCS : 1;
		T_uint8 SCS : 1;
		T_uint8 WS  : 2;
		T_uint8 MCM : 1;
		T_uint8 SCM : 1;
	} bit;
} T_ckscr;

/**
 *	@brief		The watchdog timer control register starts and clears
 * 				the watchdog timer, sets the interval time, and holds
 * 				reset factors.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 WT   : 2;
		T_uint8 WTE  : 1;
		T_uint8 SRST : 1;
		T_uint8 ERST : 1;
		T_uint8 WRST : 1;
		T_uint8      : 1;
		T_uint8 PONR : 1;
	} bit;
} T_wdtc;

/**
 *	@brief		The timebase timer control register (TBTC) provides
 * 				(1) selecting the interval time of the timebase timer,
 * 				(2) clearing the count value of the timebase timer
 * 				(3) enabling or disabling the interrupt request when an
 * 				overflow occurs, and (4) checking and clearing the state
 * 				of the interrupt request flag when an overflow occurs.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 TBC  : 2;
		T_uint8 TBR  : 1;
		T_uint8 TBOF : 1;
		T_uint8 TBIE : 1;
		T_uint8      : 3;
	} bit;
} T_tbtc;

/**
 *	@brief		The watch timer is a 15-bit free-run counter that
 * 				increments in synchronization with the subclock.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 WTC  : 3;
		T_uint8 WTR  : 1;
		T_uint8 WTOF : 1;
		T_uint8 WTIE : 1;
		T_uint8 SCE  : 1;
		T_uint8 WDCS : 1;
	} bit;
} T_wtc;

/**
 *	@brief		The flash memory control status register (FMCS)
 * 				contains flash memory programming/erasing status,
 * 				enablers and interrupt enablers.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8        : 4;
		T_uint8 RDY    : 1;
		T_uint8 WE     : 1;
		T_uint8 RDYINT : 1;
		T_uint8 INTE   : 1;
	} bit;
} T_fmcs;

/**
 *	@brief		The interrupt control registers are allocated
 * 				in the interrupt controller, and correspond to all
 * 				resources with interrupt functions.
 */
typedef union {
	T_uint8 byte;
	union {
		struct {
			T_uint8 IL  : 3;
			T_uint8 ISE : 1;
			T_uint8 ICS : 4;
		} write;
		struct {
			T_uint8 IL  : 3;
			T_uint8 ISE : 1;
			T_uint8 S   : 2;
			T_uint8     : 2;
		} read;
	} bit;
} T_icr;

/**
 *	@brief		The EI2OS descriptor (ISD) is allocated to the addresses
 * 				"000100H" to "00017FH" in the internal RAM, and consists
 * 				of 8 bytes × 16 channels.
 */
typedef struct {
	T_uint16 BAPML;
	T_uint8 BAPH;
	union {
		T_uint8 byte;
		struct {
			T_uint8 SE  : 1;
			T_uint8 DIR : 1;
			T_uint8 BF  : 1;
			T_uint8 BW  : 1;
			T_uint8 IF  : 1;
			T_uint8     : 3;
		} bit;
	} ISCS;
	T_uint16 IOA;
	T_uint16 DCT;
} T_isd;

/**
 *	@brief		The value of an address to be detected is set in the
 * 				detect address setting registers.
 */
typedef struct {
	T_uint8 LOW;
	T_uint8 MID;
	T_uint8 HIGH;
} T_padr;

/**
 *	@brief		The value (reload value) from which the PPG down
 * 				counter starts counting is set in the PPG reload
 * 				registers, which are an 8-bit register at "L" level
 * 				and an 8-bit register at "H" level.
 */
typedef union {
	T_uint32 dword;
	struct {
		T_uint32 PRL0  : 16;
		T_uint32 PRL1  : 16;
	} word;
	struct {
		T_uint32 PRLL0 : 8;
		T_uint32 PRLH0 : 8;
		T_uint32 PRLL1 : 8;
		T_uint32 PRLH1 : 8;
	} byte;
} T_prl01;

/**
 *	@brief		The value (reload value) from which the PPG down
 * 				counter starts counting is set in the PPG reload
 * 				registers, which are an 8-bit register at "L" level
 * 				and an 8-bit register at "H" level.
 */
typedef union {
	T_uint32 dword;
	struct {
		T_uint32 PRL2  : 16;
		T_uint32 PRL3  : 16;
	} word;
	struct {
		T_uint32 PRLL2 : 8;
		T_uint32 PRLH2 : 8;
		T_uint32 PRLL3 : 8;
		T_uint32 PRLH3 : 8;
	} byte;
} T_prl23;

/**
 * 	@struct		T_canid_ram
 *	@brief		CAN RAM.
 */
typedef struct {
	T_uint8 RAM[16];
} T_canid_ram;

/**
 *	@brief		The ID register (IDR) sets the ID of the message buffer
 * 				used for transmitting and receiving. In the standard
 * 				frame format, 11 bits from ID28 to ID18 are used, and
 * 				in the extended frame format, 29 bits from ID28 to ID0
 * 				are used.
 */
typedef union {
	T_uint32 dword;
	struct {
		T_uint32 ID21 : 1;
		T_uint32 ID22 : 1;
		T_uint32 ID23 : 1;
		T_uint32 ID24 : 1;
		T_uint32 ID25 : 1;
		T_uint32 ID26 : 1;
		T_uint32 ID27 : 1;
		T_uint32 ID28 : 1;
		T_uint32 ID13 : 1;
		T_uint32 ID14 : 1;
		T_uint32 ID15 : 1;
		T_uint32 ID16 : 1;
		T_uint32 ID17 : 1;
		T_uint32 ID18 : 1;
		T_uint32 ID19 : 1;
		T_uint32 ID20 : 1;
		T_uint32 ID5  : 1;
		T_uint32 ID6  : 1;
		T_uint32 ID7  : 1;
		T_uint32 ID8  : 1;
		T_uint32 ID9  : 1;
		T_uint32 ID10 : 1;
		T_uint32 ID11 : 1;
		T_uint32 ID12 : 1;
		T_uint32      : 3;
		T_uint32 ID0  : 1;
		T_uint32 ID1  : 1;
		T_uint32 ID2  : 1;
		T_uint32 ID3  : 1;
		T_uint32 ID4  : 1;
	} bit;
} T_canid_idr;

/**
 *	@brief		The DLC register (DLCR) sets the data length of the
 * 				message to be transmitted or received.
 */
typedef union {
	T_uint16 word;
	T_uint16 DLC : 4;
} T_canid_dlcr;

/**
 *	@brief		The data register (DTR) sets the messages at
 * 				transmitting or receiving a data frame (0 to 8 bytes).
 * 	@note		When setting the data register (DTR), write by words.
 * 				Writing by bytes is disabled.
 */
typedef union {
	T_float64 DOUBLE   ;
	T_float32 FLOAT [2];
	T_uint32  DWORD [2];
	T_uint16  WORD  [4];
	T_uint8   BYTE  [8];
} T_canid_dtr;

/**
 *	@brief		Bundled IO Structure of CAN IDR, CAN DLCR and CAN DTR.
 */
typedef struct {
	T_canid_ram  RAM    ;
	T_canid_idr  IDR [8];
	T_canid_dlcr DLCR[8];
	T_canid_dtr  DTR [8];
} T_canid;

/**
 *	@brief		The control status register (CSR) controls operation of
 * 				the CAN controller.
 * 	@note		The control status register (High) (CSR: H) transmits and
 * 				receives the message and indicates the node status. The
 * 				control status register (CSR) controls operation of the
 * 				CAN controller. The control status register (Low) (CSR: L)
 * 				enables and disables transmit interrupt and node status
 * 				transition interrupt, controls bus halt and indicates the
 * 				node status.
 */
typedef union {
	T_uint16 word;
	struct {
		T_uint16 HALT: 1;
		T_uint16     : 1;
		T_uint16 NIE : 1;
		T_uint16     : 4;
		T_uint16 TOE : 1;
		T_uint16 NS  : 2;
		T_uint16 NT  : 1;
		T_uint16     : 3;
		T_uint16 RS  : 1;
		T_uint16 TS  : 1;
	} bit;
} T_canct_csr;

/**
 *	@brief		This register indicates the state of the last event.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 MBP : 3;
		T_uint8     : 2;
		T_uint8 RCE : 1;
		T_uint8 TCE : 1;
		T_uint8 NTE : 1;
	} bit;
} T_canct_leir;

/**
 *	@brief		The receive/transmit error counter (RTEC) indicates
 * 				the number of times an error occurs at transmitting and
 * 				receiving the message.
 */
typedef struct {
	T_uint8 REC;
	T_uint8 TEC;
} T_canct_rtec;

/**
 *	@brief		The bit timing register (BTR) sets the prescaler and
 * 				bit timing after halting the bus (CSR: HALT = 1).
 */
typedef union {
	T_uint16 word;
	struct {
		T_uint16 PSC : 6;
		T_uint16 RSJ : 2;
		T_uint16 TS1 : 4;
		T_uint16 TS2 : 3;
		T_uint16     : 1;
	} bit;
} T_canct_btr;

/**
 *	@brief		The IDE register (IDER) sets the frame format, either
 *  			standard frame format (ID11 bits) and the extended frame
 *  			format (ID29 bits), of the message buffer used during
 *  			transmitting and receiving.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 IDE0 : 1;
		T_uint8 IDE1 : 1;
		T_uint8 IDE2 : 1;
		T_uint8 IDE3 : 1;
		T_uint8 IDE4 : 1;
		T_uint8 IDE5 : 1;
		T_uint8 IDE6 : 1;
		T_uint8 IDE7 : 1;
	} bit;
} T_canct_ider;

/**
 *	@brief		This register sets the frame format of transmit message
 * 				for the message buffers.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 TRTR0 : 1;
		T_uint8 TRTR1 : 1;
		T_uint8 TRTR2 : 1;
		T_uint8 TRTR3 : 1;
		T_uint8 TRTR4 : 1;
		T_uint8 TRTR5 : 1;
		T_uint8 TRTR6 : 1;
		T_uint8 TRTR7 : 1;
	} bit;
} T_canct_trtrr;

/**
 *	@brief		Remote frame receiving wait register (RFWTR) sets
 * 				whether this register waits remote frame receiving
 * 				when transmission request of data frame is set.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 RFWT0 : 1;
		T_uint8 RFWT1 : 1;
		T_uint8 RFWT2 : 1;
		T_uint8 RFWT3 : 1;
		T_uint8 RFWT4 : 1;
		T_uint8 RFWT5 : 1;
		T_uint8 RFWT6 : 1;
		T_uint8 RFWT7 : 1;
	} bit;
} T_canct_rfwtr;

/**
 *	@brief		The transmission complete interrupt enable register
 * 				(TIER) enables or disables a transmit complete
 * 				interrupt for each message buffer.
 */
typedef union {
	T_uint8 byte;
	struct {
		T_uint8 TIE0 : 1;
		T_uint8 TIE1 : 1;
		T_uint8 TIE2 : 1;
		T_uint8 TIE3 : 1;
		T_uint8 TIE4 : 1;
		T_uint8 TIE5 : 1;
		T_uint8 TIE6 : 1;
		T_uint8 TIE7 : 1;
	} bit;
} T_canct_tier;

/**
 *	@brief		The acceptance mask select register (AMSR) selects
 * 				the mask (acceptance mask) format for comparison
 * 				between the identifier (ID) of the received message
 * 				and the message buffer.
 */
typedef union {
	T_uint16 word;
	struct {
		T_uint16 AMS0 : 2;
		T_uint16 AMS1 : 2;
		T_uint16 AMS2 : 2;
		T_uint16 AMS3 : 2;
		T_uint16 AMS4 : 2;
		T_uint16 AMS5 : 2;
		T_uint16 AMS6 : 2;
		T_uint16 AMS7 : 2;
	} bit;
} T_canct_amsr;

/**
 *	@brief		The CAN controller has two acceptance mask registers
 * 				(AMR0 and AMR1). Both of them can be used in the standard
 * 				frame format (ID11 bits, AM28 to AM18) and the extended
 * 				frame format (ID29 bits, AM28 to AM0).
 */
typedef union {
	T_uint32 dword;
	struct {
		T_uint32 AM21 : 1;
		T_uint32 AM22 : 1;
		T_uint32 AM23 : 1;
		T_uint32 AM24 : 1;
		T_uint32 AM25 : 1;
		T_uint32 AM26 : 1;
		T_uint32 AM27 : 1;
		T_uint32 AM28 : 1;
		T_uint32 AM13 : 1;
		T_uint32 AM14 : 1;
		T_uint32 AM15 : 1;
		T_uint32 AM16 : 1;
		T_uint32 AM17 : 1;
		T_uint32 AM18 : 1;
		T_uint32 AM19 : 1;
		T_uint32 AM20 : 1;
		T_uint32 AM5  : 1;
		T_uint32 AM6  : 1;
		T_uint32 AM7  : 1;
		T_uint32 AM8  : 1;
		T_uint32 AM9  : 1;
		T_uint32 AM10 : 1;
		T_uint32 AM11 : 1;
		T_uint32 AM12 : 1;
		T_uint32      : 3;
		T_uint32 AM0  : 1;
		T_uint32 AM1  : 1;
		T_uint32 AM2  : 1;
		T_uint32 AM3  : 1;
		T_uint32 AM4  : 1;
	} bit;
} T_canct_amr0;

/**
 *	@brief		The CAN controller has two acceptance mask registers
 * 				(AMR0 and AMR1). Both of them can be used in the standard
 * 				frame format (ID11 bits, AM28 to AM18) and the extended
 * 				frame format (ID29 bits, AM28 to AM0).
 */
typedef union {
	T_uint32 dword;
	struct {
		T_uint32 AM21 : 1;
		T_uint32 AM22 : 1;
		T_uint32 AM23 : 1;
		T_uint32 AM24 : 1;
		T_uint32 AM25 : 1;
		T_uint32 AM26 : 1;
		T_uint32 AM27 : 1;
		T_uint32 AM28 : 1;
		T_uint32 AM13 : 1;
		T_uint32 AM14 : 1;
		T_uint32 AM15 : 1;
		T_uint32 AM16 : 1;
		T_uint32 AM17 : 1;
		T_uint32 AM18 : 1;
		T_uint32 AM19 : 1;
		T_uint32 AM20 : 1;
		T_uint32 AM5  : 1;
		T_uint32 AM6  : 1;
		T_uint32 AM7  : 1;
		T_uint32 AM8  : 1;
		T_uint32 AM9  : 1;
		T_uint32 AM10 : 1;
		T_uint32 AM11 : 1;
		T_uint32 AM12 : 1;
		T_uint32      : 3;
		T_uint32 AM0  : 1;
		T_uint32 AM1  : 1;
		T_uint32 AM2  : 1;
		T_uint32 AM3  : 1;
		T_uint32 AM4  : 1;
	} bit;
} T_canct_amr1;

/**
 *	@brief		Bundled IO Structure of CAN CSR, CAN LEIR, CAN RTEC
 *  			CAN BTR, CAN IDER, CAN TRTRR, CAN RFWTR, CAN TIER,
 *  			CAN AMSR, CAN AMR0 and CAN AMR1.
 */
typedef struct {
	T_canct_csr		CSR;
	T_canct_leir	LEIR;
	T_uint8			: 8;
	T_canct_rtec	RTEC;
	T_canct_btr		BTR;
	T_canct_ider	IDER;
	T_uint8 		: 8;
	T_canct_trtrr	TRTRR;
	T_uint8 		: 8;
	T_canct_rfwtr	RFWTR;
	T_uint8 		: 8;
	T_canct_tier	TIER;
	T_uint8 		: 8;
	T_canct_amsr	AMSR;
	T_uint16 		: 16;
	T_canct_amr0	AMR0;
	T_canct_amr1	AMR1;
} T_canct;

/* ----------------------------------------------------------------------------
**	IO Registers Getters and Setters.
*/

/* IOREG getters */

/**
 * 	@def		GetIOREG
 * 	@brief		IO Register Generic Getter.
 *	@param		REG		The IO register name or data structure.
 * 	@return		IO register (itself).
 */
#define GetIOREG(REG)							(REG)

/**
 * 	@def		GetIOREGVar
 * 	@brief		IO Register Variable Getter.
 *	@param		REG		The IO register name or data structure.
 *	@param		VAR		The IO register variable member (union or struct).
 * 	@return		IO register multi-size member access.
 */
#define GetIOREGVar(REG, VAR)					((REG).VAR)

/**
 * 	@def		GetIOREGBit
 * 	@brief		IO Register Bit Getter.
 *	@param		REG		The IO register name or data structure.
 * 	@return		IO register bit access (bits).
 */
#define GetIOREGBit(REG)						((REG).bit)

/**
 * 	@def		GetIOREGByte
 * 	@brief		IO Register Byte Getter.
 *	@param		REG		The IO register name or data structure.
 * 	@return		IO register byte access (byte).
 */
#define GetIOREGByte(REG)						((REG).byte)

/**
 * 	@def		GetIOREGWord
 * 	@brief		IO Register Word Getter.
 *	@param		REG		The IO register name or data structure.
 * 	@return		IO register word access (word).
 */
#define GetIOREGWord(REG)						((REG).word)

/**
 * 	@def		GetIOREGDWord
 * 	@brief		IO Register DWord Getter.
 *	@param		REG		The IO register name or data structure.
 * 	@return		IO register double word access (dword).
 */
#define GetIOREGDWord(REG)						((REG).dword)

/**
 * 	@def		GetIOREGBitVar
 * 	@brief		IO Register Bit Member Getter.
 *	@param		REG		The IO register name or data structure.
 *	@param		VAR		The IO register bit member (union or struct).
 * 	@return		IO register bit member access (bits).
 */
#define GetIOREGBitVar(REG, VAR)				((REG).bit.VAR)

/**
 * 	@def		GetIOREGByteVar
 * 	@brief		IO Register Byte Member Getter.
 *	@param		REG		The IO register name or data structure.
 *	@param		VAR		The IO register byte member (union or struct).
 * 	@return		IO register byte member access (byte).
 */
#define GetIOREGByteVar(REG, VAR)				((REG).byte.VAR)

/**
 * 	@def		GetIOREGWordVar
 * 	@brief		IO Register Word Member Getter.
 *	@param		REG		The IO register name or data structure.
 *	@param		VAR		The IO register word member (union or struct).
 * 	@return		IO register word member access (word).
 */
#define GetIOREGWordVar(REG, VAR)				((REG).word.VAR)

/**
 * 	@def		GetIOREGDWordVar
 * 	@brief		IO Register DWord Member Getter.
 *	@param		REG		The IO register name or data structure.
 *	@param		VAR		The IO register dword member (union or struct).
 * 	@return		IO register double word member access (dword).
 */
#define GetIOREGDWordVar(REG, VAR)				((REG).dword.VAR)

/**
 * 	@def		GetIOSSREG
 * 	@brief		IO Super Structure Register Generic Getter.
 *	@param		SS		The IO super data structure.
 *	@param		REG		The IO register name or data structure.
 * 	@return		IO register (itself).
 */
#define GetIOSSREG(SS, REG)						((SS).REG)

/**
 * 	@def		GetIOSSREGVar
 * 	@brief		IO Super Structure Register Variable Getter.
 *	@param		SS		The IO super data structure.
 *	@param		REG		The IO register name or data structure.
 *	@param		VAR		The IO register variable member (union or struct).
 * 	@return		IO register multi-size member access.
 */
#define GetIOSSREGVar(SS, REG, VAR)				((SS).REG.VAR)

/**
 * 	@def		GetIOSSREGBit
 * 	@brief		IO Super Structure Register Bit Getter.
 *	@param		SS		The IO super data structure.
 *	@param		REG		The IO register name or data structure.
 * 	@return		IO register bit access (bits).
 */
#define GetIOSSREGBit(SS, REG)					((SS).REG.bit)

/**
 * 	@def		GetIOSSREGByte
 * 	@brief		IO Super Structure Register Byte Getter.
 *	@param		SS		The IO super data structure.
 *	@param		REG		The IO register name or data structure.
 * 	@return		IO register byte access (byte).
 */
#define GetIOSSREGByte(SS, REG)					((SS).REG.byte)

/**
 * 	@def		GetIOSSREGWord
 * 	@brief		IO Super Structure Register Word Getter.
 *	@param		SS		The IO super data structure.
 *	@param		REG		The IO register name or data structure.
 * 	@return		IO register word access (word).
 */
#define GetIOSSREGWord(SS, REG)					((SS).REG.word)

/**
 * 	@def		GetIOSSREGDWord
 * 	@brief		IO Super Structure Register DWord Getter.
 *	@param		SS		The IO super data structure.
 *	@param		REG		The IO register name or data structure.
 * 	@return		IO register double word access (dword).
 */
#define GetIOSSREGDWord(SS, REG)				((SS).REG.dword)

/**
 * 	@def		GetIOSSREGBitVar
 * 	@brief		IO Super Structure Register Bit Member Getter.
 *	@param		SS		The IO super data structure.
 *	@param		REG		The IO register name or data structure.
 *	@param		VAR		The IO register bit member (union or struct).
 * 	@return		IO register bit member access (bits).
 */
#define GetIOSSREGBitVar(SS, REG, VAR)			((SS).REG.bit.VAR)

/**
 * 	@def		GetIOSSREGByteVar
 * 	@brief		IO Super Structure Register Byte Member Getter.
 *	@param		SS		The IO super data structure.
 *	@param		REG		The IO register name or data structure.
 *	@param		VAR		The IO register byte member (union or struct).
 * 	@return		IO register byte member access (byte).
 */
#define GetIOSSREGByteVar(SS, REG, VAR)			((SS).REG.byte.VAR)

/**
 * 	@def		GetIOSSREGWordVar
 * 	@brief		IO Super Structure Register Word Member Getter.
 *	@param		SS		The IO super data structure.
 *	@param		REG		The IO register name or data structure.
 *	@param		VAR		The IO register word member (union or struct).
 * 	@return		IO register word member access (word).
 */
#define GetIOSSREGWordVar(SS, REG, VAR)			((SS).REG.word.VAR)

/**
 * 	@def		GetIOSSREGDWordVar
 * 	@brief		IO Super Structure Register DWord Member Getter.
 *	@param		SS		The IO super data structure.
 *	@param		REG		The IO register name or data structure.
 *	@param		VAR		The IO register dword member (union or struct).
 * 	@return		IO register double word member access (dword).
 */
#define GetIOSSREGDWordVar(SS, REG, VAR)		((SS).REG.dword.VAR)

/* IOREG setters */

/**
 * 	@def		SetIOREG
 * 	@brief		IO Register Generic Setter.
 *	@param		REG		The IO register name or data structure.
 *	@param[in]	VAL		Control, status or selection data.
 * 	@return		.
 */
#define SetIOREG(REG, VAL) { \
	(REG) = (VAL); \
}

/**
 * 	@def		SetIOREGVar
 * 	@brief		IO Register Variable Setter.
 *	@param		REG		The IO register name or data structure.
 *	@param		VAR		The IO register variable member (union or struct).
 *	@param[in]	VAL		Control, status or selection data.
 * 	@return		.
 */
#define SetIOREGVar(REG, VAR, VAL) { \
	((REG).VAR) = (VAL); \
}

/**
 * 	@def		SetIOREGBit
 * 	@brief		IO Register Bit Setter.
 *	@param		REG		The IO register name or data structure.
 *	@param[in]	VAL		Control, status or selection bit, flag, state or choice.
 * 	@return		.
 */
#define SetIOREGBit(REG, VAL) { \
	((REG).bit) = (T_bit)(VAL); \
}

/**
 * 	@def		SetIOREGByte
 * 	@brief		IO Register Byte Setter.
 *	@param		REG		The IO register name or data structure.
 *	@param[in]	VAL		Control, status or selection bits, flags, states or choices.
 * 	@return		.
 */
#define SetIOREGByte(REG, VAL) { \
	((REG).byte) = (T_byte)(VAL); \
}

/**
 * 	@def		SetIOREGWord
 * 	@brief		IO Register Word Setter.
 *	@param		REG		The IO register name or data structure.
 *	@param[in]	VAL		Control, status or selection bits, flags, states or choices.
 * 	@return		.
 */
#define SetIOREGWord(REG, VAL) { \
	((REG).word) = (T_word)(VAL); \
}

/**
 * 	@def		SetIOREGDWord
 * 	@brief		IO Register DWord Setter.
 *	@param		REG		The IO register name or data structure.
 *	@param[in]	VAL		Control, status or selection bits, flags, states or choices.
 * 	@return		.
 */
#define SetIOREGDWord(REG, VAL) { \
	((REG).dword) = (T_dword)(VAL); \
}

/**
 * 	@def		SetIOREGBitVar
 * 	@brief		IO Register Bit Member Setter.
 *	@param		REG		The IO register name or data structure.
 *	@param		VAR		The IO register bit member (union or struct).
 *	@param[in]	VAL		Control, status or selection bit, flag, state or choice.
 * 	@return		.
 */
#define SetIOREGBitVar(REG, VAR, VAL) { \
	((REG).bit.VAR) = (T_bit)(VAL); \
}

/**
 * 	@def		SetIOREGByteVar
 * 	@brief		IO Register Byte Member Setter.
 *	@param		REG		The IO register name or data structure.
 *	@param		VAR		The IO register byte member (union or struct).
 *	@param[in]	VAL		Control, status or selection bits, flags, states or choices.
 * 	@return		.
 */
#define SetIOREGByteVar(REG, VAR, VAL) { \
	((REG).byte.VAR) = (T_byte)(VAL); \
}

/**
 * 	@def		SetIOREGWordVar
 * 	@brief		IO Register Word Member Setter.
 *	@param		REG		The IO register name or data structure.
 *	@param		VAR		The IO register word member (union or struct).
 *	@param[in]	VAL		Control, status or selection bits, flags, states or choices.
 * 	@return		.
 */
#define SetIOREGWordVar(REG, VAR, VAL) { \
	((REG).word.VAR) = (T_word)(VAL); \
}

/**
 * 	@def		SetIOREGDWordVar
 * 	@brief		IO Register DWord Member Setter.
 *	@param		REG		The IO register name or data structure.
 *	@param		VAR		The IO register dword member (union or struct).
 *	@param[in]	VAL		Control, status or selection bits, flags, states or choices.
 * 	@return		.
 */
#define SetIOREGDWordVar(REG, VAR, VAL) { \
	((REG).dword.VAR) = (T_dword)(VAL); \
}

/**
 * 	@def		SetIOSSREG
 * 	@brief		IO Register Generic Setter.
 *	@param		SS		The IO super data structure.
 *	@param		REG		The IO register name or data structure.
 *	@param[in]	VAL		Control, status or selection data.
 * 	@return		.
 */
#define SetIOSSREG(SS, REG, VAL) { \
	((SS).REG) = (VAL); \
}

/**
 * 	@def		SetIOSSREGVar
 * 	@brief		IO Register Variable Setter.
 *	@param		SS		The IO super data structure.
 *	@param		REG		The IO register name or data structure.
 *	@param		VAR		The IO register variable member (union or struct).
 *	@param[in]	VAL		Control, status or selection data.
 * 	@return		.
 */
#define SetIOSSREGVar(SS, REG, VAR, VAL) { \
	((SS).REG.VAR) = (VAL); \
}

/**
 * 	@def		SetIOSSREGBit
 * 	@brief		IO Register Bit Setter.
 *	@param		SS		The IO super data structure.
 *	@param		REG		The IO register name or data structure.
 *	@param[in]	VAL		Control, status or selection bit, flag, state or choice.
 * 	@return		.
 */
#define SetIOSSREGBit(SS, REG, VAL) { \
	((SS).REG.bit) = (T_bit)(VAL); \
}

/**
 * 	@def		SetIOSSREGByte
 * 	@brief		IO Register Byte Setter.
 *	@param		SS		The IO super data structure.
 *	@param		REG		The IO register name or data structure.
 *	@param[in]	VAL		Control, status or selection bits, flags, states or choices.
 * 	@return		.
 */
#define SetIOSSREGByte(SS, REG, VAL) { \
	((SS).REG.byte) = (T_byte)(VAL); \
}

/**
 * 	@def		SetIOSSREGWord
 * 	@brief		IO Register Word Setter.
 *	@param		SS		The IO super data structure.
 *	@param		REG		The IO register name or data structure.
 *	@param[in]	VAL		Control, status or selection bits, flags, states or choices.
 * 	@return		.
 */
#define SetIOSSREGWord(SS, REG, VAL) { \
	((SS).REG.word) = (T_word)(VAL); \
}

/**
 * 	@def		SetIOSSREGDWord
 * 	@brief		IO Register DWord Setter.
 *	@param		SS		The IO super data structure.
 *	@param		REG		The IO register name or data structure.
 *	@param[in]	VAL		Control, status or selection bits, flags, states or choices.
 * 	@return		.
 */
#define SetIOSSREGDWord(SS, REG, VAL) { \
	((SS).REG.dword) = (T_dword)(VAL); \
}

/**
 * 	@def		SetIOSSREGBitVar
 * 	@brief		IO Register Bit Member Setter.
 *	@param		SS		The IO super data structure.
 *	@param		REG		The IO register name or data structure.
 *	@param		VAR		The IO register bit member (union or struct).
 *	@param[in]	VAL		Control, status or selection bits, flags, states or choices.
 * 	@return		.
 */
#define SetIOSSREGBitVar(SS, REG, VAR, VAL) { \
	((SS).REG.bit.VAR) = (T_bit)(VAL); \
}

/**
 * 	@def		SetIOSSREGByteVar
 * 	@brief		IO Register Byte Member Setter.
 *	@param		SS		The IO super data structure.
 *	@param		REG		The IO register name or data structure.
 *	@param		VAR		The IO register byte member (union or struct).
 *	@param[in]	VAL		Control, status or selection bits, flags, states or choices.
 * 	@return		.
 */
#define SetIOSSREGByteVar(SS, REG, VAR, VAL) { \
	((SS).REG.byte.VAR) = (T_byte)(VAL); \
}

/**
 * 	@def		SetIOSSREGWordVar
 * 	@brief		IO Register Word Member Setter.
 *	@param		SS		The IO super data structure.
 *	@param		REG		The IO register name or data structure.
 *	@param		VAR		The IO register word member (union or struct).
 *	@param[in]	VAL		Control, status or selection bits, flags, states or choices.
 * 	@return		.
 */
#define SetIOSSREGWordVar(SS, REG, VAR, VAL) { \
	((SS).REG.word.VAR) = (T_word)(VAL); \
}

/**
 * 	@def		SetIOSSREGDWordVar
 * 	@brief		IO Register DWord Member Setter.
 *	@param		SS		The IO super data structure.
 *	@param		REG		The IO register name or data structure.
 *	@param		VAR		The IO register dword member (union or struct).
 *	@param[in]	VAL		Control, status or selection bits, flags, states or choices.
 * 	@return		.
 */
#define SetIOSSREGDWordVar(SS, REG, VAR, VAL) { \
	((SS).REG.dword.VAR) = (T_dword)(VAL); \
}

#endif /* IO_STRUCTS_H. */
