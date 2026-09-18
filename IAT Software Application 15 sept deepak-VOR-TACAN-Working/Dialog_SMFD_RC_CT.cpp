// Dialog_SMFD_RC_CT.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_RC_CT.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;


// CDialog_SMFD_RC_CT dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_RC_CT, CDialogEx)

CDialog_SMFD_RC_CT::CDialog_SMFD_RC_CT(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_RC_CT::IDD, pParent)
	, m_edt_SmfdRc_CoTank(_T(""))
{

}

CDialog_SMFD_RC_CT::~CDialog_SMFD_RC_CT()
{
}

void CDialog_SMFD_RC_CT::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RCCOLLECTORANK, m_edt_SmfdRc_CoTank);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_RC_CT, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_RCCT, &CDialog_SMFD_RC_CT::OnBnClickedButtonSmfdAnalogRcct)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_RC_CT::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_RC_CT message handlers


void CDialog_SMFD_RC_CT::OnBnClickedButtonSmfdAnalogRcct()
{
	// TODO: Add your control notification handler code here
	 UpdateData(TRUE);
	 m_edt_SmfdRc_CoTank = "183";
	 UpdateData(FALSE);
}


void CDialog_SMFD_RC_CT::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	 CMessageBox_Dlg msgdlg;

    UpdateData(TRUE);
      // -------- COLLECTOR TANK --------
   int val = atoi(m_edt_SmfdRc_CoTank);
    if (val >= 178 && val <= 188)
    {
        m_strCollectorTank = m_edt_SmfdRc_CoTank;
        m_strStatusCollectorTank = "OK";
    }
    else
    {
        g_strMsgStr.Format("Collector Tank Fuel not OK, Continue?");
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;

        m_strCollectorTank = m_edt_SmfdRc_CoTank;
        m_strStatusCollectorTank = "NOT OK";
    }
	  UpdateData(FALSE);
	CDialogEx::OnOK();
}
