/*************************************************************************************
*		Project Name	:	BEL ISIS													 * 							       
	                       
*		Version of file	:	V1.00													 *			                       
*						 *
*************************************************************************************/

#include <afxmt.h>
#include "stdafx.h"
#include "string.h"
#include <cstdint> 
#include "SIPU_SDU_GndRig.h"
#include "Macros.h"
#include "DataStruct.h"
#include "Schedule.h"
#include "WndSlider.h"
#include "MainFrm.h"
#include "CaptionListView.h"
#include "SIPU_AMStruct.h"
#include "driver.h"
#include "SerialPort.h"
#include <bitset>
#include <string>
#include <iostream>
#include <sstream>
#include "ADT_L1.h"
#include "Arinc429.h"

#define DEVID (ADT_PRODUCT_PCIA429 | ADT_DEVID_BOARDNUM_01 | ADT_DEVID_CHANNELTYPE_A429 | ADT_DEVID_BANK_01)
static BOOL g_bARINC_Initialized = FALSE;
using namespace std;

ARINC_RX_DATA g_ARINCRxData[16][512];
extern CSerialPort gCommPort1,gCommPort2,gCommPort12;

#if 1
extern long m_lPCI1711DriverHandle;
extern LRESULT     m_lrErrCode;
extern PT_AIConfig     m_ptAIConfig;     // structure for AIConfig table
extern PT_AIVoltageIn  m_ptAIVoltageIn;  // structure for AIVoltageIn table
extern DEVFEATURES     m_DevFeatures;    // structure for device features
extern float       g_fVoltage;
 int m_portCountMax1758;
InstantDoCtrl *      m_instantDoCtrl;
InstantAiCtrl *     m_instantAiCtrl;
DevConfParam         m_confParam;
InstantDiCtrl *      m_instantDiCtrl;
extern TimerPulseCtrl*      m_timerPulseCtrl;
int m_portNum0 = 0;
byte * portsValue;
BYTE byDioReadData ;
BYTE byDioReadData1 ;
byte* m_portData;
int m_portCount;
int m_ports[8][12];
int m_imageList[2]; 
int newBitValue = 0;
int oldBitValue = 0;
bool RXData_Read;
#endif
unsigned char m_byDoPortData[16];
BOOL g_bADCThreadRunning = FALSE;
BOOL g_bADCStopThread = FALSE;
//InstantDoCtrl *      m_instantDoCtrl;

//int m_portNum0 = 0;
//byte * portsValue;
//BYTE byDioReadData ;

typedef struct
{
	unsigned char port;   // 0..15  (PCI-1758 has 16 DO ports)
	unsigned char bit;    // 0..7
} DIO_CHANNEL_MAP;

#ifdef _UNICODE 
#define _T(des) L##des
#define TEXT(des) L##des
#else 
 #define _T(des) des
 #define TEXT(des) des
#endif
InstantDoCtrl* m_instantDoCtrl1758 = AdxInstantDoCtrlCreate();
BufferedAiCtrl* bfdAiCtrl = AdxBufferedAiCtrlCreate();
BufferedAiCtrl * bufAiCtrl = AdxBufferedAiCtrlCreate();


void CheckError(ErrorCode errorCode)
{
   if (errorCode != Success)
   {
      CString str;
      str.Format(_T("Some errors happened, the error code is: 0x%X !\n"),errorCode);
      AfxMessageBox(str);
      
   }
}

DevConfParam GetParameter()
{
   DevConfParam param;
   param.deviceNumber = 1;//(int)m_comboBox_Device.GetItemData(m_comboBox_Device.GetCurSel());
   param.channelCount = 8;//m_comboBox_ChannelCount.GetCurSel() + 1;
   param.channelStart = 0;//m_comboBox_ChannelStart.GetCurSel();
   param.vrgType = 3;//(int)m_comboBox_ValueRange.GetItemData(m_comboBox_ValueRange.GetCurSel());
   return param;
}


void SwitchDiscrete(unsigned char ucDOType, BOOL bState)
{
	m_instantDoCtrl = AdxInstantDoCtrlCreate();
	m_portNum0 = 0;
	m_confParam.deviceNumber =PCI1711_1;
	 DeviceInformation devInfo(m_confParam.deviceNumber);
   ErrorCode errorCode1 = m_instantDoCtrl->setSelectedDevice(devInfo);
   CheckError(errorCode1);
   m_instantDoCtrl->getSelectedDevice(devInfo);
   
	
	char        m_szErrMsg[80];               // Use for MESSAGEBOX function
	#if 1
	unsigned char ucIndex0 = 0;
	
	// Read the current port status
	switch (ucDOType)
	{
	case ADC_ON:
    case  AHRS_ON:
	case VOR_ON:
    case  TACAN_ON:
	case GPS_FC_ON:
    case  GPS_RC_ON:
	case ISIS_DU_FC_ON:
    case  ISIS_DU_RC_ON:
		m_portNum0 = PORT_A0;
		break;
	case SMFD_FC_ON:
    case  SMFD_RC_ON:
	case MFD_FC_ON:
    case  MFD_RC_ON:
	
		m_portNum0 = PORT_A1;
		break;
	
	}

	// read the current discrete status
		int portCountMax = m_instantDoCtrl->getFeatures()->getPortCount();
	 portsValue = new byte[portCountMax];
	ErrorCode errorCode = m_instantDoCtrl->Read(m_portNum0, portCountMax, portsValue);


    CheckError(errorCode);



	switch (ucDOType)
	{
	case ADC_ON:
		
		if (bState)
		{
			byDioReadData = (byte)(byDioReadData | (1 << 0));

		}
		else
		{
			
			byDioReadData = (byte)byDioReadData & ~(1 << 0);
		}
		break;
	

	case AHRS_ON:
	
		if (bState)
		{
			byDioReadData = (byte)(byDioReadData | (1 << 1));

		}
		else
		{
			
			byDioReadData = (byte)byDioReadData & ~(1 << 1);
		}
		break;


	case VOR_ON:
	
		if (bState)
		{
			byDioReadData = (byte)(byDioReadData | (1 << 2));

		}
		else
		{
			byDioReadData = (byte)(byDioReadData & ~(1 << 2));
			
		}
		break;


	case TACAN_ON:
		if (bState)
		{
			byDioReadData = (byte)(byDioReadData | (1 << 3));

		}
		else
		{
			byDioReadData = (byte)(byDioReadData & ~(1 << 3)) ;
		}
		break;
				
	case  GPS_FC_ON:	
	
		if (bState)
		{
			byDioReadData = (byte)(byDioReadData | (1 << 4));

		}
		else
		{
			
			byDioReadData = (byte)byDioReadData & ~(1 << 4);
		}
		break;
	case GPS_RC_ON:	
	
		if (bState)
		{
			byDioReadData = (byte)(byDioReadData | (1 << 5));

		}
		else
		{
			
			byDioReadData = (byte)byDioReadData & ~(1 << 5);
		}
		break;
	case ISIS_DU_FC_ON:	
	
		if (bState)
		{
			byDioReadData = (byte)(byDioReadData | (1 << 6));

		}
		else
		{
			
			byDioReadData = (byte)byDioReadData & ~(1 << 6);
		}
		break;
	case ISIS_DU_RC_ON:
		
		if (bState)
		{
			byDioReadData = (byte)(byDioReadData | (1 << 7));

		}
		else
		{
			
			byDioReadData = (byte)byDioReadData & ~(1 << 7);
		}
		break;
	
		
	case SMFD_FC_ON:
	
		if (bState)
		{
			byDioReadData1 = (byte)(byDioReadData1 | (1 << 0));

		}
		else
		{
			
			byDioReadData1 = (byte)byDioReadData1 & ~(1 << 0);
		}
		break;

	case SMFD_RC_ON:
		if (bState)
		{
			byDioReadData1 = (byte)(byDioReadData1 | (1 << 1));

		}
		else
		{
			
			byDioReadData1 = (byte)(byDioReadData1 & ~(1 << 1));
		}
		break;



	case MFD_FC_ON:
		if (bState)
		{
			byDioReadData1 = (byte)(byDioReadData1 | (1 << 2));

		}
		else
		{
			byDioReadData1 = (byte)(byDioReadData1 & ~(1 << 2)) ;
		}
		break;
				
	case  MFD_RC_ON:	
	if (bState)
		{
			byDioReadData1 = (byte)(byDioReadData1 | (1 << 3));

		}
		else
		{
			byDioReadData1 = (byte)(byDioReadData1 & ~(1 << 3));
		}
		break;
		/*
	case DNS_CH4:	
	if (bState)
		{
			byDioReadData1 = (byte)(byDioReadData1 | (1 << 5));

		}
		else
		{
			byDioReadData1 = (byte)byDioReadData1 & ~(1 << 5);
		}
		break;
	case FC_RC_CH4:	
	if (bState)
		{
			byDioReadData1 = (byte)(byDioReadData1 | (1 << 7));

		}
		else
		{
			byDioReadData1 = (byte)byDioReadData1 & ~(1 << 7);
		}
		break;
		*/
	}

	//Write Do ports
	if(m_portNum0 == 0){
	ErrorCode errorCode2 = m_instantDoCtrl->Write(m_portNum0, byDioReadData);
	CheckError(errorCode2);}
	else{
	ErrorCode errorCode3 = m_instantDoCtrl->Write(m_portNum0, byDioReadData1);
	CheckError(errorCode3);}
	
	// read the current discrete status

	errorCode = m_instantDoCtrl->Read(m_portNum0, portCountMax, portsValue);
    CheckError(errorCode);
	
#endif
}

