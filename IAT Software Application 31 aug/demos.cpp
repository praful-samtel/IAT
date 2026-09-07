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

//------------------------------------------------------------------------------
//         Headers
//------------------------------------------------------------------------------

#include "stdafx.h"

#include "ConsFunc.h"
#include "PlxApi.h"
#include "PlxInit.h"
#include "HI6130.h"

//#include "AppConfig.h"
#include "Api.h"
#include "CommonAPI.h"
#include "Registers.h"




// Demo defines
#define RECEIVE 0
#define TRANSMIT 1
#define BUFFER_SIZE 8
#define RT_ADDRESS 27
#define RT1_ADDRESS 4
#define RT_SUB_ADDRESS 1

#define SMT_ADDRESSLIST_A 0x00b0
#define SMT_ADDRESSLIST_B 0x00b8

#define START_ADDR_LIST 0x4400  // Start addrese of Address list combined stack
#define CUR_ADDR_LIST   0x4400  // Current addrese of Address list combined stack
#define END_ADDR_LIST   0x4fff  // End  addrese of Address list combined stack
#define INT_ADDR        0x0000  // Interrupt address

#define START_DATA_STACK 0x6000 // Start address of Data Stack
#define CUR_DATA_STACK   0x6000 // current address of Data Stack
#define END_DATA_STACK   0x7fff // end address of Data Stack
#define INT_ADDR_BEFORE_END_STACK 0x1ff// Interrupt address n words before end of stack

#define	  MASTER_CONFIG_REG					0x0000
#define	  STATUS_AND_RESET_REG 				0x0001
#define	  RT1_CURR_CMD_REG 					0x0002
#define	  RT1_CURR_CTRL_WORD_ADDR_REG 		0x0003
//#define	  RT1_CURR_CTRL_WORD_ADDR_REG 		0x0C00
#define	  RT2_CURR_CMD_REG 					0x0004
#define	  RT2_CURR_CTRL_WORD_ADDR_REG 		0x0005
#define	  HDW_PENDING_INT_REG 				0x0006
#define	  BC_PENDING_INT_REG 				0x0007
#define	  SMT_IMT_PENDING_INT_REG 			0x0008
#define	  RT1_RT2_PENDING_INT_REG 			0x0009
#define	  INT_COUNT_AND_LOG_ADDR_REG 		0x000a
#define	  dummy1   							0x000b
#define	  dummy2   				            0x000c
#define	  dummy3  							0x000d
#define	  dummy4  							0x000e
#define   HDW_INT_ENABLE_REG				0x000f
#define	  BC_INT_ENABLE_REG 				0x0010
#define	  SMT_IMT_INT_ENABLE_REG 			0x0011
#define	  RT1_RT2_INT_ENABLE_REG 			0x0012
#define	  HDW_INT_OUTPUT_ENABLE_REG 		0x0013
#define	  BC_INT_OUTPUT_ENABLE_REG 			0x0014
#define	  SMT_IMT_INT_OUTPUT_ENABLE_REG		0x0015
#define	  RT1_RT2_INT_OUTPUT_ENABLE_REG		0x0016
#define	  RT1_CONFIG_REG 					0x0017
//#define	  RT1_CONFIG_REG 					0x0C00
#define	  RT1_OP_STATUS_REG 				0x0018
#define	  RT1_DESC_TBL_BASE_ADDR_REG 		0x0019
#define	  RT1_1553_STATUS_BITS_REG 			0x001a
#define	  RT1_MSG_INFO_WD_ADDR_REG 			0x001b
#define	  RT1_BUSA_SELECT_REG 				0x001c
#define	  RT1_BUSB_SELECT_REG 				0x001d
#define	  RT1_BIT_WORD_REG 					0x001e
#define	  RT1_ALT_BIT_WORD_REG 				0x001f
#define	  RT2_CONFIG_REG 					0x0020
#define	  RT2_OP_STATUS_REG 				0x0021
#define	  RT2_DESC_TBL_BASE_ADDR_REG 		0x0022
#define	  RT2_1553_STATUS_BITS_REG 			0x0023
#define	  RT2_MSG_INFO_WD_ADDR_REG 			0x0024
#define	  RT2_BUSA_SELECT_REG 				0x0025
#define	  RT2_BUSB_SELECT_REG 				0x0026
#define	  RT2_BIT_WORD_REG 					0x0027
#define   RT2_ALT_BIT_WORD_REG 				0x0028
#define	  SMT_IMT_CONFIG_REG 				0x0029
#define	  IMT_MAX_MSG_COUNT 				0x002a
#define	  IMT_MAX_1553_WORDS 				0x002b
#define	  IMT_MAX_PKT_TIME 					0x002c
#define	  IMT_MAX_GAP_TIME 					0x002d
#define	  IMT_CHANNEL_ID 					0x002e
#define	  SMT_IMT_START_ADDR_LIST_POINTER 	0x002f
#define	  SMT_IMT_NEXT_MSG_STACK_ADDR_REG 	0x0030
#define	  SMT_IMT_LAST_MSG_STACK_ADDR_REG 	0x0031
#define	  BC_CONFIG_REG 					0x0032
#define	  BC_INST_LIST_BASE_ADDR_REG 		0x0033
#define	  BC_INST_LIST_POINTER 				0x0034
#define	  BC_FRAME_TIME_REMAINING_REG 		0x0035
#define	  BC_TIME_TO_NEXT_MSG_REG 			0x0036
#define	  BC_CCODE_AND_GPF_REG 				0x0037
#define	  BC_GP_QUEUE_POINTER 				0x0038
#define	  TTAG_CONFIG_REG 					0x0039
#define	  SMT_IMT_TTAG_COUNT_LOW 			0x003a
#define	  SMT_IMT_TTAG_COUNT_MID 			0x003b
#define	  SMT_IMT_TTAG_COUNT_HIGH 			0x003c
#define	  SMT_IMT_TTAG_UTILITY_REG_LOW 		0x003d
#define	  SMT_IMT_TTAG_UTILITY_REG_MID 		0x003e
#define	  SMT_IMT_TTAG_UTILITY_REG_HIGH 	0x003f
#define	  SMT_IMT_TTAG_MATCH_LOW 			0x0040
#define	  SMT_IMT_TTAG_MATCH_MID 			0x0041
#define	  SMT_IMT_TTAG_MATCH_HIGH 			0x0042
#define	  BC_TTAG_COUNT_LOW 				0x0043
#define	  BC_TTAG_COUNT_HIGH 				0x0044
#define	  BC_TTAG_UTILITY_REG_LOW 			0x0045
#define	  BC_TTAG_UTILITY_REG_HIGH 			0x0046
#define	  BC_TTAG_MATCH_LOW 				0x0047
#define	  BC_TTAG_MATCH_HIGH 				0x0048
#define	  RT1_TTAG_COUNT 					0x0049
#define	  RT1_TTAG_UTILITY_REG 				0x004a
#define	  RT2_TTAG_COUNT 					0x004b
#define	  RT2_TTAG_UTILITY_REG 				0x004c
#define	  FACTORY_TEST_CONTROL_REG 	  		0x004d
#define	  EEPROM_UNLOCK_REG 				0x004e
#define	  BC_LAST_MSG_BLOCK_ADDR_REG 		0x004f
#define	  BC_DEFAULT_WMI_REG      			0x0050

