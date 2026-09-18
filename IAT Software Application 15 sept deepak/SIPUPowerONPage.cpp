/*************************************************************************************************
*	Project Name		:	ISIS																	 *
*	File Name			:   SIPUPowerONPage.cpp               									 *
*	Author				:													     *
*	Date				:													 *
*	Version of file		:	V1.00																 *
*	Description 		:	This file consists of the following declarations:                    *
*							void CSIPUPowerONPage::OnInitialUpdate() 							 *
*							void CSIPUPowerONPage::OnButtonExec()								 *		
*							void CSIPUPowerONPage::OnSelchangeListMainTest() 					 *
*							void CSIPUPowerONPage::OnSelchangeListSubTest() 					 *
*							void CSIPUPowerONPage::InitListCtrl(CXListCtrl &list)				 *	
*							void CSIPUPowerONPage::FillListCtrl(CXListCtrl &list)				 *	
*					
*							void OnButPrintFile();										         *															
**************************************************************************************************/

// SIPUPowerONPage.cpp : implementation file

#include "stdafx.h"
#include "string.h"
#include "SIPU_SDU_GndRig.h"
#include "SIPUPowerONPage.h"
#include "CaptionListView.h"
#include "TestTable.h"
#include "DialogISISPower.h"

//Printing 
#include "helper.h"
#include "unit_headerpage.h"
#include "unit_indexpage.h"
#include "unit_table1.h"
#include "DataStruct.h"

//Header files
#include "VisualInspection.h"


#include "Dlg_ISIS_ADUTest.h"
#include "Dlg_ISIS_PWR.h"
#include "Dlg_ISIS_SWCHK.h"
#include "Dlg_ISIS_AHRS.h"
#include "Dlg_ISIS_ADUTest.h"
#include "Dialog_ADC_Visual.h"
#include "Dlg_ADC_PWR.h"
#include "Dialog_ADC_LEAK.h"
#include "Dialog_ADC_FUNCHK.h"
#include "Dialog_AHRS_VISUAL.h"
#include "Dialog_AHRS_PWR.h"
#include "Dialog_AHRS_QualityChecks.h"
#include "Dialog_GPS_VISUAL.h"
#include "Dialog_GPS_PWR.h"
#include "Dialog_GPS_DBInfo.h"
#include "Dialog_GPS_SYSINFO.h"
#include "Dialog_VORTAC_Visual.h"
#include "Dialog_VORTAC_PWR.h"
#include "Dialog_SMFD_SW.h"
#include "Dialog_Smfd_Visual.h"
#include "Dialog_SMFD_PWR.h"
#include "Dialog_Smfd_Fuel.h"
#include "Dialog_Smfd_Rev_Page.h"
#include "Dialog_Smfd_VORILS.h"
#include "Dialog_Smfd_Analog.h"
#include "Dialog_Smfd_Analog2.h"
#include "Dialog_Smfd_Discrete.h"
#include "DialogSmfd_ADC.h"
#include "DialogSmfd_Tacan.h"
#include "DialogSmfdAHRS.h"
#include "Dialog_SMFD_GPS.h"
#include "Dialog_ISIS_BRTCHK.h"
#include "Dialog_ISIS_IBIT.h"
#include "Dialog_ISIS_NAVMODE.h"
#include "Dialog_ISIS_ALN.h"
#include "Dialog_Smfd_Adc_RC.h"
#include "Dialog_Smfd_AHRS_RC.h"
#include "Dialog_Smfd_Visual_RC.h"
#include  "Dialog_Smfd_Analog1_RC.h"
#include "Dialog_Smfd_Analog_RC.h"
#include "Dialog_Smfd_Discrete_RC.h"
#include "Dialog_Smfd_Fuel_RC.h"
#include "Dialog_Smfd_Gps_RC.h"
#include "Dialog_Smfd_Pwr_RC.h"
#include "Dialog_Smfd_Vorils_RC.h"
#include "Dialog_Smfd_Tacan_RC.h"
#include "Dialog_Smfd_Sw_RC.h"
#include "Dialog_Smfd_Rev_RC.h"
#include "Dialog_ADC_MachCHK.h"
#include "Dialog_ADC_ALTI2.h"
#include "Dialog_ADC_ALTI3.h"
#include "Dialog_ADC_AIR1.h"
#include "Dialog_ADC_AIR2.h"
#include "Dialog_ADC_AIR3.h"
#include "Dialog_ADC_ALTIRATE.h"
#include "Dialog_ADC_MACH2.h"
//Analog FC
#include "Dialog_SMFD_FC_ANBV.h"
#include "Dialog_SMFD_FC_ANCL.h"
#include "Dialog_SMFD_FC_ANCT.h"
#include "Dialog_SMFD_FC_ANEB.h"
#include "Dialog_SMFD_FC_ANES.h"
#include "Dialog_SMFD_FC_ANFTL.h"
#include "Dialog_SMFD_FC_ANFTR.h"
#include "Dialog_SMFD_FC_ANGEOP.h"
#include "Dialog_SMFD_FC_ANGV.h"
#include "Dialog_SMFD_FC_ANLBP.h"
#include "Dialog_SMFD_FC_ANRBP.h"
#include "Dialog_SMFD_FC_ATP.h"
#include "Dialog_SMFD_FC_ET.h"
#include "Dialog_SMFD_FC_ETP.h"
#include "Dialog_SMFD_FC_FP3.h"
#include "Dialog_SMFD_FC_FP4.h"
#include "Dialog_SMFD_FC_HPE.h"
#include "Dialog_SMFD_FC_RTP.h"
//Analog RC
#include "Dialog_SMFD_RC_BV.h"
#include "Dialog_SMFD_RC_ANCL.h"
#include "Dialog_SMFD_RC_CT.h"
#include "Dialog_SMFD_RC_EB.h"
#include "Dialog_SMFD_RC_ES.h"
#include "Dialog_SMFD_RC_FTL.h"
#include "Dialog_SMFD_RC_FTR.h"
#include "Dialog_SMFD_RC_EOP.h"
#include "Dialog_SMFD_RC_GV.h"
#include "Dialog_SMFD_RC_LBP.h"
#include "Dialog_SMFD_RC_RBP.h"
#include "Dialog_SMFD_RC_ATP.h"
#include "Dialog_SMFD_RC_ET.h"
#include "Dialog_SMFD_RC_ETP.h"
#include "Dialog_SMFD_RC_FP3.h"
#include "Dialog_SMFD_RC_FP4.h"
#include "Dialog_SMFD_RC_HPE.h"
#include "Dialog_SMFD_RC_RTP.h"
#include "Dialog_SMFD_RC_EOT.h"
#include "Dialog_SMFD_RC_HPM.h"
//Analog RC
#include "bdaqctrl.h"
#include "DialogStop.h"
#include "Globals.h"
#include <commctrl.h>


///////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////




#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BOOL g_bCMFD66Flag = false;
unsigned char g_ucCMFD_MOD = CMFD_MOD2;

extern BOOL g_bMFDPowerONStatus;
sTest_Header s_Index_Page;
sStopTestLog s_StopTestObj;
CString g_str_Measured_Val;
CString g_str_Test_Result;
CString g_strFileName;

CString          g_strSelfTestFileName = "";
sSelfTest_Header s_SelfTest_IndexPage;
sSelfTest_Item   s_Curr_SelfTest_Item;

CString g_strCountDigit1 = "", g_strCountDigit2 = "", g_strCountDigit3 = "";
char g_chFileName[250];
#define MODE_STANDALONE 1
#define MODE_INTEGRATION 0

int g_nItem=0;
int iTempCount = 0;

struct sTest_Details
{
	unsigned char m_ucMajor_Test_ID;
	unsigned int m_uiMinor_Test_ID;

	CString m_strExpected;
	CString m_strMajor_Test_Name;
	CString m_strMinor_Test_Name;
	CString m_strMeasuredValue;
	CString m_strTestStatus;
	CDialog *m_Intial_State_Dlg;
	CDialog *m_Procedure_Dlg;
}s_AllTestDetails[DU_ATP_MAX_NO_OF_TEST];

namespace
{
HHOOK g_hProcedureDialogHook = NULL;
CDialog* g_pProcedureDialog = NULL;
CSIPUPowerONPage* g_pTestExecutionPage = NULL;

LRESULT CALLBACK StopTestProcedureDialog(
	HWND hDialog,
	UINT message,
	WPARAM wParam,
	LPARAM lParam,
	UINT_PTR uIdSubclass,
	DWORD_PTR dwRefData)
{
	if (message == WM_COMMAND && LOWORD(wParam) == ID_STOP)
	{
		// This handler is attached to the modal procedure dialog itself, so
		// the STOP command is received even while MFC is running a modal loop.
		TRACE("\n[STOP] STOP button clicked. Cancelling the active procedure dialog.\n");
		g_bStopRequested = TRUE;

		CSIPU_SDU_GndRigApp* pApp =
			(CSIPU_SDU_GndRigApp*)AfxGetApp();
		if (pApp != NULL)
			pApp->OnTerminateTestSeq();

		// Do not call the Win32 ::EndDialog directly here.  The dialog is
		// running through CDialog::DoModal(), so CDialog::EndDialog must end
		// MFC's modal loop as well as destroy the native dialog window.
		if (g_pProcedureDialog != NULL &&
			g_pProcedureDialog->GetSafeHwnd() == hDialog)
			g_pProcedureDialog->EndDialog(IDCANCEL);
		else
			::EndDialog(hDialog, IDCANCEL);
		TRACE("[STOP] Active procedure dialog closed. Waiting for the sequence to finish.\n");
		return 0;
	}

	if (message == WM_NCDESTROY)
	{
		::RemoveWindowSubclass(hDialog, StopTestProcedureDialog, uIdSubclass);
	}

	return ::DefSubclassProc(hDialog, message, wParam, lParam);
}

LRESULT CALLBACK AddStopButtonToProcedureDialog(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode == HCBT_ACTIVATE && g_pProcedureDialog != NULL)
	{
		HWND hDialog = (HWND)wParam;
		if (hDialog == g_pProcedureDialog->GetSafeHwnd() &&
			::GetDlgItem(hDialog, ID_STOP) == NULL)
		{
			::SetWindowSubclass(
				hDialog,
				StopTestProcedureDialog,
				(UINT_PTR)ID_STOP,
				0);

			RECT clientRect;
			::GetClientRect(hDialog, &clientRect);

			::CreateWindowEx(
				0,
				_T("BUTTON"),
				_T("STOP"),
				WS_CHILD | WS_VISIBLE | WS_TABSTOP | BS_PUSHBUTTON,
				clientRect.right - 60,
				4,
				55,
				16,
				hDialog,
				(HMENU)(INT_PTR)ID_STOP,
				AfxGetInstanceHandle(),
				NULL);
		}
	}

	return ::CallNextHookEx(g_hProcedureDialogHook, nCode, wParam, lParam);
}

int ShowTestProcedure(CDialog* pDialog)
{
	if (pDialog == NULL)
		return IDCANCEL;

	g_pProcedureDialog = pDialog;
	g_hProcedureDialogHook = ::SetWindowsHookEx(
		WH_CBT,
		AddStopButtonToProcedureDialog,
		NULL,
		::GetCurrentThreadId());

	int result = pDialog->DoModal();
	TRACE("[STOP] Procedure dialog returned. result=%d, stopRequested=%d\n",
		result, g_bStopRequested);
	if (g_bStopRequested)
	{
		// Hardware shutdown has already completed. Restore the main-panel
		// controls immediately after the procedure dialog has closed.
		CSIPUPowerONPage* pExecutionPage = g_pTestExecutionPage;
		if (pExecutionPage != NULL)
		{
			pExecutionPage->SetTestExecutionControls(TRUE);
			TRACE("[STOP] Procedure dialog closed; Execute and Print controls enabled.\n");
		}
	}

	if (g_hProcedureDialogHook != NULL)
	{
		::UnhookWindowsHookEx(g_hProcedureDialogHook);
		g_hProcedureDialogHook = NULL;
	}
	g_pProcedureDialog = NULL;

	return result;
}
}

//////////////////////////////////////////////////////////////////////////
class MyPrintJob : public GPrintJob
{
public:
   MyPrintJob() {;}
   virtual ~MyPrintJob() {;}
   void OnPrint();
};


/////////////////////////////////////////////////////////////////////////////
// CSIPUPowerONPage

IMPLEMENT_DYNCREATE(CSIPUPowerONPage, CFormView)

CSIPUPowerONPage::CSIPUPowerONPage()
	: CFormView(CSIPUPowerONPage::IDD)
	, m_Edit_DU_No(_T(""))
	, m_edtStrTestDesc(_T(""))
	, m_strNAVTAC_SNO(_T(""))
{
	//{{AFX_DATA_INIT(CSIPUPowerONPage)
	m_cmdStrSelectedType = _T("");
	m_cmdStrSubTest = _T("");
	m_Edit_DU_No = _T("");
	m_fEdit_TestStart = 0.0f;
	m_fEdit_TestEnd = 0.0f;
	//}}AFX_DATA_INIT
	//brushNew.CreateSolidBrush(RGB(0xbf,0xdf,0xfa));
	//brushNew.CreateSolidBrush(RGB(0xff,0xff,0xff));
		
}

CSIPUPowerONPage::~CSIPUPowerONPage()
{
	if (DynListCtrl)
    {
        if (::IsWindow(DynListCtrl->GetSafeHwnd()))
            DynListCtrl->DestroyWindow();

        delete DynListCtrl;
        DynListCtrl = NULL;
    }
}

void CSIPUPowerONPage::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSIPUPowerONPage)

	DDX_Control(pDX, IDC_COMBO_MODE, m_Cambo_Mode);
	DDX_Control(pDX, IDC_LIST_SUB_TEST, m_List_Sub_Test);
	DDX_Control(pDX, IDC_LIST_MAIN_TEST, m_List_Main_List);
	DDX_LBString(pDX, IDC_LIST_MAIN_TEST, m_cmdStrSelectedType);
	DDX_LBString(pDX, IDC_LIST_SUB_TEST, m_cmdStrSubTest);
	DDX_Text(pDX, IDC_EDIT_DU_SNO, m_Edit_DU_No);
	DDX_Text(pDX, IDC_EDIT_START, m_fEdit_TestStart);
	DDX_Text(pDX, IDC_EDIT_END, m_fEdit_TestEnd);
	//}}AFX_DATA_MAP

	DDX_Control(pDX, IDC_COMBO_DU_TYPE, m_ctlCboDUType);
	DDX_Text(pDX, IDC_EDIT_TEST_DESC, m_edtStrTestDesc);


	// SMFD/MFD
	DDX_Text(pDX, IDC_EDIT_SMFD1_SNO, m_strSMFD1SNO);
	DDX_Text(pDX, IDC_EDIT_SMFD2_SNO, m_strSMFD2SNO);
	DDX_Text(pDX, IDC_EDIT_MFD1_SNO, m_strMFD1SNO);
	DDX_Text(pDX, IDC_EDIT_MFD2_SNO, m_strMFD2SNO);

	// ISIS
	DDX_Text(pDX, IDC_EDIT_ISIS_DU1_SNO, m_strISIS_DU1_SNO);
	DDX_Text(pDX, IDC_EDIT_ISIS_DU2_SNO, m_strISIS_DU2_SNO);
	DDX_Text(pDX, IDC_EDIT_ISIS_ADU_SNO, m_strISIS_ADU_SNO);
	DDX_Text(pDX, IDC_EDIT_ISIS_AHRS_SNO, m_strISIS_AHRS_SNO);
	DDX_Text(pDX, IDC_EDIT_ISIS_MGM_SNO, m_strISIS_MGM_SNO);

	// ADC
	DDX_Text(pDX, IDC_EDIT_ADC_SNO, m_strADC_SNO);

	// AHRS
	DDX_Text(pDX, IDC_EDIT_AHRS_SNO, m_strAHRS_SNO);

	// GPS
	DDX_Text(pDX, IDC_EDIT_GPS_SNO, m_strGPS_SNO);

	// NAV
	DDX_Text(pDX, IDC_EDIT_VORILS_TACAN_SNO, m_strNAV_SNO);
	DDX_Text(pDX, IDC_EDIT_TACAN_SNO, m_strNAVTAC_SNO);
	DDX_Control(pDX, IDC_COMBO_SMFD_SELECTION, m_ComboSMFDMode);
}


BEGIN_MESSAGE_MAP(CSIPUPowerONPage, CFormView)
	//{{AFX_MSG_MAP(CSIPUPowerONPage)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUT_VIEW_MSENSOR, OnMainSIPUDetailSensor)
	ON_BN_CLICKED(IDC_BUT_VIEW_ESENSOR, OnViewsensorDet)
	
	ON_BN_CLICKED(IDC_BUTTON_EXEC, OnButtonExec)
	ON_CBN_CLOSEUP(IDC_COMBO_MODE, OnCloseupComboMode)
	ON_LBN_KILLFOCUS(IDC_LIST_MAIN_TEST, OnKillfocusListMainTest)
	ON_LBN_SETFOCUS(IDC_LIST_SUB_TEST, OnSetfocusListSubTest)
	ON_LBN_SELCHANGE(IDC_LIST_MAIN_TEST, OnSelchangeListMainTest)
	ON_LBN_SELCHANGE(IDC_LIST_SUB_TEST, OnSelchangeListSubTest)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, OnButtonExit)
	ON_BN_CLICKED(IDC_BUT_PRINT, OnButPrint)
	ON_BN_CLICKED(IDC_BUTTON_SER, OnButtonSer)
	ON_EN_UPDATE(IDC_EDIT7, OnUpdateEdit7)
	ON_CBN_SELCHANGE(IDC_COMBO_MODE, OnSelchangeComboMode)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUT_PRINT_FILE, OnButPrintFile)
	
	//}}AFX_MSG_MAP
	ON_CBN_SELCHANGE(IDC_COMBO_DU_TYPE, &CSIPUPowerONPage::OnCbnSelchangeComboDuType)
    ON_CBN_SELCHANGE(IDC_COMBO_SMFD_SELECTION, &CSIPUPowerONPage::OnCbnSelchangeComboSMFDMode)
	//ON_EN_CHANGE(IDC_EDIT_DU_SNO, &CSIPUPowerONPage::OnEnChangeEditDuSno)
	ON_WM_CLOSE()

END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSIPUPowerONPage diagnostics

#ifdef _DEBUG
void CSIPUPowerONPage::AssertValid() const
{
	CFormView::AssertValid();
}

void CSIPUPowerONPage::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CSIPUPowerONPage message handlers

