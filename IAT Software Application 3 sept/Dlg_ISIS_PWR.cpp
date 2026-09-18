// Dlg_ISIS_PWR.cpp : implementation file
//

#include "stdafx.h"
#include "Dlg_ISIS_PWR.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "DataStruct.h"
#include "SerialPort.h"

extern BOOL g_bSimulationMode;
extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;
// CDlg_ISIS_PWR dialog
extern CSerialPort gCommPort12;


IMPLEMENT_DYNAMIC(CDlg_ISIS_PWR, CDialog)

CDlg_ISIS_PWR::CDlg_ISIS_PWR(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg_ISIS_PWR::IDD, pParent)
	, m_strCurrent28V(_T(""))
	, m_strCurrentISISDURC(_T(""))
	, m_strCurrentISISADU(_T(""))
	, m_strCurrentISISAHRS(_T(""))

	
{
	m_bThreadRunning = FALSE;
}

CDlg_ISIS_PWR::~CDlg_ISIS_PWR()
{
}

void CDlg_ISIS_PWR::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Text(pDX, IDC_EDIT_ISIS_PWR, m_strCurrent28V);
	DDX_Text(pDX, IDC_EDIT_ISIS_PWRRC, m_strCurrentISISDURC);
	DDX_Text(pDX, IDC_EDIT_ISIS_PWRADU, m_strCurrentISISADU);
	DDX_Text(pDX, IDC_EDIT_ISIS_PWRAHRS, m_strCurrentISISAHRS);
}


BEGIN_MESSAGE_MAP(CDlg_ISIS_PWR, CDialog)
	ON_BN_CLICKED(IDOK, &CDlg_ISIS_PWR::OnBnClickedBtnIsisPwr)
	ON_BN_CLICKED(IDC_BUTTON_ISISPWR, &CDlg_ISIS_PWR::OnBnClickedButtonIsispwr)
	ON_MESSAGE(WM_UPDATE_CURRENT, OnUpdateCurrent)
	ON_MESSAGE(WM_PROGRESS_UPDATE, OnProgressUpdate)
ON_MESSAGE(WM_PROGRESS_CLOSE, OnProgressClose)

END_MESSAGE_MAP()



// CDlg_ISIS_PWR message handlers


BOOL CDlg_ISIS_PWR::OnInitDialog()
{
	//SwitchDiscrete(ISIS_DU_FC_ON,ON);
	
	
	return true;
}

void CDlg_ISIS_PWR::OnBnClickedBtnIsisPwr()
{
	// TODO: Add your control notification handler code here
	CMessageBox_Dlg msgdlg;
    UpdateData(TRUE);

    
    double vdc28 = _tstof(m_strCurrent28V);
    m_strISISPWR.Format("%s", m_strCurrent28V);
	
    if (vdc28 < 1.08)
    {
        m_strStatusCurrent28V = "OK";
    }
    else
    {
        g_strMsgStr = "ISIS-DU FC Power Consumption is out of range, Do You want to Continue?";
        msgdlg.DoModal();

        if (!g_bContinueFlag)
        {
            GetDlgItem(IDC_EDIT_ISIS_PWR)->SetFocus();
            return;
        }

        m_strStatusCurrent28V = "NOT OK";
    }
	/********************** ISIS DU RC POWER ************************************/
	  double vdc28RC = _tstof(m_strCurrentISISDURC);
    m_strMeasISISDURCPWR.Format("%s", m_strCurrentISISDURC);
	
	
    if (vdc28RC < 1.08)
    {
        m_strStatusCurrentISISDURC = "OK";
    }
    else
    {
        g_strMsgStr = "ISIS-DU RC Power Consumption is out of range, Do You want to Continue?";
        msgdlg.DoModal();

        if (!g_bContinueFlag)
        {
            GetDlgItem(IDC_EDIT_ISIS_PWRRC)->SetFocus();
            return;
        }

        m_strStatusCurrentISISDURC = "NOT OK";
    }

		/********************** ISIS ADU  POWER ************************************/
	  double vdc28ADU = _tstof(m_strCurrentISISADU);
    m_strMeasISISADUPWR.Format("%s", m_strCurrentISISADU);
	
	
    if (vdc28ADU < 0.3)
    {
        m_strStatusCurrentISISADU = "OK";
    }
    else
    {
        g_strMsgStr = "ISIS ADU Power Consumption is out of range, Do You want to Continue?";
        msgdlg.DoModal();

        if (!g_bContinueFlag)
        {
            GetDlgItem(IDC_EDIT_ISIS_PWRADU)->SetFocus();
            return;
        }

        m_strStatusCurrentISISADU = "NOT OK";
    }

		/********************** ISIS AHRS  POWER ************************************/
	  double vdc28AHRS = _tstof(m_strCurrentISISAHRS);
    m_strMeasISISAHRSPWR.Format("%s", m_strCurrentISISAHRS);
	
    if (vdc28AHRS < 1)
    {
        m_strStatusCurrentISISAHRS = "OK";
    }
    else
    {
        g_strMsgStr = "ISIS AHRS Power Consumption is out of range, Do You want to Continue?";
        msgdlg.DoModal();

        if (!g_bContinueFlag)
        {
            GetDlgItem(IDC_EDIT_ISIS_PWRAHRS)->SetFocus();
            return;
        }

        m_strStatusCurrentISISAHRS = "NOT OK";
    }

	UpdateData(FALSE);
    CDialog::OnOK();


}


