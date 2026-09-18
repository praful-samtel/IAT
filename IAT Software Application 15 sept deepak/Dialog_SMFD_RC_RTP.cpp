// Dialog_SMFD_RC_RTP.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_RC_RTP.h"
#include "afxdialogex.h"

#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;

// CDialog_SMFD_RC_RTP dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_RC_RTP, CDialogEx)

CDialog_SMFD_RC_RTP::CDialog_SMFD_RC_RTP(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_RC_RTP::IDD, pParent)
	, m_edt_SmfdRc_RudTrimPos(_T(""))
{

}

CDialog_SMFD_RC_RTP::~CDialog_SMFD_RC_RTP()
{
}

void CDialog_SMFD_RC_RTP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RCRUDER, m_edt_SmfdRc_RudTrimPos);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_RC_RTP, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_RCRTP, &CDialog_SMFD_RC_RTP::OnBnClickedButtonSmfdAnalogRcrtp)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_RC_RTP::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_RC_RTP message handlers


void CDialog_SMFD_RC_RTP::OnBnClickedButtonSmfdAnalogRcrtp()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	m_edt_SmfdRc_RudTrimPos = "Nose at center white line";
	UpdateData(FALSE);
}


void CDialog_SMFD_RC_RTP::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);

    CMessageBox_Dlg msgdlg;
    double val = 0.0;

      // -------- RUDDER --------
    if (m_edt_SmfdRc_RudTrimPos.Find("center") != -1)
    {
        m_strrudder = m_edt_SmfdRc_RudTrimPos;
        m_strStatusrudder = "OK";
    }
    else
    {
        g_strMsgStr = "Rudder position incorrect. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strrudder = m_edt_SmfdRc_RudTrimPos;
        m_strStatusrudder = "NOT OK";
    }
	UpdateData(FALSE);
	CDialogEx::OnOK();
}
