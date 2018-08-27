/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Compiler				 								       		         */
/**
 * 	@file 		LIB/compiler.h
 *	@brief		This file contains compiler-specific macro types and definitions.
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

#ifndef COMPILER_H
#define COMPILER_H

#include <stddef.h>

/* ----------------------------------------------------------------------------
**	Extended Type Qualifiers.
*/

/**
 *  @def		NEAR
 *  @brief		The __near-type qualified variables and functions are
 *  			accessed using 16-bit addressing regardless of the memory
 *  			model specified at compilation.
 */
#ifdef FFMC_ETQ
#define NEAR					__near
#else
#define NEAR
#endif

/**
 *  @def		FAR
 *  @brief		The __far-type qualified variables and functions are
 *  			accessed using 24-bit addressing.
 */
#ifdef FFMC_ETQ
#define FAR						__far
#else
#define FAR
#endif

/**
 *  @def		IO
 *  @brief		The __io type qualifier is specified for a variable
 *  			mapped into the I/O area (h’0000’ to h’00ff’).
 *	@note		When defining variables with the __io type qualifier
 * 				specified, variable areas are allocated in the order
 * 				defined. A variable such as a dummy must be defined
 * 				for those locations where a variable is not defined.
 */
#ifdef FFMC_ETQ
#define IO						__io
#else
#define IO
#endif

/**
 *  @def		DIRECT
 *  @brief		The __direct type qualifier is specified for variables
 *  			mapped into the direct area.
 *	@remarks	__direct-type qualified variables are accessed using direct
 *				addressing wherein the address of a variable mapped in the
 *				direct area (page pointed to by the DTB register) is accessed
 *				in 8-bit units. As a result, a smaller code than that used
 *				when accessing using normal addressing can be generated.
 */
#ifdef FFMC_ETQ
#define DIRECT					__direct
#else
#define DIRECT
#endif

/**
 *  @def		INTERRUPT
 *  @brief		The __interrupt type qualifier is specified for an
 *  			interrupt function.
 */
#ifdef FFMC_ETQ
#define INTERRUPT				__interrupt
#else
#define INTERRUPT
#endif

/**
 *  @def		NOSAVEREG
 *  @brief		The __nosavereg type qualifier is specified for an interrupt
 *  			function together with the __interrupt type qualifier.
 *	@remarks	When an interrupt function qualified using the __nosaverreg
 *				type qualifier is called, the interrupt function executes
 *				processing without saving registers.
 */
#ifdef FFMC_ETQ
#define NOSAVEREG				__nosavereg
#else
#define NOSAVEREG
#endif

/* ----------------------------------------------------------------------------
**	General Macro Definitions.
*/

/**
 *	@def 	AUTOMATIC
 *	@brief	Used for the declaration of local pointers.
 */
#define AUTOMATIC

/**
 *	@def 	TYPEDEF
 *	@brief	Used within type definitions where no memory qualifier can be specified.
 */
#define TYPEDEF

/**
 *	@def 	NULL
 *	@brief	Defined with zero only.
 */
#ifdef NULL
#undef NULL
#endif
#define NULL					(0)

/**
 *	@def 	NULL_PTR
 *	@brief	Defined with a void pointer to address zero.
 */
#define NULL_PTR  				((void*)0)

/**
 *	@def 	INLINE
 *	@brief	Defined for abstraction of the compiler keyword inline.
 */
#define INLINE

#endif /* COMPILER_H. */
