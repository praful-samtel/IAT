/*****************************************************************************
Revision No	: 
Revised by	:
Revision on	: 
Reason		:
******************************************************************************/

#ifndef __SERIALCOMUNICATIONh
#define __SERIALCOMUNICATIONh

#include <afxmt.h>

#include "SIPU_SDU_GndRig.h"
#include "Schedule.h"
#include "Macros.h"

/* Macro Definition */
#define PORT_NOTOPEN			11
#define PORTNOTCONFIGURED		12
#define PORTOPENFAIL			13
#define PKT_SEND_ERR			14
#define PKT_RCV_TIMEOUT_ERR		15


#define MAX_232_CHANNELS	3


/* Function Declrations */

/* Serial Port Initialization */
unsigned char IT_SIPU_SerialCommInit (CString in_csPort,							
			DWORD in_dwBaudrate, BYTE in_bByteSize, DWORD in_Parity, BYTE in_bParity, 
				BYTE in_bStopBits,	
			DWORD in_RdIntTO, DWORD in_RdTotTOMx, DWORD in_RdTotTOCons, 
				DWORD in_WtTotTOMx, DWORD in_WtTotTOCons);

/* Serial Port Close Function */
unsigned char IT_SIPU_CloseSerialComm (void);

/* RS232 Transmit Function */
unsigned char IT_SIPU_SendPacket(unsigned char in_ucData);

/* Rs232 Receive Function */
unsigned char IT_SIPU_ReceivePacket (unsigned char *Out_pucData);


#endif