#define RT1_TX_CNTRL_WRD 0x0004;
#define RT1_TX_DESC_WRD2 0x2566; 
#define RT1_TX_DESC_WRD3 0x2588; 
#define RT1_TX_DESC_WRD4 0x25aa; 

//  R T 1  R E C E I V E   S U B A D D R E S S   C O M M A N D S  

#define RT1_RX_CNTRL_WRD 0x0004;
#define RT1_RX_DESC_WRD2 0x2500; 
#define RT1_RX_DESC_WRD3 0x2522; 
#define RT1_RX_DESC_WRD4 0x2544; 
//  R T 1   R E C E I V E   M O D E   C O D E   C O M M A N D S 

#define RT1_RX_MODE_CNTRL_WRD 0x0000;
#define RT1_RX_MODE_MSG_INFO  0x1a7a; 
#define RT1_RX_MODE_TT        0x0000; 
#define RT1_RX_MODE_DATAWRD   0x1a7a; 

// R T 1  T R A N S M I T   M O D E   C O D E   C O M M A N D S  

#define RT1_TX_MODE_CNTRL_WRD 0x4004;
#define RT1_TX_MODE_MSG_INFO  0x1aba; 
#define RT1_TX_MODE_TT        0x1abc; 
#define RT1_TX_MODE_DATAWRD   0x1abe; 

//  R T 2  R E C E I V E   S U B A D D R E S S   C O M M A N D S  

#define RT2_RX_CNTRL_WRD 0x0004;
#define RT2_RX_DESC_WRD2 0x3000; 
#define RT2_RX_DESC_WRD3 0x3022; 
#define RT2_RX_DESC_WRD4 0x3044; 

//  R T 2  T R A N S M I T   S U B A D D R E S S   C O M M A N D S  

#define RT2_TX_CNTRL_WRD 0x0004;
#define RT2_TX_DESC_WRD2 0x3066; 
#define RT2_TX_DESC_WRD3 0x3088; 
#define RT2_TX_DESC_WRD4 0x30aa; 

//  R T 2   R E C E I V E   M O D E   C O D E   C O M M A N D S 

#define RT2_RX_MODE_CNTRL_WRD 0x0000;
#define RT2_RX_MODE_MSG_INFO  0x1a7a; 
#define RT2_RX_MODE_TT        0x0000; 
#define RT2_RX_MODE_DATAWRD   0x1a7a; 

// R T 2  T R A N S M I T   M O D E   C O D E   C O M M A N D S  

#define RT2_TX_MODE_CNTRL_WRD 0x4004;
#define RT2_TX_MODE_MSG_INFO  0x1aba; 
#define RT2_TX_MODE_TT        0x1abc; 
#define RT2_TX_MODE_DATAWRD   0x1abe; 

/*extern unsigned short RT1_descr_table[512];
extern unsigned short RT1_illegal_table[512];
extern unsigned short RT2_descr_table[512];
extern unsigned short RT2_illegal_table[512];
extern unsigned short smt_addr_list[128];
extern unsigned short smt_filter_table[128];
*/

 U16  BCMsgBlks; // Number of message blocks 
 U16  BCDataBlks;// Number of data blocks;
 U16  BCDataBlkStatus[128]; // 128 word boundry Circular buffer holds 5024 default words.
 U16  BCMsgBlkStatus[128];