BOOL DisableAllLRUPowerDiscretes()
{
	InstantDoCtrl* pDoCtrl = AdxInstantDoCtrlCreate();
	if (pDoCtrl == NULL)
	{
		TRACE("[STOP] Unable to create the digital-output controller.\n");
		return FALSE;
	}

	DeviceInformation devInfo(PCI1711_1);
	if (pDoCtrl->setSelectedDevice(devInfo) != Success)
	{
		TRACE("[STOP] Unable to select the digital-output device.\n");
		return FALSE;
	}

	// Both digital-output ports carry the LRU power and discrete controls.
	ErrorCode portA0Result = pDoCtrl->Write(PORT_A0, (byte)0);
	ErrorCode portA1Result = pDoCtrl->Write(PORT_A1, (byte)0);

	byDioReadData = 0;
	byDioReadData1 = 0;

	if (portA0Result != Success || portA1Result != Success)
	{
		TRACE("[STOP] Failed to reset one or more LRU power/discrete ports. A0=0x%X A1=0x%X\n",
			portA0Result, portA1Result);
		return FALSE;
	}

	TRACE("[STOP] All LRU power and discrete outputs are OFF.\n");
	return TRUE;
}

BYTE ReadPort(int iPortNum)
{

	m_instantDoCtrl = AdxInstantDoCtrlCreate();
	m_portNum0 = iPortNum;

	m_confParam.deviceNumber =PCI1711_1;
   DeviceInformation devInfo(m_confParam.deviceNumber);
   ErrorCode errorCode1 = m_instantDoCtrl->setSelectedDevice(devInfo);
   CheckError(errorCode1);
   m_instantDoCtrl->getSelectedDevice(devInfo);

   // read the current discrete status
   int portCountMax = m_instantDoCtrl->getFeatures()->getPortCount();
	  portsValue = new byte[portCountMax];
	ErrorCode errorCode = m_instantDoCtrl->Read(m_portNum0, portCountMax, portsValue);

   CheckError(errorCode);
	
	//return *portsValue;
	return *portsValue;


}

void ResetAll()
{
	int iGetStatePortCount = 1;
	BYTE byDioReadData;
	char        m_szErrMsg[80];               // Use for MESSAGEBOX function
	LRESULT     m_lrErrCode;                     // Return error code
	//unsigned char ucIndex0 = 0;
	
	byDioReadData = 0;
//#ifdef HARDWARE		
	//Write Do ports
	/*m_lrErrCode = AdxDioWriteDoPorts( m_lPCI1711DriverHandle, PORT_A0, iGetStatePortCount, byDioReadData);
	if ( m_lrErrCode != SUCCESS)
	{   
		DRV_GetErrorMessage( m_lrErrCode, m_szErrMsg );
		//MessageBox(m_szErrMsg, "Driver Error", MB_OK);
		AfxMessageBox("DO Switch ON Error");
	}
	
	// read the current discrete status
	m_lrErrCode = AdxDioGetCurrentDoPortsState( m_lPCI1711DriverHandle, PORT_A0, iGetStatePortCount, byDioReadData);
	if (m_lrErrCode != SUCCESS)
	{
		DRV_GetErrorMessage(m_lrErrCode, m_szErrMsg);*/
		//MessageBox(m_szErrMsg, "Driver Error", MB_OK);
		AfxMessageBox("DO status read back Error");
		return;
	//}

//#endif

}