void CDlg_ISIS_PWR::OnBnClickedButtonIsispwr()
{
	// TODO: Add your control notification handler code here
	
	 if(m_bThreadRunning)
        return;

	 if(g_bSimulationMode)
		{	
		 CString message;
		message.Format("Connect load of 3 Amps on power supply.");

		::MessageBox(AfxGetMainWnd() ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
					 message,
					 "ISIS PWR",
					 MB_OK | MB_ICONINFORMATION);
	 }

    m_bThreadRunning = TRUE;

	m_ProgressDlg.Create(IDD_PROGRESS_DIALOG,this);

    m_ProgressDlg.ShowWindow(SW_SHOW);
	SetDlgItemTextA(IDD_PROGRESS_DIALOG,"Test Status from Test No 2.01 to 2.04");

EnableWindow(FALSE);

   CWinThread* pThread = AfxBeginThread(PowerOnThread, this);

if(pThread == NULL)
{  
	m_bThreadRunning = FALSE;
    AfxMessageBox("Thread Creation Failed");
}
else
{
    //AfxMessageBox("Thread Created");
}
}

UINT CDlg_ISIS_PWR::PowerOnThread(LPVOID pParam)
{
    CDlg_ISIS_PWR* pDlg = (CDlg_ISIS_PWR*)pParam;

	try
{
    pDlg->ExecutePowerOnSequence();
}
catch(...)
{
}

pDlg->PostCloseProgress();

pDlg->m_bThreadRunning = FALSE;

return 0;
}

LRESULT CDlg_ISIS_PWR::OnUpdateCurrent(WPARAM, LPARAM)
{
    UpdateData(FALSE);

    return 0;
}