#define SA1 1


U16 ReadBCDataBlocks(PLX_DEVICE_OBJECT *pDevice);
/* ----------------------------------------------------------------------------*/    
// Initialize RT descripter and illegal tables to default values
// TBD read file created by GUI based tools.

short BCInit(PLX_DEVICE_OBJECT *pDevice)
{   
		short i;

		BCMsgBlks = 0; // Reset Message Block Count
		for (i=0;i<128;i++)
            BCMsgBlkStatus[i] = 0;

		BCDataBlks = 0; // Reset data blobk count
		for (i=0;i<128;i++)
            BCDataBlkStatus[i] = 0;
		return i;
}

/* ----------------------------------------------------------------------------*/    
// Initialize RT descripter and illegal tables to default values
// TBD read file created by GUI based tools.


short RTInit(PLX_DEVICE_OBJECT *pDevice)
{   
		unsigned int addr;
		/*
		addr = (RT1_RX_DESCRIP_TABLE_BASE_ADDR);  

		WriteMemoryRange(pDevice, addr, &RT1_descr_table[0],512); 

		addr =  (RT1_ILLEGAL_TABLE_BASE_ADDR );  

		WriteMemoryRange(pDevice, addr, &RT1_illegal_table[0],256); 
*/
		return HOLT_SUCCESS;
}

