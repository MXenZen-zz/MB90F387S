/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*  Automatic generated C-code by the application:                              */
/*     HFSM Editor v1.4r3                                                       */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Methodology: Hierarchical Switch-case state. [v1.5r1]                        */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Exported function: T_void appLED(T_void);                                    */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Module header proposed by the user (Start).                                  */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
/*     Copyright (C) 2015-2017 Xeno Xerxes Masong (xxmasong@gmail.com)          */
/*                                                                              */
/*     This program does not guarantee that it shall fulfill its task           */
/*     under all circumstances. Thus, the author/developer shall not            */
/*     be held liable for any damages that might be incurred by the             */
/*     device using this program, or for any reason whatsoever.                 */
/*                                                                              */
/*     This program is free software: you can redistribute it and/or            */
/*     modify it under the terms of the GNU General Public License as           */
/*     published by the Free Software Foundation, either version 3 of           */
/*     the License, or (at your option) any later version.                      */
/*                                                                              */
/*     This program is distributed in the hope that it will be useful,          */
/*     but WITHOUT ANY WARRANTY; without even the implied warranty of           */
/*     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the             */
/*     GNU General Public License for more details.                             */
/*                                                                              */
/*     You should have received a copy of the GNU General Public License        */
/*     along with this program. If not, see <https://www.gnu.org/licenses/>.    */
/*                                                                              */
/*  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
/*     Target Hardware Information:                                             */
/*                                                                              */
/*         MCU         : F2MC-16LX MB90385 Series                               */
/*         CPU         : MB90F387S                                              */
/*         Vcc         : 5.0 V                                                  */
/*         Frequency   : 16 MHz (4 MHz PLLx4)                                   */
/*         Inputs      : P25, P27                                               */
/*         Outputs     : P10-P14, PPG2(P16)-PPG3(P17)                           */
/*         Driver      : N/A                                                    */
/*         Helper      : ADC, DIO, PPG                                          */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
/* Module header proposed by the user (End).                                    */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Initialization proposed by the user (Start).                                 */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
  
  #include <ADC/adc.h>
  #include <GPIO/dio.h>
  #include <TMR/ppg.h>
  
  /* --------------------------------------------------------------------------
  **  Test Variables.
  */
  
  /**
   *  @var        appLEDData
   *  @brief      LED application user data.
   */
  static struct {
      T_uint8 noteIndex : 7;
      T_uint16 noteFreq;
      T_uint32 blinkCtr;
      T_pinLevel state25;
      T_pinLevel state27;
  } appLEDData;
  
  /* --------------------------------------------------------------------------
  **  Test Helper Functions.
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

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
/* Initialization proposed by the user (End).                                   */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Entry flags (Start).                                                         */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
  typedef struct {
      T_bit flg            :1;
  } T_EntryFsmFlg;
  static T_EntryFsmFlg entryFsm;
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
/* Entry flags (End).                                                           */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Automatic initialization (Start).                                            */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
 /* States index. */
  #define  i_LED_START  ((T_u8)0)
  #define  i_LED_POS_1  ((T_u8)1)
  #define  i_LED_POS_2  ((T_u8)2)
  #define  i_LED_POS_3  ((T_u8)3)
  #define  i_LED_POS_4  ((T_u8)4)
  #define  i_LED_POS_5  ((T_u8)5)

 /* Index variable. */
static T_u8 ind_appLED = i_LED_START;

#if defined(FSM_DEBUG)
    static T_u8 debug_transNumber = (T_u8)0;
    static const T_char* debug_stateNames[] = {
        "LED_START",
        "LED_POS_1",
        "LED_POS_2",
        "LED_POS_3",
        "LED_POS_4",
        "LED_POS_5",
    };
#endif


/* Macros & functions.                                                          */
/* Force the FSM to the initial state.                                          */
#if defined(FSM_DEBUG)
    #define appLED_Init() { ind_appLED = i_LED_START; entryFsm.flg = 0U; debug_transNumber = (T_u8)0U;}
#else
    #define appLED_Init() { ind_appLED = i_LED_START; entryFsm.flg = 0U; }
#endif

/* This is not a history FSM.                                                   */
#define _appLED_Init()  {appLED_Init(); /* Children: */ }

/* Confirm that the FSM has reached a final state.                              */
#define appLED_End() (\
    0)

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
/* Automatic initialization (End).                                              */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Local child functions  (Start).                                              */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
/* Local child functions  (End).                                                */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Debug customized macros.                                                     */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
#if defined(FSM_DEBUG)
    #define FSM_STATE_NAME()   debug_stateNames[ind_appLED]
    #define FSM_TRANS_NUMBER() debug_transNumber
    #define FSM_NAME()         "appLED"
#else
    #define FSM_STATE_NAME()
    #define FSM_TRANS_NUMBER()
    #define FSM_NAME()
