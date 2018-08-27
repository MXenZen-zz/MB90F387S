/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Finite State Machine													     */
/**
 *	@file		FSM/fsm.h
 *	@brief		This file contains flags, types, getters, other macro
 *				functions, and API functions for creating and managing
 *				finite state machines (FSMs).
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

#ifndef FSM_H
#define FSM_H

#include <LIB/bitmanip.h>

/* ----------------------------------------------------------------------------
**	Flags.
*/

/**
 * 	@def		FSM_THIS
 * 	@brief		The dereferenced parameter or pointer variable of T_fsm* type
 *				known as 'automaton' which is present and is accessible in both
 *				FSM state function and FSM function implementation code blocks.
 *	@note		FSM state functions are required to use this macro alias instead
 *				of using 'automaton' to refer to the FSM parameter variable.
 */
#define FSM_THIS						(*automaton)

/**
 * 	@def		FSM_NEXT
 * 	@brief		The state transition condition specific to any standard next
 *				state as its only state transition, except self-transition.
 */
#define FSM_NEXT						(1U)

/**
 * 	@def		FSM_ELSE
 * 	@brief		The state transition condition only used when there are multiple
 *				state transition conditional expressions which requires last state
 *				transition condition similar to else in an if-else ladder.
 */
#define FSM_ELSE						(1U)

/**
 * 	@def		FSM_LAST
 * 	@brief		The state transition condition specific to last or final state
 *				transition (which is actually a self-transition).
 */
#define FSM_LAST						(1U)

/**
 * 	@def		FSM_SELF
 * 	@brief		The state transition next state index often used together with
 * 				FSM_LAST as state transition condition for last or final state
 * 				transition (which is actually a self-transition).
 */
#define FSM_SELF						(NULL)

/**
 * 	@def		FSM_NONE
 * 	@brief		Empty state action or no (other) operation to execute.
 */
#define FSM_NONE						((T_void)NULL)

/**
 * 	@def		FSM_NONHISTORICAL
 * 	@brief		FSM is not historical (can be re-initialized or restarted).
 */
#define FSM_NONHISTORICAL				(0U)

/**
 * 	@def		FSM_HISTORICAL
 * 	@brief		FSM is historical (cannot be re-initialized or restarted).
 */
#define FSM_HISTORICAL					(1U)

/* ----------------------------------------------------------------------------
**	Types.
*/

/* forward declaration */
struct fsm_t;

/**
 *	@brief		Callback type for functions of finite state machines (FSM).
 */
typedef T_void	(*T_fsmCB)(struct fsm_t*);

/**
 * 	@brief		Defined type for FSM ID data type width (default: 8 bits).
 */
typedef T_uint8	T_fsmID;

/**
 * 	@brief		Defined type for FSM name pointer type (machine specific).
 */
typedef T_char*	T_fsmName;

/**
 * 	@brief		Defined type for FSM flags data type width (default: 8-bit).
 */
typedef T_bit	T_fsmFlag;

/**
 * 	@brief		Defined type for FSM state index data type width (default: 8 bits).
 */
typedef T_uint8	T_fsmIndex;

/**
 * 	@brief		Defined type for FSM LUT size data type width (default: 8 bits).
 */
typedef T_uint8	T_fsmSize;

/**
 * 	@brief		Defined type for FSM data free-type (size unknown).
 */
typedef T_void	T_fsmData;

/**
 *	@brief		Data structure for FSM state properties.
 */
typedef struct {
	/* state identification */
	T_fsmIndex stateNumber;
	T_fsmName stateName;
	/* state callback */
	T_fsmCB state;
} T_fsmState;

/**
 *	@brief		Data structure for FSM properties.
 */
typedef struct {
	/* state machine identification */
	T_fsmID id;
	T_fsmName name;
	/* state machine control */
	T_fsmFlag historical : 1;
	/* state machine table */
	const T_fsmState* stateLUT;
	T_fsmSize stateLUTSize;
} T_fsmProp;

/**
 *	@brief		Data structure for FSM control block.
 */