#if 1
BOOL InitializeSerialPort(CString strComPort)
{
	BOOL bTrsFlag;
	unsigned char ucLBackCmd;
	if (strComPort.Compare("com1") == 0)
	{
		// perform test bench self test
		if (!gCommPort1.OpenPort(strComPort))
		{
			AfxMessageBox("Unable to open Serial Port");
			return FALSE;
			
		}
		TRACE("Com 1 init success");
		//	return PORT_NOTOPEN;
		//if (!gCommPort1.ConfigurePort(9600, 8, FALSE, 1, 0))
     if (!gCommPort1.ConfigurePort(115200, 8, FALSE, 0, 0))
		{
			AfxMessageBox("Unable to open Serial Port");
			return FALSE;
			
		}
		//return PORTNOTCONFIGURED;
		
		if (!gCommPort1.SetCommunicationTimeouts(100, 1000, 0,0,0))
		{
			AfxMessageBox("Unable to open Serial Port");
			return FALSE;
			
		}
		//return PORTOPENFAIL;
//		FlushPCSerialPort();
	}
	else
	{
	}

	if (strComPort.Compare("com2") == 0)
	{
		// perform test bench self test
		if (!gCommPort2.OpenPort(strComPort))
		{
			AfxMessageBox("Unable to open Serial Port");
			return FALSE;
			
		}
		TRACE("Com 2 init success");
		//	return PORT_NOTOPEN;
		//if (!gCommPort1.ConfigurePort(9600, 8, FALSE, 1, 0))
     if (!gCommPort2.ConfigurePort(115200, 8, FALSE, 0, 0))
		{
			AfxMessageBox("Unable to open Serial Port");
			return FALSE;
			
		}
		//return PORTNOTCONFIGURED;
		
		if (!gCommPort2.SetCommunicationTimeouts(100, 1000, 0,0,0))
		{
			AfxMessageBox("Unable to open Serial Port");
			return FALSE;
			
		}
		//return PORTOPENFAIL;
//		FlushPCSerialPort();
	}
	else
	{
	}

	if (strComPort.Compare("com12") == 0)
	{
		if (!gCommPort12.OpenPort(strComPort))
		{
			//AfxMessageBox("Unable to open Serial Port");
		}
		//	return PORT_NOTOPEN;
		
		
		/*if (!gCommPort5.ConfigurePort(9600, FALSE, 8, FALSE, 1))
		{
			//AfxMessageBox("Unable to open Serial Port");
		}*/
		
		
			if (!gCommPort12.ConfigurePort(9600, 8, FALSE, 0, 0))
			{
				//AfxMessageBox("Unable to open Serial Port");
			}
		

		//return PORTNOTCONFIGURED;
		
		if (!gCommPort12.SetCommunicationTimeouts(100, 1000, 0,0,0))
		{
			//AfxMessageBox("Unable to open Serial Port");
		}
		//	return PORTOPENFAIL;
	}

	return TRUE;
}


void FlushPCSerialPort()
{
	BOOL bTrsFlag = true;
	unsigned char ucReadData1;
	
	while(bTrsFlag)
	{
		bTrsFlag = gCommPort1.ReadByte(ucReadData1);
	}
	while(bTrsFlag)
	{
		bTrsFlag = gCommPort2.ReadByte(ucReadData1);
	}
}
#endif


BOOL CloseRx(ADT_L0_UINT32 ChannelNo)
{
	 ADT_L0_UINT32 status;
	 status = ADT_L1_A429_RX_Channel_Close(DEVID, ChannelNo);
    if (status != ADT_SUCCESS)
        return FALSE;

	return TRUE;
}


BOOL CloseARINC429()
{
    ADT_L0_UINT32 status;

    TRACE("\n========== Closing ARINC429 ==========\n");

    status = ADT_L1_CloseDevice(DEVID);

    if(status != ADT_SUCCESS)
    {
        TRACE("ADT_L1_CloseDevice FAILED : 0x%08X\n", status);
        g_bARINC_Initialized = FALSE;
        gArinc429.ResetChannelState();
        return FALSE;
    }

    g_bARINC_Initialized = FALSE;
    gArinc429.ResetChannelState();
    TRACE("ADT_L1_CloseDevice SUCCESS\n");

    return TRUE;
}

BOOL ReadRX(ADT_L0_UINT32 ChannelNo)
{
    ADT_L0_UINT32 status;
    ADT_L0_UINT32 numRXPs;
    ADT_L1_A429_RXP myRXP_buffer[100];

    UINT label;
    float value;

    status = ADT_L1_A429_RX_Channel_ReadNewRxPs(
                    DEVID,
                    ChannelNo,
                    1,
                    &numRXPs,
                    myRXP_buffer);

    if(status != ADT_SUCCESS)
    {
        TRACE("ReadRX(Channel %u) FAILED : 0x%08X\n",
              ChannelNo,
              status);

        return FALSE;
    }

    if(numRXPs == 0)
    {
        TRACE("ReadRX(Channel %u) : No Labels Received\n",
              ChannelNo);

        return FALSE;
    }

    TRACE("ReadRX(Channel %u) : %u Labels Received\n",
          ChannelNo,
          numRXPs);

    for(UINT i=0;i<numRXPs;i++)
    {
        DecodeArincData(
            (unsigned int*)&myRXP_buffer[i].Data,
            &label,
            &value);

        g_ARINCRxData[ChannelNo][label].bValid = TRUE;
        g_ARINCRxData[ChannelNo][label].uiLabel = label;
        g_ARINCRxData[ChannelNo][label].fValue = value;

        TRACE("CH:%u  LABEL:%03o (%u)  VALUE:%f  RAW:0x%08X\n",
              ChannelNo,
              label,
              label,
              value,
              myRXP_buffer[i].Data);
    }

    return TRUE;
}


BOOL ReadSMFDRX(ADT_L0_UINT32 ChannelNo)
{
    ADT_L0_UINT32 status;
    ADT_L0_UINT32 numRXPs;
    ADT_L1_A429_RXP myRXP_buffer[100];

    UINT label;
    float value;

    status = ADT_L1_A429_RX_Channel_ReadNewRxPs(
                    DEVID,
                    ChannelNo,
                    1,
                    &numRXPs,
                    myRXP_buffer);

    if(status != ADT_SUCCESS)
    {
        TRACE("ReadRX(Channel %u) FAILED : 0x%08X\n",
              ChannelNo,
              status);

        return FALSE;
    }

    if(numRXPs == 0)
    {
        TRACE("ReadRX(Channel %u) : No Labels Received\n",
              ChannelNo);

        return FALSE;
    }

    TRACE("ReadRX(Channel %u) : %u Labels Received\n",
          ChannelNo,
          numRXPs);

    for(UINT i=0;i<numRXPs;i++)
    {
        DecodeSmfdArincData(
            (unsigned int*)&myRXP_buffer[i].Data,
            &label,
            &value);

        g_ARINCRxData[ChannelNo][label].bValid = TRUE;
        g_ARINCRxData[ChannelNo][label].uiLabel = label;
        g_ARINCRxData[ChannelNo][label].fValue = value;

        TRACE("CH:%u  LABEL:%03o (%u)  VALUE:%f  RAW:0x%08X\n",
              ChannelNo,
              label,
              label,
              value,
              myRXP_buffer[i].Data);
    }

    return TRUE;
}

