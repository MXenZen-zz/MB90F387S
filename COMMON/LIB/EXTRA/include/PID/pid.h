/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Proportional Integral Derivative Controller					             */
/**
 *	@file		PID/pid.h
 *	@brief		This file contains flags, types and API functions
 *				needed for PID control.
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

#ifndef PID_H
#define PID_H

#include <LIB/bitmanip.h>
#include <math.h>

/* ----------------------------------------------------------------------------
**	Flags.
*/

/**
 * 	@def		PID_EPS
 * 	@brief		Smallest difference that has significant value (~ epsilon).
 */
#define PID_EPS 				(0.001F)

/**
 * 	@def		PID_DEF_KP
 * 	@brief		The default proportional control coefficient or factor.
 */
#define PID_DEF_KP 				(0.100F)

/**
 * 	@def		PID_DEF_KI
 * 	@brief		The default integral control coefficient or factor.
 */
#define PID_DEF_KI 				(0.015F)

/**
 * 	@def		PID_DEF_KD
 * 	@brief		The default derivative control coefficient or factor.
 */
#define PID_DEF_KD 				(0.100F)

/* ----------------------------------------------------------------------------
**	Types.
*/

/**
 *	@brief	Defined structured type for PID control data.
 */
typedef struct {
	T_float32 output;			/**< ouput value */
	T_float32 max; 				/**< maximum value */
	T_float32 min; 				/**< miniumum value */
	T_float32 err; 				/**< error value */
	T_float32 i;				/**< Integrator value */
	T_float32 kp; 				/**< Proportional factor */
	T_float32 ki; 				/**< integral factor */
	T_float32 kd; 				/**< derivative factor */
} T_pid;

/* ----------------------------------------------------------------------------
**	API Functions.
*/

/**
 *	@fn 		T_void initPID(T_pid*, T_float32, T_float32,
 *  				T_float32, T_float32, T_float32)
 *	@brief 		Initialize PID controller variables (initial tuning parameters
 *  			are also set here).
 *	@param		control		PID variable.
 *	@param[in]  Kp			Proportional control coefficient (float).
 *	@param[in]  Ki			Integral control coefficient (float).
 *	@param[in]  Kd			Derivative control coefficient (float).
 *	@param[in]  Min			Minimum output value (float).
 *	@param[in]  Max			Maximum output value (float).
 *	@return		.
 */
extern T_void initPID(T_pid* control, T_float32 Kp, T_float32 Ki, T_float32 Kd,
	T_float32 Min, T_float32 Max);

/**
 *	@fn 		T_void tunePID(T_pid*, T_float32, T_float32, T_float32)
 *	@brief 		Allows the controller's dynamic performance to be adjusted
 *  			on the fly during normal operation.
 *	@param		control		PID variable.
 *	@param[in]  Kp			Proportional control coefficient (float).
 *	@param[in]  Ki			Integral control coefficient (float).
 *	@param[in]  Kd			Derivative control coefficient (float).
 *	@return		.
 */
extern T_void tunePID(T_pid* control, T_float32 Kp, T_float32 Ki, T_float32 Kd);

/**
 *	@fn 		T_void setPIDOutput(T_pid*, T_float32, T_float32)
 *	@brief 		Clamps output to specific range of values.
 *	@param		control		PID variable.
 *	@param[in]  Min			Minimum output value (float).
 *	@param[in]  Max			Maximum output value (float).
 *	@return		.
 */
extern T_void setPIDOutput(T_pid* control, T_float32 Min, T_float32 Max);

/**
 *	@fn 		T_float32 computePID(T_pid*, T_float32, T_float32)
 *	@brief 		Performs the PID calculation.
 *	@param		control		PID variable.
 *	@param[in]  setPoint	The set point or reference (float).
 *	@param[in]  input		The process variable (float).
 *	@return		Manipulated value or output (float).
 */
extern T_float32 computePID(T_pid* control, T_float32 setPoint, T_float32 input);

#endif /* PID_H. */
