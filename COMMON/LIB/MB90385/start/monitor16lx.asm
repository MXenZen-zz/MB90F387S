;==========================================================================
; The following software is for demonstration purposes only.
; It is not fully tested, nor validated in order to fullfill its task under
; all circumstances. Therefore, this software or any part of it must only be
; used in an evaluation laboratory environment. This software is subject to
; the rules of Accemic's standard DISCLAIMER, available at www.accemic.com.
;--------------------------------------------------------------------------
; Copyright (c) 2001-2003 Accemic GmbH & Co. KG
; All rights reserved.
;==========================================================================

;==========================================================================
; Module name        : monitor16lx.asm
; Version            : 5.01
; Date of creation.  : 07.03.2003
; Last Modification  : 03.05.2004
; Authors            : Rainer Harthaus (RH)
;--------------------------------------------------------------------------

;===<< DESCRIPTION >>======================================================
; Reservation of memory for monitor and dummy declaration
; for application functions
;--------------------------------------------------------------------------

;===<< HISTORY >>==========================================================
; Vers   * Datum    * Name  * Subject
; 5.00   * 07.03.03 * RH    * first creation
; 5.01   * 03.05.04 * AL    * MB90895 monitor section added
;                             functions offsets changed
;--------------------------------------------------------------------------

;==========================================================================
; Please visit www.accemic.com
; for updates and other valuable developer resources.
;==========================================================================

  		.PROGRAM	MONITORFUNC
 		.TITLE		"MONITOR RESERVATION AND FUNCTIONS"

;--------------------------------------------------------------------------
; monitor version information
;--------------------------------------------------------------------------
ACC_FILE_VERSION:	.EQU	7

;--------------------------------------------------------------------------
; monitor data area reservation (0x000880 to 0x0008FF)
;--------------------------------------------------------------------------
		.SECTION	ACC_MDATA,	DATA,   	ALIGN=2
ACC_MDATA_S:
  		.RES.B 		128

;--------------------------------------------------------------------------
; monitor target information area reservation (0xFFFB00 to 0xFFFBFF)
;--------------------------------------------------------------------------
		.SECTION	ACC_UDATA,	CONST,		ALIGN=2
ACC_UDATA_S:
		.RES.B 		256

;--------------------------------------------------------------------------
; monitor kernel area reservation (0x00FFA000 to 0x00FFBFFF)
;--------------------------------------------------------------------------
		.SECTION 	ACC_MCODE,	CONST,		ALIGN=2
ACC_MCODE_S:
    	.EXPORT 	_acc_WatchdogEnable
    	.EXPORT 	_acc_MessageBox
    	.EXPORT		_acc_printf
    	.EXPORT 	_acc_KernelUART
    	.EXPORT 	_acc_SetLockState
    	.RES.B 		16
_acc_WatchdogEnable:
		.RES.L 		1
_acc_KernelUART:
		.RES.L 		1
_acc_MessageBox:
		.RES.L 		1
_acc_printf:
		.RES.L 		1
_acc_SetLockState:
		.RES.L 		1
    	.RES.B 		8156

  .END
