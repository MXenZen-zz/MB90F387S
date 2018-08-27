/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Tone (PPG Output)							          				     */
/**
 *	@file		PWM/tone.h
 * 	@brief		This file contains tone types, macro functions
 * 				and API functions.
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

#ifndef TONE_H
#define TONE_H

#include <PWM/notes.h>
#include <TMR/ppg.h>

/* ----------------------------------------------------------------------------
**	Tone Types.
*/

/**
 * 	@brief		Defined enumerated type for tone channel.
 */
typedef enum {
	TONE_CH01 = PPG_CH01,		/**< combined channels 0 and 1 */
	TONE_CH23 = PPG_CH23		/**< combined channels 2 and 3 */
} T_toneChannel;

/**
 * 	@brief		Defined type for tone frequency data type.
 */
typedef T_gptFrequency T_toneFrequency;

/**
 * 	@brief		Defined type for tone duration data type.
 */
typedef T_gptInterval  T_toneDuration;

/* ----------------------------------------------------------------------------
**	Tone Macro Functions.
*/

/**
 * 	@def		Tone
 * 	@brief		Generates a square wave of the specified frequency with 50%
 * 				duty cycle on a 16-bit PPG.
 * 	@param[in]	CH		Tone channel (byte).
 * 	@param[in]	FREQ	Tone frequency in hertz (dword).
 *	@return  	.
 *  @warning	Do not exceed below 30 Hz or beyond 62.5 kHz.
 */
#define Tone(CH, FREQ) { \
	pulseOutByFrequency(CH, FREQ, Mask(6U, 0U)); \
}

/**
 * 	@def		NoTone
 * 	@brief		Stops generating tone.
 * 	@param[in]	CH		Tone channel (byte).
 *	@return  	.
 */
#define NoTone(CH) { \
	stopPPG(CH); \
}

/* ----------------------------------------------------------------------------
**	Tone API Functions.
*/

/**
 * 	@fn 		T_void playTune(T_toneChannel, const T_toneFrequency*,
 * 					const T_toneDuration*, T_uint16)
 *	@brief		Plays a sequence of tones one at a time with respective durations.
 *	@attention	PPG and TBT must be initialized already!
 * 	@param[in]	channel			Tone Channel.
 * 	@param[in]	tuneLength		Total number of tones to play.
 * 	@param[in]	frequencyTable	List of tone frequencies to play in sequence (hertz).
 * 	@param[in]	durationTable	List of tone durations to play in sequence (ms).
 * 	@return		.
 */
extern T_void playTune(T_toneChannel channel, const T_toneFrequency* frequencyTable,
	const T_toneDuration* durationTable, T_uint16 tuneLength);


/**
 * 	@fn 		T_void playRTTTL(T_toneChannel, const T_char*)
 *	@brief		Plays RTTTL formatted string.
 *	@attention	PPG and TBT must be initialized already!
 * 	@param[in]	channel		Tone Channel.
 * 	@param[in]	rtttlStr	RTTTL formatted string to play.
 * 	@return		.
 * 	@note		The string must be in the format "name:d=N,o=N,b=NNN:notes"
 * 				and in the same order with no spaces and other symbols other
 * 				than approved by RTTTL.	The RTTTL format is a string divided
 * 				into three sections: name, default value or settings, and data
 * 				or notes. The name part or section is discarded by the player
 * 				(although it must be present) while the settings part contains
 * 				'd' (default duration of a note), 'o' (default octave), and 'b'
 * 				(tempo in beats per minute). The notes section contains the
 * 				sequence of notes to play separated by commas. The note is in
 * 				the format "NP#.O" where 'N' is the duration of the note, 'P'
 * 				is the pitch of the note (with or without '#' (sharp)), '.' is
 * 				for dotted rhythm (optional), and 'O' is the scale or octave of
 * 				the note. To generate a pause, replace the pitch of the note
 * 				with 'p' and the octave of the note should be left out of the
 * 				notation.
 * @see			Read further regarding RTTTL online.
 */
extern T_void playRTTTL(T_toneChannel channel, const T_char* rtttlStr);

#endif /* TONE_H. */