void CDlg_ISIS_PWR::ExecutePowerOnSequence()
{
    double current = 0.0;
	SwitchDiscrete(ISIS_DU_FC_ON, ON);
#if 1
    // Turn ON 28V Supply
  // On28Power("com12");

    /******************** ISIS DU FC ************************/

    SwitchDiscrete(ISIS_DU_FC_ON, ON);
	

	PostProgress(15,
"Powering ON ISIS DU FC...\nPlease wait...");
    Sleep(20000);
		//InitializeSerialPort("com12");
		//Sleep(250);
    current = ReadPowerSupplyValue('C');

    m_strCurrent28V.Format("%.3f", current);
    m_strISISPWR = m_strCurrent28V;      // Report Variable

    PostMessage(WM_UPDATE_CURRENT); 

    SwitchDiscrete(ISIS_DU_FC_ON, OFF);

    Sleep(500);


    /******************** ISIS DU RC ************************/

    SwitchDiscrete(ISIS_DU_RC_ON, ON);
	PostProgress(45,
"Powering ON ISIS DU RC...\nPlease wait...");
    Sleep(20000);

    current = ReadPowerSupplyValue('C');

    m_strCurrentISISDURC.Format("%.3f", current);
    m_strMeasISISDURCPWR = m_strCurrentISISDURC;

    PostMessage(WM_UPDATE_CURRENT);

    SwitchDiscrete(ISIS_DU_RC_ON, OFF);

    Sleep(500);

#if 1
    /******************** ISIS ADU ************************/

    //SwitchDiscrete(ISIS_ADU_ON, ON);
	 PostProgress(75,
"Powering ON ISIS ADU ...\nPlease wait...");
    Sleep(10000);

    current = ReadPowerSupplyValue('C');

    m_strCurrentISISADU.Format("%.3f", current);
    m_strMeasISISADUPWR = m_strCurrentISISADU;

   PostMessage(WM_UPDATE_CURRENT);

   // SwitchDiscrete(ISIS_ADU_ON, OFF);

    Sleep(500);


    /******************** ISIS AHRS ************************/

   // SwitchDiscrete(ISIS_AHRS_ON, ON);
	PostProgress(90,
"Powering ON ISIS AHRS...\nPlease wait...");
   // Sleep(10000);

    current = ReadPowerSupplyValue('C');

    m_strCurrentISISAHRS.Format("%.3f", current);
    m_strMeasISISAHRSPWR = m_strCurrentISISAHRS;

    PostMessage(WM_UPDATE_CURRENT);
PostProgress(100,
"Power Test Completed.");

Sleep(500);
   // SwitchDiscrete(ISIS_AHRS_ON, OFF);

  //  Sleep(500);

    // Optional: Turn OFF 28V Supply
    // Off28Power();
#endif
#endif
#if 0
	m_strCurrent28V = "0.6";
	m_strCurrentISISDURC = "0.6";
		m_strCurrentISISADU = "0.2";
		m_strCurrentISISAHRS = "0.3";
		  m_strISISPWR = m_strCurrent28V;
		    m_strMeasISISAHRSPWR = m_strCurrentISISAHRS;
			  m_strMeasISISADUPWR = m_strCurrentISISADU;
			   m_strMeasISISDURCPWR = m_strCurrentISISDURC;
			   PostMessage(WM_UPDATE_CURRENT);
#endif
}

void CDlg_ISIS_PWR::PostProgress(int nPercent,
                                 LPCTSTR pszText)
{
    PROGRESS_MSG* pMsg = new PROGRESS_MSG;

    pMsg->nPercent = nPercent;
    pMsg->strStatus = pszText;

    PostMessage(WM_PROGRESS_UPDATE,
                0,
                (LPARAM)pMsg);
}

void CDlg_ISIS_PWR::PostCloseProgress()
{
    PostMessage(WM_PROGRESS_CLOSE);
}

LRESULT CDlg_ISIS_PWR::OnProgressUpdate(
        WPARAM,
        LPARAM lParam)
{
    PROGRESS_MSG* pMsg =
        (PROGRESS_MSG*)lParam;

    if(::IsWindow(m_ProgressDlg.GetSafeHwnd()))
    {
        m_ProgressDlg.SetProgress(
                pMsg->nPercent);

        m_ProgressDlg.SetStatus(
                pMsg->strStatus);
    }

    delete pMsg;

    return 0;
}


LRESULT CDlg_ISIS_PWR::OnProgressClose(
        WPARAM,
        LPARAM)
{
    if(::IsWindow(m_ProgressDlg.GetSafeHwnd()))
        m_ProgressDlg.DestroyWindow();

    EnableWindow(TRUE);

    ::SetForegroundWindow(GetSafeHwnd());

    return 0;
}