/* ----------------------------------------------------------------------------*/
short RT2Init(PLX_DEVICE_OBJECT *pDevice)
{    
		unsigned int addr;

	/*	addr = (RT2_RX_DESCRIP_TABLE_BASE_ADDR);  

		WriteMemoryRange(pDevice, addr, &RT2_descr_table[0],512); 

		addr = (RT2_ILLEGAL_TABLE_BASE_ADDR);  

		WriteMemoryRange(pDevice, addr, &RT2_illegal_table[0],256); 
		*/
		return HOLT_SUCCESS;
}
/* ----------------------------------------------------------------------------*/
short SMTInit(PLX_DEVICE_OBJECT *pDevice)
{
		unsigned short retVal;
		unsigned int addr;

#if 0

		retVal = HoltSMT_IMTAddrListPointer(pDevice,SET_MASK,SMT_ADDRESSLIST_A);
		addr = (SMT_ADDRESSLIST_A);   // start  putting frames in Major block address

		// initialize MT address list using array declared  localy
		WriteMemoryRange(pDevice, addr, &smt_addr_list[0],8); 
            
		//  Iitialize filter table
		addr = (SMT_MESSAGE_FILTER_TABLE);   // start  putting frames in Major block address
		            
		// initialize MT address list using array declared at top of function 
		WriteMemoryRange(pDevice, addr, &smt_filter_table[0],128); 

		retVal = retVal;
#endif
		           
		return HOLT_SUCCESS;        
}
/* ----------------------------------------------------------------------------*/
void list_all_regs(PLX_DEVICE_OBJECT *pDevice)
{

		U16 retData,addr;
		U16 retVal;
		U16 DataBlock[10];

		//retVal = HoltReadRegister(  pDevice,MASTER_CONFIG_REG,&retData);
		/*printf("\n\rMASTER_CONFIG_REG = %4x\n\r",retData);
		printf("STATUS_AND_RESET_REG = %4x\n\r",ReadRegister(  pDevice, STATUS_AND_RESET_REG));
		printf("RT1_CURR_CMD_REG = %4x \n\r",ReadRegister(  pDevice, RT1_CURR_CMD_REG));
		printf("RT1_CURR_CTRL_WORD_ADDR_REG = %x \n\r",ReadRegister(  pDevice, RT1_CURR_CTRL_WORD_ADDR_REG));

		printf("RT2_CURR_CMD_REG = %x\n\r",ReadRegister(  pDevice, RT2_CURR_CMD_REG));
		printf("RT2_CURR_CTRL_WORD_ADDR_REG = %x\n\r",ReadRegister(  pDevice, RT2_CURR_CTRL_WORD_ADDR_REG));
		printf("HDW_PENDING_INT_REG = %x \n\r",ReadRegister(  pDevice, HDW_PENDING_INT_REG));
		printf("BC_PENDING_INT_REG = %x \n\r",ReadRegister(  pDevice, BC_PENDING_INT_REG));

		printf("MT_PENDING_INT_REG = %x \n\r",ReadRegister(  pDevice, SMT_IMT_PENDING_INT_REG));
		printf("RT_PENDING_INT_REG = %x \n\r",ReadRegister(  pDevice, RT1_RT2_PENDING_INT_REG));
		printf("INT_COUNT_AND_LOG_ADDR_REG = %x \n\r",ReadRegister(  pDevice, INT_COUNT_AND_LOG_ADDR_REG));
		printf("HDW_INT_ENABLE_REG = %x \n\r",ReadRegister(  pDevice, HDW_INT_ENABLE_REG));

		printf("BC_INT_ENABLE_REG = %x \n\r",ReadRegister(  pDevice, BC_INT_ENABLE_REG));
		printf("MT_INT_ENABLE_REG = %x \n\r",ReadRegister(  pDevice, SMT_IMT_INT_ENABLE_REG));
		printf("RT_INT_ENABLE_REG = %x \n\r",ReadRegister(  pDevice, RT1_RT2_INT_ENABLE_REG));
		printf("HDW_INT_OUTPUT_ENABLE_REG = %x \n\r",ReadRegister(  pDevice, HDW_INT_OUTPUT_ENABLE_REG));

		printf("BC_INT_OUTPUT_ENABLE_REG = %x \n\r",ReadRegister(  pDevice, BC_INT_OUTPUT_ENABLE_REG));
		printf("MT_INT_OUTPUT_ENABLE_REG = %x \n\r",ReadRegister(  pDevice, SMT_IMT_INT_OUTPUT_ENABLE_REG));
		printf("RT_INT_OUTPUT_ENABLE_REG = %x \n\r",ReadRegister(  pDevice, RT1_RT2_INT_OUTPUT_ENABLE_REG));
		printf("RT1_CONFIG_REG = %x \n\r",ReadRegister(  pDevice, RT1_CONFIG_REG));

		printf("RT1_OP_STATUS_REG = %x \n\r",ReadRegister(  pDevice, RT1_OP_STATUS_REG));
		printf("RT1_DESC_TBL_BASE_ADDR_REG = %x \n\r",ReadRegister(  pDevice, RT1_DESC_TBL_BASE_ADDR_REG));
		printf("RT1_1553_STATUS_BITS_REG = %x \n\r",ReadRegister(  pDevice, RT1_1553_STATUS_BITS_REG));
		printf("RT1_MSG_INFO_WD_ADDR_REG = %x \n\r",ReadRegister(  pDevice, RT1_MSG_INFO_WD_ADDR_REG));

		printf("RT1_BUSA_SELECT_REG = %x \n\r",ReadRegister(  pDevice, RT1_BUSA_SELECT_REG));
		printf("RT1_BUSB_SELECT_REG = %x \n\r",ReadRegister(  pDevice, RT1_BUSB_SELECT_REG));
		printf("RT1_BIT_WORD_REG = %x \n\r",ReadRegister(  pDevice, RT1_BIT_WORD_REG));
		printf("RT1_ALT_BIT_WORD_REG = %x \n\r",ReadRegister(  pDevice, RT1_ALT_BIT_WORD_REG));

		printf("RT2_CONFIG_REG = %x \n\r",ReadRegister(  pDevice, RT2_CONFIG_REG));
		printf("RT2_OP_STATUS_REG = %x \n\r",ReadRegister(  pDevice, RT2_OP_STATUS_REG));
		printf("RT2_DESC_TBL_BASE_ADDR_REG = %x \n\r",ReadRegister(  pDevice, RT2_DESC_TBL_BASE_ADDR_REG));
		printf("RT2_1553_STATUS_BITS_REG = %x \n\r",ReadRegister(  pDevice, RT2_1553_STATUS_BITS_REG));

		printf("RT2_MSG_INFO_WD_ADDR_REG = %x \n\r",ReadRegister(  pDevice, RT2_MSG_INFO_WD_ADDR_REG));
		printf("RT2_BUSA_SELECT_REG = %x \n\r",ReadRegister(  pDevice, RT2_BUSA_SELECT_REG));
		printf("RT2_BUSB_SELECT_REG = %x \n\r",ReadRegister(  pDevice, RT2_BUSB_SELECT_REG));
		printf("RT2_BIT_WORD_REG = %x \n\r",ReadRegister(  pDevice, RT2_BIT_WORD_REG));

		printf("RT2_ALT_BIT_WORD_REG = %x \n\r",ReadRegister(  pDevice, RT2_ALT_BIT_WORD_REG));
		printf("MT_CONFIG_REG = %x \n\r",ReadRegister(  pDevice, SMT_IMT_CONFIG_REG));
		printf("IMT_MAX_1553_MSGS = %x \n\r",ReadRegister(  pDevice, IMT_MAX_MSG_COUNT));

		printf("IMT_MAX_1553_WORDS = %x \n\r",ReadRegister(  pDevice, IMT_MAX_1553_WORDS));
		printf("IMT_MAX_PKT_TIME = %x \n\r",ReadRegister(  pDevice, IMT_MAX_PKT_TIME));
		printf("IMT_MAX_GAP_TIME = %x \n\r",ReadRegister(  pDevice, IMT_MAX_GAP_TIME));
		printf("IMT_CHANNEL_ID = %x \n\r",ReadRegister(  pDevice, IMT_CHANNEL_ID));

		printf("MT_ADDR_LIST_POINTER = %x \n\r",ReadRegister(  pDevice, SMT_IMT_START_ADDR_LIST_POINTER));
		printf("MT_NEXT_MSG_STACK_ADDR_REG = %x \n\r",ReadRegister(  pDevice, SMT_IMT_NEXT_MSG_STACK_ADDR_REG));
		printf("MT_LAST_MSG_STACK_ADDR_REG = %x \n\r",ReadRegister(  pDevice, SMT_IMT_LAST_MSG_STACK_ADDR_REG));
		printf("BC_CONFIG_REG = %x \n\r",ReadRegister(  pDevice, BC_CONFIG_REG));

		printf("BC_INST_LIST_BASE_ADDR_REG = %x \n\r",ReadRegister(  pDevice, BC_INST_LIST_BASE_ADDR_REG));
		printf("BC_INST_LIST_POINTER = %x \n\r",ReadRegister(  pDevice, BC_INST_LIST_POINTER));
		printf("BC_FRAME_TIME_LEFT_REG = %x \n\r",ReadRegister(  pDevice, BC_FRAME_TIME_REMAINING_REG));
		printf("BC_TIME_TO_NEXT_MSG_REG = %x \n\r",ReadRegister(  pDevice, BC_TIME_TO_NEXT_MSG_REG));

		printf("BC_CCODE_AND_GPF_REG = %x \n\r",ReadRegister(  pDevice, BC_CCODE_AND_GPF_REG));
		printf("BC_GP_QUEUE_POINTER = %x \n\r",ReadRegister(  pDevice, BC_GP_QUEUE_POINTER));
		printf("TTAG_CONFIG_REG = %x \n\r",ReadRegister(  pDevice, TTAG_CONFIG_REG));

		printf("MT_TTAG_COUNT_LOW = %x \n\r",ReadRegister(  pDevice, SMT_IMT_TTAG_COUNT_LOW));
		printf("MT_TTAG_COUNT_MID = %x \n\r",ReadRegister(  pDevice, SMT_IMT_TTAG_COUNT_MID));
		printf("MT_TTAG_COUNT_HIGH = %x \n\r",ReadRegister(  pDevice, SMT_IMT_TTAG_COUNT_HIGH));
		printf("MT_TTAG_UTILITY_REG_LOW = %x \n\r",ReadRegister(  pDevice, SMT_IMT_TTAG_UTILITY_REG_LOW));

		printf("MT_TTAG_UTILITY_REG_MID = %x \n\r",ReadRegister(  pDevice, SMT_IMT_TTAG_UTILITY_REG_MID));
		printf("MT_TTAG_MATCH_HIGH = %x \n\r",ReadRegister(  pDevice, SMT_IMT_TTAG_UTILITY_REG_HIGH));
		printf("MT_TTAG_MATCH_MID = %x \n\r",ReadRegister(  pDevice, SMT_IMT_TTAG_MATCH_LOW));
		printf("BC_TTAG_COUNT_LOW = %x \n\r",ReadRegister(  pDevice, BC_TTAG_COUNT_LOW));

		printf("BC_TTAG_COUNT_HIGH = %x \n\r",ReadRegister(  pDevice, BC_TTAG_COUNT_HIGH));
		printf("BC_TTAG_UTILITY_REG_LOW = %x \n\r",ReadRegister(  pDevice, BC_TTAG_UTILITY_REG_LOW));
		printf("BC_TTAG_UTILITY_REG_HIGH = %x \n\r",ReadRegister(  pDevice, BC_TTAG_UTILITY_REG_HIGH));
		printf("BC_TTAG_MATCH_LOW = %x \n\r",ReadRegister(  pDevice, BC_TTAG_MATCH_LOW));

		printf("BC_TTAG_MATCH_HIGH = %x \n\r",ReadRegister(  pDevice, BC_TTAG_MATCH_HIGH));
		printf("RT1_TTAG_COUNT = %x \n\r",ReadRegister(  pDevice, RT1_TTAG_COUNT));
		printf("RT1_TTAG_UTILITY_REG = %x \n\r",ReadRegister(  pDevice, RT1_TTAG_UTILITY_REG));
		printf("RT2_TTAG_COUNT = %x \n\r",ReadRegister(  pDevice, RT2_TTAG_COUNT));

		printf("RT2_TTAG_UTILITY_REG = %x \n\r",ReadRegister(  pDevice, RT2_TTAG_UTILITY_REG));
		printf("RT_CONFIG2_REG = %x \n\r",ReadRegister(  pDevice, EEPROM_UNLOCK_REG));
		printf("BC_LAST_MSG_BLOCK_ADDR_REG = %x \n\r",ReadRegister(  pDevice, BC_LAST_MSG_BLOCK_ADDR_REG));
		printf("BC_DEFAULT_WMI_REG = %x \n\r",ReadRegister(  pDevice, BC_DEFAULT_WMI_REG));
		*/
}