struct fsm_t {
	/* state machine pseudo-private members */
	struct {
		/* state machine control */
		T_fsmFlag firstEntry	 : 1;
		T_fsmFlag transitConEval : 1;
		T_fsmFlag transitLock	 : 1;
		T_fsmFlag transitChain	 : 1;
		/* state machine callbacks */
		T_fsmCB	preProcess;
		T_fsmCB	postProcess;
		/* state machine indices */
		T_fsmIndex reset;
		T_fsmIndex next;
	} privileged;
	/* state machine properties */
	const T_fsmProp* properties;
	/* state machine control */
	T_fsmFlag transitNumber;
	/* state machine data */
	T_fsmData* fsmData;
	T_fsmSize fsmDataSize;
	/* state machine indices */
	T_fsmIndex current;
};

/**
 *	@brief		Defined structured type for FSMs.
 */
typedef struct fsm_t T_fsm;

/* ----------------------------------------------------------------------------
**	Getters.
*/

/**
 *	@def 		GetByteFSMID
 *	@brief		Gets FSM specified machine ID.
 *	@param		FSM		FSM control block handler.
 *	@return		FSM ID (byte).
 */
#define GetByteFSMID(FSM) \
	((FSM).properties->id)

/**
 *	@def 		GetStringFSMName
 *	@brief		Gets FSM specified machine name.
 *	@param		FSM		FSM control block handler.
 *	@return		FSM name (char pointer).
 */
#define GetStringFSMName(FSM) \
	((FSM).properties->name)

/**
 *	@def 		GetByteFSMTotalStates
 *	@brief		Gets FSM maximum or total state count or table size.
 *	@param		FSM		FSM control block handler.
 *	@return		FSM state table size (byte).
 */
#define GetByteFSMTotalStates(FSM) \
	((FSM).properties->stateLUTSize)

/**
 *	@def 		GetByteFSMStateNumber
 *	@brief		Gets FSM state number or index of specified state.
 *	@param		FSM		FSM control block handler.
 *	@param[in]	STATE   FSM state index (byte).
 *	@return		FSM state number (according to order) (byte).
 *	@note		State number is only valid if it also matches with state index.
 */
#define GetByteFSMStateNumber(FSM, STATE) \
	((FSM).properties->stateLUT[STATE].stateNumber)

/**
 *	@def 		GetStringFSMStateName
 *	@brief		Gets FSM specified state name.
 *	@param		FSM		FSM control block handler.
 *	@param[in]	STATE   FSM state index (byte).
 *	@return		FSM state name (char pointer).
 */
#define GetStringFSMStateName(FSM, STATE) \
	((FSM).properties->stateLUT[STATE].stateName)

/**
 *	@def 		GetByteFSMTransitionNumber
 *	@brief		Gets FSM latest transition number of a recently executed state.
 *	@param		FSM		FSM control block handler.
 *	@return		FSM transition number (byte).
 */
#define GetByteFSMTransitionNumber(FSM) \
	((FSM).transitNumber)

/**
 *	@def 		GetByteFSMCurrentStateIndex
 *	@brief		Gets FSM current state index.
 *	@param		FSM		FSM control block handler.
 *	@return		FSM current state index (byte).
 */
#define GetByteFSMCurrentStateIndex(FSM) \
	((FSM).current)

/**
 *	@def 		GetFSMData
 *	@brief		Gets FSM data.
 *	@param		FSM		FSM control block handler.
 *	@param		CAST	FSM data structure type cast.
 *	@param		FIELD	FSM data structure member or field.
 *	@return		FSM data to retrieve (multitype).
 *	@note		Make sure that FSM data address is initialized to
 *				a valid memory location (either static or dynamic).
 */
#define GetFSMData(FSM, CAST, FIELD) \
	(((CAST*)((FSM).fsmData))->FIELD)

/**
 *	@def 		GetFSMDataSize
 *	@brief		Gets FSM data size.
 *	@param		FSM		FSM control block handler.
 *	@return		FSM data size (byte).
 *	@note		Make sure that FSM data address is initialized to
 *				a valid memory location (either static or dynamic).
 */
#define GetFSMDataSize(FSM) \
	((FSM).fsmDataSize)

/**
 *	@def		IsFSMHistorical
 *	@brief		Checks if FSM is historical (initialize at once).
 *	@param		FSM		FSM control block handler.
 *	@param		.
 *	@return		boolean.
 */
#define IsFSMHistorical(FSM) \
	IS((FSM).properties->historical)

