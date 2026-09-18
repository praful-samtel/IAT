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
//# include "AppConfig.h"
#define RT1_DESC_TABLE_SIZE  512 // default size  will be managed by Memory manager
#define RT1_ILLEGALIZATION_TABLE_SIZE 256

#define RT_MSGTYPE_TX 1
#define RT_MSGTYPE_BCST 2
#define RT_MSGTYPE_ALL 3
#define HOLT_RT_INTERNAL_ADDR_HOSTWRITE 2
#define HOLT_RT_INTERNAL_ADDR_AUTOINIT 3
/* RT block status word bits */
#define HOLT_RT_BSW_CMDERR			0x0001
#define HOLT_RT_BSW_RTRTERR_2CMD	0x0002
#define HOLT_RT_BSW_RTRTERR_GSA		0x0004
#define HOLT_RT_BSW_INVWRD			0x0008
#define HOLT_RT_BSW_BADSYNC			0x0010
#define HOLT_RT_BSW_WCERR			0x0020
#define HOLT_RT_BSW_ILLCMD			0x0040
#define HOLT_RT_BSW_CIRCOVR			0x0080
#define HOLT_RT_BSW_LPFAIL			0x0100
#define HOLT_RT_BSW_NORES			0x0200
#define HOLT_RT_BSW_FMTERR			0x0400
#define HOLT_RT_BSW_RTRT			0x0800
#define HOLT_RT_BSW_ERRFLG			0x1000
#define HOLT_RT_BSW_CHNL			0x2000
#define HOLT_RT_BSW_SOM				0x4000
#define HOLT_RT_BSW_EOM				0x8000

/* Host Buffer Processing Modes */
#define HOLT_RT_HBUFMODE_RT          0x0001
#define HOLT_RT_HBUFMODE_BOTH        0x0002
#define HOLT_RT_HBUFMODE_TMPRT       0x0003

/* wMsgLoc parameter can be any one of the following */
#define HOLT_RT_MSGLOC_NEXT_PURGE	0	/* next unread msg, clr stk */
#define HOLT_RT_MSGLOC_NEXT_NPURGE	1	/* next unread msg, leave stk */
#define HOLT_RT_MSGLOC_LATEST_PURGE	2	/* latest msg, clear stk */
#define HOLT_RT_MSGLOC_LATEST_NPURGE	3	/* latest msg, leave stk alone */

/* wCmdStkSize parameter can be any one of the following */
#define HOLT_RT_CMDSTK_256	0x0000	/* Cmd Stacks are 256 words */
#define HOLT_RT_CMDSTK_512	0x2000	/* Cmd Stacks are 512 words */
#define HOLT_RT_CMDSTK_1K	0x4000	/* Cmd Stacks are 1K words */
#define HOLT_RT_CMDSTK_2K	0x6000	/* Cmd Stacks are 2K words */

/* RT Address Sources */
#define HOLT_RT_INTERNAL_ADDR 0x0001
#define HOLT_RT_EXTERNAL_ADDR 0x0000

/* RT Lookup Table Base Addresses */
#define HOLT_RT_LOOKUP_RX   0x140
#define HOLT_RT_LOOKUP_TX   0x160
#define HOLT_RT_LOOKUP_BCST 0x180

/* wOptions parameter can be any of the following bit "OR'd" together */
#define HOLT_RT_OPT_CLR_SREQ			0x00000001 /* Clear sreq after tx vector wrd*/
#define HOLT_RT_OPT_LOAD_TT				0x00000002 /* Load Time Tag on sync MCODE */
#define HOLT_RT_OPT_CLEAR_TT			0x00000004 /* Clear Time Tag on sync MCODE */
#define HOLT_RT_OPT_OVR_DATA			0x00000008 /* Overwrite inv data -circ buf */
#define HOLT_RT_OPT_OVR_MBIT			0x00000010 /* T/R*=0,MC MSB=0, Holt will resp*/
#define HOLT_RT_OPT_ALT_STS				0x00000020 /* Use RT alternate status word */
#define HOLT_RT_OPT_IL_RX_D				0x00000040 /* Illegal receive disable */
#define HOLT_RT_OPT_BSY_RX_D			0x00000080 /* Busy receive disable */
#define HOLT_RT_OPT_SET_RTFG			0x00000100 /* set flag if loopback tsts fail*/
#define HOLT_RT_OPT_1553A_MC			0x00000200 /* 1553a mode codes enabled */
#define HOLT_RT_OPT_MC_O_BSY			0x00000400 /* Busy bit and data word sent */
#define HOLT_RT_OPT_BCST_DIS			0x00000800 /* Broadcast disabled */

