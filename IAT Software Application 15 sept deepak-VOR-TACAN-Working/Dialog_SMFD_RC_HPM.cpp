// Dialog_SMFD_RC_HPM.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_RC_HPM.h"
#include "afxdialogex.h"

#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;
// CDialog_SMFD_RC_HPM dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_RC_HPM, CDialogEx)

CDialog_SMFD_RC_HPM::CDialog_SMFD_RC_HPM(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_RC_HPM::IDD, pParent)
	, m_edt_SmfdRc_HyPrMain(_T(""))
{

}

CDialog_SMFD_RC_HPM::~CDialog_SMFD_RC_HPM()
{
}

void CDialog_SMFD_RC_HPM::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RCHYDPRESMAIN, m_edt_SmfdRc_HyPrMain);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_RC_HPM, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_RC_ANHPM, &CDialog_SMFD_RC_HPM::OnBnClickedButtonSmfdRcAnhpm)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_RC_HPM::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_RC_HPM message handlers


void CDialog_SMFD_RC_HPM::OnBnClickedButtonSmfdRcAnhpm()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	    m_edt_SmfdRc_HyPrMain = "2940";  
		UpdateData(FALSE);

}


void CDialog_SMFD_RC_HPM::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CMessageBox_Dlg msgdlg;

    UpdateData(TRUE);

    // -------- HYD PRES MAIN --------
    int val = atoi(m_edt_SmfdRc_HyPrMain);
    if (val >= 2910 && val <= 2950)
    {
        m_strHydPresMain = m_edt_SmfdRc_HyPrMain;
        m_strStatusHydPresMain = "OK";
    }
    else
    {
        g_strMsgStr.Format("Hydraulic Main Pressure not in range, Continue?");
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;

        m_strHydPresMain = m_edt_SmfdRc_HyPrMain;
        m_strStatusHydPresMain = "NOT OK";
    }
	    UpdateData(FALSE);
	CDialogEx::OnOK();
}
