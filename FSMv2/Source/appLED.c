/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Finite State Machine								               	   	     */
/**
 *	@file		appLED.c
 *	@brief		This file contains the sample test program for FSM debugging.
 *	@details 	In this test, an FSM will simulate a blinking "straight ring
 *				/ one-hot counter" - circulating a single LED ON state around
 *				a ring of five (active LOW) LEDs. Two pushbuttons control the
 *				direction of the circulation (CW, CCW) or sequence of LED ON
 *				state and they also increment and/or decrement the frequency
 *				of the generated tone through the piezoelectric buzzer. The
 *				FSM requires machine property which can only be specified once
 *				(not flexible to change id,	name, or the state table) along
 *				with a state table with names, indices, and function pointers
 *				of each state. Each state of the FSM is implemented as a
 *				callback function which contains state entry, state action,
 *				state transition, and state exit macro functions. Dispatching
 *				an FSM requires no periodic interval or timing. However, the
 *				transition sequence must be guaranteed to be correct to avoid
 *				breaking the program or ending in an unrecoverable situation.
**/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *	Copyright (C) 2015-2017 Xeno Xerxes Masong (xxmasong@gmail.com)
 *
 *	This program does not guarantee that it shall fulfill its task
 *	under all circumstances. Thus, the author/developer shall not
 *	be held liable for any damages that might be incurred by the
 *	device using this program, or for any reason whatsoever.
 *
 *	This program is free software: you can redistribute it and/or
 *	modify it under the terms of the GNU General Public License as
 *	published by the Free Software Foundation, either version 3 of
 *	the License, or (at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program. If not, see <https://www.gnu.org/licenses/>.
 *++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 *	Target Hardware Information:
 *
 *		MCU			: F2MC-16LX MB90385 Series
 *		CPU			: MB90F387S
 *		Vcc			: 5.0 V
 *		Frequency	: 16 MHz (4 MHz PLLx4)
 *		Inputs		: P25, P27
 *		Outputs		: P10-P14, PPG2(P16)-PPG3(P17)
 *		Driver		: N/A
 *		Helper		: ADC, DIO, PPG
 *+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

#include <ADC/adc.h>
#include <GPIO/dio.h>
#include <TMR/ppg.h>

#include <FSM/fsm.h>

/* ----------------------------------------------------------------------------
**	Test State Indices.
*/

/**
 * 	@brief		Defined enumerated type for LED app state indices.
 */
typedef enum {
	S_LED_SELF,					/**< Null-State / Self-Transition Index */
	S_LED_START,				/**< Initializer */
	S_LED_POS_1,				/**< ON at Position 1 */
	S_LED_POS_2,				/**< ON at Position 2 */
	S_LED_POS_3,				/**< ON at Position 3 */
	S_LED_POS_4,				/**< ON at Position 4 */
	S_LED_POS_5					/**< ON at Position 5 */
} T_appLEDStates;

/* ----------------------------------------------------------------------------
**	Test State Prototypes.
*/

FSM_PRE(LED_PREPROC);

FSM_STATE(LED_START);
FSM_STATE(LED_POS_1);
FSM_STATE(LED_POS_2);
FSM_STATE(LED_POS_3);
FSM_STATE(LED_POS_4);
FSM_STATE(LED_POS_5);

FSM_POST(LED_POSTPROC);

/* ----------------------------------------------------------------------------
**	Test Constants.
*/

/**
 *	@var 		appLEDStateTable
 *	@brief		FSM state table specified for appLED.
 */
static const T_fsmState appLEDStateTable[] = {
	{
		(T_fsmIndex)S_LED_SELF,
		(T_fsmName)"LED[0] Self-Transition",
		(T_fsmCB)FSM_SELF
	}, {
		(T_fsmIndex)S_LED_START,
		(T_fsmName)"LED[1] Started",
		(T_fsmCB)&LED_START
	}, {
		(T_fsmIndex)S_LED_POS_1,
		(T_fsmName)"LED[2] ON at Position 1",
		(T_fsmCB)&LED_POS_1
	}, {
		(T_fsmIndex)S_LED_POS_2,
		(T_fsmName)"LED[3] ON at Position 2",
		(T_fsmCB)&LED_POS_2
	}, {
		(T_fsmIndex)S_LED_POS_3,
		(T_fsmName)"LED[4] ON at Position 3",
		(T_fsmCB)&LED_POS_3
	}, {
		(T_fsmIndex)S_LED_POS_4,
		(T_fsmName)"LED[5] ON at Position 4",
		(T_fsmCB)&LED_POS_4
	}, {
		(T_fsmIndex)S_LED_POS_5,
		(T_fsmName)"LED[6] ON at Position 5",
		(T_fsmCB)&LED_POS_5
	}
};

/**
 *	@var 		appLEDProp
 *	@brief		FSM properties specified for appLED.
 */
static const T_fsmProp appLEDProp = {
	(T_fsmID)1U,
	(T_fsmName)"LED App",
	(T_fsmFlag)FSM_NONHISTORICAL,
	(const T_fsmState*)appLEDStateTable,
	(T_fsmSize)SzElems_(appLEDStateTable, T_fsmState)
};

/* ----------------------------------------------------------------------------
**	Test Variables.
*/

/**
 *	@var 		appLED
 *	@brief		LED application (super)parent FSM.
 */
static T_fsm appLED;

/**
 *  @var		appLEDData
 *  @brief		LED application user data.
 */
static struct {
	T_uint8 noteIndex : 7;
	T_uint16 noteFreq;
	T_uint32 blinkCtr;
	T_pinLevel state25;
	T_pinLevel state27;
} appLEDData;

/* ----------------------------------------------------------------------------
**	Test Helper Functions.
*/

static T_void updatePin25State(T_void)
{
	static T_swDebBuffer swDebPin25;
	static T_pinLevel trigger25;

	/* check button debounce state */
	if (NOT(readDebouncedNegTrig(&swDebPin25, 8U, ReadBitIOPinData(PIN_P25)))) {
		/* check internal trigger state */
		if (NOT(trigger25)) {
			/* set logic state HIGH */
			appLEDData.state25 = PIN_HIGH;
		} else {
			/* set logic state LOW */
			appLEDData.state25 = PIN_LOW;
		}
		/* set internal trigger state HIGH */
		trigger25 = PIN_HIGH;
	} else {
		/* set internal trigger state LOW */
		trigger25 = PIN_LOW;
	}
}

static T_void updatePin27State(T_void)
{
	static T_swDebBuffer swDebPin27;
	static T_pinLevel trigger27;

	/* check button debounce state */
	if (NOT(readDebouncedNegTrig(&swDebPin27, 8U, ReadBitIOPinData(PIN_P27)))) {
		/* check internal trigger state */
		if (NOT(trigger27)) {
			/* set logic state HIGH */
			appLEDData.state27 = PIN_HIGH;
		} else {
			/* set logic state LOW */
			appLEDData.state27 = PIN_LOW;
		}
		/* set internal trigger state HIGH */
		trigger27 = PIN_HIGH;
	} else {
		/* set internal trigger state LOW */
		trigger27 = PIN_LOW;
	}
}

static T_uint16 getNoteFrequency(T_uint8 noteIndex)
{
	static const T_float32 freqC0 = 16.35159783F;
	static const T_float32 freqB8 = 7902.132819F;
	static const T_float32 twelfthRootOf2 = 1.059463094F;
	T_float32 freqN = freqC0;
	T_uint8 count;

	/* compute for note's frequency */
	for (count = noteIndex; NEQ(count, 0U) && LEQ(freqN, freqB8); count--) {
		freqN *= twelfthRootOf2;
	}

	return (T_uint16)freqN;
}

static T_void resetLED(T_void)
{
	/* (re)initialize (super)parent FSM */
	ResetStateMachine(appLED);
	/* save FSM user data size */
	SetFSMDataSize(appLED, SzBytes_(appLEDData));
}

/* ----------------------------------------------------------------------------
**	Test Parent FSM: LED States.
*/

FSM_PRE(LED_PREPROC)
{
	(T_void)FSM_THIS;

	/* update pin state */
	updatePin25State();
	updatePin27State();
}

FSM_STATE(LED_START)
{
	(T_void)FSM_THIS;

	/* state entry */
	StateEntry(FSM_NONE);

	/* state action */
	StateAction(FSM_NONE);

	/* state transition(s) */
	StateTransition(NOT(appLEDData.state25) && IS(appLEDData.state27), S_LED_POS_1, {				/* [1]. */
		/* continue immediately */
		StateRequestTransitChain(FSM_THIS);
	});
	StateTransition(IS(appLEDData.state25) && NOT(appLEDData.state27), S_LED_POS_5, {				/* [2]. */
		/* continue immediately */
		StateRequestTransitChain(FSM_THIS);
	});
	StateTransition(FSM_ELSE, FSM_SELF, FSM_NONE);													/* [3]. */

	/* state exit */
	StateExit(FSM_NONE);
}

FSM_STATE(LED_POS_1)
{
	(T_void)FSM_THIS;

	/* state entry */
	StateEntry({
		/* LED ON */
		writeDigital(PIN10, PIN_LOW);
	});

	/* state action */
	StateAction({
		/* LED BLINK */
		if (NOT(appLEDData.blinkCtr % 100UL)) {
			writeDigital(PIN10, !readDigital(PIN10));
		}
	});

	/* state transition(s) */
	StateTransition(NOT(appLEDData.state25) && IS(appLEDData.state27), S_LED_POS_2, {				/* [1]. */
		/* stop pulse generation */
		stopPPG(PPG_CH23);
		/* increment note index */
		COND(NEQ(appLEDData.noteIndex, 127U), appLEDData.noteIndex++, appLEDData.noteIndex);
	});
	StateTransition(IS(appLEDData.state25) && NOT(appLEDData.state27), S_LED_POS_5, {				/* [2]. */
		/* stop pulse generation */
		stopPPG(PPG_CH23);
		/* decrement note index */
		COND(NEQ(appLEDData.noteIndex, 0U), appLEDData.noteIndex--, appLEDData.noteIndex);
	});
	StateTransition(FSM_ELSE, FSM_SELF, {															/* [3]. */
		/* generate adjustable tone */
		pulseOutByFrequency(PPG_CH23, getNoteFrequency(appLEDData.noteIndex), readAnalog(PIN_AN0));
	});

	/* state exit */
	StateExit({
		/* LED OFF */
		writeDigital(PIN10, PIN_HIGH);
	});
}

FSM_STATE(LED_POS_2)
{
	(T_void)FSM_THIS;

	/* state entry */
	StateEntry({
		/* LED ON */
		writeDigital(PIN11, PIN_LOW);
	});

	/* state action */
	StateAction({
		/* LED BLINK */
		if (NOT(appLEDData.blinkCtr % 200UL)) {
			writeDigital(PIN11, !readDigital(PIN11));
		}
	});

	/* state transition(s) */
	StateTransition(NOT(appLEDData.state25) && IS(appLEDData.state27), S_LED_POS_3, {				/* [1]. */
		/* stop pulse generation */
		stopPPG(PPG_CH23);
		/* increment note index */
		COND(NEQ(appLEDData.noteIndex, 127U), appLEDData.noteIndex++, appLEDData.noteIndex);
	});
	StateTransition(IS(appLEDData.state25) && NOT(appLEDData.state27), S_LED_POS_1, {				/* [2]. */
		/* stop pulse generation */
		stopPPG(PPG_CH23);
		/* decrement note index */
		COND(NEQ(appLEDData.noteIndex, 0U), appLEDData.noteIndex--, appLEDData.noteIndex);
	});
	StateTransition(FSM_ELSE, FSM_SELF, {															/* [3]. */
		/* generate adjustable tone */
		pulseOutByFrequency(PPG_CH23, getNoteFrequency(appLEDData.noteIndex), readAnalog(PIN_AN0));
	});

	/* state exit */
	StateExit({
		/* LED OFF */
		writeDigital(PIN11, PIN_HIGH);
	});
}

FSM_STATE(LED_POS_3)
{
	(T_void)FSM_THIS;

	/* state entry */
	StateEntry({
		/* LED ON */
		writeDigital(PIN12, PIN_LOW);
	});

	/* state action */
	StateAction({
		/* LED BLINK */
		if (NOT(appLEDData.blinkCtr % 400UL)) {
			writeDigital(PIN12, !readDigital(PIN12));
		}
	});

	/* state transition(s) */
	StateTransition(NOT(appLEDData.state25) && IS(appLEDData.state27), S_LED_POS_4, {				/* [1]. */
		/* stop pulse generation */
		stopPPG(PPG_CH23);
		/* increment note index */
		COND(NEQ(appLEDData.noteIndex, 127U), appLEDData.noteIndex++, appLEDData.noteIndex);
	});
	StateTransition(IS(appLEDData.state25) && NOT(appLEDData.state27), S_LED_POS_2, {				/* [2]. */
		/* stop pulse generation */
		stopPPG(PPG_CH23);
		/* decrement note index */
		COND(NEQ(appLEDData.noteIndex, 0U), appLEDData.noteIndex--, appLEDData.noteIndex);
	});
	StateTransition(FSM_ELSE, FSM_SELF, {															/* [3]. */
		/* generate adjustable tone */
		pulseOutByFrequency(PPG_CH23, getNoteFrequency(appLEDData.noteIndex), readAnalog(PIN_AN0));
	});

	/* state exit */
	StateExit({
		/* LED OFF */
		writeDigital(PIN12, PIN_HIGH);
	});
}

FSM_STATE(LED_POS_4)
{
	(T_void)FSM_THIS;

	/* state entry */
	StateEntry({
		/* LED ON */
		writeDigital(PIN13, PIN_LOW);
	});

	/* state action */
	StateAction({
		/* LED BLINK */
		if (NOT(appLEDData.blinkCtr % 800UL)) {
			writeDigital(PIN13, !readDigital(PIN13));
		}
	});

	/* state transition(s) */
	StateTransition(NOT(appLEDData.state25) && IS(appLEDData.state27), S_LED_POS_5, {				/* [1]. */
		/* stop pulse generation */
		stopPPG(PPG_CH23);
		/* increment note index */
		COND(NEQ(appLEDData.noteIndex, 127U), appLEDData.noteIndex++, appLEDData.noteIndex);
	});
	StateTransition(IS(appLEDData.state25) && NOT(appLEDData.state27), S_LED_POS_3, {				/* [2]. */
		/* stop pulse generation */
		stopPPG(PPG_CH23);
		/* decrement note index */
		COND(NEQ(appLEDData.noteIndex, 0U), appLEDData.noteIndex--, appLEDData.noteIndex);
	});
	StateTransition(FSM_ELSE, FSM_SELF, {															/* [3]. */
		/* generate adjustable tone */
		pulseOutByFrequency(PPG_CH23, getNoteFrequency(appLEDData.noteIndex), readAnalog(PIN_AN0));
	});

	/* state exit */
	StateExit({
		/* LED OFF */
		writeDigital(PIN13, PIN_HIGH);
	});
}

FSM_STATE(LED_POS_5)
{
	(T_void)FSM_THIS;

	/* state entry */
	StateEntry({
		/* LED ON */
		writeDigital(PIN14, PIN_LOW);
	});

	/* state action */
	StateAction({
		/* LED BLINK */
		if (NOT(appLEDData.blinkCtr % 1600UL)) {
			writeDigital(PIN14, !readDigital(PIN14));
		}
	});

	/* state transition(s) */
	StateTransition(NOT(appLEDData.state25) && IS(appLEDData.state27), S_LED_POS_1, {				/* [1]. */
		/* stop pulse generation */
		stopPPG(PPG_CH23);
		/* increment note index */
		COND(NEQ(appLEDData.noteIndex, 127U), appLEDData.noteIndex++, appLEDData.noteIndex);
	});
	StateTransition(IS(appLEDData.state25) && NOT(appLEDData.state27), S_LED_POS_4, {				/* [2]. */
		/* stop pulse generation */
		stopPPG(PPG_CH23);
		/* decrement note index */
		COND(NEQ(appLEDData.noteIndex, 0U), appLEDData.noteIndex--, appLEDData.noteIndex);
	});
	StateTransition(FSM_ELSE, FSM_SELF, {															/* [3]. */
		/* generate adjustable tone */
		pulseOutByFrequency(PPG_CH23, getNoteFrequency(appLEDData.noteIndex), readAnalog(PIN_AN0));
	});

	/* state exit */
	StateExit({
		/* LED OFF */
		writeDigital(PIN14, PIN_HIGH);
	});
}

FSM_POST(LED_POSTPROC)
{
	(T_void)FSM_THIS;

	/* increment blink counter */
	++appLEDData.blinkCtr;
}

/* ----------------------------------------------------------------------------
**	Inline Functions.
*/

/**
 *  @fn			T_void init(T_void)
 *  @brief 		Initialization / setup code runs once.
 *  @param		.
 *	@return		.
 */
#pragma inline init
static T_void init(T_void)
{
	__DI();
	__set_il(7);

	/* initialize variables */
	memset(&appLEDData, NULL, SzBytes_(appLEDData));
	/* initialize pin modes */
	pinModeDigital(PIN10, PIN_OUTPUT);
	pinModeDigital(PIN11, PIN_OUTPUT);
	pinModeDigital(PIN12, PIN_OUTPUT);
	pinModeDigital(PIN13, PIN_OUTPUT);
	pinModeDigital(PIN14, PIN_OUTPUT);
	/* initialize IO pin modes (write to IO pin mode) */
	WriteBitIOPinMode(PIN_D25, PIN_INPUT);
	WriteBitIOPinMode(PIN_D27, PIN_INPUT);
	/* initialize pins state */
	writeDigital(PIN10, PIN_HIGH);
	writeDigital(PIN11, PIN_HIGH);
	writeDigital(PIN12, PIN_HIGH);
	writeDigital(PIN13, PIN_HIGH);
	writeDigital(PIN14, PIN_HIGH);
	/* initialize ADC (8-bit resolution) */
	initADC(ADC_DEF_CT, ADC_DEF_ST, ADC_RES_8BITS);
	/* initialize PPG */
	initPPG();

	/* initialize application (super)parent FSM */
	initFSM((T_fsm*)memset(&appLED, NULL, SzBytes_(T_fsm)), &appLEDProp, (T_fsmData*)&appLEDData, S_LED_START);
	setFSMPreAndPostFunctions(&appLED, &LED_PREPROC, &LED_POSTPROC);
	/* initialize FSM (internal reset) */
	resetLED();

	__EI();
}

/**
 *  @fn			T_void debug(T_void)
 *  @brief 		Iteration / loop code runs repeatedly.
 *  @param		.
 *	@return		.
 */
#pragma inline debug
static T_void debug(T_void)
{
	/* run application FSM dispatcher */
	dispatchFSM(&appLED);
}

/* ----------------------------------------------------------------------------
**	Main Function.
*/

/**
 *  @fn			T_void main(T_void)
 *  @brief 		Main / program entry point.
 *  @param		.
 *	@return		.
 */
T_void FAR main(T_void)
{
	/* initialize first */
	init();
	/* then iterate indefinitely */
	for (;;) {
		debug();
	}
}

/* END OF APPLED. */
