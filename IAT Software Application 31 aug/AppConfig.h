/* ----------------------------------------------------------------------------
 *            HOLT INTEGRATED CIRCUITS Applications Engineering
 * ----------------------------------------------------------------------------
 * Copyright (c) 2011, Holt Integrated Circuits
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Holt's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY HOLT "AS IS" AND ANY EXPRESSED OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL HOLT BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES{    } LOSS OF USE, DATA,
 * OR PROFITS{    } OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
        - Complies with "Holt HI-6130 API Library Software Manual pending Rev 1.1"
	  API calls.
	- Split registers calls further to reflect the functionality.

 */
#define IAR 1

#ifdef IAR
	#include <time.h>
	#include <stdlib.h>
	#include <stdio.h>
	#define MSG_BASE_ADDRESS  0x62000000 
#endif

#ifdef WIN32
	#include <windows.h>
	#define _DECL	WINAPI
	#define _EXTERN
#else
	#define _DECL
	#define _EXTERN
#endif

#ifdef LINUX
	#include <emacepl/stdemace.h>
	#include "../linuxutil.h"
#endif

#ifdef VX_WORKS
	#include "../LibPrj/include/stdemace.h"
	#include "../utils/vxwrksuti.h"
#endif
#ifdef __cplusplus
extern "C" {
#endif

#define BUFFER_ADDRESS 0x00

// install flag for BC,RT,RT2,MT, MT-I

#define NULL_MASK 0
#define CHN_ID0 0
#define HOLT_RX_CMD 0
#define HOLT_TX_CMD 1
#define HOLT_RT_MODIFY_ALL 0xFFFF
#define TRUE 1
#define FALSE 0

#define MSG_BLK_LEN 10

#define  U32 unsigned long
#define  S32 long
#define  U16 unsigned short
#define  S16 short
#define  U8  unsigned char
#define  S8  char

#define US unsigned int

#define READ_REG 0
#define SET_MASK 1
#define CLR_MASK 2
#define NULL_MASK 0
#define CHN_ID0 0

#define RECEIVE 0
#define TRANSMIT 1

#define DBLK_ID 255
#define OP_IDS 32
#define RTS 32
#define FRM_TYPE 2
#define OP_CODE_CNT 512

// Addition data block definition can be added
#define DBK0 0
#define DBK1 1
#define DBK2 2
#define DBK3 3
#define DBK4 4
#define DBK5 5
#define DBK6 6
#define DBK7 7
#define DBK8 8
#define DBK9 9

#define  DBK10 10
#define  DBK11 11
#define  DBK12 12
#define  DBK13 13
#define  DBK14 14
#define  DBK15 15
#define  DBK16 16
#define  DBK17 17
#define  DBK18 18
#define  DBK19 19

// BC opcodes 
#define LT        0
#define GP0       0
#define GTorEQ    16
#define nGP0      16
#define EQ        1
#define GP1       1
#define GP2       2
#define nEQ       17
#define nGP1      17
#define nGP2      18
#define nGP3      19
#define nGP4      20
#define nGP5      21
#define nGP6      22
#define nGP7      23
#define nRESP     8
#define RESP      24
#define nFMTERR   25
#define GBLOCK    10
#define nGBLOCK   26
#define MASKSTAT  11
#define nMASKSTAT 27
#define GOODMSG   28
#define x1RETRY   13
#define n1RETRY   29
#define x2RETRY   14
#define ALWAYS    15
#define NEVER     31

// Major Minor frame
U16 HOLT_FRAME_MAJOR=0;
U16 HOLT_FRAME_OTHER=1;
U16 HOLT_FRAME_MINOR=2;

// USER CONFIGURABLE section
// Buffer manager  refer to Hi6130 data sheet for user memory MAP
U16 BC_BUF_BASE  =0x0800;   // start of host allocated static RAM till 0x7fff  words
U16 RT_BUF_BASE  =0x0800;   
U16 RT2_BUF_BASE =0x0800;   
U16 MT_BUF_BASE  =0x0800;   
U16 DEVICE_SCRATCH_PAD =0x5000; 

// BC
U16 INST_LIST_ADDR   	=0x1000; 
U16 BC_MAJOR_BASE_ADDR  =0x1000;
U16 BC_MINOR_BASE_ADDR  =0x1000;
U16 MSG_BLK_FULL        =0x1200;  
U16 MSG_BLK_ADDR        =0x1300;  
U16 ASYNC_BLK_ADDR		=0x0800;
U16 ASYNC_RT_RT_ADDR 	=0x0800;
U16 DATA_BLK_ADDR		=0x0800;
U16 RT1_DATA_BLK_ADDR	=0x0800;
U16 RT2_DATA_BLK_ADDR	=0x0800;
// END USER CONFIGUTSRION section


// following section is fixed  
U16 SMT_FILTER_TABLE_BASE_ADDR           =0x100;
U16 IMT_FILTER_TABLE_BASE_ADDR           =0x100;
U16 RT1_ILLEGAL_TABLE_BASE_ADDR			 =0x200; // RT1 default illegalization table addr range =0x0200 to =0x02FF
U16 RT1_RX_DESCRIP_TABLE_BASE_ADDR		 =0x400; // RT1 default descriptor table addr range =0x0400 to =0x05FF
U16 RT1_TX_DESCRIP_TABLE_BASE_ADDR		 =0x480;
U16 RT1_RX_DESCRIP_MODE_TABLE_BASE_ADDR  =0x500; // RT1 default descriptor table addr range =0x0400 to =0x05FF
U16 RT1_TX_DESCRIP_MODE_TABLE_BASE_ADDR  =0x580;

U16 RT2_ILLEGAL_TABLE_BASE_ADDR			 =0x300; 
U16 RT2_RX_DESCRIP_TABLE_BASE_ADDR		 =0x600; // RT1 default descriptor table addr range =0x0400 to =0x05FF
U16 RT2_TX_DESCRIP_TABLE_BASE_ADDR		 =0x680;
U16 RT2_RX_DESCRIP_MODE_TABLE_BASE_ADDR  =0x700; // RT1 default descriptor table addr range =0x0400 to =0x05FF
U16 RT2_TX_DESCRIP_MODE_TABLE_BASE_ADDR  =0x780;

/* Global (used for all modes) Message Structure for decoded 1553 msgs */
typedef struct MSGSTRUCT
{
	U16 uType;				/* Contains the msg type (see above) */
	U16 uBlkSts;			/* Contains the block status word */
	U16 uTimeTag;			/* Time tag of message */
	U16 uCmdWrd1;			/* First command word */
	U16 uCmdWrd2;			/* Second command word (RT to RT) */
	U16 uCmdWrd1Flg;		/* Is command word 1 valid? */
	U16 uCmdWrd2Flg;		/* Is command word 2 valid? */
	U16 uStsWrd1;			/* First status word */
	U16 uStsWrd2;			/* Second status word */
	U16 uStsWrd1Flg;		/* Is status word 1 valid? */
	U16 uStsWrd2Flg;		/* Is status word 2 valid? */
	U16 uWordCount;			/* Number of valid data words */
	U16 aDataWrds[32];		/* An array of data words */

	/* The following are only applicable in BC mode */
	U16 uBCCtrlWrd;			/* Contains the BC control word */
	U16 uBCGapTime;			/* Message gap time word */
	U16 uBCLoopBack1;		/* First looped back word */
	U16 uTimeTag2;			/* wBCLoopBack2 is redefined as TimeTag2 */
	U16 uBCLoopBack1Flg;	/* Is loop back 1 valid? */
	U16 uReserved;			/* wBCLoopBack2Flg is redefined as TimeTag3 */
}MSGSTRUCT;

typedef struct MSGSTRUCT_BCR
{
	U16 uCntrlWrd;			/* BC Control word 0 */
	U16 uCmdWrd1;			/* Command word 1*/
	U16 uType;				/* Encoded  Message Type  + Data Length + EOM */
    U16 uBCGapTime;			/* Time To Next Message Word 3*/
	U16 uTimeTag;			/* low Time Tag Message word 4*/
	U16 uStsWrd;			/* block status word 5 */
	U16 uBCLoopBack;		/* Loop Back Word or high time tag if 32 WORD 6 */	U16 uRTStsWrd;			/* RT Status wrd2 if RT to RT word - 7 */
	U16 uStsWrd1;           /* Rx RT Status word for RTtoRT word 7 */
	U16 uCmdWrd2;           /* Command word 2 if RT to RT word 8*/
    U16 uStsWrd2;           /* Status wrd 2 if RT to RT word 9 */

	U16 aDataWrds[32];		/* An array of data words 2 */
}MSGSTRUCT_BCR;

typedef struct MSGSTRUCT_RTR
{
	U16 uBlkSts;			/* block status word 5 */
	U16 uTimeTag;			/* low Time Tag Message word 4*/
	U16 uType;				/* Type Derived from two words + Data Length + EOM */
	U16 uCmdWrd;			/* command word 1*/
	U16 aDataWrds[32];		/* An array of data words 2 */
}MSGSTRUCT_RTR;

typedef struct MSGSTRUCT_SMR
{
	U16 uBlkSts;			/* block status word 0 */
	U16 uTimeTag;			/* low Time Tag Message word 1*/
	U16 uTimeTag2;			/* High Time Tag Message word 2*/
	U16 uType;				/* Word 3 Type Derived from two words + Data Length + EOM */
	U16 uCmdWrd1;			/* Word 4 command word 1*/
	U16 uCmdWrd2;		    /* word 5 status word 8 */
	U16 uRTStsWrd;			/* word 6 block status word 5 */
	U16 uRTStsWrd2;			/* word 7 RT Status wrd2 if RT to RT word - 7 */	
	U16 aDataWrds[32];		/* An array of data words 2 */
}MSGSTRUCT_SMR;

typedef struct MSGSTRUCT_IMR
{
	U16 uStsWrd;			/* block status word 5 */
	U16 uTimeTag;			/* low Time Tag Message word 4*/
	U16 uTimeTag2;          /* Time Tag 2*/
	U16 uType;				/* Is Type Derived from two words + Data Length + EOM */
	U16 uCmdWrd1;			/* Is command word 1*/
	U16 uCmdWrd2;		    /* Is status word 8 */
	U16 uRTStsWrd;			/* block status word 5 */
	U16 uRxRTStsWrd;			/* RT Status wrd2 if RT to RT word - 7 */	
	U16 aDataWrds[32];		/* An array of data words 2 */
}MSGSTRUCT_IMR;

typedef struct STKMETRIC
{
	U32 dwLost;		/* Total number of msgs lost since RT start */
	U32 dwPctFull;	/* Current Percentage of Cmd Stk used */
	U32 dwHighPct;	/* Highest Percentage of Cmd Stk used */

} STKMETRIC;

typedef struct HBUFMETRIC
{
	U32 dwCount;	/* total number of msgs lost since install */
	U32 dwPctFull;	/* Current Percentage of HBuf used */
	U32 dwHighPct;	/* Highest Percentage of HBuf used */
} HBUFMETRIC;


 #ifdef __cplusplus
}
#endif