/* ----------------------------------------------------------------------------*/     
unsigned short 	MajorMinorframe(PLX_DEVICE_OBJECT *pDevice)
{
	unsigned short opCodeArray[12];					
	unsigned short retval, addr;
		U16 retVal;
		U16 DataBlock[10];

	// BC Major Minor frame demo
	unsigned short RxTxdata[32] = {0x0909,0x0909,0x0909,0x0909,0x0000,0x0000,0x0000,0x0000,
					0x0000,0x000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
					0x0000,0x000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,
					0x0000,0x000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000};
				   
	unsigned short TxRxdata[32] = {0xaaaa,0xaaaa,0xbbbb,0xbbbb,0xbbbb,0xbbbb,0xbbbb,0xbbbb,
					0x2525,0x2626,0x2727,0x2828,0x2929,0x3030,0x3131,0x3232,
					0x1717,0x1818,0x1919,0x2020,0x2121,0x2222,0x2323,0x2424,
					0x2525,0x2626,0x2727,0x2828,0x2929,0x3030,0x3131,0x3232};

	unsigned short R1[32] = {0x0001,0x0205,0x0303,0x0404,0x0505,0x0606,0x0707,0x0808,
					0x0909,0x1010,0x1111,0x1212,0x1313,0x1414,0x1515,0x1616,
					0x1717,0x1818,0x1919,0x2020,0x2121,0x2222,0x2323,0x2424,
					0x2525,0x2626,0x2727,0x2828,0x2929,0x3030,0x3131,0x3232};
								
	unsigned short R2[32] = {0xaaaa,0xaaaa,0xaaaa,0xaaaa,0xaaaa,0xaaaa,0xaaaa,0xaaaa,
					0x0909,0x1010,0x1111,0x1212,0x1313,0x1414,0x1515,0x1616,
					0x1717,0x1818,0x1919,0x2020,0x2121,0x2222,0x2323,0x2424,
					0x2525,0x2626,0x2727,0x2828,0x2929,0x3030,0x3131,0x3232};


	
	retval = BCInit(pDevice); // Initialize BCtables
	
	//retval = HoltBCStop(pDevice);
#if 0
	// Setup registers				
	retval =  HoltBCConfigurationRegister(pDevice, SET_MASK, BCTO_138U|BCGTE|ETTSYN|TTSYNEN|BCRME|BCRE);

	retval =  HoltBCInterruptEnableRegister(pDevice, SET_MASK ,BCWDT|SELMSG|BCGPQ|BCRETRY|CSTKERR|BCTRAP|STATSET|BCIRQMASK|BCMERR|BCEOM); 
	retval =  HoltBCInterruptOutputEnableRegister(pDevice, SET_MASK, BCWDT|SELMSG|BCGPQ|BCRETRY|CSTKERR|STATSET|BCIRQMASK|BCMERR|BCEOM );
	retval =  HoltBCInstListBaseAddrRegister(pDevice,SET_MASK,INST_LIST_ADDR);
    // Create data block				
	retval =  HoltBCDataBlkCreate(pDevice,BC_DBK0,32, &RxTxdata[0], DATA_LENGTH32 );// Create data block 1
	retval =  HoltBCDataBlkCreate(pDevice,BC_DBK1,32, &TxRxdata[0], DATA_LENGTH32 );// Create data block 2
	
	// Create  message block
	retval = HoltBCMsgCreateRTtoBC(pDevice, MSG_ID0, BC_DBK0, RT3, RTSUB1, 32, 40000, RTRYENA|MEMASK|USEBUSA);// create message block 1
	retval = HoltBCMsgCreateBCtoRT(pDevice, MSG_ID1, BC_DBK1, RT3, RTSUB1, 32, 40000, RTRYENA|MEMASK|USEBUSA);// create message block 2
	
	// Create instruction list for Minor frame 1	
	retval =  HoltBCOpCodeCreate(  pDevice, INST_OPCODE0, LFT, ALWAYS, 0x3700,  0,  0); // load frame counter for 400 micro seconds
	retval =  HoltBCOpCodeCreate(  pDevice, INST_OPCODE1, SFT, ALWAYS, 0,  0,  0); 		// Start minor frame timer				
	retval =  HoltBCOpCodeCreate(  pDevice, INST_OPCODE2, XEQ, ALWAYS, MSG_BLK_ADDR ,  2,  0);	// Execute message block	
	retval =  HoltBCOpCodeCreate(  pDevice, INST_OPCODE3, XEQ, ALWAYS, MSG_BLK_ADDR + (MSG_BLK_LEN*1),  2,  0);	// Execute message block	
	retval =  HoltBCOpCodeCreate(  pDevice, INST_OPCODE4, CAL, ALWAYS, INST_OPCODE11 ,	0,	0); // call subroutine

	// Create instruction list for Minor frame 2
	retval =  HoltBCOpCodeCreate(  pDevice, INST_OPCODE5, LFT, ALWAYS, 0x3700,  0,  0); // load frame counter for 400 micro seconds
	retval =  HoltBCOpCodeCreate(  pDevice, INST_OPCODE6, SFT, ALWAYS, 0,  0,  0);      // Start minor frame timer							
	retval =  HoltBCOpCodeCreate(  pDevice, INST_OPCODE7, XEQ, ALWAYS, MSG_BLK_ADDR+ (MSG_BLK_LEN*2),  4,  0); // Execute message block	
	retval =  HoltBCOpCodeCreate(  pDevice, INST_OPCODE8, XEQ, ALWAYS, MSG_BLK_ADDR+ (MSG_BLK_LEN*3),  4,  0); // Execute message block									
	retval =  HoltBCOpCodeCreate(  pDevice, INST_OPCODE9, CAL, ALWAYS, INST_OPCODE11,  0,  0); // call soubroutine
	retval =  HoltBCOpCodeCreate(  pDevice, INST_OPCODE10,JMP, ALWAYS, INST_LIST_ADDR,  0,  0 ); // JUMP to start of instruction list

    // subroutine at INST_OPCODE11 address
	retval =  HoltBCOpCodeCreate(  pDevice, INST_OPCODE11, WFT, ALWAYS, 0,  0,  0); // Wait for frame counter to count down
	retval =  HoltBCOpCodeCreate(  pDevice, INST_OPCODE12, RTN, ALWAYS, 0,  0,  0); // return to caller

	// Set start BC in configuration register
	retval =  HoltBCConfigurationRegister( pDevice,SET_MASK,BCENA | BCSTRT );
    
    // Start BC 
	HoltBCStart(pDevice,1,1);

    retval = retval;

	
#endif

	return HOLT_SUCCESS;
}

