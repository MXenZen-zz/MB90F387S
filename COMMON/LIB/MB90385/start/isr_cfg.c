/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Interrupt Service Routine Configuration			           			     */
/**
 *	@file		isr_cfg.c
 * 	@brief		This file contains ISR priority constants definition.
 * 	@note		The CPU performs interrupt processing only when an interrupt
 * 				with a lower value (interrupt level) than that indicated by
 * 				the interrupt level mask register (ILM) is requested with an
 * 				interrupt enable (CCR: I = 1). Also, ensure that the ISR usage
 * 				of the ISR functions is set or enabled. Interrupt levels or
 * 				priorities must not be set to 7 (or none) and ILM must not be
 * 				set to 0 (or interrupts disabled, globally).
 *	@note		The interrupt level for resources sharing an ICR register
 *				become the same. The priority is given when plural interrupts
 *				with the same level are generated simultaneously.
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

#include <MCU/isr.h>

#if USE_ADC_ISR
#include <ADC/adc.h>
#endif
#if USE_CAN_ISR
#include <COM/can.h>
#endif
#if USE_DIG_ISR
#include <MCU/dig.h>
#endif
#if ((USE_EXI4_ISR || USE_EXI5_ISR) || (USE_EXI6_ISR || USE_EXI7_ISR) || USE_EXIRX_ISR)
#include <INT/exi.h>
#endif
#if (USE_ICU0_ISR || USE_ICU1_ISR || (USE_ICU2_ISR || USE_ICU3_ISR))
#include <INT/icu.h>
#endif
#if USE_IOT_ISR
#include <TMR/iot.h>
#endif
#if ((USE_PPG01_ISR || (USE_PPG0_ISR || USE_PPG1_ISR)) || (USE_PPG23_ISR || (USE_PPG2_ISR || USE_PPG3_ISR)))
#include <TMR/ppg.h>
#endif
#if (USE_RLT0_ISR || USE_RLT1_ISR)
#include <TMR/rlt.h>
#endif
#if USE_SER_ISR
#include <COM/ser.h>
#endif
#if USE_TBT_ISR
#include <TMR/tbt.h>
#endif
#if USE_WTT_ISR
#include <TMR/wtt.h>
#endif

/* ----------------------------------------------------------------------------
**	ISR Constants.
*/

/**
 * 	@var		PRIO_ADC_ISR
 *	@brief		ISR interrupt level/priority of ADC.
 *	@note		The ICR of ADC is shared with RLT0. Unless RLT0 is not used,
 *				they must have the same ICR level at all times. If only ADC
 *				is (or will be) used, then set the ICR level of ADC alone.
 */
const T_icrINTLevel PRIO_ADC_ISR = ICR_LVL_6;

/**
 * 	@var		PRIO_CAN_ISR
 *	@brief		ISR interrupt level/priority of CAN.
 */
const T_icrINTLevel PRIO_CAN_ISR = ICR_LVL_5;

/**
 * 	@var		PRIO_DIG_ISR
 *	@brief		ISR interrupt level/priority of DIG.
 */
const T_icrINTLevel PRIO_DIG_ISR = ICR_LVL_6;

/**
 * 	@var		PRIO_EXI45_ISR
 *	@brief		ISR interrupt level/priority of EXI for channels 4 and 5.
 *	@note		The ICR of EXI45 is shared with ICU0. Unless ICU0 is not used,
 *				they must have the same ICR level at all times. If only EXI45
 *				is (or will be) used, then set the ICR level of EXI45 alone.
 */
const T_icrINTLevel PRIO_EXI45_ISR = ICR_LVL_1;

/**
 * 	@var		PRIO_EXI67_ISR
 *	@brief		ISR interrupt level/priority of EXI for channels 6 and 7.
 *	@note		The ICR of EXI67 is shared with WTT. Since there is no
 *				subclock in MB90F387S and MB90387S, WTT interrupt level
 *				must be the same as EXI67 interrupt level at all times.
 */
const T_icrINTLevel PRIO_EXI67_ISR = ICR_LVL_1;

/**
 * 	@var		PRIO_EXIRX_ISR
 *	@brief		ISR interrupt level/priority of EXI for channel RX
 *				or interrupt level/priority of of CAN Wake-up.
 *	@note		The ICR of EXI RX (CAN Wake-up) is shared with TBT. Unless
 *				TBT is not used, they must have the same ICR level at all
 *				times. If only EXI RX (CAN Wake-up) is (or will be) used,
 *				then set the ICR level of EXI RX (CAN Wake-up) alone.
 */
