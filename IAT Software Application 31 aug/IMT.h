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

#define IMT_ADDRESSLIST_A 0x00b0
#define IMT_ADDRESSLIST_A_END_CMD_STK 0x00b2
#define IMT_ADDRESSLIST_A_START_DATA_BLK 0x00b4

#define IMT_ADDRESSLIST_B 0x00b8
#define IMT_ADDRESSLIST_B_END_CMD_STK 0x00ba
#define IMT_ADDRESSLIST_B_START_DATA_BLK 0x00bc

#define IMT_MESSAGE_FILTER_TABLE 0x100
#define IMT_CH10_PKT_HEADER_SIZE	24

/* Device Memory Buffer Sizes in Bytes*/
#define IMT_DEVBUF_SIZE_4K		0x001000
#define IMT_DEVBUF_SIZE_8K		0x002000
#define IMT_DEVBUF_SIZE_16K		0x004000
#define IMT_DEVBUF_SIZE_32K		0x008000
#define IMT_DEVBUF_SIZE_64K		0x010000
#define IMT_DEVBUF_SIZE_128K	0x020000
#define IMT_DEVBUF_SIZE_256K	0x040000
#define IMT_DEVBUF_SIZE_512K	0x080000
#define IMT_DEVBUF_SIZE_1M		0x100000
#define IMT_DEVBUF_SIZE_MAX		0x004000
/* Interrupt Condition Masks */
#define IMT_OVERFLOW_INT       0x020     /*  interrupt host on overflow of unified cmd/data
                                             stack */
#define IMT_HOST_INT           0x010     /* asynchronous interrupt event forced by host  */
#define IMT_TIME_MSG_TRIG_INT  0x008     /* interrupt on time reached, triggered by msg  */
#define IMT_TIME_INT           0x004     /* interrupt on time period                     */
#define IMT_NUM_MSGS           0x002     /* interrupt on number of messages reached      */
#define IMT_NUM_WORDS          0x001     /* interrupt on number of words reached         */

/* Interrupt Mask Register #3 (IMR3) Bits */
#define IMR3_IMT_NUM_WORDS      0x0001
#define IMR3_IMT_NUM_MSGS       0x0002
#define IMR3_IMT_TIME           0x0004
#define IMR3_IMT_MSG_TIME       0x0008
#define IMR3_IMT_HOST           0x0010
#define IMR3_IMT_OVR	        0x0020

/* Chapter 10 time packet IRIG formats */
#define IRIG_FMT_MASK	0x0016L
#define IRIG_FMT_NONE	0x0000L
#define IRIG_FMT_1		0x0002L
#define IRIG_FMT_2		0x0004L
#define IRIG_FMT_3		0x0006L
#define IRIG_FMT_4		0x0008L

/* Chapter 10 time packet enable mask */
#define IMT_CH10_TIME_PKT_MASK		0x20000
#define IMT_CH10_TIME_PKT_ENABLE	0x20000
#define IMT_CH10_TIME_PKT_DISABLE	0x00000

/* Chapter 10 time packet IRIG enable */
#define IMT_CH10_TIME_PKT_IRIG_MASK		0x1
#define IMT_CH10_TIME_PKT_IRIG_DISABLE	0x0
#define IMT_CH10_TIME_PKT_IRIG_ENABLE	0x1

/* MTI Configure parameter range definitions */
#define IMT_BUFFER_COUNT_MIN	4
#define IMT_BUFFER_COUNT_MAX	32

#define IMT_BUFFER_SIZE_MIN		0x1000
#define IMT_BUFFER_SIZE_MAX		0x80000

#define IMT_INTERRUPT_TIME_MIN	10		 /* 1ms Minimum Interrupt Interval */
#define IMT_INTERRUPT_TIME_MAX	65535  /* 6.5535s Maximun Interrupt Interval */

#define IMT_INTERRUPT_MSG_MIN	100      /* Based On Min Buffer Size */
#define IMT_INTERRUPT_MSG_MAX	1000     /* Based On Max Buffer Size */

