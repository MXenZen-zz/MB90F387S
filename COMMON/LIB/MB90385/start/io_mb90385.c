/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* MB90385 Series IO Data and Register Variables Declaration	 	   	     */
/**
 *	@file		io_mb90385.c
 * 	@brief		This file contains variables declaration of all the associated
 * 				IO data and register of F2MC-16LX MB90385 Series MB90F387S with
 * 				their specified arrangement or memory-mapped IO addresses.
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

#ifndef IO_DEFINE
#define IO_DEFINE

#include <IO/io_mb90385.h>

/* ----------------------------------------------------------------------------
**	IO Register Variables.
*/

#pragma segment IO=IO_REG,attr=IOCOMMON,locate=0x000000

IO T_uint8 rsv_00[1];
IO T_pdr1 IO_PDR1;						/* address 01h */
IO T_pdr2 IO_PDR2;						/* address 02h */
IO T_pdr3 IO_PDR3;						/* address 03h */
IO T_pdr4 IO_PDR4;						/* address 04h */
IO T_pdr5 IO_PDR5;						/* address 05h */
IO T_uint8 rsv_06_10[11];
IO T_ddr1 IO_DDR1;						/* address 11h */
IO T_ddr2 IO_DDR2;						/* address 12h */
IO T_ddr3 IO_DDR3;						/* address 13h */
IO T_ddr4 IO_DDR4;						/* address 14h */
IO T_ddr5 IO_DDR5;						/* address 15h */
IO T_uint8 rsv_16_1A[5];
IO T_ader IO_ADER;						/* address 1Bh */
IO T_uint8 rsv_1C_25[10];
IO T_smr IO_SMR1;						/* address 26h */
IO T_scr IO_SCR1;						/* address 27h */
IO T_siodr IO_SIODR1;					/* address 28h */
IO T_ssr IO_SSR1;						/* address 29h */
IO T_uint8 rsv_2A[1];
IO T_cdcr IO_CDCR1;						/* address 2Bh */
IO T_uint8 rsv_2C_2F[4];
IO T_enir IO_ENIR;						/* address 30h */
IO T_eirr IO_EIRR;						/* address 31h */
IO T_elvr IO_ELVR;						/* address 32-33h */
IO T_adcsl IO_ADCSL;					/* address 34h */
IO T_adcsh IO_ADCSH;					/* address 35h */
IO T_adcrlh IO_ADCRLH;					/* address 36-37h */
IO T_uint8 rsv_38_3F[8];
IO T_ppgc IO_PPGC01;					/* address 40-41h */
IO T_ppg IO_PPG01;						/* address 42h */
IO T_uint8 rsv_43[1];
IO T_ppgc IO_PPGC23;					/* address 44-45h */
IO T_ppg IO_PPG23;						/* address 46h */
IO T_uint8 rsv_47_4F[9];
IO T_uint16 IO_IPCP0;					/* address 50-51h */
IO T_uint16 IO_IPCP1;					/* address 52-53h */
IO T_ics IO_ICS01;						/* address 54h */
IO T_ics IO_ICS23;						/* address 55h */
IO T_uint16 IO_TCDT;					/* address 56-57h */
IO T_tccs IO_TCCS;						/* address 58h */
IO T_uint8 rsv_59[1];
IO T_uint16 IO_IPCP2;					/* address 5A-5Bh */
IO T_uint16 IO_IPCP3;					/* address 5C-5Dh */
IO T_uint8 rsv_5E_65[8];
IO T_tmcsr IO_TMCSR0;					/* address 66-67h */
IO T_tmcsr IO_TMCSR1;					/* address 68-69h */
IO T_uint8 rsv_6A_6E[5];
IO T_romm IO_ROMM;						/* address 6Fh */
IO T_uint8 rsv_70_7F[16];
IO T_bvalr IO_BVALR;					/* address 80h */
IO T_uint8 rsv_81[1];
IO T_treqr IO_TREQR;					/* address 82h */
IO T_uint8 rsv_83[1];
IO T_tcanr IO_TCANR;					/* address 84h */
IO T_uint8 rsv_85[1];
IO T_tcr IO_TCR;						/* address 86h */
IO T_uint8 rsv_87[1];
IO T_rcr IO_RCR;						/* address 88h */
IO T_uint8 rsv_89[1];
IO T_rrtrr IO_RRTRR;					/* address 8Ah */
IO T_uint8 rsv_8B[1];
IO T_rovrr IO_ROVRR;					/* address 8Ch */
IO T_uint8 rsv_8D[1];
IO T_rier IO_RIER;						/* address 8Eh */
IO T_uint8 rsv_8F[1];
IO T_uint8 rsv_90_9D[14];
IO T_pacsr IO_PACSR;					/* address 9Eh */
IO T_dirr IO_DIRR;						/* address 9Fh */
IO T_lpmcr IO_LPMCR;					/* address A0h */
IO T_ckscr IO_CKSCR;					/* address A1h */
IO T_uint8 rsv_A2_A7[6];
IO T_wdtc IO_WDTC;						/* address A8h */
IO T_tbtc IO_TBTC;						/* address A9h */
IO T_wtc IO_WTC;						/* address AAh */
IO T_uint8 rsv_AB_AD[3];
IO T_fmcs IO_FMCS;						/* address AEh */
IO T_uint8 rsv_AF[1];
IO T_icr IO_ICR00;						/* address B0h */
IO T_icr IO_ICR01;						/* address B1h */
IO T_icr IO_ICR02;						/* address B2h */
IO T_icr IO_ICR03;						/* address B3h */
IO T_icr IO_ICR04;						/* address B4h */
IO T_icr IO_ICR05;						/* address B5h */
IO T_icr IO_ICR06;						/* address B6h */
IO T_icr IO_ICR07;						/* address B7h */
IO T_icr IO_ICR08;						/* address B8h */
IO T_icr IO_ICR09;						/* address B9h */
IO T_icr IO_ICR10;						/* address BAh */
IO T_icr IO_ICR11;						/* address BBh */
IO T_icr IO_ICR12;						/* address BCh */
IO T_icr IO_ICR13;						/* address BDh */
IO T_icr IO_ICR14;						/* address BEh */
IO T_icr IO_ICR15;						/* address BFh */