HBRUSH CSIPUPowerONPage::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor) 
{
	HBRUSH hbr = CFormView::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	if( (nCtlColor == CTLCOLOR_DLG) || (nCtlColor == CTLCOLOR_STATIC) )   
	{
		pDC->SetBkMode(BACKGROUND_COLOR);
		return brushNew;
	}
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CSIPUPowerONPage::OnMainSIPUDetailSensor() 
{
	// TODO: Add your control notification handler code here
	if(((CSIPU_SDU_GndRigApp *)AfxGetApp())->m_pDynamicViewWnd != NULL)
	{					
		((CSIPU_SDU_GndRigApp *)AfxGetApp())->m_pDynamicViewWnd->DestroyWindow();										
		((CSIPU_SDU_GndRigApp *)AfxGetApp())->m_pDynamicViewWnd = NULL;

	}
		
}

void CSIPUPowerONPage::OnViewsensorDet() 
{
	// TODO: Add your control notification handler code here
	if(((CSIPU_SDU_GndRigApp *)AfxGetApp())->m_pDynamicViewWnd != NULL)
	{					
		((CSIPU_SDU_GndRigApp *)AfxGetApp())->m_pDynamicViewWnd->DestroyWindow();										
		((CSIPU_SDU_GndRigApp *)AfxGetApp())->m_pDynamicViewWnd = NULL;

	}
	
}

/*******************************************************************************
*  Function Name    = OnInitialUpdate										   *
*  Class            = CSIPUPowerONPage          		                       *
*  Return Type      = void                                                     *
*  Parameters       = None				                                       *
*  Visibility       = Public	                                               *
*  Description      = This function is used for intial update.				   * 
*******************************************************************************/
void CSIPUPowerONPage::OnInitialUpdate() 
{
	CFormView::OnInitialUpdate();
	

	//InitializePCI_Boards();
	// hide the partial mode cotrols  
	//HidePartialControls();
	
	//Font For Button
	CFont    ButtonViewfont;
	ButtonViewfont.CreateFont(17,                        // nHeight
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
	   //"LiquidCrystal");        
	   "Verdana");    
 
CRect rtWnd;
GetClientRect(&rtWnd);

    rtWnd.top = 190;
	rtWnd.left = 360;
	rtWnd.right = 1000;
	rtWnd.bottom = 650;
//int margin = 20;

// 👇 Adjust this once based on your UI
/*int leftPanelRight = 550;  

CRect listRect;
listRect.left   = leftPanelRight + margin;
listRect.right  = rtWnd.right - margin;
listRect.top    = 150;
listRect.bottom = rtWnd.bottom - margin;*/

// Create List Control
DynListCtrl = new CXListCtrl();
if (DynListCtrl == NULL) return;

DynListCtrl->Create(
    WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT | LVS_SINGLESEL,
    rtWnd,
    this,
    1
);

DynListCtrl->SetExtendedStyle(
    LVS_EX_FULLROWSELECT |
    LVS_EX_GRIDLINES |
    LVS_EX_HEADERDRAGDROP |
    LVS_EX_ONECLICKACTIVATE
);

DynListCtrl->EnableToolTips(TRUE);

InitListCtrl(*DynListCtrl);
	// default setting for combo and list box controls
	m_Cambo_Mode.SetCurSel(0);
	m_ctlCboDUType.SetCurSel(0);
	m_List_Main_List.SetCurSel(0);
	m_List_Sub_Test.SetCurSel(0);
		

	m_Cambo_Mode.SetCurSel(1);
    m_ComboSMFDMode.SetCurSel(0);

   OnCbnSelchangeComboDuType();
 //  EnableLRUSerialInputs(m_ctlCboDUType.GetCurSel());
	UpdateData(false);
}

BOOL CSIPUPowerONPage::PreTranslateMessage(MSG* pMsg) 
{
	// TODO: Add your specialized code here and/or call the base class
	//m_Tooltip.RelayEvent(pMsg);
	return CFormView::PreTranslateMessage(pMsg);
}

void CSIPUPowerONPage::OnFileLog() 
{}

/*******************************************************************************
*  Function Name    = OnButtonExec											   *
*  Class            = CSIPUPowerONPage          		                       *
*  Return Type      = void                                                     *
*  Parameters       = None							                           *
*  Visibility       = Public	                                               *
*  Description      = This function is called when Execution os test is started*
*  If test is stopped then display the test otherwise display test completion  *
*  message																       *
*******************************************************************************/

void CSIPUPowerONPage::OnButtonExec() 
{
	CSIPU_SDU_GndRigApp *pMainFrame;
	pMainFrame = (CSIPU_SDU_GndRigApp *)AfxGetApp();
	g_bStopRequested = FALSE;
	pMainFrame->m_bTestStopFlag = FALSE;
	TRACE("\n[TEST] LRU test sequence started.\n");

	SetTestExecutionControls(FALSE);
	g_pTestExecutionPage = this;
	//On28Power("com12"); //change future
	ExecuteLRUTestSequence();

	BOOL bStopped = (g_bStopRequested || pMainFrame->m_bTestStopFlag);
	TRACE("[TEST] LRU test sequence returned. stopped=%d\n", bStopped);

	// The sequence and hardware shutdown have completed; return the main
	// panel to a stable, ready-to-run state before notifying the operator.
	pMainFrame->m_bTestStopFlag = FALSE;
	g_bStopRequested = FALSE;
	SetTestExecutionControls(TRUE);
	g_pTestExecutionPage = NULL;
	TRACE("[TEST] Main panel is stable. Execute and Print controls are enabled.\n");

	if (bStopped)
		AfxMessageBox("LRU Test Sequence Execution Terminated. Bench outputs are now OFF.");
	else
		AfxMessageBox("LRU Test Sequence Execution Completed");

}

void CSIPUPowerONPage::SetTestExecutionControls(BOOL bEnable)
{
	CWnd* pExecuteButton = GetDlgItem(IDC_BUTTON_EXEC);
	CWnd* pPrintButton = GetDlgItem(IDC_BUT_PRINT);

	if (pExecuteButton != NULL)
		pExecuteButton->EnableWindow(bEnable);
	if (pPrintButton != NULL)
		pPrintButton->EnableWindow(bEnable);
}

void CSIPUPowerONPage::OnCloseupComboMode() 
{
	// TODO: Add your control notification handler code here
	
}

void CSIPUPowerONPage::OnCloseupComboStopOnFault() 
{
	// TODO: Add your control notification handler code here
}


void CSIPUPowerONPage::OnKillfocusListMainTest() 
{
}

void CSIPUPowerONPage::OnSetfocusListSubTest() 
{
}

/*******************************************************************************
*  Function Name    = OnSelchangeListMainTest								   *
*  Class            = CSIPUPowerONPage	          		                       *
*  Return Type      = void                                                     *
*  Parameters       = None							                           *
*  Visibility       = Public	                                               *
*  Description      = This function is display main and sub list of BEL ISIS   *
********************************************************************************/


void CSIPUPowerONPage::OnSelchangeListMainTest()
{
   UpdateListBoxData();
}
/*******************************************************************************
*  Function Name    = OnSelchangeListSubTest								   *
*  Class            = CSIPUPowerONPage		          		                   *
*  Return Type      = void                                                     *
*  Parameters       = None							                           *
*  Visibility       = Public	                                               *
*  Description      = This function siaply sb test window.					   *
*******************************************************************************/

void CSIPUPowerONPage::OnSelchangeListSubTest() 
{
	UpdateData(true);

	// set the static text on right as per selected sub test
     GetDlgItem(IDC_LIST_SUB_TEST)->SetWindowText(m_cmdStrSubTest);

	UpdateData(false);
	
}

void CSIPUPowerONPage::OnButtonExit() 
{
	
}
void CSIPUPowerONPage::OnCbnSelchangeComboSMFDMode()
{
    EnableLRUSerialInputs(m_ctlCboDUType.GetCurSel());
}
/*******************************************************************************
*  Function Name    = InitListCtrl											   *
*  Class            = CSIPUPowerONPage	          		                       *
*  Return Type      = void                                                     *
*  Parameters       = CXListCtrl &list				                           *
*  Visibility       = Public	                                               *
*  Description      = This function Initialize test list, having paramters	   *
*  shown in report.															   *
*******************************************************************************/

void CSIPUPowerONPage::InitListCtrl(CXListCtrl &list)
{
	// set column width according to window rect
	CRect rect;
	list.GetWindowRect(&rect);
	
	int w = rect.Width() - 2;
	
	//int colwidths[9] = { 6,9,12,6,9,6,6,5,5};	// sixty-fourths
	int colwidths[10] = { 8,13,15,10,9,7};	// sixty-fourths

	TCHAR *	lpszHeaders[] = { _T("Test no"),
							  _T("Test Type"),
							  _T("Sub Test Type"),
							  _T("Specification"),
							  _T("Measured Value"),
							  _T("Test Status"),
							 };

	int i;
	int total_cx = 0;
	LV_COLUMN lvcolumn;
	memset(&lvcolumn, 0, sizeof(lvcolumn));

	// add columns
	for (i = 0;i<6; i++)
	{
		if (lpszHeaders[i] == NULL)
			break;

		lvcolumn.mask = LVCF_FMT | LVCF_SUBITEM | LVCF_TEXT | LVCF_WIDTH;
		//lvcolumn.fmt = (i == 1 || i == 5) ? LVCFMT_LEFT : LVCFMT_CENTER;
		lvcolumn.fmt = LVCFMT_CENTER;
		lvcolumn.pszText = lpszHeaders[i];
		lvcolumn.iSubItem = i;
		lvcolumn.cx = (lpszHeaders[i+1] == NULL) ? w - total_cx - 2 : (w * colwidths[i]) / 64;
		total_cx += lvcolumn.cx;
		list.InsertColumn(i, &lvcolumn);
	}


	// create the image list from bitmap resource
	VERIFY(list.m_cImageList.Create(IDB_CHECKBOXES, 16, 3, RGB(255, 0, 255)));
	list.m_HeaderCtrl.SetImageList(&list.m_cImageList);

	// iterate through header items and attach the image list
	HDITEM hditem;

	for (i = 0; i < list.m_HeaderCtrl.GetItemCount(); i++)
	{
		hditem.mask = HDI_IMAGE | HDI_FORMAT;
		list.m_HeaderCtrl.GetItem(i, &hditem);
		hditem.fmt |=  HDF_IMAGE;

		/*if (i == 0 || i == 4)
			hditem.iImage = XHEADERCTRL_UNCHECKED_IMAGE;
		else*/
			hditem.iImage = XHEADERCTRL_NO_IMAGE;

		list.m_HeaderCtrl.SetItem(i, &hditem);
	}

	memset(&lvcolumn, 0, sizeof(lvcolumn));

	// set the format again - must do this twice or first column does not get set
	for (i = 0; ; i++)
	{
		if (lpszHeaders[i] == NULL)
			break;

		lvcolumn.mask = LVCF_FMT | LVCF_SUBITEM;
		//lvcolumn.fmt = (i == 1 || i == 5) ? LVCFMT_LEFT : LVCFMT_CENTER;
		lvcolumn.fmt = LVCFMT_CENTER;
		lvcolumn.iSubItem = i;
		list.SetColumn(i, &lvcolumn);
	}
}
/*******************************************************************************
*  Function Name    = FillListCtrl											   *
*  Class            = CSIPUPowerONPage	          		                       *
*  Return Type      = void                                                     *
*  Parameters       = CXListCtrl &list				                           *
*  Visibility       = Public	                                               *
*  Description      = This function fills the data in list of report and also  *
*  performing formatting of report.											   *
*******************************************************************************/

void CSIPUPowerONPage::FillListCtrl(CXListCtrl &list)
{
	CString str;

	list.LockWindowUpdate();	// ***** lock window updates while filling list *****

	//int nItem=0, nSubItem=0;
	int nSubItem=0;
	int Sno=0;

	CSIPU_SDU_GndRigApp *AppPtr	=	NULL;
	AppPtr						=	(CSIPU_SDU_GndRigApp *)AfxGetApp();
	
	//To Add Date into Report	Heading.....
	char  date[25]=" : ";	
//	MergeDateOnlyTostring(date,25);
	
	//append_head(date);

	//fptr.SeekToBegin();

	int SubItemCnt = 0;


	//while(fptr.Read(&obj,(sizeof(obj))) > 0)
	//while( Sno < 3)
	//{
	
		if (g_nItem == 0)
		{
			UpdateData(true);

			list.DeleteAllItems();
			list.UpdateWindow();

			UpdateData(false);
		}
		
		SubItemCnt = 0;			

		str = _T("");
		list.InsertItem(g_nItem, str);

		//----------------------------------------------------------------
		str = "";
		Sno++;
		//str.Format("%u",Sno);
		float fTemp = 0;
		fTemp = (s_Curr_Test_Result.m_uiMinor_Test_ID)/100.0;
		//str.Format("%u",s_Curr_Test_Result.m_uiMinor_Test_ID);
		str.Format("%.2f",fTemp);
		list.SetItemText(g_nItem, SubItemCnt++, str, BLUE_COLOR, LPINK_COLOR);
	/*	//----------------------------------------------------------------
		str = "";
		str =obj.cParamName;
		list.SetItemText(nItem, SubItemCnt++, str, BLUE_COLOR, LPINK_COLOR);*/
		//----------------------------------------------------------------
		str = "";
		//str.Format("%o",obj.usLABEL);
		str.Format("%s", s_Curr_Test_Result.m_strMajorTestName);
		list.SetItemText(g_nItem, SubItemCnt++, str, BLUE_COLOR, MGRAY_COLOR);
		//-----------------------------------------------------------------
		
		str = "";
		//GetBit_Pattern((unsigned long)obj.usSSM, &str, 2);
		str.Format("%s", s_Curr_Test_Result.m_strMinorTestName);
		list.SetItemText(g_nItem, SubItemCnt++, str, BLUE_COLOR, LPINK_COLOR);
		//----------------------------------------------------------------

		str.Format("%s", s_Curr_Test_Result.m_strSpec);
		list.SetItemText(g_nItem, SubItemCnt++, str, BLUE_COLOR, LPINK_COLOR);
		//----------------------------------------------------------------

				
		if (! (strcmp(s_Curr_Test_Result.m_strTestStatus,"OK")) )
		{
			str.Format("%s", s_Curr_Test_Result.m_strMeasuered_Val);
			list.SetItemText(g_nItem, SubItemCnt++, str, BLUE_COLOR, LPINK_COLOR);
			//----------------------------------------------------------------

			str.Format("OK");
			list.SetItemText(g_nItem, SubItemCnt++, str, BLUE_COLOR, LPINK_COLOR);

		}
		else
		{
			str.Format("%s", s_Curr_Test_Result.m_strMeasuered_Val);
			list.SetItemText(g_nItem, SubItemCnt++, str, RED_COLOR, LPINK_COLOR);
			//----------------------------------------------------------------

			str.Format("NOT OK");
			list.SetItemText(g_nItem, SubItemCnt++, str, RED_COLOR, LPINK_COLOR);
		}

	
	//----------------------------------------------------------------
		g_nItem++;
	//}	
	//fptr.Close(); 
	
	list.EnsureVisible((list.GetItemCount()-1),NULL);

	list.UnlockWindowUpdate();	// ***** unlock window updates *****
/*
	CRect r;
	GetClientRect(r);
	list.MoveWindow(r,true);   	
	*/

}
/*******************************************************************************
*  Function Name    = OnButPrint											   *
*  Class            = CSIPUPowerONPage	          		                       *
*  Return Type      = void                                                     *
*  Parameters       = None							                           *
*  Visibility       = Public	                                               *
*  Description      = This function take the file for printing.				   *
*******************************************************************************/

void CSIPUPowerONPage::OnButPrint() 
{
	static char BASED_CODE szFilter[] = "Binary Files(*.BIN)|*.BIN||";
	
	if (g_strFileName.Compare("") == 0)
	{
		CFileDialog CmnCtlobj(true, "bin","", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);

		// get the file name for currently executed test
		g_strFileName.Format("%s", g_chFileName);

		if(CmnCtlobj.DoModal() == IDCANCEL)
		{
			return;
		}
		else
		{
			UpdateData(true);
			g_strFileName = CmnCtlobj.GetPathName();	
		}
	}

	MyPrintJob job;
   job.Print();
	
	CWaitCursor UserInteractionLock;
	g_strFileName.Format("");
}

/*******************************************************************************
*  Function Name    = ResetListCtrl											   *
*  Class            = CSIPUPowerONPage	          		                       *
*  Return Type      = void                                                     *
*  Parameters       = CXListCtrl &list				                           *
*  Visibility       = Public	                                               *
*  Description      = This function reset the list of paramters of report.	   *
*******************************************************************************/

void CSIPUPowerONPage::ResetListCtrl(CXListCtrl &list)
{
		
//	if( DynListCtrl != NULL)
//		delete(DynListCtrl);

	CRect rtWnd;
	GetClientRect(rtWnd);
	
	rtWnd.top = 120;
	rtWnd.bottom = 600;
	rtWnd.left = 300;
	rtWnd.right = 850;

//	if( DynListCtrl != NULL)
//		delete(DynListCtrl);

	DynListCtrl = new CXListCtrl();
	
	if(DynListCtrl==NULL) return; 

	DynListCtrl->Create(
	WS_CHILD|WS_VISIBLE|WS_BORDER|LVS_REPORT|LVS_SINGLESEL|LVS_EX_GRIDLINES,
	rtWnd, this, 1);	
	
	/*DWORD dwStyle = LVS_REPORT | LVS_SINGLESEL | LVS_SHOWSELALWAYS |
	 WS_CHILD | WS_VISIBLE | WS_GROUP | WS_TABSTOP;*/
	/*DynListCtrl->CreateEx(WS_EX_CLIENTEDGE,_T("ADC Channel View"), _T(""),dwStyle, rtWnd, this, NULL, NULL);*/

	DynListCtrl->SetExtendedStyle(LVS_EX_HEADERDRAGDROP|LVS_EX_GRIDLINES|LVS_EX_FULLROWSELECT|LVS_EX_ONECLICKACTIVATE|LVS_EX_FLATSB); 
	//DynListCtrl->SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_TRACKSELECT);	
	DynListCtrl->EnableToolTips(true); 

	//Fill the report details here and 
	InitListCtrl(*DynListCtrl);	
}
/*******************************************************************************
*  Function Name    = OnPrint												   *
*  Class            = MyPrintJob		          		                       *
*  Return Type      = void                                                     *
*  Parameters       = None							                           *
*  Visibility       = Public	                                               *
*  Description      = This function print the header and test page.			   *
*******************************************************************************/

void MyPrintJob::OnPrint()
{
	//Variable b_retValue added on 03-12-14
   BOOL b_retValue = TRUE;
   IndexUnit unitIndex(this);
   GSELECT_PJINDEXTREE(&unitIndex.m_pTree);

   HeaderPage unitHeaderPage(this);
   unitHeaderPage.Print();

   Table1Unit unitTable1(this);
   b_retValue = unitTable1.Print();
  // if(b_retValue)
	//   unitIndex.Print();
}

/*******************************************************************************
*  Function Name    = OnButtonSer											   *
*  Class            = CSIPUPowerONPage          		                       *
*  Return Type      = void                                                     *
*  Parameters       = None							                           *
*  Visibility       = Public	                                               *
*  Description      =														   *
*******************************************************************************/

void CSIPUPowerONPage::OnButtonSer() 
{
}
/*******************************************************************************
*  Function Name    = OnUpdateEdit7											   *
*  Class            = CSIPUPowerONPage          		                       *
*  Return Type      = void                                                     *
*  Parameters       = None							                           *
*  Visibility       = Public	                                               *
*  Description      =														   *	
*******************************************************************************/

void CSIPUPowerONPage::OnUpdateEdit7() 
{
	UpdateData(true);

	unsigned char ucRData = 0;
	bool bTrsFlag = false;

	UpdateData(true);
}
/*******************************************************************************
*  Function Name    = HidePartialControls									   *
*  Class            = CSIPUPowerONPage          		                       *
*  Return Type      = void                                                     *
*  Parameters       = None							                           *
*  Visibility       = Public	                                               *
*  Description      = This function is hide the START and END window,          *
*  is partial mode is selected.												   *	
*******************************************************************************/

void CSIPUPowerONPage::HidePartialControls()
{
	GetDlgItem(IDC_STATIC_START)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_START)->ShowWindow(false);
	GetDlgItem(IDC_STATIC_END)->ShowWindow(false);
	GetDlgItem(IDC_EDIT_END)->ShowWindow(false);

}

/*******************************************************************************
*  Function Name    = DisplayPartialControls								   *
*  Class            = CSIPUPowerONPage          		                       *
*  Return Type      = void                                                     *
*  Parameters       = None							                           *
*  Visibility       = Public	                                               *
*  Description      = This function is display the START and END window,       *
*  is partial mode is selected.												   *	
*******************************************************************************/

void CSIPUPowerONPage::DisplayPartialControls()
{
	UpdateData(true);

	GetDlgItem(IDC_STATIC_START)->ShowWindow(true);
	GetDlgItem(IDC_EDIT_START)->ShowWindow(true);
	GetDlgItem(IDC_STATIC_END)->ShowWindow(true);
	GetDlgItem(IDC_EDIT_END)->ShowWindow(true);

	OnSelchangeListMainTest();

	UpdateData(false);
}

/*******************************************************************************
*  Function Name    = OnSelchangeComboMode									   *
*  Class            = CSIPUPowerONPage          		                       *
*  Return Type      = void                                                     *
*  Parameters       = None							                           *
*  Visibility       = Public	                                               *
*  Description      = This function is sued to display window like START, END  * 
*  if partial mode is selected.												   *
*******************************************************************************/


    void CSIPUPowerONPage::OnSelchangeComboMode()
{
    int mode = m_Cambo_Mode.GetCurSel();

    if(mode == MODE_INTEGRATION)
    {
        m_ctlCboDUType.SetCurSel(0);
        m_ctlCboDUType.EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_SMFD_SELECTION)->ShowWindow(FALSE);

        // Enable all serial inputs
       EnableLRUSerialInputs(-1);

        GetDlgItem(IDC_EDIT_SMFD1_SNO)->EnableWindow(TRUE);
        GetDlgItem(IDC_EDIT_SMFD2_SNO)->EnableWindow(TRUE);
        GetDlgItem(IDC_EDIT_MFD1_SNO)->EnableWindow(TRUE);
        GetDlgItem(IDC_EDIT_MFD2_SNO)->EnableWindow(TRUE);

        GetDlgItem(IDC_EDIT_ISIS_DU1_SNO)->EnableWindow(TRUE);
        GetDlgItem(IDC_EDIT_ISIS_DU2_SNO)->EnableWindow(TRUE);
        GetDlgItem(IDC_EDIT_ISIS_ADU_SNO)->EnableWindow(TRUE);
        GetDlgItem(IDC_EDIT_ISIS_AHRS_SNO)->EnableWindow(TRUE);
        GetDlgItem(IDC_EDIT_ISIS_MGM_SNO)->EnableWindow(TRUE);

        GetDlgItem(IDC_EDIT_ADC_SNO)->EnableWindow(TRUE);
        GetDlgItem(IDC_EDIT_AHRS_SNO)->EnableWindow(TRUE);
        GetDlgItem(IDC_EDIT_GPS_SNO)->EnableWindow(TRUE);
        GetDlgItem(IDC_EDIT_VORILS_TACAN_SNO)->EnableWindow(TRUE);
    }
    else
    {
        m_ctlCboDUType.EnableWindow(TRUE);
		if(m_ctlCboDUType.GetCurSel() == 0)
		{
			GetDlgItem(IDC_COMBO_SMFD_SELECTION)->ShowWindow(TRUE);
			if(m_ComboSMFDMode.GetCurSel() < 0)
				m_ComboSMFDMode.SetCurSel(0);
		}
		int lru = m_ctlCboDUType.GetCurSel();
        EnableLRUSerialInputs(lru);
    }

	
    // ---- PARTIAL MODE DISABLED ----
    
    if(mode == 1)
        DisplayPartialControls();
    else
        HidePartialControls();
    

    // Always hide start/end controls
   // HidePartialControls();
}

/*******************************************************************************
*  Function Name    = SetSelectedControls									   *
*  Class            = CSIPUPowerONPage          		                       *
*  Return Type      = void                                                     *
*  Parameters       = int iTestNumber				                           *
*  Visibility       = Public	                                               *
*  Description      = This function maintain MFD communication and com port	   *
*  configuratrion															   *
*******************************************************************************/

void CSIPUPowerONPage::SetSelectedControls(int iTestNumber)
{
	int iMajorTest, iMinorTest;
	CString strTmp, strMajorTest, strMinorTest; 
	
	UpdateData(true);

	strTmp.Format("%d", iTestNumber);

	if (iTestNumber < 1000)
	{
		strMajorTest = strTmp.Left(1);
		strMinorTest = strTmp.Right(2);
	
		iMajorTest = atoi(strMajorTest);
		iMinorTest = atoi(strMinorTest);

		m_List_Main_List.SetCurSel(iMajorTest - 1);
		m_List_Sub_Test.SetCurSel(iMinorTest - 1);

		m_List_Main_List.SetSel((iMajorTest - 1), TRUE);
		m_List_Sub_Test.SetSel((iMinorTest - 1), TRUE);
		//OnSelchangeListMainTest();
		UpdateListBoxData();
	}

	else
	{
		strMajorTest = strTmp.Left(2);
		strMinorTest = strTmp.Right(2);

		iMajorTest = atoi(strMajorTest);
		iMinorTest = atoi(strMinorTest);

		m_List_Main_List.SetCurSel(iMajorTest - 1);
		m_List_Sub_Test.SetCurSel(iMinorTest - 1);

		m_List_Main_List.SetSel((iMajorTest - 1), TRUE);
		m_List_Sub_Test.SetSel((iMinorTest - 1), TRUE);
		UpdateListBoxData();
		//OnSelchangeListMainTest();
	}
	m_List_Main_List.UpdateWindow();
	m_List_Sub_Test.UpdateWindow();

	UpdateData(false);
}
/*******************************************************************************
*  Function Name    = OnTimer												   *
*  Class            = CSIPUPowerONPage          		                       *
*  Return Type      = void                                                     *
*  Parameters       = UINT nIDEvent					                           *
*  Visibility       = Public	                                               *
*  Description      = This function maintain MFD communication and com port	   *
*  configuratrion															   *
*******************************************************************************/

void CSIPUPowerONPage::OnTimer(UINT_PTR nIDEvent) 
{
	//unsigned char ucReadData1,ucReadData2, ucReadData3, ucReadData4, ucWriteData;
	CString strTmp, in_csPort = "com1";
	BOOL bTrsFlag = true;

	
	CFormView::OnTimer(nIDEvent);
}

/*******************************************************************************
*  Function Name    = OnButPrintFile										   *
*  Class            = CSIPUPowerONPage          		                       *
*  Return Type      = void                                                     *
*  Parameters       = None							                           *
*  Visibility       = Public	                                               *
*  Description      = This function is used to select file for printing		   *
*******************************************************************************/

void CSIPUPowerONPage::OnButPrintFile() 
{
	static char BASED_CODE szFilter[] = "Binary Files(*.BIN)|*.BIN||";
	
	CFileDialog CmnCtlobj(true, "bin","", OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);

	if(CmnCtlobj.DoModal() == IDCANCEL)
	{
		return;
	}
	else
	{
		UpdateData(true);

		g_strFileName = CmnCtlobj.GetPathName();	
	}

	MyPrintJob job;
   job.Print();
	
	CWaitCursor UserInteractionLock;
	
}

/*******************************************************************************
*  Function Name    = LogTestStoppedInfo									   *
*  Class            = CSIPUPowerONPage          		                       *
*  Return Type      = void                                                     *
*  Parameters       = int iCurrentTest				                           *
*  Visibility       = Public	                                               *
*  Description      = This function is used to take log of paramters while test*
*  is stopped.																   * 
*******************************************************************************/

void CSIPUPowerONPage::LogTestStoppedInfo(int iCurrentTest)
{
	// variable declaration
	char chStopLogFile[150];
	unsigned long ulSysDir;
	CString strCurrentTest;
	CFile fptrStopLog;
		
	UpdateData(true);

	// create the log file name
	ulSysDir = GetSystemDirectory(chStopLogFile, 512);
	strcat(chStopLogFile,"\\TestStopLog.bin");

	//Open the binary log file
	if(!fptrStopLog.Open(chStopLogFile, CFile::typeBinary | CFile::modeWrite| CFile::modeCreate)) 
	{ 
		AfxMessageBox("Test Stop Log File Open Error");
		return;
	}
	
	// frame the data to be written to the log file m_Edit_DU_No
	strCurrentTest.Format("%d", iCurrentTest);
	strcpy(s_StopTestObj.m_strTestNumber, strCurrentTest);
	strcpy(s_StopTestObj.m_strReportFileName, g_chFileName);
	s_StopTestObj.iTestMode = m_Cambo_Mode.GetCurSel();

	s_StopTestObj.fStartTest = m_fEdit_TestStart;
	s_StopTestObj.fEndTest = m_fEdit_TestEnd;
	strcpy(s_StopTestObj.m_strDUSrNo, m_Edit_DU_No); 

	// write the framed data in the log file
	fptrStopLog.Write(&s_StopTestObj,sizeof(s_StopTestObj));
	fptrStopLog.Close();

	UpdateData(false);
}

/*******************************************************************************
*  Function Name    = CheckForTestStopped									   *
*  Class            = CSIPUPowerONPage          		                       *
*  Return Type      = int                                                      *
*  Parameters       = None				                                       *
*  Visibility       = Public	                                               *
*  Description      = This function is used to check case for stop the test	   * 
*  If command is for the stop the test then all paramtere will be reset.	   *
*******************************************************************************/

int CSIPUPowerONPage::CheckForTestStopped()
{
	// variable declaration
	char chStopLogFile[512];
	int iMboxRet;
	unsigned long ulSysDir;
	CString strMsg, strMake_TypeInfo;
	CString strCurrentTest, strTmpTestNum;
	CFile fptrStopLog;

	return 0;// remove this line if code malfunction
}

/*******************************************************************************
*  Function Name    = UpdateListBoxData										   *
*  Class            = CSIPUPowerONPage          		                       *
*  Return Type      = void                                                     *
*  Parameters       = None				                                       *
*  Visibility       = Public	                                               *
*  Description      = This function is used to display sub test of du CONFIG1 AND CONFIG2* 
*******************************************************************************/

void CSIPUPowerONPage::UpdateListBoxData()
{
    UpdateData(TRUE);

int lruIndex  = m_ctlCboDUType.GetCurSel();
int mainIndex = m_List_Main_List.GetCurSel();

if (lruIndex < 0 || mainIndex < 0)
    return;

m_List_Sub_Test.ResetContent();

MAIN_TEST &mainTest = LRU_Table[lruIndex].mainTests[mainIndex];

// 🔥 Fill subtests dynamically
for (int i = 0; i < mainTest.subCount; i++)
{
    m_List_Sub_Test.AddString(mainTest.subTests[i].name);
}

// 🔥 NEW LOGIC (convert float → integer ID)
if (mainTest.subCount > 0)
{
    int lruBase = (lruIndex + 1) * 100;   // SMFD=100, ISIS=200, ADC=300...

    int startID = lruBase + (int)(mainTest.subTests[0].id * 100) % 100;
    int endID   = lruBase + (int)(mainTest.subTests[mainTest.subCount - 1].id * 100) % 100;

    m_fEdit_TestStart = startID;
    m_fEdit_TestEnd   = endID;

    m_List_Sub_Test.SetCurSel(0);
}

UpdateData(FALSE);
}

