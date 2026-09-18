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
 * Rev 1.00 
	- Initial Release KPatel 1/30/2014
        - Complies with "Holt HI-6130 API Library Software Manual Rev 1.0"
	  API calls.
	- Split registers calls further to reflect the functionality.

 */
#define SMT_ADDRESSLIST_A 0x00b0
#define SMT_ADDRESSLIST_B 0x00b8

#define SMT_ADDRESSLIST_A_END_CMD_STK 0x00b2
#define SMT_ADDRESSLIST_A_START_DATA_BLK 0x00b4

#define SMT_ADDRESSLIST_B_END_CMD_STK 0x00ba
#define SMT_ADDRESSLIST_B_START_DATA_BLK 0x00bc

#define SMT_MESSAGE_FILTER_TABLE 0x100

/* monitor stack area constants */
#define  SMT_STKA		0x0000
#define  SMT_STKB		0x2000
#define  SMT_STK_CMB		0x4000

/* MT block status word bits */
#define  SMT_BSW_ERROR		0x163F
#define  SMT_BSW_CMDERR		0x0001
#define  SMT_BSW_RTRTERR_2CMD	0x0002
#define  SMT_BSW_RTRTERR_GSA	0x0004
#define  SMT_BSW_INVWRD		0x0008
#define  SMT_BSW_BADSYNC	0x0010
#define  SMT_BSW_WCERR		0x0020
#define  SMT_BSW_DSTK_ROVER	0x0080
#define  SMT_BSW_GDATA		0x0100
#define  SMT_BSW_NORES		0x0200
#define  SMT_BSW_FMTERR		0x0400
#define  SMT_BSW_RTRT		0x0800
#define  SMT_BSW_ERRFLG		0x1000
#define  SMT_BSW_CHNL		0x2000
#define  SMT_BSW_SOM		0x4000
#define  SMT_BSW_EOM		0x8000
#define  SMT_BSW_SUPER		SMT_BSW_ERRFLG

/* wOptions parameter can be any of the following bit "OR's" together */
#define  SMT_OPT_1553A_MC       0x00000200 /* 1553a mode codes enabled */
#define  SMT_OPT_BCST_DIS       0x00000800 /* Broadcast disabled */
#define  SMT_OPT_ERR_MON_ENA    0x00001000 /* MTi Error Monitor mode enable */
#define  SMT_OPT_MEC_MON_ENA    0x00001000 /* MTi Message Error Capture enable (Formerly MTi Error Monitor) */
#define  SMT_OPT_RTBUSY_DISABLE 0x00002000 /* Busy/Illegal bit and data data valid format disable */
#define  SMT_OPT_EOM_TT_ENABLE  0x00004000 /* Enables EOM for TT */
#define  SMT_OPT_AES_MON_ENA    0x00008000 /* MTi Advanced Error Sampling enable */
#define  SMT_OPT_DDC_DATA_TYPE  0x00010000 /* Use ddc defined custom data types for  MTI, MEC, and AES packets */
#define  SMT_OPT_DISABLE_BUS_B  0x00020000 /* Disables Bus B monitoring */
#define  SMT_OPT_DISABLE_BUS_A  0x00040000 /* Disables Bus A monitoring */
#define  SMT_OPT_TRIG_START_ENA 0x00080000 /* Enables mti/mtr start triggering */
#define  SMT_OPT_TRIG_STOP_ENA  0x00100000 /* Enables mti/mtr stop triggering */
#define  MTI_OPT_NO_RESTART     0x80000000 /* Change Options without restarting */

/* wMsgLoc parameter can be any one of the following */
#define  SMT_MSGLOC_NEXT_PURGE	0	/* next unread msg, clr stk */
#define  SMT_MSGLOC_NEXT_NPURGE	1	/* next unread msg, leave stk */
#define  SMT_MSGLOC_LATEST_PURGE  2	/* latest msg, clear stk */
#define  SMT_MSGLOC_LATEST_NPURGE 3	/* latest msg, leave stk alone */

/* wStkLoc parameter can be any one of the following */
#define  SMT_STKLOC_ACTIVE	0	/* Use the active stk */
#define  SMT_STKLOC_INACTIVE	1	/* Use the inactive stk */
#define  SMT_STKLOC_STKA	2	/* Use stk A */
#define  SMT_STKLOC_STKB	3	/* Use stk B */

