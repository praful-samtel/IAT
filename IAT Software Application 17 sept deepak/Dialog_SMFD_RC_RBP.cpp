// Dialog_SMFD_RC_RBP.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_RC_RBP.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_SMFD_RC_RBP dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_RC_RBP, CDialogEx)

CDialog_SMFD_RC_RBP::CDialog_SMFD_RC_RBP(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_RC_RBP::IDD, pParent)
	, m_edt_SmfdRc_RhBr(_T(""))
{

}

CDialog_SMFD_RC_RBP::~CDialog_SMFD_RC_RBP()
{
}

void CDialog_SMFD_RC_RBP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RCLHBRAKE, m_edt_SmfdRc_RhBr);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_RC_RBP, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_RCRBP, &CDialog_SMFD_RC_RBP::OnBnClickedButtonSmfdAnalogRcrbp)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_RC_RBP::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_RC_RBP message handlers


void CDialog_SMFD_RC_RBP::OnBnClickedButtonSmfdAnalogRcrbp()
{
	// TODO: Add your control notification handler code here
	    UpdateData(TRUE);
		
		m_edt_SmfdRc_RhBr = "1205"; //1200± 15 psi
			UpdateData(FALSE);
}


void CDialog_SMFD_RC_RBP::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	 CMessageBox_Dlg msgdlg;

    UpdateData(TRUE);
    // -------- RH BRAKE --------
   int val = atoi(m_edt_SmfdRc_RhBr);
    if (val >= 1185 && val <= 1215)
    {
        m_strRhBrake = m_edt_SmfdRc_RhBr;
        m_strStatusRhBrake = "OK";
    }
    else
    {
        g_strMsgStr.Format("RH Brake Pressure not OK, Continue?");
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;

        m_strRhBrake = m_edt_SmfdRc_RhBr;
        m_strStatusRhBrake = "NOT OK";
    }
	    UpdateData(FALSE);
	CDialogEx::OnOK();
}