#define IMT_INTERRUPT_WORDS_MIN	(IMT_BUFFER_SIZE_MIN / 2) - 40 /* Subtract 40 Words For Potential In-Process Message */
#define IMT_INTERRUPT_WORDS_MAX	(IMT_BUFFER_SIZE_MAX / 2) - 40 /* Subtract 40 Words For Potential In-Process Message */

#define IRIG_CH10_PKT_SYNC_PATT        0xEB25
#define IRIG_CH10_PKT_MSG_COUNT_MASK   0x007FFFFF
#define IRIG_CH10_PKT_CHNL_SP_DATA_WORD_SIZE    2
#define IMT_FORMAT_ERR_NO_RESP_MASK    0x0600

/* MTI CH10 File Access */
#define IMT_CH10_FILE_READ  0
#define IMT_CH10_FILE_WRITE 1

/* MTI CH10 File Read Control */
#define IMT_CH10_FILE_READ_CURRENT_PACKET   0
#define IMT_CH10_FILE_READ_NEXT_PACKET      1
// 
// These 3 options apply only to Simple Monitor 
#define SELECT_SMT	1	// select mode: Simple Monitor enabled
#define SMT_TTAG48	1<<1	// SMT ONLY: 48-bit time tagging
#define SMT_TTAG16	0<<1	// SMT ONLY: 16-bit time tagging

// These options apply only to IRIG-106 Monitor 
#define SELECT_IMT	0	// select mode: IRIG-106 Monitor enabled
#define IMT_HDR_OFF 1<<3	// IMT ONLY: disable packet header/trailer generation 
#define IMT_HDR_ON	0<<3	// IMT ONLY: enable packet header/trailer generation
#define IMT_CKSUM_ON 1<<1	// IMT ONLY: enable data packet checksum
#define IMT_CKSUM_OFF 0<<1	// IMT ONLY: disable data packet checksum
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
#define HPKTSTOP	1<<10	// IMT ONLY: host asserted packet stop, now stopped
#define PKTREADY	1<<9 	// IMT ONLY: packet ready, other bit says why
#define FULL_OFS	1<<5 	// IMT ONLY: offset from FULL_EOP interrupt

// These interrupts apply only to Simple Monitor 
#define DSTKROVR	1<<7 	// SMT ONLY: data stack end-address written 
#define DSTKADRSS	1<<5 	// SMT ONLY: data stack address written equals word 7 in MT Addr List
#define MSG_ERR		1<<4	// SMT ONLY: RT status word detected with Message Error


typedef struct {   
    short  command_word;  /* index of oldest element              */
    short  data_pointer;    /* index at which to write new element  */
    short  msg_tt;	
	short  blk_status_wrd;
	short SMTData[255];
 } SMTElemType;

typedef struct {
    int         size;   /* maximum number of elements           */
    int         start;  /* index of oldest element              */
    int         end;    /* index at which to write new element  */
    int         numberOfMessages;
    SMTElemType   *elements;  /* vector of elements                */
} SMTCircularBuffer;


U16 cbSMTInit(SMTCircularBuffer *smt, int size);
void cbSMTFree(SMTCircularBuffer *smt);
int cbSMTIsFull(SMTCircularBuffer *smt);
int cbSMTIsEmpty(SMTCircularBuffer *smt);
void cbSMTWrite(SMTCircularBuffer *smt, SMTElemType *elem);
void cbSMTRead(SMTCircularBuffer *smt, SMTElemType *elem);

/*-----------------------------------------------------------------------
Struct:	IMT_CONFIG

Description:
	This structure describes MTI Mode Configuration.
------------------------------------------------------------------------*/
typedef struct IMT_Config
{
    U32 u32DevBufByteSize;
    U32	u32DevBufWordAddr;
    U32	u32NumBufBlks;
    U32	u32BufBlkByteSize;
    U16	fZeroCopyEnable;
    U32	u32IrqDataLen;
    U32	u32IrqMsgCnt;
    U16	u16IrqTimeInterval;
    U32	u32IntConditions;
    U16	u16Ch10ChnlId;
    U16	u8HdrVer;
    U16	u8RelAbsTime;
    U16	u8Ch10Checksum;
} IMT_Config, *PIMT_CONFIG;