/* Additional options */
#define HOLT_RT_OPT_ILL_DIS              0x00001000 /* illegalization disabled */
#define HOLT_RT_OPT_1553A_ERESP_EN       0x00002000 /* 1553A Error Response enabled */
#define HOLT_RT_OPT_INHIBIT_BTWD_IF_BUSY 0x00004000 /* Inhibit BITWD if Busy */
#define HOLT_RT_OPT_EXTERN_BTWD_IF_BUSY  0x00008000 /* Extern BITWD if Busy */

/* options for Multi-function  */
#define HOLT_RT_OPT_INACTIVE            0x00010000 /* inactive RT */
#define HOLT_RT_OPT_TO_ACTIVATE         0x00020000 /* the RT will be activated during DBC*/

/* Added to set Valid Busy Bit. Update for TT 1280. */
#define HOLT_RT_OPT_VALID_BUSY_BIT_ENA  0x00040000 /* the RT will set Valid Busy Bit in the BC Config reg 1 */

/* RTMT options */
#define HOLT_RTMT_OPT_MON_RT_ADDR		0x40000000 /* Allow monitoring of the RT's messages (Flexcore only) */
#define HOLT_RTMT_COMBO_HBUF			0x80000000 /* Capture RT and MT messages in a single host buffer */

#define HOLT_RT_OPTIONS_MAX             0x80000000

/* wDataBlkType parameter can be any one of the following */
#define HOLT_RT_DBLK_SINGLE		    34	/* single msg data block 34 words */
#define HOLT_RT_DBLK_DOUBLE		    33	/* doubled buffered msg dblk 64 wds */
#define HOLT_RT_DBLK_C_128		    34	/* circular buffer 128 words long */
#define HOLT_RT_DBLK_C_256		    35	/* circular buffer 256 words long */
#define HOLT_RT_DBLK_C_512		    36	/* circular buffer 512 words long */
#define HOLT_RT_DBLK_C_1K		    37	/* circular buffer 1K words long */
#define HOLT_RT_DBLK_C_2K		    38	/* circular buffer 2K words long */
#define HOLT_RT_DBLK_C_4K		    39	/* circular buffer 4K words long */
#define HOLT_RT_DBLK_C_8K		    40	/* circular buffer 8K words long */
#define HOLT_RT_DBLK_C_TYPE_MAX     40  /* last type definition this number should equal  */
                                        /* the highest DBLK identifier, which is currently */                                                                                  
#define HOLT_RT_DBLK_GBL_C_128	    41	/* global circ buf 128 words long */
#define HOLT_RT_DBLK_GBL_C_256	    42	/* global circ buf 256 words long */
#define HOLT_RT_DBLK_GBL_C_512	    43	/* global circ buf 512 words long */
#define HOLT_RT_DBLK_GBL_C_1K	    44	/* global circ buf 1K words long */
#define HOLT_RT_DBLK_GBL_C_2K	    45	/* global circ buf 2K words long */
#define HOLT_RT_DBLK_GBL_C_4K	    46	/* global circ buf 4K words long */
#define HOLT_RT_DBLK_GBL_C_8K	    47	/* global circ buf 8K words long */
#define HOLT_RT_DBLK_GBL_TYPE_MAX   47  /* last type definition this number should equal 
                                           the highest DBLK identifier, which is currently 
                                           47 - HOLT_RT_DBLK_GBL_C_8K */

