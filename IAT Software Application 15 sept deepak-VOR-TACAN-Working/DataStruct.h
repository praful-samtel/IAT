/************************************************************************************************
*		Project Name		:	Universal Tester																*
*		File Name			:	DataStruct.h												    *
*		Version of file		:	V1.00															*
*		Description 		:	This File includes the declarations of the following:-          *
*	*/	

#ifndef _DATASTRUCT_H
#define _DATASTRUCT_H

#include <afxmt.h>
#include <cstdint>
#include "SIPU_SDU_GndRig.h"
#include "Macros.h"
#include "bdaqctrl.h"
#include "ADT_L1.h"
#define WM_PROGRESS_UPDATE   (WM_USER + 300)
#define WM_PROGRESS_CLOSE    (WM_USER + 301)
using namespace Automation::BDaq;

#ifdef __cplusplus
extern "C" {
#endif

	struct PROGRESS_MSG
{
    int nPercent;
    CString strStatus;
};

//---------------------------------------------------------------------------------------
//***************************************************************************************
//***************************************************************************************
//***************************************************************************************
//***************************************************************************************
//***************************************************************************************
//***************************************************************************************
//---------------------S T R U C T U R E S   F O R   R E P O R T S-----------------------

//---------------------------------------------------------------------------------------
//***************************************************************************************
//***************************************************************************************
//***************************************************************************************
//***************************************************************************************
//***************************************************************************************
//***************************************************************************************
//---------------------------------------------------------------------------------------
struct GlobalReportPool{
	int MainThreadActiveFlag;
	int ApplicationRunFlag;
	BOOL SIPUConnected;
	BOOL SDUConnected;
	BOOL bFlag;
	BOOL SIPUNormalmode;
	BOOL SIPUCalibMode;
	BOOL SIPUMaintMode;
	BOOL SDUNormalMode;
	BOOL SDUSimulatMode;
	BOOL SDUMaintMode;

	CString				DynamicReportHeader;
};

//---------------------S T R U C T U R E S   F O R   R E P O R T S-----------------------

//Structure for maintaining the memory test report
struct S_MemoryTestRpt
{
	BYTE	m_ucDevType;
	BYTE	m_ucmemory_type;
	BYTE	m_ucAction;
	BYTE	m_uiData;
	WORD	m_uiAddress;
	BYTE	Result;
	char	Time[10];
	char	Date[12];
	WORD	MinorCycleNo;
	WORD	MajorCycleNo;
};

//---------------------------------------------------------------------------------------
typedef enum ThreadState{Running=10,Suspended,Stopped};

class AutoModeMainThreadState{
public:
	static	BOOL        bStop;
	WORD		usNoofMajorCycle;
	WORD		usNoofMinCycle;
	WORD		MajorCycleDelay;
	WORD		MinorCycleDelay;
 	ThreadState ThreadCurrentState;
	WORD		ProgressBarState;
	BOOL        FlashLodingThread;

	HANDLE		AutoModeModuleEvent;
	HANDLE      ENTESTMsgDisEvent;
	HANDLE		PBarEvent;
	HANDLE		AutoModeMainThreadHandle;
	HANDLE      M1553BTestEvent;
	BOOL		bStopping;

	HANDLE		GeneralEvent;

	WORD		ElapsedMjCount;
	WORD		ElapsedMinCount;

	WORD		CurrentModule;
	 
	AutoModeMainThreadState();
	~AutoModeMainThreadState();
};

#if 0 
typedef struct 
{
	char m_strEquipment[100];
	char m_strSerialNo[100];

	char m_strOperator[100];
	char m_strDateTime[50];

	char m_strExecMode[50];
	
	char m_strFileName[100];
	
	unsigned int m_uiMinor_Test_ID;
}sTest_Header;
#endif
typedef struct
{
    // COMMON REPORT DETAILS
    char m_strEquipment[100];
    char m_strSerialNo[100];

    char m_strOperator[100];
    char m_strDateTime[50];

    char m_strExecMode[50];       // STANDALONE / INTEGRATION

    char m_strFileName[260];

    // SYSTEM DETAILS
  
	// e.g. ISIS / VORILS / TACAN
	char m_strSmfdFc[100];
	char m_strSmfdRc[100];
	char m_strMfdFc[100];
	char m_strMfdRc[100];
	char m_strIsisDuFc[100];
	char m_strIsisDuRc[100];
	char m_strIsisAdu[100];
	char m_strIsisAhrs[100];
	char m_strIsisMms[100];
	char m_strAdc[100];
	char m_strAhrs[100];
	char m_strGps[100];
	char m_strVorrx[100];
	char m_strTacrx[100];
	char m_strCdu[100];
    // INTEGRATION SUPPORT
    char m_strIntegratedLRUs[500];    // Store all LRU names

    // TEST DETAILS
    char m_strTestDescription[200];

    unsigned int m_uiMinor_Test_ID;

} sTest_Header;


struct sSelfTest_Header
{
    char m_strOperator[64];
    char m_strDateTime[32];
    char m_strFileName[260];
};

struct sSelfTest_Item
{
    char m_strItemName[64];   // e.g. "PCI Card 1711 Self Test"
    char m_strResult[16];     // "OK" / "NOT OK"
};

typedef struct 
{
	char m_strMajorTestName[100];
	char m_strMinorTestName[100];

	char m_strSpec[100];
	char m_strMeasuered_Val[100];
	char m_strTestStatus[100];
	
	unsigned int m_uiMinor_Test_ID;
}sTest_Result;

typedef struct 
{
	char m_strTestNumber[100];
	char m_strReportFileName[150];
	unsigned char ucMFD_Make;  // 1-SMD, 2-CMFD
	int iTestMode; //0-complete, 1-partial
	int iMFDType; //0-SMD55, 1-SMD66
	float fStartTest;
	float fEndTest;
	char m_strDUSrNo[100];
}sStopTestLog;


/****************************************1711*************************************/
/*********************************************************************************/
//	void CheckError(ErrorCode errorCode);
	//void ConfigureDevice();
	//void ConfigurateDevice();
	//BOOL InitializePCI_Boards();
	//void ConfigurateDevice();

	void SwitchDiscrete(unsigned char ucDOType, BOOL bState);
	void SwitchDiscrete1758(unsigned char ucDOType, BOOL bState);
	BOOL ReadVorIlsTacanRX(ADT_L0_UINT32 ChannelNo);
	void InitDiscrete1758();
	BOOL DisableAllLRUPowerDiscretes();
	BYTE ReadPort(int iPortNum);
	//void ConfigureADC(unsigned char ucChannelNo);
	//void ReadADC(unsigned char ucChannelNo);
	void ResetAll();
	void ReadRXData(void);
	void ReadSpecificData(int32 portStart, int32 portCount, uint8 data[]);
	double ReadPowerSupplyValue(char chType);
	void On28Power(CString strComPort);
	void Off28Power(CString strComPort);
	//void CPulseOutputwithTimerInterruptDlg();
	//void Opreate28VDCPowerSupply();

	//int m_portNum0;
	
#if 0

typedef struct tagDevConfParam
{
	int deviceNumber;
}DevConfParam1, *pDevConfParam;

typedef struct tagConfigParam{
	int			deviceNumber;					 
	int			channelCount;				
	int			channelStart;			
	int			vrgType;	
}DevConfParam;

typedef struct tagDevConfiParam
{
   int  deviceNumber;
   long channel;
	int  moduleIndex ;
}DevConfParam2, *PDevConfParam;

extern TCHAR const * WCHAR_TO_TCHAR(WCHAR const * in, TCHAR * out);
extern WCHAR const * TCHAR_TO_WCHAR(TCHAR const * in,  WCHAR* out);


extern DevConfParam1         m_confParam1;
extern DevConfParam         m_confParamADC;
extern DevConfParam2		m_Comf;	
#endif


extern BOOL g_bADCThreadRunning;
extern BOOL g_bADCStopThread;
	
	
	

/****************************************************************************************/
void ReadBackCmdBytes(int iByteCount);
BOOL SendIOBoardCMD(unsigned char ucCMD_ID, unsigned char ucSubCMD_ID, unsigned char ucNoofBytes, unsigned char ucByte1, unsigned char ucByte2);
BOOL ReceiveIOBoardResponse(unsigned char* ucTestStatus);
BOOL InitializeARINC429();
BOOL InitArincRX(ADT_L0_UINT32 ChannelNo);
BOOL ReadRX(ADT_L0_UINT32 ChannelNo);
BOOL ReadSMFDRX(ADT_L0_UINT32 ChannelNo);
BOOL ReadADCRX(ADT_L0_UINT32 ChannelNo);
BOOL GetARINCValue(UINT ChannelNo,UINT Label,float* pValue);
BOOL  CloseARINC429();
BYTE ComputeCheckSum();
void FlushPCSerialPort(CString strComPort);
BOOL InitializeSerialPort(CString strComPort);
BOOL CloseRx(ADT_L0_UINT32 ChannelNo);
typedef struct
{
    BOOL  bValid;
    UINT  uiLabel;
    float fValue;
} ARINC_RX_DATA;

extern ARINC_RX_DATA g_ARINCRxData[16][512];
//BOOL InitializeSerialPort(CString strComPort);
extern sTest_Header s_Index_Page;
extern sStopTestLog s_StopTestObj;
static int32_t GetAdcSignedBnr19(const ADC_BNR19_PACKET& packet);
static int32_t GetAdcBnr19Value(const ADC_BNR19_PACKET& packet);
static float GetAhrsBnrValue(const ADC_BNR19_PACKET& packet, float resolution);
void UpdateDlgCtrl(unsigned char ucPortNum, BYTE BPortVal);

void DecodeArincData(unsigned int buff[4],unsigned int *plabel,float *pdata);
void DecodeAdcArincData(unsigned int buff[4],unsigned int *plabel,float *pdata);
void DecodeSmfdArincData(unsigned int buff[4],unsigned int *plabel,float *pdata);
void DecodeVorIlsTacanArincData(unsigned int buff[4],unsigned int *plabel,float *pdata);
int GetDecimal(unsigned char ucData);
float readArincData (unsigned char buffArincReadData[4]);

void DecodeArincData1(unsigned char buff[4],unsigned char *plabel,float *pdata);
//int GetDecimal(unsigned char ucData);
float readArincData1 (unsigned char buffArincReadData[4]);


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////ISIS///////////////////////////////////////////////////////////////////////

void ATITestComd (int param1);

 


#ifdef __cplusplus
}
#endif
#endif
