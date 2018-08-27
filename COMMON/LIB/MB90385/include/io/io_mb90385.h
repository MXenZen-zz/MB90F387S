/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* MB90385 Series IO Data and Register Variables Export			 		     */
/**
 *	@file		IO/io_mb90385.h
 *	@brief		This file contains exports of IO data and register variables
 *				of F2MC-16LX MB90385 Series MB90F387S.
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

#ifndef IO_MB90385_H
#define IO_MB90385_H

#include <IO/io_structs.h>

/* ----------------------------------------------------------------------------
**	IO External Variables.
*/

#ifndef IO_DEFINE

/**
 *	@var 		IO_PDR1
 *	@brief  	Port 1 Data Register.
 */
extern IO T_pdr1 IO_PDR1;				/* address 01h */

/**
 *	@var 		IO_PDR2
 *	@brief  	Port 2 Data Register.
 */
extern IO T_pdr2 IO_PDR2;				/* address 02h */

/**
 *	@var 		IO_PDR3
 *	@brief  	Port 3 Data Register.
 */
extern IO T_pdr3 IO_PDR3;				/* address 03h */

/**
 *	@var 		IO_PDR4
 *	@brief  	Port 4 Data Register.
 */
extern IO T_pdr4 IO_PDR4;				/* address 04h */

/**
 *	@var 		IO_PDR5
 *	@brief  	Port 5 Data Register.
 */
extern IO T_pdr5 IO_PDR5;				/* address 05h */

/**
 *	@var 		IO_DDR1
 *	@brief  	Port 1 Direction Register.
 */
extern IO T_ddr1 IO_DDR1;				/* address 11h */

/**
 *	@var 		IO_DDR2
 *	@brief  	Port 2 Direction Register.
 */
extern IO T_ddr2 IO_DDR2;				/* address 12h */

/**
 *	@var 		IO_DDR3
 *	@brief  	Port 3 Direction Register.
 */
extern IO T_ddr3 IO_DDR3;				/* address 13h */

/**
 *	@var 		IO_DDR4
 *	@brief  	Port 4 Direction Register.
 */
extern IO T_ddr4 IO_DDR4;				/* address 14h */

/**
 *	@var 		IO_DDR5
 *	@brief  	Port 5 Direction Register.
 */
extern IO T_ddr5 IO_DDR5;				/* address 15h */

/**
 *	@var 		IO_ADER
 *	@brief  	Analog Input Enable Register.
 */
extern IO T_ader IO_ADER;				/* address 1Bh */

/**
 *	@var 		IO_SMR1
 *	@brief  	Serial Mode Register.
 */
extern IO T_smr IO_SMR1;				/* address 26h */

/**
 *	@var 		IO_SCR1
 *	@brief  	Serial Control Register.
 */
extern IO T_scr IO_SCR1;				/* address 27h */

/**
 *	@var 		IO_SIODR1
 *	@brief  	Serial Input / Output Data Register.
 */
extern IO T_siodr IO_SIODR1;			/* address 28h */

/**
 *	@var 		IO_SSR1
 *	@brief  	Serial Status Register.
 */
extern IO T_ssr IO_SSR1;				/* address 29h */

/**
 *	@var 		IO_CDCR1
 *	@brief  	Communication Prescaler Control Register.
 */
extern IO T_cdcr IO_CDCR1;				/* address 2Bh */

/**
 *	@var 		IO_ENIR
 *	@brief  	External Interrupt Enable Register.
 */
extern IO T_enir IO_ENIR;				/* address 30h */

/**
 *	@var 		IO_EIRR
 *	@brief  	External Interrupt Condition Register.
 */
extern IO T_eirr IO_EIRR;				/* address 31h */

/**
 *	@var 		IO_ELVR
 *	@brief  	Detection Level Config Register.
 */
extern IO T_elvr IO_ELVR;				/* address 32-33h */

/**
 *	@var 		IO_ADCSL
 *	@brief  	A/D Control Status Register.
 */
extern IO T_adcsl IO_ADCSL;				/* address 34h */

