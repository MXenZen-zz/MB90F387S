/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Node Serial Communication Command API Functions Sample Implementation     */
/**
 *	@file		NSC/nsc_api.c
 *	@brief		This file contains NSC API functions implementation.
 *	@details	The command functions of NSC can be configured to access and
 *				modify variables and execute functions or simple routines
 *				through serial communication.
 *	@note		The code is for demonstration purpose only. It only contains
 *				bare minimum implementation required by NSC and must contain
 *				user implementation if necessary.
 *	@warning	Do not confuse the compiler by implementing two or more similar
 *				NSC-related API functions. Remove or exclude other similar
 *				source codes from build except for the current or correct source.
**/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <NSC/nsc.h>

/* ----------------------------------------------------------------------------
**	API Functions.
*/

/**
 *	@fn			T_void NSCErrorCheck(T_nscErrCode)
 *	@brief 		NSC API function for error messages.
 *	@param[in]	errCode		Error code or number.
 *	@return		.
 */
T_void NSCErrorCheck(T_nscErrCode errCode)
{
	/* refer to error code */
	switch (errCode) {
		case 0xFFUL:
			/* reserved */
			break;

		case 0x00UL:
			/* no error */
			break;
		default:
			/* error not found */
			break;
	}
}

/**
 *	@fn			T_nscErrCode NSCExecute(T_nscAddress)
 *	@brief 		NSC API function for executable procedures.
 *	@param[in]	address 	Address specific to command to execute.
 *	@return		error code.
 */
T_nscErrCode NSCExecute(T_nscAddress address)
{
	T_nscErrCode errCode = 0UL;

	/* refer to address */
	switch (address) {
		case 0xFFUL:
			/* reserved */
			break;

		case 0x00UL:
			/* reserved */
			break;
		default:
			/* address not found */
			break;
	}

	return errCode;
}

/**
 *	@fn			T_nscErrCode NSCDataStore(T_nscAddress)
 *	@brief 		NSC API function for data storing activity.
 *	@param[in]	address 	Address specific to data to store.
 *	@return		error code.
 */
T_nscErrCode NSCDataStore(T_nscAddress address)
{
	T_nscErrCode errCode = 0UL;

	/* check if NSC stack is not empty */
	if (NOT(emptyNSCStackSpace())) {
		/* refer to address */
		switch (address) {
			case 0xFFUL:
				/* reserved */
				break;

			case 0x00UL:
				/* reserved */
				break;
			default:
				/* address not found */
				break;
		}
	} else {
		/* stack is empty (dummy error code) */
		errCode = 1UL;
	}

	return errCode;
}

/**
 *	@fn			T_nscErrCode NSCDataTransfer(T_nscAddress)
 *	@brief 		NSC API function for retrieving and transfering data.
 *	@param[in]	address 	Address specific to data to transfer.
 *	@return		error code.
 */
T_nscErrCode NSCDataTransfer(T_nscAddress address)
{
	T_nscErrCode errCode = 0UL;
	T_nscRepType type = NSC_SINT;
	T_nscParamData parameter = {NULL};

	/* refer to address */
	switch (address) {
		case 0xFFUL:
			/* reserved */
			break;

		case 0x00UL:
			/* reserved */
			break;
		default:
			/* address not found */
			break;
	}

	/* check if no error encountered */
	if (EQU(errCode, 0UL)) {
		/* message response (data type considered) */
		manageNSCResponse(NSC_CMD_PSH, parameter, type);
	}

	return errCode;
}

/* END OF NSC_API. */