BOOL ReadADCRX(ADT_L0_UINT32 ChannelNo)
{
    ADT_L0_UINT32 status;
    ADT_L0_UINT32 numRXPs;
    ADT_L1_A429_RXP myRXP_buffer[100];

    UINT label;
    float value;

    status = ADT_L1_A429_RX_Channel_ReadNewRxPs(
                    DEVID,
                    ChannelNo,
                    1,
                    &numRXPs,
                    myRXP_buffer);

    if(status != ADT_SUCCESS)
    {
        TRACE("ReadRX(Channel %u) FAILED : 0x%08X\n",
              ChannelNo,
              status);

        return FALSE;
    }

    if(numRXPs == 0)
    {
        TRACE("ReadRX(Channel %u) : No Labels Received\n",
              ChannelNo);

        return FALSE;
    }

    TRACE("ReadRX(Channel %u) : %u Labels Received\n",
          ChannelNo,
          numRXPs);

    for(UINT i=0;i<numRXPs;i++)
    {
        DecodeAdcArincData(
            (unsigned int*)&myRXP_buffer[i].Data,
            &label,
            &value);

        g_ARINCRxData[ChannelNo][label].bValid = TRUE;
        g_ARINCRxData[ChannelNo][label].uiLabel = label;
        g_ARINCRxData[ChannelNo][label].fValue = value;

        TRACE("CH:%u  LABEL:%03o (%u)  VALUE:%f  RAW:0x%08X\n",
              ChannelNo,
              label,
              label,
              value,
              myRXP_buffer[i].Data);
    }

    return TRUE;
}

BOOL GetARINCValue(UINT ChannelNo,
                   UINT Label,
                   float* pValue)
{
    if(ChannelNo >= 16)
    {
        TRACE("GetARINCValue() Invalid Channel %u\n",
              ChannelNo);

        return FALSE;
    }

    if(!g_ARINCRxData[ChannelNo][Label].bValid)
    {
        TRACE("Channel %u Label %03o Not Available\n",
              ChannelNo,
              Label);

        return FALSE;
    }

    *pValue = g_ARINCRxData[ChannelNo][Label].fValue;

    TRACE("Channel %u Label %03o = %f\n",
          ChannelNo,
          Label,
          *pValue);

    return TRUE;
}

BOOL InitializeARINC429()
{
    if(g_bARINC_Initialized)
    {
        TRACE("ARINC429 Already Initialized\n");
        return TRUE;
    }

    ADT_L0_UINT32 status;

    TRACE("\n========== Initializing ARINC429 ==========\n");

    status = ADT_L1_A429_InitDefault_ExtendedOptions(
                    DEVID,
                    100,
                    ADT_L1_API_DEVICEINIT_FORCEINIT |
                    ADT_L1_API_DEVICEINIT_NOMEMTEST);

    if(status != ADT_SUCCESS)
    {
        TRACE("ARINC429 Initialization FAILED : 0x%08X\n", status);
        return FALSE;
    }

    TRACE("ARINC429 Initialization SUCCESS\n");

    g_bARINC_Initialized = TRUE;

    return TRUE;
}

BOOL InitArincRX(ADT_L0_UINT32 ChannelNo)
{
    ADT_L0_UINT32 status;

    // The Stop path closes the ARINC device. Reopen it before a later RX test.
    if(!InitializeARINC429())
        return FALSE;

    TRACE("\nInitializing RX Channel %u\n", ChannelNo);

    status = ADT_L1_A429_RX_Channel_Init(
                    DEVID,
                    ChannelNo,
                    100000,
                    100,
                    0);

    if(status != ADT_SUCCESS)
    {
        TRACE("RX Channel %u Init FAILED : 0x%08X\n",
              ChannelNo,
              status);

        return FALSE;
    }

    TRACE("RX Channel %u Init SUCCESS\n", ChannelNo);

    status = ADT_L1_A429_RX_Channel_Start(
                    DEVID,
                    ChannelNo);

    if(status != ADT_SUCCESS)
    {
        TRACE("RX Channel %u Start FAILED : 0x%08X\n",
              ChannelNo,
              status);

        return FALSE;
    }

    TRACE("RX Channel %u Started\n", ChannelNo);

    return TRUE;
}



void DecodeArincData(unsigned int buff[4],unsigned int *plabel,float *pdata)
{
    ARINC_PACKET packet;
    short int digitaldata;
	CString strData;

	 //UpdateData(true);
		
	memcpy(&packet, buff, sizeof(ARINC_PACKET) );
	
//#if 1
   *plabel = packet.label ;
    switch ((*plabel))
    {
        case LABEL_324:     /* pitch angle decoding */
        PITCH_ANGLE_PACKET pitchPacket;
        memcpy(&pitchPacket, buff, sizeof(PITCH_ANGLE_PACKET) );
        digitaldata = pitchPacket.data;
        *pdata = digitaldata * RESOLUTION_324;
		//strPichVal.Format("%f",*pdata);
		//strPichVal.Format(strData);
		break;
        
#if PITCH_ROLL
        case LABEL_325:     /* roll angle decoding */
        ROLL_ANGLE_PACKET rollPacket;
        memcpy(&rollPacket, buff, sizeof(ROLL_ANGLE_PACKET) );
        digitaldata = rollPacket.data;
        *pdata = digitaldata * RESOLUTION_325;
		//strPichVal.Format("%f",*pdata);    // Adarsh : commentd it
		//strPichVal.Format(strData);
		break;
        
        case LABEL_246:     /* static pressure decoding */
        STATIC_PRESSURE_PACKET staticPressurePacket;
        memcpy(&staticPressurePacket, buff, sizeof(STATIC_PRESSURE_PACKET) );
        digitaldata = staticPressurePacket.data;
        *pdata = digitaldata * RESOLUTION_246;
		//strData.Format("Label   %o  ---Pich Angel  %f",label,dataArinc11);
		//M_listCtrl.AddString(strData);
		break;
        
        case LABEL_203:     /* Non Baro Corrected Altitude decoding */
        NBC_ALTITUDE_PACKET nbcAltitudePacket;
        memcpy(&nbcAltitudePacket, buff, sizeof(NBC_ALTITUDE_PACKET) );
        digitaldata = nbcAltitudePacket.data;
        *pdata = digitaldata * RESOLUTION_203;
		//strData.Format("Label   %o  ---Pich Angel  %f",label,dataArinc11);
		//M_listCtrl.AddString(strData);
		break;
        
        case LABEL_204:     /* Baro Corrected Altitude decoding */
        BC_ALTITUDE_PACKET bcAltitudePacket;
        memcpy(&bcAltitudePacket, buff, sizeof(BC_ALTITUDE_PACKET) );
        digitaldata = bcAltitudePacket.data;
        *pdata = digitaldata * RESOLUTION_204;
		break;
        
        case LABEL_205:     /* Mach decoding */
        MACH_PACKET machPacket;
        memcpy(&machPacket, buff, sizeof(MACH_PACKET) );
        digitaldata = machPacket.data;
        *pdata = digitaldata * RESOLUTION_205;
		break;
        
        case LABEL_206:     /* Indicated Air Speed decoding */
        IAIR_SPEED_PACKET iairSpeedPacket;
        memcpy(&iairSpeedPacket, buff, sizeof(IAIR_SPEED_PACKET) );
        digitaldata = iairSpeedPacket.data;
        *pdata = digitaldata * RESOLUTION_206;
		break;
        
        case LABEL_320:     /* Heading decoding */
        HEADING_PACKET headingPacket;
        memcpy(&headingPacket, buff, sizeof(HEADING_PACKET) );
        digitaldata = headingPacket.data;
        *pdata = digitaldata * RESOLUTION_320;
		break;
#endif
		//return(*pdata);
         //UpdateData(false);
        
    }
//#endif  

}



