/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Programmable Pulse Generator			 						             */
/**
 *	@file		TMR/ppg.h
 * 	@brief		This file contains PPG types, external constants, and API functions.
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

#ifndef PPG_H
#define PPG_H

#include <IO/ppg01_io.h>
#include <IO/ppg23_io.h>
#include <TMR/gpt.h>
#include <MCU/isr.h>

/* ----------------------------------------------------------------------------
**	PPG Types.
*/

/**
 * 	@brief		Defined enumerated type for PPG channel.
 */
typedef enum {
	PPG_CH0		 =   14U,		/**< channel 0 */
	PPG_CH1		 =   15U,		/**< channel 1 */
	PPG_CH2		 =   16U,		/**< channel 2 */
	PPG_CH3		 =   17U,		/**< channel 3 */
	PPG_CH01	 =   45U,		/**< combined channels 0 and 1 */
	PPG_CH23	 =   67U,		/**< combined channels 2 and 3 */
	PPG_CH01_CH0 = 4514U,		/**< channel 0 of channel group 0 and 1 */
	PPG_CH01_CH1 = 4515U,		/**< channel 1 of channel group 0 and 1 */
	PPG_CH23_CH2 = 6716U,		/**< channel 2 of channel group 2 and 3 */
	PPG_CH23_CH3 = 6717U		/**< channel 3 of channel group 2 and 3 */
} T_ppgChannel;

/* ----------------------------------------------------------------------------
**	PPG External Constants.
*/

/**
 * 	@var		PRIO_PPG01_ISR
 *	@brief		ISR interrupt level/priority of PPG for channels 0 and 1, or both.
 */
extern const T_icrINTLevel PRIO_PPG01_ISR;

/**
 * 	@var		PRIO_PPG23_ISR
 *	@brief		ISR interrupt level/priority of PPG for channels 2 and 3, or both.
 *	@note		The ICR of PPG23 is shared with ICU1. Unless ICU1 is not used,
 *				they must have the same ICR level at all times. If only PPG23
 *				is (or will be) used, then set the ICR level of PPG23 alone.
 */
extern const T_icrINTLevel PRIO_PPG23_ISR;

/* ----------------------------------------------------------------------------
**	PPG API Functions.
*/

/**
 * 	@fn 		T_void initPPG(T_void)
 *	@brief 		Initialize PPG.
 * 	@param		.
 * 	@return		.
 */
extern T_void initPPG(T_void);

/**
 * 	@fn 		T_void setupPPGTimer(T_ppgChannel, T_gptInterval, T_gptISRHook)
 *	@brief 		Initializes the PPG for reload timing purpose only.
 * 	@pre		initPPG must be called first (or called already).
 * 	@param[in]	channel 	PPG channel.
 * 	@param[in]	interval	GPT interval duration in microseconds.
 * 	@param[in]	ppgFunc		PPG interrupt user function.
 * 	@return		.
 * 	@warning	Do not use this function to initialize PPG output operation.
 * 				Instead, use either pulseOutByPeriod or pulseOutByFrequency
 * 				function. To start or stop the PPG timer-only, use runPPGTimer
 * 				and haltPPGTimer function, respectively.
 *  @warning	Do not exceed beyond 32768 us interval (for 8-bit independent
 *  			PPG channels and 8+8-bit primary / prescaler PPG channel) or
 *  			8388608 us interval (for 16-bit dual PPG channel and 8+8-bit
 *  			secondary PPG channel).
 *  @note		It is recommended to set the same value in both mark and space
 *  			for 8+8-bit PPG. Otherwise, ensure that both the secondary PPG
 *  			channel's mark and space is greater than the primary PPG channel
 *  			or prescaler. Note that since both PPG channels are utilizing
 *  			8-bit counter resolution, the accurate timing might not be guaranteed.
 *  @note		Prefer using 16-bit counter resolution if more accurate timing
 *  			is needed. Frequencies or interval durations higher or lower
 *  			than the mentioned might yield incorrect timing.
 */
extern T_void setupPPGTimer(T_ppgChannel channel,
	T_gptInterval interval, T_gptISRHook ppgFunc);

/**
 * 	@fn 		T_void runPPGTimer(T_ppgChannel)
 *	@brief 		Starts the PPG timer if routine is present.
 * 	@pre		setupPPGTimer must be called first (or called already).
 * 	@param[in]	channel 	PPG channel.
 * 	@return		.
 *  @note		This function is for use of PPG timer-only function.
 */