/* ----------------------------------------------------------------------------
**	IO Data Variables.
*/

#ifdef FFMC_ISD
#pragma segment 	DATA=IO_ISD,locate=0x000100
#pragma segment FAR_DATA=IO_ISD,locate=0x000100

volatile T_isd IO_ISD[16];				/* address 100-17Fh */
#endif

#pragma segment	    DATA=IO_PADR,locate=0x001FF0
#pragma segment FAR_DATA=IO_PADR,locate=0x001FF0

volatile T_padr IO_PADR[2]; 			/* address 1FF0-1FF5h */

#pragma segment     DATA=IO_TMR,locate=0x003900
#pragma segment FAR_DATA=IO_TMR,locate=0x003900

volatile T_uint16 IO_TMR[2];			/* address 3900-3903h */

#pragma segment     DATA=IO_PRL01,locate=0x003910
#pragma segment FAR_DATA=IO_PRL01,locate=0x003910

volatile T_prl01 IO_PRL01;				/* address 3910-3913h */

#pragma segment     DATA=IO_PRL23,locate=0x003914
#pragma segment FAR_DATA=IO_PRL23,locate=0x003914

volatile T_prl23 IO_PRL23;				/* address 3914-3917h */

#pragma segment     DATA=IO_CANID,locate=0x003C00
#pragma segment FAR_DATA=IO_CANID,locate=0x003C00

volatile T_canid IO_CANID;				/* address 3C00-3C7Fh */

#pragma segment     DATA=IO_CANCT,locate=0x003D00
#pragma segment FAR_DATA=IO_CANCT,locate=0x003D00

volatile T_canct IO_CANCT;				/* address 3D00-3D1Bh */

#endif

/* END OF IO_MB90385. */
