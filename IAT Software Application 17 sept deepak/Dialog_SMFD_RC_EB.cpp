// Dialog_SMFD_RC_EB.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_RC_EB.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_SMFD_RC_EB dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_RC_EB, CDialogEx)

CDialog_SMFD_RC_EB::CDialog_SMFD_RC_EB(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_RC_EB::IDD, pParent)
	, m_edt_SmfdRc_EmBr(_T(""))
{

}

CDialog_SMFD_RC_EB::~CDialog_SMFD_RC_EB()
{
}

void CDialog_SMFD_RC_EB::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RCACCUMPRES, m_edt_SmfdRc_EmBr);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_RC_EB, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_RCEB, &CDialog_SMFD_RC_EB::OnBnClickedButtonSmfdAnalogRceb)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_RC_EB::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_RC_EB message handlers


void CDialog_SMFD_RC_EB::OnBnClickedButtonSmfdAnalogRceb()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	  m_edt_SmfdRc_EmBr = "1307";   // 1300± 15 psi
	  UpdateData(FALSE);
}


void CDialog_SMFD_RC_EB::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	 CMessageBox_Dlg msgdlg;

    UpdateData(TRUE);

    // -------- EMER BRAKE --------
  int  val = atoi(m_edt_SmfdRc_EmBr);
    if (val >= 1285 && val <= 1315)
    {
        m_strEmerBrake = m_edt_SmfdRc_EmBr;
        m_strStatusEmerBrake = "OK";
    }
    else
    {
        g_strMsgStr.Format("Emergency Brake Pressure not OK, Continue?");
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;

        m_strEmerBrake = m_edt_SmfdRc_EmBr;
        m_strStatusEmerBrake = "NOT OK";
    }
	 UpdateData(FALSE);
	CDialogEx::OnOK();
}