/* wMTBufferType parameter can be any one of the following */
#define  SMT_SINGLESTK	0	/* Use a single stack */
#define  SMT_DOUBLESTK	1	/* Use stack A and B */

/* wCmdStkSize parameter can be any one of the following */
#define  SMT_CMDSTK_256	0x0000	/* Cmd Stacks are 256 words */
#define  SMT_CMDSTK_1K	0x0800	/* Cmd Stacks are 1K words */
#define  SMT_CMDSTK_4K	0x1000	/* Cmd Stacks are 4K words */
#define  SMT_CMDSTK_16K	0x1800	/* Cmd Stacks are 16K words */

/* wDataStkSize parameter can be any one of the following */
#define  SMT_DATASTK_512 0x0700	/* data Stacks are 256 words */
#define  SMT_DATASTK_1K	0x0600	/* data Stacks are 1K words */
#define  SMT_DATASTK_2K	0x0500	/* data Stacks are 4K words */
#define  SMT_DATASTK_4K	0x0400	/* data Stacks are 16K words */
#define  SMT_DATASTK_8K	0x0300	/* data Stacks are 16K words */
#define  SMT_DATASTK_16K 0x0200	/* data Stacks are 16K words */
#define  SMT_DATASTK_32K 0x0100	/* data Stacks are 16K words */

/* Filter parameters can use the following to enable/disable all */
#define  HOLT_SMT_FILTER_ALL	0xFFFF	/* Enable/disable all */
#define  HOLT_SMT_FILTER_RX  0x0000  /* Enable/disable Receive Cmds */
#define  HOLT_SMT_FILTER_TX  0x0001  /* Enable/disable Trasmit Cmds */

/* wSAMask can be the any of the following "OR'd" together */
#define  SMT_FILTER_SA_ALL  0xFFFFFFFF
#define  SMT_FILTER_SA0	    0x00000001
#define  SMT_FILTER_SA1 	0x00000002
#define  SMT_FILTER_SA2	    0x00000004
#define  SMT_FILTER_SA3	    0x00000008
#define  SMT_FILTER_SA4	    0x00000010
#define  SMT_FILTER_SA5	    0x00000020
#define  SMT_FILTER_SA6	    0x00000040
#define  SMT_FILTER_SA7	    0x00000080
#define  SMT_FILTER_SA8	    0x00000100
#define  SMT_FILTER_SA9	    0x00000200
#define  SMT_FILTER_SA10	0x00000400
#define  SMT_FILTER_SA11	0x00000800
#define  SMT_FILTER_SA12	0x00001000
#define  SMT_FILTER_SA13	0x00002000
#define  SMT_FILTER_SA14	0x00004000
#define  SMT_FILTER_SA15	0x00008000
#define  SMT_FILTER_SA16	0x00010000
#define  SMT_FILTER_SA17	0x00020000
#define  SMT_FILTER_SA18	0x00040000
#define  SMT_FILTER_SA19	0x00080000
#define  SMT_FILTER_SA20	0x00100000
#define  SMT_FILTER_SA21	0x00200000
#define  SMT_FILTER_SA22	0x00400000
#define  SMT_FILTER_SA23	0x00800000
#define  SMT_FILTER_SA24	0x01000000
#define  SMT_FILTER_SA25	0x02000000
#define  SMT_FILTER_SA26	0x04000000
#define  SMT_FILTER_SA27	0x08000000
#define  SMT_FILTER_SA28	0x10000000
#define  SMT_FILTER_SA29	0x20000000
#define  SMT_FILTER_SA30	0x40000000
#define  SMT_FILTER_SA31	0x80000000

/* wHBufPercent -> Post Trigger percent of buffer held */
#define  SMT_TRIG_HBUF_0P	0	/* No msgs will be held prior to trg*/
#define  SMT_TRIG_HBUF_25P	1	/* 25% will be held */
#define  SMT_TRIG_HBUF_50P	2	/* 50% will be held */
#define  SMT_TRIG_HBUF_75P	3	/* 75% will be held */

