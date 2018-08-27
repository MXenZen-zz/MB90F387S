/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Accemic Monitor												             */
/**
 *	@file		monitor.h
 *	@brief		Monitor API functions.
 * 	@attention 	The following software is for demonstration purposes only.
 * 				It is not fully tested, nor validated in order to fulfill
 * 				its task under all circumstances. Therefore, this software
 * 				or any part of it must only be used in an evaluation
 * 				laboratory environment.
 * 	@version	1.0
 * 	@date		07.03.2003
 * 	@author		Rainer Harthaus (RH)
 * 	@copyright	Copyright (c) 2001-2003 Accemic GmbH & Co. KG \n
 * 				All rights reserved.
 * 	@remark		This software is subject to the rules of Accemic's
 * 				standard DISCLAIMER, available at www.accemic.com.
 * 	@see		Please visit www.accemic.com
 * 				for updates and other valuable developer resources.
**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*****************************************************************************
 * History
 * Vers   * Datum    * Name  * Subject
 * 1.00   * 07.03.03 * RH    * first creation
 *****************************************************************************/

#ifndef MONFUNC_H
#define MONFUNC_H

#include <LIB/compiler.h>

/* ----------------------------------------------------------------------------
**	Flags.
*/

/* ------------------------------- acc_printf ------------------------------ */

/* Values for Location */
#define ACC_TYPE_LISTBOX      			0x00
#define ACC_TYPE_ROW_TEXT     			0x08
#define ACC_TYPE_ROW_CAPTION  			0xF0

/* Defintions for types to display
  (specify if ACC_TYPE_LISTBOX or ACC_TYPE_ROW_TEXT) */
#define ACC_TYPE_STRING      			0x10
#define ACC_TYPE_UCHAR        			0x30	/* 1 Byte   */
#define ACC_TYPE_CHAR         			0x40  	/* 1 Byte   */
#define ACC_TYPE_USHORT      			0x50	/* 2 Bytes  */
#define ACC_TYPE_SHORT        			0x60  	/* 2 Bytes  */
#define ACC_TYPE_ULONG        			0x70  	/* 4 Bytes  */
#define ACC_TYPE_LONG         			0x80  	/* 4 Bytes  */
#define ACC_TYPE_FLOAT        			0x90	/* 4 Bytes  */
#define ACC_TYPE_DOUBLE       			0xA0	/* 8 Bytes  */

/* Values for Wait */
#define ACC_NOT_WAIT          			0
#define ACC_WAIT              			1

/* ------------------------------- acc_MessageBox -------------------------- */

/* Values for Flag
   Indicates what kind of button to show */
#define MB_OK				 			0
#define MB_OKCANCEL			  			1
#define MB_ABORTRETRYIGNORE	  			2
#define MB_YESNOCANCEL		  			3
#define MB_YESNO              			4
#define MB_RETRYCANCEL        			5

/* Return values
   Indicates what kind of button was pressed */
#define IDERROR              			-1	/* Error */
#define IDNOTCONNECTED        			0	/* PC not connected or transmission not possible */
#define IDOK                  			1	/* Button OK     was pressed */
#define IDCANCEL             			2	/* Button Cancel was pressed */
#define IDABORT	              			3	/* Button Abort  was pressed */
#define IDRETRY	              			4	/* Button Retry  was pressed */
#define IDIGNORE              			5 	/* Button Ignore was pressed */
#define IDYES	              			6	/* Button Yes    was pressed */
#define IDNO	              			7	/* Button No     was pressed */

/* ------------------------------- acc_SetLockState ------------------------ */
#define ACC_SYSTEM_LOCKED				1
#define ACC_SYSTEM_UNLOCKED				0

#define ACC_SECURE_KEY					1
#define ACC_SECURE_PASSWORD				2

/* ------------------------------- other defines --------------------------- */

#define ACC_COMMAND_EMBO				0x01
#define ACC_COMMAND_SECURE_CONNECTION 	0x02

/* ----------------------------------------------------------------------------
**	External Functions.
*/

/**
 *	@brief 		Displays text in the Target Message Box.
 * 	@param		Location:		See above
 * 	@param		Type:			See above
 * 	@param		Data:			Pointer to data to transmit
 * 	@param		Position:		Position of row (if type==ACC_TYPE_ROW)
 * 	@param		WaitOnSended:	0 Do not wait for tranmission end \n
 *		        				1 Wait for transmission end
 * 	@param		Buffer:			Transmission buffer (must be at least
 *  							sizeof(Data) + 5 Bytes)
 * 	@return		-1 : Error \n
 *  			 0 : PC not connected or transmission not possible \n
 *  			 1 : transmitted
 * 	@remark		Kernel will notify the end of transmission
 *  			by setting Buffer[0] to 0.
 */
extern char FAR (* FAR acc_printf)(char Location, char Type, FAR void* Data,
		unsigned char Position, char WaitOnSended, FAR char* Buffer);

/**
 *	@brief 		Displays a Message Box on Accemic MDE.
 * 	@param		Msg:          	Message text to show
 * 	@param		Flags:        	See above
 * 	@param		Buffer:       	Transmission buffer (must be at least
 *  							sizeof(Msg) + 4 Bytes)
 * 	@return		-1 : Error \n
 *  			 0 : PC not connected or transmission not possible \n
 *  			 other: see above
 */
extern char FAR (* FAR acc_MessageBox)(FAR char* Msg, char Flag, FAR char* Buffer);

/**
 *	@brief 		Enable Watchdog support of Accemic MDE.
 * 	@param		.
 * 	@return		.
 * 	@remark		Should be called IMMEDIATELY BEFORE first watchdog activation.
 */
extern void FAR (* FAR acc_WatchdogEnable)(void);

/**
 *	@brief 		Enable UART support of Accemic MDE.
 * 	@param		Disable:     0: Kernel UART is used by monitor kernel \n
 *  						 1: Kernel UART can be used by application
 * 	@return		.
 */
extern void FAR (* FAR acc_KernelUART)(char Disable);

/**
 *	@brief 		Set the lock/unlock state of the target.
 * 	@param		State:		1: No commands are accepted by the kernel \n
 *              			0: Kernel is unlocked
 * 	@return		.
 */
extern void FAR (* FAR acc_SetLockState)(unsigned char State);

#endif /* MONITOR_H. */
