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
 */
/* Rev 1.00 
	- Initial Release KPatel 1/30/2014
        - Complies with "Holt HI-6130 API Library Software Manual Rev 1.0"
	  API calls.
	- Split registers calls further to reflect the functionality.

 */

#define PLX 1
#ifdef PLX
    #include "PlxApi.h"
	#include <time.h>
	#include <stdlib.h>
	#include <stdio.h>
#define uChanID PLX_DEVICE_OBJECT *pDevice

#endif

#define IAR 0
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
#define BC_ena   1 // Bus Controller
#define RT1_ena  1 // Remote Terminal 1
#define RT2_ena  1 // Remote Terminal 2  
#define SMT_ena  1 // Simple Monitor Terminal   
#define IMT_ena  0 // IRIG-106 Monitor Terminal or SMT
//--------------------------------
#define NULL_MASK 0
#define CHN_ID0 0
#define HOLT_RX_CMD 0
#define HOLT_TX_CMD 1
#define HOLT_RT_MODIFY_ALL 0xFFFF
#define TRUE 1
#define FALSE 0

#define MSG_BLK_LEN 10
#define MSG_RTtoRT_LEN 16

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

extern  U16 HOLT_FRAME_MAJOR;
extern  U16 HOLT_FRAME_OTHER;
extern  U16 HOLT_FRAME_MINOR;

// Buffer manager
extern U16 BC_BUF_BASE;   // start of host allocated static RAM
extern U16 RT_BUF_BASE;   // 4096K
extern U16 RT2_BUF_BASE;  // 4096K
extern U16 MT_BUF_BASE;   // 4096K
extern U16 DEVICE_SCRATCH_PAD;// 12 K 

// BC
extern U16 INST_LIST_ADDR;  
extern U16 BC_MAJOR_BASE_ADDR;
extern U16 BC_MINOR_BASE_ADDR;
extern U16 MSG_BLK_FULL; // 10 word
extern U16 MSG_BLK_ADDR; // 10 word
extern U16 ASYNC_BLK_ADDR;
extern U16 ASYNC_RT_RT_ADDR;
extern U16 DATA_BLK_ADDR;

extern U16 RT1_ILLEGAL_TABLE_BASE_ADDR;
extern U16 RT1_RX_DESCRIP_TABLE_BASE_ADDR; // RT1 default descriptor table addr range 0x0400 to 0x05FF
extern U16 RT1_TX_DESCRIP_TABLE_BASE_ADDR;
extern U16 RT1_RX_DESCRIP_MODE_TABLE_BASE_ADDR; // RT1 default descriptor table addr range 0x0400 to 0x05FF
extern U16 RT1_TX_DESCRIP_MODE_TABLE_BASE_ADDR;

extern U16 RT2_ILLEGAL_TABLE_BASE_ADDR;
extern U16 RT2_RX_DESCRIP_TABLE_BASE_ADDR; // RT1 default descriptor table addr range 0x0400 to 0x05FF
extern U16 RT2_TX_DESCRIP_TABLE_BASE_ADDR;
extern U16 RT2_RX_DESCRIP_MODE_TABLE_BASE_ADDR;// RT1 default descriptor table addr range 0x0400 to 0x05FF
extern U16 RT2_TX_DESCRIP_MODE_TABLE_BASE_ADDR;

extern U16 RT1_DESC_TABLE_SIZE; // default size  will be managed by Memory manager
extern U16 RT1_ILLEGALIZATION_TABLE_SIZE;
extern U16 RT2_RX_DESCRIP_TABLE_BASE_ADDR; // RT1 default descriptor table addr range 0x0400 to 0x05FF
extern U16 RT1_TX_DESCRIP_TABLE_BASE_ADDR;
extern U16 RT1_RX_DESCRIP_MODE_TABLE_BASE_ADDR; // RT1 default descriptor table addr range 0x0400 to 0x05FF
extern U16 RT1_TX_DESCRIP_MODE_TABLE_BASE_ADDR;
// RT
//#define ILLEGAL_CMD_DETECT YES
extern U16 RT1_DATA_BLK_ADDR; 
extern U16 MSG_BLK_RT_ADDR;
extern U16 RT2_DESC_TABLE_SIZE;

//RT2
extern  U16 RT2_DATA_BLK_ADDR; 
extern  U16 MSG_BLK_RT2_ADDR;

