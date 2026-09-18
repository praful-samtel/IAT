// Dialog_AHRS_PWR.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_AHRS_PWR.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"
#include "DataStruct.h"
#include "Globals.h"
extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;


// CDialog_AHRS_PWR dialog

IMPLEMENT_DYNAMIC(CDialog_AHRS_PWR, CDialogEx)

CDialog_AHRS_PWR::CDialog_AHRS_PWR(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_AHRS_PWR::IDD, pParent)
	, m_edtAHRSPWR(_T(""))
{

}

CDialog_AHRS_PWR::~CDialog_AHRS_PWR()
{
}

void CDialog_AHRS_PWR::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_AHRS_PWR, m_edtAHRSPWR);
}


BEGIN_MESSAGE_MAP(CDialog_AHRS_PWR, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDialog_AHRS_PWR::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON_AHRS_PWR, &CDialog_AHRS_PWR::OnBnClickedButtonAhrsPwr)
END_MESSAGE_MAP()


// CDialog_AHRS_PWR message handlers

void CDialog_AHRS_PWR::OnBnClickedOk()
{
	UpdateData(TRUE);   // 🔥 MUST

	CMessageBox_Dlg msgdlg;

	// -------- VALIDATION --------



	// -------- STORE VALUE --------
	//m_strAHRSCurrent = m_edtAHRSPWR;

	// -------- SIMPLE CHECK (you can refine later) --------
	double current = atof(m_edtAHRSPWR);

	if (current <= 1.1)   // basic validation
	{
		m_strStatusAHRSCurrent = "OK";
	}
	else
	{
		g_strMsgStr = "AHRS Current is invalid. Continue?";
		msgdlg.DoModal();

		if (!g_bContinueFlag)
			return;

		m_strStatusAHRSCurrent = "NOT OK";
	}

	CDialogEx::OnOK();   // 🔥 MUST
}


void CDialog_AHRS_PWR::OnBnClickedButtonAhrsPwr()
{
	if(g_bSimulationMode)
		{	
		
		CString message;
		CString LRU = "AHRS";
		FORMAT_CONNECT_LOAD_MSG(message, "AHRS", AHRS_PWR_PIN_X, AHRS_PWR_PIN_Y, AHRS_PWR_CONNECTOR);

		::MessageBox(AfxGetMainWnd() ? AfxGetMainWnd()->GetSafeHwnd() : NULL,
					 message,
					 "AHRS PWR",
					 MB_OK | MB_ICONINFORMATION);
	 }

	// TODO: Add your control notification handler code here
	SwitchDiscrete(AHRS_ON,ON);
	Sleep(2000);
	double current = ReadPowerSupplyValue('C');
	m_edtAHRSPWR.Format("%.3f", current);
}