/**
 *	@var 		IO_ADCSH
 *	@brief  	A/D Control Status Register.
 *	@note		Always write 0 to reserved bit.
 */
extern IO T_adcsh IO_ADCSH;				/* address 35h */

/**
 *	@var 		IO_ADCRLH
 *	@brief  	A/D Data Register.
 */
extern IO T_adcrlh IO_ADCRLH;			/* address 36-37h */

/**
 *	@var 		IO_PPGC01
 *	@brief  	PPG Operation Mode Control Register.
 *	@note		When using a simple assignment statement to write
 *				data to PPGC01 (member IO_PPGC01.word), be sure to
 *				write 1 to reserved bit(s).
 */
extern IO T_ppgc IO_PPGC01;				/* address 40-41h */

/**
 *	@var 		IO_PPG01
 *	@brief  	PPG Count Clock Selection Register.
 */
extern IO T_ppg IO_PPG01;				/* address 42h */

/**
 *	@var 		IO_PPGC23
 *	@brief  	PPG Operation Mode Control Register.
 *	@note		When using a simple assignment statement to write
 *				data to PPGC23 (member IO_PPGC23.word), be sure to
 *				write 1 to reserved bit(s).
 */
extern IO T_ppgc IO_PPGC23;				/* address 44-45h */

/**
 *	@var 		IO_PPG23
 *	@brief  	PPG Count Clock Selection Register.
 */
extern IO T_ppg IO_PPG23;				/* address 46h */

/**
 *	@var 		IO_IPCP0
 *	@brief  	Reserved Area.
 */
extern IO const T_uint16 IO_IPCP0;		/* address 50-51h */

/**
 *	@var 		IO_IPCP1
 *	@brief  	Reserved Area.
 */
extern IO const T_uint16 IO_IPCP1;		/* address 52-53h */

/**
 *	@var 		IO_ICS01
 *	@brief  	Input Capture Control Status Register.
 */
extern IO T_ics IO_ICS01;				/* address 54h */

/**
 *	@var 		IO_ICS23
 *	@brief  	Input Capture Control Status Register.
 */
extern IO T_ics IO_ICS23;				/* address 55h */

/**
 *	@var 		IO_TCDT
 *	@brief  	Timer Counter Data Register.
 */
extern IO T_uint16 IO_TCDT;				/* address 56-57h */

/**
 *	@var 		IO_TCCS
 *	@brief  	Timer Counter Control Status Register.
 */
extern IO T_tccs IO_TCCS;				/* address 58h */

/**
 *	@var 		IO_IPCP2
 *	@brief  	Input Capture Data Register.
 */
extern IO const T_uint16 IO_IPCP2;		/* address 5A-5Bh */

/**
 *	@var 		IO_IPCP3
 *	@brief  	Input Capture Data Register.
 */
extern IO const T_uint16 IO_IPCP3;		/* address 5C-5Dh */

/**
 *	@var 		IO_TMCSR0
 *	@brief  	Timer Control Status Register.
 */
extern IO T_tmcsr IO_TMCSR0;			/* address 66-67h */

/**
 *	@var 		IO_TMCSR1
 *	@brief  	Timer Control Status Register.
 */
extern IO T_tmcsr IO_TMCSR1;			/* address 68-69h */

/**
 *	@var 		IO_ROMM
 *	@brief  	ROM Mirror Function Selection Register.
 */
extern IO T_romm IO_ROMM;				/* address 6Fh */

/**
 *	@var 		IO_BVALR
 *	@brief  	Message Buffer Valid Register.
 */
extern IO T_bvalr IO_BVALR;				/* address 80h */

/**
 *	@var 		IO_TREQR
 *	@brief  	Send Request Register.
 */
extern IO T_treqr IO_TREQR;				/* address 82h */

/**
 *	@var 		IO_TCANR
 *	@brief  	Send Cancel Register.
 */
extern IO T_tcanr IO_TCANR;				/* address 84h */

/**
 *	@var 		IO_TCR
 *	@brief  	Send Complete Register.
 */