/* MT Trigger flags */
#define  SMT_TRIG_FLG_NONE	0x0000	/* all trigs disabled */
#define  SMT_TRIG_FLG_CMD1	0x0001	/* command 1 trig enabled */
#define  SMT_TRIG_FLG_CMD2	0x0002	/* command 2 trig enabled */
#define  SMT_TRIG_FLG_STS1	0x0004	/* status 1 trig enabled */
#define  SMT_TRIG_FLG_STS2	0x0008	/* status 2 trig enabled */
#define  SMT_TRIG_FLG_ERR	0x0010	/* error trig enabled */
#define  SMT_TRIG_FLG_DATA	0x0020	/* data trig enabled */
#define  SMT_TRIG_FLG_ALL	0x8000	/* all trigs must be in msg */
#define  SMT_TRIG_FLG_ANY	0x0000	/* any trigs must be in msg */

/* Monitor detection of partial data logging for RT to RT command, where RT is the transmitter */
#define  MTRT_RTRT_SUP_DET	0x00001000

// These 3 options apply only to Simple Monitor 
#define SELECT_SMT	1	// select mode: Simple Monitor enabled
#define SMT_TTAG48	1<<1	// SMT ONLY: 48-bit time tagging
#define SMT_TTAG16	0<<1	// SMT ONLY: 16-bit time tagging

// These options apply only to IRIG-106 Monitor 
#define SELECT_IMT	0	// select mode: IRIG-106 Monitor enabled
#define IMT_HDR_OFF     1<<3	// IMT ONLY: disable packet header/trailer generation 
#define IMT_HDR_ON	0<<3	// IMT ONLY: enable packet header/trailer generation
#define IMT_CKSUM_ON    1<<1	// IMT ONLY: enable data packet checksum
#define IMT_CKSUM_OFF   0<<1	// IMT ONLY: disable data packet checksum
#define IMT_DTYPE9	0<<10	// IMT ONLY: packet header "data type" specifier
#define IMT_DTYPE4	1<<10	// IMT ONLY: 
#define IMT_DTYPE5	2<<10	// IMT ONLY: 
#define IMT_DTYPE7	3<<10	// IMT ONLY: 
#define PKTSTRT_CW	0<<7	// IMT ONLY: packet timer starts at cmd word detection
#define PKTSTRT_ENA	1<<7	// IMT ONLY: packet timer starts immediately when MT enabled
#define IMT_PKTSTOP	1<<13	// IMT ONLY: BC asserts this bit to end in-process packet 

// These options apply to BOTH Simple & IRIG-106 Monitor 
#define EXTD_STATUS	1<<2	// enable extended error and status flags, NOT FOR IMT!
#define IRIG_STATUS	0<<2	// enable IRIG-106 compatible error and status flags
#define MTTO_15U	0<<14	// "no response timeout" has 15us bus dead time
#define MTTO_20U	1<<14	// "no response timeout" has 20us bus dead time
#define MTTO_58U	2<<14	// "no response timeout" has 18us bus dead time
#define MTTO_138U	3<<14	// "no response timeout" has 138us bus dead time
#define GAPCHKON	1<<12	// enables 2us bus dead time check, RT response & intermessage
#define GAPCHKOFF	0<<12	// disables 2us bus dead time check, RT response & intermessage
#define TAG_LWLB	0<<8	// time tag at last word, last bit in msg           
#define TAG_FWFB	1<<8	// time tag at first word, first bit in msg           
#define TAG_FWLB	2<<8	// time tag at first word, last bit in msg           
#define TAG_OFF		3<<8	// time tag disabled, all stored tags = 0
#define REC_CW		0<<5	// full cmd word starts new msg recording
#define REC_CWDW	1<<5	// full cmd or data word starts new msg recording
#define REC_CS		2<<5	// cmd sync + 2 data bits starts new msg recording
#define REC_CSDS	3<<5	// cmd or data sync + 2 data bits starts new msg recording
#define STOR_INVWD	1<<4	// invalid data words are stored, recording continues
#define STOP_INVWD	0<<4	// invalid data word ends msg/fragment record, bad word not stored

//
//	Macros for HI-613x Bus Monitor Interrupt Management Registers
//	(Int Enable Register, Int Output Enable Register & Pending Int Register)
// 
// These interrupts apply to BOTH Simple & IRIG-106 Monitor 
#define STKROVR 	1<<8 	// IMT or SMT: (command) stack end-address written
#define STKADRSS	1<<6 	// IMT or SMT: (cmd) stack address written equals word 3 in MT Addr List
#define MT_EOM		1<<3	// IMT or SMT: message completion