/**
 *	@def 		SetFSMData
 *	@brief		Sets FSM data.
 *	@param		FSM		FSM control block handler.
 *	@param		CAST	FSM data structure type cast.
 *	@param		FIELD	FSM data structure member or field.
 *	@param[in]	VAL		FSM data to store (multitype).
 *	@return		.
 *	@note		Make sure that FSM data address is initialized to
 *				a valid memory location (either static or dynamic).
 */
#define SetFSMData(FSM, CAST, FIELD, VAL) { \
	((CAST*)((FSM).fsmData))->FIELD = (VAL); \
}

/**
 *	@def 		SetFSMDataSize
 *	@brief		Sets FSM data size.
 *	@param		FSM		FSM control block handler.
 *	@param[in]	VAL		FSM data size (byte).
 *	@return		.
 *	@note		Make sure that FSM data address is initialized to
 *				a valid memory location (either static or dynamic).
 */
#define SetFSMDataSize(FSM, VAL) \
	(FSM).fsmDataSize = (T_fsmSize)(VAL);

/* ----------------------------------------------------------------------------
**	Macro Functions.
*/

/**
 *	@def		FSM_STATE
 *	@brief		FSM state function declaration and definition macro alias.
 *	@param		NAME	FSM state function name.
 *	@return		(void-type).
 */
#define FSM_STATE(NAME)					T_void NAME(T_fsm FSM_THIS)

/**
 *	@def		FSM_PRE
 *	@brief		FSM preprocessing function declaration and definition macro alias.
 *	@param		NAME	FSM preprocessing function name.
 *	@return		(void-type).
 */
#define FSM_PRE(NAME)					T_void NAME(T_fsm FSM_THIS)

/**
 *	@def		FSM_POST
 *	@brief		FSM postprocessing function declaration and definition macro alias.
 *	@param		NAME	FSM postprocessing function name.
 *	@return		(void-type).
 */
#define FSM_POST(NAME)					T_void NAME(T_fsm FSM_THIS)

/**
 *	@def		StateRequestTransitChain
 *	@brief		Request next state transition to be executed immediately.
 *	@param		FSM		FSM control block handler.
 *	@param		.
 *	@return		.
 *	@note		There should be no immediate transition request althroughout
 *				the state machine nor a closed loop path transition chain.
 */
#define StateRequestTransitChain(FSM) { \
	(FSM).privileged.transitChain = TRUE; \
}

/**
 *	@def		ForceStateEntry
 *	@brief		Forces the state machine to enter a specified state.
 *	@param		FSM				FSM control block handler.
 *	@param		FORCED_STATE	State index (byte).
 *	@return		.
 */
#define ForceStateEntry(FSM, FORCED_STATE) { \
	/* check if forced state index is not the reset state */ \
	if (LT(FORCED_STATE, (FSM).properties->stateLUTSize) \
		&& NEQ(FORCED_STATE, (FSM).privileged.reset)) { \
		/* set next state index to forced state */ \
		(FSM).privileged.next = (FORCED_STATE); \
		/* set current state index to next state */ \
		(FSM).current = (FSM).privileged.reset; \
		/* clear state first-entry flag to allow entry */ \
		(FSM).privileged.firstEntry = FALSE; \
		/* set state transition locked */ \
		(FSM).privileged.transitLock = TRUE; \
	} \
}

/**
 *	@def		ResetStateMachine
 *	@brief		Forces the state machine to enter the reset state so that the
 *  			next time it executes, it will initialize to the first state.
 *	@param		FSM		FSM control block handler.
 *	@return		.
 */
#define ResetStateMachine(FSM) { \
	/* check if state machine is not historical */ \
	if (NOT((FSM).properties->historical)) { \
		/* set next state index to reset state */ \
		(FSM).privileged.next = (FSM).privileged.reset; \
		/* set current state index to next state */ \
		(FSM).current = (FSM).privileged.reset; \
		/* clear state first-entry flag to allow entry */ \
		(FSM).privileged.firstEntry = FALSE; \
		/* set state transition locked */ \
		(FSM).privileged.transitLock = TRUE; \
	} \
}