// SMT / IMT
extern U16 SMT_FILTER_TABLE_BASE_ADDR; // start of host allocated static RAM
extern U16 IMT_FILTER_TABLE_BASE_ADDR; // start of host allocated static RAM

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

// -----------------------------------
// END Configurable Parameters 
// -----------------------------------

#define TXINHA		1<<15	// inhibit transmitter A
#define TXINHB		1<<14	// inhibit transmitter B
#define BCSTRT		1<<13	// BC start
#define BCENA		1<<12	// BC enable
#define ENA_MAP1    0x0<<10	// HI-6131 SPI only: enable memory addr pointer 1
#define ENA_MAP2	0x1<<10	// HI-6131 SPI only: enable memory addr pointer 2
#define ENA_MAP3	0x2<<10	// HI-6131 SPI only: enable memory addr pointer 3
#define ENA_MAP4	0x3<<10	// HI-6131 SPI only: enable memory addr pointer 4
#define SSR8		1<<9	// HI-6130 bus only: single-strobe 8-bit bus read
#define MTENA 		1<<8	// MT / IMT enable 
#define RT2ENA 		1<<7	// RT2 enable 
#define RT1ENA 		1<<6	// RT1 enable 
#define RT2STEX		1<<5	// RT2 start execution 
#define RT1STEX		1<<4	// RT1 start execution 
#define BSDTXO		1<<3	// mode code 4,20 bus shutdown kills transmit only (receive still works)
#define PULSE_INT	0<<2	// use neg-pulse interrupts, no acknowledge needed
#define LEVEL_INT	1<<2	// interrupts are continuous low level until acknowledged
#define IMTA		1<<1	// if MT enabled, ACTIVE output will be high when
#define CONFIG_RESET 0x0000

// MT is monitoring a message, otherwise ACTIVE only
// indicates activity for BC, RT1 and RT2 
//	Macros for HI-613x Master Status & Reset Register 
//
#define READY		1<<15	// READY goes high after auto-initialization or built-in test completion
#define AUTOEN		1<<13	// enables auto-initialization after /Master Reset.
#define MTRESET		1<<12	// resets the bus monitor if enabled, then self-resets
#define RT2RESET	1<<11	// resets remote terminal 2 if enabled, then self-resets
#define RT1RESET	1<<10	// resets remote terminal 1 if enabled, then self-resets
#define BCMIP		1<<9	// BC messsage in process
#define BCACTIVE	1<<8	// when BC is enabled & running, high during msg processing or programmed delays
#define MTMIP		1<<7	// MT messsage in process
#define IMTPIP		1<<6	// IRIG-106 MT packet in process
#define RT2MIP		1<<5	// RT2 messsage in process
#define RT1MIP		1<<4	// RT1 messsage in process
#define RT2INH		1<<3	// RT2 has a bus inhibited by "bus shutdown" mode code 4 or 20
#define RT1INH		1<<2	// RT1 has a bus inhibited by "bus shutdown" mode code 4 or 20
#define EECKE		1<<1	// during auto-initialization, a checksum error occurred
#define RAMIF 		1<<0	// during auto-initialization, RAM/EEPROM mismatch error