static int32_t GetAdcBnr19Value(const ADC_BNR19_PACKET& packet)
{
    // For negative 2's-complement values, bit 29 is the sign bit.
    return packet.sign
        ? static_cast<int32_t>(packet.data) - 0x40000
        : static_cast<int32_t>(packet.data);
}

void DecodeAdcArincData(unsigned int buff[4],
                        unsigned int* plabel,
                        float* pdata)
{
    ADC_BNR19_PACKET packet;
    memcpy(&packet, buff, sizeof(packet));

	TRACE("*plabel = 0x%02X (%u)",(unsigned int)*plabel, (unsigned int)*plabel);
   TRACE("MACRO : Label_203=%d LABEL_205=%d, LABEL_206=%d, LABEL_212=%d, LABEL_210=%d, LABEL_213=%d\n",LABEL_203,LABEL_205,LABEL_206,LABEL_212,LABEL_210,LABEL_213); 
    *plabel = packet.label;

    // ADC ICD: SSM = 11 means valid data.
    if (packet.SSM != 0x03)  //&& packet.SSM != 0x02
        return;

    const int32_t digitalData = GetAdcBnr19Value(packet);

    switch (*plabel)
    {
    case LABEL_203:
        *pdata = digitalData * ADC_RESOLUTION_203;
        break;

    case LABEL_204:
        *pdata = digitalData * ADC_RESOLUTION_204;
        break;

    case LABEL_205:
        *pdata = digitalData * ADC_RESOLUTION_205;
        break;

    case LABEL_206:
        *pdata = digitalData * ADC_RESOLUTION_206;
        break;
	case LABEL_212:     // Altitude Rate
		*pdata = digitalData * ADC_RESOLUTION_212;
		break;
	case LABEL_210:     // Altitude Rate
		*pdata = digitalData * ADC_RESOLUTION_210;
	break;
	case LABEL_213:     // Altitude Rate
		*pdata = digitalData * ADC_RESOLUTION_213;
		TRACE("pdata 213 VALUE:%f",*pdata);
		break;

    default:
			
        break;
    }
}


static float GetAhrsBnrValue(const ADC_BNR19_PACKET& packet, float resolution)
{
    // AHRS ICD (4030-6282) shows an explicit SIGN bit (bit 29, "0=POS")
    // separate from the 18-bit DATA magnitude field (bits 11-28) --
    // this is sign+magnitude, unlike the two's-complement transform
    // GetAdcBnr19Value() uses for the ADC path. Kept as a separate
    // helper so the two decode paths can't interfere with each other.
    float magnitude = (float)packet.data * resolution;
    return packet.sign ? -magnitude : magnitude;
}

void DecodeSmfdArincData(unsigned int buff[4],
                        unsigned int* plabel,
                        float* pdata)
{
    ADC_BNR19_PACKET packet;
    memcpy(&packet, buff, sizeof(packet));

    *plabel = packet.label;

    // AHRS ICD: SSM = 11 (3 decimal) = Normal / valid data.
    if (packet.SSM != 0x03)
        return;

    switch (*plabel)
    {
    case LABEL_320:   // AHRS Heading
        *pdata = GetAhrsBnrValue(packet, AHRS_RESOLUTION_320);
        break;

    case LABEL_324:   // AHRS Pitch
        *pdata = GetAhrsBnrValue(packet, AHRS_RESOLUTION_324);
        break;

    case LABEL_325:   // AHRS Roll
        *pdata = GetAhrsBnrValue(packet, AHRS_RESOLUTION_325);
        break;

    case LABEL_326:   // AHRS Pitch Rate
        *pdata = GetAhrsBnrValue(packet, AHRS_RESOLUTION_326);
        break;

    case LABEL_330:   // AHRS Yaw / Yaw Rate
        *pdata = GetAhrsBnrValue(packet, AHRS_RESOLUTION_330);
        break;

    case LABEL_332:   // AHRS Lateral Acceleration
        *pdata = GetAhrsBnrValue(packet, AHRS_RESOLUTION_332);
        break;

    case LABEL_333:   // AHRS Normal Acceleration
        *pdata = GetAhrsBnrValue(packet, AHRS_RESOLUTION_333);
        break;

    default:
        break;
    }
}


	
void DecodeVorIlsTacanArincData(unsigned int buff[4],
                                unsigned int* plabel,
                                float* pdata)
{
    ARINC_PACKET headerPeek;
    memcpy(&headerPeek, buff, sizeof(headerPeek));
    *plabel = headerPeek.label;

    switch (*plabel)
    {
    case LABEL_034:   // VOR/ILS Frequency -- report the ils_tuned flag (bit 14) as the value
    {
        unsigned int rawWord = buff[0];
        unsigned int ssm = (rawWord >> 29) & 0x3;
        if (ssm != 0x03) return;               // Normal only
        unsigned int ilsTuned = (rawWord >> 13) & 0x1;   // ARINC bit 14
        *pdata = (float)ilsTuned;               // 0 = VOR-tuned, 1 = ILS-tuned
        break;
    }

    case LABEL_222:   // VOR Bearing or TACAN Bearing -- same encoding
    {
        VOR_TACAN_BEARING_PACKET packet;
        memcpy(&packet, buff, sizeof(packet));
        if (packet.SSM != 0x03) return;
        float magnitude = (float)packet.data * VORILS_RESOLUTION_222;
        *pdata = packet.sign ? -magnitude : magnitude;
        break;
    }

    case LABEL_173:   // ILS Localizer Deviation
    {
        ILS_DEVIATION_PACKET packet;
        memcpy(&packet, buff, sizeof(packet));
        if (packet.SSM != 0x03) return;
        float magnitude = (float)packet.data * VORILS_RESOLUTION_173;
        *pdata = packet.sign ? -magnitude : magnitude;
        break;
    }

    case LABEL_174:   // ILS Glideslope Deviation
    {
        ILS_DEVIATION_PACKET packet;
        memcpy(&packet, buff, sizeof(packet));
        if (packet.SSM != 0x03) return;
        float magnitude = (float)packet.data * VORILS_RESOLUTION_174;
        *pdata = packet.sign ? -magnitude : magnitude;
        break;
    }

    case LABEL_201:   // TACAN Distance (BCD)
    {
        TACAN_DISTANCE_PACKET packet;
        memcpy(&packet, buff, sizeof(packet));
        if (packet.SSM != 0x03) return;
        *pdata = packet.hundreds * 100.0f + packet.tens * 10.0f + packet.ones
               + packet.tenths * 0.1f + packet.hundredths * 0.01f;
        break;
    }

    default:
        break;
    }
}

