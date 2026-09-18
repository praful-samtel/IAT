/*****************************************************************************
File Name	: SerialCommunication.cpp
Description	: This file contains the RS232 functions

Reviewer	: 
Created on	: 16/08/07 
Completed on: 
******************************************************************************/
/*****************************************************************************
Revision No	: 
Revised by	:
Revision on	: 
Reason		:
******************************************************************************/

/* Header File Inclusion */
#include "stdafx.h"
#include "SerialPort.h"
#include "SerialCommunication.h"
#include "Macros.h"
#include "MainFrm.h"
#include "CaptionListView.h"

/* Serial Port Declration*/
//extern CSerialPort gCommPort1,gCommPort2,gCommPort3, gCommPort4;
CSerialPort gCommPort1,gCommPort2,gCommPort3, gCommPort4;


unsigned char IT_SIPU_SerialCommInit (CString in_csPort,							
			DWORD in_dwBaudrate, BYTE in_bByteSize, DWORD in_Parity, BYTE in_bParity, 
				BYTE in_bStopBits,	
			DWORD in_RdIntTO, DWORD in_RdTotTOMx, DWORD in_RdTotTOCons, 
				DWORD in_WtTotTOMx, DWORD in_WtTotTOCons)
{
	if (in_csPort.Compare("com1") == 0)
	{
		if (!gCommPort1.OpenPort(in_csPort))
			return PORT_NOTOPEN;

		if (!gCommPort1.ConfigurePort(in_dwBaudrate, in_bByteSize, in_Parity, in_bParity, in_bStopBits))
			return PORTNOTCONFIGURED;

		if (!gCommPort1.SetCommunicationTimeouts(in_RdIntTO, in_RdTotTOMx, in_RdTotTOCons, in_WtTotTOMx, in_WtTotTOCons))
			return PORTOPENFAIL;
	}
	if (in_csPort.Compare("com2") == 0)
	{
		if (!gCommPort2.OpenPort(in_csPort))
			return PORT_NOTOPEN;

		if (!gCommPort2.ConfigurePort(in_dwBaudrate, in_bByteSize, in_Parity, in_bParity, in_bStopBits))
			return PORTNOTCONFIGURED;

		if (!gCommPort2.SetCommunicationTimeouts(in_RdIntTO, in_RdTotTOMx, in_RdTotTOCons, in_WtTotTOMx, in_WtTotTOCons))
			return PORTOPENFAIL;
	}

	if (in_csPort.Compare("com3") == 0)
	{
		if (!gCommPort3.OpenPort(in_csPort))
			return PORT_NOTOPEN;

		if (!gCommPort3.ConfigurePort(in_dwBaudrate, in_bByteSize, in_Parity, in_bParity, in_bStopBits))
			return PORTNOTCONFIGURED;

		if (!gCommPort3.SetCommunicationTimeouts(in_RdIntTO, in_RdTotTOMx, in_RdTotTOCons, in_WtTotTOMx, in_WtTotTOCons))
			return PORTOPENFAIL;

		//gCommPort3.ClosePort();
	}

	/*if (in_csPort.Compare("com4") == 0)
	{
		if (!gCommPort4.OpenPort(in_csPort))
			return PORT_NOTOPEN;

		if (!gCommPort4.ConfigurePort(in_dwBaudrate, in_bByteSize, in_Parity, in_bParity, in_bStopBits))
			return PORTNOTCONFIGURED;

		if (!gCommPort4.SetCommunicationTimeouts(in_RdIntTO, in_RdTotTOMx, in_RdTotTOCons, in_WtTotTOMx, in_WtTotTOCons))
			return PORTOPENFAIL;
	}*/
	return 0;
}

unsigned char IT_SIPU_CloseSerialComm (void)
{
	gCommPort1.ClosePort();
	gCommPort2.ClosePort();
	gCommPort3.ClosePort();
	return 0;
}	

