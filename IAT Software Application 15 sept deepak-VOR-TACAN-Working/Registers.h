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
#ifdef __cplusplus
extern "C" {
#endif

#define  U32 unsigned long
#define  S32 long
#define  U16 unsigned short
#define  S16 short
#define  U8  unsigned char
#define  S8  char


#define	  MASTER_CONFIG_REG					0x0000
#define	  STATUS_AND_RESET_REG 				0x0001
#define	  RT1_CURR_CMD_REG 					0x0002
#define	  RT1_CURR_CTRL_WORD_ADDR_REG 		0x0003
#define	  RT2_CURR_CMD_REG 					0x0004
#define	  RT2_CURR_CTRL_WORD_ADDR_REG 		0x0005
#define	  HDW_PENDING_INT_REG 				0x0006
#define	  BC_PENDING_INT_REG 				0x0007
#define	  SMT_IMT_PENDING_INT_REG 			0x0008
#define	  RT1_RT2_PENDING_INT_REG 			0x0009
#define	  INT_COUNT_AND_LOG_ADDR_REG 		0x000a
#define	  MAP_1   							0x000b
#define	  MAP_2   				            0x000c
#define	  MAP_3  							0x000d
#define	  MAP_4  							0x000e
#define   HDW_INT_ENABLE_REG				0x000f
#define	  BC_INT_ENABLE_REG 				0x0010
#define	  SMT_IMT_INT_ENABLE_REG 			0x0011
#define	  RT1_RT2_INT_ENABLE_REG 			0x0012
#define	  HDW_INT_OUTPUT_ENABLE_REG 		0x0013
#define	  BC_INT_OUTPUT_ENABLE_REG 			0x0014
#define	  SMT_IMT_INT_OUTPUT_ENABLE_REG		0x0015
#define	  RT1_RT2_INT_OUTPUT_ENABLE_REG		0x0016
#define	  RT1_CONFIG_REG 					0x0017
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

#if 1
	/* ----------------------------------------------------------------------------*/
extern S16 HoltBCInterruptEnableRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* ----------------------------------------------------------------------------*/
extern S16 HoltBCConfigurationRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* ----------------------------------------------------------------------------*/
extern S16 HoltBCInterruptOutputEnableRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* ----------------------------------------------------------------------------*/
extern S16 HoltBCInstListBaseAddrRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* ----------------------------------------------------------------------------*/


S16 HoltMasterConfigurationRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* ----------------------------------------------------------------------------*/
S16 HoltMasterStatusandResetRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);


/* ----------------------------------------------------------------------------*/
S16 HoltHardwarePendingInterruptRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* ----------------------------------------------------------------------------*/
S16 HoltBCPendingInterruptRegister(PLX_DEVICE_OBJECT *pDevice, U16 uAction, U16 uMask);
/* ----------------------------------------------------------------------------*/
S16 HoltSMT_IMT_PendingInterruptRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* ----------------------------------------------------------------------------*/
S16 HoltRT1_RT2_PendingInterruptRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* ----------------------------------------------------------------------------*/
S16 HoltHardwareInterruptEnableRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* ----------------------------------------------------------------------------*/
S16 HoltIntrttuptCountandLogAddressRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);

/* ----------------------------------------------------------------------------*/
S16 HoltSMT_IMTInterruptEnableRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* ----------------------------------------------------------------------------*/
S16 HoltRT1_RT2_InterruptEnableRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* ----------------------------------------------------------------------------*/
S16 HoltHardwareInterruptOutputEnableRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* ----------------------------------------------------------------------------*/
S16 HoltRT1_RT2_InterruptOutputEnableRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);

/* ----------------------------------------------------------------------------*/
S16 HoltSMT_IMTInterruptOutputEnableRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* ----------------------------------------------------------------------------*/
/* RT2 Registers */
S16 HoltRT2ConfigureRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* ----------------------------------------------------------------------------*/
S16 HoltRT2OpStatusRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* ----------------------------------------------------------------------------*/
S16 HoltRT2DescTblBaseAddrRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* ----------------------------------------------------------------------------*/
S16 HoltRT2StatusBitRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* ----------------------------------------------------------------------------*/
S16 HoltRT2MsgInfoAddrRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* ----------------------------------------------------------------------------*/
S16 HoltRT2BusASelectRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* ----------------------------------------------------------------------------*/
S16 HoltRT2BusBSelectRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* ----------------------------------------------------------------------------*/
S16 HoltRT2BitWordRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* ----------------------------------------------------------------------------*/
/* RT1 Registers */
S16 HoltRT1ConfigureRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* ----------------------------------------------------------------------------*/
S16 HoltRT1OpStatusRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* ----------------------------------------------------------------------------*/
S16 HoltRT1DescTblBaseAddrRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* ----------------------------------------------------------------------------*/
S16 HoltRT1StatusBitRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* ----------------------------------------------------------------------------*/
S16 HoltRT1CurrentCommandRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* -------------------------------------------------------------/---------------*/
S16 HoltRT1MsgInfoAddrRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* ----------------------------------------------------------------------------*/
S16 HoltRT1BusASelectRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* ----------------------------------------------------------------------------*/
S16 HoltRT1BusBSelectRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* ----------------------------------------------------------------------------*/
S16 HoltRT1CurrentCntrlolWordAddressRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* ----------------------------------------------------------------------------*/
S16 HoltRT2CurrentCommandRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* -------------------------------------------------------------/---------------*/
S16 HoltRT2CurrentCntrlolWordAddressRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* ----------------------------------------------------------------------------*/
S16 HoltRT1AlternateBITWordRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
/* ----------------------------------------------------------------------------*/
S16 HoltRT2AlternateBITWordRegister(PLX_DEVICE_OBJECT *pDevice,U16 uAction, U16 uMask);
#endif
/* ---------------------------*/
 #ifdef __cplusplus
}
#endif