extern IO T_tcr IO_TCR;					/* address 86h */

/**
 *	@var 		IO_RCR
 *	@brief  	Reception Complete Register.
 */
extern IO T_rcr IO_RCR;					/* address 88h */

/**
 *	@var 		IO_RRTRR
 *	@brief  	Reception RTR Register.
 */
extern IO T_rrtrr IO_RRTRR;				/* address 8Ah */

/**
 *	@var 		IO_ROVRR
 *	@brief  	Reception Overrun Register.
 */
extern IO T_rovrr IO_ROVRR;				/* address 8Ch */

/**
 *	@var 		IO_RIER
 *	@brief  	Reception Complete Interrupt Enable.
 */
extern IO T_rier IO_RIER;				/* address 8Eh */

/**
 *	@var 		IO_PACSR
 *	@brief  	Address Detection Control Register.
 *	@note		When using a simple assignment statement to write
 *				data to PACSR (member IO_PACSR.byte), be sure to
 *				write 0 to reserved bit(s).
 */
extern IO T_pacsr IO_PACSR;				/* address 9Eh */

/**
 *	@var 		IO_DIRR
 *	@brief  	Delayed Interrupt Request / Generate Register.
 *	@note		When DIRR is accessed, bits should be operated
 * 				considering future expansion.
 */
extern IO T_dirr IO_DIRR;				/* address 9Fh */

/**
 *	@var 		IO_LPMCR
 *	@brief  	Low Power Consumption Mode Control Register.
 *	@note		Always write 0 to reserved bit of LPMCR.
 */
extern IO T_lpmcr IO_LPMCR;				/* address A0h */

/**
 *	@var 		IO_CKSCR
 *	@brief  	Clock Selection Register.
 */
extern IO T_ckscr IO_CKSCR;				/* address A1h */

/**
 *	@var 		IO_WDTC
 *	@brief  	Watchdog Timer Control Register.
 *	@note		WT and WTE of WDTC are write-only bits; members to
 *				be accessed in bits are not declared.
 */
extern IO T_wdtc IO_WDTC;				/* address A8h */

/**
 *	@var 		IO_TBTC
 *	@brief  	Timebase Timer Control Register.
 *	@note		Always write 1 to reserved bit(s).
 */
extern IO T_tbtc IO_TBTC;				/* address A9h */

/**
 *	@var 		IO_WTC
 *	@brief  	Watch Timer Register.
 */
extern IO T_wtc IO_WTC;					/* address AAh */

/**
 *	@var 		IO_FMCS
 *	@brief  	FMCS.
 *	@note		When using a simple assignment statement to write
 *				data to FMCS  (member IO_FMCS.byte), be sure to write
 *				0 to reserved bit(s).
 */
extern IO T_fmcs IO_FMCS;				/* address AEh */

/**
 *	@var 		IO_ICR00
 *	@brief  	Interrupt Control Register 00.
 *	@note		Corresponding resource is CAN controller.
 */
extern IO T_icr IO_ICR00;				/* address B0h */

/**
 *	@var 		IO_ICR01
 *	@brief  	Interrupt Control Register 01.
 */
extern IO T_icr IO_ICR01;				/* address B1h */

/**
 *	@var 		IO_ICR02
 *	@brief  	Interrupt Control Register 02.
 *	@note		Corresponding resource is shared with CAN wake-up
 *				and timebase timer.
 */
extern IO T_icr IO_ICR02;				/* address B2h */

/**
 *	@var 		IO_ICR03
 *	@brief  	Interrupt Control Register 03.
 *	@note		Corresponding resource is shared with 16-bit reload timer 0
 *				and A/D converter.
 */
extern IO T_icr IO_ICR03;				/* address B3h */

/**
 *	@var 		IO_ICR04
 *	@brief  	Interrupt Control Register 04.
 *	@note		Corresponding resource is 16-bit free-run timer overflow.
 */
extern IO T_icr IO_ICR04;				/* address B4h */

