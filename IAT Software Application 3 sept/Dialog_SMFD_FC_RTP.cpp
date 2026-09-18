// Dialog_SMFD_FC_RTP.cpp : implementation file
//

#include "stdafx.h"
#include "Dialog_SMFD_FC_RTP.h"
#include "afxdialogex.h"
#include "MessageBox_Dlg.h"

extern CString g_strMsgStr;
extern BOOL g_bContinueFlag;


// CDialog_SMFD_FC_RTP dialog

IMPLEMENT_DYNAMIC(CDialog_SMFD_FC_RTP, CDialogEx)

CDialog_SMFD_FC_RTP::CDialog_SMFD_FC_RTP(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDialog_SMFD_FC_RTP::IDD, pParent)
	, m_edt_SMFDFC_RTP(_T(""))
{

}

CDialog_SMFD_FC_RTP::~CDialog_SMFD_FC_RTP()
{
}

void CDialog_SMFD_FC_RTP::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_RUDER, m_edt_SMFDFC_RTP);
}


BEGIN_MESSAGE_MAP(CDialog_SMFD_FC_RTP, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_SMFD_ANALOG_FCRTP, &CDialog_SMFD_FC_RTP::OnBnClickedButtonSmfdAnalogFcrtp)
	ON_BN_CLICKED(IDOK, &CDialog_SMFD_FC_RTP::OnBnClickedOk)
END_MESSAGE_MAP()


// CDialog_SMFD_FC_RTP message handlers


void CDialog_SMFD_FC_RTP::OnBnClickedButtonSmfdAnalogFcrtp()
{
	// TODO: Add your control notification handler code here

	
		UpdateData(TRUE);
	m_edt_SMFDFC_RTP = "center";


	  UpdateData(FALSE);
}


void CDialog_SMFD_FC_RTP::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	 UpdateData(TRUE);

    CMessageBox_Dlg msgdlg;
    double val = 0.0;
	    //// -------- RUDDER --------
    if (m_edt_SMFDFC_RTP.Find("center") != -1)
    {
        m_strrudder = m_edt_SMFDFC_RTP;
        m_strStatusrudder = "OK";
    }
    else
    {
        g_strMsgStr = "Rudder position incorrect. Continue?";
        msgdlg.DoModal();
        if (!g_bContinueFlag) return;
        m_strrudder = m_edt_SMFDFC_RTP;
        m_strStatusrudder = "NOT OK";
    }

	 UpdateData(FALSE);
	CDialogEx::OnOK();
}
