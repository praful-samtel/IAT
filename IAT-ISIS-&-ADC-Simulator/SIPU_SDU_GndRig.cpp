/*************************************************************************************************
*	Project Name		:	ILT																	 *
*	File Name			:   SIPU_SDU_GndRig.cpp               									 *
*	Modified for ARINC 429 data acquisition instead of PCI cards                                *
**************************************************************************************************/

#include "stdafx.h"
#include "SIPU_SDU_GndRig.h"
#include "MainFrm.h"
#include "SIPU_SDU_GndRigDoc.h"
#include "SIPU_SDU_GndRigView.h"
#include "Splach.h"
#include "DataStruct.h"  // Contains ARINC 429 functions
#include "UserAuthendication.h"
#include "BenchSelfTest.h"
#include "SIPUPowerONPage.h"
#include "SerialPort.h"
#include "Macros.h"
#include <tchar.h>
#include "Globals.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

// KEEP: Serial port for power supply control
extern CSerialPort gCommPort12;

// REMOVED: PCI1711 driver handle - not needed for ARINC
// long m_lPCI1711DriverHandle=NULL;   

// ADDED: ARINC 429 initialization flag
extern BOOL g_bARINC_Initialized;

#ifndef UNICODE
TCHAR const * WCHAR_TO_TCHAR(WCHAR const * in, TCHAR * out)
{
   WideCharToMultiByte (CP_OEMCP,NULL,in,-1,out,MAX_DEVICE_DESC_LEN,NULL,FALSE);
   return out;
}
#else
TCHAR const * WCHAR_TO_TCHAR(WCHAR const * in, TCHAR * out)
{
   return in;
}
#endif

#ifndef UNICODE
WCHAR const * TCHAR_TO_WCHAR(TCHAR const * in,  WCHAR* out)
{
   MultiByteToWideChar(CP_ACP, 0, (LPCTSTR)in, -1, out, MAX_DEVICE_DESC_LEN);
   return out;
}
#else
WCHAR const * TCHAR_TO_WCHAR(TCHAR const * in,  WCHAR* out)
{
   return in;
}
#endif

LRESULT     m_lrErrCode;  

#define MANUAL_MODE_COLOR  RGB(0xbf,0xdf,0xfa) //brinjal
#define AUTO_MODE_COLOR	   RGB(0xaf,0xbf,0xbf)
#define SELF_TEST_COLOR	   RGB(0xbf,0xdf,0xfa) //brinjal
#define STATIC_CTRL_COLOR  RGB(0x00,0xff,0xd6)
unsigned long Data;

// REMOVED: Interrupt Thread Parameter - not needed for ARINC
// IntHandlerParam ThreadParam;
bool g_bThreadCreated=false;
HANDLE hAppSemId[2]; 

int g_Count=0,Sno=0;
int g_ECount = 0;

CString g_strAppVersion;
CString g_strCheckSum;
unsigned char g_ucTestType;
BOOL g_bMFDPowerONStatus = false;
BOOL g_bInitStartFlag = false;


/////////////////////////////////////////////////////////////////////////////
// CSIPU_SDU_GndRigApp
char g_cAdminstrator = 0;

