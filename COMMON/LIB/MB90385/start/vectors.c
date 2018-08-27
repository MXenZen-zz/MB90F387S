/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Vectors														             */
/**
 *	@file		vectors.c
 *	@brief		This file contains interrupt vector table mapping various
 * 				interrupt handler functions (ISRs).
 * 	@note		The CPU performs interrupt processing only when an interrupt
 * 				with a lower value (interrupt level) than that indicated by
 * 				the interrupt level mask register (ILM) is requested with an
 * 				interrupt enable (CCR: I = 1). Also, ensure that the ISR usage
 * 				of the ISR functions is set or enabled. Interrupt levels or
 * 				priorities must not be set to 7 (or none) and ILM must not be
 * 				set to 0 (or interrupts disabled, globally).
 * 	@note		All resource related vectors are predefined. Software interrupts
 * 				can be added here as well. If software interrupts 0 to 7 are
 * 				defined here, this might conflict with the reset vector in the
 * 				start-up file.
 *	@note 		To specify different or customized ISR (IRQ Handler) on an
 *				interrupt vector, replace the predefined ISR function name
 *				formatted as "[TLA]_IRQHandler" with the name of the alternative
 *				ISR function specified. The ISR function must correspond to its
 *				intended interrupt vector given as hexadecimal number at the
 *				end of the pragma invect line. For example, if the ISR function
 *				__interrupt void Custom_ISR(void) is an ISR of DIG (Delayed
 *				Interrupt Generation Module) at a specific interrupt vector
 *				number of 0x2A (42) intended to replace the predefined ISR
 *				function __interrupt void DIG_IRQHandler(void) registered as
 *				"#pragma intvect DIG_IRQHandler 0x2A", then replace as follows:
 *				"#pragma intvect Custom_ISR 0x2A".
 *	@warning	It is not safe to remove any of the registered ISR function
 *				in the interrupt vector table. It's better to replace them or
 *				disable them through the ISR usage macro if they are not used.
 *				Do not remove or replace the reset or start ISR function nor
 *				the defined vector "DEFAULT_IRQHandler" mapped to an interrupt
 *				vector that has not been specified using pragma intvect.
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
**	Interrupt Vector Table.
*/

#pragma section INTVECT=VECTORS,attr=CONST,locate=0xFFFC00

#pragma intvect _start					0x08		0x0

#if USE_CAN_ISR
#pragma intvect CANRX_IRQHandler		0x0B
#pragma intvect CANTX_IRQHandler		0x0C
#endif

#if USE_EXIRX_ISR
#pragma intvect EXIRX_IRQHandler		0x0F
#endif

#if USE_TBT_ISR
#pragma intvect TBT_IRQHandler			0x10
#endif

#if USE_RLT0_ISR
#pragma intvect RLT0_IRQHandler			0x11
#endif

#if USE_ADC_ISR
#pragma intvect ADC_IRQHandler			0x12
#endif

#if USE_IOT_ISR
#pragma intvect IOT_IRQHandler			0x13
#endif

#if (USE_PPG01_ISR || (USE_PPG0_ISR || USE_PPG1_ISR))
#pragma intvect PPG01_IRQHandler		0x16
#endif

#if USE_ICU0_ISR
#pragma intvect ICU0_IRQHandler			0x17
#endif

#if (USE_EXI4_ISR || USE_EXI5_ISR)
#pragma intvect EXI45_IRQHandler		0x18
#endif

#if USE_ICU1_ISR
#pragma intvect ICU1_IRQHandler			0x19
#endif

#if (USE_PPG23_ISR || (USE_PPG2_ISR || USE_PPG3_ISR))
#pragma intvect PPG23_IRQHandler		0x1A
#endif

#if (USE_EXI6_ISR || USE_EXI7_ISR)
#pragma intvect EXI67_IRQHandler		0x1B
#endif

#if USE_WTT_ISR
#pragma intvect WTT_IRQHandler			0x1C
#endif

#if (USE_ICU2_ISR || USE_ICU3_ISR)
#pragma intvect ICU23_IRQHandler		0x1E
#endif

#if USE_RLT1_ISR
#pragma intvect RLT1_IRQHandler			0x24
#endif

#if USE_SER_ISR
#pragma intvect SERRX_IRQHandler		0x25
#pragma intvect SERTX_IRQHandler		0x26
#endif

#if USE_DIG_ISR
#pragma intvect DIG_IRQHandler			0x2A
#endif

#pragma defvect DEFAULT_IRQHandler

/* END OF VECTORS. */