//
//	Macros for HI-613x Time Tag Counter Configuration Register
//
#define MTTAG_CLR	1<<14	// reset MT time tag count to zero
#define MTTAG_LOAD	2<<14	// load MT time tag count from MT Time Tag Utility reg(s)
#define MTTAG_CAP	3<<14	// capture MT time tag count to MT Time Tag Utility reg(s)
#define BTTAG_CLR	1<<12	// reset BC time tag count to zero
#define BTTAG_LOAD	2<<12	// load BC time tag count from BC Time Tag Utility reg(s)
#define R2TTAG_CLR	1<<10	// reset RT2 time tag count to zero
#define R2TTAG_LOAD	2<<10	// load RT2 time tag count from RT2 Time Tag Utility reg
#define R1TTAG_CLR	1<<8	// reset RT1 time tag count to zero
#define R1TTAG_LOAD	2<<8	// load RT1 time tag count from RT1 Time Tag Utility reg
#define MTTAG_OFF	0	    // MT time tag clock is disabled, no counting
#define MTTAG_PIN	1<<4	// MT time tag clock is MTTCLK input pin
#define MTTAG_2U	2<<4	// MT time tag counter uses internally generated 2us clock
#define MTTAG_4U	3<<4	// MT time tag counter uses internally generated 4us clock
#define MTTAG_8U	4<<4	// MT time tag counter uses internally generated 8us clock
#define MTTAG_16U	5<<4	// MT time tag counter uses internally generated 16us clock
#define MTTAG_32U	6<<4	// MT time tag counter uses internally generated 32us clock
#define MTTAG_64U	7<<4	// MT time tag counter uses internally generated 64us clock
#define MTTAG_100N	8<<4	// MT time tag counter uses internally generated 100ns clock
#define BTTAG32		1<<3	// BC time tag counter is 32 bits
#define BTTAG16		0<<3	// BC time tag counter is 16 bits
#define TTAG_PIN	1<<4	// BC & RT time tag clock is TTCLK input pin
#define TTAG_2U		2<<0	// BC & RT time tag counter uses internally generated 2us clock
#define TTAG_4U		3<<0	// BC & RT time tag counter uses internally generated 4us clock
#define TTAG_8U		4<<0	// BC & RT time tag counter uses internally generated 8us clock
#define TTAG_16U	5<<0	// BC & RT time tag counter uses internally generated 16us clock
#define TTAG_32U	6<<0	// BC & RT time tag counter uses internally generated 32us clock
#define TTAG_64U	7<<0	// BC & RT time tag counter uses internally generated 64us clock

// NOTE: for SMT simple bus monitor, 16- or 48-bit time tag is selected by MT Configuration reg bit 1 !!
//
//	Macros for HI-613x Hardware Interrupt Registers: 
//      Interrupt Enable Reg, Interrupt Output Enable Reg & Pending Interrupt Reg 
//
#define HSPI_INT	1<<15	// HI-6131 only: host SPI gave wrong # of SCK clocks
#define EECKE_INT	1<<14	// EEPROM checksum error
#define RAMIF_INT	1<<13	// RAM initialization fail: mismatches EEPROM
#define LBFA		1<<12	// bus A loopback failure
#define LBFB		1<<11	// bus B loopback failure 
#define MTTTRO		1<<10	// MT timetag counter rollover from full count to zero
#define BCTTRO		1<<9	// BC timetag counter rollover from full count to zero
#define RT2TTM		1<<8	// RT2 timetag count matches value in RT2 Timetag Utility reg
#define RT1TTM		1<<7	// RT1 timetag count matches value in RT1 Timetag Utility reg
#define MTTTM		1<<6	// MT timetag count matches value in MT Timetag Utility reg(s)
#define BCTTM		1<<5	// BC timetag count matches value in BC Timetag Utility reg(s)
#define RT2APF		1<<4	// RT2 address parity error (in RT2 Operational Status reg)
#define RT1APF		1<<3	// RT1 address parity error (in RT1 Operational Status reg)

// next 3 only apply to Hardware Pending Interrupt Register
#define RTIP		1<<2	// RT interrupt pending
#define MTIP		1<<1	// MT interrupt pending
#define BCIP		1<<0	// BC interrupt pending

//-------------------------------------------------------------------------------------------
//
//	Macros for HI-613x Bus Controller Configuration Register
//
#define BCTO_15U	0<<14	// "no response timeout" has 15us bus dead time
#define BCTO_20U	1<<14	// "no response timeout" has 20us bus dead time
#define BCTO_58U	2<<14	// "no response timeout" has 18us bus dead time
#define BCTO_138U	3<<14	// "no response timeout" has 138us bus dead time
#define CHKCWFMT	1<<13	// enable msg format error checking (see data sheet)
#define BCRE		1<<12	// BC retry enable
#define BC2RE		1<<11	// BC second retry enable
#define BCR1A		1<<10	// BC first retry use alternate bus
#define BCR2A		1<<9	// BC second retry use alternate bus
#define RESBS		1<<8	// BC retry if RT status bit set
#define MENDV		1<<7	// tx msg is valid if RT gives Message Error status without sending data
#define BSYNDV		1<<6	// tx msg is valid if RT gives Busy status without sending data
#define BCGTE		1<<5	// BC gap timer enable
#define BCWDTE		1<<4	// BC watchdog timer enable
#define TTSYNEN		1<<3	// for mode code 17, transmit (low) 16-bits of BC TTAG count as data
#define ETTSYN		1<<2	// enhanced time tag sync for mode code 17 (see data sheet)
#define BCGCE		1<<1	// BC gap check enable
#define BCRME		1<<0	// BC Broadcast mask enable

