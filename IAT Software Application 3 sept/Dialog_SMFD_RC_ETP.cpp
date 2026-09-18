// Dialog_SMFD_RC_ETP.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_RC_ETP.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;


// CDialog_SMFD_RC_ETP dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_RC_ETP, CDialogEx)

CDialog_SMFD_RC_ETP::CDialog_SMFD_RC_ETP(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_RC_ETP::IDD, pParent)
	, m_edt_SmfdRc_ElevTrimPos(_T(""))
{

}

CDialog_SMFD_RC_ETP::~CDialog_SMFD_RC_ETP()
{
}

void CDialog_SMFD_RC_ETP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RCELEVATOR, m_edt_SmfdRc_ElevTrimPos);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_RC_ETP, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_RCETP, &CDialog_SMFD_RC_ETP::OnBnClickedButtonSmfdAnalogRcetp)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_RC_ETP::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_RC_ETP message handlers


void CDialog_SMFD_RC_ETP::OnBnClickedButtonSmfdAnalogRcetp()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_edt_SmfdRc_ElevTrimPos = "-1.2 deg";
	UpdateData(FALSE);
}


void CDialog_SMFD_RC_ETP::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

    CMessageBox_Dlg msgdlg;
    double val = 0.0;

    // -------- ELEVATOR --------
    if (m_edt_SmfdRc_ElevTrimPos.Find("deg") != -1)
    {
        m_strelevator = m_edt_SmfdRc_ElevTrimPos;
        m_strStatuselevator = "OK";
    }
    else
    {
        g_strMsgStr = "Elevator value incorrect. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strelevator = m_edt_SmfdRc_ElevTrimPos;
        m_strStatuselevator = "NOT OK";
    }
	UpdateData(FALSE);
	CDialogEx::OnOK();
}
