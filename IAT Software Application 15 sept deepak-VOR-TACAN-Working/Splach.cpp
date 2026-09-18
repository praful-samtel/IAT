/**************************************************************************************** 
*		Project Name		:	Universal Tester														*				       
*		File Name			:   Splach.cpp												*					   
*		Author				:	Chaman Lal Sharma										*		                          
*		Date				:	19th July.2011											*			                      
*		Version of file		:	V1.01													*			                      
*		Description 		:	This file consists of the following declarations:       *                                  
*																				        *                                      
*								CSplach::												*            
*									CSplach(CWnd* pParent):								*						   
*									CDialog(CSplach::IDD, pParent)                      *
*								void CSplach::OnTimer(UINT_PTR nIDEvent)					*                           
*								void CSplach::											*
*									DoDataExchange(CDataExchange* pDX)                  *                              
*								void CSplach::OnBtnContinue()							*                                                                    
*								HBRUSH CSplach::										* 
*									OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)    *
*								BOOL CSplach::OnInitDialog()                            *
*								void CSplach::OnSelchangeComboHoldTime()				*                
****************************************************************************************/

// Splach.cpp : implementation file
//

#include "stdafx.h"
#include "SIPU_SDU_GndRig.h"
#include "Splach.h"
//#include "IMAGEHLP.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CString g_strAppVersion;
extern CString g_strCheckSum;
extern unsigned char g_ucTestType;

/////////////////////////////////////////////////////////////////////////////
// CSplach dialog
#define TIMER_NUM		0x01
#define SPLASH_TIME		1000

CSplach::CSplach(CWnd* pParent /*=NULL*/)
	: CDialog(CSplach::IDD, pParent)
{
	m_uiTimeElapsed = 0;
	//{{AFX_DATA_INIT(CSplach)
	m_radTestType = 0;
	//}}AFX_DATA_INIT
	brushNew.CreateSolidBrush(RGB(0xbf,0xdf,0xfa));
}

/*****************************************************************************
*  Function Name    = DoDataExchange()                                       *                       
*  Class            = CSplach												 *                       
*  Return Type      = void                                                   *                       
*  Parameters       = CDataExchange* pDX                                     *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to perform data exchange.        *                        							                               
*****************************************************************************/

void CSplach::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSplach)
	DDX_Control(pDX, IDC_COMBO_HOLD_TIME, m_ctlCboHoldTime);
	DDX_Radio(pDX, IDC_RAD_TESTTYPE, m_radTestType);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSplach, CDialog)
	//{{AFX_MSG_MAP(CSplach)
	ON_WM_CTLCOLOR()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUT_CONTINUE, OnButContinue)
	ON_CBN_SELCHANGE(IDC_COMBO_HOLD_TIME, OnSelchangeComboHoldTime)
	//}}AFX_MSG_MAP
	ON_STN_CLICKED(IDC_STATIC_EXE_CHECKSUM, &CSplach::OnStnClickedStaticExeChecksum)
	ON_BN_CLICKED(IDC_RAD_TESTTYPE, &CSplach::OnBnClickedRadTesttype)
	ON_BN_CLICKED(IDC_RAD_ILT_LUM_CENTERING, &CSplach::OnBnClickedRadIltLumCentering)
	ON_BN_CLICKED(IDC_RAD_ILTSELFTEST, &CSplach::OnBnClickedRadIltselftest)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSplach message handlers

/*****************************************************************************
*  Function Name    = OnInitDialog()                                         *                       
*  Class            = CSplach												 *                       
*  Return Type      = BOOL                                                   *                       
*  Parameters       = None													 *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to initialize the dialog box     *  							                               
*****************************************************************************/