/*******************************************************************************
*  Function Name    = ExecuteDUTestSequence()									   *
*  Class            = CSIPUPowerONPage          		                       *
*  Return Type      = void                                                     *
*  Parameters       = None				                                       *
*  Visibility       = Public	                                               *
*  Description      = This function is used to execute DUConfig1 test sequences.	   * 
*******************************************************************************/
#if 1
void CSIPUPowerONPage::ExecuteLRUTestSequence()
{   
    int mode = m_Cambo_Mode.GetCurSel();
	if(m_Cambo_Mode.GetCurSel() == 0)
		{
			strcpy(s_Index_Page.m_strExecMode,"Integration");
		}
		else
		{
			strcpy(s_Index_Page.m_strExecMode,"Standalone");
		}
    CString strTmpName;
	if(!ValidateUserInput(strTmpName))
        return;

    CFile fptr;
	g_nItem = 0;

    if(DynListCtrl != NULL)
    {
        DynListCtrl->DeleteAllItems();
    }

if(mode == MODE_INTEGRATION)
{
    SYSTEMTIME sysTime;
    GetLocalTime(&sysTime);

    g_nItem = 0;

    CString strFileName;

    strFileName.Format("%s_%02d_%02d_%04d_%02dH%02dM%02dS.bin",
        strTmpName,
        sysTime.wDay,
        sysTime.wMonth,
        sysTime.wYear,
        sysTime.wHour,
        sysTime.wMinute,
        sysTime.wSecond);

    // SAVE DIALOG
    CFileDialog dlg(FALSE, "bin", strFileName,
        OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
        "Binary Files (*.BIN)|*.BIN||",
        this);

    if(dlg.DoModal() == IDCANCEL)
        return;
	strcpy(g_chFileName, dlg.GetPathName());
    // CREATE FILE
    if(!fptr.Open(g_chFileName,
        CFile::typeBinary | CFile::modeWrite | CFile::modeCreate))
    {
        AfxMessageBox("File Creation Failed");
        return;
    }
	  
    // WRITE HEADER
	 strcpy(s_Index_Page.m_strSmfdFc,m_strSMFD1SNO);
	 strcpy(s_Index_Page.m_strSmfdRc,m_strSMFD2SNO);
	 strcpy(s_Index_Page.m_strMfdFc,m_strMFD1SNO);
	 strcpy(s_Index_Page.m_strMfdRc,m_strMFD2SNO);
	 strcpy(s_Index_Page.m_strIsisDuFc,m_strISIS_DU1_SNO);
	 strcpy(s_Index_Page.m_strIsisDuRc,m_strISIS_DU2_SNO);
	 strcpy(s_Index_Page.m_strIsisAdu,m_strISIS_ADU_SNO);
	 strcpy(s_Index_Page.m_strIsisAhrs,m_strISIS_AHRS_SNO);
	 strcpy(s_Index_Page.m_strIsisMms,m_strISIS_MGM_SNO);
	 strcpy(s_Index_Page.m_strAdc,m_strADC_SNO);
	 strcpy(s_Index_Page.m_strAhrs,m_strAHRS_SNO);
	 strcpy(s_Index_Page.m_strGps,m_strGPS_SNO);
	 strcpy(s_Index_Page.m_strVorrx,m_strNAV_SNO);
	 strcpy(s_Index_Page.m_strCdu,m_strNAV_SNO);
	 strcpy(s_Index_Page.m_strTacrx,m_strNAVTAC_SNO);
    strcpy(s_Index_Page.m_strFileName,g_chFileName);

    fptr.Write(&s_Index_Page, sizeof(s_Index_Page));

    // EXECUTE ALL TESTS
         ExecuteSMFDSequence(&fptr);
	if (!g_bStopRequested) ExecuteSMFDSequenceRC(&fptr);
    if (!g_bStopRequested) ExecuteISISSequence(&fptr);
    if (!g_bStopRequested) ExecuteADCSequence(&fptr);
    if (!g_bStopRequested) ExecuteAHRSTestSequence(&fptr);
    if (!g_bStopRequested) ExecuteGPSTestSequence(&fptr);
    if (!g_bStopRequested) ExecuteVORILSTACTestSequence(&fptr);

    fptr.Close();

    if (!g_bStopRequested)
        AfxMessageBox("Integration Test Completed");
}
else
{
   int iSelectedLRU = m_ctlCboDUType.GetCurSel();

    // Route execution based on selected LRU
    if(iSelectedLRU == 0)        // SMFD & MFD
    {
        
    

        int nSMFDMode = m_ComboSMFDMode.GetCurSel();

        switch(nSMFDMode)
        {
        case 0:     // Front Cockpit
		strcpy(s_Index_Page.m_strEquipment,"SMFD & MFD FC");
        strcpy(s_Index_Page.m_strSmfdFc,m_strSMFD1SNO);
		 strcpy(s_Index_Page.m_strMfdFc,m_strMFD1SNO);
            ExecuteSMFDSequence(NULL);
            break;

        case 1:     // Rear Cockpit
		strcpy(s_Index_Page.m_strEquipment,"SMFD & MFD RC");
	   strcpy(s_Index_Page.m_strSmfdRc,m_strSMFD2SNO);
        strcpy(s_Index_Page.m_strMfdRc,m_strMFD2SNO);
            ExecuteSMFDSequenceRC(NULL);
            break;

        case 2:     // Both
			strcpy(s_Index_Page.m_strEquipment,"SMFD & MFD");
		 strcpy(s_Index_Page.m_strSmfdFc,m_strSMFD1SNO);
		 strcpy(s_Index_Page.m_strMfdFc,m_strMFD1SNO);
		 strcpy(s_Index_Page.m_strSmfdRc,m_strSMFD2SNO);
        strcpy(s_Index_Page.m_strMfdRc,m_strMFD2SNO);
            ExecuteBothSMFD();
            break;
        }

        return;
    }
    else if(iSelectedLRU == 1)   // ISIS
    { strcpy(s_Index_Page.m_strEquipment,"ISIS");   
	 strcpy(s_Index_Page.m_strIsisDuFc,m_strISIS_DU1_SNO);
	 strcpy(s_Index_Page.m_strIsisDuRc,m_strISIS_DU2_SNO);
	 strcpy(s_Index_Page.m_strIsisAdu,m_strISIS_ADU_SNO);
	 strcpy(s_Index_Page.m_strIsisAhrs,m_strISIS_AHRS_SNO);
	 strcpy(s_Index_Page.m_strIsisMms,m_strISIS_MGM_SNO);
        ExecuteISISSequence(NULL);
        return;
    }
    else if(iSelectedLRU == 2)   // ADC
    { strcpy(s_Index_Page.m_strEquipment,"ADC");
		 strcpy(s_Index_Page.m_strAdc,m_strADC_SNO);
        ExecuteADCSequence(NULL);
        return;
    }
    else if(iSelectedLRU == 3)   // AHRS
    { strcpy(s_Index_Page.m_strEquipment,"AHRS");
		strcpy(s_Index_Page.m_strAhrs,m_strAHRS_SNO);
        ExecuteAHRSTestSequence(NULL);
        return;
    }
    else if(iSelectedLRU == 4)   // GPS
    {  strcpy(s_Index_Page.m_strEquipment,"GPS");
		 strcpy(s_Index_Page.m_strGps,m_strGPS_SNO);
        ExecuteGPSTestSequence(NULL);
        return;
    }
    else if(iSelectedLRU == 5)   // VOR/ILS
    { 
		strcpy(s_Index_Page.m_strEquipment,"VOR/ILS TACAN");
		strcpy(s_Index_Page.m_strVorrx,m_strNAV_SNO);
	strcpy(s_Index_Page.m_strCdu,m_strNAV_SNO);
	 strcpy(s_Index_Page.m_strTacrx,m_strNAVTAC_SNO);
    strcpy(s_Index_Page.m_strFileName,g_chFileName);
        ExecuteVORILSTACTestSequence(NULL);
        return;
    }
}
   
}
#endif

void CSIPUPowerONPage::ExecuteBothSMFD()
{
    CString strTmpName;

    if (!ValidateUserInput(strTmpName))
        return;

    UpdateData(TRUE);

    SYSTEMTIME st;
    ::GetLocalTime(&st);

    CString strCurrDateTime;
    CString strCurrDateTime1;

    strCurrDateTime.Format("%s_%d_%d_%d_%dH%dM%dS",
        strTmpName,
        st.wDay,
        st.wMonth,
        st.wYear,
        st.wHour,
        st.wMinute,
        st.wSecond);

    strCurrDateTime1.Format("%d/%d/%d",
        st.wDay,
        st.wMonth,
        st.wYear);

    CFileDialog dlg(
        FALSE,                              // Save As dialog
        "bin",
        strCurrDateTime,
        OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
        "Binary Files (*.BIN)|*.BIN||",
        this);

    if (dlg.DoModal() == IDCANCEL)
        return;

    strcpy(g_chFileName, dlg.GetPathName());

    CFile file;

    if (!file.Open(g_chFileName,
        CFile::modeCreate |
        CFile::modeWrite |
        CFile::typeBinary))
    {
        AfxMessageBox("File Creation Failed");
        return;
    }

    //------------------------------------------------------------------
    // Fill Header Information
    //------------------------------------------------------------------

    CSIPU_SDU_GndRigApp* pMainFrame =
        (CSIPU_SDU_GndRigApp*)AfxGetApp();

    ZeroMemory(&s_Index_Page, sizeof(s_Index_Page));

    strcpy(s_Index_Page.m_strOperator,
           pMainFrame->m_strLogin_UserName);

    strcpy(s_Index_Page.m_strSerialNo,
           m_Edit_DU_No);

    strcpy(s_Index_Page.m_strTestDescription,
           (LPCTSTR)m_edtStrTestDesc);

    sprintf(s_Index_Page.m_strDateTime,
            "%s",
            strCurrDateTime1);

    strcpy(s_Index_Page.m_strFileName,
           g_chFileName);

    strcpy(s_Index_Page.m_strExecMode,
           "Standalone");

    strcpy(s_Index_Page.m_strEquipment,
           "SMFD");

    //------------- FC Serial Numbers -----------------

    strcpy(s_Index_Page.m_strSmfdFc,
           m_strSMFD1SNO);

    strcpy(s_Index_Page.m_strMfdFc,
           m_strMFD1SNO);

    //------------- RC Serial Numbers -----------------

    strcpy(s_Index_Page.m_strSmfdRc,
           m_strSMFD2SNO);

    strcpy(s_Index_Page.m_strMfdRc,
           m_strMFD2SNO);

    //------------------------------------------------------------------
    // Write Header ONLY ONCE
    //------------------------------------------------------------------

    file.Write(&s_Index_Page, sizeof(s_Index_Page));

    //------------------------------------------------------------------
    // Execute FC Tests
    //------------------------------------------------------------------

    ExecuteSMFDSequence(&file);

    //------------------------------------------------------------------
    // Execute RC Tests
    //------------------------------------------------------------------

    ExecuteSMFDSequenceRC(&file);

    //------------------------------------------------------------------
    // Close File
    //------------------------------------------------------------------

    file.Close();

    AfxMessageBox("SMFD FC & RC Test Completed Successfully.");
}

void CSIPUPowerONPage::ExecuteISISSequence(CFile* pFile)
{
    BOOL bDlgFlag = FALSE;
    int iStartTest, iEndTest, iCurrentTest, iCurr_Pointer, iResult;
    CString strCurrDateTime, strCurrDateTime1, strTmpName;

    iTempCount = 0;
    if (!ValidateUserInput(strTmpName))
        return;

    CSIPU_SDU_GndRigApp *pMainFrame = (CSIPU_SDU_GndRigApp *)AfxGetApp();

    UpdateData(TRUE);

    SYSTEMTIME sysTime;
    ::GetLocalTime(&sysTime);

    strCurrDateTime.Format("%s_%d_%d_%d_%dH%dM%dS",
        strTmpName, sysTime.wDay, sysTime.wMonth, sysTime.wYear,
        sysTime.wHour, sysTime.wMinute, sysTime.wSecond);

    strCurrDateTime1.Format("%d/%d/%d",
        sysTime.wDay, sysTime.wMonth, sysTime.wYear);

    // ===== MODE FLAG =====
    // Integration mode (curSel == 0): keep existing numbering, major = 2, minor 201-236 (sequential)
    // Standalone mode (else): each sub-test category is its own major group, minor restarts at 01
    BOOL bIntegrationMode = (m_Cambo_Mode.GetCurSel() == 0);

    CFile fptr;
    CFile* pUseFile = pFile;

    if (pUseFile == NULL)
    {
        // 👉 STANDALONE FILE MODE → create file here
        CString strTmpName;

        if (!ValidateUserInput(strTmpName))
            return;

        CFileDialog dlg(TRUE, "bin", strCurrDateTime,
            OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
            "Binary Files(*.BIN)|*.BIN||", this);

        if (dlg.DoModal() == IDCANCEL)
            return;

        if (!fptr.Open(dlg.GetPathName(),
            CFile::typeBinary | CFile::modeWrite | CFile::modeCreate))
            return;
        strcpy(g_chFileName, dlg.GetPathName());
        pUseFile = &fptr;

        // write header
        strcpy(s_Index_Page.m_strOperator, pMainFrame->m_strLogin_UserName);
        strcpy(s_Index_Page.m_strTestDescription, (LPCTSTR)m_edtStrTestDesc);
        sprintf(s_Index_Page.m_strDateTime, "%s", strCurrDateTime1);
        strcpy(s_Index_Page.m_strFileName, g_chFileName);
        pUseFile->Write(&s_Index_Page, sizeof(s_Index_Page));
    }

    // ===== DIALOG OBJECTS =====
    VisualInspection m_Dlg_Visual_Inspctn;
    CDlg_ISIS_PWR m_Dlg_ISIS_PWR;
    CDlg_ISIS_SWCHK m_Dlg_ISIS_SWCHK;
    CDlg_ISIS_AHRS m_Dlg_ISIS_AHRS;
    CDlg_ISIS_ADUTest m_Dlg_ISIS_ADU;
    CDialog_ISIS_BRTCHK m_Dlg_ISIS_BRT;
    CDialog_ISIS_ALN   m_Dlg_ISIS_ALN;
    CDialog_ISIS_NAVMODE m_Dlg_ISIS_NAV;
    CDialog_ISIS_IBIT m_Dlg_ISIS_IBIT;

    // ===== TEST TABLE =====
    // idInteg      -> minor ID used in Integration mode (unchanged, 201-236 sequential)
    // idStandalone -> minor ID used in Standalone mode (restarts at 01 per category)
    // majStandalone-> major ID used in Standalone mode (1=Visual,2=Power,3=SW,4=IBIT,5=BRT,6=ALN,7=NAV,8=AHRS,9=ADU)
#define ADD_TEST(idInteg, idStandalone, majStandalone, majName, minName, dlgPtr, exp) \
    s_AllTestDetails[iTempCount].m_ucMajor_Test_ID  = bIntegrationMode ? 2 : majStandalone; \
    s_AllTestDetails[iTempCount].m_uiMinor_Test_ID  = bIntegrationMode ? idInteg : idStandalone; \
    s_AllTestDetails[iTempCount].m_strMajor_Test_Name = majName; \
    s_AllTestDetails[iTempCount].m_strMinor_Test_Name = minName; \
    s_AllTestDetails[iTempCount].m_Procedure_Dlg = dlgPtr; \
    s_AllTestDetails[iTempCount].m_strExpected = exp; \
    iTempCount++;

    // VISUAL -> Integration 201-209 | Standalone 101-109
    ADD_TEST(201,101,1,"Visual Inspection","Display Unit FC PN",&m_Dlg_Visual_Inspctn,"IS2100000000");
    ADD_TEST(202,102,1,"Visual Inspection","Display Unit RC PN",&m_Dlg_Visual_Inspctn,"IS2100000000");
    ADD_TEST(203,103,1,"Visual Inspection","Air Data Unit PN",&m_Dlg_Visual_Inspctn,"AN-014-ADU-V00");
    ADD_TEST(204,104,1,"Visual Inspection","Magnetometer PN",&m_Dlg_Visual_Inspctn,"AN-015-MMS-V00");
    ADD_TEST(205,105,1,"Visual Inspection","AHRS PN",&m_Dlg_Visual_Inspctn,"1901400000000");
    ADD_TEST(206,106,1,"Visual Inspection","Any Corrosion",&m_Dlg_Visual_Inspctn,"NO");
    ADD_TEST(207,107,1,"Visual Inspection","Any foreign Material",&m_Dlg_Visual_Inspctn,"NO");
    ADD_TEST(208,108,1,"Visual Inspection","Loose Screws",&m_Dlg_Visual_Inspctn,"NO");
    ADD_TEST(209,109,1,"Visual Inspection","Bend Pins",&m_Dlg_Visual_Inspctn,"NO");

    // POWER -> Integration 210-213 | Standalone 201-204
    ADD_TEST(210,201,2,"Power","Current Rating ISIS-DU FC",&m_Dlg_ISIS_PWR,"< 1.08 A");
    ADD_TEST(211,202,2,"Power","Current Rating ISIS-DU RC",&m_Dlg_ISIS_PWR,"< 1.08 A");
    ADD_TEST(212,203,2,"Power","Current Rating ISIS ADU",&m_Dlg_ISIS_PWR,"< 0.3 A");
    ADD_TEST(213,204,2,"Power","Current Rating ISIS AHRS",&m_Dlg_ISIS_PWR,"< 1 A");

    // SOFTWARE -> Integration 214-221 | Standalone 301-308
    ADD_TEST(214,301,3,"Software","ISIS-DU FC MPM Version",&m_Dlg_ISIS_SWCHK,"01.00");
    ADD_TEST(215,302,3,"Software","ISIS-DU FC MPM Checksum",&m_Dlg_ISIS_SWCHK,"0xCA347B86");
    ADD_TEST(216,303,3,"Software","ISIS-DU FC BLGM Version",&m_Dlg_ISIS_SWCHK,"01.00");
    ADD_TEST(217,304,3,"Software","ISIS-DU FC BLGM Checksum",&m_Dlg_ISIS_SWCHK,"0x43760D0A");
    ADD_TEST(218,305,3,"Software","ISIS-DU RC MPM Version",&m_Dlg_ISIS_SWCHK,"01.00");
    ADD_TEST(219,306,3,"Software","ISIS-DU RC MPM Checksum",&m_Dlg_ISIS_SWCHK,"0xCA347B86");
    ADD_TEST(220,307,3,"Software","ISIS-DU RC BLGM Version",&m_Dlg_ISIS_SWCHK,"01.00");
    ADD_TEST(221,308,3,"Software","ISIS-DU RC BLGM Checksum",&m_Dlg_ISIS_SWCHK,"0x43760D0A");

    // IBIT -> Integration 222-223 | Standalone 401-402
    ADD_TEST(222,401,4,"IBIT Checks","ISIS-DU FC",&m_Dlg_ISIS_IBIT,"Operational");
    ADD_TEST(223,402,4,"IBIT Checks","ISIS-DU RC",&m_Dlg_ISIS_IBIT,"Operational");

    // BRIGHTNESS -> Integration 224-225 | Standalone 501-502
    ADD_TEST(224,501,5,"Brightness and Set knob Checks","ISIS-DU FC",&m_Dlg_ISIS_BRT,"Operational");
    ADD_TEST(225,502,5,"Brightness and Set knob Checks","ISIS-DU RC",&m_Dlg_ISIS_BRT,"Operational");

    // ALIGNMENT -> Integration 226-227 | Standalone 601-602
    ADD_TEST(226,601,6,"Alignment mode Checks","ISIS-DU FC",&m_Dlg_ISIS_ALN,"Operational");
    ADD_TEST(227,602,6,"Alignment mode Checks","ISIS-DU RC",&m_Dlg_ISIS_ALN,"Operational");

    // NAVIGATION -> Integration 228-229 | Standalone 701-702
    ADD_TEST(228,701,7,"Navigation mode Checks","ISIS-DU FC",&m_Dlg_ISIS_NAV,"Operational");
    ADD_TEST(229,702,7,"Navigation mode Checks","ISIS-DU RC",&m_Dlg_ISIS_NAV,"Operational");

    // AHRS -> Integration 230-232 | Standalone 801-803
    ADD_TEST(230,801,8,"AHRS","Roll FC",&m_Dlg_ISIS_AHRS,"OK");
    ADD_TEST(231,802,8,"AHRS","Pitch FC",&m_Dlg_ISIS_AHRS,"OK");
    ADD_TEST(232,803,8,"AHRS","Heading FC",&m_Dlg_ISIS_AHRS,"OK");
	ADD_TEST(233,804,8,"AHRS","Roll RC",&m_Dlg_ISIS_AHRS,"OK");
    ADD_TEST(234,805,8,"AHRS","Pitch RC",&m_Dlg_ISIS_AHRS,"OK");
    ADD_TEST(235,806,8,"AHRS","Heading RC",&m_Dlg_ISIS_AHRS,"OK");

    // ADU -> Integration 233-236 | Standalone 901-904
    ADD_TEST(236,901,9,"ADU","Airspeed FC",&m_Dlg_ISIS_ADU,"192±5");
    ADD_TEST(237,902,9,"ADU","Altitude FC",&m_Dlg_ISIS_ADU,"9980±30");
    ADD_TEST(238,903,9,"ADU","Mach FC",&m_Dlg_ISIS_ADU,"0.37± 0.012 M");
    ADD_TEST(239,904,9,"ADU","Vertical Speed FC",&m_Dlg_ISIS_ADU,"Operational");
	ADD_TEST(240,905,9,"ADU","Airspeed RC",&m_Dlg_ISIS_ADU,"192±5");
    ADD_TEST(241,906,9,"ADU","Altitude RC",&m_Dlg_ISIS_ADU,"9980±30");
    ADD_TEST(242,907,9,"ADU","Mach RC",&m_Dlg_ISIS_ADU,"0.37± 0.012 M");
    ADD_TEST(243,908,9,"ADU","Vertical Speed RC",&m_Dlg_ISIS_ADU,"Operational");

#undef ADD_TEST

    // ===== EXECUTION RANGE =====
    if (bIntegrationMode)
    {
        iStartTest = 200;
        iEndTest   = 299;   // unchanged behaviour
    }
    else
    {
        iStartTest = 100;
        iEndTest   = 999;   // sweep major groups 1-9
    }

    // ================= EXECUTION =================
    for (iCurrentTest = iStartTest; iCurrentTest <= iEndTest; iCurrentTest++)
    {
		if (g_bStopRequested)
			break;
        if (iCurrentTest % 100 <= DU_ATP_MAX_NO_OF_SUBTEST)
        {
            for (iCurr_Pointer = 0; iCurr_Pointer < iTempCount; iCurr_Pointer++)
            {
                if (iCurrentTest == s_AllTestDetails[iCurr_Pointer].m_uiMinor_Test_ID)
                {
                    g_str_Measured_Val = "";
                    g_str_Test_Result  = "";

                    s_Curr_Test_Result.m_uiMinor_Test_ID = iCurrentTest;
                    strcpy(s_Curr_Test_Result.m_strMajorTestName,
                           s_AllTestDetails[iCurr_Pointer].m_strMajor_Test_Name);
                    strcpy(s_Curr_Test_Result.m_strMinorTestName,
                           s_AllTestDetails[iCurr_Pointer].m_strMinor_Test_Name);
                    strcpy(s_Curr_Test_Result.m_strSpec,
                           s_AllTestDetails[iCurr_Pointer].m_strExpected);

                    SetSelectedControls(iCurrentTest);

                    if (!bDlgFlag)
                    {
                        iResult = ShowTestProcedure(s_AllTestDetails[iCurr_Pointer].m_Procedure_Dlg);
						if (g_bStopRequested)
							break;
                        bDlgFlag = TRUE;
                    }

                    // switch keyed on ARRAY POSITION (mode-independent),
                    // not on the raw test ID
                    switch (iCurr_Pointer)
                    {
                    case 0:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_Visual_Inspctn.m_strProductLabel);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_Visual_Inspctn.m_strStatusProductLabel);
                        break;
                    case 1:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_Visual_Inspctn.m_strProductLabelRC);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_Visual_Inspctn.m_strStatusProductLabelRC);
                        break;
                    case 2:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_Visual_Inspctn.m_strSrNoLabel);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_Visual_Inspctn.m_strStatusSrNoLabel);
                        break;
                    case 3:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_Visual_Inspctn.m_strESDLabel);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_Visual_Inspctn.m_strStatusESDLabel);
                        break;
                    case 4:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_Visual_Inspctn.m_strRearMarking);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_Visual_Inspctn.m_strStatusRearMarking);
                        break;
                    case 5:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_Visual_Inspctn.m_strISISDamage);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_Visual_Inspctn.m_strStatusISISDamage);
                        break;
                    case 6:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_Visual_Inspctn.m_strISISScratches);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_Visual_Inspctn.m_strStatusISISScratches);
                        break;
                    case 7:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_Visual_Inspctn.m_strISISScrews);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_Visual_Inspctn.m_strStatusISISScrews);
                        break;
                    case 8:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_Visual_Inspctn.m_strISISPins);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_Visual_Inspctn.m_strStatusISISPins);
                        bDlgFlag = FALSE;   // last Visual
                        break;

                    case 9:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_PWR.m_strCurrent28V);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_PWR.m_strStatusCurrent28V);
                        break;
                    case 10:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_PWR.m_strMeasISISDURCPWR);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_PWR.m_strStatusCurrentISISDURC);
                        break;
                    case 11:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_PWR.m_strMeasISISADUPWR);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_PWR.m_strStatusCurrentISISADU);
                        break;
                    case 12:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_PWR.m_strMeasISISAHRSPWR);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_PWR.m_strStatusCurrentISISAHRS);
                        bDlgFlag = FALSE;   // last Power
                        break;

                    case 13:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_SWCHK.m_strISISMPMVer);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_SWCHK.m_strStatusISISMPMVer);
                        break;
                    case 14:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_SWCHK.m_strISISMPMCSum);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_SWCHK.m_strStatusISISMPMCSum);
                        break;
                    case 15:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_SWCHK.m_strISISSWVer);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_SWCHK.m_strStatusISISSWVer);
                        break;
                    case 16:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_SWCHK.m_strISISSWCsum);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_SWCHK.m_strStatusISISSWCsum);
                        break;
                    case 17:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_SWCHK.m_strISISRCMPMVer);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_SWCHK.m_strStatusISISRCMPMVer);
                        break;
                    case 18:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_SWCHK.m_strISISRCMPMCSum);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_SWCHK.m_strStatusISISRCMPMCSum);
                        break;
                    case 19:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_SWCHK.m_strISISRCSWVer);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_SWCHK.m_strStatusISISRCSWVer);
                        break;
                    case 20:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_SWCHK.m_strISISRCSWCsum);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_SWCHK.m_strStatusISISRCSWCsum);
                        bDlgFlag = FALSE;   // last Software
                        break;

                    case 21:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_IBIT.m_strIsisFCIBIT);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_IBIT.m_strStatusIsisFCIBIT);
                        break;
                    case 22:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_IBIT.m_strIsisRCIBIT);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_IBIT.m_strStatusIsisRCIBIT);
                        bDlgFlag = FALSE;   // last IBIT
                        break;

                    case 23:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_BRT.m_strIsisFCBRT);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_BRT.m_strStatusIsisFCBRT);
                        break;
                    case 24:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_BRT.m_strIsisRCBRT);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_BRT.m_strStatusIsisRCBRT);
                        bDlgFlag = FALSE;   // last Brightness
                        break;

                    case 25:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_ALN.m_strIsisFCALN);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_ALN.m_strStatusIsisFCALN);
                        break;
                    case 26:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_ALN.m_strIsisRCALN);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_ALN.m_strStatusIsisRCALN);
                        bDlgFlag = FALSE;   // last Alignment
                        break;

                    case 27:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_NAV.m_strIsisFCNAVMODE);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_NAV.m_strStatusIsisFCNAVMODE);
                        break;
                    case 28:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_NAV.m_strIsisRCNAVMODE);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_NAV.m_strStatusIsisRCNAVMODE);
                        bDlgFlag = FALSE;   // last Navigation
                        break;

                    case 29:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_AHRS.m_strISISRoll);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_AHRS.m_strStatusISISRoll);
                        break;
                    case 30:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_AHRS.m_strISISPitch);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_AHRS.m_strStatusISISPitch);
                        break;
                    case 31:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_AHRS.m_strISISHeading);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_AHRS.m_strStatusISISHeading);
                        break;
					 case 32:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_AHRS.m_strISISRollRC);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_AHRS.m_strStatusISISRollRC);
                        break;
                    case 33:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_AHRS.m_strISISPitchRC);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_AHRS.m_strStatusISISPitchRC);
                        break;
                    case 34:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_AHRS.m_strISISHeadingRC);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_AHRS.m_strStatusISISHeadingRC);
                        bDlgFlag = FALSE;   // last AHRS
                        break;

                    case 35:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_ADU.m_strISISAirspeed);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_ADU.m_strStatusISISAirspeed);
                        break;
                    case 36:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_ADU.m_strISISAltitude);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_ADU.m_strStatusISISAltitude);
                        break;
                    case 37:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_ADU.m_strISISMach);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_ADU.m_strStatusISISMach);
                        break;
                    case 38:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_ADU.m_strISISVerticalRC);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_ADU.m_strStatusISISVerticalRC);
                        //bDlgFlag = FALSE;   // last ADU
                        break;
					 case 39:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_ADU.m_strISISAirspeedRC);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_ADU.m_strStatusISISAirspeedRC);
                        break;
                    case 40:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_ADU.m_strISISAltitudeRC);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_ADU.m_strStatusISISAltitudeRC);
                        break;
                    case 41:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_ADU.m_strISISMachRC);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_ADU.m_strStatusISISMachRC);
                        break;
                    case 42:
                        strcpy(s_Curr_Test_Result.m_strMeasuered_Val, m_Dlg_ISIS_ADU.m_strISISVerticalRC);
                        strcpy(s_Curr_Test_Result.m_strTestStatus,  m_Dlg_ISIS_ADU.m_strStatusISISVerticalRC);
                        bDlgFlag = FALSE;   // last ADU
                        break;
                    }

                    pUseFile->Write(&s_Curr_Test_Result, sizeof(s_Curr_Test_Result));
                    FillListCtrl(*DynListCtrl);
                }
            }
        }
        else
        {
            iCurrentTest = ((iCurrentTest / 100) + 1) * 100;
        }
    }

    if (pFile == NULL)
    {
        fptr.Close();
    }
}