void UpdateDlgCtrl(unsigned char ucPortNum, BYTE BPortVal)
{
//	UpdateData(true);

	

#if 1
switch (ucPortNum)
	{
	case PORT_A0:
		 
		if (BPortVal>>0 & 1)
		{
			
		}
		else
		{
			
		}
		
		/*if (BPortVal>>1 & 1)
		{
			GetDlgItem(IDC_CHK_BEZ) ->SetWindowText("28VDC ADU ON");
			m_chkBez = TRUE;
			
		}
		else
		{
			GetDlgItem(IDC_CHK_BEZ) ->SetWindowText("28VDC ADU OFF");
			m_chkBez = FALSE;
			
		}*/

		if (BPortVal>>1 & 1)
		{
			//GetDlgItem(IDC_CHK_RPC) ->SetWindowText("Night Discrete");
			//m_chkRPC = TRUE;
		}
		else
		{
			
			//GetDlgItem(IDC_CHK_RPC) ->SetWindowText("Day Discrete");
			//m_chkRPC = FALSE;
		}

		if (BPortVal>>7 & 1)
		{
			
			//GetDlgItem(IDC_CHK_MODE_SELECT) ->SetWindowText("RC Discrete");
			//m_chkModeSelect = TRUE;
			
		}
		else
		{
			
			//GetDlgItem(IDC_CHK_MODE_SELECT) ->SetWindowText("FC Discrete");
			//m_chkModeSelect = FALSE;	
		}
		break;
	case PORT_A1:
	
		/*if (BPortVal>>3 & 1)
		{
			
			GetDlgItem(IDC_CHK_MODE_SELECT) ->SetWindowText("FC Discrete");
			m_chkModeSelect = TRUE;
			
		}
		else
		{
			
			GetDlgItem(IDC_CHK_MODE_SELECT) ->SetWindowText("RC Discrete");
			m_chkModeSelect = FALSE;	
		}*/

		if (BPortVal>>3 & 1)
		{
			//GetDlgItem(IDC_CHK_AUTO_MANUAL) ->SetWindowText("Maintenance Mode");
			//m_chkAutoManual = TRUE;
		}
		else
		{
			//GetDlgItem(IDC_CHK_AUTO_MANUAL) ->SetWindowText("Operational Mode");
			//m_chkAutoManual = FALSE;
		}
		break;
	}
#endif 

		

	//UpdateData(false);
}


int GetDecimal(unsigned char ucData)
{
	int iRet=0;
	switch(ucData)
	{
	case '1':
		iRet = 1;
		break;
	case '2':
		iRet = 2;
		break;
	case '3':
		iRet = 3;
		break;
	case '4':
		iRet = 4;
		break;
	case '5':
		iRet = 5;
		break;
	case '6':
		iRet = 6;
		break;
	case '7':
		iRet = 7;
		break;
	case '8':
		iRet = 8;
		break;
	case '9':
		iRet = 9;
		break;
	case 'A':
		iRet = 10;
		break;
	case 'B':
		iRet = 11;
		break;
	case 'C':
		iRet = 12;
		break;
	case 'D':
		iRet = 13;
		break;
	case 'E':
		iRet = 14;
		break;
	case 'F':
		iRet = 15;
		break;
	case 'a':
		iRet = 10;
		break;
	case 'b':
		iRet = 11;
		break;
	case 'c':
		iRet = 12;
		break;
	case 'd':
		iRet = 13;
		break;
	case 'e':
		iRet = 14;
		break;
	case 'f':
		iRet = 15;
		break;
	}
	return iRet;
}

float readArincData(unsigned char buffArincReadData[4])
{
    static float ret = 400.0f;
    unsigned int label, dataArinc[4];
    float dataArinc11;
	string strmsg;
    ADT_L0_UINT32 numRXPs, status;
    ADT_L1_A429_RXP myRXP_buffer[20];
	CString strDebug;
    
    if (!g_bARINC_Initialized)
    {
        if (!InitializeARINC429())
            return ret;
    }
    
    status = ADT_L1_A429_RX_Channel_ReadNewRxPs(DEVID, 8, 1, &numRXPs, myRXP_buffer);
    
    if (status != ADT_SUCCESS || numRXPs == 0)
        return ret;
    
    for (int i = 0; i < numRXPs; i++)
    {
        unsigned int arincWord = myRXP_buffer[i].Data;
        unsigned char labelExtracted = arincWord ;
		//strDebug.Format("label recieved %d",labelExtracted);
        //AfxMessageBox(strDebug);
		if (labelExtracted == LABEL_324)  // Label 324 (Pitch)
       {
            dataArinc[0] = arincWord;
            DecodeArincData(dataArinc, &label, &dataArinc11);
            ret = dataArinc11;
            break;
        }
    }
   
    return ret+10;
}


