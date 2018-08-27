/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Node Serial Communication				   							     */
/**
 *	@file		NSC/nsc.h
 *	@brief		This file contains NSC types and API functions.
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

#ifndef NSC_H
#define NSC_H

#include <NSC/toString.h>

/* ----------------------------------------------------------------------------
**	Types.
*/

/**
 * 	@brief		Defined enumerated type for NSC commands list.
 */
typedef enum {
	NSC_CMD_INV,				/**< invalid /empty command */
	NSC_CMD_ERR,				/**< error message command */
	NSC_CMD_EXE,				/**< execute function command */
	NSC_CMD_LNK,				/**< link / reservation command */
	NSC_CMD_PSH,				/**< numerical stack push command */
	NSC_CMD_POP, 				/**< numerical stack pop command */
	NSC_CMD_TXD,				/**< transmit data command */
	NSC_CMD_RXD,				/**< request (receive) data command */
	NSC_CMD_RC0,				/**< reserved command 0 (as linked) */
	NSC_CMD_RC1,				/**< reserved command 1 (as linked) */
	NSC_CMD_RC2,				/**< reserved command 2 (as linked) */
	NSC_CMD_RC3,				/**< reserved command 3 (as linked) */
	NSC_CMD_MSR,  				/**< master node request */
	NSC_CMD_SLV,  				/**< slave node response */
	NSC_CMD_REL,  				/**< node session release */
	NSC_CMD_NLN,				/**< newline / terminator command */
	NSC_CMD_SIZE 				/**< total number of available commands */
} T_nscCommand;

/**
 * 	@brief		Defined enumerated type for NSC sessions list.
 */
typedef enum {
	NSC_SSN_MSR	 = NSC_CMD_MSR,	/**< master session */
	NSC_SSN_SLV	 = NSC_CMD_SLV,	/**< slave session */
	NSC_SSN_IDLE = NSC_CMD_REL	/**< idle (no) session */
} T_nscSession;

/**
 * 	@brief		Defined enumerated type for NSC parameter data representation type.
 */
typedef enum {
	NSC_SINT,					/**< signed (32-bit) decimal representation */
	NSC_UINT,					/**< unsigned (32-bit) decimal representation */
	NSC_UHEX,					/**< unsigned (32-bit) hexadecimal representation */
	NSC_FLOAT					/**< single precision floating point representation */
} T_nscRepType;

/**
 * 	@brief		Defined union type for NSC parameter data (default: 32-bit multi).
 */
typedef union {
	T_float32	fl32;
	T_sint32	si32;
	T_sint16	si16[SzWords_DWORD];
	T_sint8		si8 [SzBytes_DWORD];
	T_uint32	ui32;
	T_uint16	ui16[SzWords_DWORD];
	T_uint8		ui8 [SzBytes_DWORD];
} T_nscParamData;

/**
 * 	@brief		Defined type for NSC activity count / event update (default: 8 bits).
 */
typedef T_uint8 T_nscActivity;

/**
 * 	@brief		Defined type for NSC error number or code (default: 32 bits).
 */
typedef T_uint32 T_nscErrCode;

/**
 * 	@brief		Defined type for NSC location or address (default: 32 bits).
 */
typedef T_uint32 T_nscAddress;

/* ----------------------------------------------------------------------------
**	API Functions.
*/

/**
 *	@fn			T_void initNSC(T_void)
 *	@brief 		Initialize node serial communication.
 *	@details	Sets variables (fields or properties) to their initial values.
 *	@post		UART must be initialized and running after NSC initialization!
 *	@param		.
 *	@return		.
 */
extern T_void initNSC(T_void);

/**
 *	@fn			T_nscCommand evaluateNSCSession(T_nscCommand)
 *	@brief 		Session Command Evaluation and Manager.
 *	@details	Evaluates command and returns the same command index
 *				if messaging is in session. The function also manage the
 *				clearing of stack at the start and / or end of session.
 *	@param[in]	command		Command to evaluate.
 *	@return		command index.
 */
extern T_nscCommand evaluateNSCSession(T_nscCommand command);

/**
 *	@fn			T_void manageNSCRequest(T_uint8)
 *	@brief 		Message Parser (Slave) and Evaluator.
 *	@details	Receives message string, evaluates message length, extracts
 *				and validates received command, interprets received data as
 *				parameter, and performs execution of command either through
 *				the library of command functions, through stack operations
 *				or through session control.
 *	@param[in]	rxWaitCount		Reception wait count (0 for no waiting).
 *	@return		.
 */
extern T_void manageNSCRequest(T_uint8 rxWaitCount);

/**
 *	@fn			T_void manageNSCResponse(T_nscCommand, T_nscParamData, T_nscRepType)
 *	@brief 		Message Responder (Master) and Generator.
 *	@details	Manage creation of commands as request or response and prepares
 *				the parameter or data to transmit, then formats command and
 *				parameter, then transmits the message string.
 *	@param[in]	command 	Instruction to execute.
 *	@param[in]	parameter	Parameter of command.
 *	@param[in]	type		Data type parameter format.
 *	@return		.
 */