//	Macros for HI-613x Bus Controller Interrupt Registers
//	(Int Enable Reg, Int Output Enable Reg & Pending Int Reg)
//
#define BCWDT		1<<15	// BC frame timer expired
#define SELMSG		1<<14	// completion of a 1553 msg with EOM set in msg block Control Word
#define BCGPQ		1<<13	// BC general pupose queue rollover
#define BCRETRY		1<<12	// occurence of a retried 1553 message
#define CSTKERR		1<<11	// BC call stack pointer error
#define BCTRAP		1<<10 	// BC trap interrupt, illegal op code 
#define STATSET		1<<9	// BC status set (see data sheet)
#define BCIRQMASK	15<<5	// logical AND mask for 4-bit interrupt request bits
#define BCMERR		1<<4	// message error status received from RT
#define BCEOM		1<<3	// end-of-message interrupt 

//-------------------------------------------------------------------------------------------
//
//	Macros for HI-613x Remote Terminal RT1 & RT2 Configuration Registers
//
#define RTTO_15U	0<<14	// RT-RT receive "no response timeout" has 15us bus dead time
#define RTTO_20U	1<<14	// RT-RT receive "no response timeout" has 20us bus dead time
#define RTTO_58U	2<<14	// RT-RT receive "no response timeout" has 18us bus dead time
#define RTTO_138U	3<<14	// RT-RT receive "no response timeout" has 138us bus dead time
#define RTINH_A		1<<13	// RT inhibit Bus A as defined by BSDTXO bit in register 0
#define RTINH_B		1<<12	// RT inhibit Bus B as defined by BSDTXO bit in register 0
#define BCASTINV	1<<11	// when high, this bit renders broadcast commands invalid for this RT
#define DBCENA		1<<10	// dynamic bus control enable for this RT
#define UMCINV		1<<9	// undefined mode commands invalid
#define NOTICE2		1<<8	// 1553 Notice 2 storage of broadcast command data
#define SMCP		1<<7	// simplified mode command processing
#define TRXDB		1<<6	// temporary receive buffer enable
#define ALTBITW		1<<5	// use alternate BIT word for mode code 19
#define HOST_SHUTDN	1<<4	// host does bus shutdown for mode codes 4,20
#define AUTO_SHUTDN	0<<4	// automatic bus shutdown for mode codes 4,20
#define HOSTSYNC	0<<2	// host performs synchronize for mode code 17
#define ASYNCDB0	1<<2	// device performs mode code 17 sync, loading data to timetag if data bit 0 = 0
#define ASYNCDB1	2<<2	// device performs mode code 17 sync, loading data to timetag if data bit 0 = 1
#define AUTO_SYNC	3<<2	// device performs mode code 17 sync, unconditionally loading data to timetag
#define MC16OPT		1<<1	// mode code command 16 option (see data sheet)
#define HOST_MC8_RESET  1	// host reset for mode code command 8 (see data sheet)
#define AUTO_MC8_RESET  0	// automatic soft reset for mode code command 8 (see data sheet)

//
//	Macros for HI-613x Remote Terminal RT1 & RT2 Operational Status Registers
//
#define RTAP		1<<10	// RT address parity bit
#define LOCK		1<<9	// Terminal address bits lock (write prevented)
#define MCND		1<<5	// current (last) command was a mode command, no data (transmit MC0-MC15)
#define MCRD		1<<4	// current (last) command was a mode command, w/ data (receive  MC16-MC31)
#define MCTD		1<<3	// current (last) command was a mode command, w/ data (transmit MC16-MC31)
#define RTAPF		1<<2	// interrupt for RT address parity error