void DecodeArincData1(unsigned int buff[4],unsigned int *plabel,float *pdata)
{
    ARINC_PACKET packet;
    short int digitaldata;
	CString strData;

	 //UpdateData(true);
		
	memcpy(&packet, buff, sizeof(ARINC_PACKET) );
	
//#if 1
   *plabel = packet.label ;
    switch ((*plabel))
    {
         case LABEL_325:     /* roll angle decoding */
        ROLL_ANGLE_PACKET rollPacket;
        memcpy(&rollPacket, buff, sizeof(ROLL_ANGLE_PACKET) );
        digitaldata = rollPacket.data;
        *pdata = digitaldata * RESOLUTION_325;
		//strPichVal.Format("%f",*pdata);
		//strPichVal.Format(strData);
		break;
        
#if PITCH_ROLL

		/*
		case LABEL_325:     // roll angle decoding 
      ROLL_ANGLE_PACKET rollPacket;
     memcpy(&rollPacket, buff, sizeof(ROLL_ANGLE_PACKET) );
        digitaldata = rollPacket.data;
        *pdata = digitaldata * RESOLUTION_325;
		//strPichVal.Format("%f",*pdata);
		//strPichVal.Format(strData);
		break;*/
    
        case LABEL_246:     /* static pressure decoding */
        STATIC_PRESSURE_PACKET staticPressurePacket;
        memcpy(&staticPressurePacket, buff, sizeof(STATIC_PRESSURE_PACKET) );
        digitaldata = staticPressurePacket.data;
        *pdata = digitaldata * RESOLUTION_246;
		//strData.Format("Label   %o  ---Pich Angel  %f",label,dataArinc11);
		//M_listCtrl.AddString(strData);
		break;
        
        case LABEL_203:     /* Non Baro Corrected Altitude decoding */
        NBC_ALTITUDE_PACKET nbcAltitudePacket;
        memcpy(&nbcAltitudePacket, buff, sizeof(NBC_ALTITUDE_PACKET) );
        digitaldata = nbcAltitudePacket.data;
        *pdata = digitaldata * RESOLUTION_203;
		//strData.Format("Label   %o  ---Pich Angel  %f",label,dataArinc11);
		//M_listCtrl.AddString(strData);
		break;
        
        case LABEL_204:     /* Baro Corrected Altitude decoding */
        BC_ALTITUDE_PACKET bcAltitudePacket;
        memcpy(&bcAltitudePacket, buff, sizeof(BC_ALTITUDE_PACKET) );
        digitaldata = bcAltitudePacket.data;
        *pdata = digitaldata * RESOLUTION_204;
		break;
        
        case LABEL_205:     /* Mach decoding */
        MACH_PACKET machPacket;
        memcpy(&machPacket, buff, sizeof(MACH_PACKET) );
        digitaldata = machPacket.data;
        *pdata = digitaldata * RESOLUTION_205;
		break;
        
        case LABEL_206:     /* Indicated Air Speed decoding */
        IAIR_SPEED_PACKET iairSpeedPacket;
        memcpy(&iairSpeedPacket, buff, sizeof(IAIR_SPEED_PACKET) );
        digitaldata = iairSpeedPacket.data;
        *pdata = digitaldata * RESOLUTION_206;
		break;
        
        case LABEL_320:     /* Heading decoding */
        HEADING_PACKET headingPacket;
        memcpy(&headingPacket, buff, sizeof(HEADING_PACKET) );
        digitaldata = headingPacket.data;
        *pdata = digitaldata * RESOLUTION_320;
		break;
#endif
		//return *pdata;
         //UpdateData(false);
        
    }
//#endif  

}


float readArincData1(unsigned char buffArincReadData[4])
{
    static float ret = -400.0f;
    unsigned int label, dataArinc[4];
    float dataArinc11;
    ADT_L0_UINT32 numRXPs, status;
    ADT_L1_A429_RXP myRXP_buffer[20];
    
    if (!g_bARINC_Initialized)
    {
        if (!InitializeARINC429())
            return ret;
    }
    
    status = ADT_L1_A429_RX_Channel_ReadNewRxPs(DEVID, 8, 1, &numRXPs, myRXP_buffer);
    
    if (status != ADT_SUCCESS || numRXPs == 0)
        return ret;
    
    for (int i = 0; i < numRXPs; i++)
    {
        unsigned int arincWord = myRXP_buffer[i].Data;
        unsigned char labelExtracted = arincWord & 0xFF;
        
		if (labelExtracted == LABEL_325)  // Label 325 (Roll)
        {
            dataArinc[0] = arincWord;
            DecodeArincData1(dataArinc, &label, &dataArinc11);
            ret = dataArinc11;
            break;
        }
    }
    
    return ret;
}


double ReadPowerSupplyValue(char chType)
{
    BOOL bTrsFlag;
    unsigned char ucReadData[10] = {0};
    unsigned char ucWriteData;
    int icountData = 0;
    CString strValue;
	
    // Send command
    ucWriteData = 'M';
    gCommPort12.WriteByte(ucWriteData);

    ucWriteData = chType;      // 'V' or 'C'
    gCommPort12.WriteByte(ucWriteData);

    ucWriteData = '?';
    gCommPort12.WriteByte(ucWriteData);

    ucWriteData = 0x0D;
    gCommPort12.WriteByte(ucWriteData);

    // Read response
    while(icountData < 7)
    {
        bTrsFlag = gCommPort12.ReadByte(ucReadData[icountData]);
        icountData++;
    }

    strValue.Format("%c%c%c%c%c%c",
        ucReadData[0],
        ucReadData[1],
        ucReadData[2],
        ucReadData[3],
        ucReadData[4],
        ucReadData[5]);

    return atof(strValue);
}

void On28Power(CString strComPort)  
{
	BOOL bTrsFlag;
	unsigned char ucWriteData, ucReadData[10]; 
	int icountData,iEVolt,iEFreq;
	
	CString str_float, str_int, strACSourceID,strDCresponse;
	//UpdateData(true);
	
	// com port initialization
	InitializeSerialPort(strComPort);
	//send 28V DC identification command 
	if(strComPort.Compare("com12")==0)
	{
	ucWriteData = 'A';
	bTrsFlag = gCommPort12.WriteByte (ucWriteData);
	
	ucWriteData = 'D';
	bTrsFlag = gCommPort12.WriteByte (ucWriteData);
		
	ucWriteData = 'R';
	bTrsFlag = gCommPort12.WriteByte (ucWriteData);
	
	ucWriteData = ' ';
	bTrsFlag = gCommPort12.WriteByte (ucWriteData);
	
	ucWriteData = '0';
	bTrsFlag = gCommPort12.WriteByte (ucWriteData);

	ucWriteData = '6';
	bTrsFlag = gCommPort12.WriteByte (ucWriteData);
	
	ucWriteData = 0x0D;
	bTrsFlag = gCommPort12.WriteByte (ucWriteData);
	
	bTrsFlag = true;
	icountData = 0;

	Sleep(100);

	ucWriteData = 'O';
	bTrsFlag = gCommPort12.WriteByte (ucWriteData);
	
	ucWriteData = 'U';
	bTrsFlag = gCommPort12.WriteByte (ucWriteData);
		
	ucWriteData = 'T';
	bTrsFlag = gCommPort12.WriteByte (ucWriteData);
	
	ucWriteData = ' ';
	bTrsFlag = gCommPort12.WriteByte (ucWriteData);
	
	ucWriteData = '1';
	bTrsFlag = gCommPort12.WriteByte (ucWriteData);

	ucWriteData = 0x0D;
	bTrsFlag = gCommPort12.WriteByte (ucWriteData);

	while(bTrsFlag)
	{
		bTrsFlag = gCommPort12.ReadByte(ucReadData[icountData]);
		icountData++;
	}

	strDCresponse.Format("%c%c",ucReadData[0],ucReadData[1]);

	if(strDCresponse.Compare("OK"))
	{
		//AfxMessageBox("TDK-Lambda 28V DC Power Supply Indentification failure!!");
		//AfxMessageBox("Application is now quiting");
		//exit(0);

	}
	else
	{
		
	}

	//send 28V DC set volt 28V command 
	ucWriteData = 'P';
	bTrsFlag = gCommPort12.WriteByte (ucWriteData);
	
	ucWriteData = 'V';
	bTrsFlag = gCommPort12.WriteByte (ucWriteData);
		
	ucWriteData = ' ';
	bTrsFlag = gCommPort12.WriteByte (ucWriteData);
	
	ucWriteData = '2';
	bTrsFlag = gCommPort12.WriteByte (ucWriteData);
	
	ucWriteData = '8';
	bTrsFlag = gCommPort12.WriteByte (ucWriteData);

	ucWriteData = 0x0D;
	bTrsFlag = gCommPort12.WriteByte (ucWriteData);

	bTrsFlag = true;
	icountData = 0;

	while(bTrsFlag)
	{
		bTrsFlag = gCommPort12.ReadByte(ucReadData[icountData]);
		icountData++;
	}
//Sleep(50000);
	}
}