// These interrupts apply only to IRIG-106 Monitor 
#define FULL_EOP	1<<15	// IMT ONLY: stack full end-of-packet
#define MAXWORDS	1<<14	// IMT ONLY: max 1553 msg word count attained
#define PKTREADY	1<<9 	// IMT ONLY: packet ready, other bit says why
#define FULL_OFS	1<<5 	// IMT ONLY: offset from FULL_EOP interrupt

// These interrupts apply only to Simple Monitor 
#define DSTKROVR	1<<7 	// SMT ONLY: data stack end-address written 
#define DSTKADRSS	1<<5 	// SMT ONLY: data stack address written equals word 7 in MT Addr List
#define MSG_ERR		1<<4	// SMT ONLY: RT status word detected with Message Error

#define HOLT_MT_CMDSTK_256	256
#define HOLT_MT_CMDSTK_1K	1024
#define HOLT_MT_CMDSTK_4K	4096
#define HOLT_MT_CMDSTK_16K	16384

#define HOLT_MT_DATASTK_512	512 
#define HOLT_MT_DATASTK_1K	1024 
#define HOLT_MT_DATASTK_2K	2048 
#define HOLT_MT_DATASTK_4K	4096 
#define HOLT_MT_DATASTK_8K	8192 
#define HOLT_MT_DATASTK_16K	16384
#define HOLT_MT_DATASTK_32K	32768

/* wStkLoc parameter can be any one of the following */
#define HOLT_MT_STKLOC_ACTIVE		0	/* Use the active stk */
#define HOLT_MT_STKLOC_INACTIVE		1	/* Use the inactive stk */
#define HOLT_MT_STKLOC_STKA			2	/* Use stk A */
#define HOLT_MT_STKLOC_STKB			3	/* Use stk B */

/* wHBufPercent -> Post Trigger percent of buffer held */
#define HOLT_MT_TRIG_HBUF_0P		0	/* No msgs will be held prior to trg*/
#define HOLT_MT_TRIG_HBUF_25P	1	/* 25% will be held */
#define HOLT_MT_TRIG_HBUF_50P	2	/* 50% will be held */
#define HOLT_MT_TRIG_HBUF_75P	3	/* 75% will be held */

typedef struct MTINFO
{
	U16 wStkMode;
	U16 wCmdStkSize;
	U16 wDataStkSize;
	U16 b1553aMCodes;
	U32 dwHBufSize;
}SMTINFO;

typedef struct SMTTRIGGER
{
	U16 wCmdWrd1;	/* CmdWrd1 value */
	U16 wCmdMsk1;	/* CmdWrd1 mask */
	U16 wCmdWrd2;	/* CmdWrd2 value */
	U16 wCmdMsk2;	/* CmdWrd2 mask */
	U16 wStsWrd1;	/* StsWrd1 value */
	U16 wStsMsk1;	/* StsWrd1 mask */
	U16 wStsWrd2;	/* StsWrd2 value */
	U16 wStsMsk2;	/* StsWrd2 mask */
	U16 wDataWrd;	/* DataWrd value */
	U16 wDataMsk;	/* DataWrd mask */
	U16 wDataPos;	/* DataWrd position in message */
	U16 wErrWrd;		/* ErrWrd value (errors in Block Status) */
	U16 wErrFlg;		/* should all errors be met or only one */

	U16 wCount;		/* # of trig's needed to produce real trigger */
	U16 wTrigFlags;	/* should all conditions be met or only one */

	U16 wNextFlags;	/* Next flags for complex triggering */
	struct SMTTRIGGER *pNextTrg;/* indicates next condition to trigger on*/
} SMTTRIGGER;

S16 HoltSMTClearHBufTrigger(
		PLX_DEVICE_OBJECT *pDevice);

S16 HoltSMTConfigure(
			PLX_DEVICE_OBJECT *pDevice,
			U16 uMTStkType,
			U16 uCmdStkSize,
			U16 uDataStkSize,
			U16 uOptions);

S16 HoltSMTContinue(
			PLX_DEVICE_OBJECT *pDevice);

S16 HoltSMTDisableRTFilter(
			PLX_DEVICE_OBJECT *pDevice,
			U16 uRT,
			U16 uTR,
			U16 uSAMask);