void CSIPUPowerONPage::ExecuteSMFDSequence(CFile* pFile)
{
    BOOL bDlgFlag = FALSE;
    int iStartTest, iEndTest, iCurrentTest, iCurr_Pointer, iResult;
     CString strTmpName;
	 int mode = m_Cambo_Mode.GetCurSel();
	 
    iTempCount = 0;

    if (!ValidateUserInput(strTmpName))
        return;
	 CSIPU_SDU_GndRigApp *pMainFrame = (CSIPU_SDU_GndRigApp *)AfxGetApp();

    UpdateData(TRUE);
	CString strCurrDateTime, strCurrDateTime1 ;
    SYSTEMTIME sysTime;
    ::GetLocalTime(&sysTime);

    strCurrDateTime.Format("%s_%d_%d_%d_%dH%dM%dS",
        strTmpName, sysTime.wDay, sysTime.wMonth, sysTime.wYear,
        sysTime.wHour, sysTime.wMinute, sysTime.wSecond);

    strCurrDateTime1.Format("%d/%d/%d",
        sysTime.wDay, sysTime.wMonth, sysTime.wYear);
 

    CFile fptr;
    CFile* pUseFile = pFile;

    // -------- STANDALONE FILE CREATION --------
    if (pUseFile == NULL)
    {
         // 👉 STANDALONE FILE MODE → create file here
        CString strTmpName;

        if (!ValidateUserInput(strTmpName))
            return;

        CFileDialog dlg(TRUE, "bin", strCurrDateTime,
            OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
            "Binary Files(*.BIN)|*.BIN||", this);

        if (dlg.DoModal() == IDCANCEL)
            return;

        if (!fptr.Open(dlg.GetPathName(),
            CFile::typeBinary | CFile::modeWrite | CFile::modeCreate))
            return;
        strcpy(g_chFileName, dlg.GetPathName());
        pUseFile = &fptr;

        // write header
        strcpy(s_Index_Page.m_strOperator, pMainFrame->m_strLogin_UserName);
        strcpy(s_Index_Page.m_strTestDescription, (LPCTSTR)m_edtStrTestDesc);
        sprintf(s_Index_Page.m_strDateTime, "%s", strCurrDateTime1);
        strcpy(s_Index_Page.m_strFileName, g_chFileName);
        pUseFile->Write(&s_Index_Page, sizeof(s_Index_Page));

    }

    // -------- DIALOG OBJECTS --------
    CDialog_Smfd_Visual dlgSmfdVisual;
    CDialog_SMFD_PWR    dlgSmfdPwr;
    CDialog_SMFD_SW     dlgSmfdSW;
    CDialog_Smfd_Analog dlgSmfdAnalog;
    CDialog_Smfd_Fuel   dlgSmfdFuel;
    CDialog_Smfd_Rev_Page dlgSmfdRev;
	CDialog_Smfd_Analog2 dlgSmfdAnalog2;
	CDialogSmfd_ADC     dlgSmfdADC;
    CDialogSmfdAHRS     dlgSmfdAHRS;
    CDialog_Smfd_VORILS dlgSmfdVORILS;
    CDialogSmfd_Tacan   dlgSmfdTACAN;
    CDialog_Smfd_Discrete dlgSmfdDiscrete;
    CDialog_SMFD_GPS dlgSmfdGPS;
	//Analog
	CDialog_SMFD_FC_ANBV dlgSmfdANBV;
   CDialog_SMFD_FC_ANCL  dlgSmfdANCL;
CDialog_SMFD_FC_ANCT    dlgSmfdANCT;
 CDialog_SMFD_FC_ANEB   dlgSmfdANEB;
 CDialog_SMFD_FC_ANES dlgSmfdANES;
 CDialog_SMFD_FC_ANFTL dlgSmfdANFTL;
 CDialog_SMFD_FC_ANFTR dlgSmfdANFTR;
   CDialog_SMFD_FC_ANGEOP dlgSmfdANGEOP;
    CDialog_SMFD_FC_ANGV  dlgSmfdANGV;
    CDialog_SMFD_FC_ANLBP  dlgSmfdANLBP;
    CDialog_SMFD_FC_ANRBP  dlgSmfdANRBP;
  CDialog_SMFD_FC_ATP      dlgSmfdANATP;
   CDialog_SMFD_FC_ET     dlgSmfdANET;
   CDialog_SMFD_FC_ETP    dlgSmfdANETP;
   CDialog_SMFD_FC_FP3    dlgSmfdANFP3;
    CDialog_SMFD_FC_FP4    dlgSmfdANFP4;
     CDialog_SMFD_FC_HPE    dlgSmfdANHPE;
     CDialog_SMFD_FC_RTP     dlgSmfdANRTP;
	 //Analog
    // -------- TEST TABLE --------
   BOOL bIntegrationMode = (m_Cambo_Mode.GetCurSel() == 0);

#define ADD_TEST(idInteg,idStandalone,majStandalone,majName,minName,dlgPtr,exp)\
    s_AllTestDetails[iTempCount].m_ucMajor_Test_ID = bIntegrationMode ? 1 : majStandalone;\
    s_AllTestDetails[iTempCount].m_uiMinor_Test_ID = bIntegrationMode ? idInteg : idStandalone;\
    s_AllTestDetails[iTempCount].m_strMajor_Test_Name = majName;\
    s_AllTestDetails[iTempCount].m_strMinor_Test_Name = minName;\
    s_AllTestDetails[iTempCount].m_Procedure_Dlg = dlgPtr;\
    s_AllTestDetails[iTempCount].m_strExpected = exp;\
    iTempCount++;

// -------- VISUAL --------
ADD_TEST(101,101,1,"SMFD FC Visual","MFD FC Part Number",&dlgSmfdVisual,"100-604077-000");
ADD_TEST(102,102,1,"SMFD FC Visual","SMFD FC Part Number",&dlgSmfdVisual,"100-604078-000");
ADD_TEST(103,103,1,"SMFD FC Visual","Damage Check",&dlgSmfdVisual,"NO");
ADD_TEST(104,104,1,"SMFD FC Visual","Scratches Check",&dlgSmfdVisual,"NO");
ADD_TEST(105,105,1,"SMFD FC Visual","Screws Check",&dlgSmfdVisual,"NO");
ADD_TEST(106,106,1,"SMFD FC Visual","Pins Check",&dlgSmfdVisual,"NO");

// -------- POWER --------
ADD_TEST(201,201,2,"SMFD FC Power","SMFD FC Current",&dlgSmfdPwr,"< 3A");
ADD_TEST(202,202,2,"SMFD FC Power","MFD FC Current",&dlgSmfdPwr,"< 1.8A");

// -------- SOFTWARE --------
ADD_TEST(301,301,3,"SMFD FC Software","Operational Software",&dlgSmfdSW,"E73D5822");

// -------- ANALOG --------
ADD_TEST(401,401,4,"SMFD FC Analog","Oil Temp",&dlgSmfdAnalog,"60±2 °C");                                        
ADD_TEST(402,402,4,"SMFD FC Analog","Oil Pressure",&dlgSmfdANGEOP,"40±3 psi");
ADD_TEST(403,403,4,"SMFD FC Analog","Torque",&dlgSmfdANET,"1740±4 ft-lb");
ADD_TEST(404,404,4,"SMFD FC Analog","Rudder",&dlgSmfdANRTP,"Nose at centre white line");
ADD_TEST(405,405,4,"SMFD FC Analog","Elevator",&dlgSmfdANETP,"Nose at green line & -1.2 deg");
ADD_TEST(406,406,4,"SMFD FC Analog","Aileron",&dlgSmfdANATP,"Wing at green line");
ADD_TEST(407,407,4,"SMFD FC Analog","Flap 3V",&dlgSmfdANFP3,"FLAPS 20 in Green");
ADD_TEST(408,408,4,"SMFD FC Analog","Flap 4V",&dlgSmfdANFP4,"Flaps 30 in Yellow");
ADD_TEST(409,409,4,"SMFD FC Analog","Generator Volt",&dlgSmfdANGV,"28±1 V");
ADD_TEST(410,410,4,"SMFD FC Analog","Battery Volt",&dlgSmfdANBV,"28±1 V");
ADD_TEST(411,411,4,"SMFD FC Analog","Current Load",&dlgSmfdANCL,"200±10 A");

// -------- ANALOG2 --------
ADD_TEST(412,412,4,"SMFD FC Analog","Hydraulic Main Pressure",&dlgSmfdAnalog2,"2930±20 psi");
ADD_TEST(413,413,4,"SMFD FC Analog","Hydraulic Emergency Pressure",&dlgSmfdANHPE,"3330±20 psi");
ADD_TEST(414,414,4,"SMFD FC Analog","Emergency Brake Pressure",&dlgSmfdANEB,"1300±15 psi");
ADD_TEST(415,415,4,"SMFD FC Analog","LH Brake Pressure",&dlgSmfdANLBP,"1200±15 psi");
ADD_TEST(416,416,4,"SMFD FC Analog","RH Brake Pressure",&dlgSmfdANRBP,"1200±15 psi");
ADD_TEST(417,417,4,"SMFD FC Analog","Engine Speed",&dlgSmfdANES,"79±2 rpm");
ADD_TEST(418,418,4,"SMFD FC Analog","Fuel LH",&dlgSmfdANFTL,"168±5 lb");
ADD_TEST(419,419,4,"SMFD FC Analog","Fuel RH",&dlgSmfdANFTR,"168±5 lb");
ADD_TEST(420,420,4,"SMFD FC Analog","Collector Tank Fuel",&dlgSmfdANCT,"183±5 lb");

// -------- FUEL --------
ADD_TEST(501,501,5,"SMFD FC Fuel Flow Check","Fuel Flow",&dlgSmfdFuel,"300 lb/hr");

// -------- DISCRETE --------
ADD_TEST(601,601,6,"SMFD FC Discrete","Bus Tie",&dlgSmfdDiscrete,"Operational");
ADD_TEST(602,602,6,"SMFD FC Discrete","Canopy",&dlgSmfdDiscrete,"Operational");
ADD_TEST(603,603,6,"SMFD FC Discrete","ECS OFF",&dlgSmfdDiscrete,"Operational");
ADD_TEST(604,604,6,"SMFD FC Discrete","ECS Over Pressure",&dlgSmfdDiscrete,"Operational");
ADD_TEST(605,605,6,"SMFD FC Discrete","AOA Mute",&dlgSmfdDiscrete,"Operational");
ADD_TEST(606,606,6,"SMFD FC Discrete","Alarm Mute",&dlgSmfdDiscrete,"Operational");
ADD_TEST(607,607,6,"SMFD FC Discrete","Demist",&dlgSmfdDiscrete,"Operational");
ADD_TEST(608,608,6,"SMFD FC Discrete","Start Switch",&dlgSmfdDiscrete,"Operational");

// -------- REVISION --------
ADD_TEST(701,701,7,"SMFD FC Revisionary Page Check","Revision Page",&dlgSmfdRev,"Operational");

// -------- ADC --------
ADD_TEST(801,801,8,"SMFD FC ADC","Altitude (203)",&dlgSmfdADC,"5000 ft");
ADD_TEST(802,802,8,"SMFD FC ADC","Mach (205)",&dlgSmfdADC,"0.5 M");
ADD_TEST(803,803,8,"SMFD FC ADC","Airspeed (206)",&dlgSmfdADC,"100 knots");
ADD_TEST(804,804,8,"SMFD FC ADC","Altitude Rate (212)",&dlgSmfdADC,"1500 ft/min");
ADD_TEST(805,805,8,"SMFD FC ADC","Static Air Temp (213)",&dlgSmfdADC,"25 °C");
ADD_TEST(806,806,8,"SMFD FC ADC","True Airspeed (210)",&dlgSmfdADC,"100 knots");

// -------- AHRS --------
ADD_TEST(901,901,9,"SMFD FC AHRS","Heading (320)",&dlgSmfdAHRS,"60 Deg");
ADD_TEST(902,902,9,"SMFD FC AHRS","Pitch (324)",&dlgSmfdAHRS,"20 Deg");
ADD_TEST(903,903,9,"SMFD FC AHRS","Roll (325)",&dlgSmfdAHRS,"10 Deg");
ADD_TEST(904,904,9,"SMFD FC AHRS","Yaw Rate (330)",&dlgSmfdAHRS,"Valid");
ADD_TEST(905,905,9,"SMFD FC AHRS","Lat Acc (332)",&dlgSmfdAHRS,"Valid");
ADD_TEST(906,906,9,"SMFD FC AHRS","Norm Acc (333)",&dlgSmfdAHRS,"6 g");

// -------- VOR/ILS --------
ADD_TEST(1001,1001,10,"SMFD FC VOR/ILS","VOR Frequency",&dlgSmfdVORILS,"108.00 MHz");
ADD_TEST(1002,1002,10,"SMFD FC VOR/ILS","ILS Frequency",&dlgSmfdVORILS,"108.10 MHz");
ADD_TEST(1003,1003,10,"SMFD FC VOR/ILS","VOR Bearing",&dlgSmfdVORILS,"90");
ADD_TEST(1004,1004,10,"SMFD FC VOR/ILS","Localizer",&dlgSmfdVORILS,"OK");
ADD_TEST(1005,1005,10,"SMFD FC VOR/ILS","Glide Slope",&dlgSmfdVORILS,"OK");

// -------- TACAN --------
ADD_TEST(1101,1101,11,"SMFD FC TACAN","Control Word (145)",&dlgSmfdTACAN,"12X");
ADD_TEST(1102,1102,11,"SMFD FC TACAN","Distance (201)",&dlgSmfdTACAN,"300 KM");
ADD_TEST(1103,1103,11,"SMFD FC TACAN","Bearing (222)",&dlgSmfdTACAN,"90 deg");

// -------- GPS --------
ADD_TEST(1201,1201,12,"SMFD FC GPS","Ground Speed",&dlgSmfdGPS,"1000 KM");
ADD_TEST(1202,1202,12,"SMFD FC GPS","True Track",&dlgSmfdGPS,"90 deg");
ADD_TEST(1203,1203,12,"SMFD FC GPS","Magnetic Track",&dlgSmfdGPS,"90 deg");
ADD_TEST(1204,1204,12,"SMFD FC GPS","GPS Time",&dlgSmfdGPS,"Valid");

#undef ADD_TEST

 



    iStartTest = 100;
    iEndTest   = 1299;


    // -------- EXECUTION LOOP --------
for(iCurrentTest = iStartTest;iCurrentTest <= iEndTest;iCurrentTest++)
{
	if (g_bStopRequested)
		break;
    if(iCurrentTest % 100 <= DU_ATP_MAX_NO_OF_SUBTEST)
    {
        for(iCurr_Pointer = 0;
            iCurr_Pointer < iTempCount;
            iCurr_Pointer++)
        {
            if(iCurrentTest ==
               s_AllTestDetails[iCurr_Pointer].m_uiMinor_Test_ID)
            {
                s_Curr_Test_Result.m_uiMinor_Test_ID = iCurrentTest;

                strcpy(s_Curr_Test_Result.m_strMajorTestName,
                       s_AllTestDetails[iCurr_Pointer].m_strMajor_Test_Name);

                strcpy(s_Curr_Test_Result.m_strMinorTestName,
                       s_AllTestDetails[iCurr_Pointer].m_strMinor_Test_Name);

                strcpy(s_Curr_Test_Result.m_strSpec,
                       s_AllTestDetails[iCurr_Pointer].m_strExpected);
				 SetSelectedControls(iCurrentTest);

                    // cases go here
					switch(iCurr_Pointer)
{
    // ---------- VISUAL ----------
    case 0: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdVisual,FALSE,pUseFile); break;
    case 1: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdVisual,FALSE,pUseFile); break;
    case 2: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdVisual,FALSE,pUseFile); break;
    case 3: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdVisual,FALSE,pUseFile); break;
    case 4: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdVisual,FALSE,pUseFile); break;
    case 5: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdVisual,TRUE ,pUseFile); break;

    // ---------- POWER ----------
    case 6: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdPwr,FALSE,pUseFile); break;
    case 7: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdPwr,TRUE ,pUseFile); break;

    // ---------- SOFTWARE ----------
    case 8: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdSW,TRUE,pUseFile); break;

    // ---------- ANALOG ----------

    case 9:  ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdAnalog,TRUE,pUseFile); break;
    case 10: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANGEOP,TRUE,pUseFile); break;
    case 11: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANET,TRUE,pUseFile); break;
    case 12: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANRTP,TRUE,pUseFile); break;
    case 13: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANETP,TRUE,pUseFile); break;
    case 14: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANATP,TRUE,pUseFile); break;
    case 15: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANFP3,TRUE,pUseFile); break;
    case 16: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANFP4,TRUE,pUseFile); break;
    case 17: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANGV,TRUE,pUseFile); break;
    case 18: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANBV,TRUE,pUseFile); break;
    case 19: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANCL,TRUE ,pUseFile); break;

    // ---------- ANALOG2 ----------
    case 20: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdAnalog2,TRUE,pUseFile); break;
    case 21: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANHPE,TRUE,pUseFile); break;
    case 22: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANEB,TRUE,pUseFile); break;
    case 23: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANLBP,TRUE,pUseFile); break;
    case 24: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANRBP,TRUE,pUseFile); break;
    case 25: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANES,TRUE,pUseFile); break;
    case 26: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANFTL,TRUE,pUseFile); break;
    case 27: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANFTR,TRUE,pUseFile); break;
    case 28: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANCT,TRUE ,pUseFile); break;

    // ---------- FUEL ----------
    case 29: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdFuel,TRUE,pUseFile); break;

    // ---------- DISCRETE ----------
    case 30: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdDiscrete,FALSE,pUseFile); break;
    case 31: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdDiscrete,FALSE,pUseFile); break;
    case 32: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdDiscrete,FALSE,pUseFile); break;
    case 33: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdDiscrete,FALSE,pUseFile); break;
    case 34: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdDiscrete,FALSE,pUseFile); break;
    case 35: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdDiscrete,FALSE,pUseFile); break;
    case 36: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdDiscrete,FALSE,pUseFile); break;
    case 37: ProcessTest(iCurrentTest,bDlgFlag,iResult,&dlgSmfdDiscrete,TRUE,pUseFile); break;

   // ---------- REV ----------
case 38:
    ProcessTest(iCurrentTest, bDlgFlag, iResult, &dlgSmfdRev, TRUE, pUseFile);
    break;

// ---------- ADC ----------
case 39:
    ProcessTest(iCurrentTest, bDlgFlag, iResult, &dlgSmfdADC, FALSE, pUseFile);
    break;

case 40:
    ProcessTest(iCurrentTest, bDlgFlag, iResult, &dlgSmfdADC, FALSE, pUseFile);
    break;

case 41:
    ProcessTest(iCurrentTest, bDlgFlag, iResult, &dlgSmfdADC, FALSE, pUseFile);
    break;

case 42:
    ProcessTest(iCurrentTest, bDlgFlag, iResult, &dlgSmfdADC, FALSE, pUseFile);
    break;

case 43:
    ProcessTest(iCurrentTest, bDlgFlag, iResult, &dlgSmfdADC, FALSE, pUseFile);
    break;

case 44:
    ProcessTest(iCurrentTest, bDlgFlag, iResult, &dlgSmfdADC, TRUE, pUseFile);
    break;


// ---------- AHRS ----------
case 45:
    ProcessTest(iCurrentTest, bDlgFlag, iResult, &dlgSmfdAHRS, FALSE, pUseFile);
    break;

case 46:
    ProcessTest(iCurrentTest, bDlgFlag, iResult, &dlgSmfdAHRS, FALSE, pUseFile);
    break;

case 47:
    ProcessTest(iCurrentTest, bDlgFlag, iResult, &dlgSmfdAHRS, FALSE, pUseFile);
    break;

case 48:
    ProcessTest(iCurrentTest, bDlgFlag, iResult, &dlgSmfdAHRS, FALSE, pUseFile);
    break;

case 49:
    ProcessTest(iCurrentTest, bDlgFlag, iResult, &dlgSmfdAHRS, FALSE, pUseFile);
    break;

case 50:
    ProcessTest(iCurrentTest, bDlgFlag, iResult, &dlgSmfdAHRS, TRUE, pUseFile);
    break;


// ---------- VOR / ILS ----------
case 51:
    ProcessTest(iCurrentTest, bDlgFlag, iResult, &dlgSmfdVORILS, FALSE, pUseFile);
    break;

case 52:
    ProcessTest(iCurrentTest, bDlgFlag, iResult, &dlgSmfdVORILS, FALSE, pUseFile);
    break;

case 53:
    ProcessTest(iCurrentTest, bDlgFlag, iResult, &dlgSmfdVORILS, FALSE, pUseFile);
    break;

case 54:
    ProcessTest(iCurrentTest, bDlgFlag, iResult, &dlgSmfdVORILS, FALSE, pUseFile);
    break;

case 55:
    ProcessTest(iCurrentTest, bDlgFlag, iResult, &dlgSmfdVORILS, TRUE, pUseFile);
    break;


// ---------- TACAN ----------
case 56:
    ProcessTest(iCurrentTest, bDlgFlag, iResult, &dlgSmfdTACAN, FALSE, pUseFile);
    break;

case 57:
    ProcessTest(iCurrentTest, bDlgFlag, iResult, &dlgSmfdTACAN, FALSE, pUseFile);
    break;

case 58:
    ProcessTest(iCurrentTest, bDlgFlag, iResult, &dlgSmfdTACAN, TRUE, pUseFile);
    break;


// ---------- GPS ----------
case 59:
    ProcessTest(iCurrentTest, bDlgFlag, iResult, &dlgSmfdGPS, FALSE, pUseFile);
    break;

case 60:
    ProcessTest(iCurrentTest, bDlgFlag, iResult, &dlgSmfdGPS, FALSE, pUseFile);
    break;

case 61:
    ProcessTest(iCurrentTest, bDlgFlag, iResult, &dlgSmfdGPS, FALSE, pUseFile);
    break;

case 62:
    ProcessTest(iCurrentTest, bDlgFlag, iResult, &dlgSmfdGPS, TRUE, pUseFile);
    break;

                }

                break;
            }
        }
    }
    else
    {
        iCurrentTest = ((iCurrentTest / 100) + 1) * 100;
    }
}    if (pFile == NULL)
    {
        fptr.Close();
    }
}

