// Dialog_SMFD_RC_ET.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_RC_ET.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;


// CDialog_SMFD_RC_ET dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_RC_ET, CDialogEx)

CDialog_SMFD_RC_ET::CDialog_SMFD_RC_ET(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_RC_ET::IDD, pParent)
	, m_edt_SmfdRc_EnTor(_T(""))
{

}

CDialog_SMFD_RC_ET::~CDialog_SMFD_RC_ET()
{
}

void CDialog_SMFD_RC_ET::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RCTORQUE, m_edt_SmfdRc_EnTor);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_RC_ET, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_RCET, &CDialog_SMFD_RC_ET::OnBnClickedButtonSmfdAnalogRcet)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_RC_ET::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_RC_ET message handlers


void CDialog_SMFD_RC_ET::OnBnClickedButtonSmfdAnalogRcet()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_edt_SmfdRc_EnTor = "1742";
	UpdateData(FALSE);
}


void CDialog_SMFD_RC_ET::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

    CMessageBox_Dlg msgdlg;
    double val = 0.0;

    // -------- TORQUE --------
    val = _tstof(m_edt_SmfdRc_EnTor);
    if (val >= 1736 && val <= 1744)
    {
        m_strtorque = m_edt_SmfdRc_EnTor;
        m_strStatustorque = "OK";
    }
    else
    {
        g_strMsgStr = "Torque invalid. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strtorque = m_edt_SmfdRc_EnTor;
        m_strStatustorque = "NOT OK";
    }
	UpdateData(FALSE);
	CDialogEx::OnOK();
}