/**
 *	@def		StateEntry
 *	@brief		Performs initialization on first (or each) entry and executes the
 *				process or routine block if the state is entering first time only.
 *	@param		ENTRY_PROCESS	State entry action, routine, process or algorithm.
 *	@return		.
 *	@note		Must be placed above all procedures inside the state, preferably
 *				before StateAction.
 */
#define StateEntry(ENTRY_PROCESS) { \
	/* clear state transition lock and number */ \
	FSM_THIS.privileged.transitLock = FALSE; \
	FSM_THIS.transitNumber = NULL; \
	/* check if state is entering first */ \
	if (NOT(FSM_THIS.privileged.firstEntry)) { \
		/* execute state on-entry process */ \
		ENTRY_PROCESS; \
		/* set state first-entry flag to avoid re-entry */ \
		FSM_THIS.privileged.firstEntry = TRUE; \
	} \
}

/**
 *	@def		StateAction
 *	@brief		Standard state actions or Moore operation.
 *	@param		MOORE_ACTION	Moore state action, routine, process or algorithm.
 *	@return		.
 *	@note		Must be placed after StateEntry and before StateTransition.
 */
#define StateAction(MOORE_ACTION) { \
	/* execute in-state or during (Moore) process */ \
	MOORE_ACTION; \
}

/**
 *	@def		StateTransition
 *	@brief		Performs conditional evaluation which shall determines what
 *  			exact state the state machine will execute next and executes
 *				transition action block or Meally operation before leaving the
 *				state (if specified).
 *	@param		TRANS_CON		Transition conditional expression.
 *	@param		NEXT_STATE		Next state index (byte).
 *	@param		MEALLY_ACTION	Meally action, process or operation.
 *	@return		.
 *	@note		The order or priority of the transition conditional expression
 *				depends on which condition is evaluated first. Thus, the first
 *				to be evaluated has the highest priority while the next and
 *				remaining conditional expressions have descending priority,
 *				one after the other. The state transition evaluator favors
 *				the first to be evaluated true in the list even though the
 *				remaining transition conditional expressions might also be
 *				true. The next state index specified by the transition is the
 *				final next state the state machine will execute. If there's no
 *				transition conditional expression that is true, the next state
 *				will be the same current state being executed.
 *	@note		For standard state transition, use FSM_NEXT for the TRANS_CON
 *				and specify NEXT_STATE manually. For state transition with
 *				(multiple) specific conditional expression(s), specify both
 *				TRANS_CON and NEXT_STATE manually (separate StateTransition
 *				for every specific conditional expression). For state transition
 *				requiring default case or final "else" statement, use FSM_ELSE
 *				for the TRANS_CON and specify NEXT_STATE manually but at or as
 *				the last StateTransition. For last state self-transition, use
 *				FSM_LAST for the TRANS_CON and FSM_SELF for the NEXT_STATE.
 *				For standard state self-transition, use FSM_SELF for both
 *				TRANS_CON and NEXT_STATE. The state table must guarantee to
 *				have FSM_SELF as the first state in the list with zero as its
 *				index value.
 *	@note		Must be placed after StateAction and before StateExit.
 */
#define StateTransition(TRANS_CON, NEXT_STATE, MEALLY_ACTION) { \
	/* check if state transition is not locked */ \
	if (NOT(FSM_THIS.privileged.transitLock)) { \
		/* save evaluated state transition condition logic */ \
		FSM_THIS.privileged.transitConEval = (TRANS_CON); \
		/* check evaluated state transition condition */ \
		if (IS(FSM_THIS.privileged.transitConEval)) { \
			/* execute state on-transition (Meally) process */ \
			MEALLY_ACTION; \
			/* set next state index */ \
			FSM_THIS.privileged.next = (NEXT_STATE); \
			/* set state transition locked */ \
			FSM_THIS.privileged.transitLock = TRUE; \
		} \
		/* increment state transition number */ \
		FSM_THIS.transitNumber++; \
	} \
}

/**
 *	@def		StateExit
 *	@brief		Performs other necessary operations such as executing the process
 *				or routine block as its last operation before leaving the state.
 *	@param		EXIT_PROCESS	State exit action, routine, process or algorithm.
 *	@return		.
 *	@note		Must be placed below all procedures inside the state, preferably
 *				after StateTransition(s).
 */
