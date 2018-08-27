/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Kalman Filter												             */
/**
 *	@file		KLM/klm.h
 *	@brief		This file contains flags, types and API functions
 *				needed for kalman filtering.
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

#ifndef KLM_H
#define KLM_H

#include <LIB/bitmanip.h>
#include <math.h>

/* ----------------------------------------------------------------------------
**	Flags.
*/

/**
 * 	@def		KLM_DEF_PROC_NOISE
 * 	@brief		The default process noise which estimates the error in
 * 				the system model.
 */
#define KLM_DEF_PROC_NOISE			(5E-6F)

/**
 * 	@def		KLM_DEF_MEA_NOISE
 * 	@brief		The default measurement noise which is the inaccuracy the
 * 				input introduced or an external fluctuation.
 */
#define KLM_DEF_MEA_NOISE			(6E-5F)

/* ----------------------------------------------------------------------------
**	Types.
*/

/**
 *	@brief	Defined structured type for kalman data.
 */
typedef struct {
	T_float32 procNoise;
	T_float32 meaNoise;
	T_float32 value;
	T_float32 estimate;
	T_float32 estError;
	T_float32 gain;
} T_kalman;

/* ----------------------------------------------------------------------------
**	API Functions.
*/

/**
 *	@fn 		T_void initKalman(T_kalman*, T_float32, T_float32)
 *	@brief 		Initialize kalman filter variables.
 *	@param		filter		Kalman variable.
 *	@param[in]  pErr		Process noise (float).
 *	@param[in]  mErr		Measurement noise (float).
 *	@return		.
 */
extern T_void initKalman(T_kalman* filter, T_float32 pErr, T_float32 mErr);

/**
 *	@fn 		T_void tuneKalman(T_kalman*, T_float32, T_float32)
 *	@brief 		Set kalman filter error / covariance variables.
 *	@param		filter		Kalman variable.
 *	@param[in]  pErr		Process noise (float).
 *	@param[in]  mErr		Measurement noise (float).
 *	@return		.
 */
extern T_void tuneKalman(T_kalman* filter, T_float32 pErr, T_float32 mErr);

/**
 *	@fn 		T_float32 computeKalman(T_kalman*, T_float32)
 *	@brief 		Computes for the kalman estimate due to a recent value.
 *	@param		filter		Kalman variable.
 *	@param[in]  recent		Recent value (float).
 *	@return		kalman estimate (float).
 */
extern T_float32 computeKalman(T_kalman* filter, T_float32 recent);

#endif /* KLM_H. */