extern T_void manageNSCResponse(T_nscCommand command,
	T_nscParamData parameter, T_nscRepType type);

/**
 *  @fn 		T_nscCommand getNSCRxRecentCommand(T_void)
 *  @brief 		Gets recent reception / incoming message valid command.
 *  @param		.
 *  @return		command index.
 */
extern T_nscCommand getNSCRxRecentCommand(T_void);

/**
 *  @fn 		T_nscCommand getNSCTxRecentCommand(T_void)
 *  @brief 		Gets recent transmission / outgoing message valid command.
 *  @param		.
 *  @return		command index.
 */
extern T_nscCommand getNSCTxRecentCommand(T_void);

/**
 *  @fn 		T_nscSession getNSCRxSession(T_void)
 *  @brief 		Gets reception / incoming message session type.
 *  @param		.
 *  @return		session type.
 */
extern T_nscSession getNSCRxSession(T_void);

/**
 *  @fn 		T_nscSession getNSCTxSession(T_void)
 *  @brief 		Gets transmission / outgoing message session type.
 *  @param		.
 *  @return		session type.
 */
extern T_nscSession getNSCTxSession(T_void);

/**
 *  @fn 		T_nscActivity getNSCRxActivityCount(T_void)
 *  @brief 		Gets reception / incoming message activity count.
 *  @param		.
 *  @return		activity count.
 */
extern T_nscActivity getNSCRxActivityCount(T_void);

/**
 *  @fn 		T_nscActivity getNSCTxActivityCount(T_void)
 *  @brief 		Gets transmission / outgoing message activity count.
 *  @param		.
 *  @return		activity count.
 */
extern T_nscActivity getNSCTxActivityCount(T_void);

/**
 *	@fn			T_bit pushNSCStackInteger(T_sint32)
 *	@brief 		Push integral data to NSC stack.
 *	@param[in]	data	Integral data to push in stack.
 *	@return		push success.
 */
extern T_bit pushNSCStackInteger(T_sint32 data);

/**
 *	@fn			T_bit pushNSCStackFloat(T_float32)
 *	@brief 		Push floating data to NSC stack.
 *	@param[in]	data	Floating data to push in stack.
 *	@return		push success.
 */
extern T_bit pushNSCStackFloat(T_float32 data);

/**
 *	@fn			T_sint32 popNSCStackInteger(T_void)
 *	@brief 		Pop integral data from NSC stack.
 *	@param		.
 *	@return		data [returns EOF (-1) if stack is empty].
 */
extern T_sint32 popNSCStackInteger(T_void);

/**
 *	@fn			T_float32 popNSCStackFloat(T_void)
 *	@brief 		Pop floating data from NSC stack.
 *	@param		.
 *	@return		data [returns NaN if stack is empty].
 */
extern T_float32 popNSCStackFloat(T_void);

/**
 *	@fn			T_bit fullNSCStackSpace(T_void)
 *	@brief 		Returns TRUE if all NSC stack buffer entries are occupied.
 *	@param		.
 *	@return		full.
 */
extern T_bit fullNSCStackSpace(T_void);

/**
 *	@fn			T_bit emptyNSCStackSpace(T_void)
 *	@brief 		Returns TRUE if all NSC stack buffer entries are available.
 *	@param		.
 *	@return		empty.
 */
extern T_bit emptyNSCStackSpace(T_void);

/**
 *	@fn 		T_void clearNSCStackSpace(T_void)
 *	@brief 		Resets NSC stack top and bottom pointer location.
 *	@param		.
 *	@return		.
 */
extern T_void clearNSCStackSpace(T_void);

/**
 *	@fn			T_void NSCErrorCheck(T_nscErrCode)
 *	@brief 		NSC API function for error messages.
 *	@param[in]	errCode		Error code or number.
 *	@return		.
 */
extern T_void NSCErrorCheck(T_nscErrCode errCode);

/**
 *	@fn			T_nscErrCode NSCExecute(T_nscAddress)
 *	@brief 		NSC API function for executable procedures.
 *	@param[in]	address 	Address specific to command to execute.
 *	@return		error code.
 */
extern T_nscErrCode NSCExecute(T_nscAddress address);

/**
 *	@fn			T_nscErrCode NSCDataStore(T_nscAddress)
 *	@brief 		NSC API function for data storing activity.
 *	@param[in]	address 	Address specific to data to store.
 *	@return		error code.
 */
extern T_nscErrCode NSCDataStore(T_nscAddress address);

/**
 *	@fn			T_nscErrCode NSCDataTransfer(T_nscAddress)
 *	@brief 		NSC API function for retrieving and transfering data.
 *	@param[in]	address 	Address specific to data to transfer.
 *	@return		error code.
 */
extern T_nscErrCode NSCDataTransfer(T_nscAddress address);

#endif /* NSC_H. */
