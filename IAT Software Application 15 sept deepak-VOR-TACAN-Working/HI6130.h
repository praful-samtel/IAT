// Holt HI-6130 header file for PCIe constants

#ifdef __cplusplus
extern "C" {
#endif

#define HI6130BASE 0X20000000		// R/W Based address for the 6130
#define MAIN_LATCHES 0x24000000			// R/W LED and MR GPIO port
#define STATUSINPUT 0x28000000		// R READY, ACTIVE, nIRQ, RTXMC8 interrupt inputs
#define SECONDARYOUTPUTLATCHES 0x2C000000	// R RT,BC,MT switch inputs

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

//      Macros for HI-613x Bus Controller Instruction List
//      Command Word entries
//
#define RX 		0
#define TX		1<<10

//      Macros for HI-613x Bus Controller Instruction List
//      BC Control Word 
//
#define TXTTMC17	1<<15	// only applies for mode code 17: transmit BC time tag count
#define MEMASK		1<<14	// if bit 0 = 0, Status Set occurs for RT Status Word Msg Error bit
#define SRQMASK		1<<13	// if bit 0 = 0, Status Set occurs for RT Status Word Svc Request bit
#define BSYMASK		1<<12	// if bit 0 = 0, Status Set occurs for RT Status Word Busy bit
#define SSFMASK		1<<11	// if bit 0 = 0, Status Set occurs for RT Status Word Subsystem Fail bit
#define TFMASK		1<<10	// if bit 0 = 0, Status Set occurs for RT Status Word Terminal Flag bit
#define RSVMASK		1<<9	// if bit 0 = 0, Status Set occurs for any RT Status Word Reserved bit 7-5
#define RTRYENA		1<<8	// if retry enabled in BC Config reg, retry occurs for Status Set
#define USEBUSA		1<<7	// if bit = 1 then use Bus A, if bit = 0 then use Bus B
#define USEBUSB		0<<7
#define SFTEST		1<<6	// if bit = 1 then use offline self-test
#define MSKBCR		1<<5	// if BCRME = 1 in BC Config, this bit INVERTED reflects expected BCR status, 
				//				mismatch when BCR = 1 causes status set
				// if BCRME = 0 in BC Config, this bit reflects expected BCR status, 
				//				mismatch = status set
#define EOMINT		1<<4	// if BCEOM interrupt is enabled, this bit causes message EOM interrupt
// bit 3 reserved 					
#define MCODE		1<<2	// select mode code message format
#define BCST		1<<1	// select broadcast message format
#define RT_RT		1<<0	// select RT-to-RT message format


//	Macros for HI-613x Bus Controller Instruction List
//      BC Op Codes 
//
#define XEQ	0x01<<10
#define XQG	0x16<<10
#define JMP	0x02<<10
#define CAL	0x03<<10
#define IRQ	0x06<<10
#define RTN	0x04<<10
#define HLT	0x07<<10
#define DLY	0x08<<10
#define WFT	0x09<<10
#define CFT	0x0A<<10
#define CMT	0x0B<<10
#define LTT	0x0D<<10
#define LTH	0x18<<10
#define LFT	0x0E<<10
#define SFT	0x0F<<10
#define PTT	0x10<<10
#define PTH	0x19<<10
#define PTB	0x1A<<10
#define PBS	0x11<<10
#define PSI	0x12<<10
#define PSM	0x13<<10
#define WTG	0x14<<10
#define XQF	0x15<<10
#define XFG	0x17<<10
#define WMP	0x1B<<10
#define WMI	0x1C<<10
#define DSZ	0x1D<<10
#define FLG	0x0C<<10
//	Macros for HI-613x Bus Controller Instruction List
//      BC Condition Codes 
//
#define LT        0
#define GP0       0
#define GTorEQ    16
#define nGP0      16
#define EQ        1
#define GP1       1
#define nEQ       17
#define nGP1      17
#define GP2       2
#define nGP2      18
#define GP3       3
#define nGP3      19
#define GP4       4
#define nGP4      20
#define GP5       5
#define nGP5      21
#define GP6       6
#define nGP6      22
#define GP7       7
#define nGP7      23
#define nRESP     8
#define RESP      24
#define FMTERR    9
#define nFMTERR   25
#define GBLOCK    10
#define nGBLOCK   26
#define MASKSTAT  11
#define nMASKSTAT 27
#define BADMSG    12
#define GOODMSG   28
#define x1RETRY   13
#define n1RETRY   29
#define x2RETRY   14
#define ALWAYS    15
#define NEVER     31

// op code word validation field with odd parity bit = 0 
#define VP0                 0x0140

// op code word validation field with odd parity bit = 1 
#define VP1                 0x8140
#define BC_ILIST_BASE_ADDR 0x1B70

// GPIO functions
U16 MasterReset6130(PLX_DEVICE_OBJECT *pDevice);
#if 1
U16 ReadGPIOPort(PLX_DEVICE_OBJECT *pDevice, U32 port);
U16 WriteGPIOPort(PLX_DEVICE_OBJECT *pDevice, U32 port, U16 gpio);
U16 SetBit(PLX_DEVICE_OBJECT *pDevice, U32 port, U16 mask);
U16 ClearBit(PLX_DEVICE_OBJECT *pDevice, U32 port, U16 mask);
#endif
U16 bc_trigger(PLX_DEVICE_OBJECT *pDevice);

// 6130 device memory space functions
U16 Read6130Regs(PLX_DEVICE_OBJECT *pDevice);
U16 HoltReadRegister(PLX_DEVICE_OBJECT *pDevice, U16 reg, U16 *buffer);
U16 ReadRegister(PLX_DEVICE_OBJECT *pDevice, U16 reg);
U16 WriteRegister(PLX_DEVICE_OBJECT *pDevice, U16 reg, U16 value);
U16 HoltWriteRegister(PLX_DEVICE_OBJECT *pDevice, U16 reg, U16 value);

void initialize_bc_msg_blocks(PLX_DEVICE_OBJECT *pDevice);
void initialize_bc_instruction_list(PLX_DEVICE_OBJECT *pDevice);

U16 ReadDisplayRange(PLX_DEVICE_OBJECT *pDevice, U16 localAddress, U16 len);
U16 WriteMemoryRange(PLX_DEVICE_OBJECT *pDevice, U16 localAddress, U16 *buffer, U16 len);
U16 HoltWriteMemoryRange(PLX_DEVICE_OBJECT *pDevice, U16 localAddress, U16 *buffer, U16 len);
U16 ReadMemoryRange(PLX_DEVICE_OBJECT *pDevice, U16 localAddress, U16 *pBufferDest, U16 len);
U16 HoltReadMemoryRange(PLX_DEVICE_OBJECT *pDevice, U16 localAddress, U16 *pBufferDest, U16 len);
U16 FetchMemoryRange(PLX_DEVICE_OBJECT *pDevice, U16 localAddress, U16 *pBufferDest, U16 len);

// Misc functions
void delay(U32 count);
U16 ack_irq(PLX_DEVICE_OBJECT *pDevice);
void commandMenu(void);

 #ifdef __cplusplus
}
#endif