BEGIN_MESSAGE_MAP(CSIPU_SDU_GndRigApp, CWinApp)
	//{{AFX_MSG_MAP(CSIPU_SDU_GndRigApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	// Standard print setup command
	ON_COMMAND(ID_FILE_PRINT_SETUP, CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSIPU_SDU_GndRigApp construction

CSIPU_SDU_GndRigApp::CSIPU_SDU_GndRigApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	ManualModeBrush.CreateSolidBrush(MANUAL_MODE_COLOR);
	AutoModeBrush.CreateSolidBrush(AUTO_MODE_COLOR);
	StaticBrush.CreateSolidBrush(STATIC_CTRL_COLOR);
	SelfTestBrush.CreateSolidBrush(SELF_TEST_COLOR);
	uc_ViewBackFlag=0;

	Viewfont.CreateFont(
	   17,                        // nHeight
	   0,                         // nWidth
	   0,                         // nEscapement
	   0,                         // nOrientation
	   FW_BOLD,		              // nWeight
	   TRUE,                     // bItalic
	   FALSE,                     // bUnderline
	   0,                         // cStrikeOut
	   ANSI_CHARSET,              // nCharSet
	   OUT_DEFAULT_PRECIS,        // nOutPrecision
	   CLIP_DEFAULT_PRECIS,       // nClipPrecision
	   DEFAULT_QUALITY,           // nQuality
	   DEFAULT_PITCH | FF_SWISS,  // nPitchAndFamily
	   "Verdana");        
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CSIPU_SDU_GndRigApp object

CSIPU_SDU_GndRigApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CSIPU_SDU_GndRigApp initialization

BOOL CSIPU_SDU_GndRigApp::InitInstance()
{
	// variable declaration
	unsigned char ucMaxPOST_Labels=0,ucChannelNo=0, ucBytecount;
	unsigned char arrucLabel[13]={0};
	
	CSplach splash_dlg;
	CUserAuthendication User_dlg; // user login screen display
	CBenchSelfTest objSelfTestDlg; // self test dialog
	
	BOOL bRetVal = false;
	unsigned char ucIOBRD_Status[MAX_BYTE_COUNT];

	CString in_csPort = "com1";

	CSIPU_SDU_GndRigApp *pMainFrame;
	pMainFrame = (CSIPU_SDU_GndRigApp *)AfxGetApp();
	
	// display application startup screen
	splash_dlg.DoModal();
	
	HCURSOR hCursor = LoadCursorFromFile("Handapst.ani");
	if(hCursor != NULL)
	{
		SetCursor(hCursor);
	}

	// MODIFIED: Initialize ARINC 429 instead of PCI cards

	if (!InitializeARINC429Hardware())
	{
		AfxMessageBox("Unable to Initialize ARINC 429 hardware!\nPlease check:\n1. ADT ARINC card is installed\n2. Drivers are properly installed\n3. Hardware connections are correct");
		
		// Ask if user wants to continue in simulation mode
		int result = MessageBox(NULL, "Do you want to continue ?", "ARINC 429 Init Failed", MB_YESNO | MB_ICONQUESTION);
		if (result != IDYES)
		{
			exit(0);
		}
		// Continue in simulation mode - readArincData will return default values
	}
	
#if 0
	// OPTIONAL: Initialize COM5 for power supply control
	if (!InitializePowerSupplyPort())
	{
		AfxMessageBox("Warning: Unable to initialize COM5 for power supply control\nPower control will not be available");
		// Continue without power control
	}
#endif

	//Commented for disabling login screen
	//User_dlg.DoModal();

	// if the option selected is ILT self test
	if (g_ucTestType == IAT_SELFTEST)
	{
		HCURSOR hCursor = LoadCursorFromFile("Handapst.ani");
		if(hCursor != NULL)
		{
			SetCursor(hCursor);
		}

		// ILT self test screen display
		objSelfTestDlg.DoModal();
		
		AfxMessageBox("The Application Software Will Exit, Please Run the EXE Again to Perform LRUs Testing");
		exit(0);
	}
	if(g_ucTestType == IAT_SIMULATION)
	{
	  g_bSimulationMode  = true;
	}

	hCursor = LoadCursorFromFile("Handapst.ani");
	if(hCursor != NULL)
	{
		SetCursor(hCursor);
	}

	AfxEnableControlContainer();

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	SetRegistryKey(_T("Local AppWizard-Generated Applications"));
	LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.
	CSingleDocTemplate* pDocTemplate;
	pDocTemplate = new CSingleDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CSIPU_SDU_GndRigDoc),
		RUNTIME_CLASS(CMainFrame),       // main SDI frame window
		RUNTIME_CLASS(CSIPUPowerONPage));
	AddDocTemplate(pDocTemplate);

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;

	// REMOVED: Thread creation for ARINC interrupt handling - not needed
	// ARINC 429 reading will be done via timer or on-demand

	// The one and only window has been initialized, so show and update it.
	m_pMainWnd->ShowWindow(SW_SHOWMAXIMIZED);
	m_pMainWnd->UpdateWindow();
	m_pMainWnd->SetWindowText("Integrated Avionics Tester Application");
	::SetPriorityClass(GetCurrentProcess(), HIGH_PRIORITY_CLASS); 

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	CString	m_strSTC_AppVer;
	CString	m_strSTC_Checksum;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	m_strSTC_AppVer = _T("");
	m_strSTC_Checksum = _T("");
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	DDX_Text(pDX, IDC_STATIC_APP_VERSION, m_strSTC_AppVer);
	DDX_Text(pDX, IDC_STATIC_APP_CHECKSUM, m_strSTC_Checksum);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CSIPU_SDU_GndRigApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	
	aboutDlg.m_strSTC_AppVer.Format("%s", g_strAppVersion);
	aboutDlg.m_strSTC_Checksum.Format("650d56", g_strCheckSum);

	aboutDlg.DoModal();
}