/* ----------------------------------------------------------------------------*/     
unsigned short 	AsyncMethod3(PLX_DEVICE_OBJECT *pDevice)
    // Hidden console commands
    // In consol window, menu 'f' or 'F' sets GP2 general purpose flag.
    // 					 menu 'i' or 'I' starts this demo
    // This demo sends Async messages based on the GP2 flags.
    // Menu selection 'f' of 'F' will send a message with "dead" pattern
{
	U16 opCodeArray[50];	

	unsigned short retval;

	return HOLT_SUCCESS;
}

/* ----------------------------------------------------------------------------*/	   
 unsigned short  RTDemo(PLX_DEVICE_OBJECT *pDevice)
 {
	  unsigned short dataBlkArray[4];
	  U32 LegalityStatus=0;

      unsigned short retval;

     /*unsigned short RxTxdata[34] = {0,0,0x0301,0x0202,0x0003,0x0004,0x0505,0x0606,0x0707,0x0808,
                      0x0909,0x1010,0x1111,0x1212,0x1313,0x1414,0x1515,0x1616,
                      0x1717,0x1818,0x1919,0x2020,0x2121,0x2222,0x2323,0x2424,
                      0x2525,0x2626,0x2727,0x2828,0x2929,0x3030,0x3131,0x3232};
                     
      unsigned short TxRxdata[34] = {0,0,0xbbbb,0x2202,0x3303,0x0404,0x0505,0x0606,0x0707,0x0808,
                      0x0909,0x1010,0x1111,0x1212,0x1313,0x1414,0x1515,0x1616,
                      0x1717,0x1818,0x1919,0x2020,0x2121,0x2222,0x2323,0x2424,
                      0x2525,0x2626,0x2727,0x2828,0x2929,0x3030,0x3131,0x3232};*/
      
      unsigned short RxTxdata[34] = {0,0,0x0909,0x1010,0x1111,0x1212,0x1313,0x1414,0x1515,0x1616,
                      0x0909,0x1010,0x1111,0x1212,0x1313,0x1414,0x1515,0x1616,
                      0x1717,0x1818,0x1919,0x2020,0x2121,0x2222,0x2323,0x2424,
                      0x2525,0x2626,0x2727,0x2828,0x2929,0x3030,0x3131,0x3232};
                     
      unsigned short TxRxdata[34] = {0,0,0x1717,0x1818,0x1919,0x2020,0x2121,0x2222,0x2323,0x2424,
                      0x0909,0x1010,0x1111,0x1212,0x1313,0x1414,0x1515,0x1616,
                      0x1717,0x1818,0x1919,0x2020,0x2121,0x2222,0x2323,0x2424,
                      0x2525,0x2626,0x2727,0x2828,0x2929,0x3030,0x3131,0x3232};
      unsigned short R1[34] = {0,0,0xccc0,0x4402,0x5503,0x0404,0x0505,0x0606,0x0707,0x0808,
	                  0x0909,0x1010,0x1111,0x1212,0x1313,0x1414,0x1515,0x1616,
	                  0x1717,0x1818,0x1919,0x2020,0x2121,0x2222,0x2323,0x2424,
	                  0x2525,0x2626,0x2727,0x2828,0x2929,0x3030,0x3131,0x3232};

      unsigned short R2[34] = {0,0,0xddd0,0x4402,0x5503,0x0404,0x0505,0x0606,0x0707,0x0808,
	                  0x0909,0x1010,0x1111,0x1212,0x1313,0x1414,0x1515,0x1616,
	                  0x1717,0x1818,0x1919,0x2020,0x2121,0x2222,0x2323,0x2424,
	                  0x2525,0x2626,0x2727,0x2828,0x2929,0x3030,0x3131,0x3232};



	  return HOLT_SUCCESS;
 }

