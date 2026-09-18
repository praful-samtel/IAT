// Dialog_SMFD_RC_LBP.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_RC_LBP.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_SMFD_RC_LBP dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_RC_LBP, CDialogEx)

CDialog_SMFD_RC_LBP::CDialog_SMFD_RC_LBP(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_RC_LBP::IDD, pParent)
	, m_edt_SmfdRc_LHBr(_T(""))
{

}

CDialog_SMFD_RC_LBP::~CDialog_SMFD_RC_LBP()
{
}

void CDialog_SMFD_RC_LBP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RCLHBRAKE, m_edt_SmfdRc_LHBr);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_RC_LBP, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_RCLBP, &CDialog_SMFD_RC_LBP::OnBnClickedButtonSmfdAnalogRclbp)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_RC_LBP::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_RC_LBP message handlers


void CDialog_SMFD_RC_LBP::OnBnClickedButtonSmfdAnalogRclbp()
{
	// TODO: Add your control notification handler code here
	 UpdateData(TRUE);
	 
	
		m_edt_SmfdRc_LHBr = "1205"; //1200± 15 psi
	 UpdateData(FALSE);
}


void CDialog_SMFD_RC_LBP::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	 CMessageBox_Dlg msgdlg;

    UpdateData(TRUE);


    // -------- LH BRAKE --------
   int val = atoi(m_edt_SmfdRc_LHBr);
    if (val >= 1185 && val <= 1215)
    {
        m_strLhBrake = m_edt_SmfdRc_LHBr;
        m_strStatusLhBrake = "OK";
    }
    else
    {
        g_strMsgStr.Format("LH Brake Pressure not OK, Continue?");
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;

        m_strLhBrake = m_edt_SmfdRc_LHBr;
        m_strStatusLhBrake = "NOT OK";
    }
	
	UpdateData(FALSE);
	CDialogEx::OnOK();
}
