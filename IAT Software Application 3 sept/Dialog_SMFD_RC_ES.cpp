// Dialog_SMFD_RC_ES.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_RC_ES.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_SMFD_RC_ES dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_RC_ES, CDialogEx)

CDialog_SMFD_RC_ES::CDialog_SMFD_RC_ES(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_RC_ES::IDD, pParent)
	, m_edt_SmfdRc_EnSpeed(_T(""))
{

}

CDialog_SMFD_RC_ES::~CDialog_SMFD_RC_ES()
{
}

void CDialog_SMFD_RC_ES::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RCENGSPD, m_edt_SmfdRc_EnSpeed);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_RC_ES, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_RCES, &CDialog_SMFD_RC_ES::OnBnClickedButtonSmfdAnalogRces)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_RC_ES::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_RC_ES message handlers


void CDialog_SMFD_RC_ES::OnBnClickedButtonSmfdAnalogRces()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_edt_SmfdRc_EnSpeed = "80";
	UpdateData(FALSE);

}


void CDialog_SMFD_RC_ES::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	 CMessageBox_Dlg msgdlg;
    UpdateData(TRUE);
   
    // -------- ENGINE SPEED --------
   int val = atoi(m_edt_SmfdRc_EnSpeed);
    if (val >= 77 && val <= 81)
    {
        m_strEngineSpd = m_edt_SmfdRc_EnSpeed;
        m_strStatusEngineSpd = "OK";
    }
    else
    {
        g_strMsgStr.Format("Engine Speed not OK, Continue?");
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;

        m_strEngineSpd = m_edt_SmfdRc_EnSpeed;
        m_strStatusEngineSpd = "NOT OK";
    }
	 UpdateData(FALSE);
	CDialogEx::OnOK();
}