void Off28Power(CString strComPort)
{
	BOOL bTrsFlag;
	unsigned char ucWriteData, ucReadData[10]; 
	int icountData,iEVolt,iEFreq;
	
	CString str_float, str_int, strACSourceID,strDCresponse;
	//UpdateData(true);
	icountData = 0;
	if(strComPort.Compare("com12")==0)
	{
	
	ucWriteData = 'O';
	bTrsFlag = gCommPort12.WriteByte (ucWriteData);
	 
	ucWriteData = 'U';
	bTrsFlag = gCommPort12.WriteByte (ucWriteData);
		
	ucWriteData = 'T';
	bTrsFlag = gCommPort12.WriteByte (ucWriteData);
	
	ucWriteData = ' ';
	bTrsFlag = gCommPort12.WriteByte (ucWriteData);
	
	ucWriteData = 'O';
	bTrsFlag = gCommPort12.WriteByte (ucWriteData);

	ucWriteData = 'F';
	bTrsFlag = gCommPort12.WriteByte (ucWriteData);

	ucWriteData = 'F';
	bTrsFlag = gCommPort12.WriteByte (ucWriteData);

	ucWriteData = 0x0D;
	bTrsFlag = gCommPort12.WriteByte (ucWriteData);

	while(bTrsFlag)
	{
		bTrsFlag = gCommPort12.ReadByte(ucReadData[icountData]);
		icountData++;
	}

	strDCresponse.Format("%c%c",ucReadData[0],ucReadData[1]);

	if(strDCresponse.Compare("OK"))
	{
		//AfxMessageBox("TDK-Lambda 28V DC Power Supply Indentification failure!!");
		//AfxMessageBox("Application is now quiting");
		//exit(0);

	}
	else
	{
		//GetDlgItem(IDC_CHK_28VDC) ->SetWindowText("28VDC OFF");
		//m_chk28VDC = FALSE;
	}

	gCommPort12.ClosePort();
	}
	
	//UpdateData(false);
}

void InitDiscrete1758()
{
	
      
	DeviceInformation devInfo(PCI1758_1);   // define PCI1758_1 like PCI1711_1
	ErrorCode errorCode = m_instantDoCtrl1758->setSelectedDevice(devInfo);
	CheckError(errorCode);
 
	// Optional: load a profile that sets all/selected ports to Output,
	// same idea as the LoadProfile()/portDirection sample you pasted.
	// ErrorCode errRet = m_instantDoCtrl1758->LoadProfile(filePath);
	// CheckError(errRet);
 
	m_portCountMax1758 = m_instantDoCtrl1758->getFeatures()->getPortCount();
 
	// Read current hardware state once, into the software cache
	memset(m_byDoPortData, 0, sizeof(m_byDoPortData));
	byte* portsValue = new byte[m_portCountMax1758];
	ErrorCode errRead = m_instantDoCtrl1758->Read(0, m_portCountMax1758, portsValue);
	CheckError(errRead);
 
	for (int i = 0; i < m_portCountMax1758 && i < 16; i++)
		m_byDoPortData[i] = portsValue[i];
 
	delete[] portsValue;
}

void SwitchDiscrete1758(unsigned char ucDOType, BOOL bState)
{
	char m_szErrMsg[80];   // kept for consistency with your CheckError() usage

	if (ucDOType >= PCI1758_TOTAL_CHANNELS)
	{
		// invalid channel index
		return;
	}

	unsigned char ucPort = DIO_PORT_OF(ucDOType);
	unsigned char ucBit  = DIO_BIT_OF(ucDOType);

	// modify only the affected bit in the cached byte for that port
	if (bState)
	{
		m_byDoPortData[ucPort] = (byte)(m_byDoPortData[ucPort] | (1 << ucBit));
		TRACE("Discrete on");
	}
	else
	{
		m_byDoPortData[ucPort] = (byte)(m_byDoPortData[ucPort] & ~(1 << ucBit));
			TRACE("Discrete OFF");
	}

	// write just that one port
	ErrorCode errorCodeWrite = m_instantDoCtrl1758->Write(ucPort, m_byDoPortData[ucPort]);
	CheckError(errorCodeWrite);

	// optional read-back to confirm/refresh cache
	byte byReadBack = 0;
	ErrorCode errorCodeRead = m_instantDoCtrl1758->Read(ucPort, 1, &byReadBack);
	CheckError(errorCodeRead);
	m_byDoPortData[ucPort] = byReadBack;
}

void CleanupDiscrete1758()
{
	if (m_instantDoCtrl1758)
	{
		m_instantDoCtrl1758->Dispose();
		m_instantDoCtrl1758 = NULL;
	}
}


BOOL ReadVorIlsTacanRX(ADT_L0_UINT32 ChannelNo)
{
    ADT_L0_UINT32 status;
    ADT_L0_UINT32 numRXPs;
    ADT_L1_A429_RXP myRXP_buffer[100];

    UINT label;
    float value;

    status = ADT_L1_A429_RX_Channel_ReadNewRxPs(
                    DEVID,
                    ChannelNo,
                    1,
                    &numRXPs,
                    myRXP_buffer);

    if(status != ADT_SUCCESS)
    {
        TRACE("ReadRX(Channel %u) FAILED : 0x%08X\n", ChannelNo, status);
        return FALSE;
    }

    if(numRXPs == 0)
    {
        TRACE("ReadRX(Channel %u) : No Labels Received\n", ChannelNo);
        return FALSE;
    }

    TRACE("ReadRX(Channel %u) : %u Labels Received\n", ChannelNo, numRXPs);

    for(UINT i=0;i<numRXPs;i++)
    {
        DecodeVorIlsTacanArincData(
            (unsigned int*)&myRXP_buffer[i].Data,
            &label,
            &value);

        g_ARINCRxData[ChannelNo][label].bValid = TRUE;
        g_ARINCRxData[ChannelNo][label].uiLabel = label;
        g_ARINCRxData[ChannelNo][label].fValue = value;

        TRACE("CH:%u  LABEL:%03o (%u)  VALUE:%f  RAW:0x%08X\n",
              ChannelNo, label, label, value, myRXP_buffer[i].Data);
    }

    return TRUE;
}