/* wModeCodeType parameter can be any one of the following */
#define HOLT_RT_MCTYPE_RX_NO_DATA		0x0000 /* undefined mc's */
#define HOLT_RT_MCTYPE_RX_DATA			0x0001 /* rx mc's w/ data */
#define HOLT_RT_MCTYPE_TX_NO_DATA		0x0002 /* tx mc's w/o data */
#define HOLT_RT_MCTYPE_TX_DATA			0x0003 /* tx mc's w/ data */
#define HOLT_RT_MCTYPE_BCST_RX_NO_DATA	0x0004 /* undefined mc's */
#define HOLT_RT_MCTYPE_BCST_RX_DATA		0x0005 /* bcst rx mc's w/ data */
#define HOLT_RT_MCTYPE_BCST_TX_NO_DATA	0x0006 /* bcst tx mc's w/o data */
#define HOLT_RT_MCTYPE_BCST_TX_DATA		0x0007 /* undefined/reserved mc */

/* wModeCodes parameter can be any of the following OR'd together */
/* the constants are followed by their valid types */
#define HOLT_RT_MCIRQ_DYN_BUS_CTRL		0x0001 /* TX_NO_DATA */
#define HOLT_RT_MCIRQ_SYNCHRONIZE		0x0002 /*(BCST_)(TX|RX)(_NO)_DATA*/
#define HOLT_RT_MCIRQ_TRNS_STATUS		0x0004 /* TX_NO_DATA */
#define HOLT_RT_MCIRQ_INIT_SELF_TEST	0x0008 /* (BCST_)TX_NO_DATA */
#define HOLT_RT_MCIRQ_TRNS_SHUTDOWN		0x0010 /* (BCST_)TX_NO_DATA */
#define HOLT_RT_MCIRQ_OVR_TRNS_SHUTDWN	0x0020 /* (BCST_)TX_NO_DATA */
#define HOLT_RT_MCIRQ_INH_TERM_FLAG		0x0040 /* (BCST_)TX_NO_DATA */
#define HOLT_RT_MCIRQ_OVR_INH_TERM_FLG	0x0080 /* (BCST_)TX_NO_DATA */
#define HOLT_RT_MCIRQ_RESET_REMOTE_TERM	0x0100 /* (BCST_)TX_NO_DATA */
#define HOLT_RT_MCIRQ_TRNS_VECTOR		0x0001 /* TX_DATA */
#define HOLT_RT_MCIRQ_TRNS_LAST_CMD		0x0004 /* TX_DATA */
#define HOLT_RT_MCIRQ_TRNS_BIT			0x0008 /* TX_DATA */
#define HOLT_RT_MCIRQ_SEL_TRNS_SHUTDWN	0x0010 /* (BCST_)RX_DATA */
#define HOLT_RT_MCIRQ_OVR_SEL_TRNS_SHUTDWN 0x0020 /* (BCST_)RX_DATA */
#define HOLT_RT_MCIRQ_RESERVED_BIT6		0x0040
#define HOLT_RT_MCIRQ_RESERVED_BIT7		0x0080
#define HOLT_RT_MCIRQ_RESERVED_BIT8		0x0100
#define HOLT_RT_MCIRQ_RESERVED_BIT9		0x0200
#define HOLT_RT_MCIRQ_RESERVED_BIT10	0x0400
#define HOLT_RT_MCIRQ_RESERVED_BIT11	0x0800
#define HOLT_RT_MCIRQ_RESERVED_BIT12	0x1000
#define HOLT_RT_MCIRQ_RESERVED_BIT13	0x2000
#define HOLT_RT_MCIRQ_RESERVED_BIT14	0x4000
#define HOLT_RT_MCIRQ_RESERVED_BIT15	0x8000

