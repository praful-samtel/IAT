// Dialog_SMFD_RC_ATP.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_RC_ATP.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_SMFD_RC_ATP dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_RC_ATP, CDialogEx)

CDialog_SMFD_RC_ATP::CDialog_SMFD_RC_ATP(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_RC_ATP::IDD, pParent)
	, m_edt_SmfdRc_AilTrimPos(_T(""))
{

}

CDialog_SMFD_RC_ATP::~CDialog_SMFD_RC_ATP()
{
}

void CDialog_SMFD_RC_ATP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RCAILERON, m_edt_SmfdRc_AilTrimPos);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_RC_ATP, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_RCATP, &CDialog_SMFD_RC_ATP::OnBnClickedButtonSmfdAnalogRcatp)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_RC_ATP::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_RC_ATP message handlers


void CDialog_SMFD_RC_ATP::OnBnClickedButtonSmfdAnalogRcatp()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_edt_SmfdRc_AilTrimPos = "wing at green line";
	UpdateData(FALSE);
	

}


void CDialog_SMFD_RC_ATP::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
		UpdateData(TRUE);

    CMessageBox_Dlg msgdlg;
    double val = 0.0;

    // -------- AILERON --------
    if (m_edt_SmfdRc_AilTrimPos.Find("green") != -1)
    {
        m_straileron = m_edt_SmfdRc_AilTrimPos;
        m_strStatusaileron = "OK";
    }
    else
    {
        g_strMsgStr = "Aileron not in green range. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_straileron = m_edt_SmfdRc_AilTrimPos;
        m_strStatusaileron = "NOT OK";
    }
	UpdateData(FALSE);
	CDialogEx::OnOK();
}
