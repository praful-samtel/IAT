// Dialog_AHRS_QualityChecks.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_AHRS_QualityChecks.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "DataStruct.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_AHRS_QualityChecks dialog

IMPLEMENT_DYNAMIC(CDialog_AHRS_QualityChecks, CDialog)

CDialog_AHRS_QualityChecks::CDialog_AHRS_QualityChecks(CWnd* pParent /*=NULL*/)
	: CDialog(CDialog_AHRS_QualityChecks::IDD, pParent)
	, m_chkAHRSPitch(FALSE)
	, m_chkAHRSRoll(FALSE)
	, m_chkAHRSHeading(FALSE)
	, m_edtAHRSPitch(_T(""))
	, m_edtAHRSRoll(_T(""))
	, m_edtAHRSHeading(_T(""))
{
	m_bThreadRunning = FALSE;
    m_bStopThread = FALSE;
}

CDialog_AHRS_QualityChecks::~CDialog_AHRS_QualityChecks()
{
}

void CDialog_AHRS_QualityChecks::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK_AHRS_PITCH, m_chkAHRSPitch);
	DDX_Check(pDX, IDC_CHECK_AHRS_ROLL, m_chkAHRSRoll);
	DDX_Check(pDX, IDC_CHECK_AHRS_HEADING, m_chkAHRSHeading);

	DDX_Text(pDX, IDC_EDIT_AHRS_PITCH, m_edtAHRSPitch);
	DDX_Text(pDX, IDC_EDIT_AHRS_ROLL, m_edtAHRSRoll);
	DDX_Text(pDX, IDC_EDIT_AHRS_HEAD, m_edtAHRSHeading);
}


BEGIN_MESSAGE_MAP(CDialog_AHRS_QualityChecks, CDialog)
	ON_BN_CLICKED(IDOK, &CDialog_AHRS_QualityChecks::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK_AHRS_PITCH, &CDialog_AHRS_QualityChecks::OnBnClickedCheckAhrsPitch)
	ON_BN_CLICKED(IDC_CHECK_AHRS_ROLL, &CDialog_AHRS_QualityChecks::OnBnClickedCheckAhrsRoll)
	ON_BN_CLICKED(IDC_CHECK_AHRS_HEADING, &CDialog_AHRS_QualityChecks::OnBnClickedCheckAhrsHeading)
	ON_MESSAGE(WM_UPDATE_ARINC, OnUpdateArinc)
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CDialog_AHRS_QualityChecks message handlers


void CDialog_AHRS_QualityChecks::OnBnClickedOk()
{
    UpdateData(TRUE);

    CMessageBox_Dlg msgdlg;

    // -------- Pitch --------
    m_strAhrsPitch = m_chkAHRSPitch ? "Operational" : "NOT Operational";

    if (m_chkAHRSPitch)
    {
        m_strStatusAhrsPitch = "OK";
    }
    else
    {
        g_strMsgStr = "AHRS Pitch value out of range. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strStatusAhrsPitch = "NOT OK";
    }

    // -------- Roll --------
    m_strAhrsRoll = m_chkAHRSRoll ? "Operational" : "NOT Operational";

    if (m_chkAHRSRoll)
    {
        m_strStatusAhrsRoll = "OK";
    }
    else
    {
        g_strMsgStr = "AHRS Roll value out of range. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strStatusAhrsRoll = "NOT OK";
    }

    // -------- Heading --------
    m_strAhrsHeading = m_chkAHRSHeading ? "Operational" : "NOT Operational";

    if (m_chkAHRSHeading)
    {
        m_strStatusAhrsHeading = "OK";
    }
    else
    {
        g_strMsgStr = "AHRS Heading check failed. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strStatusAhrsHeading = "NOT OK";
    }

    CDialog::OnOK();
}

void CDialog_AHRS_QualityChecks::OnBnClickedCheckAhrsPitch()
{
    UpdateData(TRUE);

    if (m_chkAHRSPitch)
        GetDlgItem(IDC_CHECK_AHRS_PITCH)->SetWindowText("Operational");
    else
        GetDlgItem(IDC_CHECK_AHRS_PITCH)->SetWindowText("NOT Operational");

    UpdateData(FALSE);
}

void CDialog_AHRS_QualityChecks::OnBnClickedCheckAhrsRoll()
{
    UpdateData(TRUE);

    if (m_chkAHRSRoll)
        GetDlgItem(IDC_CHECK_AHRS_ROLL)->SetWindowText("Operational");
    else
        GetDlgItem(IDC_CHECK_AHRS_ROLL)->SetWindowText("NOT Operational");

    UpdateData(FALSE);
}

void CDialog_AHRS_QualityChecks::OnBnClickedCheckAhrsHeading()
{
    UpdateData(TRUE);

    if (m_chkAHRSHeading)
        GetDlgItem(IDC_CHECK_AHRS_HEADING)->SetWindowText("Operational");
    else
        GetDlgItem(IDC_CHECK_AHRS_HEADING)->SetWindowText("NOT Operational");

    UpdateData(FALSE);
}

BOOL CDialog_AHRS_QualityChecks::OnInitDialog()
{
	CDialog::OnInitDialog();

	if(m_bThreadRunning)
        return true;

    //InitializeARINC429();

    InitArincRX(8);
   

    m_bStopThread = FALSE;
    m_bThreadRunning = TRUE;

    AfxBeginThread(ArincRXThread,this);

	return true;
}

UINT CDialog_AHRS_QualityChecks::ArincRXThread(LPVOID pParam)
{
    CDialog_AHRS_QualityChecks* pDlg =
        (CDialog_AHRS_QualityChecks*)pParam;

    pDlg->ExecuteArincRX();

    pDlg->m_bThreadRunning = FALSE;

    return 0;
}

void CDialog_AHRS_QualityChecks::ExecuteArincRX()
{
    float value;

    while(!m_bStopThread)
    {
        ReadRX(8);

if(GetARINCValue(8,LABEL_324,&value))
    m_edtAHRSPitch.Format("%.0f",value);

if(GetARINCValue(8,LABEL_325,&value))
    m_edtAHRSRoll.Format("%.2f",value);

if(GetARINCValue(8,LABEL_320,&value))
    m_edtAHRSHeading.Format("%.0f",value);
 
        PostMessage(WM_UPDATE_ARINC);

        Sleep(100);
    }
}


void CDialog_AHRS_QualityChecks::OnDestroy()
{
    m_bStopThread = TRUE;

    while(m_bThreadRunning)
        Sleep(10);

    CloseRx(8);
	SwitchDiscrete(AHRS_ON,OFF);

    CDialog::OnDestroy();
}

LRESULT CDialog_AHRS_QualityChecks::OnUpdateArinc(WPARAM wParam, LPARAM lParam)
{
    UpdateData(FALSE);

    return 0;
}