/* wModeCode parameter can be any one of the following*/
#define HOLT_RT_MCDATA_RX_SYNCHRONIZE		0x0011  
#define HOLT_RT_MCDATA_RX_SEL_T_SHUTDWN		0x0004
#define HOLT_RT_MCDATA_RX_OVR_SEL_T_SHUTDWN	0x0005
#define HOLT_RT_MCDATA_TX_TRNS_VECTOR		0x0010
#define HOLT_RT_MCDATA_TX_TRNS_LAST_CMD		0x0012
#define HOLT_RT_MCDATA_TX_TRNS_BIT		0x0013
#define HOLT_RT_MCDATA_BCST_CODE_BITMASK        0X0020
#define HOLT_RT_MCDATA_BCST_SYNCHRONIZE		0x0021
#define HOLT_RT_MCDATA_BCST_SEL_T_SHUTDWN	0x0024
#define HOLT_RT_MCDATA_BCST_OVR_SEL_T_SHUTDWN   0x0025


                                             

/* wMsgType can be any of the following bitwize OR'd together */
#define HOLT_RT_MSGTYPE_RX	0x0000	/* Rx msgs to SA will use data blk */
#define HOLT_RT_MSGTYPE_TX	0x0001	/* Tx msgs to SA will use data blk */
#define HOLT_RT_MSGTYPE_RXMC	0x0002	/* TX Mode Code msgs data blk*/
#define HOLT_RT_MSGTYPE_TXMC	0x0003	/* RX Mode Code msgs data blk*/

/* wIrqOptions can be 0 or any of the following "OR'd" together */
#define HOLT_RT_DBLK_EOM_IRQ		    0x0002 /* Irqs gen on end of msg */
#define HOLT_RT_DBLK_CIRC_IRQ	    0x0001 /* Irqs gen on circ buf rover */

#define HOLT_RT_DBLK_TXEOM_IRQ_MASK  0x4000 /* SA Ctrl TX EOM interrupt enable */
#define HOLT_RT_DBLK_RXEOM_IRQ_MASK  0x0200 /* SA Ctrl TX EOM interrupt enable */

/* wBITLoc can be one of the following */
#define HOLT_RT_BIT_INTERNAL		0 /* (Default) use internal BIT wrd*/
#define HOLT_RT_BIT_EXTERNAL		1 /* Use BIT from external RAM location */

#define HOLT_RT_BIT_NO_INHIBIT	0 /* (Default) BIT wrd not inhibited */
#define HOLT_RT_BIT_INHIBIT		1 /* BIT Wrd inhibited on RT busy */

/* wOwnAddrOrBcst parameter can be any one of the following */
#define HOLT_RT_OWN_ADDRESS				0x0001
#define HOLT_RT_BCST_ADDRSS				0x0000
#define HOLT_RT_ARRT_0		0x0000   //DISABLE Automatic “reset RT” 				
#define HOLT_RT_ARRT_1		0x0001   //(1) ENABLE: Automatic “reset RT”

#define HOLT_RT_BSD_TXRX	(0x0<<16)  //(0) RT bus shutdown MC4, MC20 	
#define HOLT_RT_BSD_TX	   	(0x0001<<16)// (1) RT bus shutdown MC4,

#define HOLT_RT_RT1_ENA_0  	 0<<17  //RT1 is ENABLED 
#define HOLT_RT_RT1_ENA_1  	 1<<17  //RT1 is ENABLED 

#define HOLT_RT_RT2_ENA_0   (0<<18)  //RT2 is DISABLED (Default)
#define HOLT_RT_RT2_ENA_1  	(1<<18)  //RT2 is ENABLED 

#define HOLT_RT_SMCP_0		(0<<7) 	//Simple Mode Code Processing
#define HOLT_RT_SMCP_1		(1<<7) 	//Simple Mode Code 

#define HOLT_RT_TRXB_0		(0<<6) //Temp Rx Data Buffer is enabled
#define HOLT_RT_TRXB_1		(1<<6) //Temp Rx Data Buffer disabled 

#define HOLT_RT_ABIT_ENA_0	(0<<5) //Alternate BIT Word disabled 
#define HOLT_RT_ABIT_ENA_1	(1<<5) //Alternate BIT Word enabled 

#define HOLT_RT_ABSD_0		(0<<4) //Auto bus shutdown for mode 
#define HOLT_RT_ABSD_1		(1<<4) //Auto bus shutdown for mode 