#endif

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* FSM dispatcher function to be called by the O.S.                             */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* In this test, an FSM will simulate a blinking "straight ring / one-hot       */
/* counter" - circulating a single LED ON state around a ring of five (active   */
/* LOW) LEDs. Two pushbuttons control the direction of the circulation (CW,     */
/* CCW) or sequence of LED ON state and they also increment and/or decrement    */
/* the frequency of the generated tone through the piezoelectric buzzer.        */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
T_void appLED(T_void)
{
    /* Chain transition flag. */
    T_bit fsm_chainTransition;

    /* User actions to be executed before analyse the state. */
    /* update pin state */
    updatePin25State();
    updatePin27State();

    #if defined(FSM_DEBUG)
        debug_transNumber = (T_u8)0U;
    #endif
    /* Chain transition loop. */
    do{
        fsm_chainTransition = FALSE;
        /* Next state analyser. */
        switch(ind_appLED){
            case i_LED_START:
                /* Next state selection. */
                if(IS(appLEDData.state25) && NOT(appLEDData.state27)){	/* [1]. */
                    /* Pointing to the next state. */
                    ind_appLED = i_LED_POS_5;
                    #if defined(FSM_DEBUG)
                        debug_transNumber = (T_u8)1;
                    #endif
                    /* Chain transition. */
                    fsm_chainTransition = TRUE;
                }else if(NOT(appLEDData.state25) && IS(appLEDData.state27)){	/* [2]. */
                    /* Pointing to the next state. */
                    ind_appLED = i_LED_POS_1;
                    #if defined(FSM_DEBUG)
                        debug_transNumber = (T_u8)2;
                    #endif
                    /* Chain transition. */
                    fsm_chainTransition = TRUE;
                }
            break;
            case i_LED_POS_1:
                /* Entry check */
                if(!((T_bit)entryFsm.flg)){
                    entryFsm.flg = (T_bit)1;
                    /* Entry actions */
                    /* LED ON */
                    writeDigital(PIN10, PIN_LOW);
                }
                /* State actions (Moore). */
                /* LED BLINK */
                if (NOT(appLEDData.blinkCtr % 100UL)) {
                    writeDigital(PIN10, !readDigital(PIN10));
                }
                /* Next state selection. */
                if(IS(appLEDData.state25) && NOT(appLEDData.state27)){	/* [1]. */
                    /* Exit actions. */
                    /* LED OFF */
                    writeDigital(PIN10, PIN_HIGH);
                    /* Transition actions (Meally). */
                    /* stop pulse generation */
                    stopPPG(PPG_CH23);
                    /* decrement note index */
                    COND(NEQ(appLEDData.noteIndex, 0U), 
                        appLEDData.noteIndex--, appLEDData.noteIndex);
                    /* Pointing to the next state. */
                    ind_appLED = i_LED_POS_5;
                    #if defined(FSM_DEBUG)
                        debug_transNumber = (T_u8)1;
                    #endif
                    /* Reset entry flag */
                    entryFsm.flg = 0U;
                }else if(NOT(appLEDData.state25) && IS(appLEDData.state27)){	/* [2]. */
                    /* Exit actions. */
                    /* LED OFF */
                    writeDigital(PIN10, PIN_HIGH);
                    /* Transition actions (Meally). */
                    /* stop pulse generation */
                    stopPPG(PPG_CH23);
                    /* increment note index */
                    COND(NEQ(appLEDData.noteIndex, 127U), 
                        appLEDData.noteIndex++, appLEDData.noteIndex);
                    /* Pointing to the next state. */
                    ind_appLED = i_LED_POS_2;
                    #if defined(FSM_DEBUG)
                        debug_transNumber = (T_u8)2;
                    #endif
                    /* Reset entry flag */
                    entryFsm.flg = 0U;
                }else { /* Else actions. */
                    /* generate adjustable tone */
                    pulseOutByFrequency(PPG_CH23, 
                        getNoteFrequency(appLEDData.noteIndex), 
                            readAnalog(PIN_AN0));
                }
            break;
            case i_LED_POS_2:
                /* Entry check */
                if(!((T_bit)entryFsm.flg)){
                    entryFsm.flg = (T_bit)1;
                    /* Entry actions */
                    /* LED ON */
                    writeDigital(PIN11, PIN_LOW);
                }
                /* State actions (Moore). */
                /* LED BLINK */
                if (NOT(appLEDData.blinkCtr % 200UL)) {
                    writeDigital(PIN11, !readDigital(PIN11));
                }
                /* Next state selection. */
                if(IS(appLEDData.state25) && NOT(appLEDData.state27)){	/* [1]. */
                    /* Exit actions. */
                    /* LED OFF */
                    writeDigital(PIN11, PIN_HIGH);
                    /* Transition actions (Meally). */
                    /* stop pulse generation */
                    stopPPG(PPG_CH23);
                    /* decrement note index */
                    COND(NEQ(appLEDData.noteIndex, 0U), 
                        appLEDData.noteIndex--, appLEDData.noteIndex);
                    /* Pointing to the next state. */
                    ind_appLED = i_LED_POS_1;
                    #if defined(FSM_DEBUG)
                        debug_transNumber = (T_u8)1;
                    #endif
                    /* Reset entry flag */
                    entryFsm.flg = 0U;
                }else if(NOT(appLEDData.state25) && IS(appLEDData.state27)){	/* [2]. */
                    /* Exit actions. */
                    /* LED OFF */
                    writeDigital(PIN11, PIN_HIGH);
                    /* Transition actions (Meally). */
                    /* stop pulse generation */
                    stopPPG(PPG_CH23);
                    /* increment note index */
                    COND(NEQ(appLEDData.noteIndex, 127U), 
                        appLEDData.noteIndex++, appLEDData.noteIndex);
                    /* Pointing to the next state. */
                    ind_appLED = i_LED_POS_3;
                    #if defined(FSM_DEBUG)
                        debug_transNumber = (T_u8)2;
                    #endif
                    /* Reset entry flag */
                    entryFsm.flg = 0U;
                }else { /* Else actions. */
                    /* generate adjustable tone */
                    pulseOutByFrequency(PPG_CH23, 
                        getNoteFrequency(appLEDData.noteIndex), 
                            readAnalog(PIN_AN0));
                }
            break;
            case i_LED_POS_3:
                /* Entry check */
                if(!((T_bit)entryFsm.flg)){
                    entryFsm.flg = (T_bit)1;
                    /* Entry actions */
                    /* LED ON */
                    writeDigital(PIN12, PIN_LOW);
                }
                /* State actions (Moore). */
                /* LED BLINK */
                if (NOT(appLEDData.blinkCtr % 400UL)) {
                    writeDigital(PIN12, !readDigital(PIN12));
                }
                /* Next state selection. */
                if(IS(appLEDData.state25) && NOT(appLEDData.state27)){	/* [1]. */
                    /* Exit actions. */
                    /* LED OFF */
                    writeDigital(PIN12, PIN_HIGH);
                    /* Transition actions (Meally). */
                    /* stop pulse generation */
                    stopPPG(PPG_CH23);
                    /* decrement note index */
                    COND(NEQ(appLEDData.noteIndex, 0U), 
                        appLEDData.noteIndex--, appLEDData.noteIndex);
                    /* Pointing to the next state. */
                    ind_appLED = i_LED_POS_2;
                    #if defined(FSM_DEBUG)
                        debug_transNumber = (T_u8)1;
                    #endif
                    /* Reset entry flag */
                    entryFsm.flg = 0U;
                }else if(NOT(appLEDData.state25) && IS(appLEDData.state27)){	/* [2]. */
                    /* Exit actions. */
                    /* LED OFF */
                    writeDigital(PIN12, PIN_HIGH);
                    /* Transition actions (Meally). */
                    /* stop pulse generation */
                    stopPPG(PPG_CH23);
                    /* increment note index */
                    COND(NEQ(appLEDData.noteIndex, 127U), 
                        appLEDData.noteIndex++, appLEDData.noteIndex);
                    /* Pointing to the next state. */
                    ind_appLED = i_LED_POS_4;
                    #if defined(FSM_DEBUG)
                        debug_transNumber = (T_u8)2;
                    #endif
                    /* Reset entry flag */
                    entryFsm.flg = 0U;
                }else { /* Else actions. */
                    /* generate adjustable tone */
                    pulseOutByFrequency(PPG_CH23, 
                        getNoteFrequency(appLEDData.noteIndex), 
                            readAnalog(PIN_AN0));
                }
            break;
            case i_LED_POS_4:
                /* Entry check */
                if(!((T_bit)entryFsm.flg)){
                    entryFsm.flg = (T_bit)1;
                    /* Entry actions */
                    /* LED ON */
                    writeDigital(PIN13, PIN_LOW);
                }
                /* State actions (Moore). */
                /* LED BLINK */
                if (NOT(appLEDData.blinkCtr % 800UL)) {
                    writeDigital(PIN13, !readDigital(PIN13));
                }
                /* Next state selection. */
                if(IS(appLEDData.state25) && NOT(appLEDData.state27)){	/* [1]. */
                    /* Exit actions. */
                    /* LED OFF */
                    writeDigital(PIN13, PIN_HIGH);
                    /* Transition actions (Meally). */
                    /* stop pulse generation */
                    stopPPG(PPG_CH23);
                    /* decrement note index */
                    COND(NEQ(appLEDData.noteIndex, 0U), 
                        appLEDData.noteIndex--, appLEDData.noteIndex);
                    /* Pointing to the next state. */
                    ind_appLED = i_LED_POS_3;
                    #if defined(FSM_DEBUG)
                        debug_transNumber = (T_u8)1;
                    #endif
                    /* Reset entry flag */
                    entryFsm.flg = 0U;
                }else if(NOT(appLEDData.state25) && IS(appLEDData.state27)){	/* [2]. */
                    /* Exit actions. */
                    /* LED OFF */
                    writeDigital(PIN13, PIN_HIGH);
                    /* Transition actions (Meally). */
                    /* stop pulse generation */
                    stopPPG(PPG_CH23);
                    /* increment note index */
                    COND(NEQ(appLEDData.noteIndex, 127U), 
                        appLEDData.noteIndex++, appLEDData.noteIndex);
                    /* Pointing to the next state. */
                    ind_appLED = i_LED_POS_5;
                    #if defined(FSM_DEBUG)
                        debug_transNumber = (T_u8)2;
                    #endif
                    /* Reset entry flag */
                    entryFsm.flg = 0U;
                }else { /* Else actions. */
                    /* generate adjustable tone */
                    pulseOutByFrequency(PPG_CH23, 
                        getNoteFrequency(appLEDData.noteIndex), 
                            readAnalog(PIN_AN0));
                }
            break;
            case i_LED_POS_5:
                /* Entry check */
                if(!((T_bit)entryFsm.flg)){
                    entryFsm.flg = (T_bit)1;
                    /* Entry actions */
                    /* LED ON */
                    writeDigital(PIN14, PIN_LOW);
                }
                /* State actions (Moore). */
                /* LED BLINK */
                if (NOT(appLEDData.blinkCtr % 1600UL)) {
                    writeDigital(PIN14, !readDigital(PIN14));
                }
                /* Next state selection. */
                if(IS(appLEDData.state25) && NOT(appLEDData.state27)){	/* [1]. */
                    /* Exit actions. */
                    /* LED OFF */
                    writeDigital(PIN14, PIN_HIGH);
                    /* Transition actions (Meally). */
                    /* stop pulse generation */
                    stopPPG(PPG_CH23);
                    /* decrement note index */
                    COND(NEQ(appLEDData.noteIndex, 0U), 
                        appLEDData.noteIndex--, appLEDData.noteIndex);
                    /* Pointing to the next state. */
                    ind_appLED = i_LED_POS_4;
                    #if defined(FSM_DEBUG)
                        debug_transNumber = (T_u8)1;
                    #endif
                    /* Reset entry flag */
                    entryFsm.flg = 0U;
                }else if(NOT(appLEDData.state25) && IS(appLEDData.state27)){	/* [2]. */
                    /* Exit actions. */
                    /* LED OFF */
                    writeDigital(PIN14, PIN_HIGH);
                    /* Transition actions (Meally). */
                    /* stop pulse generation */
                    stopPPG(PPG_CH23);
                    /* increment note index */
                    COND(NEQ(appLEDData.noteIndex, 127U), 
                        appLEDData.noteIndex++, appLEDData.noteIndex);
                    /* Pointing to the next state. */
                    ind_appLED = i_LED_POS_1;
                    #if defined(FSM_DEBUG)
                        debug_transNumber = (T_u8)2;
                    #endif
                    /* Reset entry flag */
                    entryFsm.flg = 0U;
                }else { /* Else actions. */
                    /* generate adjustable tone */
                    pulseOutByFrequency(PPG_CH23, 
                        getNoteFrequency(appLEDData.noteIndex), 
                            readAnalog(PIN_AN0));
                }
            break;
            default:
                /* State index error trap (MISRA requiremment). */
                /* fail-safe reset */
                appLED_Init();
            break;
        }
    }while(fsm_chainTransition);

    /* User actions to be executed after analyse the state. */
    /* increment blink counter */
    ++appLEDData.blinkCtr;
}


/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Ending code proposed by the user (Start).                                    */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/

/* ----------------------------------------------------------------------------
**  Inline Functions.
*/

/**
 *  @fn         T_void init(T_void)
 *  @brief      Initialization / setup code runs once.
 *  @param      .
 *  @return     .
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

    __EI();
}

/**
 *  @fn         T_void debug(T_void)
 *  @brief      Iteration / loop code runs repeatedly.
 *  @param      .
 *  @return     .
 */
#pragma inline debug
static T_void debug(T_void)
{
    /* run application FSM dispatcher */
    appLED();
}

/* ----------------------------------------------------------------------------
**  Main Function.
*/

/**
 *  @fn         T_void main(T_void)
 *  @brief      Main / program entry point.
 *  @param      .
 *  @return     .
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

/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/* Diagram comments (Start).                                                    */
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
/* Diagram comments (End).                                                      */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -*/
/* Ending code proposed by the user (End).                                      */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*  End of the automatic generated C-code.                                      */
/*++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/