#if 1
void CSIPUPowerONPage::ExecuteSMFDSequenceRC(CFile* pFile)
{
    BOOL bDlgFlag = FALSE;
    int iStartTest, iEndTest, iCurrentTest, iCurr_Pointer, iResult;
     CString strTmpName;
	 int mode = m_Cambo_Mode.GetCurSel();
	 
    iTempCount = 0;

    if (!ValidateUserInput(strTmpName))
        return;
	 CSIPU_SDU_GndRigApp *pMainFrame = (CSIPU_SDU_GndRigApp *)AfxGetApp();

    UpdateData(TRUE);
	CString strCurrDateTime, strCurrDateTime1 ;
    SYSTEMTIME sysTime;
    ::GetLocalTime(&sysTime);

    strCurrDateTime.Format("%s_%d_%d_%d_%dH%dM%dS",
        strTmpName, sysTime.wDay, sysTime.wMonth, sysTime.wYear,
        sysTime.wHour, sysTime.wMinute, sysTime.wSecond);

    strCurrDateTime1.Format("%d/%d/%d",
        sysTime.wDay, sysTime.wMonth, sysTime.wYear);
 

    CFile fptr;
    CFile* pUseFile = pFile;

    // -------- STANDALONE FILE CREATION --------
    if (pUseFile == NULL)
    {
        if (!ValidateUserInput(strTmpName))
            return;

        CFileDialog dlg(TRUE, "bin", strCurrDateTime,
            OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
            "Binary Files(*.BIN)|*.BIN||", this);

        if (dlg.DoModal() == IDCANCEL)
            return;
		strcpy(g_chFileName,dlg.GetPathName());
        if (!fptr.Open(g_chFileName,
            CFile::typeBinary | CFile::modeWrite | CFile::modeCreate))
            return;
		
        pUseFile = &fptr;
		 strcpy(s_Index_Page.m_strOperator, pMainFrame->m_strLogin_UserName);
        strcpy(s_Index_Page.m_strSerialNo, m_Edit_DU_No);
       strcpy(s_Index_Page.m_strTestDescription, (LPCTSTR)m_edtStrTestDesc);
       sprintf(s_Index_Page.m_strDateTime, "%s", strCurrDateTime1);
        strcpy(s_Index_Page.m_strFileName,g_chFileName);
        pUseFile->Write(&s_Index_Page, sizeof(s_Index_Page));
    }

    // -------- DIALOG OBJECTS --------
    CDialog_Smfd_Visual_RC dlgSmfdVisual;
    CDialog_Smfd_Pwr_RC    dlgSmfdPwr;
    CDialog_Smfd_Sw_RC     dlgSmfdSW;
    CDialog_Smfd_Fuel_RC   dlgSmfdFuel;
    CDialog_Smfd_Rev_RC    dlgSmfdRev;
	CDialog_Smfd_Adc_RC     dlgSmfdADC;
    CDialog_Smfd_AHRS_RC     dlgSmfdAHRS;
    CDialog_Smfd_Vorils_RC dlgSmfdVORILS;
    CDialog_Smfd_Tacan_RC   dlgSmfdTACAN;
    CDialog_Smfd_Discrete_RC dlgSmfdDiscrete;
    CDialog_Smfd_Gps_RC dlgSmfdGPS;
	//ANALOG RC
		CDialog_SMFD_RC_BV dlgSmfdANBV;
   CDialog_SMFD_RC_ANCL  dlgSmfdANCL;
CDialog_SMFD_RC_CT    dlgSmfdANCT;
 CDialog_SMFD_RC_EB   dlgSmfdANEB;
 CDialog_SMFD_RC_ES dlgSmfdANES;
 CDialog_SMFD_RC_FTL dlgSmfdANFTL;
 CDialog_SMFD_RC_FTR dlgSmfdANFTR;
   CDialog_SMFD_RC_EOP dlgSmfdANGEOP;
    CDialog_SMFD_RC_GV  dlgSmfdANGV;
    CDialog_SMFD_RC_LBP  dlgSmfdANLBP;
    CDialog_SMFD_RC_RBP  dlgSmfdANRBP;
  CDialog_SMFD_RC_ATP      dlgSmfdANATP;
   CDialog_SMFD_RC_ET     dlgSmfdANET;
   CDialog_SMFD_RC_ETP    dlgSmfdANETP;
   CDialog_SMFD_RC_FP3    dlgSmfdANFP3;
    CDialog_SMFD_RC_FP4    dlgSmfdANFP4;
     CDialog_SMFD_RC_HPE    dlgSmfdANHPE;
     CDialog_SMFD_RC_RTP     dlgSmfdANRTP;
	 CDialog_SMFD_RC_EOT     dlgSmfdANEOT;
	 CDialog_SMFD_RC_HPM     dlgSmfdANHPM;

    // -------- TEST TABLE --------

BOOL bIntegrationMode = (m_Cambo_Mode.GetCurSel() == 0);

#define ADD_TEST(idInteg,idStandalone,majStandalone,majName,minName,dlgPtr,exp)\
    s_AllTestDetails[iTempCount].m_ucMajor_Test_ID = bIntegrationMode ? 1 : majStandalone;\
    s_AllTestDetails[iTempCount].m_uiMinor_Test_ID = bIntegrationMode ? idInteg : idStandalone;\
    s_AllTestDetails[iTempCount].m_strMajor_Test_Name = majName;\
    s_AllTestDetails[iTempCount].m_strMinor_Test_Name = minName;\
    s_AllTestDetails[iTempCount].m_Procedure_Dlg = dlgPtr;\
    s_AllTestDetails[iTempCount].m_strExpected = exp;\
    iTempCount++;

// -------- VISUAL --------
ADD_TEST(101,101,1,"SMFD RC Visual","MFD RC Part Number",&dlgSmfdVisual,"100-604077-000");
ADD_TEST(102,102,1,"SMFD RC Visual","SMFD RC Part Number",&dlgSmfdVisual,"100-604078-000");
ADD_TEST(103,103,1,"SMFD RC Visual","Damage Check",&dlgSmfdVisual,"NO");
ADD_TEST(104,104,1,"SMFD RC Visual","Scratches Check",&dlgSmfdVisual,"NO");
ADD_TEST(105,105,1,"SMFD RC Visual","Screws Check",&dlgSmfdVisual,"NO");
ADD_TEST(106,106,1,"SMFD RC Visual","Pins Check",&dlgSmfdVisual,"NO");

// -------- POWER --------
ADD_TEST(201,201,2,"SMFD RC Power","SMFD RC Current",&dlgSmfdPwr,"< 3A");
ADD_TEST(202,202,2,"SMFD RC Power","MFD RC Current",&dlgSmfdPwr,"< 1.8A");

// -------- SOFTWARE --------
ADD_TEST(301,301,3,"SMFD RC Software","Operational Software",&dlgSmfdSW,"E73D5822");

// -------- ANALOG --------
ADD_TEST(401,401,4,"SMFD RC Analog","Oil Temp",&dlgSmfdANEOT,"60±2 °C");                                        
ADD_TEST(402,402,4,"SMFD RC Analog","Oil Pressure",&dlgSmfdANGEOP,"40±3 psi");
ADD_TEST(403,403,4,"SMFD RC Analog","Torque",&dlgSmfdANET,"1740±4 ft-lb");
ADD_TEST(404,404,4,"SMFD RC Analog","Rudder",&dlgSmfdANRTP,"Nose at centre white line");
ADD_TEST(405,405,4,"SMFD RC Analog","Elevator",&dlgSmfdANETP,"Nose at green line & -1.2 deg");
ADD_TEST(406,406,4,"SMFD RC Analog","Aileron",&dlgSmfdANATP,"Wing at green line");
ADD_TEST(407,407,4,"SMFD RC Analog","Flap 3V",&dlgSmfdANFP3,"FLAPS 20 in Green");
ADD_TEST(408,408,4,"SMFD RC Analog","Flap 4V",&dlgSmfdANFP4,"Flaps 30 in Yellow");
ADD_TEST(409,409,4,"SMFD RC Analog","Generator Volt",&dlgSmfdANGV,"28±1 V");
ADD_TEST(410,410,4,"SMFD RC Analog","Battery Volt",&dlgSmfdANBV,"28±1 V");
ADD_TEST(411,411,4,"SMFD RC Analog","Current Load",&dlgSmfdANCL,"200±10 A");

// -------- ANALOG2 --------
ADD_TEST(412,412,4,"SMFD RC Analog","Hydraulic Main Pressure",&dlgSmfdANHPM,"2930±20 psi");
ADD_TEST(413,413,4,"SMFD RC Analog","Hydraulic Emergency Pressure",&dlgSmfdANHPE,"3330±20 psi");
ADD_TEST(414,414,4,"SMFD RC Analog","Emergency Brake Pressure",&dlgSmfdANEB,"1300±15 psi");
ADD_TEST(415,415,4,"SMFD RC Analog","LH Brake Pressure",&dlgSmfdANLBP,"1200±15 psi");
ADD_TEST(416,416,4,"SMFD RC Analog","RH Brake Pressure",&dlgSmfdANRBP,"1200±15 psi");
ADD_TEST(417,417,4,"SMFD RC Analog","Engine Speed",&dlgSmfdANES,"79±2 rpm");
ADD_TEST(418,418,4,"SMFD RC Analog","Fuel LH",&dlgSmfdANFTL,"168±5 lb");
ADD_TEST(419,419,4,"SMFD RC Analog","Fuel RH",&dlgSmfdANFTR,"168±5 lb");
ADD_TEST(420,420,4,"SMFD RC Analog","Collector Tank Fuel",&dlgSmfdANCT,"183±5 lb");

// -------- FUEL --------
ADD_TEST(501,501,5,"SMFD RC Fuel Flow Check","Fuel Flow",&dlgSmfdFuel,"300 lb/hr");

// -------- DISCRETE --------
ADD_TEST(601,601,6,"SMFD RC Discrete","Bus Tie",&dlgSmfdDiscrete,"Operational");
ADD_TEST(602,602,6,"SMFD RC Discrete","Canopy",&dlgSmfdDiscrete,"Operational");
ADD_TEST(603,603,6,"SMFD RC Discrete","ECS OFF",&dlgSmfdDiscrete,"Operational");
ADD_TEST(604,604,6,"SMFD RC Discrete","ECS Over Pressure",&dlgSmfdDiscrete,"Operational");
ADD_TEST(605,605,6,"SMFD RC Discrete","AOA Mute",&dlgSmfdDiscrete,"Operational");
ADD_TEST(606,606,6,"SMFD RC Discrete","Alarm Mute",&dlgSmfdDiscrete,"Operational");
ADD_TEST(607,607,6,"SMFD RC Discrete","Demist",&dlgSmfdDiscrete,"Operational");
ADD_TEST(608,608,6,"SMFD RC Discrete","Start Switch",&dlgSmfdDiscrete,"Operational");

// -------- REVISION --------
ADD_TEST(701,701,7,"SMFD RC Revisionary Page Check","Revision Page",&dlgSmfdRev,"Operational");

// -------- ADC --------
ADD_TEST(801,801,8,"SMFD RC ADC","Altitude (203)",&dlgSmfdADC,"5000 ft");
ADD_TEST(802,802,8,"SMFD RC ADC","Mach (205)",&dlgSmfdADC,"0.5 M");
ADD_TEST(803,803,8,"SMFD RC ADC","Airspeed (206)",&dlgSmfdADC,"100 knots");
ADD_TEST(804,804,8,"SMFD RC ADC","Altitude Rate (212)",&dlgSmfdADC,"1500 ft/min");
ADD_TEST(805,805,8,"SMFD RC ADC","Static Air Temp (213)",&dlgSmfdADC,"25 °C");
ADD_TEST(806,806,8,"SMFD RC ADC","True Airspeed (210)",&dlgSmfdADC,"100 knots");

// -------- AHRS --------
ADD_TEST(901,901,9,"SMFD RC AHRS","Heading (320)",&dlgSmfdAHRS,"60 Deg");
ADD_TEST(902,902,9,"SMFD RC AHRS","Pitch (324)",&dlgSmfdAHRS,"20 Deg");
ADD_TEST(903,903,9,"SMFD RC AHRS","Roll (325)",&dlgSmfdAHRS,"10 Deg");
ADD_TEST(904,904,9,"SMFD RC AHRS","Yaw Rate (330)",&dlgSmfdAHRS,"Valid");
ADD_TEST(905,905,9,"SMFD RC AHRS","Lat Acc (332)",&dlgSmfdAHRS,"Valid");
ADD_TEST(906,906,9,"SMFD RC AHRS","Norm Acc (333)",&dlgSmfdAHRS,"6 g");

// -------- VOR/ILS --------
ADD_TEST(1001,1001,10,"SMFD RC VOR/ILS","VOR Frequency",&dlgSmfdVORILS,"108.00 MHz");
ADD_TEST(1002,1002,10,"SMFD RC VOR/ILS","ILS Frequency",&dlgSmfdVORILS,"108.10 MHz");
ADD_TEST(1003,1003,10,"SMFD RC VOR/ILS","VOR Bearing",&dlgSmfdVORILS,"90");
ADD_TEST(1004,1004,10,"SMFD RC VOR/ILS","Localizer",&dlgSmfdVORILS,"OK");
ADD_TEST(1005,1005,10,"SMFD RC VOR/ILS","Glide Slope",&dlgSmfdVORILS,"OK");

// -------- TACAN --------
ADD_TEST(1101,1101,11,"SMFD RC TACAN","Control Word (145)",&dlgSmfdTACAN,"12X");
ADD_TEST(1102,1102,11,"SMFD RC TACAN","Distance (201)",&dlgSmfdTACAN,"300 KM");
ADD_TEST(1103,1103,11,"SMFD RC TACAN","Bearing (222)",&dlgSmfdTACAN,"90 deg");

// -------- GPS --------
ADD_TEST(1201,1201,12,"SMFD RC GPS","Ground Speed",&dlgSmfdGPS,"1000 KM");
ADD_TEST(1202,1202,12,"SMFD RC GPS","True Track",&dlgSmfdGPS,"90 deg");
ADD_TEST(1203,1203,12,"SMFD RC GPS","Magnetic Track",&dlgSmfdGPS,"90 deg");
ADD_TEST(1204,1204,12,"SMFD RC GPS","GPS Time",&dlgSmfdGPS,"Valid");

#undef ADD_TEST



    iStartTest = 100;
    iEndTest   = 1299;


    // -------- EXECUTION LOOP --------
for(iCurrentTest = iStartTest;iCurrentTest <= iEndTest;iCurrentTest++)
{
	if (g_bStopRequested)
		break;
    if(iCurrentTest % 100 <= DU_ATP_MAX_NO_OF_SUBTEST)
    {
        for(iCurr_Pointer = 0;
            iCurr_Pointer < iTempCount;
            iCurr_Pointer++)
        {
            if(iCurrentTest ==
               s_AllTestDetails[iCurr_Pointer].m_uiMinor_Test_ID)
            {
                s_Curr_Test_Result.m_uiMinor_Test_ID = iCurrentTest;

                strcpy(s_Curr_Test_Result.m_strMajorTestName,
                       s_AllTestDetails[iCurr_Pointer].m_strMajor_Test_Name);

                strcpy(s_Curr_Test_Result.m_strMinorTestName,
                       s_AllTestDetails[iCurr_Pointer].m_strMinor_Test_Name);

                strcpy(s_Curr_Test_Result.m_strSpec,
                       s_AllTestDetails[iCurr_Pointer].m_strExpected);
				 SetSelectedControls(iCurrentTest);

                
                    // cases go here
switch(iCurr_Pointer)
{
    // ---------- VISUAL ----------
    case 0: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdVisual,FALSE,pUseFile); break;
    case 1: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdVisual,FALSE,pUseFile); break;
    case 2: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdVisual,FALSE,pUseFile); break;
    case 3: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdVisual,FALSE,pUseFile); break;
    case 4: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdVisual,FALSE,pUseFile); break;
    case 5: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdVisual,TRUE ,pUseFile); break;

    // ---------- POWER ----------
    case 6: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdPwr,FALSE,pUseFile); break;
    case 7: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdPwr,TRUE ,pUseFile); break;

    // ---------- SOFTWARE ----------
    case 8: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdSW,TRUE,pUseFile); break;

    case 9:  ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANEOT,TRUE,pUseFile); break;
    case 10: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANGEOP,TRUE,pUseFile); break;
    case 11: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANET,TRUE,pUseFile); break;
    case 12: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANRTP,TRUE,pUseFile); break;
    case 13: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANETP,TRUE,pUseFile); break;
    case 14: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANATP,TRUE,pUseFile); break;
    case 15: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANFP3,TRUE,pUseFile); break;
    case 16: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANFP4,TRUE,pUseFile); break;
    case 17: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANGV,TRUE,pUseFile); break;
    case 18: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANBV,TRUE,pUseFile); break;
    case 19: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANCL,TRUE ,pUseFile); break;

    // ---------- ANALOG2 ----------
    case 20: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANHPM,TRUE,pUseFile); break;
    case 21: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANHPE,TRUE,pUseFile); break;
    case 22: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANEB,TRUE,pUseFile); break;
    case 23: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANLBP,TRUE,pUseFile); break;
    case 24: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANRBP,TRUE,pUseFile); break;
    case 25: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANES,TRUE,pUseFile); break;
    case 26: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANFTL,TRUE,pUseFile); break;
    case 27: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANFTR,TRUE,pUseFile); break;
    case 28: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdANCT,TRUE ,pUseFile); break;

    // ---------- FUEL ----------
    case 29: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdFuel,TRUE,pUseFile); break;

    // ---------- DISCRETE ----------
    case 30: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdDiscrete,FALSE,pUseFile); break;
    case 31: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdDiscrete,FALSE,pUseFile); break;
    case 32: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdDiscrete,FALSE,pUseFile); break;
    case 33: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdDiscrete,FALSE,pUseFile); break;
    case 34: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdDiscrete,FALSE,pUseFile); break;
    case 35: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdDiscrete,FALSE,pUseFile); break;
    case 36: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdDiscrete,FALSE,pUseFile); break;
    case 37: ProcessTestRC(iCurrentTest,bDlgFlag,iResult,&dlgSmfdDiscrete,TRUE,pUseFile); break;

   // ---------- REV ----------
case 38:
    ProcessTestRC(iCurrentTest, bDlgFlag, iResult, &dlgSmfdRev, TRUE, pUseFile);
    break;

// ---------- ADC ----------
case 39:
    ProcessTestRC(iCurrentTest, bDlgFlag, iResult, &dlgSmfdADC, FALSE, pUseFile);
    break;

case 40:
    ProcessTestRC(iCurrentTest, bDlgFlag, iResult, &dlgSmfdADC, FALSE, pUseFile);
    break;

case 41:
    ProcessTestRC(iCurrentTest, bDlgFlag, iResult, &dlgSmfdADC, FALSE, pUseFile);
    break;

case 42:
    ProcessTestRC(iCurrentTest, bDlgFlag, iResult, &dlgSmfdADC, FALSE, pUseFile);
    break;

case 43:
    ProcessTestRC(iCurrentTest, bDlgFlag, iResult, &dlgSmfdADC, FALSE, pUseFile);
    break;

case 44:
    ProcessTestRC(iCurrentTest, bDlgFlag, iResult, &dlgSmfdADC, TRUE, pUseFile);
    break;


// ---------- AHRS ----------
case 45:
    ProcessTestRC(iCurrentTest, bDlgFlag, iResult, &dlgSmfdAHRS, FALSE, pUseFile);
    break;

case 46:
    ProcessTestRC(iCurrentTest, bDlgFlag, iResult, &dlgSmfdAHRS, FALSE, pUseFile);
    break;

case 47:
    ProcessTestRC(iCurrentTest, bDlgFlag, iResult, &dlgSmfdAHRS, FALSE, pUseFile);
    break;

case 48:
    ProcessTestRC(iCurrentTest, bDlgFlag, iResult, &dlgSmfdAHRS, FALSE, pUseFile);
    break;

case 49:
    ProcessTestRC(iCurrentTest, bDlgFlag, iResult, &dlgSmfdAHRS, FALSE, pUseFile);
    break;

case 50:
    ProcessTestRC(iCurrentTest, bDlgFlag, iResult, &dlgSmfdAHRS, TRUE, pUseFile);
    break;


// ---------- VOR / ILS ----------
case 51:
    ProcessTestRC(iCurrentTest, bDlgFlag, iResult, &dlgSmfdVORILS, FALSE, pUseFile);
    break;

case 52:
    ProcessTestRC(iCurrentTest, bDlgFlag, iResult, &dlgSmfdVORILS, FALSE, pUseFile);
    break;

case 53:
    ProcessTestRC(iCurrentTest, bDlgFlag, iResult, &dlgSmfdVORILS, FALSE, pUseFile);
    break;

case 54:
    ProcessTestRC(iCurrentTest, bDlgFlag, iResult, &dlgSmfdVORILS, FALSE, pUseFile);
    break;

case 55:
    ProcessTestRC(iCurrentTest, bDlgFlag, iResult, &dlgSmfdVORILS, TRUE, pUseFile);
    break;


// ---------- TACAN ----------
case 56:
    ProcessTestRC(iCurrentTest, bDlgFlag, iResult, &dlgSmfdTACAN, FALSE, pUseFile);
    break;

case 57:
    ProcessTestRC(iCurrentTest, bDlgFlag, iResult, &dlgSmfdTACAN, FALSE, pUseFile);
    break;

case 58:
    ProcessTestRC(iCurrentTest, bDlgFlag, iResult, &dlgSmfdTACAN, TRUE, pUseFile);
    break;


// ---------- GPS ----------
case 59:
    ProcessTestRC(iCurrentTest, bDlgFlag, iResult, &dlgSmfdGPS, FALSE, pUseFile);
    break;

case 60:
    ProcessTestRC(iCurrentTest, bDlgFlag, iResult, &dlgSmfdGPS, FALSE, pUseFile);
    break;

case 61:
    ProcessTestRC(iCurrentTest, bDlgFlag, iResult, &dlgSmfdGPS, FALSE, pUseFile);
    break;

case 62:
    ProcessTestRC(iCurrentTest, bDlgFlag, iResult, &dlgSmfdGPS, TRUE, pUseFile);
    break;
                }

                break;
            }
        }
    }
    else
    {
        iCurrentTest = ((iCurrentTest / 100) + 1) * 100;
    }
}    if (pFile == NULL)
    {
        fptr.Close();
    }
}
#endif