/* ----------------------------------------------------------------------------*/	   
 unsigned short  RT2Demo(PLX_DEVICE_OBJECT *pDevice)
 {
	  unsigned short dataBlkArray[4];
      unsigned short retval;
	  U32 ligalityStatus=0;

      unsigned short RxTxdata[34] = {0,0,0x0401,0x2222,0x3333,0x4444,0x5555,0x6666,0x7777,0x8888,
                      0x9999,0x1010,0x1111,0x1212,0x1313,0x1414,0x1515,0x1616,
                      0x1717,0x1818,0x1919,0x2020,0x2121,0x2222,0x2323,0x2424,
                      0x2525,0x2626,0x2727,0x2828,0x2929,0x3030,0x3131,0x3232};
                     
      unsigned short TxRxdata[34] = {0,0,0xcccc,0x0202,0x0303,0x0404,0x0505,0x0606,0x0707,0x0808,
                      0x0909,0x1010,0x1111,0x1212,0x1313,0x1414,0x1515,0x1616,
                      0x1717,0x1818,0x1919,0x2020,0x2121,0x2222,0x2323,0x2424,
                      0x2525,0x2626,0x2727,0x2828,0x2929,0x3030,0x3131,0x3232};
      
      unsigned short R1[34] = {0,0,0xccc0,0x4402,0x5503,0x0404,0x0505,0x0606,0x0707,0x0808,
	                  0x0909,0x1010,0x1111,0x1212,0x1313,0x1414,0x1515,0x1616,
	                  0x1717,0x1818,0x1919,0x2020,0x2121,0x2222,0x2323,0x2424,
	                  0x2525,0x2626,0x2727,0x2828,0x2929,0x3030,0x3131,0x3232};

      unsigned short R2[34] = {0,0,0xddd0,0x4402,0x5503,0x0404,0x0505,0x0606,0x0707,0x0808,
	                  0x0909,0x1010,0x1111,0x1212,0x1313,0x1414,0x1515,0x1616,
	                  0x1717,0x1818,0x1919,0x2020,0x2121,0x2222,0x2323,0x2424,
	                  0x2525,0x2626,0x2727,0x2828,0x2929,0x3030,0x3131,0x3232};

	


	  return HOLT_SUCCESS;
 }
