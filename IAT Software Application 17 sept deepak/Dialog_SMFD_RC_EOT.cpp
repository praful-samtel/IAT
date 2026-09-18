// Dialog_SMFD_RC_EOT.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_RC_EOT.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_SMFD_RC_EOT dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_RC_EOT, CDialogEx)

CDialog_SMFD_RC_EOT::CDialog_SMFD_RC_EOT(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_RC_EOT::IDD, pParent)
	, m_edt_SMFDRC_EOT(_T(""))
{

}

CDialog_SMFD_RC_EOT::~CDialog_SMFD_RC_EOT()
{
}

void CDialog_SMFD_RC_EOT::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_OILTEMP, m_edt_SMFDRC_EOT);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_RC_EOT, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_RC_ANALOGEOT, &CDialog_SMFD_RC_EOT::OnBnClickedButtonSmfdRcAnalogeot)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_RC_EOT::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_RC_EOT message handlers


void CDialog_SMFD_RC_EOT::OnBnClickedButtonSmfdRcAnalogeot()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_edt_SMFDRC_EOT = "61";
	UpdateData(FALSE);
}


void CDialog_SMFD_RC_EOT::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

    CMessageBox_Dlg msgdlg;
    double val = 0.0;

    // -------- OIL TEMP --------
    val = _tstof(m_edt_SMFDRC_EOT);
    if (val >= 58 && val <= 62)
    {
        m_stroiltemp = m_edt_SMFDRC_EOT;
        m_strStatusoiltemp = "OK";
    }
    else
    {
        g_strMsgStr = "Oil Temperature out of range. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_stroiltemp = m_edt_SMFDRC_EOT;
        m_strStatusoiltemp = "NOT OK";
    }

	UpdateData(FALSE);
	CDialogEx::OnOK();
}