void CSIPUPowerONPage::ProcessTest(
    int iCurrentTest,
    int& bDlgFlag,
    int& iResult,
    CDialog* pDlg,
    BOOL bLastInGroup,
    CFile* pUseFile)
{
    // Open dialog only once per group
    if (!bDlgFlag)
    {
        iResult = ShowTestProcedure(pDlg);
		if (g_bStopRequested)
			return;
        bDlgFlag = TRUE;
    }

    CString measured, status;

    // -------- FETCH VALUES AFTER DIALOG CLOSE --------
    switch (iCurrentTest)
    {
        // -------- VISUAL --------
		if(g_bStopRequested)
        break;
        case 101:
        {
            CDialog_Smfd_Visual* dlg = (CDialog_Smfd_Visual*)pDlg;
            measured = dlg->m_strSmfdPNo;
            status   = dlg->m_strStatusSmfdPNo;
            break;
        }
        case 102:
        {
            CDialog_Smfd_Visual* dlg = (CDialog_Smfd_Visual*)pDlg;
            measured = dlg->m_strMfdPNo;
            status   = dlg->m_strStatusMfdPNo;
            break;
        }
        case 103:
        {
            CDialog_Smfd_Visual* dlg = (CDialog_Smfd_Visual*)pDlg;
            measured = dlg->m_strSmfdDamage;
            status   = dlg->m_strStatusSmfdDamage;
            break;
        }
        case 104:
        {
            CDialog_Smfd_Visual* dlg = (CDialog_Smfd_Visual*)pDlg;
            measured = dlg->m_strSmfdScratches;
            status   = dlg->m_strStatusSmfdScratches;
            break;
        }
        case 105:
        {
            CDialog_Smfd_Visual* dlg = (CDialog_Smfd_Visual*)pDlg;
            measured = dlg->m_strSmfdScrews;
            status   = dlg->m_strStatusSmfdScrews;
            break;
        }
        case 106:
        {
            CDialog_Smfd_Visual* dlg = (CDialog_Smfd_Visual*)pDlg;
            measured = dlg->m_strSmfdPins;
            status   = dlg->m_strStatusSmfdPins;
            break;
        }

        // -------- POWER --------
        case 201:
        {
            CDialog_SMFD_PWR* dlg = (CDialog_SMFD_PWR*)pDlg;
            measured = dlg->m_strSMFD1Current;
            status   = dlg->m_strStatusSMFD1Current;
            break;
        }
        case 202:
        {
            CDialog_SMFD_PWR* dlg = (CDialog_SMFD_PWR*)pDlg;
            measured = dlg->m_strMFD1Current;
            status   = dlg->m_strStatusMFD1Current;
            break;
        }
      

        // -------- SOFTWARE --------
        case 301:
        {
            CDialog_SMFD_SW* dlg = (CDialog_SMFD_SW*)pDlg;
            measured = dlg->m_strSmfdSw;
            status   = dlg->m_strStatusSmfdSw;
            break;
        }

        // -------- ANALOG --------
        case 401:
        {
            CDialog_Smfd_Analog* dlg = (CDialog_Smfd_Analog*)pDlg;
            measured = dlg->m_stroiltemp;
            status   = dlg->m_strStatusoiltemp;
            break;
        }
        case 402:
        {
            CDialog_SMFD_FC_ANGEOP* dlg = (CDialog_SMFD_FC_ANGEOP*)pDlg;
            measured = dlg->m_stroilpressure;
            status   = dlg->m_strStatusoilpressure;
            break;
        }
        case 403:
        {
            CDialog_SMFD_FC_ET* dlg = (CDialog_SMFD_FC_ET*)pDlg;
            measured = dlg->m_strtorque;
            status   = dlg->m_strStatustorque;
            break;
        }
        case 404:
        {
            CDialog_SMFD_FC_RTP* dlg = (CDialog_SMFD_FC_RTP*)pDlg;
            measured = dlg->m_strrudder;
            status   = dlg->m_strStatusrudder;
            break;
        }
        case 405:
        {
            CDialog_SMFD_FC_ETP* dlg = (CDialog_SMFD_FC_ETP*)pDlg;
            measured = dlg->m_strelevator;
            status   = dlg->m_strStatuselevator;
            break;
        }
        case 406:
        {
            CDialog_SMFD_FC_ATP* dlg = (CDialog_SMFD_FC_ATP*)pDlg;
            measured = dlg->m_straileron;
            status   = dlg->m_strStatusaileron;
            break;
        }
        case 407:
        {
            CDialog_SMFD_FC_FP3* dlg = (CDialog_SMFD_FC_FP3*)pDlg;
            measured = dlg->m_strflap3v;
            status   = dlg->m_strStatusflap3v;
            break;
        }
        case 408:
        {
            CDialog_SMFD_FC_FP4* dlg = (CDialog_SMFD_FC_FP4*)pDlg;
            measured = dlg->m_strflap4v;
            status   = dlg->m_strStatusflap4v;
            break;
        }
        case 409:
        {
            CDialog_SMFD_FC_ANGV* dlg = (CDialog_SMFD_FC_ANGV*)pDlg;
            measured = dlg->m_strgenvolt;
            status   = dlg->m_strStatusgenvolt;
            break;
        }
        case 410:
        {
            CDialog_SMFD_FC_ANBV* dlg = (CDialog_SMFD_FC_ANBV*)pDlg;
            measured = dlg->m_strbatvolt;
            status   = dlg->m_strStatusbatvolt;
            break;
        }
        case 411:
        {
            CDialog_SMFD_FC_ANCL* dlg = (CDialog_SMFD_FC_ANCL*)pDlg;
            measured = dlg->m_strcurload;
            status   = dlg->m_strStatuscurload;
            break;
        }

        // -------- FUEL --------
        case 501:
        {
            CDialog_Smfd_Fuel* dlg = (CDialog_Smfd_Fuel*)pDlg;
            measured = dlg->m_strSmfdfuel;
            status   = dlg->m_strStatusSmfdfuel;
            break;
        }

        // -------- REV --------
        case 701:
        {
            CDialog_Smfd_Rev_Page* dlg = (CDialog_Smfd_Rev_Page*)pDlg;
            measured = dlg->m_strSMFDRevPage;
            status   = dlg->m_strStatusSMFDRevPage;
            break;
        }
		// -------- ANALOG2 --------
case 412:
{
    CDialog_Smfd_Analog2* dlg = (CDialog_Smfd_Analog2*)pDlg;
    measured = dlg->m_strHydPresMain;
    status   = dlg->m_strStatusHydPresMain;
    break;
}
case 413:
{
    CDialog_SMFD_FC_HPE* dlg = (CDialog_SMFD_FC_HPE*)pDlg;
    measured = dlg->m_strHydPresEmer;
    status   = dlg->m_strStatusHydPresEmer;
    break;
}
case 414:
{
    CDialog_SMFD_FC_ANEB* dlg = (CDialog_SMFD_FC_ANEB*)pDlg;
    measured = dlg->m_strEmerBrake;
    status   = dlg->m_strStatusEmerBrake;
    break;
}

case 415:
{
    CDialog_SMFD_FC_ANLBP* dlg = (CDialog_SMFD_FC_ANLBP*)pDlg;
    measured = dlg->m_strLhBrake;
    status   = dlg->m_strStatusLhBrake;
    break;
}
case 416:
{
    CDialog_SMFD_FC_ANRBP* dlg = (CDialog_SMFD_FC_ANRBP*)pDlg;
    measured = dlg->m_strRhBrake;
    status   = dlg->m_strStatusRhBrake;
    break;
}
case 417:
{
    CDialog_SMFD_FC_ANES* dlg = (CDialog_SMFD_FC_ANES*)pDlg;
    measured = dlg->m_strEngineSpd;
    status   = dlg->m_strStatusEngineSpd;
    break;
}
case 418:
{
    CDialog_SMFD_FC_ANFTL* dlg = (CDialog_SMFD_FC_ANFTL*)pDlg;
    measured = dlg->m_strFuelLh;
    status   = dlg->m_strStatusFuelLh;
    break;
}
case 419:
{
    CDialog_SMFD_FC_ANFTR* dlg = (CDialog_SMFD_FC_ANFTR*)pDlg;
    measured = dlg->m_strFuelRh;
    status   = dlg->m_strStatusFuelRh;
    break;
}
case 420:
{
    CDialog_SMFD_FC_ANCT* dlg = (CDialog_SMFD_FC_ANCT*)pDlg;
    measured = dlg->m_strCollectorTank;
    status   = dlg->m_strStatusCollectorTank;
    break;
}

// -------- ADC --------
case 801:
{
    CDialogSmfd_ADC* dlg = (CDialogSmfd_ADC*)pDlg;
    measured = dlg->m_strSmfdAdc203;
    status   = dlg->m_strStatusSmfdAdc203;
    break;
}
case 802:
{
    CDialogSmfd_ADC* dlg = (CDialogSmfd_ADC*)pDlg;
    measured = dlg->m_strSmfdAdc205;
    status   = dlg->m_strStatusSmfdAdc205;
    break;
}
case 803:
{
    CDialogSmfd_ADC* dlg = (CDialogSmfd_ADC*)pDlg;
    measured = dlg->m_strSmfdAdc206;
    status   = dlg->m_strStatusSmfdAdc206;
    break;
}
case 804:
{
    CDialogSmfd_ADC* dlg = (CDialogSmfd_ADC*)pDlg;
    measured = dlg->m_strSmfdAdc212;
    status   = dlg->m_strStatusSmfdAdc212;
    break;
}
case 805:
{
    CDialogSmfd_ADC* dlg = (CDialogSmfd_ADC*)pDlg;
    measured = dlg->m_strSmfdAdc213;
    status   = dlg->m_strStatusSmfdAdc213;
    break;
}
case 806:
{
    CDialogSmfd_ADC* dlg = (CDialogSmfd_ADC*)pDlg;
    measured = dlg->m_strSmfdAdc210;
    status   = dlg->m_strStatusSmfdAdc210;
    break;
}

// -------- AHRS --------
case 901:
{
    CDialogSmfdAHRS* dlg = (CDialogSmfdAHRS*)pDlg;
    measured = dlg->m_strSmfdAhrs320;
    status   = dlg->m_strStatusSmfdAhrs320;
    break;
}
case 902:
{
    CDialogSmfdAHRS* dlg = (CDialogSmfdAHRS*)pDlg;
    measured = dlg->m_strSmfdAhrs324;
    status   = dlg->m_strStatusSmfdAhrs324;
    break;
}
case 903:
{
    CDialogSmfdAHRS* dlg = (CDialogSmfdAHRS*)pDlg;
    measured = dlg->m_strSmfdAhrs325;
    status   = dlg->m_strStatusSmfdAhrs325;
    break;
}
case 904:
{
    CDialogSmfdAHRS* dlg = (CDialogSmfdAHRS*)pDlg;
    measured = dlg->m_strSmfdAhrs330;
    status   = dlg->m_strStatusSmfdAhrs330;
    break;
}
case 905:
{
    CDialogSmfdAHRS* dlg = (CDialogSmfdAHRS*)pDlg;
    measured = dlg->m_strSmfdAhrs332;
    status   = dlg->m_strStatusSmfdAhrs332;
    break;
}
case 906:
{
    CDialogSmfdAHRS* dlg = (CDialogSmfdAHRS*)pDlg;
    measured = dlg->m_strSmfdAhrs333;
    status   = dlg->m_strStatusSmfdAhrs333;
    break;
}

// -------- VOR/ILS --------
case 1001:
{
    CDialog_Smfd_VORILS* dlg = (CDialog_Smfd_VORILS*)pDlg;
    measured = dlg->m_strvorfreq;
    status   = dlg->m_strStatusvorfreq;
    break;
}
case 1002:
{
    CDialog_Smfd_VORILS* dlg = (CDialog_Smfd_VORILS*)pDlg;
    measured = dlg->m_strilsfreq;
    status   = dlg->m_strStatusilsfreq;
    break;
}
case 1003:
{
    CDialog_Smfd_VORILS* dlg = (CDialog_Smfd_VORILS*)pDlg;
    measured = dlg->m_strvorbrg;
    status   = dlg->m_strStatusvorbrg;
    break;
}
case 1004:
{
    CDialog_Smfd_VORILS* dlg = (CDialog_Smfd_VORILS*)pDlg;
    measured = dlg->m_strlocalizer;
    status   = dlg->m_strStatuslocalizer;
    break;
}
case 1005:
{
    CDialog_Smfd_VORILS* dlg = (CDialog_Smfd_VORILS*)pDlg;
    measured = dlg->m_strglideslope;
    status   = dlg->m_strStatusglideslope;
    break;
}

// -------- TACAN --------
case 1101:
{
    CDialogSmfd_Tacan* dlg = (CDialogSmfd_Tacan*)pDlg;
    measured = dlg->m_strtac145;
    status   = dlg->m_strStatustac145;
    break;
}
case 1102:
{
    CDialogSmfd_Tacan* dlg = (CDialogSmfd_Tacan*)pDlg;
    measured = dlg->m_strtac201;
    status   = dlg->m_strStatustac201;
    break;
}
case 1103:
{
    CDialogSmfd_Tacan* dlg = (CDialogSmfd_Tacan*)pDlg;
    measured = dlg->m_strtac222;
    status   = dlg->m_strStatustac222;
    break;
}

// -------- DISCRETE --------
case 601:
{
    CDialog_Smfd_Discrete* dlg = (CDialog_Smfd_Discrete*)pDlg;
    measured = dlg->m_strBusTie;
    status   = dlg->m_strStatusBusTie;
    break;
}
case 602:
{
    CDialog_Smfd_Discrete* dlg = (CDialog_Smfd_Discrete*)pDlg;
    measured = dlg->m_strCanopy;
    status   = dlg->m_strStatusCanopy;
    break;
}
case 603:
{
    CDialog_Smfd_Discrete* dlg = (CDialog_Smfd_Discrete*)pDlg;
    measured = dlg->m_strEcsoff;
    status   = dlg->m_strStatusEcsoff;
    break;
}
case 604:
{
    CDialog_Smfd_Discrete* dlg = (CDialog_Smfd_Discrete*)pDlg;
    measured = dlg->m_strEcsOvPr;
    status   = dlg->m_strStatusEcsOvPr;
    break;
}
case 605:
{
    CDialog_Smfd_Discrete* dlg = (CDialog_Smfd_Discrete*)pDlg;
    measured = dlg->m_strAoamute;
    status   = dlg->m_strStatusAoamute;
    break;
}
case 606:
{
    CDialog_Smfd_Discrete* dlg = (CDialog_Smfd_Discrete*)pDlg;
    measured = dlg->m_strAlarmMute;
    status   = dlg->m_strStatusAlarmMute;
    break;
}
case 607:
{
    CDialog_Smfd_Discrete* dlg = (CDialog_Smfd_Discrete*)pDlg;
    measured = dlg->m_strDemist;
    status   = dlg->m_strStatusDemist;
    break;
}
case 608:
{
    CDialog_Smfd_Discrete* dlg = (CDialog_Smfd_Discrete*)pDlg;
    measured = dlg->m_strStarton;
    status   = dlg->m_strStatusStarton;
    break;
}
// -------- GPS --------
case 1201:
{
    CDialog_SMFD_GPS* dlg = (CDialog_SMFD_GPS*)pDlg;
    measured = dlg->m_strSmfdGpsGrSpd;
    status   = dlg->m_strStatusSmfdGpsGrSpd;
    break;
}
case 1202:
{
    CDialog_SMFD_GPS* dlg = (CDialog_SMFD_GPS*)pDlg;
    measured = dlg->m_strSmfdGpsTrueTrack;
    status   = dlg->m_strStatusSmfdGpsTrueTrack;
    break;
}
case 1203:
{
    CDialog_SMFD_GPS* dlg = (CDialog_SMFD_GPS*)pDlg;
    measured = dlg->m_strSmfdGpsMagTrack;
    status   = dlg->m_strStatusSmfdGpsMagTrack;
    break;
}
case 1204:
{
    CDialog_SMFD_GPS* dlg = (CDialog_SMFD_GPS*)pDlg;
    measured = dlg->m_strSmfdGpsTime;
    status   = dlg->m_strStatusSmfdGpsTime;
    break;
}

        // -------- DEFAULT --------
        default:
            measured = "";
            status   = "NOT OK";
            break;
    }

    // -------- STORE --------
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val, measured);
    strcpy(s_Curr_Test_Result.m_strTestStatus, status);

    // Reset dialog flag at end of group
    if (bLastInGroup)
        bDlgFlag = FALSE;

    pUseFile->Write(&s_Curr_Test_Result, sizeof(s_Curr_Test_Result));

    if(DynListCtrl != NULL)
    FillListCtrl(*DynListCtrl);
}


#if 1
void CSIPUPowerONPage::ProcessTestRC(
    int iCurrentTest,
    int& bDlgFlag,
    int& iResult,
    CDialog* pDlg,
    BOOL bLastInGroup,
    CFile* pUseFile)
{
    // Open dialog only once per group
    if (!bDlgFlag)
    {
        iResult = ShowTestProcedure(pDlg);
		if (g_bStopRequested)
			return;
        bDlgFlag = TRUE;
    }

    CString measured, status;

    // -------- FETCH VALUES AFTER DIALOG CLOSE --------
    switch (iCurrentTest)
    {
       // -------- VISUAL --------
		if(g_bStopRequested)
        break;
case 101:
{
    CDialog_Smfd_Visual_RC* dlg = (CDialog_Smfd_Visual_RC*)pDlg;
    measured = dlg->m_strSmfdRcPNo;
    status   = dlg->m_strStatusSmfdRcPNo;
    break;
}
case 102:
{
    CDialog_Smfd_Visual_RC* dlg = (CDialog_Smfd_Visual_RC*)pDlg;
    measured = dlg->m_strMfdRcPNo;
    status   = dlg->m_strStatusMfdRcPNo;
    break;
}
case 103:
{
    CDialog_Smfd_Visual_RC* dlg = (CDialog_Smfd_Visual_RC*)pDlg;
    measured = dlg->m_strRcDamage;
    status   = dlg->m_strStatusRcDamage;
    break;
}
case 104:
{
    CDialog_Smfd_Visual_RC* dlg = (CDialog_Smfd_Visual_RC*)pDlg;
    measured = dlg->m_strRcScratches;
    status   = dlg->m_strStatusRcScratches;
    break;
}
case 105:
{
    CDialog_Smfd_Visual_RC* dlg = (CDialog_Smfd_Visual_RC*)pDlg;
    measured = dlg->m_strRcScrews;
    status   = dlg->m_strStatusRcScrews;
    break;
}
case 106:
{
    CDialog_Smfd_Visual_RC* dlg = (CDialog_Smfd_Visual_RC*)pDlg;
    measured = dlg->m_strRcPins;
    status   = dlg->m_strStatusRcPins;
    break;
}

// -------- POWER --------
case 201:
{
    CDialog_Smfd_Pwr_RC* dlg = (CDialog_Smfd_Pwr_RC*)pDlg;
    measured = dlg->m_strSMFD1Current;
    status   = dlg->m_strStatusSMFD1Current;
    break;
}
case 202:
{
    CDialog_Smfd_Pwr_RC* dlg = (CDialog_Smfd_Pwr_RC*)pDlg;
    measured = dlg->m_strMFD1Current;
    status   = dlg->m_strStatusMFD1Current;
    break;
}


// -------- SOFTWARE --------
case 301:
{
    CDialog_Smfd_Sw_RC* dlg = (CDialog_Smfd_Sw_RC*)pDlg;
    measured = dlg->m_strSmfdSw;
    status   = dlg->m_strStatusSmfdSw;
    break;
}

// -------- ANALOG --------
case 401:
{
    CDialog_SMFD_RC_EOT* dlg = (CDialog_SMFD_RC_EOT*)pDlg;
    measured = dlg->m_stroiltemp;
    status   = dlg->m_strStatusoiltemp;
    break;
}
case 402:
{
    CDialog_SMFD_RC_EOP* dlg = (CDialog_SMFD_RC_EOP*)pDlg;
    measured = dlg->m_stroilpressure;
    status   = dlg->m_strStatusoilpressure;
    break;
}
case 403:
{
    CDialog_SMFD_RC_ET* dlg = (CDialog_SMFD_RC_ET*)pDlg;
    measured = dlg->m_strtorque;
    status   = dlg->m_strStatustorque;
    break;
}
case 404:
{
    CDialog_SMFD_RC_RTP* dlg = (CDialog_SMFD_RC_RTP*)pDlg;
    measured = dlg->m_strrudder;
    status   = dlg->m_strStatusrudder;
    break;
}
case 405:
{
    CDialog_SMFD_RC_ETP* dlg = (CDialog_SMFD_RC_ETP*)pDlg;
    measured = dlg->m_strelevator;
    status   = dlg->m_strStatuselevator;
    break;
}
case 406:
{
    CDialog_SMFD_RC_ATP* dlg = (CDialog_SMFD_RC_ATP*)pDlg;
    measured = dlg->m_straileron;
    status   = dlg->m_strStatusaileron;
    break;
}
case 407:
{
    CDialog_SMFD_RC_FP3* dlg = (CDialog_SMFD_RC_FP3*)pDlg;
    measured = dlg->m_strflap3v;
    status   = dlg->m_strStatusflap3v;
    break;
}
case 408:
{
    CDialog_SMFD_RC_FP4* dlg = (CDialog_SMFD_RC_FP4*)pDlg;
    measured = dlg->m_strflap4v;
    status   = dlg->m_strStatusflap4v;
    break;
}
case 409:
{
    CDialog_SMFD_RC_GV* dlg = (CDialog_SMFD_RC_GV*)pDlg;
    measured = dlg->m_strgenvolt;
    status   = dlg->m_strStatusgenvolt;
    break;
}
case 410:
{
    CDialog_SMFD_RC_BV* dlg = (CDialog_SMFD_RC_BV*)pDlg;
    measured = dlg->m_strbatvolt;
    status   = dlg->m_strStatusbatvolt;
    break;
}
case 411:
{
    CDialog_SMFD_RC_ANCL* dlg = (CDialog_SMFD_RC_ANCL*)pDlg;
    measured = dlg->m_strcurload;
    status   = dlg->m_strStatuscurload;
    break;
}

// -------- FUEL --------
case 501:
{
    CDialog_Smfd_Fuel_RC* dlg = (CDialog_Smfd_Fuel_RC*)pDlg;
    measured = dlg->m_strSmfdfuel;
    status   = dlg->m_strStatusSmfdfuel;
    break;
}

// -------- REV --------
case 701:
{
    CDialog_Smfd_Rev_RC* dlg = (CDialog_Smfd_Rev_RC*)pDlg;
    measured = dlg->m_strSMFDRevPage;
    status   = dlg->m_strStatusSMFDRevPage;
    break;
}

// -------- ANALOG2 --------

case 412:
{
    CDialog_SMFD_RC_HPM* dlg = (CDialog_SMFD_RC_HPM*)pDlg;
    measured = dlg->m_strHydPresMain;
    status   = dlg->m_strStatusHydPresMain;
    break;
}
case 413:
{
    CDialog_SMFD_RC_HPE* dlg = (CDialog_SMFD_RC_HPE*)pDlg;
    measured = dlg->m_strHydPresEmer;
    status   = dlg->m_strStatusHydPresEmer;
    break;
}
case 414:
{
    CDialog_SMFD_RC_EB* dlg = (CDialog_SMFD_RC_EB*)pDlg;
    measured = dlg->m_strEmerBrake;
    status   = dlg->m_strStatusEmerBrake;
    break;
}
case 415:
{
    CDialog_SMFD_RC_LBP* dlg = (CDialog_SMFD_RC_LBP*)pDlg;
    measured = dlg->m_strLhBrake;
    status   = dlg->m_strStatusLhBrake;
    break;
}
case 416:
{
    CDialog_SMFD_RC_RBP* dlg = (CDialog_SMFD_RC_RBP*)pDlg;
    measured = dlg->m_strRhBrake;
    status   = dlg->m_strStatusRhBrake;
    break;
}
case 417:
{
    CDialog_SMFD_RC_ES* dlg = (CDialog_SMFD_RC_ES*)pDlg;
    measured = dlg->m_strEngineSpd;
    status   = dlg->m_strStatusEngineSpd;
    break;
}
case 418:
{
    CDialog_SMFD_RC_FTL* dlg = (CDialog_SMFD_RC_FTL*)pDlg;
    measured = dlg->m_strFuelLh;
    status   = dlg->m_strStatusFuelLh;
    break;
}
case 419:
{
    CDialog_SMFD_RC_FTR* dlg = (CDialog_SMFD_RC_FTR*)pDlg;
    measured = dlg->m_strFuelRh;
    status   = dlg->m_strStatusFuelRh;
    break;
}
case 420:
{
    CDialog_SMFD_RC_CT* dlg = (CDialog_SMFD_RC_CT*)pDlg;
    measured = dlg->m_strCollectorTank;
    status   = dlg->m_strStatusCollectorTank;
    break;
}

// -------- ADC --------
case 801:
{
    CDialog_Smfd_Adc_RC* dlg = (CDialog_Smfd_Adc_RC*)pDlg;
    measured = dlg->m_strSmfdAdc203;
    status   = dlg->m_strStatusSmfdAdc203;
    break;
}
case 802:
{
    CDialog_Smfd_Adc_RC* dlg = (CDialog_Smfd_Adc_RC*)pDlg;
    measured = dlg->m_strSmfdAdc205;
    status   = dlg->m_strStatusSmfdAdc205;
    break;
}
case 803:
{
    CDialog_Smfd_Adc_RC* dlg = (CDialog_Smfd_Adc_RC*)pDlg;
    measured = dlg->m_strSmfdAdc206;
    status   = dlg->m_strStatusSmfdAdc206;
    break;
}
case 804:
{
    CDialog_Smfd_Adc_RC* dlg = (CDialog_Smfd_Adc_RC*)pDlg;
    measured = dlg->m_strSmfdAdc212;
    status   = dlg->m_strStatusSmfdAdc212;
    break;
}
case 805:
{
    CDialog_Smfd_Adc_RC* dlg = (CDialog_Smfd_Adc_RC*)pDlg;
    measured = dlg->m_strSmfdAdc213;
    status   = dlg->m_strStatusSmfdAdc213;
    break;
}
case 806:
{
    CDialog_Smfd_Adc_RC* dlg = (CDialog_Smfd_Adc_RC*)pDlg;
    measured = dlg->m_strSmfdAdc210;
    status   = dlg->m_strStatusSmfdAdc210;
    break;
}

// -------- AHRS --------
case 901:
{
    CDialog_Smfd_AHRS_RC* dlg = (CDialog_Smfd_AHRS_RC*)pDlg;
    measured = dlg->m_strSmfdAhrs320;
    status   = dlg->m_strStatusSmfdAhrs320;
    break;
}
case 902:
{
    CDialog_Smfd_AHRS_RC* dlg = (CDialog_Smfd_AHRS_RC*)pDlg;
    measured = dlg->m_strSmfdAhrs324;
    status   = dlg->m_strStatusSmfdAhrs324;
    break;
}
case 903:
{
    CDialog_Smfd_AHRS_RC* dlg = (CDialog_Smfd_AHRS_RC*)pDlg;
    measured = dlg->m_strSmfdAhrs325;
    status   = dlg->m_strStatusSmfdAhrs325;
    break;
}
case 904:
{
    CDialog_Smfd_AHRS_RC* dlg = (CDialog_Smfd_AHRS_RC*)pDlg;
    measured = dlg->m_strSmfdAhrs330;
    status   = dlg->m_strStatusSmfdAhrs330;
    break;
}
case 905:
{
    CDialog_Smfd_AHRS_RC* dlg = (CDialog_Smfd_AHRS_RC*)pDlg;
    measured = dlg->m_strSmfdAhrs332;
    status   = dlg->m_strStatusSmfdAhrs332;
    break;
}
case 906:
{
    CDialog_Smfd_AHRS_RC* dlg = (CDialog_Smfd_AHRS_RC*)pDlg;
    measured = dlg->m_strSmfdAhrs333;
    status   = dlg->m_strStatusSmfdAhrs333;
    break;
}

// -------- VOR/ILS --------
case 1001:
{
    CDialog_Smfd_Vorils_RC* dlg = (CDialog_Smfd_Vorils_RC*)pDlg;
    measured = dlg->m_strvorfreq;
    status   = dlg->m_strStatusvorfreq;
    break;
}
case 1002:
{
    CDialog_Smfd_Vorils_RC* dlg = (CDialog_Smfd_Vorils_RC*)pDlg;
    measured = dlg->m_strilsfreq;
    status   = dlg->m_strStatusilsfreq;
    break;
}
case 1003:
{
    CDialog_Smfd_Vorils_RC* dlg = (CDialog_Smfd_Vorils_RC*)pDlg;
    measured = dlg->m_strvorbrg;
    status   = dlg->m_strStatusvorbrg;
    break;
}
case 1004:
{
    CDialog_Smfd_Vorils_RC* dlg = (CDialog_Smfd_Vorils_RC*)pDlg;
    measured = dlg->m_strlocalizer;
    status   = dlg->m_strStatuslocalizer;
    break;
}
case 1005:
{
    CDialog_Smfd_Vorils_RC* dlg = (CDialog_Smfd_Vorils_RC*)pDlg;
    measured = dlg->m_strglideslope;
    status   = dlg->m_strStatusglideslope;
    break;
}

// -------- TACAN --------
case 1101:
{
    CDialog_Smfd_Tacan_RC* dlg = (CDialog_Smfd_Tacan_RC*)pDlg;
    measured = dlg->m_strtac145;
    status   = dlg->m_strStatustac145;
    break;
}
case 1102:
{
    CDialog_Smfd_Tacan_RC* dlg = (CDialog_Smfd_Tacan_RC*)pDlg;
    measured = dlg->m_strtac201;
    status   = dlg->m_strStatustac201;
    break;
}
case 1103:
{
    CDialog_Smfd_Tacan_RC* dlg = (CDialog_Smfd_Tacan_RC*)pDlg;
    measured = dlg->m_strtac222;
    status   = dlg->m_strStatustac222;
    break;
}

// -------- DISCRETE --------
case 601:
{
    CDialog_Smfd_Discrete_RC* dlg = (CDialog_Smfd_Discrete_RC*)pDlg;
    measured = dlg->m_strBusTie;
    status   = dlg->m_strStatusBusTie;
    break;
}
case 602:
{
    CDialog_Smfd_Discrete_RC* dlg = (CDialog_Smfd_Discrete_RC*)pDlg;
    measured = dlg->m_strCanopy;
    status   = dlg->m_strStatusCanopy;
    break;
}
case 603:
{
    CDialog_Smfd_Discrete_RC* dlg = (CDialog_Smfd_Discrete_RC*)pDlg;
    measured = dlg->m_strEcsoff;
    status   = dlg->m_strStatusEcsoff;
    break;
}
case 604:
{
    CDialog_Smfd_Discrete_RC* dlg = (CDialog_Smfd_Discrete_RC*)pDlg;
    measured = dlg->m_strEcsOvPr;
    status   = dlg->m_strStatusEcsOvPr;
    break;
}
case 605:
{
    CDialog_Smfd_Discrete_RC* dlg = (CDialog_Smfd_Discrete_RC*)pDlg;
    measured = dlg->m_strAoamute;
    status   = dlg->m_strStatusAoamute;
    break;
}
case 606:
{
    CDialog_Smfd_Discrete_RC* dlg = (CDialog_Smfd_Discrete_RC*)pDlg;
    measured = dlg->m_strAlarmMute;
    status   = dlg->m_strStatusAlarmMute;
    break;
}
case 607:
{
    CDialog_Smfd_Discrete_RC* dlg = (CDialog_Smfd_Discrete_RC*)pDlg;
    measured = dlg->m_strDemist;
    status   = dlg->m_strStatusDemist;
    break;
}
case 608:
{
    CDialog_Smfd_Discrete_RC* dlg = (CDialog_Smfd_Discrete_RC*)pDlg;
    measured = dlg->m_strStarton;
    status   = dlg->m_strStatusStarton;
    break;
}

// -------- GPS --------
case 1201:
{
    CDialog_Smfd_Gps_RC* dlg = (CDialog_Smfd_Gps_RC*)pDlg;
    measured = dlg->m_strSmfdGpsGrSpd;
    status   = dlg->m_strStatusSmfdGpsGrSpd;
    break;
}
case 1202:
{
    CDialog_Smfd_Gps_RC* dlg = (CDialog_Smfd_Gps_RC*)pDlg;
    measured = dlg->m_strSmfdGpsTrueTrack;
    status   = dlg->m_strStatusSmfdGpsTrueTrack;
    break;
}
case 1203:
{
    CDialog_Smfd_Gps_RC* dlg = (CDialog_Smfd_Gps_RC*)pDlg;
    measured = dlg->m_strSmfdGpsMagTrack;
    status   = dlg->m_strStatusSmfdGpsMagTrack;
    break;
}
case 1204:
{
    CDialog_Smfd_Gps_RC* dlg = (CDialog_Smfd_Gps_RC*)pDlg;
    measured = dlg->m_strSmfdGpsTime;
    status   = dlg->m_strStatusSmfdGpsTime;
    break;
}

        // -------- DEFAULT --------
        default:
            measured = "";
            status   = "NOT OK";
            break;
    }

    // -------- STORE --------
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val, measured);
    strcpy(s_Curr_Test_Result.m_strTestStatus, status);

    // Reset dialog flag at end of group
    if (bLastInGroup)
        bDlgFlag = FALSE;

    pUseFile->Write(&s_Curr_Test_Result, sizeof(s_Curr_Test_Result));

    FillListCtrl(*DynListCtrl);
}
#endif
void CSIPUPowerONPage::ExecuteADCSequence(CFile* pFile)
{
	BOOL bDlgFlag = FALSE;
	int iStartTest, iEndTest, iCurrentTest, iCurr_Pointer, iResult;
	CString strTmpName;

	iTempCount = 0;
	//g_nItem = 0;

	//CFile fptr;

	if(!ValidateUserInput(strTmpName))
		return;

	CSIPU_SDU_GndRigApp *pMainFrame;
	pMainFrame = (CSIPU_SDU_GndRigApp *)AfxGetApp();

	UpdateData(TRUE);
	CString strCurrDateTime, strCurrDateTime1 ;
    SYSTEMTIME sysTime;
    ::GetLocalTime(&sysTime);

    strCurrDateTime.Format("%s_%d_%d_%d_%dH%dM%dS",
        strTmpName, sysTime.wDay, sysTime.wMonth, sysTime.wYear,
        sysTime.wHour, sysTime.wMinute, sysTime.wSecond);

    strCurrDateTime1.Format("%d/%d/%d",
        sysTime.wDay, sysTime.wMonth, sysTime.wYear);
 

	CFile fptr;
CFile* pUseFile = pFile;

if(pUseFile == NULL)
{
    // 👉 STANDALONE MODE → create file here
    CString strTmpName;

    if(!ValidateUserInput(strTmpName))
        return;

    CFileDialog dlg(TRUE, "bin", strCurrDateTime,
        OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
        "Binary Files(*.BIN)|*.BIN||", this);

    if(dlg.DoModal() == IDCANCEL)
        return;

    if(!fptr.Open(dlg.GetPathName(),
        CFile::typeBinary | CFile::modeWrite | CFile::modeCreate))
        return;

    pUseFile = &fptr;

    // write header
	 strcpy(s_Index_Page.m_strOperator, pMainFrame->m_strLogin_UserName);
    strcpy(s_Index_Page.m_strTestDescription, (LPCTSTR)m_edtStrTestDesc);
    sprintf(s_Index_Page.m_strDateTime, "%s", strCurrDateTime1);
    strcpy(s_Index_Page.m_strFileName, dlg.GetPathName());
    pUseFile->Write(&s_Index_Page, sizeof(s_Index_Page));
}
	// ---------------- DIALOG OBJECTS ----------------
	CDialog_ADC_Visual dlgVisual;
	CDialog_ADC_LEAK   dlgLeak;
	CDlg_ADC_PWR  dlgPower;
	CDialog_ADC_FUNCHK   dlgFunc;
	CDialog_ADC_ALTI2 dlgAlti2;
	CDialog_ADC_ALTI3 dlgAlti3;
	CDialog_ADC_ALTIRATE dlgAltiRate;
	CDialog_ADC_AIR1 dlgAir1;
	CDialog_ADC_AIR2 dlgAir2;
	CDialog_ADC_AIR3 dlgAir3;
	CDialog_ADC_MachCHK dlgMach;
	CDialog_ADC_MACH2 dlgMach2;

	
	BOOL bIntegrationMode = (m_Cambo_Mode.GetCurSel() == 0);

    #define ADD_TEST(idInteg,idStandalone,majStandalone,majName,minName,dlgPtr,exp)\
    s_AllTestDetails[iTempCount].m_ucMajor_Test_ID = bIntegrationMode ? 3 : majStandalone;\
    s_AllTestDetails[iTempCount].m_uiMinor_Test_ID = bIntegrationMode ? idInteg : idStandalone;\
    s_AllTestDetails[iTempCount].m_strMajor_Test_Name = majName;\
    s_AllTestDetails[iTempCount].m_strMinor_Test_Name = minName;\
    s_AllTestDetails[iTempCount].m_Procedure_Dlg = dlgPtr;\
    s_AllTestDetails[iTempCount].m_strExpected = exp;\
    iTempCount++;

	// ---------------- TEST TABLE ----------------

// VISUAL (301–302)

ADD_TEST(301,101,1,"ADC Visual Inspection","Part Number",&dlgVisual,"U104.01.0000 ADC 2601 A HTT1");
ADD_TEST(302,102,1,"ADC Visual Inspection","Any Physical Damage",&dlgVisual,"NO");
ADD_TEST(303,103,1,"ADC Visual Inspection","Any Pressure holes blocked",&dlgVisual,"NO");
ADD_TEST(304,104,1,"ADC Visual Inspection","Corrosion on unit",&dlgVisual,"NO");
ADD_TEST(305,105,1,"ADC Visual Inspection","Any Foreign material & Loose Parts",&dlgVisual,"NO");
ADD_TEST(306,106,1,"ADC Visual Inspection","Marking on Pressure Connector",&dlgVisual,"YES");

// Leak
ADD_TEST(307,201,2,"ADC Leak Test","Pitot Leak",&dlgLeak,"<0.1Hg");
ADD_TEST(308,202,2,"ADC Leak Test","Static Leak",&dlgLeak,"<0.1Hg");

// Power
ADD_TEST(309,301,3,"ADC Power","Current",&dlgPower,"100mA");

// Functional
ADD_TEST(310,401,4,"ADC Altitude","7500",&dlgFunc,"7500±30 ft");
ADD_TEST(311,402,4,"ADC Altitude","15000",&dlgAlti2,"15000±45 ft");
ADD_TEST(312,403,4,"ADC Altitude","20000",&dlgAlti3,"20000±50 ft");
ADD_TEST(313,404,4,"ADC Altitude Rate","Positive",&dlgAltiRate,"Operational");
ADD_TEST(314,405,4,"ADC Altitude Rate","Negative",&dlgAltiRate,"Operational");
ADD_TEST(315,406,4,"ADC Airspeed","100",&dlgAir1,"100±5 knots");
ADD_TEST(316,407,4,"ADC Airspeed","180",&dlgAir2,"183±4 konts");
ADD_TEST(317,408,4,"ADC Airspeed","220",&dlgAir3,"223±4 knots");
ADD_TEST(318,409,4,"ADC Mach","Mach 1",&dlgMach,"0.29 M");
ADD_TEST(319,410,4,"ADC Mach","Mach 2",&dlgMach2,"0.36 M");

	// ---------------- EXECUTION RANGE ----------------
	if(bIntegrationMode)
{
    iStartTest = 300;
    iEndTest   = 399;
}
else
{
    iStartTest = 100;
    iEndTest   = 499;
}

	// ---------------- EXECUTION LOOP ----------------
	// ---------------- EXECUTION LOOP ----------------

	for(iCurrentTest=iStartTest;
    iCurrentTest<=iEndTest;
    iCurrentTest++)
{
	if (g_bStopRequested)
		break;
    if(iCurrentTest%100<=DU_ATP_MAX_NO_OF_SUBTEST)
    {
        for(iCurr_Pointer=0;
            iCurr_Pointer<iTempCount;
            iCurr_Pointer++)
        {
            if(iCurrentTest==
                s_AllTestDetails[iCurr_Pointer].m_uiMinor_Test_ID)
            {
                s_Curr_Test_Result.m_uiMinor_Test_ID=iCurrentTest;

                strcpy(
                    s_Curr_Test_Result.m_strMajorTestName,
                    s_AllTestDetails[iCurr_Pointer].m_strMajor_Test_Name);

                strcpy(
                    s_Curr_Test_Result.m_strMinorTestName,
                    s_AllTestDetails[iCurr_Pointer].m_strMinor_Test_Name);

                strcpy(
                    s_Curr_Test_Result.m_strSpec,
                    s_AllTestDetails[iCurr_Pointer].m_strExpected);
				 SetSelectedControls(iCurrentTest);
                if(!bDlgFlag)
                {
                    iResult = ShowTestProcedure(
                        s_AllTestDetails[iCurr_Pointer].m_Procedure_Dlg);
					if (g_bStopRequested)
						break;

                    bDlgFlag=TRUE;
                }

                switch(iCurr_Pointer)
                {

    //---------------- VISUAL ----------------//

case 0:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val,
           dlgVisual.m_strADCSrNo);
    strcpy(s_Curr_Test_Result.m_strTestStatus,
           dlgVisual.m_strStatusADCSrNo);
    break;

case 1:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val,
           dlgVisual.m_strADCDamage);
    strcpy(s_Curr_Test_Result.m_strTestStatus,
           dlgVisual.m_strStatusADCDamage);
    break;

case 2:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val,
           dlgVisual.m_strADCScratches);
    strcpy(s_Curr_Test_Result.m_strTestStatus,
           dlgVisual.m_strStatusADCScratches);
    break;

case 3:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val,
           dlgVisual.m_strADCScrews);
    strcpy(s_Curr_Test_Result.m_strTestStatus,
           dlgVisual.m_strStatusADCScrews);
    break;

case 4:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val,
           dlgVisual.m_strADCPins);
    strcpy(s_Curr_Test_Result.m_strTestStatus,
           dlgVisual.m_strStatusADCPins);
    break;

case 5:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val,
           dlgVisual.m_strADCMarking);
    strcpy(s_Curr_Test_Result.m_strTestStatus,
           dlgVisual.m_strStatusADCMarking);

    bDlgFlag = FALSE;        // Last Visual Test
    break;