/* ----------------------------------------------------------------------------*/      
 unsigned short  SMTDemo(PLX_DEVICE_OBJECT *pDevice)
  {
    unsigned short retVal;
    unsigned short buffer[8];
  
    retVal = SMTInit(pDevice);

    buffer[0] = START_ADDR_LIST ;  // Start addrese of Address list combined stack
    buffer[1] = CUR_ADDR_LIST   ;  // Current addrese of Address list combined stack
    buffer[2] = END_ADDR_LIST   ;  // End  addrese of Address list combined stack
    buffer[3] = INT_ADDR        ;       // Interrupt address
    buffer[4] = START_DATA_STACK ;  // Start address of Data Stack
    buffer[5] = CUR_DATA_STACK   ;  // Current address of Data Stack
    buffer[6] = END_DATA_STACK   ;  // End address of Data Stack
    buffer[7] = INT_ADDR_BEFORE_END_STACK ;   // Interrupt address n words before end of stack
 
	// Fill SMT Address list

    
 	return HOLT_SUCCESS;
  }

/* ----------------------------------------------------------------------------*/      
unsigned short  IMTDemo(PLX_DEVICE_OBJECT *pDevice)
   {

    unsigned short retVal;

    unsigned short buffer[8];

    buffer[0] = START_ADDR_LIST ;  // Start addrese of Address list combined stack
    buffer[1] = CUR_ADDR_LIST   ;  // Current addrese of Address list combined stack
    buffer[2] = END_ADDR_LIST   ;  // End  addrese of Address list combined stack
    buffer[3] = INT_ADDR        ;  // Interrupt address
    buffer[4] = START_DATA_STACK ;  // Start address of Data Stack
    buffer[5] = CUR_DATA_STACK   ;  // Current address of Data Stack
    buffer[6] = END_DATA_STACK   ;  // End address of Data Stack
    buffer[7] = INT_ADDR_BEFORE_END_STACK ;   // Interrupt address n words before end of stack



  	return HOLT_SUCCESS;
   }

/* ----------------------------------------------------------------------------*/     
U16  ReadBCDataBlocks(PLX_DEVICE_OBJECT *pDevice) 
{

	U16 i=0,retval=0;
	U16 pBuffer[1024],uBufferSize=1024;
    U16 pMsgCount,pMsgLostHBuf;

	U16 Rxdata[32] = {1,2,3,4,5,6,7,8,9,10,0x1111,0x1212,0x1313,0x1414,0x1515,0x1616,
					0x1717,0x1818,0x1919,0x2020,0x2121,0x2222,0x2323,0x2424,
					0x2525,0x2626,0x2727,0x2828,0x2929,0x3030,0x3131,0x3232};
				   
	U16 Rxdata1[32] = {9,10,11,12,13,14,15,0x88,0x99,0x13,0x1111,0x1212,0x1313,0x1414,0x1515,0x1616,
					0x1717,0x1818,0x1919,0x2020,0x2121,0x2222,0x2323,0x2424,
					0x2525,0x2626,0x2727,0x2828,0x2929,0x3030,0x3131,0x3232};

#if 0
    retval = BCInit(pDevice); // Initialize BCtables
    retval = HoltBCInstallHBuf(pDevice,3);

	// Create data block				
	retval =  HoltBCDataBlkCreate(pDevice,BC_DBK0, DATA_LENGTH32,&Rxdata[0],DATA_LENGTH32 );// Create data block 1
	retval =  HoltBCDataBlkCreate(pDevice,BC_DBK1, DATA_LENGTH32,&Rxdata1[0],DATA_LENGTH32 );// Create data block 2

	/* Move data from host stack to host buffer */
	retval = HoltBCFrmToHBuf( pDevice );
 
	/* Read next 1024 words form Host buffer */
    retval = HoltBCGetHBufMsgsRaw( pDevice, &pBuffer[0], uBufferSize, &pMsgCount, &pMsgLostHBuf);

    /* print first 10 elements  elements */
    printf("\n\r");
	for (i=0; i< 10; i++)
	     printf("pBuffer %d = %d\n\r",i+1, pBuffer[i]);
#endif

    return retval;

}