extern T_void runPPGTimer(T_ppgChannel channel);

/**
 * 	@fn 		T_void haltPPGTimer(T_ppgChannel)
 *	@brief 		Stops and disables the PPG time module.
 * 	@param[in]	channel 	PPG channel.
 * 	@return		.
 *  @note		This function is for use of PPG timer-only function.
 */
extern T_void haltPPGTimer(T_ppgChannel channel);

/**
 * 	@fn 		T_void pulseOutByPeriod(T_ppgChannel, T_gptInterval, T_gptInterval)
 *	@brief		Generates output pulses based on period's mark and space.
 * 	@pre		initPPG must be called first (or called already).
 * 	@param[in]	channel		PPG channel.
 * 	@param[in]	mark		GPT high (ON) interval duration in microseconds.
 * 	@param[in]	space		GPT low (OFF) interval duration in microseconds.
 * 	@return		.
 * 	@warning	Do not use this function to initialize PPG timer-only operation.
 * 				Instead, use setupPPGTimer function. To start or stop the PPG
 * 				output, use startPPG or stopPPG function, respectively.
 *  @warning	Do not exceed beyond 32768 us interval (for 8-bit independent
 *  			PPG channels and 8+8-bit primary / prescaler PPG channel) or
 *  			8388608 us interval (for 16-bit dual PPG channel and 8+8-bit
 *  			secondary PPG channel).
 */
extern T_void pulseOutByPeriod(T_ppgChannel channel,
	T_gptInterval mark, T_gptInterval space);

/**
 * 	@fn 		T_void pulseOutByFrequency(T_ppgChannel, T_gptFrequency, T_gptDutyCycle)
 *	@brief		Generates output pulses based on frequency and duty cycle.
 * 	@pre		initPPG must be called first (or called already).
 * 	@param[in]	channel		PPG channel.
 * 	@param[in]	frequency	GPT frequency in hertz.
 * 	@param[in]	dutyCycle	GPT duty cycle in byte (0-255).
 * 	@return		.
 * 	@warning	Do not use this function to initialize PPG timer-only operation.
 * 				Instead, use setupPPGTimer function. To start or stop the PPG
 * 				output, use startPPG or stopPPG function, respectively.
 *  @warning	Do not exceed below 30 Hz or beyond 62.5 kHz.
 */
extern T_void pulseOutByFrequency(T_ppgChannel channel,
	T_gptFrequency frequency, T_gptDutyCycle dutyCycle);

/**
 * 	@fn 		T_void startPPG(T_ppgChannel)
 *	@brief 		Starts or resumes PPG pulse output operation.
 * 	@pre		PPG previous pulse output initialization needed.
 * 	@param[in]	channel		PPG channel.
 * 	@return		.
 *  @note		This function is for use of PPG pulse out function.
 */
extern T_void startPPG(T_ppgChannel channel);

/**
 * 	@fn 		T_void stopPPG(T_ppgChannel)
 *	@brief 		Stops PPG pulse output operation.
 * 	@param[in]	channel		PPG channel.
 * 	@return		.
 *  @note		This function is for use of PPG pulse out function.
 */
extern T_void stopPPG(T_ppgChannel channel);

/**
 * 	@fn 		T_void PPG01_IRQHandler(T_void)
 *	@brief 		Clears PPG interrupt flag and executes PPG user interrupt
 *  			routine function.
 *  @param		.
 *  @return		.
 */
#if (USE_PPG01_ISR || (USE_PPG0_ISR || USE_PPG1_ISR))
#if NOSAVEREG_PPG01_ISR
NOSAVEREG
#endif
extern ISR(PPG01_IRQHandler);
#endif

/**
 * 	@fn 		T_void PPG23_IRQHandler(T_void)
 *	@brief 		Clears PPG interrupt flag and executes PPG user interrupt
 *  			routine function.
 *  @param		.
 *  @return		.
 */
#if (USE_PPG23_ISR || (USE_PPG2_ISR || USE_PPG3_ISR))
#if NOSAVEREG_PPG23_ISR
NOSAVEREG
#endif
extern ISR(PPG23_IRQHandler);
#endif

#endif /* PPG_H. */