//---------------- LEAK ----------------//

case 6:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val,
           dlgLeak.m_strPitot);
    strcpy(s_Curr_Test_Result.m_strTestStatus,
           dlgLeak.m_strStatusPitot);
    break;

case 7:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val,
           dlgLeak.m_strStatic);
    strcpy(s_Curr_Test_Result.m_strTestStatus,
           dlgLeak.m_strStatusStatic);

    bDlgFlag = FALSE;        // Last Leak Test
    break;


//---------------- POWER ----------------//

case 8:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val,
           dlgPower.m_strADCCurrent);
    strcpy(s_Curr_Test_Result.m_strTestStatus,
           dlgPower.m_strStatusADCCurrent);

    bDlgFlag = FALSE;
    break;


//---------------- ALTITUDE ----------------//

case 9:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val,
           dlgFunc.m_strAltitude1);
    strcpy(s_Curr_Test_Result.m_strTestStatus,
           dlgFunc.m_strStatusAltitude1);

    bDlgFlag = FALSE;
    break;

case 10:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val,
           dlgAlti2.m_strAltitude2);
    strcpy(s_Curr_Test_Result.m_strTestStatus,
           dlgAlti2.m_strStatusAltitude2);

    bDlgFlag = FALSE;
    break;

case 11:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val,
           dlgAlti3.m_strAltitude3);
    strcpy(s_Curr_Test_Result.m_strTestStatus,
           dlgAlti3.m_strStatusAltitude3);

    bDlgFlag = FALSE;
    break;


//---------------- ALTITUDE RATE ----------------//

case 12:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val,
           dlgAltiRate.m_strAltiRate1);
    strcpy(s_Curr_Test_Result.m_strTestStatus,
           dlgAltiRate.m_strStatusAltiRate1);
    break;

case 13:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val,
           dlgAltiRate.m_strAltiRate2);
    strcpy(s_Curr_Test_Result.m_strTestStatus,
           dlgAltiRate.m_strStatusAltiRate2);

    bDlgFlag = FALSE;
    break;


//---------------- AIRSPEED ----------------//

case 14:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val,
           dlgAir1.m_strAirspeed1);
    strcpy(s_Curr_Test_Result.m_strTestStatus,
           dlgAir1.m_strStatusAirspeed1);

    bDlgFlag = FALSE;
    break;

case 15:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val,
           dlgAir2.m_strAirspeed2);
    strcpy(s_Curr_Test_Result.m_strTestStatus,
           dlgAir2.m_strStatusAirspeed2);

    bDlgFlag = FALSE;
    break;

case 16:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val,
           dlgAir3.m_strAirspeed3);
    strcpy(s_Curr_Test_Result.m_strTestStatus,
           dlgAir3.m_strStatusAirspeed3);

    bDlgFlag = FALSE;
    break;


//---------------- MACH ----------------//

case 17:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val,
           dlgMach.m_strMach1);
    strcpy(s_Curr_Test_Result.m_strTestStatus,
           dlgMach.m_strStatusMach1);

    bDlgFlag = FALSE;
    break;

case 18:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val,
           dlgMach2.m_strMach2);
    strcpy(s_Curr_Test_Result.m_strTestStatus,
           dlgMach2.m_strStatusMach2);

    bDlgFlag = FALSE;        // Last ADC Test
    break;
}
                

                pUseFile->Write(
                    &s_Curr_Test_Result,
                    sizeof(s_Curr_Test_Result));

                FillListCtrl(*DynListCtrl);
            }
        }
    }
    else
    {
        iCurrentTest=((iCurrentTest/100)+1)*100;
    }
}
          if(pFile == NULL)
    {
        fptr.Close();
    }
	 #undef ADD_TEST

}

void CSIPUPowerONPage::ExecuteAHRSTestSequence(CFile* pFile)
{
	BOOL bDlgFlag = FALSE;
	int iStartTest, iEndTest, iCurrentTest, iCurr_Pointer, iResult;
	CString strTmpName;

	iTempCount = 0;
	//g_nItem = 0;

	//CFile fptr;

	if (!ValidateUserInput(strTmpName))
		return;

	CSIPU_SDU_GndRigApp *pMainFrame;
	pMainFrame = (CSIPU_SDU_GndRigApp *)AfxGetApp();

	UpdateData(TRUE);
	CString strCurrDateTime, strCurrDateTime1 ;
    SYSTEMTIME sysTime;
    ::GetLocalTime(&sysTime);

    strCurrDateTime.Format("%s_%d_%d_%d_%dH%dM%dS",
        strTmpName, sysTime.wDay, sysTime.wMonth, sysTime.wYear,
        sysTime.wHour, sysTime.wMinute, sysTime.wSecond);

    strCurrDateTime1.Format("%d/%d/%d",
        sysTime.wDay, sysTime.wMonth, sysTime.wYear);
 


	// ---------------- FILE ----------------
	CFile fptr;
CFile* pUseFile = pFile;

if(pUseFile == NULL)
{
    // 👉 STANDALONE MODE → create file here
    CString strTmpName;

    if(!ValidateUserInput(strTmpName))
        return;

    CFileDialog dlg(TRUE, "bin", strCurrDateTime,
        OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
        "Binary Files(*.BIN)|*.BIN||", this);

    if(dlg.DoModal() == IDCANCEL)
        return;

    if(!fptr.Open(dlg.GetPathName(),
        CFile::typeBinary | CFile::modeWrite | CFile::modeCreate))
        return;

    pUseFile = &fptr;

    // write header
	 strcpy(s_Index_Page.m_strOperator, pMainFrame->m_strLogin_UserName);
    strcpy(s_Index_Page.m_strTestDescription, (LPCTSTR)m_edtStrTestDesc);
    sprintf(s_Index_Page.m_strDateTime, "%s", strCurrDateTime1);
    strcpy(s_Index_Page.m_strFileName, dlg.GetPathName());
    pUseFile->Write(&s_Index_Page, sizeof(s_Index_Page));
}
	// ---------------- DIALOG ----------------
	CDialog_AHRS_VISUAL dlgAHRS;
	CDialog_AHRS_PWR dlgAHRSPWR;
	CDialog_AHRS_QualityChecks dlgAHRSQuality;

	// ---------------- TEST TABLE ----------------


   BOOL bIntegrationMode = (m_Cambo_Mode.GetCurSel() == 0);

#define ADD_TEST(idInteg,idStandalone,majStandalone,majName,minName,dlgPtr,exp)\
    s_AllTestDetails[iTempCount].m_ucMajor_Test_ID = bIntegrationMode ? 4 : majStandalone;\
    s_AllTestDetails[iTempCount].m_uiMinor_Test_ID = bIntegrationMode ? idInteg : idStandalone;\
    s_AllTestDetails[iTempCount].m_strMajor_Test_Name = majName;\
    s_AllTestDetails[iTempCount].m_strMinor_Test_Name = minName;\
    s_AllTestDetails[iTempCount].m_Procedure_Dlg = dlgPtr;\
    s_AllTestDetails[iTempCount].m_strExpected = exp;\
    iTempCount++;
  

	// AHRS VISUAL (401–404)
// Visual
ADD_TEST(401,101,1,"AHRS Visual Inspection","AHRU Part No",&dlgAHRS,"420-00332-440");
ADD_TEST(402,102,1,"AHRS Visual Inspection","RMM Part No",&dlgAHRS,"420-01867-310");
ADD_TEST(403,103,1,"AHRS Visual Inspection","MMS Part No",&dlgAHRS,"420-00339-000");
ADD_TEST(404,104,1,"AHRS Visual Inspection","Damage Check",&dlgAHRS,"OK");
ADD_TEST(405,105,1,"AHRS Visual Inspection","Scratches Check",&dlgAHRS,"OK");
ADD_TEST(406,106,1,"AHRS Visual Inspection","Screws Check",&dlgAHRS,"OK");
ADD_TEST(407,107,1,"AHRS Visual Inspection","Bend Pins Check",&dlgAHRS,"OK");

// Power
ADD_TEST(408,201,2,"AHRS Power Consumption","Current @28V",&dlgAHRSPWR,"<1.1 A");

// Quality
ADD_TEST(409,301,3,"AHRS Quality Checks","Pitch Angle Check",&dlgAHRSQuality,"OK");
ADD_TEST(410,302,3,"AHRS Quality Checks","Roll Angle Check",&dlgAHRSQuality,"OK");
ADD_TEST(411,303,3,"AHRS Quality Checks","Heading Angle Check",&dlgAHRSQuality,"OK");
	// ---------------- EXECUTION RANGE ----------------
	if(bIntegrationMode)
{
    iStartTest = 400;
    iEndTest   = 499;
}
else
{
    iStartTest = 100;
    iEndTest   = 399;
}

	// ---------------- EXECUTION LOOP ----------------
	for(iCurrentTest=iStartTest;
    iCurrentTest<=iEndTest;
    iCurrentTest++)
{
	if (g_bStopRequested)
		break;
    if(iCurrentTest%100<=DU_ATP_MAX_NO_OF_SUBTEST)
    {
        for(iCurr_Pointer=0;
            iCurr_Pointer<iTempCount;
            iCurr_Pointer++)
        {
            if(iCurrentTest==
                s_AllTestDetails[iCurr_Pointer].m_uiMinor_Test_ID)
            {
                s_Curr_Test_Result.m_uiMinor_Test_ID=iCurrentTest;

                strcpy(
                    s_Curr_Test_Result.m_strMajorTestName,
                    s_AllTestDetails[iCurr_Pointer].m_strMajor_Test_Name);

                strcpy(
                    s_Curr_Test_Result.m_strMinorTestName,
                    s_AllTestDetails[iCurr_Pointer].m_strMinor_Test_Name);

                strcpy(
                    s_Curr_Test_Result.m_strSpec,
                    s_AllTestDetails[iCurr_Pointer].m_strExpected);


				SetSelectedControls(iCurrentTest);
                if(!bDlgFlag)
                {
                    iResult = ShowTestProcedure(
                        s_AllTestDetails[iCurr_Pointer].m_Procedure_Dlg);
					if (g_bStopRequested)
						break;

                    bDlgFlag = TRUE;
                }

                switch(iCurr_Pointer)
                {
					case 0:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val, dlgAHRS.m_strAHRUPtNo);
    strcpy(s_Curr_Test_Result.m_strTestStatus, dlgAHRS.m_strStatusAHRUPtNo);
    break;

case 1:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val, dlgAHRS.m_strRMMPtNo);
    strcpy(s_Curr_Test_Result.m_strTestStatus, dlgAHRS.m_strStatusRMMPtNo);
    break;

case 2:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val, dlgAHRS.m_strMMSPtNo);
    strcpy(s_Curr_Test_Result.m_strTestStatus, dlgAHRS.m_strStatusMMSPtNo);
    break;

case 3:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val, dlgAHRS.m_strAHRSDamage);
    strcpy(s_Curr_Test_Result.m_strTestStatus, dlgAHRS.m_strStatusAHRSDamage);
    break;

case 4:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val, dlgAHRS.m_strAHRSScratches);
    strcpy(s_Curr_Test_Result.m_strTestStatus, dlgAHRS.m_strStatusAHRSScratches);
    break;

case 5:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val, dlgAHRS.m_strAHRSScrews);
    strcpy(s_Curr_Test_Result.m_strTestStatus, dlgAHRS.m_strStatusAHRSScrews);
    break;

case 6:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val, dlgAHRS.m_strAHRSPins);
    strcpy(s_Curr_Test_Result.m_strTestStatus, dlgAHRS.m_strStatusAHRSPins);
    bDlgFlag = FALSE;
    break;

case 7:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val, dlgAHRSPWR.m_strAHRSCurrent);
    strcpy(s_Curr_Test_Result.m_strTestStatus, dlgAHRSPWR.m_strStatusAHRSCurrent);
    bDlgFlag = FALSE;
    break;

case 8:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val, dlgAHRSQuality.m_strAhrsPitch);
    strcpy(s_Curr_Test_Result.m_strTestStatus, dlgAHRSQuality.m_strStatusAhrsPitch);
    break;

case 9:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val, dlgAHRSQuality.m_strAhrsRoll);
    strcpy(s_Curr_Test_Result.m_strTestStatus, dlgAHRSQuality.m_strStatusAhrsRoll);
    break;

case 10:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val, dlgAHRSQuality.m_strAhrsHeading);
    strcpy(s_Curr_Test_Result.m_strTestStatus, dlgAHRSQuality.m_strStatusAhrsHeading);
    bDlgFlag = FALSE;
    break;
                }

                pUseFile->Write(
                    &s_Curr_Test_Result,
                    sizeof(s_Curr_Test_Result));

                if(DynListCtrl != NULL)
                    FillListCtrl(*DynListCtrl);
            }
        }
    }
    else
    {
        iCurrentTest=((iCurrentTest/100)+1)*100;
    }
}

	if(pFile == NULL)
    {
        fptr.Close();
    }
}

void CSIPUPowerONPage::ExecuteGPSTestSequence(CFile* pFile)
{
	BOOL bDlgFlag = FALSE;
	int iStartTest, iEndTest, iCurrentTest, iCurr_Pointer, iResult;
	CString strTmpName;

	iTempCount = 0;
	//g_nItem = 0;

	//CFile fptr;

	if (!ValidateUserInput(strTmpName))
		return;
	CSIPU_SDU_GndRigApp *pMainFrame;
	pMainFrame = (CSIPU_SDU_GndRigApp *)AfxGetApp();

	UpdateData(TRUE);
	CString strCurrDateTime, strCurrDateTime1 ;
    SYSTEMTIME sysTime;
    ::GetLocalTime(&sysTime);

    strCurrDateTime.Format("%s_%d_%d_%d_%dH%dM%dS",
        strTmpName, sysTime.wDay, sysTime.wMonth, sysTime.wYear,
        sysTime.wHour, sysTime.wMinute, sysTime.wSecond);

    strCurrDateTime1.Format("%d/%d/%d",
        sysTime.wDay, sysTime.wMonth, sysTime.wYear);
 

	// ---------------- FILE ----------------
CFile fptr;
CFile* pUseFile = pFile;

if(pUseFile == NULL)
{
    // 👉 STANDALONE MODE → create file here
    CString strTmpName;

    if(!ValidateUserInput(strTmpName))
        return;

    CFileDialog dlg(TRUE, "bin", strCurrDateTime,
        OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
        "Binary Files(*.BIN)|*.BIN||", this);

    if(dlg.DoModal() == IDCANCEL)
        return;

    if(!fptr.Open(dlg.GetPathName(),
        CFile::typeBinary | CFile::modeWrite | CFile::modeCreate))
        return;

    pUseFile = &fptr;

    // write header
	 strcpy(s_Index_Page.m_strOperator, pMainFrame->m_strLogin_UserName);
    strcpy(s_Index_Page.m_strTestDescription, (LPCTSTR)m_edtStrTestDesc);
    sprintf(s_Index_Page.m_strDateTime, "%s", strCurrDateTime1);
    strcpy(s_Index_Page.m_strFileName, dlg.GetPathName());
    pUseFile->Write(&s_Index_Page, sizeof(s_Index_Page));
}

	// ---------------- DIALOG ----------------
	CDialog_GPS_VISUAL dlgGPSVisual;
	CDialog_GPS_PWR dlgGPSPWR;
	CDialog_GPS_DBInfo dlgGPSDbInfo;
	CDialog_GPS_SYSINFO dlgGPSSysInfo;


BOOL bIntegrationMode = (m_Cambo_Mode.GetCurSel() == 0);

#define ADD_TEST(idInteg,idStandalone,majStandalone,majName,minName,dlgPtr,exp)\
    s_AllTestDetails[iTempCount].m_ucMajor_Test_ID = bIntegrationMode ? 5 : majStandalone;\
    s_AllTestDetails[iTempCount].m_uiMinor_Test_ID = bIntegrationMode ? idInteg : idStandalone;\
    s_AllTestDetails[iTempCount].m_strMajor_Test_Name = majName;\
    s_AllTestDetails[iTempCount].m_strMinor_Test_Name = minName;\
    s_AllTestDetails[iTempCount].m_Procedure_Dlg = dlgPtr;\
    s_AllTestDetails[iTempCount].m_strExpected = exp;\
    iTempCount++;

	// -------- VISUAL (501–502) --------
	//---------------- VISUAL ----------------//

ADD_TEST(501,101,1,"GPS Visual Inspection","Part Number",&dlgGPSVisual,"011-04629-00");
ADD_TEST(502,102,1,"GPS Visual Inspection","Damage Check",&dlgGPSVisual,"NO");
//ADD_TEST(503,103,1,"GPS Visual Inspection","Scratches Check",&dlgGPSVisual,"OK");
//ADD_TEST(504,104,1,"GPS Visual Inspection","Screws Check",&dlgGPSVisual,"OK");
//ADD_TEST(505,105,1,"GPS Visual Inspection","Pins Check",&dlgGPSVisual,"OK");

//---------------- POWER ----------------//

ADD_TEST(503,201,2,"GPS Power Consumption","Voltage Check",&dlgGPSPWR,"28V DC ±1V");
ADD_TEST(504,202,2,"GPS Power Consumption","Current Check",&dlgGPSPWR,"1 ±0.7A");

//---------------- DATABASE ----------------//

ADD_TEST(505,301,3,"GPS Database Info","Navigation Check",&dlgGPSDbInfo,"Available");
ADD_TEST(506,302,3,"GPS Database Info","BaseMap Check",&dlgGPSDbInfo,"Available");
ADD_TEST(507,303,3,"GPS Database Info","Obstacle/Hot line Check",&dlgGPSDbInfo,"Available");
ADD_TEST(508,304,3,"GPS Database Info","Safe Taxi Check",&dlgGPSDbInfo,"Available");
ADD_TEST(509,305,3,"GPS Database Info","Terrain Check",&dlgGPSDbInfo,"Available");

//---------------- SYSTEM ----------------//

ADD_TEST(510,401,4,"GPS System","Serial Number",&dlgGPSSysInfo,"Correct");
ADD_TEST(511,402,4,"GPS System","System ID",&dlgGPSSysInfo,"Correct");
ADD_TEST(512,403,4,"GPS System","Main SW",&dlgGPSSysInfo,"Correct");
ADD_TEST(513,404,4,"GPS System","GPS/WAAS SW",&dlgGPSSysInfo,"Correct");



	if(bIntegrationMode)
{
    iStartTest = 500;
    iEndTest   = 599;
}
else
{
    iStartTest = 100;
    iEndTest   = 499;
}

	// ---------------- EXECUTION LOOP ----------------
	for(iCurrentTest=iStartTest;  iCurrentTest<=iEndTest;iCurrentTest++)
{
	if (g_bStopRequested)
		break;
    if(iCurrentTest%100<=DU_ATP_MAX_NO_OF_SUBTEST)
    {
        for(iCurr_Pointer=0;
            iCurr_Pointer<iTempCount;
            iCurr_Pointer++)
        {
            if(iCurrentTest==
                s_AllTestDetails[iCurr_Pointer].m_uiMinor_Test_ID)
            {
                s_Curr_Test_Result.m_uiMinor_Test_ID=iCurrentTest;

                strcpy(
                    s_Curr_Test_Result.m_strMajorTestName,
                    s_AllTestDetails[iCurr_Pointer].m_strMajor_Test_Name);

                strcpy(
                    s_Curr_Test_Result.m_strMinorTestName,
                    s_AllTestDetails[iCurr_Pointer].m_strMinor_Test_Name);

                strcpy(
                    s_Curr_Test_Result.m_strSpec,
                    s_AllTestDetails[iCurr_Pointer].m_strExpected);


				SetSelectedControls(iCurrentTest);
                if(!bDlgFlag)
                {
                    iResult = ShowTestProcedure(
                        s_AllTestDetails[iCurr_Pointer].m_Procedure_Dlg);
					if (g_bStopRequested)
						break;

                    bDlgFlag = TRUE;
                }

					switch(iCurr_Pointer)
						{
						case 0:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val, dlgGPSVisual.m_strGPSPtNo);
    strcpy(s_Curr_Test_Result.m_strTestStatus, dlgGPSVisual.m_strStatusGPSPtNo);
    break;

case 1:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val, dlgGPSVisual.m_strGPSDamage);
    strcpy(s_Curr_Test_Result.m_strTestStatus, dlgGPSVisual.m_strStatusGPSDamage);
	 bDlgFlag = FALSE;
    break;

case 2:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val, dlgGPSPWR.m_strGPS28V);
    strcpy(s_Curr_Test_Result.m_strTestStatus, dlgGPSPWR.m_strStatusGPS28V);
    break;

case 3:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val, dlgGPSPWR.m_strGPSCurrent);
    strcpy(s_Curr_Test_Result.m_strTestStatus, dlgGPSPWR.m_strStatusGPSCurrent);
    bDlgFlag = FALSE;
    break;

case 4:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val, dlgGPSDbInfo.m_strGPSNavi);
    strcpy(s_Curr_Test_Result.m_strTestStatus, dlgGPSDbInfo.m_strStatusGPSNavi);
    break;

case 5:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val, dlgGPSDbInfo.m_strGPSBasemap);
    strcpy(s_Curr_Test_Result.m_strTestStatus, dlgGPSDbInfo.m_strStatusGPSBasemap);
    break;