//
//	Macros for HI-613x Remote Terminal RT1 & RT2 descriptor table Control Words
//
#define IXEQZ		0x8000	// interrupt when index equals zero
#define IWA			0x4000	// interrupt whenever accessed
#define IBRD		0x2000	// interrupt when broadcast command
#define MKBUSY		0x1000	// make busy
#define DBAC		0x0800	// data block accessed
#define DPA			0x0400	// data pointer A flag
#define BCAST		0x0200	// broadcast flag
#define PPON		0x0100	// ping-pong enable status
#define STOPP		0x0008	// stop ping-pong request
#define PINGPONG	0x0004	// ping-pong mode select
#define CIR2_2MSG	0x0032	// circular mode 2 select, 2 messages
#define CIR2_4MSG	0x0042	// circular mode 2 select, 4 messages  
#define CIR2_8MSG	0x0052	// circular mode 2 select, 8 messages  
#define CIR2_16MSG	0x0062	// circular mode 2 select, 16 messages  
#define CIR2_32MSG	0x0072	// circular mode 2 select, 32 messages  
#define CIR2_64MSG	0x0082	// circular mode 2 select, 64 messages  
#define CIR2_128MSG	0x0092	// circular mode 2 select, 128 messages  
#define CIR2_256MSG	0x00A2	// circular mode 2 select, 256 messages  
#define CIR2_512MSG	0x00B2	// circular mode 2 select, 512 messages  
#define CIRC1		0x0001	// circular mode 1 select
#define INDEX		0x0000	// index mode select

//
//	Macros for HI-613x Remote Terminal RT1 & RT2 1553 Status Word Bits Registers
//
#define TXANDCLR	1<<15	// transmit once then clear 
#define INST		1<<9	// instrumentation
#define SVCREQ		1<<8	// service request
#define BUSY		1<<3	// busy
#define SUBSYSTEM	1<<2	// subsystem flag
#define TERMFLAG	1<<0	// terminal flag bit

//
//	Macros for HI-613x Remote Terminal Interrupt Registers
//	(Int Enable Reg, Int Output Enable Reg & Pending Int Reg)
//
#define RT2_MC8		1<<15	// mode code command 8, "reset RT"
#define RT2_IXEQZ	1<<14	// interrupt when index equals zero
#define RT2_ILCMD	1<<13	// interrupt for illegalized command
#define RT2_IBR		1<<12	// interrupt when broadcast command
#define RT2_MERR	1<<11	// interrupt for message error
#define RT2_IWA		1<<10	// interrupt whenever accessed

#define RT1_MC8		1<<8	// mode code command 8, "reset RT"
#define RT1_IXEQZ	1<<7	// interrupt when index equals zero
#define RT1_ILCMD	1<<6	// interrupt for illegalized command
#define RT1_IBR		1<<5	// interrupt when broadcast command
#define RT1_MERR	1<<4	// interrupt for message error
#define RT1_IWA		1<<3	// interrupt whenever accessed

//
//      Macros for HI-613x Remote Terminal RT1 & RT2 BIT (Built-In Test) Word Registers
//
#define TXSDA		1<<15	// Bus A transmitter shut down by MC4 or MC21
#define TXSDB		1<<14	// Bus B transmitter shut down by MC4 or MC21
#define RXSDA		1<<13	// Bus A receiver shut down by MC4 or MC21
#define RXSDB		1<<12	// Bus B receiver shut down by MC4 or MC21
#define BLBFA		1<<5	// BIST Bus A loopback failure
#define BLBFB		1<<4	// BIST Bus B loopback failure
#define BMTF		1<<3	// BIST memory test failure
#define RTAPE		1<<2	// RT address parity error 
#define EEPROMFAIL	1<<1	// EEPROM load fail flag
#define TFLAGINH	1<<0	// Terminal Flag (status) Bit inhibited by MC6

//-------------------------------------------------------------------------------------------

//
// 	Macros for HI-613x Bus Monitor Configuration Register
// 
// These 3 options apply only to Simple Monitor 
#define SELECT_SMT	1	// select mode: Simple Monitor enabled
#define SMT_TTAG48	1<<1	// SMT ONLY: 48-bit time tagging
#define SMT_TTAG16	0<<1	// SMT ONLY: 16-bit time tagging

