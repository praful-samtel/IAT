// Dialog_SMFD_RC_ANCL.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_RC_ANCL.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_SMFD_RC_ANCL dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_RC_ANCL, CDialogEx)

CDialog_SMFD_RC_ANCL::CDialog_SMFD_RC_ANCL(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_RC_ANCL::IDD, pParent)
	, m_edt_SmfdRc_CurrLoad(_T(""))
{

}

CDialog_SMFD_RC_ANCL::~CDialog_SMFD_RC_ANCL()
{
}

void CDialog_SMFD_RC_ANCL::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RCCURR, m_edt_SmfdRc_CurrLoad);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_RC_ANCL, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_RCCL, &CDialog_SMFD_RC_ANCL::OnBnClickedButtonSmfdAnalogRccl)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_RC_ANCL::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_RC_ANCL message handlers


void CDialog_SMFD_RC_ANCL::OnBnClickedButtonSmfdAnalogRccl()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_edt_SmfdRc_CurrLoad = "202";
	UpdateData(FALSE);
}


void CDialog_SMFD_RC_ANCL::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

    CMessageBox_Dlg msgdlg;
    double val = 0.0;

    // -------- CURRENT LOAD --------
    val = _tstof(m_edt_SmfdRc_CurrLoad);
    if (val >= 190 && val <= 210)
    {
        m_strcurload = m_edt_SmfdRc_CurrLoad;
        m_strStatuscurload = "OK";
    }
    else
    {
        g_strMsgStr = "Current load invalid. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strcurload = m_edt_SmfdRc_CurrLoad;
        m_strStatuscurload = "NOT OK";
    }

    UpdateData(FALSE);

	CDialogEx::OnOK();
}