#define HOLT_RT_ASWD_0		(0) //Auto sync with data MC17 OFF
#define HOLT_RT_ASWD_1		(4) //Auto sync with data MC17 ON 
#define HOLT_RT_ASWD_2		(8) //Auto sync with data MC17 ON 
#define HOLT_RT_ASWD_3		(0xC) //Auto sync with data MC17 is

#define HOLT_RT_CSRQ_0		(0) //DISABLE: Auto clear SVCREQ 
#define HOLT_RT_CSRQ_1		(2) //ENABLE: Auto clear SVCREQ 
				
#define HOLT_RT_2RTO_57 	(0<<14) //RT-to-RT no response timeout is
#define HOLT_RT_2RTO_62	 	(1<<14) //RT-to-RT no response 
#define HOLT_RT_2RTO_100	(2<<14) //RT-to-RT no response timeout 100µs
#define HOLT_RT_2RTO_180	(3<<14) //RT-to-RT no response 

#define HOLT_RT_BUSA_INH_0	(0<<13) //Bus A not inhibited (Default)
#define HOLT_RT_BUSA_INH_1	(1<<13) //Bus A is inhibited

#define HOLT_RT_BUSB_INH_0	(0<<12) //Bus B not inhibited (Default)
#define HOLT_RT_BUSB_INH_1	(1<<12) //Bus B is inhibited

#define HOLT_RT_BCST_INV_0	(0<<11) //Broadcast cmds valid  (Default)
#define HOLT_RT_BCST_INV_1	(1<<11) //Broadcast commands invalid

#define HOLT_RT_DBC_ENA_0	(0<<10) //Dynamic bus control disabled
#define HOLT_RT_DBC_ENA_1	(1<<10) //Dynamic bus control is 

#define HOLT_RT_UMCINV_0	(0<<9) //Undefined mode commands 
#define HOLT_RT_UMCINV_1	(1<<9) //Undefined mode commands 
				
#define HOLT_RT_N2_ENA_0	(0<<8) 	//Notice 2 Broadcast receive data 
#define HOLT_RT_N2_ENA_1	(1<<8) //Notice 2 Broadcast receive

#define HOLT_RT_STSBIT_TFLAG 0x0001 //Setting parameter bit 0 high resets Terminal Flag status bit 0 low.
#define HOLT_RT_STSBIT_DBCA  0x0002 //Setting parameter bit 1 high resets the Dynamic Bus Control Acceptance status bit 1 low.
#define HOLT_RT_STSBIT_SSFLAG 0x0004 //Setting parameter bit 2 high resets the Subsystem Flag status bit 2 low.
#define HOLT_RT_STSBIT_BUSY  0x0008 //Setting parameter bit 3 high resets the Busy status bit 3 low.
#define HOLT_RT_STSBIT_SREQ  0x0100 //Setting parameter bit 8 high resets the Service Request status bit 8 low.
#define HOLT_RT_STSBIT_INST  0x0200 //Setting parameter bit 9 high resets the Instrumentation status bit 

#define HOLT_RT_STSBIT_RTFLAG	1
#define HOLT_RT_STSBIT_ME	1<<10

//	All non-address bits including Reserved bits:
#define  HOLT_RT_STSBIT_ALL	0x07FF
// RT1 Configuration

/* ----------------------------------------------------------------------------*/    
S16 HoltRT1BITWrdConfig(
			PLX_DEVICE_OBJECT *pDevice,
			U16 uBITLoc,
			U16 uBITBusyInh);

/* ----------------------------------------------------------------------------*/    
S16 HoltRT1BITWrdRead(
			PLX_DEVICE_OBJECT *pDevice,
			U16 uBITLoc,
			U16 *pBITWrd);

/* ----------------------------------------------------------------------------*/    
S16 HoltRT1BITWrdPriWrite(
			PLX_DEVICE_OBJECT *pDevice,
			U16 uBITWrd);