#define StateExit(EXIT_PROCESS) { \
	/* check if state transition is locked */ \
	if (IS(FSM_THIS.privileged.transitLock)) { \
		/* check if next state index is neither a self-transition
		 * nor the current state index itself (self-redirection),
		 * and must be within the bounds of the state table */ \
		if (NEQ(FSM_THIS.privileged.next, FSM_SELF) \
			&& NEQ(FSM_THIS.privileged.next, FSM_THIS.current) \
			&& LT(FSM_THIS.privileged.next, \
				FSM_THIS.properties->stateLUTSize)) { \
			/* execute state on-exit process */ \
			EXIT_PROCESS; \
			/* set current state index to next state index */ \
			FSM_THIS.current = FSM_THIS.privileged.next; \
			/* clear state first-entry flag to allow entry */ \
			FSM_THIS.privileged.firstEntry = FALSE; \
		} else { \
			/* set next state index back to current state index */ \
			FSM_THIS.privileged.next = FSM_THIS.current; \
		} \
	} \
}

/* ----------------------------------------------------------------------------
**	API Functions.
*/

/**
 *	@fn			T_fsm* initFSM(T_fsm*, const T_fsmProp*, T_fsmData*, T_fsmIndex)
 *	@brief 		Initialize a finite state machine.
 *	@param		automaton	FSM control block handler.
 *	@param[in]	properties  FSM properties handler (must be constant).
 *	@param[in]	structData	FSM data (cast to T_fsmData*).
 *	@param[in]	initIndex	FSM initial (reset) state index.
 *	@return		fsm-pointer (same with first parameter).
 *	@note		If FSM has no other state other than its initial state, no
 *  			state transition will be held and the initial state will be
 *  			solely executed.
 */
extern T_fsm* initFSM(T_fsm* automaton, const T_fsmProp* properties,
 	T_fsmData* structData, T_fsmIndex initIndex);

 /**
  *	@fn			T_void setFSMPreAndPostFunctions(T_fsm*, T_fsmCB, T_fsmCB)
  *	@brief		Sets the address of the state's preprocess and postprocess
  *  			functions which executes before and after the state, respectively.
  *	@param		automaton	FSM control block handler.
  *	@param[in]	preProcess  State's preprocess function.
  *	@param[in]	postProcess State's postprocess function.
  *	@return		.
  *	@note		The pre and post functions should not be changed once it is set.
  */
extern T_void setFSMPreAndPostFunctions(T_fsm* automaton,
	T_fsmCB preProcess, T_fsmCB postProcess);

/**
 *	@fn			T_bit dispatchFSM(T_fsm*)
 *	@brief		Executes single state (with/without chained transition).
 *	@param		automaton	FSM control block handler.
 *	@return		dispatch success.
 *	@warning	The FSM should have at least one state to dispatch.
 */
extern T_bit dispatchFSM(T_fsm* automaton);

/**
 *	@brief		Starts logging (through serial output) currently executed or
 *				active parent FSM state.
 *	@note		Must be registered through setFSMPreAndPostFunctions.
 */
extern FSM_PRE(logFSMParentStatePreprocess);

/**
 *	@brief		Starts logging (through serial output) currently executed or
 *				active child FSM state.
 *	@note		Must be registered through setFSMPreAndPostFunctions.
 */
extern FSM_PRE(logFSMChildStatePreprocess);

/**
 *	@brief		Ends logging (through serial output) currently executed or
 *				active state with transition activation, next state selection,
 *				and hexadecimal view of the application data for parent FSM
 *				states only.
 *	@note		Must be registered through setFSMPreAndPostFunctions. Also set
 *				FSM data and its data size to be included in hexdump.
 *	@note		Transition number is only valid if there's no chained transition
 *				between the current and next state.
 *  @note		Hex dump is organized into a single row of 8-bits per column
 *				separated by whitespace.
 */
extern FSM_POST(logFSMParentStatePostprocess);

/**
 *	@brief		Ends logging (through serial output) currently executed or
 *				active state with transition activation and next state
 *				selection for child FSM states only.
 *	@note		Must be registered through setFSMPreAndPostFunctions.
 *	@note		Transition number is only valid if there's no chained transition
 *				between the current and next state.
 */
extern FSM_POST(logFSMChildStatePostprocess);

#endif /* FSM_H. */