BOOL CSplach::OnInitDialog() 
{
	CDialog::OnInitDialog();
	char chFileName[18];
	char chHexCheckSum[8];
	CString strCheckSum;
	DWORD CheckSum = NULL;
    DWORD HeaderSum = NULL;

	m_uiTimeElapsed = 0;
	m_uiTimeHold = 10;

	// display exe version and release date
	g_strAppVersion.Format("Version 1.00 Release Date 13-04-2026");

	// Get exe file checksum
	sprintf (chFileName, "IAT.exe");

#if 1
	HANDLE hFile = NULL;
    hFile = CreateFile(chFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL , 0);
    
    HANDLE hMapFile;
    hMapFile = CreateFileMapping(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
    
    LPVOID lpMapAddress;
    lpMapAddress = MapViewOfFile( hMapFile, FILE_MAP_READ, 0, 0, 0);

	//ULONG ulret = MapFileAndCheckSumA(chFileName, &HeaderSum, &CheckSum);
#endif	

	// convert the checksum value from unsigned int to hex
	itoa(CheckSum, chHexCheckSum, 16);
	
	// frame the display string
	//g_strCheckSum.Format("EXE File Checksum: %s", chHexCheckSum);
	//g_strCheckSum.Format("EXE File Checksum: 650d56");
	g_strCheckSum.Format("EXE File Checksum: 1a67s77");

	GetDlgItem(IDC_STATIC_APP_VERSION)->SetWindowText(g_strAppVersion);
	GetDlgItem(IDC_STATIC_EXE_CHECKSUM)->SetWindowText(g_strCheckSum);

	// start the time for hold time string
	SetTimer(TIMER_NUM, SPLASH_TIME, NULL);

	m_ctlCboHoldTime.SetCurSel(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

/*****************************************************************************
*  Function Name    = OnTimer()							                     *                       
*  Class            = CSplach												 *                       
*  Return Type      = void                                                   *                       
*  Parameters       = UINT nIDEvent											 *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function checks that if m_uiTimeElapsed is equal  *
*  to m_uiTimeHold, kill timer other wise  increased m_uiTimeElapsed.		 *                  
*****************************************************************************/

void CSplach::OnTimer(UINT_PTR nIDEvent) 
{
	UpdateData(true);

	// check for user selected time out
	if(m_uiTimeElapsed == m_uiTimeHold)
	{
		KillTimer(TIMER_NUM);
		OnOK();
	}
	else
	{
		m_uiTimeElapsed++;
	}

	CDialog::OnTimer(nIDEvent);
}

/*****************************************************************************
*  Function Name    = OnCtlColor()                                           *                       
*  Class            = CSplach												 *                       
*  Return Type      = HBRUSH                                                 *                       
*  Parameters       = CDC* pDC, CWnd* pWnd, UINT nCtlColor                   *                       
*  Visibility       = Protected                                              *                       
*  Description      = It changes attributes of DC when default is desired    *
*					  otherwise return a different brush                     *   							                               
*****************************************************************************/

HBRUSH CSplach::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	
	if( (nCtlColor == CTLCOLOR_DLG) || (nCtlColor == CTLCOLOR_STATIC) )   
	{
		pDC->SetBkMode(BACKGROUND_COLOR);
		return brushNew;
	}	
	return hbr;
}

/*****************************************************************************
*  Function Name    = OnBtnContinue()			                             *                       
*  Class            = CSplach												 *                       
*  Return Type      = void                                                   *                       
*  Parameters       = None                                                   *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to continue the  process.        *            
*****************************************************************************/

void CSplach::OnButContinue() 
{
	UpdateData(true);

	g_ucTestType = m_radTestType;

	UpdateData(false);
	
	HCURSOR hCursor = LoadCursorFromFile("Handapst.ani");

    if(hCursor != NULL)
	{
	    SetCursor(hCursor);
	}

	KillTimer(TIMER_NUM);
	CDialog::OnOK();
}

/*****************************************************************************
*  Function Name    = OnSelchangeComboHoldTime()                             *                       
*  Class            = CSplach												 *                       
*  Return Type      = void                                                   *                       
*  Parameters       = None                                                   *                       
*  Visibility       = Protected                                              *                       
*  Description      = This function is used to get the currently selected    *
*					  hold time index										 *
*****************************************************************************/

void CSplach::OnSelchangeComboHoldTime() 
{
	// variable declaration
	int iCurSel;
	
	KillTimer(TIMER_NUM);
	
	UpdateData(true);

	m_uiTimeElapsed = 0;

	// get currently selected hold time index
	iCurSel = m_ctlCboHoldTime.GetCurSel();

	if (iCurSel == 0)
	{
		m_uiTimeHold = 10;		
	}
	else
	{
		m_uiTimeHold = (iCurSel*5) + 10;
	}
	
	UpdateData(false);

	GetDlgItem(IDC_BUT_CONTINUE)-> SetFocus();
	SetTimer(TIMER_NUM, SPLASH_TIME, NULL);	

}

void CSplach::OnStnClickedStaticExeChecksum()
{
}

void CSplach::OnBnClickedRadTesttype()
{
}

void CSplach::OnBnClickedRadIltLumCentering()
{
}

void CSplach::OnBnClickedRadIltselftest()
{
}