/**
 *	@var 		IO_ICR05
 *	@brief  	Interrupt Control Register 05.
 *	@note		Corresponding resource is PPG 0/1.
 */
extern IO T_icr IO_ICR05;				/* address B5h */

/**
 *	@var 		IO_ICR06
 *	@brief  	Interrupt Control Register 06.
 *	@note		Corresponding resource is shared with input capture 0
 *				and external interrupt INT4/INT5.
 */
extern IO T_icr IO_ICR06;				/* address B6h */

/**
 *	@var 		IO_ICR07
 *	@brief  	Interrupt Control Register 07.
 *	@note		Corresponding resource is shared with input capture 1
 *				and PPG 2/3.
 */
extern IO T_icr IO_ICR07;				/* address B7h */

/**
 *	@var 		IO_ICR08
 *	@brief  	Interrupt Control Register 08.
 *	@note		Corresponding resource is shared with external interrupt INT6/INT7
 *				and watch timer.
 */
extern IO T_icr IO_ICR08;				/* address B8h */

/**
 *	@var 		IO_ICR09
 *	@brief  	Interrupt Control Register 09.
 *	@note		Corresponding resource is input capture 2/3.
 */
extern IO T_icr IO_ICR09;				/* address B9h */

/**
 *	@var 		IO_ICR10
 *	@brief  	Interrupt Control Register 10.
 */
extern IO T_icr IO_ICR10;				/* address BAh */

/**
 *	@var 		IO_ICR11
 *	@brief  	Interrupt Control Register 11.
 */
extern IO T_icr IO_ICR11;				/* address BBh */

/**
 *	@var 		IO_ICR12
 *	@brief  	Interrupt Control Register 12.
 *	@note		Corresponding resource is 16-bit reload timer 1.
 */
extern IO T_icr IO_ICR12;				/* address BCh */

/**
 *	@var 		IO_ICR13
 *	@brief  	Interrupt Control Register 13.
 *	@note		Corresponding resource is UART1.
 */
extern IO T_icr IO_ICR13;				/* address BDh */

/**
 *	@var 		IO_ICR14
 *	@brief  	Interrupt Control Register 14.
 */
extern IO T_icr IO_ICR14;				/* address BEh */

/**
 *	@var 		IO_ICR15
 *	@brief  	Interrupt Control Register 15.
 *	@note		Corresponding resource is shared with flash memory
 *				and delayed interrupt.
 */
extern IO T_icr IO_ICR15;				/* address BFh */

/**
 *	@var 		IO_ISD
 *	@brief  	IO Variables of ISD (EI2OS Descriptor).
 *	@note		When you describe the application program which
 *				refers to ISDn, please compile all the I/O register
 *				definition files with "-D FFMC_ISD" option.
 */
#ifdef FFMC_ISD
extern volatile T_isd IO_ISD[16];		/* address 100-17Fh */
#endif

/**
 *	@var 		IO_PADR
 *	@brief  	IO Variables of PADR.
 */
extern volatile T_padr IO_PADR[2]; 		/* address 1FF0-1FF5h */

/**
 *	@var 		IO_TMR
 *	@brief  	IO Variables of 16-bit reload timers 1 and 2.
 */
extern volatile T_uint16 IO_TMR[2];		/* address 3900-3903h */

/**
 *	@var 		IO_PRL01
 *	@brief  	IO Variables of 8/16-bit PPG.
 */
extern volatile T_prl01 IO_PRL01;		/* address 3910-3913h */

/**
 *	@var 		IO_PRL23
 *	@brief  	IO Variables of 8/16-bit PPG.
 */
extern volatile T_prl23 IO_PRL23;		/* address 3914-3917h */

/**
 *	@var 		IO_CANID
 *	@brief  	IO Variables of CAN controller.
 */
extern volatile T_canid IO_CANID;		/* address 3C00-3C7Fh */

/**
 *	@var 		IO_CANCT
 *	@brief  	IO Variables of CAN controller.
 */
extern volatile T_canct IO_CANCT;		/* address 3D00-3D1Bh */

#endif

#endif /* IO_MB90385_H. */