/* ----------------------------------------------------------------------------*/    
S16 HoltRT1BITWrdWrite(
			PLX_DEVICE_OBJECT *pDevice,
			U16 uBITWrd);

/* ----------------------------------------------------------------------------*/    
S16 HoltRT1BusyBitsTblClear(
			PLX_DEVICE_OBJECT *pDevice,
			U16 uOwnAddrOrBcst,
			U16 uTR,
			U32 uSAMask);

/* ----------------------------------------------------------------------------*/    
S16 HoltRT1BusyBitsTblSet(
			PLX_DEVICE_OBJECT *pDevice,
			U16 uOwnAddrOrBcst,
			U16 uTR,
			U16 uSAMask);

/* ----------------------------------------------------------------------------*/    
S16 HoltRT1BusyBitsTblStatus(
			PLX_DEVICE_OBJECT *pDevice,
			U16 uOwnAddrOrBcst,
			U16 uTR,
			U16 *pSABusyBits);

/* ----------------------------------------------------------------------------*/    
S16 HoltRT1Configure(
			PLX_DEVICE_OBJECT *pDevice,
			U16 uCmdStkSize,
			U32 Options);


/* ----------------------------------------------------------------------------*/    
S16 HoltRT1DataBlkCircBufInfo(
			PLX_DEVICE_OBJECT *pDevice,
			U16 uDataBlkID,
			U16 *pUserRWOffset,
			U16 *pHoltRWOffset);

/* ----------------------------------------------------------------------------*/    
S16 HoltRT1DataBlkCreate(
			PLX_DEVICE_OBJECT *pDevice,
			U16 uDataBlkID,
			U16 uDataBlkType,
			U16 *pBuffer,
			U16 uBufferSize);

/* ----------------------------------------------------------------------------*/    
S16 HoltRT1DataBlkDelete(
			PLX_DEVICE_OBJECT *pDevice,
			U16 uDataBlkID);
 
/* ----------------------------------------------------------------------------*/    
S16 HoltRT1DataBlkMapToSA(
			PLX_DEVICE_OBJECT *pDevice,
			U16 *pDataBlkID,
			U16 uSA,
			U16 uMsgType,
			U16 uIrqOptions,
			U16 uLegalizeSA);

/* ----------------------------------------------------------------------------*/    
S16 HoltRT1DataBlkRead(
			PLX_DEVICE_OBJECT *pDevice,
			U16 uDataBlkID,
			U16 *pBuffer,
			U16 uBufferSize,
			U16 uOffset);

/* ----------------------------------------------------------------------------*/    
S16 HoltRT1DataBlkUnmapFromSA(
			PLX_DEVICE_OBJECT *pDevice,
			U16 uDataBlkID,
			U16 uSA,
			U16 uMsgType);

/* ----------------------------------------------------------------------------*/    
S16 HoltRT1DataBlkWrite(
			PLX_DEVICE_OBJECT *pDevice,
			U16 uDataBlkID,
			U16 *pBuffer,
			U16 uBufferSize,
			U16 uOffset);

/* ----------------------------------------------------------------------------*/    
S16 HoltRT1GetAddress(
			PLX_DEVICE_OBJECT *pDevice,
			U16 *pRTAddress);

/* ----------------------------------------------------------------------------*/    
S16 HoltRT1GetAddrSource(
			PLX_DEVICE_OBJECT *pDevice, 
			U16 *uRTSource);

/* ----------------------------------------------------------------------------*/    
S16 HoltRT1GetHBufMetric(
			PLX_DEVICE_OBJECT *pDevice,
			HBUFMETRIC *pMetric,
			U16 uReset);

/* ----------------------------------------------------------------------------*/    
S16 HoltRT1GetHBufMsgCount(
			PLX_DEVICE_OBJECT *pDevice);

/* ----------------------------------------------------------------------------*/    
S16 HoltRT1GetHBufMsgDecoded(
			PLX_DEVICE_OBJECT *pDevice,
			MSGSTRUCT_RTR *pMsg,
			U16*pMsgCount,
			U16*pMsgLostStk,
			U16*pMsgLostHBuf,
			U16 uMsgLoc);