void CAboutDlg::OnOK() 
{
	CDialog::OnOK();
}

BOOL CSIPU_SDU_GndRigApp::OnIdle(LONG lCount) 
{
	return CWinApp::OnIdle(lCount);
}

// REMOVED: App_IntHandler thread function - not needed for ARINC 429

int CSIPU_SDU_GndRigApp::ExitInstance() 
{
	// REMOVED: Thread termination code
	OnTerminateTestSeq();
	// Close ARINC 429 if needed (handled in DataStruct.cpp)
	
	return CWinApp::ExitInstance();
}

void CSIPU_SDU_GndRigApp::OnTerminateTestSeq()
{
	int iMboxRet;
	// AfxMessageBox("OnTerminateTestSeq Called");
	// prompt to user for confirmation of stop operation
	/*iMboxRet = MessageBox(NULL, "Are you sure you want to Terminate Test Sequence Execution?","Test Stop",MB_YESNO | MB_ICONINFORMATION);
	
	if(iMboxRet!=IDYES)
	{
		m_bTestStopFlag = false;
		return;
	}*/
	
	// Switch off power supply if COM12 is available
	SwitchOFFPowerSupply();
	CloseARINC429();
		
	// set the stop flag
	m_bTestStopFlag = true;
}

// NEW: Initialize ARINC 429 Hardware
BOOL CSIPU_SDU_GndRigApp::InitializeARINC429Hardware()
{
	// Call the ARINC initialization function from DataStruct.cpp
	if (!InitializeARINC429())
	{
		return FALSE;
	}
	
	// Additional ARINC configuration if needed
	// For example, configure specific channels, labels, etc.
	
	return TRUE;
}

// NEW: Initialize Power Supply Port
BOOL CSIPU_SDU_GndRigApp::InitializePowerSupplyPort()
{
	// Open COM5 for power supply control
	if (!gCommPort12.OpenPort("com12"))
	{
		return FALSE;
	}
	
	// Configure COM5 (9600, 8, N, 1)
	if (!gCommPort12.ConfigurePort(9600, 8, FALSE, 0, 0))
	{
		gCommPort12.ClosePort();
		return FALSE;
	}
	
	// Set communication timeouts
	if (!gCommPort12.SetCommunicationTimeouts(100, 1000, 0, 0, 0))
	{
		gCommPort12.ClosePort();
		return FALSE;
	}
	
	return TRUE;
}

// REMOVED: InitializePCI_Board() - replaced with InitializeARINC429Hardware()
// REMOVED: ConfigureDevice() - not needed for ARINC 429
// REMOVED: CheckError() - not needed for ARINC 429

// KEEP: Power supply control function (unchanged)
void CSIPU_SDU_GndRigApp::SwitchOFFPowerSupply(void)
{
	BOOL bTrsFlag;
	BYTE ucWriteData;
	BYTE ucReadData;
	int icountData;
	CString strDCresponse;
	
	// Check if COM12 is open
	if (!gCommPort12.IsOpen())
	{
		if (!InitializePowerSupplyPort())
		{
			AfxMessageBox("Unable to open COM12 for power supply control");
			return;
		}
	}
	
	// Send ADR 06
	const char* cmd1 = "ADR 06\r";
	for (int i = 0; cmd1[i] != '\0'; i++)
	{
		ucWriteData = (BYTE)cmd1[i];
		gCommPort12.WriteByte(ucWriteData);
	}
	Sleep(100);
	
	// Send OUT 0 (OFF)
	const char* cmd2 = "OUT 0\r";
	for (int i = 0; cmd2[i] != '\0'; i++)
	{
		ucWriteData = (BYTE)cmd2[i];
		gCommPort12.WriteByte(ucWriteData);
	}
	Sleep(100);
	
	// Read response
	CString response;
	icountData = 0;
	while(gCommPort12.ReadByte(ucReadData) && icountData < 10)
	{
		response += (char)ucReadData;
		icountData++;
	}
	
	if(response.Find("OK") == -1)
	{
		//AfxMessageBox("TDK-Lambda 28V DC Power Supply OFF command failed!");
	}
}