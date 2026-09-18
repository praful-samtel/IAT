// Dialog_SMFD_RC_HPE.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_RC_HPE.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;


// CDialog_SMFD_RC_HPE dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_RC_HPE, CDialogEx)

CDialog_SMFD_RC_HPE::CDialog_SMFD_RC_HPE(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_RC_HPE::IDD, pParent)
	
	
	, m_edt_SmfdRc_HyPrEm(_T(""))
{

}

CDialog_SMFD_RC_HPE::~CDialog_SMFD_RC_HPE()
{
}

void CDialog_SMFD_RC_HPE::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);


	DDX_Text(pDX, IDC_EDIT_RCHYDPRESEMER, m_edt_SmfdRc_HyPrEm);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_RC_HPE, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_RCHPE, &CDialog_SMFD_RC_HPE::OnBnClickedButtonSmfdAnalogRchpe)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_RC_HPE::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_RC_HPE message handlers


void CDialog_SMFD_RC_HPE::OnBnClickedButtonSmfdAnalogRchpe()
{
	// TODO: Add your control notification handler code here
	
    UpdateData(TRUE);
	 m_edt_SmfdRc_HyPrEm = "3340";
	  UpdateData(FALSE);

}


void CDialog_SMFD_RC_HPE::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CMessageBox_Dlg msgdlg;

    UpdateData(TRUE);
 int val = atoi(m_edt_SmfdRc_HyPrEm);
    if (val >= 3310 && val <= 3350)
    {
        m_strHydPresEmer = m_edt_SmfdRc_HyPrEm;
        m_strStatusHydPresEmer = "OK";
    }
    else
    {
        g_strMsgStr.Format("Hydraulic Emergency Pressure not OK, Continue?");
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;

        m_strHydPresEmer = m_edt_SmfdRc_HyPrEm;
        m_strStatusHydPresEmer = "NOT OK";
    }
	    UpdateData(FALSE);
	CDialogEx::OnOK();
}