const T_icrINTLevel PRIO_EXIRX_ISR = ICR_LVL_1;

/**
 * 	@var		PRIO_ICU0_ISR
 *	@brief		ISR interrupt level/priority of ICU for channel 0.
 *	@note		The ICR of ICU0 is shared with EXI45. Unless EXI45 is not used,
 *				they must have the same ICR level at all times. If only ICU0
 *				is (or will be) used, then set the ICR level of ICU0 alone.
 */
const T_icrINTLevel PRIO_ICU0_ISR = ICR_LVL_0;

/**
 * 	@var		PRIO_ICU1_ISR
 *	@brief		ISR interrupt level/priority of ICU for channel 1.
 *	@note		The ICR of ICU1 is shared with PPG23. Unless PPG23 is not used,
 *				they must have the same ICR level at all times. If only ICU1
 *				is (or will be) used, then set the ICR level of ICU1 alone.
 */
const T_icrINTLevel PRIO_ICU1_ISR = ICR_LVL_0;

/**
 * 	@var		PRIO_ICU23_ISR
 *	@brief		ISR interrupt level/priority of ICU for channels 2 and 3.
 */
const T_icrINTLevel PRIO_ICU23_ISR = ICR_LVL_0;

/**
 * 	@var		PRIO_IOT_ISR
 *	@brief		ISR interrupt level/priority of IOT.
 */
const T_icrINTLevel PRIO_IOT_ISR = ICR_LVL_2;

/**
 * 	@var		PRIO_PPG01_ISR
 *	@brief		ISR interrupt level/priority of PPG for channels 0 and 1, or both.
 */
const T_icrINTLevel PRIO_PPG01_ISR = ICR_LVL_3;

/**
 * 	@var		PRIO_PPG23_ISR
 *	@brief		ISR interrupt level/priority of PPG for channels 2 and 3, or both.
 *	@note		The ICR of PPG23 is shared with ICU1. Unless ICU1 is not used,
 *				they must have the same ICR level at all times. If only PPG23
 *				is (or will be) used, then set the ICR level of PPG23 alone.
 */
const T_icrINTLevel PRIO_PPG23_ISR = ICR_LVL_3;

/**
 * 	@var		PRIO_RLT0_ISR
 *	@brief		ISR interrupt level/priority of RLT for channel 0.
 *	@note		The ICR of RLT0 is shared with ADC. Unless ADC is not used,
 *				they must have the same ICR level at all times. If only RLT0
 *				is (or will be) used, then set the ICR level of RLT0 alone.
 */
const T_icrINTLevel PRIO_RLT0_ISR = ICR_LVL_3;

/**
 * 	@var		PRIO_RLT1_ISR
 *	@brief		ISR interrupt level/priority of RLT for channel 1.
 */
const T_icrINTLevel PRIO_RLT1_ISR = ICR_LVL_3;

/**
 * 	@var		PRIO_SER_ISR
 *	@brief		ISR interrupt level/priority of SER.
 *	@warning	The interrupt level of SER must not be 7 (or none).
 */
const T_icrINTLevel PRIO_SER_ISR = ICR_LVL_0;

/**
 * 	@var		PRIO_TBT_ISR
 *	@brief		ISR interrupt level/priority of TBT.
 *	@note		The ICR of TBT is shared with EXI RX (CAN Wake-up). Unless
 *				EXI RX (CAN Wake-up) is not used, they must have the same
 *				ICR level at all times. If only TBT is (or will be) used,
 *				then set the ICR level of TBT alone.
 */
const T_icrINTLevel PRIO_TBT_ISR = ICR_LVL_4;

/**
 * 	@var		PRIO_WTT_ISR
 *	@brief		ISR interrupt level/priority of WTT.
 *	@note		The ICR of WTT is shared with EXI67. Since there is no
 *				subclock in MB90F387S and MB90387S, WTT interrupt level
 *				must be the same as EXI67 interrupt level at all times.
 */
const T_icrINTLevel PRIO_WTT_ISR = ICR_LVL_7;

/* END OF ISR_CFG. */