S16 HoltSMTEnableRTFilter(
			PLX_DEVICE_OBJECT *pDevice,
			U16 uRT,
			U16 uTR,
			U16 uSAMask);

S16 HoltSMTGetHBufMetric(
			PLX_DEVICE_OBJECT *pDevice,
			HBUFMETRIC *pMetric,
			U16 uReset);

S16  HoltSMTInstallHBuf(
				PLX_DEVICE_OBJECT *pDevice,
				U16 uBufferSize);

S16  HoltSMTUninstallHBuf(
				PLX_DEVICE_OBJECT *pDevice);

S16 HoltSMTGetHBufMsgDecoded(
			PLX_DEVICE_OBJECT *pDevice,
			MSGSTRUCT *pMsg,
			U16*pMsgCount,
			U16*pMsgLostStk,
			U16*pMsgLostHBuf,
			U16 uMsgLoc);

S16 HoltSMTGetHBufMsgsRaw(
			PLX_DEVICE_OBJECT *pDevice,
			U16 *pBuffer,
			U16 uBufferSize,
			U16*pMsgCount,
			U16*pMsgLostStk,
			U16*pMsgLostHBuf);

S16 HoltSMTGetInfo(
			PLX_DEVICE_OBJECT *pDevice, 
			SMTINFO *pInfo);

S16 HoltSMTGetRTFilter(
			PLX_DEVICE_OBJECT *pDevice,
			U16 uRT,
			U16 uTR,
			U16* pSAMask);

S16 HoltSMTPause(
			PLX_DEVICE_OBJECT *pDevice);

S16 HoltSMTSetHBufTrigger(
			PLX_DEVICE_OBJECT *pDevice,
			U16 uHBufPercent,
			SMTTRIGGER *pTrg);

S16 HoltSMTStart(
			PLX_DEVICE_OBJECT *pDevice);

S16 HoltSMTStop(
			PLX_DEVICE_OBJECT *pDevice);

S16 HoltSMTAddressListWrite(
			PLX_DEVICE_OBJECT *pDevice, 
			U16 uAddrListID,
			U16 *pWBuffer,
			U16 uWordsNum,
			U16 uWordsMask);

S16 HoltSMTAddressListRead(
			PLX_DEVICE_OBJECT *pDevice, 
			U16 uAddrListID,
			U16 *pRBuffer,
			U16 uWordsNum,
			U16 uWordsMask);

S16 HoltSMTFilterTableWrite (
			PLX_DEVICE_OBJECT *pDevice, 
			U16 uRTAddr,
			U16 uTR, 
			U16 uSA,
			U32 uWCMaskMonOff);
                                               
short HoltSMTScheduler(PLX_DEVICE_OBJECT *pDevice);

short HoltSMTFilterTblRead(PLX_DEVICE_OBJECT *pDevice,U16 RTAddr, U16 *buffer);

short HoltSMTUninstallHBuf(PLX_DEVICE_OBJECT *pDevice);

S16 HoltSMTGetStkMsgsRaw(
			PLX_DEVICE_OBJECT *pDevice,
			U16 *pBuffer,
			U16 uBufferSize,
			U16 uStkLoc);
			
S16 HoltSMTGeStkMetric(
			PLX_DEVICE_OBJECT *pDevice,
			STKMETRIC *pMetric,
			U16 uStk,
			U16 uReset);

S16 HoltSMTGetStkMsgDecoded(
			PLX_DEVICE_OBJECT *pDevice,
			MSGSTRUCT *pMsg,
			U16 uMsgLoc,
			U16 uStkLoc);

S16 HoltSMTInstallHBuf(
			PLX_DEVICE_OBJECT *pDevice, 
			U16 uHBufSize);

S16 HoltSMTCreateImageFiles(
			PLX_DEVICE_OBJECT *pDevice,
			U16 *pIFile,
			U16 *pHFile);

S16 HoltSMTDecodeRawMsg(
			PLX_DEVICE_OBJECT *pDevice,
			U16 *pBuffer,
			MSGSTRUCT *pMsg);

S16 HoltSMTGetHBufMsgCount(
			U16 ChanID);

S16 HoltSMTStkToHBuf(
			PLX_DEVICE_OBJECT *pDevice);

S16 HoltSMTStkToHBuf32(
			PLX_DEVICE_OBJECT *pDevice);



