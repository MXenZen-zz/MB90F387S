/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Pulse Width Modulation (PPG Output)							             */
/**
 *	@file		PWM/pwm.h
 * 	@brief		This file contains PWM types and API functions.
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

#ifndef PWM_H
#define PWM_H

#include <TMR/ppg.h>

/* ----------------------------------------------------------------------------
**	PWM Types.
*/

/**
 * 	@brief		Defined enumerated type for PWM channel.
 */
typedef enum {
	PWM_CH0 = PPG_CH0,					/**< channel 0 */
	PWM_CH1 = PPG_CH1,					/**< channel 1 */
	PWM_CH2 = PPG_CH2,					/**< channel 2 */
	PWM_CH3 = PPG_CH3					/**< channel 3 */
} T_pwmChannel;

/**
 * 	@brief		Defined enumerated type for PWM base frequency.
 */
typedef enum {
	PWM_FREQ_62k5 = PPG_MCLK_1T,		/**< 62500.00 Hz, 8-bit DC */
	PWM_FREQ_31k3 = PPG_MCLK_2T,		/**< 31250.00 Hz, 8-bit DC */
	PWM_FREQ_15k6 = PPG_MCLK_4T,		/**< 15625.00 Hz, 8-bit DC */
	PWM_FREQ_7k8  = PPG_MCLK_8T,		/**<  7812.50 Hz, 8-bit DC */
	PWM_FREQ_3k9  = PPG_MCLK_16T,		/**<  3906.25 Hz, 8-bit DC */
	PWM_FREQ_1k9  = PPG_HCLK_512T + 6,	/**<  1953.13 Hz, 2-bit DC */
	PWM_FREQ_977  = PPG_HCLK_512T + 5,	/**<   976.56 Hz, 3-bit DC */
	PWM_FREQ_488  = PPG_HCLK_512T + 4,	/**<   488.28 Hz, 4-bit DC */
	PWM_FREQ_244  = PPG_HCLK_512T + 3,	/**<   244.14 Hz, 5-bit DC */
	PWM_FREQ_122  = PPG_HCLK_512T + 2,	/**<   122.07 Hz, 6-bit DC */
	PWM_FREQ_61   = PPG_HCLK_512T + 1,	/**<    61.04 Hz, 7-bit DC */
	PWM_FREQ_30   = PPG_HCLK_512T + 0	/**<    30.52 Hz, 8-bit DC */
} T_pwmFrequency;

/**
 * 	@brief		Defined type for PWM duty cycle data type.
 */
typedef T_gptDutyCycle T_pwmDutyCycle;

/* ----------------------------------------------------------------------------
**	PWM API Functions.
*/

/**
 * 	@fn 		T_void writeAnalog(T_pwmChannel, T_pwmDutyCycle, T_pwmFrequency)
 *	@brief		Generates output pulses as digital-to-analog conversion (DAC).
 * 	@param[in]	channel			PWM channel.
 * 	@param[in]	dutyCycle		PWM duty cycle in byte, resolution dependent.
 * 	@param[in]	baseFrequency	PWM base frequency, count clock dependent.
 * 	@return		.
 *  @note		For pins that do not natively support PWM (or PPG), duty cycle
 *  			lesser than 128 implies output pin is set to LOW, and conversely.
 */
extern T_void writeAnalog(T_pwmChannel channel, T_pwmDutyCycle dutyCycle,
	T_pwmFrequency baseFrequency);

#endif /* PWM_H. */