#define IMT_CH10_PKT_HDR_SIZE		24
#define IMT_CH10_PKT_SEC_HDR_SIZE	12
#define IMT_CH10_PKT_HDR_SYNC		0xEB25

#define IMT_CH10_PKT_CH_SPEC_DATA_SIZE	4
#define IMT_CH10_1553_MSG_FMT1_HDR_SIZE	14

S16 HoltIMTConfigure(
			PLX_DEVICE_OBJECT *pDevice,
			U16 uOptions,
			U32 uDevBufSizeBytes,
			U32 uNumBufBlks,
			U32 uBufBlkByteSize,
			 U8 uZeroCopyEnable,
			U32 uIrqDataLen,
			U32 uIrqMsgCnt,
			U16 uIrqTimeInterval,
			U32 uIntConditions,
			U16 uImtChnlId,
			 U8 uHdrVer,
			 U8 uRelAbsTime,
			 U8 uIMTChecksum);

S16 HoltIMTInit(PLX_DEVICE_OBJECT *pDevice);
S16 HoltIMTStart(PLX_DEVICE_OBJECT *pDevice);
S16 HoltIMTStop(PLX_DEVICE_OBJECT *pDevice);
S16 HoltIMTGetCh10DataPkt(PLX_DEVICE_OBJECT *pDevice, U16 *ppCh10Pkt, U16 Timeout);
S16 HoltIMTFreeCh10DataPkt(PLX_DEVICE_OBJECT *pDevice, U16 *ppCh10Pkt);
S16 HoltIMTGetCh10TimePkt(PLX_DEVICE_OBJECT *pDevice, U16 *ppCh10Pkt, U16 Timeout);
S16 HoltIMTPause(PLX_DEVICE_OBJECT *pDevice);
S16 HoltIMTContinue(PLX_DEVICE_OBJECT *pDevice);
S16 HoltIMTInitiateHostIrq(PLX_DEVICE_OBJECT *pDevice);
S16 HoltIMTCh10TimePktEnable(PLX_DEVICE_OBJECT *pDevice, U16 bEnable);
S16 HoltIMTAddressListRead(PLX_DEVICE_OBJECT *pDevice, U16 uDataBlkID,
									   U16 *pBuffer, U16 wBufferSize,
									   U16 wOffset);


S16 HoltIMTAddressListWrite(PLX_DEVICE_OBJECT *pDevice, U16 uDataBlkID,
									   U16 *pBuffer, U16 wBufferSize,
									   U16 wOffset); 

S16 HoltIMTFilterTableWrite(PLX_DEVICE_OBJECT *pDevice, U16 wRTAddr,
									           U16 wTR, U16 wSA,
									           U32 dwWC_MCMask); 


S16 HoltIMTFilterTableRead(PLX_DEVICE_OBJECT *pDevice, U16 wRTAddr,
                                        U16 wTR, U16 wSA,
                                        U32 *dwWC_MCMask); 

S16 HoltIMTScheduler(PLX_DEVICE_OBJECT *pDevice);


short HoltIMTFilterTblWrite(PLX_DEVICE_OBJECT *pDevice,
                                     U16 RTSubAddr,
                                     U16 SA_RT_TX_Mask_1,
                                     U16 SA_RT_RX_Mask_2,
                                     U16 SA_RT_TX_Mask_3,
                                     U16 SA_RT_RX_Mask_4);

short HoltIMTFilterTblRead(PLX_DEVICE_OBJECT *pDevice,U16 RTAddr, U16 *buffer);

short HoltIMTUninstallHBuf(PLX_DEVICE_OBJECT *pDevice);

short HoltIMTInstallHBuf(PLX_DEVICE_OBJECT *pDevice, U16 wBufferSize);

short HoltIMTCreateImageFiles(PLX_DEVICE_OBJECT *pDevice, US dwOptions, S8 *pszlFile, S8 *pszHFile);

short HoltIMTDecodeRawMsg(	PLX_DEVICE_OBJECT *pDevice,
			U16 *pBuffer,
			U16 uBufferSize,
			U16 *pMsgCount,
			U16 *pMsgLostStk,
			U16 *pMsgLostHBuf);

short HoltIMTGetHBufMsgCount(PLX_DEVICE_OBJECT *pDevice); 