// These options apply only to IRIG-106 Monitor 
#define SELECT_IMT	0	// select mode: IRIG-106 Monitor enabled
#define IMT_HDR_OFF 1<<3	// IMT ONLY: disable packet header/trailer generation 
#define IMT_HDR_ON	0<<3	// IMT ONLY: enable packet header/trailer generation
#define IMT_CKSUM_ON  1<<1	// IMT ONLY: enable data packet checksum
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
#define MAXMSGS		1<<13	// IMT ONLY: max msg count attained
#define MAXGAP		1<<12	// IMT ONLY: max gap time exceeded
#define MAXTIME		1<<11	// IMT ONLY: max recording time exceeded
#define HPKTSTOP	1<<10	// IMT ONLY: host asserted packet stop, now stopped
#define PKTREADY	1<<9 	// IMT ONLY: packet ready, other bit says why
#define FULL_OFS	1<<5 	// IMT ONLY: offset from FULL_EOP interrupt

// These interrupts apply only to Simple Monitor 
#define DSTKROVR	1<<7 	// SMT ONLY: data stack end-address written 
#define DSTKADRSS	1<<5 	// SMT ONLY: data stack address written equals word 7 in MT Addr List
#define MSG_ERR		1<<4	// SMT ONLY: RT status word detected with Message Error