/* ----------------------------------------------------------------------------*/    
S16 HoltRT1GetStkMsgRaw(
			PLX_DEVICE_OBJECT *pDevice,
			MSGSTRUCT_RTR *pMsg,
			U16 uMsgLoc);
/* ----------------------------------------------------------------------------*/    
S16 HoltRT1GetHBufMsgsRaw(
			PLX_DEVICE_OBJECT *pDevice,
			U16 *pBuffer,
			U16 uBufferSize,
			U16 *pMsgCount,
			U16 *pMsgLostStk,
			U16 *pMsgLostHBuf);

/* ----------------------------------------------------------------------------*/    
S16 HoltRT1GetStkMetric(
			PLX_DEVICE_OBJECT *pDevice, 
			STKMETRIC *pMetric,
			U16 uReset);

/* ----------------------------------------------------------------------------*/    
S16 HoltRT1GetStkMsgDecoded(
			PLX_DEVICE_OBJECT *pDevice,
			MSGSTRUCT *pMsg,
			U16 uMsgLoc);

/* ----------------------------------------------------------------------------*/    
S16 HoltRT1GetStkMsgsRaw(
			PLX_DEVICE_OBJECT *pDevice,
			U16 *pBuffer, 
			U16 uBufferSize);

/* ----------------------------------------------------------------------------*/    
S16 HoltRT1ModeCodeIrqDisable(
			PLX_DEVICE_OBJECT *pDevice,
			U16 uModeCodeType,
			U16 uModeCodeIrq);

/* ----------------------------------------------------------------------------*/    
S16 HoltRT1ModeCodeIrqEnable(
			PLX_DEVICE_OBJECT *pDevice,
			U16 uModeCodeType,
			U16 uModeCodeIrq);
 
/* ----------------------------------------------------------------------------*/    
S16 HoltRT1ModeCodeIrqStatus(
			PLX_DEVICE_OBJECT *pDevice,
			U16 uModeCodeType,
			U16 *pMCIrqStatus);
 
/* ----------------------------------------------------------------------------*/    
S16 HoltRT1ModeCodeReadData(
			PLX_DEVICE_OBJECT *pDevice,
			U16 uModeCode,
			U16 *pMCData);
 
/* ----------------------------------------------------------------------------*/    
S16 HoltRT1ModeCodeWriteData(
			PLX_DEVICE_OBJECT *pDevice,
			U16 uModeCode,
			U16 uMCData);
  
/* ----------------------------------------------------------------------------*/    
S16 HoltRT1MsgLegalityDisable(
			PLX_DEVICE_OBJECT *pDevice,
			U16 uOwnAddrOrBcst,
			U16 uTR,
			U16 uSA,
			U32 uWCMask);
  
/* ----------------------------------------------------------------------------*/    
S16 HoltRT1MsgLegalityEnable(
			PLX_DEVICE_OBJECT *pDevice,
			U16 uOwnAddrOrBcst,
			U16 uTR,
			U16 uSA,
			U32 uWCMask);
			  
/* ----------------------------------------------------------------------------*/    
S16 HoltRT1MsgLegalityStatus(
			PLX_DEVICE_OBJECT *pDevice,
			U16 uOwnAddrOrBcst,
			U16 uTR,
			U16 uSA,
			U32 *pWCMask);

/* ----------------------------------------------------------------------------*/    
S16 HoltRT1RelatchAddress( 
			PLX_DEVICE_OBJECT *pDevice );
   
/* ----------------------------------------------------------------------------*/    
S16 HoltRT1SetAddress(
			PLX_DEVICE_OBJECT *pDevice,
			U16 uRTAddress);
    
/* ----------------------------------------------------------------------------*/    
S16 HoltRT1Start(
			PLX_DEVICE_OBJECT *pDevice);
   
/* ----------------------------------------------------------------------------*/    
S16 HoltRT1Stop(
			PLX_DEVICE_OBJECT *pDevice);

/* ----------------------------------------------------------------------*/