case 6:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val, dlgGPSDbInfo.m_strGPSObstacle);
    strcpy(s_Curr_Test_Result.m_strTestStatus, dlgGPSDbInfo.m_strStatusGPSObstacle);
    break;

case 7:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val, dlgGPSDbInfo.m_strGPSSafeTaxi);
    strcpy(s_Curr_Test_Result.m_strTestStatus, dlgGPSDbInfo.m_strStatusGPSSafeTaxi);
    break;

case 8:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val, dlgGPSDbInfo.m_strGPSTerrain);
    strcpy(s_Curr_Test_Result.m_strTestStatus, dlgGPSDbInfo.m_strStatusGPSTerrain);
    bDlgFlag = FALSE;
    break;

case 9:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val, dlgGPSSysInfo.m_strGpsSrno);
    strcpy(s_Curr_Test_Result.m_strTestStatus, dlgGPSSysInfo.m_strStatusGpsSrno);
    break;

case 10:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val, dlgGPSSysInfo.m_strGpsSysid);
    strcpy(s_Curr_Test_Result.m_strTestStatus, dlgGPSSysInfo.m_strStatusGpsSysid);
    break;

case 11:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val, dlgGPSSysInfo.m_strGpsSwVr);
    strcpy(s_Curr_Test_Result.m_strTestStatus, dlgGPSSysInfo.m_strStatusGpsSwVr);
    break;

case 12:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val, dlgGPSSysInfo.m_strGpsWaasSw);
    strcpy(s_Curr_Test_Result.m_strTestStatus, dlgGPSSysInfo.m_strStatusGpsWaasSw);
    bDlgFlag = FALSE;
    break;
default:
// Placeholder auto-pass
strcpy(s_Curr_Test_Result.m_strMeasuered_Val, "N/A");
strcpy(s_Curr_Test_Result.m_strTestStatus, "OK");
break;
						 }

                pUseFile->Write(
                    &s_Curr_Test_Result,
                    sizeof(s_Curr_Test_Result));

                if(DynListCtrl != NULL)
                    FillListCtrl(*DynListCtrl);
            }
        }
    }
    else
    {
        iCurrentTest=((iCurrentTest/100)+1)*100;
    }
}

	if(pFile == NULL)
    {
        fptr.Close();
    }
}

void CSIPUPowerONPage::ExecuteVORILSTACTestSequence(CFile* pFile)
{
	BOOL bDlgFlag = FALSE;
	int iStartTest, iEndTest, iCurrentTest, iCurr_Pointer, iResult;
	CString strTmpName;

	iTempCount = 0;
	//g_nItem = 0;

//	CFile fptr;

	if (!ValidateUserInput(strTmpName))
		return;

	CSIPU_SDU_GndRigApp *pMainFrame;
	pMainFrame = (CSIPU_SDU_GndRigApp *)AfxGetApp();

	UpdateData(TRUE);
	CString strCurrDateTime, strCurrDateTime1 ;
    SYSTEMTIME sysTime;
    ::GetLocalTime(&sysTime);

    strCurrDateTime.Format("%s_%d_%d_%d_%dH%dM%dS",
        strTmpName, sysTime.wDay, sysTime.wMonth, sysTime.wYear,
        sysTime.wHour, sysTime.wMinute, sysTime.wSecond);

    strCurrDateTime1.Format("%d/%d/%d",
        sysTime.wDay, sysTime.wMonth, sysTime.wYear);
	// ---------------- FILE ----------------
	CFile fptr;
CFile* pUseFile = pFile;

if(pUseFile == NULL)
{
    // 👉 STANDALONE MODE → create file here
    CString strTmpName;

    if(!ValidateUserInput(strTmpName))
        return;

    CFileDialog dlg(TRUE, "bin", strCurrDateTime,
        OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT,
        "Binary Files(*.BIN)|*.BIN||", this);

    if(dlg.DoModal() == IDCANCEL)
        return;

    if(!fptr.Open(dlg.GetPathName(),
        CFile::typeBinary | CFile::modeWrite | CFile::modeCreate))
        return;

    pUseFile = &fptr;

    // write header
	 strcpy(s_Index_Page.m_strOperator, pMainFrame->m_strLogin_UserName);
    strcpy(s_Index_Page.m_strTestDescription, (LPCTSTR)m_edtStrTestDesc);
    sprintf(s_Index_Page.m_strDateTime, "%s", strCurrDateTime1);
    strcpy(s_Index_Page.m_strFileName, dlg.GetPathName());
    pUseFile->Write(&s_Index_Page, sizeof(s_Index_Page));
}
	// ---------------- DIALOG ----------------
	CDialog_VORTAC_Visual dlgVORTAC_Visual;
	CDialog_VORTAC_PWR  dlgVORTAC_PWR;
	// ---------------- TEST TABLE ----------------
BOOL bIntegrationMode = (m_Cambo_Mode.GetCurSel() == 0);

#define ADD_TEST(idInteg,idStandalone,majStandalone,majName,minName,dlgPtr,exp)\
    s_AllTestDetails[iTempCount].m_ucMajor_Test_ID = bIntegrationMode ? 6 : majStandalone;\
    s_AllTestDetails[iTempCount].m_uiMinor_Test_ID = bIntegrationMode ? idInteg : idStandalone;\
    s_AllTestDetails[iTempCount].m_strMajor_Test_Name = majName;\
    s_AllTestDetails[iTempCount].m_strMinor_Test_Name = minName;\
    s_AllTestDetails[iTempCount].m_Procedure_Dlg = dlgPtr;\
    s_AllTestDetails[iTempCount].m_strExpected = exp;\
    iTempCount++;

	// -------- VISUAL (NAV/VOR/TACAN) --------
//---------------- VISUAL ----------------//

ADD_TEST(601,101,1,"VOR/ILS TACAN Visual","VOR/ILS Receiver",&dlgVORTAC_Visual,"ANS2810A HTT1");
ADD_TEST(602,102,1,"VOR/ILS TACAN Visual","TACAN Receiver",&dlgVORTAC_Visual,"2920A HTT1");
ADD_TEST(603,103,1,"VOR/ILS TACAN Visual","CDU",&dlgVORTAC_Visual,"CDU-2810A HTT1");
ADD_TEST(604,104,1,"VOR/ILS TACAN Visual","Damage Check",&dlgVORTAC_Visual,"NO");

//---------------- POWER ----------------//

ADD_TEST(605,201,2,"VOR/ILS TACAN Power","Power Consumption",&dlgVORTAC_PWR,"< 3 Amps");

	// ---------------- EXECUTION RANGE ----------------
	if(bIntegrationMode)
{
    iStartTest = 600;
    iEndTest   = 699;
}
else
{
    iStartTest = 100;
    iEndTest   = 299;
}

	// ---------------- EXECUTION LOOP ----------------
	for(iCurrentTest=iStartTest;  iCurrentTest<=iEndTest;iCurrentTest++)
{
	if (g_bStopRequested)
		break;
    if(iCurrentTest%100<=DU_ATP_MAX_NO_OF_SUBTEST)
    {
        for(iCurr_Pointer=0;iCurr_Pointer<iTempCount;iCurr_Pointer++)
        {
            if(iCurrentTest==
                s_AllTestDetails[iCurr_Pointer].m_uiMinor_Test_ID)
            {
                s_Curr_Test_Result.m_uiMinor_Test_ID=iCurrentTest;

                strcpy(
                    s_Curr_Test_Result.m_strMajorTestName,
                    s_AllTestDetails[iCurr_Pointer].m_strMajor_Test_Name);

                strcpy(
                    s_Curr_Test_Result.m_strMinorTestName,
                    s_AllTestDetails[iCurr_Pointer].m_strMinor_Test_Name);

                strcpy(
                    s_Curr_Test_Result.m_strSpec,
                    s_AllTestDetails[iCurr_Pointer].m_strExpected);


				SetSelectedControls(iCurrentTest);
                if(!bDlgFlag)
                {
                    iResult = ShowTestProcedure(
                        s_AllTestDetails[iCurr_Pointer].m_Procedure_Dlg);
					if (g_bStopRequested)
						break;

                    bDlgFlag = TRUE;
                }


						switch(iCurr_Pointer)
						{
						case 0:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val,
           dlgVORTAC_Visual.m_strVOR);
    strcpy(s_Curr_Test_Result.m_strTestStatus,
           dlgVORTAC_Visual.m_strStatusVOR);
    break;

case 1:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val,
           dlgVORTAC_Visual.m_strTACAN);
    strcpy(s_Curr_Test_Result.m_strTestStatus,
           dlgVORTAC_Visual.m_strStatusTACAN);
    break;

case 2:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val,
           dlgVORTAC_Visual.m_strCDU);
    strcpy(s_Curr_Test_Result.m_strTestStatus,
           dlgVORTAC_Visual.m_strStatusCDU);
    break;

case 3:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val,
           dlgVORTAC_Visual.m_strDamage);
    strcpy(s_Curr_Test_Result.m_strTestStatus,
           dlgVORTAC_Visual.m_strStatusDamage);

    bDlgFlag = FALSE;      // Last Visual test
    break;

case 4:
    strcpy(s_Curr_Test_Result.m_strMeasuered_Val,
           dlgVORTAC_PWR.m_strVORTACCurrent);
    strcpy(s_Curr_Test_Result.m_strTestStatus,
           dlgVORTAC_PWR.m_strStatusVORTACCurrent);

    bDlgFlag = FALSE;      // Last Power test
    break;
						}
					

					pUseFile->Write(&s_Curr_Test_Result, sizeof(s_Curr_Test_Result));
					FillListCtrl(*DynListCtrl);
				}
			}
		}
		else
		{
			iCurrentTest = ((iCurrentTest / 100) + 1) * 100;
		}
	}

	if(pFile == NULL)
    {
        fptr.Close();
    }
}

BOOL CSIPUPowerONPage::ValidateUserInput(CString &strTmpName)
{
    UpdateData(TRUE);

    int mode = m_Cambo_Mode.GetCurSel();
    int lru  = m_ctlCboDUType.GetCurSel();
	int SMFDSelection = m_ComboSMFDMode.GetCurSel();
    
    CString strDUType;

    //---------------- Test Description ----------------//

    if(m_edtStrTestDesc.IsEmpty())
    {
        AfxMessageBox("Please Enter Test Description");
        GetDlgItem(IDC_EDIT_TEST_DESC)->SetFocus();
        return FALSE;
    }

    if(m_edtStrTestDesc.GetLength() > 150)
    {
        AfxMessageBox("Test Description should not exceed 150 characters");
        GetDlgItem(IDC_EDIT_TEST_DESC)->SetFocus();
        return FALSE;
    }

    //---------------- INTEGRATION MODE ----------------//

    if(mode == MODE_INTEGRATION)
    {
        if(!CheckSerial(m_strSMFD1SNO, IDC_EDIT_SMFD1_SNO, "SMFD1")) return FALSE;
        if(!CheckSerial(m_strSMFD2SNO, IDC_EDIT_SMFD2_SNO, "SMFD2")) return FALSE;
        if(!CheckSerial(m_strMFD1SNO, IDC_EDIT_MFD1_SNO, "MFD1")) return FALSE;
        if(!CheckSerial(m_strMFD2SNO, IDC_EDIT_MFD2_SNO, "MFD2")) return FALSE;

        if(!CheckSerial(m_strISIS_DU1_SNO, IDC_EDIT_ISIS_DU1_SNO, "ISIS DU1")) return FALSE;
        if(!CheckSerial(m_strISIS_DU2_SNO, IDC_EDIT_ISIS_DU2_SNO, "ISIS DU2")) return FALSE;
        if(!CheckSerial(m_strISIS_ADU_SNO, IDC_EDIT_ISIS_ADU_SNO, "ISIS ADU")) return FALSE;
        if(!CheckSerial(m_strISIS_AHRS_SNO, IDC_EDIT_ISIS_AHRS_SNO, "ISIS AHRS")) return FALSE;
        if(!CheckSerial(m_strISIS_MGM_SNO, IDC_EDIT_ISIS_MGM_SNO, "ISIS MGM")) return FALSE;

        if(!CheckSerial(m_strADC_SNO, IDC_EDIT_ADC_SNO, "ADC")) return FALSE;
        if(!CheckSerial(m_strAHRS_SNO, IDC_EDIT_AHRS_SNO, "AHRS")) return FALSE;
        if(!CheckSerial(m_strGPS_SNO, IDC_EDIT_GPS_SNO, "GPS")) return FALSE;
        if(!CheckSerial(m_strNAV_SNO, IDC_EDIT_VORILS_TACAN_SNO, "NAV")) return FALSE;
		  if(!CheckSerial(m_strNAVTAC_SNO, IDC_EDIT_TACAN_SNO, "NAV")) return FALSE;
        strTmpName = "INTEGRATION_SYSTEM";

        return TRUE;
    }

    //---------------- STANDALONE MODE ----------------//

   // ---------------- STANDALONE MODE ----------------

if(mode == MODE_STANDALONE)
{
    switch(lru)
    {

    // -------- SMFD / MFD --------
    case 0:
	{
      switch(SMFDSelection)
         {
                case 0:     // FC
               strDUType = "SMFD & MFD FC";
		        if(!CheckSerial(m_strSMFD1SNO, IDC_EDIT_SMFD1_SNO, "SMFD1")) return FALSE;
		        if(!CheckSerial(m_strMFD1SNO, IDC_EDIT_MFD1_SNO, "MFD1")) return FALSE;
		        strTmpName.Format("%s_SYSTEM", strDUType);
                 break;

                case 1:     // RC
		         strDUType = "SMFD & MFD RC";
                  if(!CheckSerial(m_strSMFD2SNO, IDC_EDIT_SMFD2_SNO, "SMFD2")) return FALSE;
		             if(!CheckSerial(m_strMFD2SNO, IDC_EDIT_MFD2_SNO, "MFD2")) return FALSE;
		          strTmpName.Format("%s_SYSTEM", strDUType);
                    break;

                  case 2:     // BOTH
					  strDUType = "SMFD & MFD ";
                   if(!CheckSerial(m_strSMFD1SNO, IDC_EDIT_SMFD1_SNO, "SMFD1")) return FALSE;
                   if(!CheckSerial(m_strSMFD2SNO, IDC_EDIT_SMFD2_SNO, "SMFD2")) return FALSE;
                     if(!CheckSerial(m_strMFD1SNO, IDC_EDIT_MFD1_SNO, "MFD1")) return FALSE;
                     if(!CheckSerial(m_strMFD2SNO, IDC_EDIT_MFD2_SNO, "MFD2")) return FALSE;
                      strTmpName.Format("%s_SYSTEM", strDUType);
                       break;
             }
	             break;
		}


       
   // -------- ISIS --------
    case 1:

        strDUType = "ISIS";

        if(!CheckSerial(m_strISIS_DU1_SNO, IDC_EDIT_ISIS_DU1_SNO, "ISIS DU1")) return FALSE;
        if(!CheckSerial(m_strISIS_DU2_SNO, IDC_EDIT_ISIS_DU2_SNO, "ISIS DU2")) return FALSE;
        if(!CheckSerial(m_strISIS_ADU_SNO, IDC_EDIT_ISIS_ADU_SNO, "ISIS ADU")) return FALSE;
        if(!CheckSerial(m_strISIS_AHRS_SNO, IDC_EDIT_ISIS_AHRS_SNO, "ISIS AHRS")) return FALSE;
        if(!CheckSerial(m_strISIS_MGM_SNO, IDC_EDIT_ISIS_MGM_SNO, "ISIS MGM")) return FALSE;

        strTmpName.Format("%s_SYSTEM", strDUType);

    break;


    // -------- ADC --------
    case 2:

        strDUType = "ADC";

        if(!CheckSerial(m_strADC_SNO, IDC_EDIT_ADC_SNO, "ADC")) return FALSE;

        strTmpName.Format("%s_%s", strDUType, m_strADC_SNO);

    break;


    // -------- AHRS --------
    case 3:

        strDUType = "AHRS";

        if(!CheckSerial(m_strAHRS_SNO, IDC_EDIT_AHRS_SNO, "AHRS")) return FALSE;

        strTmpName.Format("%s_%s", strDUType, m_strAHRS_SNO);

    break;


    // -------- GPS --------
    case 4:

        strDUType = "GPS";

        if(!CheckSerial(m_strGPS_SNO, IDC_EDIT_GPS_SNO, "GPS")) return FALSE;

        strTmpName.Format("%s_%s", strDUType, m_strGPS_SNO);

    break;


    // -------- NAV --------
    case 5:

        strDUType = "NAV_SYS";

        if(!CheckSerial(m_strNAV_SNO, IDC_EDIT_VORILS_TACAN_SNO, "NAV")) return FALSE;
		 if(!CheckSerial(m_strNAVTAC_SNO, IDC_EDIT_TACAN_SNO, "NAV")) return FALSE;
        strTmpName.Format("%s_%s", strDUType, m_strNAV_SNO);

    break;


    default:

        AfxMessageBox("Invalid LRU Selection");
        return FALSE;
    }

    return TRUE;
}

    return FALSE;
}
BOOL CSIPUPowerONPage::CheckSerial(const CString& serial, UINT controlID, const CString& name)
{
    if(serial.IsEmpty())
    {
        CString msg;
        msg.Format("Please Enter %s Serial Number", name);
        AfxMessageBox(msg);
        GetDlgItem(controlID)->SetFocus();
        return FALSE;
    }

    if(serial.GetLength() > 15)
    {
        CString msg;
        msg.Format("%s Serial Number should not exceed 15 characters", name);
        AfxMessageBox(msg);
        GetDlgItem(controlID)->SetFocus();
        return FALSE;
    }

    return TRUE;
}
 void CSIPUPowerONPage::OnCbnSelchangeComboDuType()
{
    UpdateData(TRUE);

    int lruIndex = m_ctlCboDUType.GetCurSel();

    // Enable only selected LRU serial inputs
	// Show SMFD Position combo only for SMFD & MFD
if(lruIndex == 0)
{
    GetDlgItem(IDC_COMBO_SMFD_SELECTION)->ShowWindow(TRUE);
    if(m_ComboSMFDMode.GetCurSel() < 0)
        m_ComboSMFDMode.SetCurSel(0);
}
else
{
    GetDlgItem(IDC_COMBO_SMFD_SELECTION)->ShowWindow(SW_HIDE);
  //  GetDlgItem(IDC_COMBO_SMFD_MODE)->ShowWindow(SW_HIDE);
}
    EnableLRUSerialInputs(lruIndex);

    if(lruIndex < 0)
        return;

    m_List_Main_List.ResetContent();

    for(int i = 0; i < LRU_Table[lruIndex].mainCount; i++)
    {
        m_List_Main_List.AddString(LRU_Table[lruIndex].mainTests[i].name);
    }

    m_List_Main_List.SetCurSel(0);

    OnSelchangeListMainTest();

    UpdateData(FALSE);
}

void CSIPUPowerONPage::EnableLRUSerialInputs(int lru)
{
    // First show ALL in integration mode
	
	   int SMFDSelection = m_ComboSMFDMode.GetCurSel();
    if(lru == -1)
    {
        GetDlgItem(IDC_EDIT_SMFD1_SNO)->ShowWindow(TRUE);
        GetDlgItem(IDC_EDIT_SMFD2_SNO)->ShowWindow(TRUE);
        GetDlgItem(IDC_EDIT_MFD1_SNO)->ShowWindow(TRUE);
        GetDlgItem(IDC_EDIT_MFD2_SNO)->ShowWindow(TRUE);

        GetDlgItem(IDC_EDIT_ISIS_DU1_SNO)->ShowWindow(TRUE);
        GetDlgItem(IDC_EDIT_ISIS_DU2_SNO)->ShowWindow(TRUE);
        GetDlgItem(IDC_EDIT_ISIS_ADU_SNO)->ShowWindow(TRUE);
        GetDlgItem(IDC_EDIT_ISIS_AHRS_SNO)->ShowWindow(TRUE);
        GetDlgItem(IDC_EDIT_ISIS_MGM_SNO)->ShowWindow(TRUE);

        GetDlgItem(IDC_EDIT_ADC_SNO)->ShowWindow(TRUE);
        GetDlgItem(IDC_EDIT_AHRS_SNO)->ShowWindow(TRUE);
        GetDlgItem(IDC_EDIT_GPS_SNO)->ShowWindow(TRUE);
        GetDlgItem(IDC_EDIT_VORILS_TACAN_SNO)->ShowWindow(TRUE);
		GetDlgItem(IDC_EDIT_TACAN_SNO)->ShowWindow(TRUE);
        return;
    }

    // ---- Existing logic ----
    // Disable all first
    GetDlgItem(IDC_EDIT_SMFD1_SNO)->ShowWindow(FALSE);
    GetDlgItem(IDC_EDIT_SMFD2_SNO)->ShowWindow(FALSE);
    GetDlgItem(IDC_EDIT_MFD1_SNO)->ShowWindow(FALSE);
    GetDlgItem(IDC_EDIT_MFD2_SNO)->ShowWindow(FALSE);

    GetDlgItem(IDC_EDIT_ISIS_DU1_SNO)->ShowWindow(FALSE);
    GetDlgItem(IDC_EDIT_ISIS_DU2_SNO)->ShowWindow(FALSE);
    GetDlgItem(IDC_EDIT_ISIS_ADU_SNO)->ShowWindow(FALSE);
    GetDlgItem(IDC_EDIT_ISIS_AHRS_SNO)->ShowWindow(FALSE);
    GetDlgItem(IDC_EDIT_ISIS_MGM_SNO)->ShowWindow(FALSE);

    GetDlgItem(IDC_EDIT_ADC_SNO)->ShowWindow(FALSE);
    GetDlgItem(IDC_EDIT_AHRS_SNO)->ShowWindow(FALSE);
    GetDlgItem(IDC_EDIT_GPS_SNO)->ShowWindow(FALSE);
    GetDlgItem(IDC_EDIT_VORILS_TACAN_SNO)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_TACAN_SNO)->ShowWindow(FALSE);
	GetDlgItem(IDC_EDIT_TACAN_SNO)->ShowWindow(FALSE);
    switch(lru)
    {
       case 0:
{
	int SMFDSelection = m_ComboSMFDMode.GetCurSel();
    switch(SMFDSelection)
    {
    case 0:     // FC
        GetDlgItem(IDC_EDIT_SMFD1_SNO)->ShowWindow(TRUE);
        GetDlgItem(IDC_EDIT_MFD1_SNO)->ShowWindow(TRUE);
        break;

    case 1:     // RC
        GetDlgItem(IDC_EDIT_SMFD2_SNO)->ShowWindow(TRUE);
        GetDlgItem(IDC_EDIT_MFD2_SNO)->ShowWindow(TRUE);
        break;

    case 2:     // BOTH
        GetDlgItem(IDC_EDIT_SMFD1_SNO)->ShowWindow(TRUE);
        GetDlgItem(IDC_EDIT_MFD1_SNO)->ShowWindow(TRUE);

        GetDlgItem(IDC_EDIT_SMFD2_SNO)->ShowWindow(TRUE);
        GetDlgItem(IDC_EDIT_MFD2_SNO)->ShowWindow(TRUE);
        break;
    }
}
break;
        break;
        case 1:
            GetDlgItem(IDC_EDIT_ISIS_DU1_SNO)->ShowWindow(TRUE);
            GetDlgItem(IDC_EDIT_ISIS_DU2_SNO)->ShowWindow(TRUE);
            GetDlgItem(IDC_EDIT_ISIS_ADU_SNO)->ShowWindow(TRUE);
            GetDlgItem(IDC_EDIT_ISIS_AHRS_SNO)->ShowWindow(TRUE);
            GetDlgItem(IDC_EDIT_ISIS_MGM_SNO)->ShowWindow(TRUE);
        break;

        case 2:
            GetDlgItem(IDC_EDIT_ADC_SNO)->ShowWindow(TRUE);
        break;

        case 3:
            GetDlgItem(IDC_EDIT_AHRS_SNO)->ShowWindow(TRUE);
        break;

        case 4:
            GetDlgItem(IDC_EDIT_GPS_SNO)->ShowWindow(TRUE);
        break;

        case 5:
            GetDlgItem(IDC_EDIT_VORILS_TACAN_SNO)->ShowWindow(TRUE);
			  GetDlgItem(IDC_EDIT_TACAN_SNO)->ShowWindow(TRUE);
        break;
    }
}



 void CSIPUPowerONPage::OnClose()
{
	

	CFormView::OnClose();
 }

 