// Error code definition
#define HOLT_SUCCESS 0
#define HOLT_ERR_TIMEOUT 50
#define HOLT_ERR_DATA_UNAVAILABLE 51
#define HOLT_ERR_BUFFER_OVERFLOW 52
#define HOLT_ERR_BUFFER_UNAVAILABLE 53
#define HOLT_ERR_FUTURE_IMPLEMENTATION -46
#define HOLT_ERR_NOT_SUPPORTED_HARDWARE -47
#define HOLT_ERR_PARAMATER -48
#define HOLT_ERR_NOT_IMPLEMENTED_YET -49
#define HOLT_ERR_INVALID_DEVNUM -50
#define HOLT_ERR_INVALID_ACCESS -51
#define HOLT_ERR_INVALID_MODE -52
#define HOLT_ERR_INVALID_STATE -53
#define HOLT_ERR_INVALID_MEMSIZE -54
#define HOLT_ERR_INVALID_ADDRESS -55
#define HOLT_ERR_INVALID_OS -56
#define HOLT_ERR_INVALID_MALLOC -57
#define HOLT_ERR_INVALID_BUF -58
#define HOLT_ERR_INVALID_ADMODE -59
#define HOLT_ERR_SIMWRITEREG -60
#define HOLT_ERR_TIMETAG_RES -61
#define HOLT_ERR_RESPTIME -62
#define HOLT_ERR_CLOCKIN -63
#define HOLT_ERR_MSGSTRUCT -64
#define HOLT_ERR_PARAMETER -65
#define HOLT_ERR_INVALID_MODE_OP -66
#define HOLT_ERR_METRICS_NOT_ENA -67
#define HOLT_ERR_NOT_SUPPORTED -68
#define HOLT_ERR_ISQ_DISABLED -69
#define HOLT_ERR_TASK_FAIL -70
#define HOLT_ERR_CANADDR -71
#define HOLT_ERR_DIO -72
#define HOLT_ERR_OVERFLOW -73
#define HOLT_ERR_INITIALIZED -74
#define HOLT_ERR_INVALID_SIZE -75
#define HOLT_ERR_REG_ACCESS -80
#define HOLT_ERR_INVALID_CARD -81
#define HOLT_ERR_DRIVER_OPEN -82
#define HOLT_ERR_MAPMEN_ACC -83
#define HOLT_ERR_NODE_NOT_FOUND -100
#define HOLT_ERR_NODE_MEMBLOCK -101
#define HOLT_ERR_NODE_EXISTS -102
#define HOLT_ERR_MEMMGR_FAIL -150
#define HOLT_ERR_TEST_BADSTRUCT -200
#define HOLT_ERR_TEST_FILE -201
#define HOLT_ERR_MT_BUFTYPE -300
#define HOLT_ERR_MT_CMDSTK -301
#define HOLT_ERR_MT_DATASTK -302
#define HOLT_ERR_MT_FILTER_RT -303
#define HOLT_ERR_MT_FILTER_TR -304
#define HOLT_ERR_MT_FILTER_SA -305
#define HOLT_ERR_MT_STKLOC -306
#define HOLT_ERR_MT_MSGLOC -307
#define HOLT_ERR_MT_HBUFSIZE -308
#define HOLT_ERR_MT_HBUF -309
#define HOLT_ERR_RTMT_COMBO_HBUF -310
#define HOLT_ERR_RTMT_HBUFSIZE -311
#define HOLT_ERR_RTMT_HBUF -312
#define HOLT_ERR_RTMT_MSGLOC -313
#define HOLT_ERR_RT_DBLK_EXISTS -400
#define HOLT_ERR_RT_DBLK_ALLOC -401
#define HOLT_ERR_RT_DBLK_MAPPED -402
#define HOLT_ERR_RT_DBLK_NOT_CB -403
#define HOLT_ERR_RT_HBUF -410
#define HOLT_ERR_BC_DBLK_EXISTS -500
#define HOLT_ERR_BC_DBLK_ALLOC -501
#define HOLT_ERR_BC_DBLK_SIZE -502
#define HOLT_ERR_UNRES_DATABLK -503
#define HOLT_ERR_UNRES_MSGBLK -504
#define HOLT_ERR_UNRES_FRAME -505
#define HOLT_ERR_UNRES_OPCODE -506
#define HOLT_ERR_UNRES_JUMP -507
#define HOLT_ERR_FRAME_NOT_MAJOR -508
#define HOLT_ERR_NOT_ASYNC_MODE -509
#define HOLT_ERR_UNRES_ASYNC_OP -510
#define HOLT_ERR_UNRES_ASYNC_ID -511
#define HOLT_ERR_ASYNC_NOT_EMPTY -512
#define HOLT_ERR_ASYNC_MSG -513
#define HOLT_ERR_HBUFSIZE -600
#define HOLT_ERR_HBUF -601
#define HOLT_ERR_DISCRETE -650
#define HOLT_ERR_DLEVEL -651
#define HOLT_ERR_TOO_MANY_DEVS -700
#define HOLT_MTI_ERR_EMPTY_QUEUE -701
#define HOLT_ERR_MEMMGR_MN_BLK_SIZE -702
#define HOLT_MTI_ERR_STATE -703
#define HOLT_ERR_DMA_CHNL_REG -704
#define HOLT_ERR_DMA_QCALLOC -705
#define HOLT_ERR_DMA_REMOVE_CHANNEL -706
#define HOLT_ERR_DMA_BUFFER_LENGTH 0
#define HOLT_ERR_DMA_Q -708
#define HOLT_ERR_DMA_ZERO_BUFFER -709
#define HOLT_ERR_AVIONIC -750
#define HOLT_ERR_EMPTY_QUEUE -751
#define HOLT_RESOURCE_REQ_ERR -800
#define HOLT_IOWRITE_ERR -801
#define HOLT_IOREAD_ERR -802
#define HOLT_MEM_MAP_ERR -803
#define HOLT_TASK_SPAWN_ERR -804
#define HOLT_MEM_ADDR_OUT_OF_RANGE -805
#define HOLT_POINTER_OUT_OF_RANGE -806
#define HOLT_DATA_LENGTH_OUT_OF_RANGE -807
#define HOLT_ERR_BC_MBLK_EXISTS -810
#define HOLT_ERR_MMGR_FAIL -811
#define HOLT_ERR_RXRT -812
#define HOLT_ERR_RXSA -813
#define HOLT_ERR_TXRT -814
#define HOLT_ERR_INVALID_PARAMETER -815

// Warnings
#define HOLT_WRN_RT_CFG_INVALID 400
#define HOLT_WRN_BC_OPCODE_INVALID 500

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


typedef struct {unsigned S8 value; } ElemType;

/* Circular buffer object */
typedef struct {
    int         size;   /* maximum number of elements           */
    int         start;  /* index of oldest element              */
    int         end;    /* index at which to write new element  */
    int         numberOfMessages;
    ElemType   *elements;  /* vector of elements                */
} MessageBuffer;

#define CIRCULAR_BUFFER_SIZE 20
#if 1
extern U16 HoltWriteMemoryRange(PLX_DEVICE_OBJECT *pDevice, U16 uMemAddr, U16 *pData, U16 uLength);
extern U16 HoltReadMemoryRange(PLX_DEVICE_OBJECT *pDevice, U16 uMemAddr, U16 *pData, U16 uLength);
extern U16 HoltWriteRegister(PLX_DEVICE_OBJECT *pDevice, U16 uRegAddr, U16 uData);

#endif


 #ifdef __cplusplus
}
#endif
extern S16 HoltReadRegister(PLX_DEVICE_OBJECT *pDevice, U16 uRegAddr);
